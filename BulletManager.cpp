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
		PlaySoundMem(GameData::seShot, DX_PLAYTYPE_BACK); // ���ʉ�
	}

	// �e�̈ړ�
	void moveBullet(void)
	{
		for (int i = 0; i < GameConfig::BULLET_MAX; i++) {
			if (GameData::bullet[i].state == 0) continue; // �󂢂Ă���z��Ȃ珈�����Ȃ�
			GameData::bullet[i].x += GameData::bullet[i].vx; // �� ���W��ω�������
			GameData::bullet[i].y += GameData::bullet[i].vy; // ��
			drawImage(GameData::imgBullet, GameData::bullet[i].x, GameData::bullet[i].y); // �e�̕`��
			if (GameData::bullet[i].y < -100) GameData::bullet[i].state = 0; // ��ʊO�ɏo����A���݂��Ȃ���Ԃɂ���

};