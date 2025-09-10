#include "Player.h"
#include "GameManager.h"
#include "GameConfig.h"
#include "GameData.h"
#include "BulletManager.h"
#include "DxLib.h"

void Player::movePlayer(BulletManager& bulletManager, GameManager& game)
{
	static char oldSpcKey; // 1つ前のスペースキーの状態を保持する変数
	static int countSpcKey; // スペースキーを押し続けている間、カウントアップする変数


	if (CheckHitKey(KEY_INPUT_UP)) { // 上キー
		y -= vy;
		if (y < 30)
		{
			y = 30;
		}
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) { // 下キー
		y += vy;
		if (y > GameConfig::HEIGHT - 30)
		{
			y = GameConfig::HEIGHT - 30;
		}
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) { // 左キー
		x -= vx;
		if (x < 30)
		{
			x = 30;
		}
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) { // 右キー
		x += vx;
		if (x > GameConfig::WIDTH - 30)
		{
			x = GameConfig::WIDTH - 30;
		}
	}
	if (CheckHitKey(KEY_INPUT_SPACE)) { // スペースキー
		countSpcKey++;

			// 2秒押しっぱなしなら連射モードON
			if (countSpcKey >= GameConfig::RapidModeThreshold) {
				game.getGameData().isRapidMode = true;
			}

			int interval = game.getGameData().isRapidMode
				? GameConfig::FireIntervalHidden
				: GameConfig::FireInterval;

			// 発射タイミング
			if (countSpcKey == 1 || countSpcKey % interval == 0) {
				bulletManager.setBullet(*this, game); // 押した瞬間、発射

			}
		}
		else {
			// 離したらリセット
			countSpcKey = 0;
			game.getGameData().isRapidMode = false;
		}
	oldSpcKey = CheckHitKey(KEY_INPUT_SPACE); // スペースキーの状態を保持

	int& noDamage = game.getGameData().noDamage;

	if (noDamage > 0)
	{
		noDamage--; // 無敵時間のカウント
	}

	if (noDamage % 4 < 2)
	{	
		auto& drawer = game.getDrawer();
		auto& image = game.getImage();

		drawer.drawImage(image.getFighter(), x, y); // 自機の描画
	}
}