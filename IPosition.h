#pragma once

// �I�u�W�F�N�g�̍��W��\���C���^�[�t�F�[�X
class IPosition
{
public:
	virtual ~IPosition() = default;

	// x���W
	virtual int getX() const = 0;
	virtual void setX(int) = 0;
	// y���W
	virtual int getY() const = 0;
	virtual void setY(int) = 0;
};