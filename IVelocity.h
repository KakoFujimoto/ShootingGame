#pragma once

class IVelocity
{
public:
	virtual ~IVelocity() = default;

	// xç¿ïW
	virtual int getVX() const = 0;
	virtual void setVX(int) = 0;
	// yç¿ïW
	virtual int getVY() const = 0;
	virtual void setVY(int) = 0;
};