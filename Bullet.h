#pragma once
#include <array>
#include "GameConfig.h"
#include "IState.h"
#include "IImage.h"
#include "IMovable.h"


class Bullet : public IState,
			   public IImage,
			   public IMovable
{
	int x;
	int y;
	int vx;
	int vy;
	int state;
	const Image* image;

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

	void setImage(const Image* v) override { image = v; }
	const Image* getImage() const override { return image; }
};