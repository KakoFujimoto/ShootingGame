#pragma once

class IVelocity
{
public:
	virtual ~IVelocity() = default;

	// x���W
	virtual void setVX(int) = 0;
	virtual int getVX() const = 0;

	// y���W
	virtual void setVY(int) = 0;
	virtual int getVY() const = 0;

};