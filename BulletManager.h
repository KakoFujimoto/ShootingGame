#pragma once
#include <vector>
#include "Bullet.h"

class ImageContainer;

class BulletManager {
public:
	// �e�̈ړ�
	void setBullet(const Player& player);


	// �e�̃Z�b�g�i���ˁj
	void moveBullet(ImageContainer& imageContainer);

private:
	std::vector<Bullet> bullets;
};