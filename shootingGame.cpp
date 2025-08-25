#include "DxLib.h" //DXライブラリのインクルード
#include "shootingGame.h" // ヘッダーファイルをインクルード
#include <cstdlib>
#include <array>
#include <string>

// 定数の定義
namespace GameConfig {
	constexpr int WIDTH = 1200; // ウィンドウの幅
	constexpr int HEIGHT = 720; // ウィンドウの高さ
	constexpr int FPS = 60; // フレームレート
	constexpr int IMG_ENEMY_MAX = 5; // 敵の画像の枚数（種類）
	constexpr int BULLET_MAX = 100; // 自機が発射する弾の最大数
	constexpr int ENEMY_MAX = 100; // 敵機の数の最大値
	constexpr int STAGE_DISTANCE = FPS * 60; // ステージの長さ
	constexpr int PLAYER_SHIELD_MAX = 8; // 自機のシールドの最大値
	constexpr int EFFECT_MAX = 100; // エフェクトの最大数
	constexpr int ITEM_TYPE = 3; // アイテムの種類
	constexpr int WEAPON_LV_MAX = 10; // 武器レベルの最大値
	constexpr int PLAYER_SPEED_MAX = 20; // 自機の速さの最大値
}

// 敵機の種類
enum EnemyType {
	ENE_BULLET,
	ENE_ZAKO1,
	ENE_ZAKO2,
	ENE_ZAKO3,
	ENE_BOSS
};

// エフェクトの種類
enum EffectType {
	EFF_EXPLODE,
	EFF_RECOVER
};

// シーンの種類
enum SceneType {
	TITLE,
	PLAY,
	OVER,
	CLEAR
};



// グローバル変数
// ここでゲームに用いる変数や配列を定義する
namespace GameData {
	// --- 画像 ---
	int imgGalaxy, imgFloor, imgWallL, imgWallR; // 背景画像
	int imgFighter, imgBullet; // 自機と自機の弾の画像
	int imgEnemy[GameConfig::IMG_ENEMY_MAX]; // 敵機の画像
	int imgExplosion; // 爆発演出の画像
	int imgItem; // アイテムの画像

	// --- 音 ---
	int bgm, jinOver, jinClear, seExpl, seItem, seShot; // 音の読み込み用

	// --- ゲーム状態 ---
	int distance = 0; // ステージ終端までの距離
	int bossIdx = 0; // ボスを代入した配列のインデックス
	int stage = 1; // ステージ
	int score = 0; // スコア
	int hisco = 10000; // ハイスコア
	int noDamage = 0; // 無敵状態
	int weaponLv = 1; // 自機の武器のレベル（同時に発射される弾数）
	int scene = TITLE; // シーンを管理
	int timer = 0; // 時間の進行を管理

	// --- オブジェクト ---
	OBJECT player; // 自機用の構造体変数
	OBJECT bullet[GameConfig::BULLET_MAX]; // 弾用の構造体の配列
	OBJECT enemy[GameConfig::ENEMY_MAX]; // 敵機用の構造体の配列
	OBJECT effect[GameConfig::EFFECT_MAX]; // エフェクト用の構造体の配列
	OBJECT item; // アイテム用の構造体変数
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("シューティングゲーム"); // ウィンドウのタイトル
	SetGraphMode(GameConfig::WIDTH, GameConfig::HEIGHT, 32); // ウィンドウの大きさとカラービット数の指定
	ChangeWindowMode(TRUE); // ウィンドウモードで起動

	if (DxLib_Init() == -1)return -1; // ライブラリ初期化 エラーが起きたら終了

	GameManager game;
	
	//SetBackgroundColor(0, 0, 0); // 背景色の指定
	//SetDrawScreen(DX_SCREEN_BACK); // 描画面を裏画面にする

	//initGame(); // 初期化用の関数を呼び出す
	//initVariable(); // 【仮】ゲームを完成させる際に呼び出し位置を変える
	//GameData::distance = GameConfig::STAGE_DISTANCE; // 【記述位置は仮】ステージの長さを代入

	game.init();

	while (1) // メインループ
	{
		game.gameLoop();

		//ClearDrawScreen(); // 画面をクリアする

		//// ゲームの骨組みとなる処理を、ここに記述する
		//int spd = 1; // スクロールの速さ
		//if (GameData::scene == PLAY && GameData::distance == 0) spd = 0; // ボス戦はスクロール停止
		//scrollBG(spd); // 背景のスクロール
		//moveEnemy(); // 敵機の制御
		//moveBullet(); // 弾の制御
		//moveItem(); // アイテムの制御
		//drawEffect(); // エフェクト
		//stageMap(); // ステージマップ
		//drawParameter(); // 自機のシールドなどのパラメーターを表示

		//GameData::timer++; // タイマーをカウント
		//switch (GameData::scene) // シーンごとに処理を分岐
		//{
		//case TITLE: // タイトル画面
		//	drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "Shooting Game", 0xffffff, 80);
		//	drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.7, "Press SPACE to start.", 0xffffff, 30);
		//	if (CheckHitKey(KEY_INPUT_SPACE))
		//	{
		//		initVariable();
		//		GameData::scene = PLAY;
		//	}
		//	break;

		//case PLAY: // ゲームプレイ画面
		//	movePlayer(); // 自機の操作
		//	if (GameData::distance == GameConfig::STAGE_DISTANCE)
		//	{
		//		srand(GameData::stage); // ステージのパターンを決める
		//		PlaySoundMem(GameData::bgm, DX_PLAYTYPE_LOOP); // ＢＧＭループ出力
		//	}
		//	if (GameData::distance > 0) GameData::distance--;
		//	if (300 < GameData::distance && GameData::distance % 20 == 0) // ザコ1と2の出現
		//	{
		//		int x = 100 + rand() % (GameConfig::WIDTH - 200);
		//		int y = -50;
		//		int e = 1 + rand() % 2;
		//		if (e == ENE_ZAKO1) setEnemy(x, y, 0, 3, ENE_ZAKO1, GameData::imgEnemy[ENE_ZAKO1], 1);
		//		if (e == ENE_ZAKO2) {
		//			int vx = 0;
		//			if (GameData::player.x < x - 50) vx = -3;
		//			if (GameData::player.x > x + 50) vx = 3;
		//			setEnemy(x, -100, vx, 5, ENE_ZAKO2, GameData::imgEnemy[ENE_ZAKO2], 3);
		//		}
		//	}
		//	if (300 < GameData::distance && GameData::distance < 900 && GameData::distance % 30 == 0) // ザコ3の出現
		//	{
		//		int x = 100 + rand() % (GameConfig::WIDTH - 200);
		//		int y = -50;
		//		int vy = 40 + rand() % 20;
		//		setEnemy(x, -100, 0, vy, ENE_ZAKO3, GameData::imgEnemy[ENE_ZAKO3], 5);
		//	}
		//		if (GameData::distance == 1) GameData::bossIdx = setEnemy(GameConfig::WIDTH / 2, -120, 0, 1, ENE_BOSS, GameData::imgEnemy[ENE_BOSS], 200); // ボス出現
		//		if (GameData::distance % 800 == 1) setItem(); // アイテムの出現
		//		if (GameData::player.shield == 0)
		//		{
		//			StopSoundMem(GameData::bgm); // ＢＧＭ停止
		//			GameData::scene = OVER;
		//			GameData::timer = 0;
		//			break;
		//		}
		//		break;

		//case OVER: // ゲームオーバー
		//	if (GameData::timer < GameConfig::FPS * 3) // 自機が爆発する演出
		//	{
		//		if (GameData::timer % 7 == 0) setEffect(GameData::player.x + rand() % 81 - 40, GameData::player.y + rand() % 81 - 40, EFF_EXPLODE);
		//	}
		//	else if (GameData::timer == GameConfig::FPS * 3)
		//	{
		//		PlaySoundMem(GameData::jinOver, DX_PLAYTYPE_BACK); // ジングル出力
		//	}
		//	else
		//	{
		//		drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "GAME OVER", 0xff0000, 80);
		//	}
		//	if (GameData::timer > GameConfig::FPS * 10) GameData::scene = TITLE; // タイトルへ遷移
		//	break;

		//case CLEAR: // ステージクリア
		//	movePlayer(); // 自機の処理
		//	if (GameData::timer < GameConfig::FPS * 3) // ボスが爆発する演出
		//	{
		//		if (GameData::timer % 7 == 0) setEffect(GameData::enemy[GameData::bossIdx].x + rand() % 201 - 100, GameData::enemy[GameData::bossIdx].y + rand() % 201 - 100, EFF_EXPLODE);
		//	}
		//	else if (GameData::timer == GameConfig::FPS * 3)
		//	{
		//		PlaySoundMem(GameData::jinClear, DX_PLAYTYPE_BACK); // ジングル出力
		//	}
		//	else
		//	{
		//		drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "STAGE CLEAR!", 0x00ffff, 80);
		//	}
		//	if (GameData::timer > GameConfig::FPS * 10) // ゲームプレイへ遷移
		//	{
		//		GameData::stage++;
		//		GameData::distance = GameConfig::STAGE_DISTANCE;
		//		GameData::scene = PLAY;
		//	}
		//	break;
		//	}

		//	// スコア、ハイスコア、ステージ数の表示
		//	drawText(10, 10, "SCORE %07d", GameData::score, 0xffffff, 30);
		//	drawText(GameConfig::WIDTH - 220, 10, "HI-SC %07d", GameData::hisco, 0xffffff, 30);
		//	drawText(GameConfig::WIDTH - 145, GameConfig::HEIGHT - 40, "STAGE %02d", GameData::stage, 0xffffff, 30);

		//	ScreenFlip(); // 裏画面の内容を表画面に反映させる
		//	WaitTimer(1000 / GameConfig::FPS); // 一定時間待つ
		//	if (ProcessMessage() == -1) break; // Windowsから情報を受け取りエラーが起きたら終了
		//	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESCキーが押されたら終了
		}

		DxLib_End(); // ＤＸライブラリ使用の終了処理
		return 0; // ソフトの終了
	}

	// ここから下に自作した関数を記述する
	// 初期化用の関数
	void initGame(void)
	{
		// 背景用の画像の読み込み
		GameData::imgGalaxy = LoadGraph("image/bg0.png");
		GameData::imgFloor = LoadGraph("image/bg1.png");
		GameData::imgWallL = LoadGraph("image/bg2.png");
		GameData::imgWallR = LoadGraph("image/bg3.png");
		// 自機と自機の弾の画像の読み込み
		GameData::imgFighter = LoadGraph("image/fighter.png");
		GameData::imgBullet = LoadGraph("image/bullet.png");
		// 敵機の画像の読み込み
		for (int i = 0; i < GameConfig::IMG_ENEMY_MAX; i++) {
			std::string file = "image/enemy" + std::to_string(i) + ".png";
			GameData::imgEnemy[i] = LoadGraph(file.c_str());
		}
		// その他の画像の読み込み
		GameData::imgExplosion = LoadGraph("image/explosion.png"); // 爆発演出
		GameData::imgItem = LoadGraph("image/item.png"); // アイテム

		// サウンドの読み込みと音量設定
		GameData::bgm = LoadSoundMem("sound/bgm.mp3");
		GameData::jinOver = LoadSoundMem("sound/gameover.mp3");
		GameData::jinClear = LoadSoundMem("sound/stageclear.mp3");
		GameData::seExpl = LoadSoundMem("sound/explosion.mp3");
		GameData::seItem = LoadSoundMem("sound/item.mp3");
		GameData::seShot = LoadSoundMem("sound/shot.mp3");
		ChangeVolumeSoundMem(128, GameData::bgm);
		ChangeVolumeSoundMem(128, GameData::jinOver);
		ChangeVolumeSoundMem(128, GameData::jinClear);
	}

	// 背景のスクロール
	void scrollBG(int spd)
	{
		static int galaxyY, floorY, wallY; // スクロール位置を管理する変数（静的記憶領域に保持される）
		galaxyY = (galaxyY + spd) % GameConfig::HEIGHT; // 星空（宇宙）
		DrawGraph(0, galaxyY - GameConfig::HEIGHT, GameData::imgGalaxy, FALSE);
		DrawGraph(0, galaxyY, GameData::imgGalaxy, FALSE);
		floorY = (floorY + spd * 2) % 120;  // 床
		for (int i = -1; i < 6; i++) DrawGraph(240, floorY + i * 120, GameData::imgFloor, TRUE);
		wallY = (wallY + spd * 4) % 240;    // 左右の壁
		DrawGraph(0, wallY - 240, GameData::imgWallL, TRUE);
		DrawGraph(GameConfig::WIDTH - 300, wallY - 240, GameData::imgWallR, TRUE);
	}

	// ゲーム開始時の初期値を代入する関数
	void initVariable(void)
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

	// 中心座標を指定して画像を表示する関数
	void drawImage(int img, int x, int y)
	{
		int w, h;
		GetGraphSize(img, &w, &h);
		DrawGraph(x - w / 2, y - h / 2, img, TRUE);
	}

	// 自機を動かす関数
	void movePlayer(void)
	{
		static char oldSpcKey; // 1つ前のスペースキーの状態を保持する変数
		static int countSpcKey; // スペースキーを押し続けている間、カウントアップする変数
		if (CheckHitKey(KEY_INPUT_UP)) { // 上キー
			GameData::player.y -= GameData::player.vy;
			if (GameData::player.y < 30) GameData::player.y = 30;
		}
		if (CheckHitKey(KEY_INPUT_DOWN)) { // 下キー
			GameData::player.y += GameData::player.vy;
			if (GameData::player.y > GameConfig::HEIGHT - 30) GameData::player.y = GameConfig::HEIGHT - 30;
		}
		if (CheckHitKey(KEY_INPUT_LEFT)) { // 左キー
			GameData::player.x -= GameData::player.vx;
			if (GameData::player.x < 30) GameData::player.x = 30;
		}
		if (CheckHitKey(KEY_INPUT_RIGHT)) { // 右キー
			GameData::player.x += GameData::player.vx;
			if (GameData::player.x > GameConfig::WIDTH - 30) GameData::player.x = GameConfig::WIDTH - 30;
		}
		if (CheckHitKey(KEY_INPUT_SPACE)) { // スペースキー
			if (oldSpcKey == 0) setBullet(); // 押した瞬間、発射
			else if (countSpcKey % 20 == 0) setBullet(); // 一定間隔で発射
			countSpcKey++;
		}
		oldSpcKey = CheckHitKey(KEY_INPUT_SPACE); // スペースキーの状態を保持
		if (GameData::noDamage > 0) GameData::noDamage--; // 無敵時間のカウント
		if (GameData::noDamage % 4 < 2) drawImage(GameData::imgFighter, GameData::player.x, GameData::player.y); // 自機の描画
	}

	// 弾のセット（発射）
	void setBullet(void)
	{
		for (int n = 0; n < GameData::weaponLv; n++) {
			int x = GameData::player.x - (GameData::weaponLv - 1) * 5 + n * 10;
			int y = GameData::player.y - 20;
			for (int i = 0; i < GameConfig::BULLET_MAX; i++) {
				if (GameData::bullet[i].state == 0) {
					GameData::bullet[i].x = x;
					GameData::bullet[i].y = y;
					GameData::bullet[i].vx = 0;
					GameData::bullet[i].vy = -40;
					GameData::bullet[i].state = 1;
					break;
				}
			}
		}
		PlaySoundMem(GameData::seShot, DX_PLAYTYPE_BACK); // 効果音
	}

	// 弾の移動
	void moveBullet(void)
	{
		for (int i = 0; i < GameConfig::BULLET_MAX; i++) {
			if (GameData::bullet[i].state == 0) continue; // 空いている配列なら処理しない
			GameData::bullet[i].x += GameData::bullet[i].vx; // ┬ 座標を変化させる
			GameData::bullet[i].y += GameData::bullet[i].vy; // ┘
			drawImage(GameData::imgBullet, GameData::bullet[i].x, GameData::bullet[i].y); // 弾の描画
			if (GameData::bullet[i].y < -100) GameData::bullet[i].state = 0; // 画面外に出たら、存在しない状態にする
		}
	}

	// 敵機をセットする
	//int setEnemy(int x, int y, int vx, int vy, int ptn, int img, int sld)
	//{
	//	for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
	//		if (GameData::enemy[i].state == 0) {
	//			GameData::enemy[i].x = x;
	//			GameData::enemy[i].y = y;
	//			GameData::enemy[i].vx = vx;
	//			GameData::enemy[i].vy = vy;
	//			GameData::enemy[i].state = 1;
	//			GameData::enemy[i].pattern = ptn;
	//			GameData::enemy[i].image = img;
	//			GameData::enemy[i].shield = sld * GameData::stage; // ステージが進むほど敵が固くなる
	//			GetGraphSize(img, &GameData::enemy[i].wid, &GameData::enemy[i].hei); // 画像の幅と高さを代入
	//			return i;
	//		}
	//	}
	//	return -1;
	//}

	// 敵機を動かす
	//void moveEnemy(void)
	//{
	//	for (int i = 0; i < GameConfig::ENEMY_MAX; i++) {
	//		if (GameData::enemy[i].state == 0) continue; // 空いている配列なら処理しない
	//		if (GameData::enemy[i].pattern == ENE_ZAKO3) // ザコ機3
	//		{
	//			if (GameData::enemy[i].vy > 1) // 減速
	//			{
	//				GameData::enemy[i].vy *= 0.9;
	//			}
	//			else if (GameData::enemy[i].vy > 0) // 弾発射、飛び去る
	//			{
	//				setEnemy(GameData::enemy[i].x, GameData::enemy[i].y, 0, 6, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0); // 弾
	//				GameData::enemy[i].vx = 8;
	//				GameData::enemy[i].vy = -4;
	//			}
	//		}
	//		if (GameData::enemy[i].pattern == ENE_BOSS) // ボス機
	//		{
	//			if (GameData::enemy[i].y > GameConfig::HEIGHT - 120) GameData::enemy[i].vy = -2;
	//			if (GameData::enemy[i].y < 120) // 画面上端
	//			{
	//				if (GameData::enemy[i].vy < 0) // 弾発射
	//				{
	//					for (int bx = -2; bx <= 2; bx++) // 二重ループのfor
	//						for (int by = 0; by <= 3; by++)
	//						{
	//							if (bx == 0 && by == 0) continue;
	//							setEnemy(GameData::enemy[i].x, GameData::enemy[i].y, bx * 2, by * 3, ENE_BULLET, GameData::imgEnemy[ENE_BULLET], 0);
	//						}
	//				}
	//				GameData::enemy[i].vy = 2;
	//			}
	//		}
	//		GameData::enemy[i].x += GameData::enemy[i].vx; //┬敵機の移動
	//		GameData::enemy[i].y += GameData::enemy[i].vy; //┘
	//		drawImage(GameData::enemy[i].image, GameData::enemy[i].x, GameData::enemy[i].y); // 敵機の描画
	//		// 画面外に出たか？
	//		if (GameData::enemy[i].x < -200 || GameConfig::WIDTH + 200 < GameData::enemy[i].x || GameData::enemy[i].y < -200 || GameConfig::HEIGHT + 200 < GameData::enemy[i].y) GameData::enemy[i].state = 0;
	//		// 当たり判定のアルゴリズム
	//		if (GameData::enemy[i].shield > 0) // ヒットチェックを行う敵機（弾以外）
	//		{
	//			for (int j = 0; j < GameConfig::BULLET_MAX; j++) { // 自機の弾とヒットチェック
	//				if (GameData::bullet[j].state == 0) continue;
	//				int dx = abs((int)(GameData::enemy[i].x - GameData::bullet[j].x)); //┬中心座標間のピクセル数
	//				int dy = abs((int)(GameData::enemy[i].y - GameData::bullet[j].y)); //┘
	//				if (dx < GameData::enemy[i].wid / 2 && dy < GameData::enemy[i].hei / 2) // 接触しているか
	//				{
	//					GameData::bullet[j].state = 0; // 弾を消す
	//					damageEnemy(i, 1); // 敵にダメージ
	//				}
	//			}
	//		}
	//		if (GameData::noDamage == 0) // 無敵状態でない時、自機とヒットチェック
	//		{
	//			int dx = abs(GameData::enemy[i].x - GameData::player.x); //┬中心座標間のピクセル数
	//			int dy = abs(GameData::enemy[i].y - GameData::player.y); //┘
	//			if (dx < GameData::enemy[i].wid / 2 + GameData::player.wid / 2 && dy < GameData::enemy[i].hei / 2 + GameData::player.hei / 2)
	//			{
	//				if (GameData::player.shield > 0) GameData::player.shield--; // シールドを減らす
	//				GameData::noDamage = GameConfig::FPS; // 無敵状態をセット
	//				damageEnemy(i, 1); // 敵にダメージ
	//			}
	//		}
	//	}
	//}

	// ステージマップ
	void stageMap(void)
	{
		int mx = GameConfig::WIDTH - 30, my = 60; // マップの表示位置
		int wi = 20, he = GameConfig::HEIGHT - 120; // マップの幅、高さ
		int pos = (GameConfig::HEIGHT - 140) * GameData::distance / GameConfig::STAGE_DISTANCE; // 自機の飛行している位置
		SetDrawBlendMode(DX_BLENDMODE_SUB, 128); // 減算による描画の重ね合わせ
		DrawBox(mx, my, mx + wi, my + he, 0xffffff, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // ブレンドモードを解除
		DrawBox(mx - 1, my - 1, mx + wi + 1, my + he + 1, 0xffffff, FALSE); // 枠線
		DrawBox(mx, my + pos, mx + wi, my + pos + 20, 0x0080ff, TRUE); // 自機の位置
	}

	// 敵機のシールドを減らす（ダメージを与える）
	void damageEnemy(int n, int dmg)
	{
		SetDrawBlendMode(DX_BLENDMODE_ADD, 192); // 加算による描画の重ね合わせ
		DrawCircle(GameData::enemy[n].x, GameData::enemy[n].y, (GameData::enemy[n].wid + GameData::enemy[n].hei) / 4, 0xff0000, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // ブレンドモードを解除
		GameData::score += 100; // スコアの加算
		if (GameData::score > GameData::hisco) GameData::hisco = GameData::score; // ハイスコアの更新
		GameData::enemy[n].shield -= dmg; // シールドを減らす
		if (GameData::enemy[n].shield <= 0)
		{
			GameData::enemy[n].state = 0; // シールド0以下で消す
			setEffect(GameData::enemy[n].x, GameData::enemy[n].y, EFF_EXPLODE); // 爆発演出
			if (GameData::enemy[n].pattern == ENE_BOSS) // ボスを倒した
			{
				StopSoundMem(GameData::bgm); // ＢＧＭ停止
				GameData::scene = CLEAR;
				GameData::timer = 0;
			}
		}
	}

	// 影を付けた文字列と値を表示する関数
	void drawText(int x, int y, const char* txt, int val, int col, int siz)
	{
		SetFontSize(siz); // フォントの大きさを指定
		DrawFormatString(x + 1, y + 1, 0x000000, txt, val); // 黒で文字列を表示
		DrawFormatString(x, y, col, txt, val); // 引数の色で文字列を表示
	}

	// 自機に関するパラメーターを表示
	void drawParameter(void)
	{
		int x = 10, y = GameConfig::HEIGHT - 30; // 表示位置
		DrawBox(x, y, x + GameConfig::PLAYER_SHIELD_MAX * 30, y + 20, 0x000000, TRUE);
		for (int i = 0; i < GameData::player.shield; i++) // シールドのメーター
		{
			int r = 128 * (GameConfig::PLAYER_SHIELD_MAX - i) / GameConfig::PLAYER_SHIELD_MAX; // RGB値を計算
			int g = 255 * i / GameConfig::PLAYER_SHIELD_MAX;
			int b = 160 + 96 * i / GameConfig::PLAYER_SHIELD_MAX;
			DrawBox(x + 2 + i * 30, y + 2, x + 28 + i * 30, y + 18, GetColor(r, g, b), TRUE);
		}
		drawText(x, y - 25, "SHIELD Lv %02d", GameData::player.shield, 0xffffff, 20); // シールド値
		drawText(x, y - 50, "WEAPON Lv %02d", GameData::weaponLv, 0xffffff, 20); // 武器レベル
		drawText(x, y - 75, "SPEED %02d", GameData::player.vx, 0xffffff, 20); // 移動速度
	}

	// エフェクトのセット
	//void setEffect(int x, int y, int ptn)
	//{
	//	static int eff_num;
	//	GameData::effect[eff_num].x = x;
	//	GameData::effect[eff_num].y = y;
	//	GameData::effect[eff_num].state = 1;
	//	GameData::effect[eff_num].pattern = ptn;
	//	GameData::effect[eff_num].timer = 0;
	//	eff_num = (eff_num + 1) % GameConfig::EFFECT_MAX;
	//	if (ptn == EFF_EXPLODE) PlaySoundMem(GameData::seExpl, DX_PLAYTYPE_BACK); // 効果音
	//}

	// エフェクトの描画
	//void drawEffect(void)
	//{
	//	int ix;
	//	for (int i = 0; i < GameConfig::EFFECT_MAX; i++)
	//	{
	//		if (GameData::effect[i].state == 0) continue;

	//		GameData::effect[i].draw(drawer):

	//		//switch (GameData::effect[i].pattern) // エフェクトごとに処理を分ける
	//		//{
	//		//case EFF_EXPLODE: // 爆発演出
	//		//	ix = GameData::effect[i].timer * 128; // 画像の切り出し位置
	//		//	DrawRectGraph(GameData::effect[i].x - 64, GameData::effect[i].y - 64, ix, 0, 128, 128, GameData::imgExplosion, TRUE, FALSE);
	//		//	GameData::effect[i].timer++;
	//		//	if (GameData::effect[i].timer == 7) GameData::effect[i].state = 0;
	//		//	break;

	//		//case EFF_RECOVER: // 回復演出
	//		//	if (GameData::effect[i].timer < 30) // 加算による描画の重ね合わせ
	//		//		SetDrawBlendMode(DX_BLENDMODE_ADD, GameData::effect[i].timer * 8);
	//		//	else
	//		//		SetDrawBlendMode(DX_BLENDMODE_ADD, (60 - GameData::effect[i].timer) * 8);
	//		//	for (int i = 3; i < 8; i++) DrawCircle(GameData::player.x, GameData::player.y, (GameData::player.wid + GameData::player.hei) / i, 0x2040c0, TRUE);
	//		//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); // ブレンドモードを解除
	//		//	GameData::effect[i].timer++;
	//		//	if (GameData::effect[i].timer == 60) GameData::effect[i].state = 0;
	//		//	break;
	//		//}
	//	}
	//}

	// アイテムをセット
	void setItem(void)
	{
		GameData::item.x = (GameConfig::WIDTH / 4) * (1 + rand() % 3);
		GameData::item.y = -16;
		GameData::item.vx = 15;
		GameData::item.vy = 1;
		GameData::item.state = 1;
		GameData::item.timer = 0;
	}

	// アイテムの処理
	void moveItem(void)
	{
		if (GameData::item.state == 0) return;
		GameData::item.x += GameData::item.vx;
		GameData::item.y += GameData::item.vy;
		if (GameData::item.timer % 60 < 30)
			GameData::item.vx -= 1;
		else
			GameData::item.vx += 1;
		if (GameData::item.y > GameConfig::HEIGHT + 16) GameData::item.state = 0;
		GameData::item.pattern = (GameData::item.timer / 120) % GameConfig::ITEM_TYPE; // 現在、どのアイテムになっているか
		GameData::item.timer++;
		DrawRectGraph(GameData::item.x - 20, GameData::item.y - 16, GameData::item.pattern * 40, 0, 40, 32, GameData::imgItem, TRUE, FALSE);
		if (GameData::scene == OVER) return; // ゲームオーバー画面では回収できない
		int dis = (GameData::item.x - GameData::player.x) * (GameData::item.x - GameData::player.x) + (GameData::item.y - GameData::player.y) * (GameData::item.y - GameData::player.y);
		if (dis < 60 * 60) // アイテムと自機とのヒットチェック（円による当たり判定）
		{
			GameData::item.state = 0;
			if (GameData::item.pattern == 0) // スピードアップ
			{
				if (GameData::player.vx < GameConfig::PLAYER_SPEED_MAX)
				{
					GameData::player.vx += 3;
					GameData::player.vy += 3;
				}
			}
			if (GameData::item.pattern == 1) // シールド回復
			{
				if (GameData::player.shield < GameConfig::PLAYER_SHIELD_MAX) GameData::player.shield++;
				setEffect(GameData::player.x, GameData::player.y, EFF_RECOVER); // 回復エフェクトを表示
			}
			if (GameData::item.pattern == 2) // 武器レベルアップ
			{
				if (GameData::weaponLv < GameConfig::WEAPON_LV_MAX) GameData::weaponLv++;
			}
			PlaySoundMem(GameData::seItem, DX_PLAYTYPE_BACK); // 効果音
		}
	}

	// 文字列をセンタリングして表示する関数
	void drawTextC(int x, int y, const char* txt, int col, int siz)
	{
		SetFontSize(siz);
		int strWidth = GetDrawStringWidth(txt, strlen(txt));
		x -= strWidth / 2;
		y -= siz / 2;
		DrawString(x + 1, y + 1, txt, 0x000000);
		DrawString(x, y, txt, col);
	}