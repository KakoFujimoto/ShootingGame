class GameManger
{
public:
	void gameLoop();

	Player& getPlayer()
	{
		return player;
	}

private:
	SceneManger sceneManager;
	Graphic  graphic;

	Player player;
	EnemyManager enemies;
	BulletManager bullets;
};


void GameManger::gameLoop()
{
	ClearDrawScreen(); // 画面をクリアする

	// ゲームの骨組みとなる処理を、ここに記述する
	int spd = 1; // スクロールの速さ
	if (GameData::scene == PLAY && GameData::distance == 0) spd = 0; // ボス戦はスクロール停止
	scrollBG(graphic, spd); // 背景のスクロール

	enemies.move(*this, graphic); // 敵機の制御
	bullet.move(player graphic); // 弾の制御
	item.move(graphic); // アイテムの制御
	effetct.draw(graphic); // エフェクト

	stageMap(graphic); // ステージマップ
	drawParameter(graphic); // 自機のシールドなどのパラメーターを表示

	GameData::timer++; // タイマーをカウント

	sceneManager.run(*this);

	// スコア、ハイスコア、ステージ数の表示
	drawText(10, 10, "SCORE %07d", GameData::score, 0xffffff, 30);
	drawText(GameConfig::WIDTH - 220, 10, "HI-SC %07d", GameData::hisco, 0xffffff, 30);
	drawText(GameConfig::WIDTH - 145, GameConfig::HEIGHT - 40, "STAGE %02d", GameData::stage, 0xffffff, 30);

	ScreenFlip(); // 裏画面の内容を表画面に反映させる
	WaitTimer(1000 / GameConfig::FPS); // 一定時間待つ
	if (ProcessMessage() == -1) break; // Windowsから情報を受け取りエラーが起きたら終了
	if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break; // ESCキーが押されたら終了

}