#pragma once
#include "Effetct.h"

class EffectManager {
public:
	void setEffect(int x, int y, EffectType ptn, ImageContainer& imageContainer);

	void drawEffect(void);

private:
	std::array<Effect, GameConfig::EFFECT_MAX> effects;
};