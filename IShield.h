#pragma once

class IShield
{
public:
	virtual ~IShield() = default;
	virtual void setShield(int v) = 0;
	virtual int getShield() const = 0;

};