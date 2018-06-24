#include "GameEntity.hpp"
#include "Player.hpp"
#include "Star.hpp"
#include "Enemy.hpp"
#include "Missile.hpp"

#define DELAY 10000

void printWelcomeScreen(WINDOW* mainWin) {
	wattron(mainWin, COLOR_PAIR(3));
	mvwprintw(mainWin, WINDOW_HEIGHT / 5, WINDOW_WIDTH / 4 + 6, "__        __   _");
	mvwprintw(mainWin, WINDOW_HEIGHT / 5  + 1, WINDOW_WIDTH / 4 + 6, "\\ \\      / /__| | ___ ___  _ __ ___   ___");
	mvwprintw(mainWin, WINDOW_HEIGHT / 5  + 2, WINDOW_WIDTH / 4 + 6, " \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\");
	mvwprintw(mainWin, WINDOW_HEIGHT / 5  + 3, WINDOW_WIDTH / 4 + 6, "  \\ V  V /  __/ | (_| (_) | | | | | |  __/");
	mvwprintw(mainWin, WINDOW_HEIGHT / 5  + 4, WINDOW_WIDTH / 4 + 6, "   \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|");
	wattroff(mainWin, COLOR_PAIR(3));
	mvwprintw(mainWin, WINDOW_HEIGHT / 5 + 6, WINDOW_WIDTH / 2 - 2, "to ft_retro");
	mvwprintw(mainWin, WINDOW_HEIGHT / 5 + 7, WINDOW_WIDTH / 3 + 6, "made by dpolosuk and sbratche");
	mvwprintw(mainWin, WINDOW_HEIGHT - 10, WINDOW_WIDTH / 2 - 10, "Controls:");
	mvwprintw(mainWin, WINDOW_HEIGHT - 9, WINDOW_WIDTH / 2 - 10, "Up - key up or 'K'");
	mvwprintw(mainWin, WINDOW_HEIGHT - 8, WINDOW_WIDTH / 2 - 10, "Down - key down or 'J'");
	mvwprintw(mainWin, WINDOW_HEIGHT - 7, WINDOW_WIDTH / 2 - 10, "Left - key left or 'H'");
	mvwprintw(mainWin, WINDOW_HEIGHT - 6, WINDOW_WIDTH / 2 - 10, "Right - key right or 'L'");
	mvwprintw(mainWin, WINDOW_HEIGHT - 5, WINDOW_WIDTH / 2 - 10, "Shoot - 'X'");
	mvwprintw(mainWin, WINDOW_HEIGHT - 4, WINDOW_WIDTH / 2 - 10, "Exit - 'Q'");
	wattron(mainWin, A_BOLD);
	wattron(mainWin, A_BLINK);
	mvwprintw(mainWin, WINDOW_HEIGHT / 5 + 13, WINDOW_WIDTH / 3 + 8, "Press 'Space' to start");
	wattroff(mainWin, A_BOLD);
	wattroff(mainWin, A_BLINK);
}

int		main(void) {
	int c;
	int yMax;
	int xMax;
	int randomSeed = 0;
	int i;
	int collision = 0;

	initscr();

	noecho();
	curs_set(false);
	nodelay(stdscr, true);

	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_WHITE, COLOR_BLACK);
	srand(time(0));
	getmaxyx(stdscr, yMax, xMax);

	WINDOW* mainWin = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, WINDOW_HEIGHT / 3, WINDOW_WIDTH / 3);
	WINDOW * score = newwin (WINDOW_HEIGHT / 4, WINDOW_WIDTH, WINDOW_HEIGHT / 16, WINDOW_WIDTH / 3);
	box(mainWin, 0, 0);

	refresh();
	wrefresh(mainWin);
	wrefresh(score);


	nodelay(mainWin, true);

	while ((c = wgetch(mainWin)) != 32) {
		printWelcomeScreen(mainWin);
		if (c == 'q') {
			endwin();
			return 0;
		}
	}

	size_t initTime = time(0);

	wclear(mainWin);
	box(score, 1, 0);
	Star* spaceOfStars = new Star[NUMBER_OF_STARS];
	Enemy* someEnemies = new Enemy[NUMBER_OF_ENEMIES];
	Missile* playerMissiles = new Missile[PLAYER_MISSILES];
	Missile* enemyMissiles = new Missile[ENEMY_MISSILES];
	HealthKit healthKit;

	Player player(mainWin, WINDOW_HEIGHT - 2, WINDOW_WIDTH / 2, '@', playerMissiles);

	player.display();

	while ((c = wgetch(mainWin)) != 'q' && !collision && player.getHealth() > 0) {
		for (i = 0; i < 20; i++) {
			if (randomSeed % 20 == 0) {
				spaceOfStars[i].display(mainWin);
			}
		}

		for (i = 0; i < NUMBER_OF_ENEMIES; i++) {
			if (randomSeed % 30 == 0) {
				if (someEnemies[i].getYPos() > WINDOW_HEIGHT - 3) {
					player.setHealth(player.getHealth() - 10);
				}
				someEnemies[i].display(mainWin);
			}
			if (randomSeed % 50 == 0) {
				someEnemies[i].shoot(enemyMissiles);
			}
			if (player.enemyCollision(someEnemies[i])) {
				collision = 1;
			}
			player.hitEnemy(someEnemies[i]);
			player.hitByEnemy(enemyMissiles[i]);
		}
		someEnemies[i].missileLauncher(randomSeed, enemyMissiles, mainWin);

		player.move(c);
		player.display();
		player.missileLauncher(randomSeed);
		player.spawnHealthKit(healthKit);
		player.consumeHealthKit(healthKit);
		if (randomSeed % 10 == 0) {
			healthKit.display(mainWin);
		}
		mvwprintw(score, 2, 4, "Time: %02d:%02d", (time(0) - initTime) / 60, (time(0) - initTime) % 60);
		mvwprintw(score, 4, 4, "Health: %3.0f%%", player.getHealth());
		mvwprintw(score, 6, 4, "Score: %3.0f", player.getScore());
		wrefresh(mainWin);
		wrefresh(score);
		usleep(DELAY);
		box(mainWin, 0, 0);
		randomSeed++;
	}

	delete [] spaceOfStars;
	delete [] someEnemies;
	delete [] playerMissiles;
	delete [] enemyMissiles;
	noecho();
	mvwprintw(mainWin, WINDOW_HEIGHT / 2, WINDOW_WIDTH / 2 - 5, "Game Over");
	if (c != 'q') {
		while((c = wgetch(mainWin)) != 'q');
	}
	endwin();
	return 0;
}
