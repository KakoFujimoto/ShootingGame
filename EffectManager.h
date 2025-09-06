#pragma once
#include "Effetct.h"
#include "EffectType.h"

class GameManager;
class ImageContainer;
class SoundPlayer;
class SoundContainer;

class EffectManager {
public:
	void setEffect
	(
		int x, int y,
		EffectType ptn,
		ImageContainer& imageContainer,
		SoundPlayer& soundPlayer,
		SoundContainer& soundContainer
	);

	void drawEffect(GameManager& game);

private:
	std::array<Effect, GameConfig::EFFECT_MAX> effects;
};