#include "BulletManager.h"
#include "GameManager.h"

BulletManager::BulletManager() {
	bullets.resize(GameConfig::BULLET_MAX);
}


// �e�̃Z�b�g�i���ˁj
	void BulletManager::setBullet(const Player& player, GameManager& game)
	{	
		auto& soundPlayer = game.getSoundPlayer();
		auto& soundContainer = game.getSoundContainer();

		for (int n = 0; n < game.getGameData().weaponLv; n++) {

			int x = player.getX() - (game.getGameData().weaponLv - 1) * 5 + n * 10;
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
		soundPlayer.play(soundContainer.seShot);
	}

	// �e�̈ړ�
	void BulletManager::moveBullet(ImageContainer& imageContainer, GameManager& game)
	{
		for (auto& b : bullets) {
			if (b.getState() == 0) continue; // �󂢂Ă���z��Ȃ珈�����Ȃ�
			b.setX(b.getX() + b.getVX()); // �� ���W��ω�������
			b.setY(b.getY() + b.getVY()); // ��
			game.getDrawer().drawImage(imageContainer.getBullet(), b.getX(), b.getY()); // �e�̕`�恦drawImage�͖�����
			if (b.getY() < -100)
			{
				b.setState(0); // ��ʊO�ɏo����A���݂��Ȃ���Ԃɂ���
			}
		}
	}

	Bullet& BulletManager::getBullet(int index)
	{
		return bullets[index];
	}