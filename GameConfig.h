#pragma once

class GameConfig
{
public:
	static constexpr int WIDTH = 1200;				// ウィンドウの幅
	static constexpr int HEIGHT = 720;				// ウィンドウの高さ
	static constexpr int FPS = 60;					// フレームレート
	static constexpr int IMG_ENEMY_MAX = 5;			// 敵の画像の枚数（種類）
	static constexpr int BULLET_MAX = 100;			// 自機が発射する弾の最大数
	static constexpr int ENEMY_MAX = 100;			// 敵機の数の最大値
	//static constexpr int STAGE_DISTANCE = FPS * 60; // ステージの長さ
	static constexpr int STAGE_DISTANCE = FPS * 30; // ステージの長さ

	//static constexpr int PLAYER_SHIELD_MAX = 10;		// 自機のシールドの最大値
	static constexpr int PLAYER_SHIELD_MAX = 100;		// 自機のシールドの最大値

	static constexpr int EFFECT_MAX = 100;			// エフェクトの最大数
	static constexpr int ITEM_TYPE = 3;				// アイテムの種類
	static constexpr int WEAPON_LV_MAX = 10;		// 武器レベルの最大値
	//static constexpr int PLAYER_SPEED_MAX = 20;		// 自機の速さの最大値
	static constexpr int PLAYER_SPEED_MAX = 30;		// 自機の速さの最大値

	// --- 弾の発射間隔 ---
	static constexpr int FireInterval = 20;       // 通常モード
	static constexpr int FireIntervalHidden = 3; // 隠し要素モード
	static constexpr int RapidModeThreshold = 120; // 隠し要素モードまでの待機時間

};