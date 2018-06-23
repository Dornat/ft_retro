#include "GameEntity.hpp"
#include "Player.hpp"
#include "StarSpace.hpp"
#include "Star.hpp"
#include "Enemy.hpp"

#define DELAY 10000



int		main(void) {
	/* int y = 0; */
	/* int x = 0; */
	/* int max_y = 0; */
	/* int max_x = 0; */
	/* int next_x = 0; */
	/* int direction = 1; */

	/* int c; */

	/* initscr(); */

	/* noecho(); */
	/* curs_set(FALSE); */

	/* nodelay(stdscr, TRUE); */

	/* while ((c = getch()) != 27) { */
	/* 	getmaxyx(stdscr, max_y, max_x); */
	/* 	clear(); */
	/* 	mvprintw(y, x, "@"); */
	/* 	refresh(); */


	/* 	next_x = x + direction; */

	/* 	if (next_x >= max_x || next_x < 0) { */
	/* 		direction *= -1; */
	/* 	} else { */
	/* 		x += direction; */
	/* 	} */
	/* } */

	/* refresh(); */

	/* sleep(1); */

	/* endwin(); */
	int c;
	int yMax;
	int xMax;


	/* Missile */

	/* int missY = 1; */
	/* int missX = 1; */



	/* End Missile */

	initscr();

	noecho();
	curs_set(false);
	nodelay(stdscr, true);
	/* raw(); */

	srand(time(0));
	getmaxyx(stdscr, yMax, xMax);

	WINDOW* testWin = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, (yMax / 4), 30);
	box(testWin, 0, 0);
	refresh();
	wrefresh(testWin);

	nodelay(testWin, true);
	Star* spaceOfStars = new Star[20];
	Enemy* someEnemies = new Enemy[7];

	Player player(testWin, WINDOW_HEIGHT - 2, WINDOW_WIDTH / 2, '@');


	int j = 0;

	player.display();
	while ((c = wgetch(testWin)) != 'q') {

		/* wclear(testWin); */
		/* mvwaddch(testWin, missY, missX, ' '); */
		/* missY += 1; */
		/* mvwaddch(testWin, missY, missX, 'M'); */
		/* mvwaddch(testWin, testStar.getYPos(), testStar.getXPos(), ' '); */
		/* testStar.setYXPosSmart(testStar.getYPos() + 1); */
		/* mvwaddch(testWin, testStar.getYPos(), testStar.getXPos(), '.'); */
		for (int i = 0; i < 20; i++) {
			if (j % 20 == 0) {
				mvwaddch(testWin, spaceOfStars[i].getYPos(), spaceOfStars[i].getXPos(), ' ');
				spaceOfStars[i].setYXPosSmart(spaceOfStars[i].getYPos() + 1);
				mvwaddch(testWin, spaceOfStars[i].getYPos(), spaceOfStars[i].getXPos(), '.');
			}
		}

		for (int i = 0; i < 7; i++) {
			if (j % 30 == 0) {
				mvwaddch(testWin, someEnemies[i].getYPos(), someEnemies[i].getXPos(), ' ');
				someEnemies[i].setYXPosSmart(someEnemies[i].getYPos() + 1);
				mvwaddch(testWin, someEnemies[i].getYPos(), someEnemies[i].getXPos(), someEnemies[i].getName());
			}
		}

		player.move(c);
		player.display();
		wrefresh(testWin);
		/* if (missY == 18) { */
		/* 	mvwaddch(testWin, missY, missX, ' '); */
		/* 	missY = 1; */
		/* } */
		usleep(DELAY);
		/* timeout(0); */
		j++;
	}

	endwin();
	return 0;
}
