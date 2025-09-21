#include "Effect.h"
#include "EffectType.h"
#include "ImageContainer.h"
#include "SoundPlayer.h"
#include "SoundContainer.h"

void Effect::initialize
(
	int x,
	int y,
	EffectType ptn,
	ImageContainer& imageContainer,
	SoundPlayer& soundPlayer,
	SoundContainer& soundContainer
)
{
	setX(x);
	setY(y);
	setVX(0);
	setVY(0);
	setPattern(ptn);
	setImage((ptn == EffectType::Explode)
		? &imageContainer.getExplosion()
		: &imageContainer.getItem());

	setWidth(getImage()->getWidth());
	setHeight(getImage()->getHeight());

	setState(1);
	setTimer(0);

	if (ptn == EffectType::Explode)
	{
		soundPlayer.play(soundContainer.seExpl);
	}
}