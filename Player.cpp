#include "Player.hpp"

Player::Player(void) {
	this->setYPos(0);
	this->setXPos(0);
	this->setName('@');
	WINDOW* win = newwin(100,100, 100, 100);
	this->setWin(win);
	keypad(win, TRUE);
}

Player::Player(const Player& copy) {
	*this = copy;
}

Player::~Player(void) {
	return;
}

Player& Player::operator=(const Player& rhs) {
	this->setYPos(rhs.getYPos());
	this->setXPos(rhs.getXPos());
	this->setYMaxPos(rhs.getYMaxPos());
	this->setXMaxPos(rhs.getXMaxPos());
	this->setName(rhs.getName());
	this->setWin(rhs.getWin());
	return *this;
}

Player::Player(WINDOW* win, int y, int x, char name, Missile* missiles) {
	this->setYPos(y);
	this->setXPos(x);
	getmaxyx(win, this->_yMaxPos, this->_xMaxPos);
	this->setName(name);
	this->setWin(win);
	this->setMissiles(missiles);
	keypad(win, TRUE);
}

void Player::move(int key) {
	if (key == KEY_UP || key == 'k') {
		this->_moveUp();
	} else if (key == KEY_DOWN || key == 'j') {
		this->_moveDown();
	} else if (key == KEY_LEFT || key == 'h') {
		this->_moveLeft();
	} else if (key == KEY_RIGHT || key == 'l') {
		this->_moveRight();
	} else if (key == 'x') {
		this->shoot();
	}
}

void Player::display(void) {
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	wattron(this->getWin(), COLOR_PAIR(1));
	mvwaddch(this->getWin(), this->getYPos(), this->getXPos(), this->getName());
	wattroff(this->getWin(), COLOR_PAIR(1));
}

void Player::missileLauncher(int random) {
	for (int i = 0; i < PLAYER_MISSILES; i++) {
		/* if (this->getMissiles()[i].getXPos() > 0 || */
		/* 	this->getMissiles()[i].getYPos() > 0) { */
		/* 	if (random % 15 == 0) { */
		/* 		this->getMissiles()[i].display(this->getWin()); */
		/* 	} */
		/* } */
		if (this->_missiles[i].getXPos() > 0 ||
			this->_missiles[i].getYPos() > 0) {
			if (random % 10 == 0) {
				this->_missiles[i].displayPlayer(this->_win);
			}
		}
	}
}

void Player::shoot(void) {
	for (int i = 0; i < PLAYER_MISSILES; i++) {
		if (this->getMissiles()[i].getXPos() < 0 ||
			this->getMissiles()[i].getYPos() < 0) {
			this->getMissiles()[i].setYPos(this->getYPos() - 1);
			this->getMissiles()[i].setXPos(this->getXPos());
			break;
		}
	}
}

/* Private */

void Player::_moveUp(void) {
	mvwaddch(this->getWin(), this->getYPos(), this->getXPos(), ' ');
	this->setYPos(this->getYPos() - 1);
	if (this->getYPos() < 1) {
		this->setYPos(1);
	}
}

void Player::_moveDown(void) {
	mvwaddch(this->getWin(), this->getYPos(), this->getXPos(), ' ');
	this->setYPos(this->getYPos() + 1);
	if (this->getYPos() > this->getYMaxPos() - 2) {
		this->setYPos(this->getYMaxPos() - 2);
	}
}

void Player::_moveLeft(void) {
	mvwaddch(this->getWin(), this->getYPos(), this->getXPos(), ' ');
	this->setXPos(this->getXPos() - 1);
	if (this->getXPos() < 1) {
		this->setXPos(1);
	}
}

void Player::_moveRight(void) {
	mvwaddch(this->getWin(), this->getYPos(), this->getXPos(), ' ');
	this->setXPos(this->getXPos() + 1);
	if (this->getXPos() > this->getXMaxPos() - 2) {
		this->setXPos(this->getXMaxPos() - 2);
	}
}

/* Getters */

int Player::getYPos(void) const {
	return this->_yPos;
}

int Player::getXPos(void) const {
	return this->_xPos;
}

int Player::getYMaxPos(void) const {
	return this->_yMaxPos;
}

int Player::getXMaxPos(void) const {
	return this->_xMaxPos;
}

char Player::getName(void) const {
	return this->_name;
}

WINDOW* Player::getWin(void) const {
	return this->_win;
}

Missile* Player::getMissiles(void) const {
	return this->_missiles;
}

/* Setters */

void Player::setYPos(int yPos) {
	this->_yPos = yPos;
}

void Player::setXPos(int xPos) {
	this->_xPos = xPos;
}

void Player::setYMaxPos(int yMaxPos) {
	this->_yMaxPos = yMaxPos;
}

void Player::setXMaxPos(int xMaxPos) {
	this->_xMaxPos = xMaxPos;
}

void Player::setName(char name) {
	this->_name = name;
}

void Player::setWin(WINDOW* win) {
	this->_win = win;
}

void Player::setMissiles(Missile* missiles) {
	this->_missiles = missiles;
}
