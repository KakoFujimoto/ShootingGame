#pragma once
#include <array>
#include "GameConfig.h"
#include "IPosition.h"
#include "IState.h"
#include "IImage.h"
#include "ISize.h"
#include "IShield.h"
#include "ITimer.h"
#include "EffectType.h"

class Effect : public IPosition, IState, IImage, ISize, IShield, ITimer
{
	int x;
	int y;
	int vx;
	int vy;
	int state;
	EffectType pattern;
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

	void setVX(int v) { vx = v; }
	int getVX() const { return vx; }

	void setVY(int v) { vy = v; }
	int getVY() const { return vy; }

	void setState(int v) override { state = v; }
	int getState() const override { return state; }

	void setPattern(EffectType v) { pattern = v; }
	EffectType getPattern() const { return pattern; }

	void setImage(const Image* v) override { image = v; }
	const Image* getImage() const override { return image; }

	void setWidth(int v) override { width = v; }
	int getWidth() const override { return width; }

	void setHeight(int v) override { height = v; }
	int getHeight() const override { return height; }

	void setShield(int v) override { shield = v; }
	int getShield() const override { return shield; }

	void setTimer(int v) override { timer = v; }
	int getTimer() const override { return timer; }

};