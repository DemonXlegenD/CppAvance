#pragma once
#include <iostream>
#include <string>
class Component
{
public: 
	Component();
	Component(std::string name);


	~Component();
private:
	std::string name = "Component";
};

