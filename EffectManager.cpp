#include "EffectManager.h"
#include "EffectType.h"
#include "ImageContainer.h"
#include "DxLib.h"
#include "GameManager.h"

void EffectManager::setEffect(int x, int y, EffectType ptn, ImageContainer& imageContainer)
{
	for (auto& e : effects) {
		if (e.getState() == 0) {
			e.setX(x);
			e.setY(y);
			e.setVX(0);
			e.setVY(0);
			e.setPattern(ptn);
			e.setImage((ptn == EffectType::Explode)
				? &imageContainer.getExplosion()
				: &imageContainer.getItem());

			e.setWidth(e.getImage()->getWidth());
			e.setHeight(e.getImage()->getHeight());

			e.setState(1);
			e.setTimer(0);
			break;
		}
	}
}

void EffectManager::drawEffect(GameManager& game)
{
	int ix;
	for (auto& e : effects) {
		if (e.getState() == 0) continue;
		switch (e.getPattern()) // �G�t�F�N�g���Ƃɏ����𕪂���
		{
		case EffectType::Explode: // �������o
			ix = e.getTimer() * 128; // �摜�̐؂�o���ʒu

			DrawRectGraph(e.getX() - 64, e.getY() - 64,
				ix, 0, 128, 128,
				e.getImage()->getId(), TRUE, FALSE);

			e.setTimer(e.getTimer() + 1);
			if (e.getTimer() == 7) e.setState(0);
			break;
		case EffectType::Recover: // �񕜉��o
			if (e.getTimer() < 30) // ���Z�ɂ��`��̏d�ˍ��킹
				SetDrawBlendMode(DX_BLENDMODE_ADD, e.getTimer() * 8);
			else
				SetDrawBlendMode(DX_BLENDMODE_ADD, (60 - e.getTimer()) * 8);
			for (int i = 3; i < 8; i++)
			{
				DrawCircle(e.getX(), e.getY(),
					(game.getPlayer().getWidth() + game.getPlayer().getHeight()) / i,
					0x2040c0, TRUE);
			}
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // �u�����h���[�h������
			e.setTimer(e.getTimer() + 1);

			if (e.getTimer() == 60)
			{
				e.setState(0);
			}
			break;
		}
	}
}

void EnemyManager::resetAllEnemies()
{
	for (int i = 0; i < GameConfig::ENEMY_MAX; i++)
	{
		enemies[i].setState(0);
	}
}