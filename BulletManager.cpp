#include "BulletManager.h"
#include "GameManager.h"

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

	// 弾の移動
	void BulletManager::moveBullet(ImageContainer& imageContainer, GameManager& game)
	{
		for (auto& b : bullets) {
			if (b.getState() == 0) continue; // 空いている配列なら処理しない
			b.setX(b.getX() + b.getVX()); // ┬ 座標を変化させる
			b.setY(b.getY() + b.getVY()); // ┘
			game.getDrawer().drawImage(imageContainer.getBullet(), b.getX(), b.getY()); // 弾の描画※drawImageは未実装
			if (b.getY() < -100)
			{
				b.setState(0); // 画面外に出たら、存在しない状態にする
			}
		}
	}

	Bullet& BulletManager::getBullet(int index)
	{
		return bullets[index];
	}