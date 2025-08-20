#pragma once
#include <string>
#include "Image.h"
#include "GameConfig.h"

class ImageContainer
{
public:
	ImageContainer() {}

	// ImageLoader�Ɉڊ�
	/*void load() {}*/

	/*getter�͕K�v�ɂȂ������_�Œǉ�����*/

	const Image& getGalaxy() const
	{
		return imgGalaxy;
	}
	const Image& getBullet() const
	{
		return imgBullet;
	}
private:
	// �w�i�摜
	Image imgGalaxy;
	Image imgFloor;
	Image imgWallL;
	Image imgWallR;
	// ���@�Ǝ��@�̒e�̉摜
	Image imgFighter;
	Image imgBullet;
	// �G�@�̉摜
	std::array<Image, GameConfig::IMG_ENEMY_MAX> imgEnemy;
	// �������o�̉摜
	Image imgExplosion;
	// �A�C�e���̉摜
	Image imgItem;
};
