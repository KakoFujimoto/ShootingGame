#pragma once
#include <string>

class DrawerManager
{
public:
	struct TextStyle {
		int color = 0xffffff; // Default white color
		int size = 16; // Default font size
		bool shadow = false; // Default no shadow
		bool center = false; // Default not centered
	};

	static TextStyle DefaultTextStyle();

};