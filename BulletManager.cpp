#include "BulletManager.h"
#include "GameData.h"
#include "Player.h"
#include "DxLib.h"
#include "ImageContainer.h"


	void BulletManager::setBullet(const Player& player)
	{
		for (int n = 0; n < GameData::weaponLv; n++) {
			int x = player.getX() - (GameData::weaponLv - 1) * 5 + n * 10;
			int y = player.getY() - 20;
			for (auto& b : bullets) {
				if (b.getState() == 0) {
					b.setX(x);
					b.setY(y);
					b.setVX(0);
					b.setVY(-40);
					b.setState(1);
					break;
				}
			}
		}
		PlaySoundMem(GameData::seShot, DX_PLAYTYPE_BACK); // ���ʉ�
	}

	// �e�̈ړ�
	void BulletManager::moveBullet(ImageContainer& imageContainer, GameManager& game)
	{
		for (auto& b : bullets) {
			if (b.getState() == 0) continue; // �󂢂Ă���z��Ȃ珈�����Ȃ�
			b.setX(b.getX() + b.getVX()); // �� ���W��ω�������
			b.setY(b.getY() + b.getVY()); // ��
			game.getDrawer().drawImage(imageContainer.getBullet().getId(), b.getX(), b.getY()); // �e�̕`�恦drawImage�͖�����
			if (b.getY() < -100)
			{
				b.setState(0); // ��ʊO�ɏo����A���݂��Ȃ���Ԃɂ���
			}
		}
	}
