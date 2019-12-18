#include "ImageManager.h"
#include <Renderer2D.h>



ImageManager::ImageManager()
{
}


ImageManager::~ImageManager()
{
}

void ImageManager::AddImage(aie::Texture* image)
{
	imageList.push_back(image);
}

aie::Texture* ImageManager::GetImage(int index)
{
	return imageList[index];
}
