#include "GameManager.h"
#include "SceneType.h"

void GameManager::gameLoop()
{
	ClearDrawScreen(); // 画面をクリアする

	// ゲームの骨組みとなる処理を、ここに記述する
	int spd = 1; // スクロールの速さ
	if (gameData.scene == SceneType::Play && gameData.distance == 0)
	{
		spd = 0; // ボス戦はスクロール停止
	}

	//scrollBG(graphic, spd); // 背景のスクロール
	scrollBG(spd); 

	//moveEnemy(); 
	//enemies.move(*this, graphic);
	enemies.moveEnemy(*this); // 敵機の制御

	//moveBullet();
	//bullet.move(player graphic);
	bullets.moveBullet(images, *this); // 弾の制御

	//moveItem();
	//item.move(graphic);
	itemManager.moveItem(*this); // アイテムの制御

	//drawEffect(); // エフェクト
	//effetct.draw(graphic);
	effects.drawEffect(*this);


	stageMap(); // ステージマップ
	drawer.drawParameter(); // 自機のシールドなどのパラメーターを表示
	gameData.timer++; // タイマーをカウント

	sceneManager.run(*this);

	// スコア、ハイスコア、ステージ数の表示
	drawer.drawText(10, 10, "SCORE %07d", gameData.score, 0xffffff, 30);
	drawer.drawText(GameConfig::WIDTH - 220, 10, "HI-SC %07d", gameData.hisco, 0xffffff, 30);
	drawer.drawText(GameConfig::WIDTH - 145, GameConfig::HEIGHT - 40, "STAGE %02d", gameData.stage, 0xffffff, 30);

	ScreenFlip(); // 裏画面の内容を表画面に反映させる
	WaitTimer(1000 / GameConfig::FPS); // 一定時間待つ
	if (ProcessMessage() == -1)
	{
		return; // Windowsから情報を受け取りエラーが起きたら終了
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
	{
		return; // ESCキーが押されたら終了
	}
}

// ステージマップ
void GameManager::stageMap(void)
{
	int mx = GameConfig::WIDTH - 30, my = 60; // マップの表示位置
	int wi = 20, he = GameConfig::HEIGHT - 120; // マップの幅、高さ
	int pos = (GameConfig::HEIGHT - 140) * gameData.distance / GameConfig::STAGE_DISTANCE; // 自機の飛行している位置

	SetDrawBlendMode(DX_BLENDMODE_SUB, 128); // 減算による描画の重ね合わせ
	DrawBox(mx, my, mx + wi, my + he, 0xffffff, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // ブレンドモードを解除
	DrawBox(mx - 1, my - 1, mx + wi + 1, my + he + 1, 0xffffff, FALSE); // 枠線
	DrawBox(mx, my + pos, mx + wi, my + pos + 20, 0x0080ff, TRUE); // 自機の位置
}

// 背景のスクロール
void GameManager::scrollBG(int spd)
{
	static int galaxyY, floorY, wallY; // スクロール位置を管理する変数（静的記憶領域に保持される）
	galaxyY = (galaxyY + spd) % GameConfig::HEIGHT; // 星空（宇宙）

	DrawGraph(0, galaxyY - GameConfig::HEIGHT, images.getGalaxy().getId(), FALSE);
	DrawGraph(0, galaxyY, images.getGalaxy().getId(), FALSE);

	floorY = (floorY + spd * 2) % 120;  // 床
	for (int i = -1; i < 6; i++) DrawGraph(240, floorY + i * 120, images.getFloor().getId(), TRUE);

	wallY = (wallY + spd * 4) % 240;    // 左右の壁
	DrawGraph(0, wallY - 240, images.getWallL().getId(), TRUE);
	DrawGraph(GameConfig::WIDTH - 300, wallY - 240, images.getWallR().getId(), TRUE);
}

// ゲーム開始時の初期値を代入する関数
void GameManager::initVariable(void)
{
	GameData::player.x = GameConfig::WIDTH / 2;
	GameData::player.vx = 5;
	GameData::player.vy = 5;
	GameData::player.y = GameConfig::HEIGHT / 2;
	GameData::player.shield = GameConfig::PLAYER_SHIELD_MAX;
	GetGraphSize(GameData::imgFighter, &GameData::player.wid, &GameData::player.hei); // 自機の画像の幅と高さを代入
	for (int i = 0; i < GameConfig::ENEMY_MAX; i++) GameData::enemy[i].state = 0; // 全ての敵機を存在しない状態に
	GameData::score = 0;
	GameData::stage = 1;
	GameData::noDamage = 0;
	GameData::weaponLv = 1;
	GameData::distance = GameConfig::STAGE_DISTANCE;
}