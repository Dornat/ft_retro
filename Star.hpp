#ifndef STAR_H
# define STAR_H

#include "GameEntity.hpp"

class Star: public GameEntity {
	public:
		Star(void);
		Star(const Star& copy);
		~Star(void);
		Star& operator=(const Star&);

		void display(WINDOW* win);

		void setYXPosSmart(int yPos);
};

#endif
