#include "Deserializer/deserializer.h"
#include <fstream>


deserializer::deserializer()
{
}


deserializer::~deserializer()
{
}

bool deserializer::deserialize(const std::string& fileName, Briks& briks) {

	std::filebuf fb;
	Json::Value root;  
	Json::Reader reader;

	if (fb.open(fileName, std::ios::in)) {
		std::istream is(&fb);
		if (!reader.parse(is,root)) {
			return false;
		}
	}
	else {
		return false;
	}
	const Json::Value array = root["briks"];
	for (std::size_t i = 0; i < array.size(); ++i) {
		briks.push_back(getBrick(array[i]));
	}
	return true;
}

Brick deserializer::getBrick(const Json::Value& jsBrick) {
	int x, y, width, height, hits;
	x =			jsBrick.get("x", 0).asInt();
	y =			jsBrick.get("y", 0).asInt();
	width =		jsBrick.get("width", 0).asInt();
	height =	jsBrick.get("height", 0).asInt();
	hits =		jsBrick.get("hits", 0).asInt();
	return Brick(x, y, static_cast<int>(width),
		static_cast<int>(height), static_cast<int>(hits));
}