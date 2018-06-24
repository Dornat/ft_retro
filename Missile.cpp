#include "Missile.hpp"

Missile::Missile(void) {
	this->setYPos(-10);
	this->setXPos(-10);
}

Missile::Missile(const Missile& copy) {
	*this = copy;
}

Missile::~Missile(void) {
	return;
}

Missile& Missile::operator=(const Missile& rhs) {
	this->setYPos(rhs.getYPos());
	this->setXPos(rhs.getXPos());
	return *this;
}

void Missile::displayPlayer(WINDOW* win) {
	mvwaddch(win, this->getYPos(), this->getXPos(), ' ');
	this->_setYXPosSmartPlayer(this->getYPos() - 1);
	wattron(win, COLOR_PAIR(3));
	mvwaddch(win, this->getYPos(), this->getXPos(), '|');
	wattroff(win, COLOR_PAIR(3));
}

void Missile::displayEnemy(WINDOW* win) {
	mvwaddch(win, this->getYPos(), this->getXPos(), ' ');
	this->_setYXPosSmartEnemy(this->getYPos() + 1);
	wattron(win, COLOR_PAIR(4));
	mvwaddch(win, this->getYPos(), this->getXPos(), '|');
	wattroff(win, COLOR_PAIR(4));
}

/* Private */

void Missile::_setYXPosSmartPlayer(int yPos) {
	if (yPos < 1) {
		this->setYPos(-10);
		this->setXPos(-10);
	} else {
		this->setYPos(yPos);
	}
}

void Missile::_setYXPosSmartEnemy(int yPos) {
	if (yPos > WINDOW_HEIGHT - 2 || yPos > WINDOW_HEIGHT) {
		this->setYPos(-10);
		this->setXPos(-10);
	} else if (yPos == -1 || yPos == 0) {
		this->setYPos(1);
	} else {
		this->setYPos(yPos);
	}
}
