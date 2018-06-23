#ifndef ENEMY_H
# define ENEMY_H

#include "GameEntity.hpp"

class Enemy {
	public:
		Enemy(void);
		Enemy(const Enemy& copy);
		~Enemy(void);
		Enemy& operator=(const Enemy&);

		void setYXPosSmart(int yPos);
		void setYPos(int yPos);
		void setXPos(int xPos);
		void setSpeed(int speed);
		void setName(char name);

		int getYPos(void) const;
		int getXPos(void) const;
		int getSpeed(void) const;
		char getName(void) const;

	private:
		int _yPos;
		int _xPos;
		int _speed;
		char _name;
};

#endif
