#include "GameManager.h"
#include "BlendMode.h"
#include "DxLib.h"

void GameManager::gameLoop()
{
	ClearDrawScreen(); // 画面をクリアする

	// ゲームの骨組みとなる処理を、ここに記述する
	int spd = 1; // スクロールの速さ
	if (sceneManager.getCurrentType() == SceneType::Play && gameData.distance == 0)
	{
		spd = 0; // ボス戦はスクロール停止
	}

	scrollBG(spd); 
	enemies.moveEnemy(*this); // 敵機の制御
	bullets.moveBullet(images, *this); // 弾の移動
	itemManager.moveItem(*this, sceneManager); // アイテムの制御
	effects.drawEffect(*this);


	stageMap(); // ステージマップ
	drawParameter(*this); // 自機のシールドなどのパラメーターを表示
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
		getGameData().isRunning = false; // ESCキーが押されたら終了
	}
}

// ステージマップ
void GameManager::stageMap(void)
{
	int mx = GameConfig::WIDTH - 30, my = 60; // マップの表示位置
	int wi = 20, he = GameConfig::HEIGHT - 120; // マップの幅、高さ
	int pos = (GameConfig::HEIGHT - 140) * gameData.distance / GameConfig::STAGE_DISTANCE; // 自機の飛行している位置

	// 修正（drawer.～～となっていればOK）
	//SetDrawBlendMode(DX_BLENDMODE_SUB, 128); // 減算による描画の重ね合わせ
	drawer.setBlendMode(BlendMode::Sub, 128);// 減算による描画の重ね合わせ

	BoxData box{ mx, my, mx + wi, my + he, 0xffffff, TRUE };
	drawer.drawGraphic(box);

	// 修正
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // ブレンドモードを解除

	BoxData frame{ mx - 1, my - 1, mx + wi + 1, my + he + 1, 0xffffff, FALSE }; // 枠線
	drawer.drawGraphic(frame);

	BoxData position{ mx, my + pos, mx + wi, my + pos + 20, 0x0080ff, TRUE }; // 自機の位置
	drawer.drawGraphic(position);
}

// 背景のスクロール
void GameManager::scrollBG(int spd)
{	
	// ここも実質グローバル変数なので良くない
	static int galaxyY, floorY, wallY; // スクロール位置を管理する変数（静的記憶領域に保持される）
	galaxyY = (galaxyY + spd) % GameConfig::HEIGHT; // 星空（宇宙）

	ImageData image{ 0, galaxyY - GameConfig::HEIGHT, images.getGalaxy(), FALSE };
	drawer.drawGraphic(image);

	ImageData gfc{ 0, galaxyY, images.getGalaxy().getId(), FALSE };
	drawer.drawGraphic(gfc);


	floorY = (floorY + spd * 2) % 120;  // 床
	for (int i = -1; i < 6; i++) DrawGraph(240, floorY + i * 120, images.getFloor().getId(), TRUE);

	wallY = (wallY + spd * 4) % 240;    // 左右の壁

	ImageData wallL{ 0, wallY - 240, images.getWallL().getId(), TRUE };
	drawer.drawGraphic(wallL);

	ImageData wallR{ GameConfig::WIDTH - 300, wallY - 240, images.getWallR().getId(), TRUE };
	drawer.drawGraphic(wallR);
}

// ゲーム開始時の初期値を代入する関数
void GameManager::initVariable(void)
{
	player.setX(GameConfig::WIDTH / 2);
	player.setVX(5);
	player.setVY(5);

	player.setY(GameConfig::HEIGHT / 2);
	player.setShield(GameConfig::PLAYER_SHIELD_MAX);

	// 自機の画像の幅と高さを代入
	player.setWidth(images.getFighter().getWidth());
	player.setHeight(images.getFighter().getHeight());

	enemies.resetAllEnemies();

	gameData.score = 0;
	gameData.stage = 1;
	gameData.noDamage = 0;
	gameData.weaponLv = 1;
	gameData.distance = GameConfig::STAGE_DISTANCE;
}

// 自機に関するパラメーターを表示
void GameManager::drawParameter(GameManager& game)
{
	int x = 10, y = GameConfig::HEIGHT - 30; // 表示位置
	// 修正
	DrawBox(x, y, x + GameConfig::PLAYER_SHIELD_MAX * 30, y + 20, 0x000000, TRUE);

	for (int i = 0; i < game.getPlayer().getShield(); i++) // シールドのメーター
	{
		int r = 128 * (GameConfig::PLAYER_SHIELD_MAX - i) / GameConfig::PLAYER_SHIELD_MAX; // RGB値を計算
		int g = 255 * i / GameConfig::PLAYER_SHIELD_MAX;
		int b = 160 + 96 * i / GameConfig::PLAYER_SHIELD_MAX;
		// 修正
		DrawBox(x + 2 + i * 30, y + 2, x + 28 + i * 30, y + 18, GetColor(r, g, b), TRUE);
	}
	game.getDrawer().drawText(x, y - 25, "SHIELD Lv %02d", game.getPlayer().getShield(), 0xffffff, 20); // シールド値
	drawer.drawText(x, y - 50, "WEAPON Lv %02d", game.getGameData().weaponLv, 0xffffff, 20); // 武器レベル
	drawer.drawText(x, y - 75, "SPEED %02d", game.getPlayer().getVX(), 0xffffff, 20); // 移動速度
}

// 初期化用の関数
void GameManager::initGame(void)
{	
	// ゲームスタート時に必要な画像を読み込み
	images.load();

	// サウンドの読み込みと音量設定
	soundLoader.loadAll(soundContainer);

	soundPlayer.setVolume(soundContainer.bgm, 128);
	soundPlayer.setVolume(soundContainer.jinOver, 128);
	soundPlayer.setVolume(soundContainer.jinClear, 128);
}