#pragma once
#include "IPosition.h"
#include "IVelocity.h"
#include "IState.h"
#include "IPattern.h"
#include "IImage.h"


class Player : public IPosition, IVelocity, IState, IPattern, IImage
{
	int x;
	int y;
	int vx;
	int vy;
	int state;
	int pattern;
	int image;

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
};
