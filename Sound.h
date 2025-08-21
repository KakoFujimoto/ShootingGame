#pragma once
#include <string>

class Sound
{
public:
	std::string filePath;
	int handle = -1;

	Sound() = default;
	Sound(const std::string& path) : filePath(path){}
};