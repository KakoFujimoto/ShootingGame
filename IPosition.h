#pragma once

// オブジェクトの座標を表すインターフェース
class IPosition
{
public:
	virtual ~IPosition() = default;

	// x座標
	virtual int getX() const = 0;
	virtual void setX(int) = 0;
	// y座標
	virtual int getY() const = 0;
	virtual void setY(int) = 0;
};