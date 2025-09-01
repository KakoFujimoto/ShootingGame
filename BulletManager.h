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

	// �e�̈ړ�
	void setBullet(const Player& player);


	// �e�̃Z�b�g�i���ˁj
	void moveBullet(ImageContainer& imageContainer, GameManager& game);

private:
	std::vector<Bullet> bullets;
};