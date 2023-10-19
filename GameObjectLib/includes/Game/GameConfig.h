#pragma once
#include <vector>

#include "../Player/PlayerArchetype.h"
#include "../Player/Archetype/PlayerArchetypeKnight.h"
#include "../Player/Archetype/PlayerArchetypeMage.h"

class GameConfig
{
public:
	PlayerArchetype* getArchetypeByIndex(int index);
	void createKnight();
	void createMage();

private:
	std::vector<PlayerArchetype*> archetypes;
};
