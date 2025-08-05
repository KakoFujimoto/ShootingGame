#include "DxLib.h" //DXライブラリのインクルード
#include "shootingGame.h" // ヘッダーファイルをインクルード
#include <cstdlib>

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
	ENE_ZAKO03,
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