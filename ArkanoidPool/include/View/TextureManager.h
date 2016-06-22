#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <gl/glaux.h>
#include <string>
#include <map>
#include <iostream>
#include <memory>

#include "textures_description.h"

// Forward declaration
struct Texture;

//typedef std::map<std::string, Texture*> TexturesMap;
typedef std::map<std::string, std::shared_ptr<Texture> > TexturesMap;

struct Texture {
	unsigned id;
	AUX_RGBImageRec* data;
	~Texture();
};


// Load and provide access to all textures
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void loadTextures();
	const TexturesMap* getTexturesPool() { return &texturesPool; }
private:
	AUX_RGBImageRec* loadImage(const std::string& fileName);
	TexturesMap texturesPool;

};

#endif // TEXTURE_MANAGER_H