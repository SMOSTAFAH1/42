#include "Serializer.hpp"

int main() {
	Data original;
	original.name = "Test Data";
	original.value = 42;
	original.score = 3.14159;

	std::cout << "Original Data address: " << &original << std::endl;
	std::cout << "Original Data: name=" << original.name 
	          << ", value=" << original.value 
	          << ", score=" << original.score << std::endl;

	uintptr_t serialized = Serializer::serialize(&original);
	std::cout << "Serialized value: " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized address: " << deserialized << std::endl;

	if (deserialized == &original)
		std::cout << "Success: Addresses match!" << std::endl;
	else
		std::cout << "Error: Addresses don't match!" << std::endl;

	std::cout << "Deserialized Data: name=" << deserialized->name 
	          << ", value=" << deserialized->value 
	          << ", score=" << deserialized->score << std::endl;

	return 0;
}
