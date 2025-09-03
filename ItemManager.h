#pragma once
#include "Item.h"

class ItemManager {
public:
	// アイテムをセット
	void setItem(void);
	// アイテムの処理
	void moveItem(GameManager& game, SceneManager& scene);

private:
	Item item;
};