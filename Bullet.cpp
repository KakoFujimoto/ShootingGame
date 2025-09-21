#include "Bullet.h"
#include "GameManager.h"

void Bullet::update(ImageContainer& imageContainer,GameManager& game){
	updatePosition();
	game.getDrawer().drawImage(imageContainer.getBullet(), getX(), getY()); // ’e‚Ì•`‰æ
	if (y < -100)
	{
		setState(0); // ‰æ–ÊŠO‚Éo‚½‚çA‘¶Ý‚µ‚È‚¢ó‘Ô‚É‚·‚é
	}
}

void Bullet::reset(int x, int y)
{
	setX(x);
	setY(y);
	setVX(0);
	setVY(-40);
	setState(1);
}