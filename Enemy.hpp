#ifndef ENEMY_H
# define ENEMY_H

#include "GameEntity.hpp"
#include "Missile.hpp"

class Enemy: public GameEntity {
	public:
		Enemy(void);
		Enemy(const Enemy& copy);
		~Enemy(void);
		Enemy& operator=(const Enemy&);

		void display(WINDOW* win);
		void missileLauncher(int random, Missile* missiles, WINDOW* win);
		void shoot(Missile* missiles);

		void setYXPosSmart(int yPos);
};

#endif
