#pragma once
#include <string>
#include "IScene.h"
#include "GameManager.h"
#include "GameConfig.h"

class SceneOver
	: IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game)
	{
			if (GameData::timer < GameConfig::FPS * 3) // 自機が爆発する演出
			{
				if (GameData::timer % 7 == 0) setEffect(GameData::player.x + rand() % 81 - 40, GameData::player.y + rand() % 81 - 40, EFF_EXPLODE);
			}
			else if (GameData::timer == GameConfig::FPS * 3)
			{
				PlaySoundMem(GameData::jinOver, DX_PLAYTYPE_BACK); // ジングル出力
			}
			else
			{
				drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "GAME OVER", 0xff0000, 80);
			}
			if (GameData::timer > GameConfig::FPS * 10) GameData::scene = TITLE; // タイトルへ遷移
			break;
	}
};