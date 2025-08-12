#pragma once
#include <array>
#include "GameConfig.h"

class Image
{
public:
	// �C���X�^���X�擾
	static Image &instance();

	// �R�s�[�֎~
	Image(const Image &) = delete;
	Image &operator=(const Image &) = delete;

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

private:
	// �R���X�g���N�^(�摜�ǂݍ���)
	Image();
};