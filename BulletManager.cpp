#include "Bullet.h"
#include "GameData.h"
#include "Player.h"
#include "DxLib.h"
#include "ImageContainer.h"

Player player;
Bullet bullet[GameConfig::BULLET_MAX];
ImageContainer imageContainer;

class BulletManager
{
	void setBullet(void)
	{
		for (int n = 0; n < GameData::weaponLv; n++) {
			int x = player.getX() - (GameData::weaponLv - 1) * 5 + n * 10;
			int y = player.getY() - 20;
			for (int i = 0; i < GameConfig::BULLET_MAX; i++) {
				if (bullet[i].getState() == 0) {
					bullet[i].setX(x);
					bullet[i].setY(y);
					bullet[i].setVX(0);
					bullet[i].setVY(-40);
					bullet[i].setState(1);
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
			if (bullet[i].getState() == 0) continue; // ‹ó‚¢‚Ä‚¢‚é”z—ñ‚È‚çˆ—‚µ‚È‚¢
			bullet[i].setX(bullet[i].getX() + bullet[i].getVX()); // „¦ À•W‚ð•Ï‰»‚³‚¹‚é
			bullet[i].setY(bullet[i].getY() + bullet[i].getVY()); // „£
			drawImage(imageContainer.getBullet(), bullet[i].getX(), bullet[i].getY()); // ’e‚Ì•`‰æ¦drawImage‚Í–¢ŽÀ‘•
			if (bullet[i].getY() < -100)
			{
				bullet[i].setState(0); // ‰æ–ÊŠO‚Éo‚½‚çA‘¶Ý‚µ‚È‚¢ó‘Ô‚É‚·‚é
			}
		}
	}
};