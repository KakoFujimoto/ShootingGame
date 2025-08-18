#pragma once

class IVelocity
{
public:
	virtual ~IVelocity() = default;

	// x���W
	virtual int getVX() const = 0;
	virtual void setVX(int) = 0;
	// y���W
	virtual int getVY() const = 0;
	virtual void setVY(int) = 0;
};