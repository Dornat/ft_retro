#include "StarSpace.hpp"

StarSpace::StarSpace(void) {
	this->setN(DEFAULT_N);
	if (n < 0) {
		return;
	}

	this->space = new Star[DEFAULT_N];

	for (int i = 0; i < DEFAULT_N; i++) {
		this->space[i].setY(rand % WINDOW_HEIGHT)
		this->space[i].setX(rand % WINDOW_WIDTH);
	}
}

StarSpace::StarSpace(const StarSpace& copy) {
	*this = copy;
}

StarSpace::~StarSpace(void) {
	return;
}

StarSpace& StarSpace::operator=(const StarSpace& rhs) {
	this->setN(rhs.getN());
	return *this;
}

StarSpace::StarSpace(int n) {
	this->setN(n);
	if (n < 0) {
		return;
	}

	this->space = new Star[n];

	for (int i = 0; i < n; i++) {
		this->space[i].setY(rand % WINDOW_HEIGHT)
		this->space[i].setX(rand % WINDOW_WIDTH);
	}
}

/* Getters */

int StarSpace::getN(void) const {
	return this->_n;
}

/* Setters */

void StarSpace::setN(int n) {
	this->_n = n;
}
