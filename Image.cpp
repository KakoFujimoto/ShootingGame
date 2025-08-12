#include "Image.h"
#include <DxLib.h>

// コンストラクタ(画像読み込み)
Image::Image()
{
    imgGalaxy = LoadGraph("image/bg0.png");
    imgFloor = LoadGraph("image/floor.png");
    imgWallL = LoadGraph("image/wallL.png");
    imgWallR = LoadGraph("image/wallR.png");
    imgFighter = LoadGraph("image/fighter.png");
    imgBullet = LoadGraph("image/bullet.png");
    imgEnemy[0] = LoadGraph("image/enemy0.png");
    imgEnemy[1] = LoadGraph("image/enemy1.png");
    imgEnemy[2] = LoadGraph("image/enemy2.png");
    imgEnemy[3] = LoadGraph("image/enemy3.png");
    imgEnemy[4] = LoadGraph("image/enemy4.png");
    imgExplosion = LoadGraph("image/explosion.png");
    imgItem = LoadGraph("image/item.png");
}