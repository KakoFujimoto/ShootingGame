#pragma once
#include <string>
#include "DxLib.h"
#include "IScene.h"
#include "GameManager.h"
#include "GameConfig.h"
#include "GameData.h"
#include "SceneType.h"
#include "ScenePlay.h"
#include "EffectType.h"

class SceneClear
	: IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game)
	{		
		auto& player = game.getPlayer();
		auto& bulletManager = game.getBulletManager();
		auto& effect = game.getEffect();
		auto& enemy = game.getEnemy();
		auto& image = game.getImage();
		auto& soundContainer = game.getSoundContainer();
		auto& soundPlayer = game.getSoundPlayer();
		auto& drawer = game.getDrawer();


			player.movePlayer(bulletManager, game); // 自機の処理
			if (GameData::timer < GameConfig::FPS * 3) // ボスが爆発する演出
			{
				if (GameData::timer % 7 == 0)
				{
					effect.setEffect(enemy[GameData::bossIdx].x + rand() % 201 - 100,
						enemy[GameData::bossIdx].y + rand() % 201 - 100,
						EffectType::Explode,image);
				}
			}
			else if (GameData::timer == GameConfig::FPS * 3)
			{
				soundPlayer.play(soundContainer.jinClear); // ジングル出力
			}
			else
			{
				drawer.drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "STAGE CLEAR!", 0x00ffff, 80);
			}
			if (GameData::timer > GameConfig::FPS * 10) // ゲームプレイへ遷移
			{
				GameData::stage++;
				GameData::distance = GameConfig::STAGE_DISTANCE;
				return std::make_shared<ScenePlay>();
			
			}
			return nullptr;
	}
};