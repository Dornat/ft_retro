#include "Star.hpp"

Star::Star(void) {
	this->setYPos(rand() % (WINDOW_HEIGHT - 2) + 1);
	this->setXPos(rand() % (WINDOW_WIDTH - 2) + 1);
}

Star::Star(const Star& copy) {
	*this = copy;
}

Star::~Star(void) {
	return;
}

Star& Star::operator=(const Star& rhs) {
	this->setYPos(rhs.getYPos());
	this->setXPos(rhs.getXPos());
	return *this;
}

void Star::display(WINDOW* win) {
	mvwaddch(win, this->getYPos(), this->getXPos(), ' ');
	this->setYXPosSmart(this->getYPos() + 1);
	mvwaddch(win, this->getYPos(), this->getXPos(), '.');
}

/* Setters */

void Star::setYXPosSmart(int yPos) {
	if (yPos > (WINDOW_HEIGHT - 2)) {
		this->setYPos(1);
		this->setXPos(rand() % (WINDOW_WIDTH - 2) + 1);
	} else {
		this->setYPos(yPos);
	}
}
