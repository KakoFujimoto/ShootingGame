#include "Player.h"
#include "GameConfig.h"
#include "DxLib.h" //DXライブラリのインクルード

void Player::movePlayer()
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
		if (oldSpcKey == 0)
		{
			setBullet(); // 押した瞬間、発射
		}
		else if (countSpcKey % 20 == 0)
		{
			setBullet(); // 一定間隔で発射
		}
		countSpcKey++;
	}
	oldSpcKey = CheckHitKey(KEY_INPUT_SPACE); // スペースキーの状態を保持

	if (GameData::noDamage > 0)
	{
		GameData::noDamage--; // 無敵時間のカウント
	}

	if (GameData::noDamage % 4 < 2)
	{
		drawImage(GameData::imgFighter, GameData::player.x, GameData::player.y); // 自機の描画
	}
}