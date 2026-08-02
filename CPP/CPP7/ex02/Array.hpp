#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib>
#include <cstddef>
#include <string>
#include <ctime>

template<typename T>
class Array {
private:
	T*				_elements;
	unsigned int	_size;

public:
	Array() : _elements(0), _size(0) {}
	
	Array(unsigned int n) : _elements(0), _size(n) {
		if (n > 0)
			_elements = new T[n]();
	}
	
	Array(Array const & src) : _elements(0), _size(src._size) {
		if (_size > 0) {
			_elements = new T[_size]();
			for (unsigned int i = 0; i < _size; i++)
				_elements[i] = src._elements[i];
		}
	}
	
	~Array() {
		delete[] _elements;
	}
	
	Array & operator=(Array const & rhs) {
		if (this != &rhs) {
			T* new_elements = 0;
			if (rhs._size > 0) {
				new_elements = new T[rhs._size]();
				for (unsigned int i = 0; i < rhs._size; i++)
					new_elements[i] = rhs._elements[i];
			}
			delete[] _elements;
			_elements = new_elements;
			_size = rhs._size;
		}
		return *this;
	}
	
	T & operator[](unsigned int index) {
		if (index >= _size)
			throw OutOfBoundsException();
		return _elements[index];
	}
	
	T const & operator[](unsigned int index) const {
		if (index >= _size)
			throw OutOfBoundsException();
		return _elements[index];
	}
	
	unsigned int size() const {
		return _size;
	}
	
	class OutOfBoundsException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Array index out of bounds";
		}
	};
};

#endif
