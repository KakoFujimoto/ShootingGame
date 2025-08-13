#pragma once
#include <array>
#include <string>
#include "GameConfig.h"

class Image
{
public:
	Image() = default;
	void load();

	// 背景画像
	int imgGalaxy;
	int imgFloor;
	int imgWallL;
	int imgWallR;
	// 自機と自機の弾の画像
	int imgFighter;
	int imgBullet;
	// 敵機の画像
	std::array<int, GameConfig::IMG_ENEMY_MAX> imgEnemy;
	// 爆発演出の画像
	int imgExplosion;
	// アイテムの画像
	int imgItem;
};