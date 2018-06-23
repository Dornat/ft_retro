#include "Enemy.hpp"

Enemy::Enemy(void) {
	char names[] = {
		'Y', 'X', 'Z'
	};
	this->setYPos(-42 + rand() % 30);
	this->setXPos(rand() % (WINDOW_WIDTH - 2) + 1);
	this->setSpeed(rand() % 3 + 1);
	this->setName(names[rand() % 3]);
}

Enemy::Enemy(const Enemy& copy) {
	*this = copy;
}

Enemy::~Enemy(void) {
	return;
}

Enemy& Enemy::operator=(const Enemy& rhs) {
	this->setYPos(rhs.getYPos());
	this->setXPos(rhs.getXPos());
	return *this;
}

/* Getters */

int Enemy::getYPos(void) const {
	return this->_yPos;
}

int Enemy::getXPos(void) const {
	return this->_xPos;
}

int Enemy::getSpeed(void) const {
	return this->_speed;
}

char Enemy::getName(void) const {
	return this->_name;
}

/* Setters */

void Enemy::setYXPosSmart(int yPos) {
	if (yPos > (WINDOW_HEIGHT - 2)) {
		this->setYPos(-42 + rand() % 10);
		this->setXPos(rand() % (WINDOW_WIDTH - 2) + 1);
	} else if (yPos == -1) {
		this->setYPos(1);
	}else {
		this->setYPos(yPos);
	}
}

void Enemy::setYPos(int yPos) {
	this->_yPos = yPos;
}

void Enemy::setXPos(int xPos) {
	this->_xPos = xPos;
}

void Enemy::setSpeed(int speed) {
	this->_speed = speed;
}

void Enemy::setName(char name) {
	this->_name = name;
}
