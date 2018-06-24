#ifndef MISSILE_H
# define MISSILE_H

#include "GameEntity.hpp"

class Missile: public GameEntity {
	public:
		Missile(void);
		Missile(const Missile& copy);
		~Missile(void);
		Missile& operator=(const Missile&);

		void displayPlayer(WINDOW* win);
		void displayEnemy(WINDOW* win);

	private:
		void _setYXPosSmartPlayer(int yPos);
		void _setYXPosSmartEnemy(int yPos);
};

#endif
