#pragma once
#include "IImage.h"
#include "IShield.h"
#include "Image.h"
#include "ItemType.h"
#include "ITimer.h"
#include "IState.h"
#include "IMovable.h"


class Item : public IImage,
			 public IShield,
			 public ITimer,
			 public IState,
			 public IMovable
{
	int x;
	int y;
	int vx;
	int vy;
	int state;
	ItemType pattern;
	const Image* image;
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

	void setPattern(ItemType v) { pattern = v; }
	ItemType getPattern() const { return pattern; }

	void setImage(const Image* v) override { image = v; }
	const Image* getImage() const override { return image; }

	void setShield(int v) override { shield = v; }
	int getShield() const override { return shield; }

	void setTimer(int v) override { timer = v; }
	int getTimer() const override { return timer; }
};