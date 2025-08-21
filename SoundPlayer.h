#pragma once
#include "Sound.h"
#include "DxLib.h"

class SoundPlayer
{
public:
	void play(const Sound& sound)
	{
			PlaySoundMem(sound.handle, DX_PLAYTYPE_BACK);
	}

	void stop(const Sound& sound)
	{
			StopSoundMem(sound.handle);
	}

	void setVolume(const Sound& sound, int volume)
	{
		
			ChangeVolumeSoundMem(volume, sound.handle);
	}
};