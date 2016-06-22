#ifndef DESIRIALIZER_H
#define DESIRIALIZER_H

#include <string>
#include <vector>

#include "deserializer/json.h"
#include "Model/Brick.h"

typedef std::vector<Brick> Briks;

class deserializer
{
public:
	deserializer();
	~deserializer();

	// Read all bricks, described in json file
	bool deserialize(const std::string& fileName, Briks& briks);

	Brick getBrick(const Json::Value& jsBrick);
};

#endif // DESIRIALIZER_H