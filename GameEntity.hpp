#ifndef GAMEENTITY_H
# define GAMEENTITY_H

#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>

#define WINDOW_WIDTH 100
#define WINDOW_HEIGHT 40
#define DEFAULT_N 5
#define PLAYER_MISSILES 10
#define ENEMY_MISSILES 10
#define NUMBER_OF_ENEMIES 7
#define NUMBER_OF_STARS 20

class GameEntity {
	public:
		GameEntity(void);
		GameEntity(const GameEntity& copy);
		~GameEntity(void);
		GameEntity& operator=(const GameEntity&);

		void setYPos(int yPos);
		void setXPos(int xPos);
		void setYMaxPos(int yMaxPos);
		void setXMaxPos(int xMaxPos);
		void setName(char name);

		int getYPos(void) const;
		int getXPos(void) const;
		int getYMaxPos(void) const;
		int getXMaxPos(void) const;
		char getName(void) const;

	protected:
		int _yPos;
		int _xPos;
		int _yMaxPos;
		int _xMaxPos;
		char _name;
};

#endif
