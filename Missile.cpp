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
	mvwaddch(win, this->getYPos(), this->getXPos(), '|');
}

void Missile::displayEnemy(WINDOW* win) {
	mvwaddch(win, this->getYPos(), this->getXPos(), ' ');
	this->_setYXPosSmartEnemy(this->getYPos() + 1);
	mvwaddch(win, this->getYPos(), this->getXPos(), '|');
}

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

/* Getters */

int Missile::getYPos(void) const {
	return this->_yPos;
}

int Missile::getXPos(void) const {
	return this->_xPos;
}

/* Setters */

void Missile::setYPos(int yPos) {
	this->_yPos = yPos;
}

void Missile::setXPos(int xPos) {
	this->_xPos = xPos;
}
