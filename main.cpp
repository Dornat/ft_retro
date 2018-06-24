#include "GameEntity.hpp"
#include "Player.hpp"
#include "Star.hpp"
#include "Enemy.hpp"
#include "Missile.hpp"

#define DELAY 10000



int		main(void) {

	int c;
	int yMax;
	int xMax;




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

	WINDOW* testWin = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT / 3, WINDOW_WIDTH / 3);
	WINDOW * score = newwin (WINDOW_HEIGHT / 4, WINDOW_WIDTH, WINDOW_HEIGHT / 16, WINDOW_WIDTH / 3);
	size_t initTime = time(0);
	box(testWin, 0, 0);
	box(score, 1, 0);
	refresh();
	wrefresh(testWin);
	wrefresh(score);

	nodelay(testWin, true);

	Star* spaceOfStars = new Star[NUMBER_OF_STARS];
	Enemy* someEnemies = new Enemy[NUMBER_OF_ENEMIES];
	Missile* playerMissiles = new Missile[PLAYER_MISSILES];
	Missile* enemyMissiles = new Missile[ENEMY_MISSILES];

	Player player(testWin, WINDOW_HEIGHT - 2, WINDOW_WIDTH / 2, '@', playerMissiles);


	int j = 0;
	int i;
	player.display();
	int flag = 0;

	while ((c = wgetch(testWin)) != 'q' && flag == 0 && player.getHealth() > 0) {
		for (i = 0; i < 20; i++) {
			if (j % 20 == 0) {
				spaceOfStars[i].display(testWin);
			}
		}

		for ( i = 0; i < NUMBER_OF_ENEMIES; i++) {
			if (j % 30 == 0 && someEnemies[i].getName() == 'Z') {
				if (someEnemies[i].getYPos() > WINDOW_HEIGHT - 3)
					player.setHealth(player.getHealth() - 10);

					someEnemies[i].display(testWin);
			}
			if (j % 50 == 0) 
				someEnemies[i].shoot(enemyMissiles);
			if (player.getXPos() == someEnemies[i].getXPos() &&
				player.getYPos() == someEnemies[i].getYPos())
			{
				flag = 1;
			}
			if (player.getXPos() == enemyMissiles[i].getXPos() &&
				player.getYPos() == enemyMissiles[i].getYPos())
				{
					player.setHealth(player.getHealth() - 1);
				}
				player.hitEnemy(someEnemies[i]);
		}
		someEnemies[i].missileLauncher(j, enemyMissiles, testWin);
		

		player.move(c);
		player.display();
		player.missileLauncher(j);
		size_t curTime = time(0) - initTime;
		mvwprintw(score, 2, 4, "Time: %ds", curTime);
		mvwprintw(score, 4, 4, "Health: %3.0f%%", player.getHealth());
		mvwprintw(score, 6, 4, "Score: %3.0f", player.getScore());
		wrefresh(testWin);
		wrefresh(score);
		usleep(DELAY);
		box(testWin, 0, 0);
		j++;
	}

	delete [] spaceOfStars;
	delete [] someEnemies;
	delete [] playerMissiles;
	delete [] enemyMissiles;
	noecho();
	mvwprintw(testWin, WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2 - 5, "Game Over");
	if (c != 'q') {
			while((c = wgetch(testWin)) != 'q');
	}

	endwin();
	
	return 0;
}
