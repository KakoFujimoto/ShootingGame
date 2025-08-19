#pragma once

class ISize
{
public:
	virtual ~ISize() = default;

	virtual void setWidth(int v) = 0;
	virtual int getWidth() const = 0;

	virtual void setHeight(int v) = 0;
	virtual int getHeight() const = 0;
};