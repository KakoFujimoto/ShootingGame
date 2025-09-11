#pragma once
#include "IPosition.h"
#include "IVelocity.h"


class IMovable : public IPosition, public IVelocity
{
public:
	virtual void updatePosition()
	{
		setX(getX() + getVX());
		setY(getY() + getVY());
	}
};