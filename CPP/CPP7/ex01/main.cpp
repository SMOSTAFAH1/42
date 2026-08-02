#include "iter.hpp"

template<typename T>
void printElement(T const & element) {
	std::cout << element << " ";
}

void incrementInt(int & n) {
	n++;
}

int main(void) {
	int arr[] = {1, 2, 3, 4, 5};
	::iter(arr, 5, printElement<int>);
	std::cout << "\nIncrementing: ";
	::iter(arr, 5, incrementInt);
	::iter(arr, 5, printElement<int>);
	std::cout << "\n";

	return 0;
}
