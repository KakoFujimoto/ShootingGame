#pragma once
#include <DxLib.h>


class Image;

struct DrawData {
	virtual ~DrawData() = default;
	virtual void drawGraphic() const = 0;
};

struct ImageData : public DrawData {
	const Image& img;
	int x, y;
	bool isTransParent;
	void drawGraphic() const override {
		DrawGraph(x, y, img.getId(), isTransParent);
	}
};

struct RectGraph : public DrawData {
	int x, y, srcX, srcY, w, h;
	const Image& img;
	void drawGraphic() const override {
		DrawRectGraph(x, y, srcX, srcY, w, h,img.getId(), TRUE, FALSE);
	}
};

struct CircleData : public DrawData {
	int x, y, r;
	int color;
	bool isFilled;
	void drawGraphic() const override {
		DrawCircle(x, y, r, color, isFilled);
	}
};

struct BoxData : public DrawData {
	int left, top, right, bottom;
	int color;
	bool isFilled;
	void drawGraphic() const override {
		DrawBox(left, top, right, bottom, color, isFilled);
	}
};

//// 描画データ構造
//struct ImageData {
//	int x, y;
//	const Image& img;
//	bool isTransParent;
//};
//
//struct RectData {
//	int x, y, srcX, srcY, w, h;
//	const Image& img;
//};
//
//struct CircleData {
//	int x, y, r;
//	int color;
//	bool isFilled;
//};
//
//struct BoxData {
//	int left, top, right, bottom;
//	int color;
//	bool isFilled;
//};