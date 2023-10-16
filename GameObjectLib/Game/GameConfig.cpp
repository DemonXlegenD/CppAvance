#include "GameConfig.h"

void GameConfig::createKnight() {
	Archetype* archetype = new ArchetypeKnight();
	archetypes.push_back(archetype);
}

void GameConfig::createMage() {
	Archetype* archetype = new ArchetypeMage();
	archetypes.push_back(archetype);
}

Archetype* GameConfig::getArchetypeByIndex(int index) {
	if (archetypes.size() > index) {
		return archetypes[index];
	}
	return nullptr;
}