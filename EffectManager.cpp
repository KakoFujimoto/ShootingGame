#include "EffectManager.h"
#include "EffectType.h"
#include "ImageContainer.h"
#include "GameManager.h"
#include "SoundPlayer.h"
#include "SoundContainer.h"
#include "BlendMode.h"
#include "IDrawable.h"

void EffectManager::setEffect
(
	int x,
	int y,
	EffectType ptn, 
	ImageContainer& imageContainer,
	SoundPlayer& soundPlayer,
	SoundContainer& soundContainer
)
{
	for (auto& e : effects) {
		if (e.getState() == 0) {
			e.initialize(x, y, ptn, imageContainer, soundPlayer, soundContainer);
			break;
		}
	}
}

void EffectManager::drawEffect(GameManager& game)
{
	int ix;
	for (auto& e : effects) {
		if (e.getState() == 0) continue;
		switch (e.getPattern()) // エフェクトごとに処理を分ける
		{
		case EffectType::Explode: // 爆発演出
		{
			// 爆発演出の描画
			ix = e.getTimer() * 128; // 画像の切り出し位置

			RectData exp{ e.getX() - 64, e.getY() - 64,
				ix, 0, 128, 128,
				*e.getImage() };
			game.getDrawer().drawGraphic(exp);

			// エフェクトの存続期間の設定
			e.setTimer(e.getTimer() + 1);
			if (e.getTimer() == 7) e.setState(0);
		}
			break;
		case EffectType::Recover: // 回復演出

			// 回復演出の描画
			if (e.getTimer() < 30) // 加算による描画の重ね合わせ
				game.getDrawer().setBlendMode(BlendMode::Add, e.getTimer() * 8);
			else
				game.getDrawer().setBlendMode(BlendMode::Add, 60 - e.getTimer() * 8);

			for (int i = 3; i < 8; i++)
			{
				CircleData rcv{ e.getX(), e.getY(), game.getPlayer().getWidth() + game.getPlayer().getHeight() / i,
					0x2040c0, TRUE };
				game.getDrawer().drawGraphic(rcv);
			}
			game.getDrawer().setBlendMode(BlendMode::NoBlend, 0); // ブレンドモードを解除

			// エフェクトの存続期間の設定
			e.setTimer(e.getTimer() + 1);

			if (e.getTimer() == 60)
			{
				e.setState(0);
			}
			break;
		}
	}
}
