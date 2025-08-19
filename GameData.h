#pragma once

class GameData
{
public:
	// --- ゲーム状態 ---
	static int distance; // ステージ終端までの距離
	static int bossIdx; // ボスを代入した配列のインデックス
	static int stage; // ステージ
	static int score; // スコア
	static int hisco; // ハイスコア
	static int noDamage; // 無敵状態
	static int weaponLv; // 自機の武器のレベル（同時に発射される弾数）
	static int scene; // シーンを管理
	static int timer; // 時間の進行を管理

};