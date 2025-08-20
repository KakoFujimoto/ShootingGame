#pragma once
#include <array>
#include "GameConfig.h"
#include "IPosition.h"
#include "IVelocity.h"
#include "IState.h"
#include "IPattern.h"
#include "IImage.h"
#include "ISize.h"
#include "IShield.h"
#include "ITimer.h"

class Bullet : public IPosition, IVelocity, IState, IPattern, IImage, ISize, IShield, ITimer
{
	int x;
	int y;
	int vx;
	int vy;
	int state;
	int pattern;
	int image;
	int width;
	int height;
	int shield;
	int timer;

public:
	void setX(int v)  override { x = v; }
	int getX() const override { return x; }

	void setY(int v)  override { y = v; }
	int getY() const override { return y; }

	void setVX(int v) override { vx = v; }
	int getVX() const override { return vx; }

	void setVY(int v) override { vy = v; }
	int getVY() const override { return vy; }

	void setState(int v) override { state = v; }
	int getState() const override { return state; }

	void setPattern(int v) override { pattern = v; }
	int getPattern() const override { return pattern; }

	void setImage(int v) override { image = v; }
	int getImage() const override { return image; }

	void setWidth(int v) override { width = v; }
	int getWidth() const override { return width; }

	void setHeight(int v) override { height = v; }
	int getHeight() const override { return height; }

	void setShield(int v) override { shield = v; }
	int getShield() const override { return shield; }

	void setTimer(int v) override { timer = v; }
	int getTimer() const override { return timer; }

};


//class BulletManager {
//public:
//	// �e�̈ړ�
//	void moveBullet();
//
//	// �e�̃Z�b�g�i���ˁj
//	void setBullet();
//
//private:
//	std::vector<Bullet> bullets;
//};