#include "HealthKit.hpp"

HealthKit::HealthKit(void) {
	this->setYPos(-10);
	this->setXPos(-10);
}

HealthKit::HealthKit(const HealthKit& copy) {
	*this = copy;
}

HealthKit::~HealthKit(void) {
	return;
}

HealthKit& HealthKit::operator=(const HealthKit& rhs) {
	this->setYPos(rhs.getYPos());
	this->setXPos(rhs.getXPos());
	return *this;
}

void HealthKit::display(WINDOW* win) {
	mvwaddch(win, this->getYPos(), this->getXPos(), ' ');
	this->setYXPosSmart(this->getYPos() + 1);
	wattron(win, A_BOLD);
	wattron(win, COLOR_PAIR(5));
	mvwaddch(win, this->getYPos(), this->getXPos(), '+');
	wattroff(win, A_BOLD);
	wattroff(win, COLOR_PAIR(5));
}

/* Setters */

void HealthKit::setYXPosSmart(int yPos) {
	if (yPos > (WINDOW_HEIGHT - 2)) {
		this->setYPos(-10);
		this->setXPos(-10);
	} else {
		this->setYPos(yPos);
	}
}
