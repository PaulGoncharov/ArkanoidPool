#include "View/TextureManager.h"

Texture::~Texture() {
	free(data);
}

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
	texturesPool.clear();
}

void TextureManager::loadTextures() {

	std::shared_ptr<Texture> introBackground(new Texture());
	texturesPool[textures::introBackground] = introBackground;

	std::shared_ptr<Texture> mainBackground(new Texture());
	texturesPool[textures::mainBackground] = mainBackground;

	std::shared_ptr<Texture> winBackground(new Texture());
	texturesPool[textures::winBackground] = winBackground;

	std::shared_ptr<Texture> loseBackground(new Texture());
	texturesPool[textures::loseBackground] = loseBackground;

	std::shared_ptr<Texture> brick1hit(new Texture());
	texturesPool[textures::brick1hit] = brick1hit;

	std::shared_ptr<Texture> brick2hits(new Texture());
	texturesPool[textures::brick2hits] = brick2hits;

	std::shared_ptr<Texture> brick3hits(new Texture());
	texturesPool[textures::brick3hits] = brick3hits;

	std::shared_ptr<Texture> scate(new Texture());
	texturesPool[textures::scate] = scate;

	std::shared_ptr<Texture> mainBall(new Texture());
	texturesPool[textures::mainBall] = mainBall;

	std::shared_ptr<Texture> collisionBall(new Texture());
	texturesPool[textures::collisionBall] = collisionBall;

	TexturesMap::iterator mIt;

	for (mIt = texturesPool.begin(); mIt != texturesPool.end(); ++mIt) {
		Texture *texture = (*mIt).second.get();
		texture->data = loadImage((*mIt).first);

		if (texture->data) {
			glGenTextures(1, &texture->id);
			glBindTexture(GL_TEXTURE_2D, texture->id);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

			glTexImage2D(GL_TEXTURE_2D, 0, 3,
				texture->data->sizeX,
				texture->data->sizeY,
				0, GL_RGB, GL_UNSIGNED_BYTE,
				texture->data->data);
		}
	}
}

AUX_RGBImageRec* TextureManager::loadImage(const std::string& fileName) {

	FILE *stream;

	if (fileName.empty())										
	{
		return NULL;									
	}

	fopen_s(&stream, fileName.c_str(), "r");

	if (stream)
	{
		fclose(stream);
		return auxDIBImageLoad(fileName.c_str());
	}

	return NULL;
}