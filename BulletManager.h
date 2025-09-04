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

	// 弾のセット（発射）
	void setBullet(const Player& player, GameManager& game);

	// 弾の移動
	void moveBullet(ImageContainer& imageContainer, GameManager& game);

private:
	std::vector<Bullet> bullets;
};