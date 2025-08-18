#pragma once
#include "IPosition.h"
#include "IVelocity.h"


class Player : public IPosition, IVelocity
{
	int x;
	int y;
	int vx;
	int vy;

public:
	int getX() const override { return x; }
	void setX(int v)  override { x = v; }

	int getY() const override { return y; }
	void setY(int v)  override { y = v; }

	int getVX() const override { return vx; }
	void setVX(int v) override { vx = v; }

	int getVY() const override { return vy; }
	void setVY(int v) override { vy = v; }
};
