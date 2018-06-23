#ifndef PLAYER_H
# define PLAYER_H

#include "GameEntity.hpp"

class Player {
	public:
		Player(void);
		Player(const Player& copy);
		~Player(void);
		Player& operator=(const Player&);
		Player(WINDOW* win, int y, int x, char name);

		void move(int key);
		void display(void);

		int getYPos(void) const;
		int getXPos(void) const;
		int getYMaxPos(void) const;
		int getXMaxPos(void) const;
		char getName(void) const;
		WINDOW* getWin(void) const;

		void setYPos(int yPos);
		void setXPos(int xPos);
		void setYMaxPos(int yMaxPos);
		void setXMaxPos(int xMaxPos);
		void setName(char name);
		void setWin(WINDOW* win);


	private:
		int _yPos;
		int _xPos;
		int _yMaxPos;
		int _xMaxPos;
		char _name;
		WINDOW* _win;

		void _moveUp(void);
		void _moveDown(void);
		void _moveLeft(void);
		void _moveRight(void);
		void _shoot(void);
};

#endif
