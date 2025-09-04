#include "SceneOver.h"
#include "SceneType.h"
#include "GameManager.h"


std::shared_ptr<IScene> SceneOver::run(GameManager& game)
{
		if (game.getGameData().timer < GameConfig::FPS * 3) // Ž©‹@‚ª”š”­‚·‚é‰‰o

	{
			if (game.getGameData().timer % 7 == 0)
			{
				game.getEffect().setEffect
				(
					game.getPlayer().getX() + rand() % 81 - 40,
					game.getPlayer().getY() + rand() % 81 - 40,
					EffectType::Explode,
					game.getImage()
				);
			}
	}
	else if (game.getGameData().timer == GameConfig::FPS * 3)
	{
		game.getSoundPlayer().play(game.getSoundContainer().jinOver);
	}
	else
	{
			game.getDrawer().drawTextC(GameConfig::WIDTH * 0.5, GameConfig::HEIGHT * 0.3, "GAME OVER", 0xff0000, 80);
	}
		if (game.getGameData().timer > GameConfig::FPS * 10)
		{
			return std::make_shared<SceneTitle>();
		}
	return nullptr;
}