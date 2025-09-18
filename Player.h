#pragma once
#include "IPosition.h"
#include "IImage.h"
#include "ISize.h"
#include "IShield.h"
#include "Image.h"
#include "IVelocity.h"

class BulletManager;
class GameManager;


class Player : public IPosition, IImage, ISize, IShield, IVelocity
{
	int x;
	int y;
	int vx;
	int vy;
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

	void setImage(const Image* v) override { image = v; }
	const Image* getImage() const override { return image; }

	void setWidth(int v) override { width = v; }
	int getWidth() const override { return width; }

	void setHeight(int v) override { height = v; }
	int getHeight() const override { return height; }

	void setShield(int v) override { shield = v; }
	int getShield() const override { return shield; }

	void movePlayer(BulletManager& bulletManager, GameManager& game);

	int& refWidth() { return width; }
	int& refHeight() { return height; }

private:
	int countSpcKey = 0; // スペースキーを押し続けている間、カウントアップする変数
};
