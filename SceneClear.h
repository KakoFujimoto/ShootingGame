#pragma once
#include <string>
#include "IScene.h"
#include "GameManager.h"
#include "GameConfig.h"

class SceneClear
	: IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game)
	{
			movePlayer(); // ���@�̏���
			if (GameData::timer < GameConfig::FPS * 3) // �{�X���������鉉�o
			{
				if (GameData::timer % 7 == 0) setEffect(GameData::enemy[GameData::bossIdx].x + rand() % 201 - 100, GameData::enemy[GameData::bossIdx].y + rand() % 201 - 100, EFF_EXPLODE);
			}
			else if (GameData::timer == GameConfig::FPS * 3)
			{
				PlaySoundMem(GameData::jinClear, DX_PLAYTYPE_BACK); // �W���O���o��
			}
			else
			{
				drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "STAGE CLEAR!", 0x00ffff, 80);
			}
			if (GameData::timer > GameConfig::FPS * 10) // �Q�[���v���C�֑J��
			{
				GameData::stage++;
				GameData::distance = GameConfig::STAGE_DISTANCE;
				GameData::scene = PLAY;
			}
			break;
			}
	}
};