#pragma once

class IVelocity
{
public:
	virtual ~IVelocity() = default;

	// xç¿ïW
	virtual void setVX(int) = 0;
	virtual int getVX() const = 0;

	// yç¿ïW
	virtual void setVY(int) = 0;
	virtual int getVY() const = 0;

};