#pragma once
#include<array>

class Image
{
public:
	Image() : imageId(-1) {}
	Image(int id)
		: imageId(id)
	{
	}

	void setId(int id)
	{
		imageId = id;
	}
	int getId() const
	{
		return imageId;
	}

private:
	int imageId;
};


//void someFunc()
//{
//	ImageContainer container;
//
//	drawImage(container.getGalaxy(), 0, 0);
//}
//
//void drawImage(const Image& image, int x, int y)
//{
//	int w, h;
//	GetGraphSize(image.getId(), &w, &h);
//	DrawGraph(x - w / 2, y - h / 2, image.getId(), TRUE);
//}
