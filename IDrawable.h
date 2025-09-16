#pragma once
#include <DxLib.h>
#include "Image.h"


class Image;

struct IDrawable {
	virtual ~IDrawable() = default;
	virtual void drawGraphic() const = 0;
};

struct ImageData : public IDrawable {
	int x, y;
	const Image& img;
	bool isTransParent;

	ImageData(int x, int y, const Image& img, bool isTransParent)
		: x(x), y(y), img(img), isTransParent(isTransParent){ }


	void drawGraphic() const override {
		DrawGraph(x, y, img.getId(), isTransParent);
	}
};

struct RectGraph : public IDrawable {
	int x, y, srcX, srcY, w, h;
	const Image& img;
	void drawGraphic() const override {
		DrawRectGraph(x, y, srcX, srcY, w, h,img.getId(), TRUE, FALSE);
	}
};

struct CircleData : public IDrawable {
	int x, y, r;
	int color;
	bool isFilled;
	void drawGraphic() const override {
		DrawCircle(x, y, r, color, isFilled);
	}
};

struct BoxData : public IDrawable {
	int left, top, right, bottom;
	int color;
	bool isFilled;

	BoxData(int left, int top, int right, int bottom, int color, bool isFilled)
		:left(left), top(top), right(right), bottom(bottom), color(color), isFilled(isFilled){ }

	void drawGraphic() const override {
		DrawBox(left, top, right, bottom, color, isFilled);
	}
};