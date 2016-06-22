#include "Model/Brick.h"

/*std::map<unsigned, std::string> Brick::textureMap = {
	{ 0, std::string("") },
	{ 1, textures::brick1hit },
	{ 2, textures::brick2hits },
	{ 3, textures::brick2hits }
};*/

Brick::Brick()
: hits(0)
, destroyed(false)
{

}

Brick::Brick(int x, int y, unsigned width, unsigned height, unsigned hits)
: hits(hits)
, destroyed(false)
{
	pos.left = static_cast<float>(x);
	pos.right = static_cast<float>(x + width);
	pos.bottom = static_cast<float>(y);
	pos.top = static_cast<float>(y + height);
}


Brick::~Brick()
{
}

/*const std::string& Brick::getCurrentTexture() const {
return textureMap[hits];
}*/

void Brick::boom(){
	hits--;
	if (hits <= 0) {
		destroyed = true;
	}
}

