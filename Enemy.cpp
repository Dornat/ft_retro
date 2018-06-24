#include "Enemy.hpp"

Enemy::Enemy(void) {
	char names[] = {
		'Y', 'X', 'Z'
	};
	this->setYPos(-42 + rand() % 30);
	this->setXPos(rand() % (WINDOW_WIDTH - 2) + 1);
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

void Enemy::display(WINDOW* win) {
	mvwaddch(win, this->getYPos(), this->getXPos(), ' ');
	this->setYXPosSmart(this->getYPos() + 1);
	wattron(win, COLOR_PAIR(2));
	mvwaddch(win, this->getYPos(), this->getXPos(), this->getName());
	wattroff(win, COLOR_PAIR(2));
}

void Enemy::missileLauncher(int random, Missile* missiles, WINDOW* win) {
	for (int i = 0; i < ENEMY_MISSILES; i++) {
		if (missiles[i].getXPos() > 0 ||
			missiles[i].getYPos() > 0) {
			if (random % 10 == 0) {
				missiles[i].displayEnemy(win);
			}
		}
	}
}

void Enemy::shoot(Missile* missiles) {
	for (int i = 0; i < PLAYER_MISSILES; i++) {
		if (
			missiles[i].getYPos() < 0) {
			missiles[i].setYPos(this->getYPos() + 1);
			missiles[i].setXPos(this->getXPos());
			break;
		}
	}
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
