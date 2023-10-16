#pragma once
class GameState
{
public:
	bool getIsRunning() const { return isRunning; }
	void setIsRunning(bool state) { isRunning = state; }
private:
	bool isRunning = false;
};

