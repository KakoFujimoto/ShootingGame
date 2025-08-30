#pragma once
#include "Item.h"

class ItemManager {
	Item item;
public:
	// アイテムをセット
	void setItem(void);
	// アイテムの処理
	void moveItem(void);
};