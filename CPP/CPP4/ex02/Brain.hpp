#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
	std::string ideas[100];

public:
	// Constructor
	Brain();
	
	// Copy constructor
	Brain(const Brain& other);
	
	// Assignment operator
	Brain& operator=(const Brain& other);
	
	// Destructor
	~Brain();

	// Member functions
	void setIdea(int index, const std::string& idea);
	std::string getIdea(int index) const;
};

#endif
