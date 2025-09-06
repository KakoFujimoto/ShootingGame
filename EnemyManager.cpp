#include "Bullet.h"
#include "GameData.h"
#include "EnemyManager.h"
#include "DxLib.h"
#include "Image.h"
#include "EnemyType.h"
#include "GameManager.h"
#include "EffectType.h"
#include "SceneClear.h"

	// �G�@�𓮂���
	void EnemyManager::moveEnemy(GameManager& game)
	{
		for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
			auto& enemy = enemies[i];
			auto& ene_bullet = game.getImage().getEnemy(EnemyType::Bullet);
			auto& drawer = game.getDrawer();

			if (enemy.getState() == 0)
			{
				continue; // �󂢂Ă���z��Ȃ珈�����Ȃ�
			}
			if (enemy.getPattern() == EnemyType::Zako3) // �U�R�@3
			{
				if (enemy.getVY() > 1) // ����
				{
					enemy.setVY(enemy.getVY() * 0.9);
				}
				else if (enemy.getVY() > 0) // �e���ˁA��ы���
				{
					setEnemy(enemy.getX(), enemy.getY(), 0, 6, EnemyType::Bullet, ene_bullet, 0, game); // �e

					enemy.setVX(8);
					enemy.setVY(-4);
				}
			}
			if (enemy.getPattern() == EnemyType::Boss) // �{�X�@
			{
				if (enemy.getY() > GameConfig::HEIGHT - 120)
				{
					enemy.setVY(-2);
				}
				if (enemy.getY() < 120) // ��ʏ�[
				{
					if (enemy.getY() < 0) // �e����
					{
						for (int bx = -2; bx <= 2; bx++) // ��d���[�v��for
							for (int by = 0; by <= 3; by++)
							{
								if (bx == 0 && by == 0) continue;
								setEnemy(enemy.getX(), enemy.getY(), bx * 2, by * 3, EnemyType::Bullet, ene_bullet, 0, game);
							}
					}
					enemy.setVY(2);
				}
			}
			enemy.setX(enemy.getX() + enemy.getVX()); //���G�@�̈ړ�
			enemy.setY(enemy.getY() + enemy.getVY()); //��


			drawer.drawImage(game.getImage().getEnemy(enemy.getPattern()).getId(), enemy.getX(), enemy.getY()); // �G�@�̕`��

			// ��ʊO�ɏo�����H
			if (enemy.getX() < -200 || GameConfig::WIDTH + 200 < enemy.getX()
				|| enemy.getY() < -200 || GameConfig::HEIGHT + 200 < enemy.getY())
			{
				enemy.setState(0); // ��ʊO�ɏo����A���݂��Ȃ���Ԃɂ���
			}
			// �����蔻��̃A���S���Y��
			if (enemy.getShield() > 0) // �q�b�g�`�F�b�N���s���G�@�i�e�ȊO�j
			{
				for (int j = 0; j < GameConfig::BULLET_MAX; j++) { // ���@�̒e�ƃq�b�g�`�F�b�N
					//auto& bullet = game.getBullet();
					auto& bullet = game.getBulletManager().getBullet(j);

					if (bullet.getState() == 0)
					{
						continue;
					}
					int dx = abs((int)(enemy.getX() - bullet.getX())); //�����S���W�Ԃ̃s�N�Z����
					int dy = abs((int)(enemy.getY() - bullet.getY())); //��
					if (dx < enemy.getWidth() / 2 && dy < enemy.getHeight() / 2) // �ڐG���Ă��邩
					{
						bullet.setState(0); // �e������
						damageEnemy(i, 1, game); // �G�Ƀ_���[�W
					}
				}
			}
			if (game.getGameData().noDamage == 0) // ���G��ԂłȂ����A���@�ƃq�b�g�`�F�b�N
			{	
				auto& player = game.getPlayer();

				int dx = abs(enemy.getX() - player.getX()); //�����S���W�Ԃ̃s�N�Z����
				int dy = abs(enemy.getY() - player.getY()); //��
				if (dx < enemy.getWidth() / 2 + player.getWidth() / 2 && dy < enemy.getHeight() / 2 + player.getHeight() / 2)
				{
					if (player.getShield() > 0)
					{
						player.setShield(player.getShield() - 1); // �V�[���h�����炷
					}
					game.getGameData().noDamage = GameConfig::FPS; // ���G��Ԃ��Z�b�g
					damageEnemy(i, 1, game); // �G�Ƀ_���[�W
				}
			}
		}
	}

	// �G�@���Z�b�g����
	int EnemyManager::setEnemy(int x, int y, int vx, int vy, EnemyType ptn, Image img, int sld, GameManager& game)
	{
		for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
			auto& enemy = enemies[i];

			if (enemy.getState() == 0) {
				enemy.setX(x);
				enemy.setY(y);
				enemy.setVX(vx);
				enemy.setVY(vy);
				enemy.setState(1);
				enemy.setPattern(ptn);

				enemy.setImage(&img);
				enemy.setShield(sld * game.getGameData().stage); // �X�e�[�W���i�ނقǓG���ł��Ȃ�
				enemy.setWidth(img.getWidth());
				enemy.setHeight(img.getHeight());
				return i;
			}
		}
		return -1;
	}

	// �G�@�̃V�[���h�����炷�i�_���[�W��^����j
	void EnemyManager::damageEnemy(int n, int dmg, GameManager& game)
	{	

		SetDrawBlendMode(DX_BLENDMODE_ADD, 192); // ���Z�ɂ��`��̏d�ˍ��킹
		DrawCircle(enemies[n].getX(), enemies[n].getY(), (enemies[n].getWidth() + enemies[n].getHeight()) / 4, 0xff0000, TRUE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // �u�����h���[�h������

		int& score = game.getGameData().score;
		score += 100; // �X�R�A�̉��Z

		int& hisco = game.getGameData().hisco;
		if (score > hisco)
		{
			hisco = score; // �n�C�X�R�A�̍X�V
		}

		enemies[n].setShield(enemies[n].getShield() - dmg); // �V�[���h�����炷

		if (enemies[n].getShield() <= 0)
		{
			enemies[n].setState(0); // �V�[���h0�ȉ��ŏ���

			game.getEffect().setEffect(
				enemies[n].getX(),
				enemies[n].getY(),
				EffectType::Explode,
				game.getImage(),
				game.getSoundPlayer(),
				game.getSoundContainer()
			); // �������o

			if (enemies[n].getPattern() == EnemyType::Boss) // �{�X��|����
			{
				game.getSoundPlayer().stop(game.getSoundContainer().bgm); // �a�f�l��~

				//GameData::scene = CLEAR;
				//return std::make_shared<SceneClear>();
				game.setIsClear(true);

				game.getGameData().timer = 0;
			}
		}
	}

	const Enemy& EnemyManager::getEnemy(int idx) const
	{
		return enemies[idx];
	}
