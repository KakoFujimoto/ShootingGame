#pragma once
#include "Sound.h"
#include "DxLib.h"

class SoundPlayer
{
public:
	void play(const Sound& sound)
	{
		if (sound.handle != -1)
		{
			PlaySoundMem(sound.handle, DX_PLAYTYPE_BACK);
		}
	}

	void stop(const Sound& sound)
	{
		if (sound.handle != -1)
		{
			StopSoundMem(sound.handle);
		}
	}

	void setVolume(const Sound& sound, int volume)
	{
		if (sound.handle != -1)
		{
			ChangeVolumeSoundMem(volume, sound.handle);
		}
	}
};