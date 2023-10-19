#include "SceneAbstract.h"
#include <ctime>
#include <chrono>

SceneAbstract::SceneAbstract();

void SceneAbstract::start()
{

}

void SceneAbstract::update(float deltaTime)
{
	do {
		float currentTime = std::chrono::system_clock::now();
	}
	while (true)
}

void SceneAbstract::render()
{

}

SceneAbstract::~SceneAbstract();