#pragma once
#include "IPosition.h"

class Player : public IPosition
{
	int x;
	int y;
public:
	int getX() const override { return x; }
	void setX(int v)  override { x = v; }

	int getY() const override { return x; }
	void setY(int v)  override { y = v; }

};
