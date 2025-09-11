#pragma once
#include <vector>
#include "Bullet.h"
#include "Player.h"


class ImageContainer;

class BulletManager
{
public:
	BulletManager();
	void setBullet(const Player& player, GameManager& game); // �e�̃Z�b�g�i���ˁj
	void moveBullet(ImageContainer& imageContainer, GameManager& game); // �e�̈ړ�
	Bullet& getBullet(int index);

private:
	std::vector<Bullet> bullets;
};