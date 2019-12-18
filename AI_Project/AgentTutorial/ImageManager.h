#pragma once
#include <vector>
#include <Texture.h>

class ImageManager
{
private:
	std::vector<aie::Texture*> imageList;
public:
	ImageManager();
	~ImageManager();

	void AddImage(aie::Texture* image);
	aie::Texture* GetImage(int index);
};

