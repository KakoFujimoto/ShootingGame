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

	// �e�̃Z�b�g�i���ˁj
	void setBullet(const Player& player, GameManager& game);

	// �e�̈ړ�
	void moveBullet(ImageContainer& imageContainer, GameManager& game);

private:
	std::vector<Bullet> bullets;
};