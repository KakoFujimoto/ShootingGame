#include "BulletManager.h"
#include "GameData.h"
#include "Player.h"
#include "DxLib.h"
#include "ImageContainer.h"
#include "GameManager.h"


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

	// ’e‚ÌˆÚ“®
	void BulletManager::moveBullet(ImageContainer& imageContainer, GameManager& game)
	{
		for (auto& b : bullets) {
			if (b.getState() == 0) continue; // ‹ó‚¢‚Ä‚¢‚é”z—ñ‚È‚çˆ—‚µ‚È‚¢
			b.setX(b.getX() + b.getVX()); // „¦ À•W‚ð•Ï‰»‚³‚¹‚é
			b.setY(b.getY() + b.getVY()); // „£
			game.getDrawer().drawImage(imageContainer.getBullet().getId(), b.getX(), b.getY()); // ’e‚Ì•`‰æ¦drawImage‚Í–¢ŽÀ‘•
			if (b.getY() < -100)
			{
				b.setState(0); // ‰æ–ÊŠO‚Éo‚½‚çA‘¶Ý‚µ‚È‚¢ó‘Ô‚É‚·‚é
			}
		}
	}
