#pragma once
class BulletManager {
public:
	// �e�̈ړ�
	void moveBullet();

	// �e�̃Z�b�g�i���ˁj
	void setBullet();

private:
	std::vector<Bullet> bullets;
};