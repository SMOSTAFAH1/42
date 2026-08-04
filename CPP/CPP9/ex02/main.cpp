#include "PmergeMe.hpp"

static double getTimeUs() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return static_cast<double>(tv.tv_sec) * 1000000.0 + static_cast<double>(tv.tv_usec);
}

static void printSequence(const std::vector<int>& vec) {
	size_t maxDisplay = (vec.size() > 5) ? 4 : vec.size();
	for (size_t i = 0; i < maxDisplay; i++) {
		std::cout << vec[i];
		if (i + 1 < maxDisplay || vec.size() > 5)
			std::cout << " ";
	}
	if (vec.size() > 5)
		std::cout << "[...]";
}

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<int> numbers;
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		if (arg.empty()) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
		std::stringstream ss(arg);
		std::string token;
		while (ss >> token) {
			char* end;
			long num = strtol(token.c_str(), &end, 10);
			if (*end != '\0' || num < 0 || num > 2147483647) {
				std::cerr << "Error" << std::endl;
				return 1;
			}
			numbers.push_back(static_cast<int>(num));
		}
	}

	if (numbers.empty()) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::cout << "Before: ";
	printSequence(numbers);
	std::cout << std::endl;

	double startVector = getTimeUs();
	PmergeMe vectorSorter;
	for (size_t i = 0; i < numbers.size(); i++)
		vectorSorter.addNumber(numbers[i]);
	vectorSorter.sortVector();
	double endVector = getTimeUs();
	double vectorTime = endVector - startVector;

	double startDeque = getTimeUs();
	PmergeMe dequeSorter;
	for (size_t i = 0; i < numbers.size(); i++)
		dequeSorter.addNumber(numbers[i]);
	dequeSorter.sortDeque();
	double endDeque = getTimeUs();
	double dequeTime = endDeque - startDeque;

	std::cout << "After:  ";
	printSequence(vectorSorter.getVector());
	std::cout << std::endl;

	std::cout << "Time to process a range of " << numbers.size() 
	          << " elements with std::vector : " 
	          << std::fixed << std::setprecision(5) << vectorTime << " us" << std::endl;
	
	std::cout << "Time to process a range of " << numbers.size() 
	          << " elements with std::deque  : " 
	          << std::fixed << std::setprecision(5) << dequeTime << " us" << std::endl;

	return 0;
}
