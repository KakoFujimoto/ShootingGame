#pragma once
#include <array>
#include "GameConfig.h"

class Image
{
public:
	// インスタンス取得
	static Image &instance();

	// コピー禁止
	Image(const Image &) = delete;
	Image &operator=(const Image &) = delete;

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

private:
	// コンストラクタ(画像読み込み)
	Image();
};