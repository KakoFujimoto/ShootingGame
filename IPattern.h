#pragma once

class IPattern
{
	public:
		virtual ~IPattern() = default;

		virtual void setPattern(int v) = 0;
		virtual int getPattern() const = 0;

};