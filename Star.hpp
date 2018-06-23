#ifndef STAR_H
# define STAR_H

#include "GameEntity.hpp"

class Star {
	public:
		Star(void);
		Star(const Star& copy);
		~Star(void);
		Star& operator=(const Star&);

		void setYPos(int yPos);
		void setXPos(int xPos);
		void setYXPosSmart(int yPos);

		int getYPos(void) const;
		int getXPos(void) const;

	private:
		int _yPos;
		int _xPos;
};

#endif
