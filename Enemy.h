#pragma once
#include <array>
#include "GameConfig.h"
#include "IState.h"
#include "IImage.h"
#include "ISize.h"
#include "IShield.h"
#include "EnemyType.h"
#include "IMovable.h"

class Enemy : public IState,
			  public IImage,
			  public ISize,
			  public IShield,
			  public IMovable
{
	int x;
	int y;
	int vx;
	int vy;
	int state;
	EnemyType pattern;
	const Image* image;
	int width;
	int height;
	int shield;

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

	void setPattern(EnemyType v) { pattern = v; }
	EnemyType getPattern() const { return pattern; }

	void setImage(const Image* v) override { image = v; }
	const Image* getImage() const override { return image; }

	void setWidth(int v) override { width = v; }
	int getWidth() const override { return width; }

	void setHeight(int v) override { height = v; }
	int getHeight() const override { return height; }

	void setShield(int v) override { shield = v; }
	int getShield() const override { return shield; }
};