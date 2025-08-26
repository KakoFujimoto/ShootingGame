#pragma once

class Image;

class IImage
{
public:
	virtual ~IImage() = default;

	virtual void setImage(const Image* v) = 0;
	virtual const Image* getImage() const = 0;
};
