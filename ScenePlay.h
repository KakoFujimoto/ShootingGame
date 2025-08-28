#pragma once
#include <string>
#include "IScene.h"
#include "GameManager.h"
#include "GameConfig.h"

class ScenePlay
	: IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game)
	{
		movePlayer(); // ���@�̑���
		if (GameData::distance == GameConfig::STAGE_DISTANCE)
		{
			srand(GameData::stage); // �X�e�[�W�̃p�^�[�������߂�
			PlaySoundMem(GameData::bgm, DX_PLAYTYPE_LOOP); // �a�f�l���[�v�o��
		}
		if (GameData::distance > 0) GameData::distance--;
		if (300 < GameData::distance && GameData::distance % 20 == 0) // �U�R1��2�̏o��
		{
			int x = 100 + rand() % (GameConfig::WIDTH - 200);
			int y = -50;
			int e = 1 + rand() % 2;
			if (e == ENE_ZAKO1) setEnemy(x, y, 0, 3, ENE_ZAKO1, GameData::imgEnemy[ENE_ZAKO1], 1);
			if (e == ENE_ZAKO2) {
				int vx = 0;
				if (GameData::player.x < x - 50) vx = -3;
				if (GameData::player.x > x + 50) vx = 3;
				setEnemy(x, -100, vx, 5, ENE_ZAKO2, GameData::imgEnemy[ENE_ZAKO2], 3);
			}
		}
		if (300 < GameData::distance && GameData::distance < 900 && GameData::distance % 30 == 0) // �U�R3�̏o��
		{
			int x = 100 + rand() % (GameConfig::WIDTH - 200);
			int y = -50;
			int vy = 40 + rand() % 20;
			setEnemy(x, -100, 0, vy, ENE_ZAKO3, GameData::imgEnemy[ENE_ZAKO3], 5);
		}
		if (GameData::distance == 1) GameData::bossIdx = setEnemy(GameConfig::WIDTH / 2, -120, 0, 1, ENE_BOSS, GameData::imgEnemy[ENE_BOSS], 200); // �{�X�o��
		if (GameData::distance % 800 == 1) setItem(); // �A�C�e���̏o��
		if (GameData::player.shield == 0)
		{
			StopSoundMem(GameData::bgm); // �a�f�l��~
			GameData::scene = OVER;
			GameData::timer = 0;
			break;
		}
		break;
	}
};#pragma once
