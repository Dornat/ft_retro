#ifndef PLAYER_H
# define PLAYER_H

#include "GameEntity.hpp"
#include "Missile.hpp"
#include "Enemy.hpp"

class Player {
	public:
		Player(void);
		Player(const Player& copy);
		~Player(void);
		Player& operator=(const Player&);
		Player(WINDOW* win,
				int y,
				int x,
				char name,
				Missile* missiles);

		void move(int key);
		void display(void);
		void shoot(void);
		void missileLauncher(int missileLauncher);
		void hitEnemy(Enemy &enemy);

		int getYPos(void) const;
		int getXPos(void) const;
		int getYMaxPos(void) const;
		int getXMaxPos(void) const;
		char getName(void) const;
		WINDOW* getWin(void) const;
		Missile* getMissiles(void) const;
		float getHealth(void) const;
		float getScore(void) const;

		void setYPos(int yPos);
		void setXPos(int xPos);
		void setYMaxPos(int yMaxPos);
		void setXMaxPos(int xMaxPos);
		void setName(char name);
		void setWin(WINDOW* win);
		void setMissiles(Missile* missiles);
		void setHealth(float health);
		void setScore(float score);


	private:
		int _yPos;
		int _xPos;
		int _yMaxPos;
		int _xMaxPos;
		char _name;
		WINDOW* _win;
		Missile* _missiles;
		float _health;
		float _score;

		void _moveUp(void);
		void _moveDown(void);
		void _moveLeft(void);
		void _moveRight(void);
};

#endif
