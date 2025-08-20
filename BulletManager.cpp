#include "Bullet.h"
#include "GameData.h"
#include "Player.h"

Player player = Player();

class BulletManager
{
	void setBullet(void)
	{
		for (int n = 0; n < GameData::weaponLv; n++) {
			int x = player.getX() - (GameData::weaponLv - 1) * 5 + n * 10;
			int y = GameData::player.y - 20;
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
		PlaySoundMem(GameData::seShot, DX_PLAYTYPE_BACK); // Œø‰Ê‰¹
	}

	// ’e‚ÌˆÚ“®
	void moveBullet(void)
	{
		for (int i = 0; i < GameConfig::BULLET_MAX; i++) {
			if (GameData::bullet[i].state == 0) continue; // ‹ó‚¢‚Ä‚¢‚é”z—ñ‚È‚çˆ—‚µ‚È‚¢
			GameData::bullet[i].x += GameData::bullet[i].vx; // „¦ À•W‚ð•Ï‰»‚³‚¹‚é
			GameData::bullet[i].y += GameData::bullet[i].vy; // „£
			drawImage(GameData::imgBullet, GameData::bullet[i].x, GameData::bullet[i].y); // ’e‚Ì•`‰æ
			if (GameData::bullet[i].y < -100) GameData::bullet[i].state = 0; // ‰æ–ÊŠO‚Éo‚½‚çA‘¶Ý‚µ‚È‚¢ó‘Ô‚É‚·‚é

};