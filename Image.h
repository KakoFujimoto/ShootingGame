#pragma once
#include <array>
#include <string>
#include "GameConfig.h"

class Image
{
public:
	Image() = default;
	void load();

	// �w�i�摜
	int imgGalaxy;
	int imgFloor;
	int imgWallL;
	int imgWallR;
	// ���@�Ǝ��@�̒e�̉摜
	int imgFighter;
	int imgBullet;
	// �G�@�̉摜
	std::array<int, GameConfig::IMG_ENEMY_MAX> imgEnemy;
	// �������o�̉摜
	int imgExplosion;
	// �A�C�e���̉摜
	int imgItem;
};