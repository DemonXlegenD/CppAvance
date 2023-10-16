#pragma once
#include <vector>

#include "../Player/Archetype.h"
#include "../Player/Archetype/ArchetypeKnight.h"
#include "../Player/Archetype/ArchetypeMage.h"

class GameConfig
{
public:
	Archetype* getArchetypeByIndex(int index);
	void createKnight();
	void createMage();

private:
	std::vector<Archetype*> archetypes;
};

