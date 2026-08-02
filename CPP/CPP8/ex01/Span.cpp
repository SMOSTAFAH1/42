#include "Span.hpp"

Span::Span() : _N(0) {}
Span::Span(unsigned int N) : _N(N) {}
Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
	if (_numbers.size() >= _N)
		throw FullException();
	_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw NotEnoughElementsException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	std::vector<int> diffs(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), diffs.begin());

	return *std::min_element(diffs.begin() + 1, diffs.end());
}

int Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw NotEnoughElementsException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}

const char* Span::FullException::what() const throw() {
	return "Span is full, cannot add more elements";
}

const char* Span::NotEnoughElementsException::what() const throw() {
	return "Not enough elements to calculate span (need at least 2)";
}
