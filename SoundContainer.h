#pragma once
#include "Sound.h"

class SoundContainer
{
public:
	Sound bgm{ "sound/bgm.mp3" };
	Sound jinOver{ "sound/gameover.mp3" };
	Sound jinClear{ "sound/stageclear.mp3" };
	Sound seExpl{ "sound/explosion.mp3" };
	Sound seItem{ "sound/item.mp3" };
	Sound seShot{ "sound/shot.mp3" };
};