#pragma once

// �I�u�W�F�N�g�̍��W��\���C���^�[�t�F�[�X
class IPosition
{
public:
	virtual ~IPosition() = default;

	// x���W
	virtual void setX(int) = 0;
	virtual int getX() const = 0;

	// y���W
	virtual void setY(int) = 0;
	virtual int getY() const = 0;

};