#include "Image.h"
#include <DxLib.h>

// コンストラクタ(画像読み込み)
void Image::load()
{
    imgGalaxy = LoadGraph("image/bg0.png");
    imgFloor = LoadGraph("image/floor.png");
    imgWallL = LoadGraph("image/wallL.png");
    imgWallR = LoadGraph("image/wallR.png");

    imgFighter = LoadGraph("image/fighter.png");
    imgBullet = LoadGraph("image/bullet.png");

    for (int i = 0; i < GameConfig::IMG_ENEMY_MAX; i++)
    {
        std::string file = "image/enemy" + std::to_string(i) + ".png";
        imgEnemy[i] = LoadGraph(file.c_str());
    }

    imgExplosion = LoadGraph("image/explosion.png");
    imgItem = LoadGraph("image/item.png");
}