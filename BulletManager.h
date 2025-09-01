#pragma once
#include <vector>
#include "Bullet.h"
#include "GameManager.h"


class ImageContainer;

class BulletManager {
public:
	BulletManager() {
		bullets.resize(GameConfig::BULLET_MAX);
	}

	// 弾の移動
	void setBullet(const Player& player);


	// 弾のセット（発射）
	void moveBullet(ImageContainer& imageContainer, GameManager& game);

private:
	std::vector<Bullet> bullets;
};