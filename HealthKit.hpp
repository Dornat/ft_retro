#ifndef HEALTH_KIT_H
# define HEALTH_KIT_H

#include "GameEntity.hpp"

class HealthKit: public GameEntity {
	public:
		HealthKit(void);
		HealthKit(const HealthKit& copy);
		~HealthKit(void);
		HealthKit& operator=(const HealthKit&);

		void display(WINDOW* win);

		void setYXPosSmart(int yPos);
};

#endif
