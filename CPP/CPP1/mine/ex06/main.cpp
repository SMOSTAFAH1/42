#include "Harl.hpp"
#include <iostream>

int getLevelIndex(const std::string& level) {
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			return i;
	}
	return -1;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return 1;
	}
	
	Harl harl;
	std::string level = argv[1];
	int levelIndex = getLevelIndex(level);
	
	switch (levelIndex) {
		case 0:
			harl.complain("DEBUG");
			// fall through
		case 1:
			harl.complain("INFO");
			// fall through
		case 2:
			harl.complain("WARNING");
			// fall through
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	
	return 0;
}
