#include "BulletManager.h"
#include "GameManager.h"
#include "IMovable.h"

BulletManager::BulletManager() {
	bullets.resize(GameConfig::BULLET_MAX);
}


// 弾のセット（発射）
	void BulletManager::setBullet(const Player& player, GameManager& game)
	{	
		auto& soundPlayer = game.getSoundPlayer();
		auto& soundContainer = game.getSoundContainer();

		for (int n = 0; n < game.getGameData().weaponLv; n++) {

			int x = player.getX() - (game.getGameData().weaponLv - 1) * 5 + n * 10;
			int y = player.getY() - 20;
			for (auto& b : bullets) {
				if (b.getState() == 0) {
					b.reset(x, y);
					break;
				}
			}
		}
		soundPlayer.play(soundContainer.seShot);
	}

	// 弾の移動
	void BulletManager::moveBullet(ImageContainer& imageContainer, GameManager& game)
	{
		for (auto& b : bullets) {
			if (b.getState() == 0) continue; // 空いている配列なら処理しない
			 b.update(imageContainer, game);
		}
	}

	Bullet& BulletManager::getBullet(int index)
	{
		return bullets[index];
	}