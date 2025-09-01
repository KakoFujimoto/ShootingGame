#include "Bullet.h"
#include "GameData.h"
#include "EnemyManager.h"
#include "DxLib.h"
#include "Image.h"
#include "EnemyType.h"

	// 敵機を動かす
	void EnemyManager::moveEnemy(GameManager& game)
	{
		for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
			auto& enemy = enemies[i];

			if (enemy.getState() == 0)
			{
				continue; // 空いている配列なら処理しない
			}
			if (enemy.getPattern() == EnemyType::Zako3) // ザコ機3
			{
				if (enemy.getVY() > 1) // 減速
				{
					enemy.setVY(enemy.getVY() * 0.9);
				}
				else if (enemy.getVY()y > 0) // 弾発射、飛び去る
				{
					setEnemy(enemy.getX(), enemy.getY(), 0, 6, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0); // 弾

					//GameData::enemy[i].vx = 8;
					enemy.setVX(8);
					//GameData::enemy[i].vy = -4;
					enemy.setVY(-4);
				}
			}
			if (enemy.getPattern() == EnemyType::Boss) // ボス機
			{
				if (enemy.getY() > GameConfig::HEIGHT - 120)
				{
					//GameData::enemy[i].vy = -2;
					enemy.setVY(-2);
				}
				if (enemy.getY() < 120) // 画面上端
				{
					if (enemy.getY() < 0) // 弾発射
					{
						for (int bx = -2; bx <= 2; bx++) // 二重ループのfor
							for (int by = 0; by <= 3; by++)
							{
								if (bx == 0 && by == 0) continue;
								setEnemy(enemy.getX(), enemy.getY(), bx * 2, by * 3, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0);
							}
					}
					enemy.setVY(2);
				}
			}
			enemy.setX(enemy.getX() + enemy.getVX()); //┬敵機の移動
			enemy.setY(enemy.getY() + enemy.getVY()); //┘


			drawImage(GameData::enemy[i].image, enemy.getX(), enemy.getY()); // 敵機の描画
			// 画面外に出たか？
			if (enemy.getX() < -200 || GameConfig::WIDTH + 200 < enemy.getX()
				|| enemy.getY() < -200 || GameConfig::HEIGHT + 200 < enemy.getY())
			{
				enemy.setState(0); // 画面外に出たら、存在しない状態にする
			}
			// 当たり判定のアルゴリズム
			if (enemy.getShield() > 0) // ヒットチェックを行う敵機（弾以外）
			{
				for (int j = 0; j < GameConfig::BULLET_MAX; j++) { // 自機の弾とヒットチェック
					auto& bullet = game.getBullet();
					if (bullet.getState() == 0)
					{
						continue;
					}
					int dx = abs((int)(enemy.getX() - bullet.getX())); //┬中心座標間のピクセル数
					int dy = abs((int)(enemy.getY() - bullet.getY())); //┘
					if (dx < enemy.getWidth() / 2 && dy < enemy.getHeight() / 2) // 接触しているか
					{
						bullet.setState(0); // 弾を消す
						damageEnemy(i, 1); // 敵にダメージ
					}
				}
			}
			if (GameData::noDamage == 0) // 無敵状態でない時、自機とヒットチェック
			{	
				auto& player = game.getPlayer();

				int dx = abs(enemy.getX() - player.getX()); //┬中心座標間のピクセル数
				int dy = abs(enemy.getY() - player.getY()); //┘
				if (dx < enemy.getWidth() / 2 + player.getWidth() / 2 && dy < enemy.getHeight() / 2 + player.getHeight() / 2)
				{
					if (player.getShield() > 0)
					{
						player.setShield(player.getShield() - 1); // シールドを減らす
					}
					GameData::noDamage = GameConfig::FPS; // 無敵状態をセット
					damageEnemy(i, 1); // 敵にダメージ
				}
			}
		}
	}

	// 敵機をセットする
	int EnemyManager::setEnemy(int x, int y, int vx, int vy, EnemyType ptn, Image img, int sld)
	{
		for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
			if (GameData::enemy[i].state == 0) {
				GameData::enemy[i].x = x;
				GameData::enemy[i].y = y;
				GameData::enemy[i].vx = vx;
				GameData::enemy[i].vy = vy;
				GameData::enemy[i].state = 1;
				GameData::enemy[i].pattern = ptn;
				GameData::enemy[i].image = img;
				GameData::enemy[i].shield = sld * GameData::stage; // ステージが進むほど敵が固くなる
				GetGraphSize(img, &GameData::enemy[i].wid, &GameData::enemy[i].hei); // 画像の幅と高さを代入
				return i;
			}
		}
		return -1;
	}
