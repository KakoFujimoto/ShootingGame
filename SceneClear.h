#pragma once
#include <string>
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
		auto& bullet = game.getBullet();
		auto& effect = game.getEffect();



			player.movePlayer(bullet); // 自機の処理
			if (GameData::timer < GameConfig::FPS * 3) // ボスが爆発する演出
			{
				if (GameData::timer % 7 == 0)
				{
					effect.setEffect(GameData::enemy[GameData::bossIdx].x + rand() % 201 - 100, GameData::enemy[GameData::bossIdx].y + rand() % 201 - 100, EffectType::Explode);
				}
			}
			else if (GameData::timer == GameConfig::FPS * 3)
			{
				PlaySoundMem(GameData::jinClear, DX_PLAYTYPE_BACK); // ジングル出力
			}
			else
			{
				drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "STAGE CLEAR!", 0x00ffff, 80);
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