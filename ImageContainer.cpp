#include"ImageContainer.h"
#include <DxLib.h>


void ImageContainer::load()
{
    imgGalaxy.setId(LoadGraph("image/bg0.png"));
    imgFloor.setId(LoadGraph("image/floor.png"));
    imgWallL.setId(LoadGraph("image/bg2.png"));
    imgWallR.setId(LoadGraph("image/bg3.png"));

    imgFighter.setId(LoadGraph("image/fighter.png"));
    imgBullet.setId(LoadGraph("image/bullet.png"));

    for (int i = 0; i < GameConfig::IMG_ENEMY_MAX; i++)
    {
        std::string file = "image/enemy" + std::to_string(i) + ".png";
        imgEnemy[i] = LoadGraph(file.c_str());
    }

    imgExplosion.setId(LoadGraph("image/explosion.png"));
    imgItem.setId(LoadGraph("image/item.png"));
}