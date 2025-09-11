#pragma once
#include <vector>
#include "Bullet.h"
#include "Player.h"


class ImageContainer;

class BulletManager
{
public:
	BulletManager();
	void setBullet(const Player& player, GameManager& game); // 弾のセット（発射）
	void moveBullet(ImageContainer& imageContainer, GameManager& game); // 弾の移動
	Bullet& getBullet(int index);

private:
	std::vector<Bullet> bullets;
};