#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>
#include <string>

template<typename T, typename F>
void iter(T* array, const size_t length, F function) {
	if (!array)
		return;
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template<typename T, typename F>
void iter(const T* array, const size_t length, F function) {
	if (!array)
		return;
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

#endif
