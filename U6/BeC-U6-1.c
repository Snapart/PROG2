// Carola Berger - mit Unterstützung von Clemens Jung, bei der besseren Lösung der Blickrichtung, dem Clear und allgemeinen Best Practises; zusätzlich wurden einige Herangehensweisen im Lab disskutiert
// BeC-U6-1.c

#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

// PERSONALISIERUNG
#define MAT 29
#define V 'C'
#define N 'B'

//FELD
#define WIDTH  8
#define HEIGHT 8

// PRINT SYMBOLS - Abwandlung von der Angabe, da Blickrichtung nach der Zeit unübersichtlich wurde
#define UP '^'
#define RIGHT '>'
#define DOWN 'v'
#define LEFT '<'
#define OBSTACLE '#'
#define SPACE  '.'



/***ROBOTER***/
struct BeC_robot
{
	unsigned x;
	unsigned y;
	char blickrichtung; // < ^ > v
};
typedef struct BeC_robot BeC_robot_t;

char start_blickrichtung()
{
	switch(MAT%4)
	{
		case 0: return UP;
		case 1: return LEFT;
		case 2: return DOWN;
		case 3: return RIGHT;
	}
	return '\0'; // IMPOSSIBLE
}

/***HINDERNISSE***/
void BeC_CreateObstacles(bool env[HEIGHT][WIDTH], unsigned num_obstacles) // Feld & Anzahl Hindernisse
{
	for(unsigned y = 0; y < HEIGHT; ++y)
	{
		for(unsigned x = 0; x < WIDTH; ++x)
		{
			env[y][x] = true; // Zustand "frei" speicherm
		}
	}

	printf("Es werden %u Hindernisse eingefügt\n", num_obstacles);
	int rnd_x, rnd_y;
	for(unsigned i = 0; i < num_obstacles; ++i) // bis gewünschte Anzahl ereicht
	{
		do
                {
			rnd_x = rand() % WIDTH; // random
			rnd_y = rand() % HEIGHT; // random
		} while ( ! env[rnd_y][rnd_x] ); // wenn schon belegt

		env[rnd_y][rnd_x] = false; // Zustand "besetzt" speichern
	}
}

/***Hindernisse nach gewünschtem Prozentsatz***/
void BeC_CreateObstaclesPercent(bool env[HEIGHT][WIDTH]) // Feld
{
	unsigned percent = 15; // siehe Angabe
	unsigned long long _tmp = HEIGHT;
	_tmp *= WIDTH;
	_tmp *= percent;
	_tmp += 50; // runden in int division
	_tmp /= 100;
	BeC_CreateObstacles(env, (unsigned)_tmp); // führt die Funktion aus mit dem "neuen" Parameter der Hindernissanzahl
}

/***Nächstes Feld***/
void CalcNextCoord(BeC_robot_t* robot, unsigned* x, unsigned* y) // Roboter, x, y
{
	bool is_wall_obstacle = MAT&1; //entspricht MAT%2 == 1 -> siehe Angabe
	int vec_x = 0;
	int vec_y = 0;
	switch(robot->blickrichtung)
	{
		case UP:    vec_y = -1; break;
		case RIGHT: vec_x =  1; break;
		case DOWN:  vec_y =  1; break;
		case LEFT:  vec_x = -1; break;
	}
	int _x = (int)robot->x; // überimmt Position
	int _y = (int)robot->y;

	_x += vec_x; // berechnet nächstes Feld durch vorherigen case und Achse
	_y += vec_y;

	if(_x < 0 || _y < 0 || _x >= WIDTH || _y >= HEIGHT) // Kontrolliere Wandkollesion
	{
		if(is_wall_obstacle) // links oder rechts
		{
			
				*x = robot->x;
				*y = robot->y;
				return;
		}
		else // siehe Angabe
		{
			if(_x < 0) _x += WIDTH; // jump
			_x = _x % WIDTH;
			if(_y < 0) _y += HEIGHT; // jump
			_y = _y % HEIGHT;
		}
	}

	*x = (unsigned) _x;
	*y = (unsigned) _y;
}

void TurnRobot(BeC_robot_t* robot) // Blickrichtung (hier Abwandlung von der Angabe) 
{
	bool turn_right = MAT>=5; // siehe ANgabe
	char new_dir = '\0';
	switch(robot->blickrichtung) // aktuelle Blickrichtung vom Roboter
	{       // je nach Matrikelnummer wird hier entschieden
		case UP: new_dir    = turn_right ? RIGHT : LEFT ; break;
		case RIGHT: new_dir = turn_right ? DOWN  : UP   ; break;
		case DOWN: new_dir  = turn_right ? LEFT  : RIGHT; break;
		case LEFT: new_dir  = turn_right ? UP    : DOWN ; break;
	}
	robot->blickrichtung = new_dir; // neue Richtung übernehmen
}

void BeC_MoveOneStep(bool env[HEIGHT][WIDTH], BeC_robot_t* robot) // Feld, Roboter
{
	unsigned new_x;
	unsigned new_y;
	CalcNextCoord(robot, &new_x, &new_y);

	if ( 
		( ! env[new_y][new_x] ) ||               // Obstacle
		(new_x == robot->x && new_y == robot->y) // nicht ueberspringbare wand
	){
		TurnRobot(robot);
	}
	else
	{
		robot->x = new_x;
		robot->y = new_y;
	}
}

void CLEARSCREEN() // Internetrecherche und Unterstützung von Clemens Jung
{
	printf("\e[1;1H\e[2J"); // https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c/7660837#7660837
}

void BeC_PrintGame(bool env[HEIGHT][WIDTH], BeC_robot_t* robot) // Feld, Roboter
{
	CLEARSCREEN(); // Funktion um den Terminal aufzuräumen und Bewegung sichtbar zu machen -> Achtung! Auch Warnungen werden weggeräumt
	char c;
        /***FELD MALEN***/
	for(unsigned y = 0; y < HEIGHT; ++y)
	{
		for(unsigned x = 0; x < WIDTH; ++x)
		{
			if (robot->x == x && robot->y == y) // Position Roboter überprüfen
			{
				c = robot->blickrichtung; // gibt Symbol aus
			}
			else if(env[y][x])
			{
				c = SPACE;
			}
			else
			{
				c = OBSTACLE;
			}
			printf("%c", c); // je nachdem was zutreffend -> Ausgabe
		}
		printf("\n");
	}
}

void BeC_StepByStep(bool env[HEIGHT][WIDTH], BeC_robot_t* robot) // Feld, Roboter
{
	char* end_str = "quit\n"; // Exit-Möglichkeit
	const int LINEBUFFSZ = 1024; // Größe
	char line_buff[LINEBUFFSZ]; // String in "Größe"
	memset(line_buff, '\0', LINEBUFFSZ); // kopiert das Zeichen '\0' in die ersten 'LILNEBUFFSZ' Zeichen der Zeichenkette, auf die das Argument 'line_buff' zeigt.
	while(strcmp(line_buff, end_str) != 0) // vergleiche
	{
		BeC_PrintGame(env, robot); // Spielfeld ausgeben
		if(fgets(line_buff, LINEBUFFSZ, stdin) == NULL) return;
		BeC_MoveOneStep(env, robot); // Bewegungsregeln
	}
}

void BeC_N_Steps(bool env[HEIGHT][WIDTH], BeC_robot_t* robot)
{
	const int LINEBUFFSZ = 100;
	char line_buff[LINEBUFFSZ];

	long long steps = -1;
	while(steps < 0) // Counter
	{
		printf("Wie viele Schritte sollen simulierrt werden? ");
		if(fgets(line_buff, LINEBUFFSZ, stdin) == NULL) return;
		if(sscanf(line_buff, " %llu", &steps) != 1) // Fehlerbehandlung
		{
			fprintf(stderr, "Bitte eine Zahl eingeben!\n");
			steps = -1;
		}
	}
	for(;steps >= 0; --steps) // Spiel durchlaufen bzw. Schritte laufen und Feld zeichnen lassen
	{
		BeC_MoveOneStep(env, robot);
		BeC_PrintGame(env, robot);
		sleep(1); // damit man sieht, wie sich Robbi bewegt
	}
}

int main()
{
	srand((unsigned int) time(NULL)); // random mit Zeit seeden, für möglichst viel Zufälligkeit

	BeC_robot_t robbi; // Roboter Struct
	robbi.x = (unsigned) (V%WIDTH); // Startpos
	robbi.y = (unsigned) (N%HEIGHT); //Startpos
	robbi.blickrichtung = start_blickrichtung(); //Startblick

	// init feld
	bool env[HEIGHT][WIDTH]; // loakle Variable für Spielfeld
	BeC_CreateObstaclesPercent(env);
	BeC_PrintGame(env, &robbi);


	char option = '\0';
	int LINEBUFFSZ = 10;
	char line_buff[LINEBUFFSZ];
	while(option == '\0')
	{
		printf("\e[1mE\e[0minzelschrittmodus oder \e[1ma\e[0muf einmal? "); // Hübschere Eingabe von Userinput -> Tipp von Clemens Jung
		if(fgets(line_buff, LINEBUFFSZ, stdin) == NULL)
		{
			return 0;
		}
		option = (char) tolower(*line_buff);
		if (option != 'e' && option != 'a' && option != '\n')
		{
			fprintf(stderr, "Bitte e oder a eingeben! (es wurde %c eingegeben)\n", option); // Fehlerhafter Input
			option = '\0';
		}
	}
	if (option == 'e')
	{
		BeC_StepByStep(env, &robbi); // Programm wird gestartet und Robbi auf den Weg geschickt
	}
	else
	{
		BeC_N_Steps(env, &robbi); // Programm wird gestartet und Robbi auf den Weg geschickt 
	}
	return 0;
}
