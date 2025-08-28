#pragma once
#include <array>
#include "GameConfig.h"
#include "IPosition.h"
#include "IState.h"
#include "IImage.h"
#include "EffectType.h"
#include "ITimer.h"

class Effect : public IPosition, IState, IImage, ITimer
{
	int x;
	int y;
	int state;
	EffectType pattern;
	const Image* image;
	int width;
	int height;
	int timer;

public:
	void setX(int v)  override { x = v; }
	int getX() const override { return x; }

	void setY(int v)  override { y = v; }
	int getY() const override { return y; }

	void setState(int v) override { state = v; }
	int getState() const override { return state; }

	void setPattern(EffectType v) { pattern = v; }
	EffectType getPattern() const { return pattern; }

	void setImage(const Image* v) override { image = v; }
	const Image* getImage() const override { return image; }

	void setTimer(int v) override { timer = v; }
	int getTimer() const override { return timer; }
};