#include "GameEntity.hpp"
#include "Player.hpp"
#include "StarSpace.hpp"
#include "Star.hpp"
#include "Enemy.hpp"
#include "Missile.hpp"

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

	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	srand(time(0));
	getmaxyx(stdscr, yMax, xMax);

	WINDOW* testWin = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, (yMax / 4), 30);
	box(testWin, 0, 0);
	refresh();
	wrefresh(testWin);

	nodelay(testWin, true);

	Star* spaceOfStars = new Star[NUMBER_OF_STARS];
	Enemy* someEnemies = new Enemy[NUMBER_OF_ENEMIES];
	Missile* playerMissiles = new Missile[PLAYER_MISSILES];
	Missile* enemyMissiles = new Missile[ENEMY_MISSILES];

	Player player(testWin, WINDOW_HEIGHT - 2, WINDOW_WIDTH / 2, '@', playerMissiles);


	int j = 0;

	player.display();
	while ((c = wgetch(testWin)) != 'q') {
		for (int i = 0; i < 20; i++) {
			if (j % 20 == 0) {
				spaceOfStars[i].display(testWin);
			}
		}

		for (int i = 0; i < NUMBER_OF_ENEMIES; i++) {
			if (j % 30 == 0) {
				someEnemies[i].display(testWin);
			}
			someEnemies[i].shoot(enemyMissiles);
			someEnemies[i].missileLauncher(j, enemyMissiles, testWin);
		}

		player.move(c);
		player.display();
		player.missileLauncher(j);
		wrefresh(testWin);
		usleep(DELAY);
		box(testWin, 0, 0);
		j++;
	}

	delete [] spaceOfStars;
	delete [] someEnemies;
	delete [] playerMissiles;
	endwin();
	return 0;
}
