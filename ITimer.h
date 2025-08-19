#pragma once

class ITimer
{
public:
	virtual ~ITimer() = default;
	virtual void setTimer(int v) = 0;
	virtual int getTimer() const = 0;

};
