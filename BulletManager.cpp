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
		PlaySoundMem(GameData::seShot, DX_PLAYTYPE_BACK); // ���ʉ�
	}

	// �e�̈ړ�
	void moveBullet(void)
	{
		for (int i = 0; i < GameConfig::BULLET_MAX; i++) {
			if (bullet[i].getState() == 0) continue; // �󂢂Ă���z��Ȃ珈�����Ȃ�
			bullet[i].setX(bullet[i].getX() + bullet[i].getVX()); // �� ���W��ω�������
			bullet[i].setY(bullet[i].getY() + bullet[i].getVY()); // ��
			drawImage(imageContainer.getBullet(), bullet[i].getX(), bullet[i].getY()); // �e�̕`�恦drawImage�͖�����
			if (bullet[i].getY() < -100)
			{
				bullet[i].setState(0); // ��ʊO�ɏo����A���݂��Ȃ���Ԃɂ���
			}
		}
	}
};