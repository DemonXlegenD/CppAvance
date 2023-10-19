#include "Game/GameConfig.h"

void GameConfig::createKnight() {
	PlayerArchetype* archetype = new PlayerArchetypeKnight();
	archetypes.push_back(archetype);
}

void GameConfig::createMage() {
	PlayerArchetype* archetype = new PlayerArchetypeMage();
	archetypes.push_back(archetype);
}

PlayerArchetype* GameConfig::getArchetypeByIndex(int index) {
	if (archetypes.size() > index) {
		return archetypes[index];
	}
	return nullptr;
}