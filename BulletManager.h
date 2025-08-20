#pragma once
class BulletManager {
public:
	// 弾の移動
	void moveBullet();

	// 弾のセット（発射）
	void setBullet();

private:
	std::vector<Bullet> bullets;
};