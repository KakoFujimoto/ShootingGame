#include "EffectManager.h"
#include "EffectType.h"
#include "ImageContainer.h"

void EffectManager::setEffect(int x, int y, int ptn, ImageContainer& imageContainer)
{
	for (auto& e : effects) {
		if (e.getState() == 0) {
			e.setX(x);
			e.setY(y);
			e.setVX(0);
			e.setVY(0);
			e.setPattern(ptn);
			e.setImage((static_cast<EffectType>(ptn) == EffectType::Explode)
				? imageContainer.getExplosion().getId()
				: imageContainer.getItem().getId());
			GetGraphSize(e.getImage(), &e.getWidth(), &e.getHeight());
			e.setState(1);
			e.setTimer(0);
			break;
		}
	}
}

void EffectManager::drawEffect(void)
{
	int ix;
	for (auto& e : effects) {
		if (e.getState() == 0) continue;
		switch (e.getPattern()) // エフェクトごとに処理を分ける
		{
		case static_cast<int>(EffectType::Explode): // 爆発演出
			ix = e.getTimer() * 128; // 画像の切り出し位置
			DrawRectGraph(e.getX() - 64, e.getY() - 64, ix, 0, 128, 128, e.getImage(), TRUE, FALSE);
			e.setTimer(e.getTimer() + 1);
			if (e.getTimer() == 7) e.setState(0);
			break;
		case static_cast<int>(EffectType::Recover): // 回復演出
			if (e.getTimer() < 30) // 加算による描画の重ね合わせ
				SetDrawBlendMode(DX_BLENDMODE_ADD, e.getTimer() * 8);
			else
				SetDrawBlendMode(DX_BLENDMODE_ADD, (60 - e.getTimer()) * 8);
			for (int i = 3; i < 8; i++) DrawCircle(e.getX(), e.getY(), (GameData::player.getWidth() + GameData::player.getHeight()) / i, 0x2040c0, TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // ブレンドモードを解除
			e.setTimer(e.getTimer() + 1);
			if (e.getTimer() == 60) e.setState(0);
			break;
		}
	}
}