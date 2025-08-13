#include "Sound.h"
#include <DxLib.h>

// ゲーム開始時のサウンドロード処理
void Sound::load()
{
	bgm = LoadSoundMem("sound/bgm.mp3");
	jinOver = LoadSoundMem("sound/gameover.mp3");
	jinClear = LoadSoundMem("sound/stageclear.mp3");
	seExpl = LoadSoundMem("sound/explosion.mp3");
	seItem = LoadSoundMem("sound/item.mp3");
	seShot = LoadSoundMem("sound/shot.mp3");

	ChangeVolumeSoundMem(128, bgm);
	ChangeVolumeSoundMem(128, jinOver);
	ChangeVolumeSoundMem(128, jinClear);
}

// Bullet発射サウンドのロード処理
void Sound::loadShotSound(const std::string& filepath)
{
	seShotHandle = LoadSoundMem(filepath.c_str());
	ChangeVolumeSoundMem(128, seShotHandle);
}

// Bullet発射サウンドの再生
void Sound::playShot() const
{
	if (seShotHandle != -1)
	{
		PlaySoundMem(seShotHandle, DX_PLAYTYPE_BACK);
	}
}