#pragma once
#include <string>

class Sound
{
public:
	std::string filePath;
	int handle = -1;

	Sound() = default;
	Sound(const std::string& path) : filePath(path){}

	void load();

	void loadShotSound(const std::string& filepath);

	void playShot() const;

};