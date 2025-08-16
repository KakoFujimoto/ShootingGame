#include "Bullet.h"
#include "DxLib.h"
#include "GameObject.h"
#include "GameState.h"
#include "Image.h"

// 弾の移動
// GameData相当の部品がないとこのままでは書けない？
void Bullet::moveBullet(Player& player, int weaponLevel)
{
	for (int n = 0; n < weaponLv; n++) {
		int x = player.x - (weaponLv - 1) * 5 + n * 10;
		int y = player.y - 20;
		for (int i = 0; i < GameConfig::BULLET_MAX; i++) {
			if (GameData::bullet[i].state == 0) {
				GameData::bullet[i].x = x;
				GameData::bullet[i].y = y;
				GameData::bullet[i].vx = 0;
				GameData::bullet[i].vy = -40;
				GameData::bullet[i].state = 1;
				break;
			}
		}
	}
}

// 弾のセット（発射）
void Bullet::setBullet()
{

}