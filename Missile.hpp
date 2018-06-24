#ifndef MISSILE_H
# define MISSILE_H

#include "GameEntity.hpp"

class Missile {
	public:
		Missile(void);
		Missile(const Missile& copy);
		~Missile(void);
		Missile& operator=(const Missile&);

		void displayPlayer(WINDOW* win);
		void displayEnemy(WINDOW* win);

		void setYPos(int yPos);
		void setXPos(int xPos);

		int getYPos(void) const;
		int getXPos(void) const;

	private:
		int _yPos;
		int _xPos;

		void _setYXPosSmartPlayer(int yPos);
		void _setYXPosSmartEnemy(int yPos);
};

#endif
