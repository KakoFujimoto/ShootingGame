#pragma once

class IImage
{
public:
	virtual ~IImage() = default;

	virtual void setImage(int v) = 0;
	virtual int getImage() const = 0;

};