#pragma once

class SceneAbstract 
{
public : 
	SceneAbstract();

	void start();
	void update(float deltaTime);
	void render();

	~SceneAbstract();

protected :

};