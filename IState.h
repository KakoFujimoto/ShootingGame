#pragma once

class IState
{
public:
	virtual ~IState() = default;

	virtual void setState(int v) = 0;
	virtual int getState() const = 0;

};