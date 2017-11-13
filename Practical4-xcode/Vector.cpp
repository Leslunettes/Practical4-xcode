/*
 * Vector.cpp
 */

#include "Vector.h"

using std::string;
using std::ostream;
using std::istream;

constexpr int INITIALCAP = 5;

Vector::Vector() :
		vector { nullptr }, numberOfInt { 0 }, capacity { INITIALCAP } {
	vector = new int[capacity];
}

Vector::Vector(int size, int val) {
	if (size > 0) {
		capacity = size;
		vector = new int[capacity];
		for (int i = 0; i < size; i++) {
			vector[i] = val;
		}
		numberOfInt = size;
	}
}

Vector::Vector(const Vector& other) {
	numberOfInt = other.numberOfInt;
	capacity = other.capacity;
	vector = new int[capacity];
	for (int i = 0; i < numberOfInt; i++) {
		vector[i] = other.vector[i];
	}
}

Vector::Vector(Vector && other) :
		numberOfInt { other.numberOfInt }, capacity { other.capacity }, vector {
				other.vector } {
	other.capacity = 0;
	other.numberOfInt = 0;
	other.vector = nullptr;
}

Vector::~Vector() {
	if (vector) {
		delete[] vector;
	}
}

void Vector::push_back(int val) {
	if (numberOfInt == capacity) {
		capacity = capacity * 2;
		int* temp = new int[capacity];
		for (int i = 0; i < numberOfInt; i++) {
			temp[i] = vector[i];
		}
		delete[] vector;
		vector = temp;
	}
	vector[numberOfInt] = val;
	numberOfInt++;
}

int Vector::operator[](int loc) const {
	int val;
	if (loc > 0 && loc < numberOfInt) {
		val = vector[loc];
	} else {
		val = loc;
	}
	return val;
}

int& Vector::operator[](int loc) {
	return vector[loc];
}

Vector& Vector::operator=(const Vector& other) {
	if (this != &other) {
		if (vector)
			delete[] vector;
		numberOfInt = other.numberOfInt;
		capacity = other.capacity;
		vector = new int[capacity];
		for (int i = 0; i < numberOfInt; i++) {
			vector[i] = other.vector[i];
		}
	}
	return *this;
}

Vector & Vector::operator=(Vector && other) {
	int* tempp = other.vector;
	other.vector = vector;
	vector = tempp;

	int tempi = other.numberOfInt;
	other.numberOfInt = numberOfInt;
	numberOfInt = tempi;

	tempi = other.capacity;
	other.capacity = capacity;
	capacity = tempi;

	return *this;

}

int Vector::size() const {
	return numberOfInt;
}

bool Vector::empty() const {
	for (int i = 0; i < numberOfInt; i++) {
		if (vector[i] != 0) {
			return false;
		}
	}
	return true;
}

void Vector::clear() {
	delete[] vector;
	vector = nullptr;
	numberOfInt = 0;
	capacity = 0;
}

string Vector::toString(unsigned int width, char fill) const {
	// TODO: implement me
	return "";
}

ostream& operator<<(ostream& os, const Vector& v) {
	// TODO: implement me
	return os;
}

istream & operator>>(istream & is, Vector & v) {
	// TODO: implement me
	return is;
}

