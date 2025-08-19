#pragma once
#include <string>

class Sound
{
public:

	//// ゲーム開始時のサウンドロード処理
	//void load();

	//// Bullet発射サウンドのロード処理
	//void loadShotSound(const std::string& filePath);

	//// Bullet発射サウンドの再生
	//void playShot() const;

	// ゲーム中で使用される音
	int bgm;
	int jinOver;
	int jinClear;
	int seExpl;
	int seItem;
	int seShot;

private:
	int seShotHandle = -1;
};