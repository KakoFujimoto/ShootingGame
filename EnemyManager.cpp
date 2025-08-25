#include "Bullet.h"
#include "GameData.h"
#include "EnemyManager.h"
#include "DxLib.h"

	// 敵機を動かす
	void EnemyManager::moveEnemy(void)
	{
		for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
			if (GameData::enemy[i].state == 0) continue; // 空いている配列なら処理しない
			if (GameData::enemy[i].pattern == ENE_ZAKO3) // ザコ機3
			{
				if (GameData::enemy[i].vy > 1) // 減速
				{
					GameData::enemy[i].vy *= 0.9;
				}
				else if (GameData::enemy[i].vy > 0) // 弾発射、飛び去る
				{
					setEnemy(GameData::enemy[i].x, GameData::enemy[i].y, 0, 6, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0); // 弾
					GameData::enemy[i].vx = 8;
					GameData::enemy[i].vy = -4;
				}
			}
			if (GameData::enemy[i].pattern == ENE_BOSS) // ボス機
			{
				if (GameData::enemy[i].y > GameConfig::HEIGHT - 120) GameData::enemy[i].vy = -2;
				if (GameData::enemy[i].y < 120) // 画面上端
				{
					if (GameData::enemy[i].vy < 0) // 弾発射
					{
						for (int bx = -2; bx <= 2; bx++) // 二重ループのfor
							for (int by = 0; by <= 3; by++)
							{
								if (bx == 0 && by == 0) continue;
								setEnemy(GameData::enemy[i].x, GameData::enemy[i].y, bx * 2, by * 3, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0);
							}
					}
					GameData::enemy[i].vy = 2;
				}
			}
			GameData::enemy[i].x += GameData::enemy[i].vx; //┬敵機の移動
			GameData::enemy[i].y += GameData::enemy[i].vy; //┘
			drawImage(GameData::enemy[i].image, GameData::enemy[i].x, GameData::enemy[i].y); // 敵機の描画
			// 画面外に出たか？
			if (GameData::enemy[i].x < -200 || GameConfig::WIDTH + 200 < GameData::enemy[i].x || GameData::enemy[i].y < -200 || GameConfig::HEIGHT + 200 < GameData::enemy[i].y) GameData::enemy[i].state = 0;
			// 当たり判定のアルゴリズム
			if (GameData::enemy[i].shield > 0) // ヒットチェックを行う敵機（弾以外）
			{
				for (int j = 0; j < GameConfig::BULLET_MAX; j++) { // 自機の弾とヒットチェック
					if (GameData::bullet[j].state == 0) continue;
					int dx = abs((int)(GameData::enemy[i].x - GameData::bullet[j].x)); //┬中心座標間のピクセル数
					int dy = abs((int)(GameData::enemy[i].y - GameData::bullet[j].y)); //┘
					if (dx < GameData::enemy[i].wid / 2 && dy < GameData::enemy[i].hei / 2) // 接触しているか
					{
						GameData::bullet[j].state = 0; // 弾を消す
						damageEnemy(i, 1); // 敵にダメージ
					}
				}
			}
			if (GameData::noDamage == 0) // 無敵状態でない時、自機とヒットチェック
			{
				int dx = abs(GameData::enemy[i].x - GameData::player.x); //┬中心座標間のピクセル数
				int dy = abs(GameData::enemy[i].y - GameData::player.y); //┘
				if (dx < GameData::enemy[i].wid / 2 + GameData::player.wid / 2 && dy < GameData::enemy[i].hei / 2 + GameData::player.hei / 2)
				{
					if (GameData::player.shield > 0) GameData::player.shield--; // シールドを減らす
					GameData::noDamage = GameConfig::FPS; // 無敵状態をセット
					damageEnemy(i, 1); // 敵にダメージ
				}
			}
		}
	}

	// 敵機をセットする
	int EnemyManager::setEnemy(int x, int y, int vx, int vy, int ptn, int img, int sld)
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
