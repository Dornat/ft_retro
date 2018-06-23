#ifndef STAR_SPACE_H
# define STAR_SPACE_H

#include "Star.hpp"

class StarSpace {
	public:
		Star* space;

		StarSpace(void);
		StarSpace(const StarSpace& copy);
		~StarSpace(void);
		StarSpace& operator=(const StarSpace&);
		StarSpace(int n);

		int getN(void) const;

		void setN(int n);

	private:
		int _n;
};

#endif
