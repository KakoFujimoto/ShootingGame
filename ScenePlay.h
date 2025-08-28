#pragma once
#include <string>
#include "IScene.h"
#include "GameManager.h"
#include "GameConfig.h"
#include "BulletManager.h"
#include "GameData.h"
#include "EnemyType.h"
#include "SceneType.h"

class BulletManager;

class ScenePlay
	: IScene
{
public:
	virtual std::shared_ptr<IScene> run(GameManager& game)
	{	
		auto& player = game.getPlayer();
		auto& bullet = game.getBullet();

		int playerShield = player.getShield();

		player.movePlayer(bullet);


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
			EnemyType e = static_cast<EnemyType>(1 + rand() % 2);

			if (e == EnemyType::Zako1) setEnemy(x, y, 0, 3, EnemyType::Zako1, GameData::imgEnemy[Zako1], 1);
			if (e == EnemyType::Zako2) {
				int vx = 0;
				if (GameData::player.x < x - 50) vx = -3;
				if (GameData::player.x > x + 50) vx = 3;
				setEnemy(x, -100, vx, 5, EnemyType::Zako2, GameData::imgEnemy[Zako2], 3);
			}
		}
		if (300 < GameData::distance && GameData::distance < 900 && GameData::distance % 30 == 0) // �U�R3�̏o��
		{
			int x = 100 + rand() % (GameConfig::WIDTH - 200);
			int y = -50;
			int vy = 40 + rand() % 20;
			setEnemy(x, -100, 0, vy, EnemyType::Zako3, GameData::imgEnemy[Zako3], 5);
		}
		if (GameData::distance == 1) GameData::bossIdx = setEnemy(GameConfig::WIDTH / 2, -120, 0, 1, EnemyType::Boss, GameData::imgEnemy[Boss], 200); // �{�X�o��
		if (GameData::distance % 800 == 1) setItem(); // �A�C�e���̏o��
		if (playerShield == 0)
		{
			StopSoundMem(GameData::bgm); // �a�f�l��~
			GameData::scene = OVER; // SceneManager��OVER�ɐݒ肷��H
			GameData::timer = 0;
			break;
		}
		break;
	}
};#pragma once
