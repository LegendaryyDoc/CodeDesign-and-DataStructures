#include "FallingFactory.h"
#include <ctime>

SimpleSprite* FallingFactory::spriteMasters = NULL;
SimpleSprite* FallingFactory::newSpriteMasters = NULL;
size_t FallingFactory::spriteCount = NULL;

void FallingFactory::init()
{
	spriteCount = 4;
	spriteMasters = new SimpleSprite[spriteCount];
	spriteMasters[0] = *(new SimpleSprite("coin_anim_f0.png", "rock", 10.f));
	spriteMasters[1] = *(new SimpleSprite("coin_anim_f0.png", "rock", 10.f));
	spriteMasters[2] = *(new SimpleSprite("coin_anim_f0.png", "rock", 10.f));
	spriteMasters[3] = *(new SimpleSprite("coin_anim_f0.png", "rock", 10.f));
}

SimpleSprite * FallingFactory::getRandom()
{
	srand(time(NULL));

	int randMaster = rand() % spriteCount;

	return &spriteMasters[randMaster];
}

SimpleSprite * FallingFactory::getFromType(const std::string & _sprType)
{
	//  identify how many elements in spritemasters have a sprtype matching _sprtype.
	size_t newSpriteCount = 0;
	for (int i = 0; i < spriteCount; i++)
	{
		if (spriteMasters[i].sprType == _sprType)
		{
			++newSpriteCount;
		}
		else
		{
			delete &newSpriteMasters[i];
		}
	}

	//	create a new dynamic array of SimpleSprite of that size
	newSpriteMasters = new SimpleSprite[newSpriteCount];

	//	copy those elements that match from spritemasers to new temp array.
	for (int i = 0; i < newSpriteCount; i++)
	{
		newSpriteMasters[i] = spriteMasters[i];
	}

	//	pick one of those array elements at random
	int randMaster = rand() % newSpriteCount;

	newSpriteMasters[randMaster].r2.x = rand() % 800;
	newSpriteMasters[randMaster].r2.y = 0;

	//	return a new sprite based on that one.
	return &newSpriteMasters[randMaster];
}

FallingFactory::FallingFactory()
{

}

FallingFactory::~FallingFactory()
{

}
