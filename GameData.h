#pragma once
#include "SceneType.h"

class GameData
{
public:
	int distance = 0; // ステージ終端までの距離
	int bossIdx = 0; // ボスを代入した配列のインデックス
	int stage = 1; // ステージ
	int score = 0; // スコア
	int hisco = 10000; // ハイスコア
	int noDamage = 0; // 無敵状態
	int weaponLv = 1; // 自機の武器のレベル（同時に発射される弾数）
	SceneType scene = SceneType::Title; // シーンを管理
	int timer = 0; // 時間の進行を管理
	bool isRapidMode = false; // 連射モードのフラグ
	bool isRunning = true;
};