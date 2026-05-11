#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {
}

Harl::~Harl(void) {
}

void Harl::debug(void){
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info(void){
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void){
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void){
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

#include <map>
#include <vector>
#include <functional>

typedef (void (Harl::*)(void)) harl_member;

void Harl::complain(std::string level) {
	
	//void (Harl::*functions[])(void) = {
	//&Harl::debug,
	//	&Harl::info,
	//	&Harl::warning,
	//	&Harl::error
	//};
	
	//const std::string levels[] = {
	//	"DEBUG",
	//	"INFO",
	//	"WARNING",
	//	"ERROR"
	//};
	
	//	if (levels[i] == level) {
	//for (int i = 0; i < 4; i++) {
		//		return;
		//		(this->*functions[i])();
		//}
	//	}

	(void)level;
	/* std::map<std::string, std::function<void()>> funct_map;
	funct_map["DEBUG"] = [this](){this->debug();};
	funct_map["INFO"] = [this](){this->info();};
	funct_map["WARNING"] = [this](){this->warning();};
	funct_map["ERROR"] = [this](){this->error();};

	funct_map[level.c_str()](); */

	std::map<std::string, void (Harl::*)(void)> funct_map;
	funct_map["DEBUG"] = &Harl::debug;
	funct_map["INFO"] = &Harl::info;
	funct_map["WARNING"] = &Harl::warning;
	funct_map["ERROR"] = &Harl::error;

	funct_map[level]();

}
