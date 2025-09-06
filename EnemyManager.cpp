#include "Bullet.h"
#include "GameData.h"
#include "EnemyManager.h"
#include "DxLib.h"
#include "Image.h"
#include "EnemyType.h"
#include "GameManager.h"
#include "EffectType.h"
#include "SceneClear.h"

	// 敵機を動かす
	void EnemyManager::moveEnemy(GameManager& game)
	{
		for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
			auto& enemy = enemies[i];
			auto& ene_bullet = game.getImage().getEnemy(EnemyType::Bullet);
			auto& drawer = game.getDrawer();

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
				else if (enemy.getVY() > 0) // 弾発射、飛び去る
				{
					setEnemy(enemy.getX(), enemy.getY(), 0, 6, EnemyType::Bullet, ene_bullet, 0, game); // 弾

					enemy.setVX(8);
					enemy.setVY(-4);
				}
			}
			if (enemy.getPattern() == EnemyType::Boss) // ボス機
			{
				if (enemy.getY() > GameConfig::HEIGHT - 120)
				{
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
								setEnemy(enemy.getX(), enemy.getY(), bx * 2, by * 3, EnemyType::Bullet, ene_bullet, 0, game);
							}
					}
					enemy.setVY(2);
				}
			}
			enemy.setX(enemy.getX() + enemy.getVX()); //┬敵機の移動
			enemy.setY(enemy.getY() + enemy.getVY()); //┘


			drawer.drawImage(game.getImage().getEnemy(enemy.getPattern()).getId(), enemy.getX(), enemy.getY()); // 敵機の描画

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
					//auto& bullet = game.getBullet();
					auto& bullet = game.getBulletManager().getBullet(j);

					if (bullet.getState() == 0)
					{
						continue;
					}
					int dx = abs((int)(enemy.getX() - bullet.getX())); //┬中心座標間のピクセル数
					int dy = abs((int)(enemy.getY() - bullet.getY())); //┘
					if (dx < enemy.getWidth() / 2 && dy < enemy.getHeight() / 2) // 接触しているか
					{
						bullet.setState(0); // 弾を消す
						damageEnemy(i, 1, game); // 敵にダメージ
					}
				}
			}
			if (game.getGameData().noDamage == 0) // 無敵状態でない時、自機とヒットチェック
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
					game.getGameData().noDamage = GameConfig::FPS; // 無敵状態をセット
					damageEnemy(i, 1, game); // 敵にダメージ
				}
			}
		}
	}

	// 敵機をセットする
	int EnemyManager::setEnemy(int x, int y, int vx, int vy, EnemyType ptn, Image img, int sld, GameManager& game)
	{
		for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
			auto& enemy = enemies[i];

			if (enemy.getState() == 0) {
				enemy.setX(x);
				enemy.setY(y);
				enemy.setVX(vx);
				enemy.setVY(vy);
				enemy.setState(1);
				enemy.setPattern(ptn);

				enemy.setImage(&img);
				enemy.setShield(sld * game.getGameData().stage); // ステージが進むほど敵が固くなる
				enemy.setWidth(img.getWidth());
				enemy.setHeight(img.getHeight());
				return i;
			}
		}
		return -1;
	}

	// 敵機のシールドを減らす（ダメージを与える）
	void EnemyManager::damageEnemy(int n, int dmg, GameManager& game)
	{	

		SetDrawBlendMode(DX_BLENDMODE_ADD, 192); // 加算による描画の重ね合わせ
		DrawCircle(enemies[n].getX(), enemies[n].getY(), (enemies[n].getWidth() + enemies[n].getHeight()) / 4, 0xff0000, TRUE);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // ブレンドモードを解除

		int& score = game.getGameData().score;
		score += 100; // スコアの加算

		int& hisco = game.getGameData().hisco;
		if (score > hisco)
		{
			hisco = score; // ハイスコアの更新
		}

		enemies[n].setShield(enemies[n].getShield() - dmg); // シールドを減らす

		if (enemies[n].getShield() <= 0)
		{
			enemies[n].setState(0); // シールド0以下で消す

			game.getEffect().setEffect(
				enemies[n].getX(),
				enemies[n].getY(),
				EffectType::Explode,
				game.getImage(),
				game.getSoundPlayer(),
				game.getSoundContainer()
			); // 爆発演出

			if (enemies[n].getPattern() == EnemyType::Boss) // ボスを倒した
			{
				game.getSoundPlayer().stop(game.getSoundContainer().bgm); // ＢＧＭ停止

				//GameData::scene = CLEAR;
				//return std::make_shared<SceneClear>();
				game.setIsClear(true);

				game.getGameData().timer = 0;
			}
		}
	}

	const Enemy& EnemyManager::getEnemy(int idx) const
	{
		return enemies[idx];
	}
