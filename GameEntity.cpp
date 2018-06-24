#include "GameEntity.hpp"

GameEntity::GameEntity(void) {
	this->setYPos(0);
	this->setXPos(0);
	this->setYMaxPos(0);
	this->setXMaxPos(0);
	this->setName(' ');
}

GameEntity::GameEntity(const GameEntity& copy) {
	*this = copy;
}

GameEntity::~GameEntity(void) {
	return;
}

GameEntity& GameEntity::operator=(const GameEntity& rhs) {
	this->setYPos(rhs.getYPos());
	this->setXPos(rhs.getXPos());
	this->setYMaxPos(rhs.getYMaxPos());
	this->setXMaxPos(rhs.getXMaxPos());
	return *this;
}

/* Getters */

int GameEntity::getYPos(void) const {
	return this->_yPos;
}

int GameEntity::getXPos(void) const {
	return this->_xPos;
}

int GameEntity::getYMaxPos(void) const {
	return this->_yMaxPos;
}

int GameEntity::getXMaxPos(void) const {
	return this->_xMaxPos;
}

char GameEntity::getName(void) const {
	return this->_name;
}

/* Setters */

void GameEntity::setYPos(int yPos) {
	this->_yPos = yPos;
}

void GameEntity::setXPos(int xPos) {
	this->_xPos = xPos;
}

void GameEntity::setYMaxPos(int yMaxPos) {
	this->_yMaxPos = yMaxPos;
}

void GameEntity::setXMaxPos(int xMaxPos) {
	this->_xMaxPos = xMaxPos;
}

void GameEntity::setName(char name) {
	this->_name = name;
}
