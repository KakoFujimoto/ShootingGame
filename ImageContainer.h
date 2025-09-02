#pragma once
#include <string>
#include "Image.h"
#include "GameConfig.h"
#include "EnemyType.h"

class ImageContainer
{
public:
	ImageContainer() {}


	/*getter�͕K�v�ɂȂ������_�Œǉ�����*/

	const Image& getGalaxy() const
	{
		return imgGalaxy;
	}
	const Image& getBullet() const
	{
		return imgBullet;
	}
	const Image& getExplosion() const
	{
		return imgExplosion;
	}
	const Image& getItem() const
	{
		return imgItem;
	}
	const Image& getFighter() const
	{
		return imgFighter;
	}
	// Enemy�̔z��S�̂�Ԃ�
	const std::array<Image, GameConfig::IMG_ENEMY_MAX>& getEnemy() const
	{
		return imgEnemy;
	}
	// ����̎�ނ�Enemy��Ԃ�
	const Image& getEnemy(EnemyType type) const
	{
		return imgEnemy.at(static_cast<int>(type));
	}
	const Image& getFloor() const
	{
		return imgFloor;
	}
	const Image& getWallL() const
	{
		return imgWallL;
	}
	const Image& getWallR() const
	{
		return imgWallR;
	}

	void load();

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
