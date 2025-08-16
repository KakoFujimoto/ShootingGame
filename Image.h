#pragma once
#include <array>
#include <string>
#include "GameConfig.h"

//class Image
//{
//public:
//	Image() = default;
//	void load();
//
//	// ”wŒi‰æ‘œ
//	int imgGalaxy;
//	int imgFloor;
//	int imgWallL;
//	int imgWallR;
//	// ©‹@‚Æ©‹@‚Ì’e‚Ì‰æ‘œ
//	int imgFighter;
//	int imgBullet;
//	// “G‹@‚Ì‰æ‘œ
//	std::array<int, GameConfig::IMG_ENEMY_MAX> imgEnemy;
//	// ”š”­‰‰o‚Ì‰æ‘œ
//	int imgExplosion;
//	// ƒAƒCƒeƒ€‚Ì‰æ‘œ
//	int imgItem;
//};
//

class Image
{
public:
	Image(int id)
		: imageId(id)
	{
	}

	int getId() const
	{
		return imageId;
	}

private:
	int imageId;
};

class ImageContainer
{
public:
	void load() {}

	const Image& getGalaxy() const
	{
		return imgGalaxy;
	}

private:
	Image imgGalaxy;
	Image imgFloor;
	Image imgWallL;
	Image imgWallR;
	Image imgFighter;
	Image imgBullet;
	// “G‹@‚Ì‰æ‘œ
	std::array<Image, GameConfig::IMG_ENEMY_MAX> imgEnemy;
	Image imgExplosion;
	Image imgItem;
};

void someFunc()
{
	ImageContainer container;

	drawImage(container.getGalaxy(), 0, 0);
}

void drawImage(const Image& image, int x, int y)
{
	int w, h;
	GetGraphSize(image.getId(), &w, &h);
	DrawGraph(x - w / 2, y - h / 2, image.getId(), TRUE);
}
