#include "GameLog.h"

static void GameLog::log(std::string& message) {
	std::cout << std::string("Log : ") << message << std::endl;
}
static void GameLog::debug(std::string& message) {
	std::cout << std::string("Debug : ") << message << std::endl;
}
static void GameLog::error(std::string& message) {
	std::cerr << std::string("Error : ") << message << std::endl;
}