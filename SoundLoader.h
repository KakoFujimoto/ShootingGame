#pragma once
#include "SoundContainer.h"
#include "DxLib.h"

class SoundLoader
{
public:
	void load(Sound& sound)
	{
		sound.handle = LoadSoundMem(sound.filePath.c_str());
	}

	void loadAll(SoundContainer& container)
	{
		load(container.bgm);
		load(container.jinOver);
		load(container.jinClear);
		load(container.seExpl);
		load(container.seItem);
		load(container.seShot);
	}
};