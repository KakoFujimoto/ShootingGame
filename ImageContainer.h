#pragma once
#include <string>
#include "Image.h"
#include "GameConfig.h"
#include "EnemyType.h"

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
	const Image& getFighter() const
	{
		return imgFighter;
	}
	// Enemyの配列全体を返す
	const std::array<Image, GameConfig::IMG_ENEMY_MAX>& getEnemy() const
	{
		return imgEnemy;
	}
	// 特定の種類のEnemyを返す
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
