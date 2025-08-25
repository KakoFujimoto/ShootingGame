#pragma once
#include <string>
#include "Image.h"
#include "GameConfig.h"

class ImageContainer
{
public:
	ImageContainer() {}


	/*getterは必要になった時点で追加する*/

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

	void load();

private:
	// 背景画像
	Image imgGalaxy;
	Image imgFloor;
	Image imgWallL;
	Image imgWallR;
	// 自機と自機の弾の画像
	Image imgFighter;
	Image imgBullet;
	// 敵機の画像
	std::array<Image, GameConfig::IMG_ENEMY_MAX> imgEnemy;
	// 爆発演出の画像
	Image imgExplosion;
	// アイテムの画像
	Image imgItem;
};
