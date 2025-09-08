#include "DxLib.h" //DXライブラリのインクルード
//#include "shootingGame.h" // ヘッダーファイルをインクルード
#include "GameManager.h"
#include <cstdlib>
//#include <array>
#include <string>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetMainWindowText("シューティングゲーム"); // ウィンドウのタイトル
	SetGraphMode(GameConfig::WIDTH, GameConfig::HEIGHT, 32); // ウィンドウの大きさとカラービット数の指定
	ChangeWindowMode(TRUE); // ウィンドウモードで起動

	if (DxLib_Init() == -1)return -1; // ライブラリ初期化 エラーが起きたら終了
	GameManager game;


	SetBackgroundColor(0, 0, 0); // 背景色の指定
	SetDrawScreen(DX_SCREEN_BACK); // 描画面を裏画面にする

	game.initGame(); // 初期化用の関数を呼び出す

	game.initVariable(); // 【仮】ゲームを完成させる際に呼び出し位置を変える
	game.getGameData().distance = GameConfig::STAGE_DISTANCE; // 【記述位置は仮】ステージの長さを代入


	while (game.getGameData().isRunning) // メインループ
	{
		game.gameLoop();
	}
	DxLib_End(); // ＤＸライブラリ使用の終了処理
	return 0; // ソフトの終了
}

