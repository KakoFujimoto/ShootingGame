#pragma once
#include "Item.h"

class ItemManager {
public:
	// �A�C�e�����Z�b�g
	void setItem(void);
	// �A�C�e���̏���
	void moveItem(GameManager& game);

private:
	Item item;
};