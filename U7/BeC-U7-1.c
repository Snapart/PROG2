// Carola Berger
// BeC-U6-1.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <math.h> // BeC_CreateObstaclesPercent -> aufrunden

/***USER-DATEN***/
#define MAT 29
#define V 'C'
#define N 'B'



/***FELDINHALTE***/
#define OBST '#'
#define FREE  '.'

/***VORGABEN***/
#define PROZENT 15.00

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

/***PUNKTESYSTEM***/
#define START_POINTS 10
#define COST 1
#define WIN 2


#define MAX_Y 8   /* Anzahl Felder erste Dimension - Zeilen   */
#define MAX_X 8   /* Anzahl Felder zweite Dimension - Spalten */

// typedef int occu_t[];



/***ROBOT***/
struct BeC_robot
{
        int ypos;
        int xpos;
        int view;
};

typedef struct BeC_robot robot_t;


int start_blickrichtung()
{
        int vec_x = 0;
        int vec_y = 0;


        switch(MAT%4)
        {                                                                        
                case UP:
                        vec_y = -1;
                        return vec_y;
                case LEFT:
                        vec_x = -1;  
                        return vec_x;
                case  DOWN:
                        vec_y = 1;  
                        return vec_y;
                case RIGHT:
                        vec_x = 1;  
                        return vec_x;
        }
} 


/***LEERES FELD***/
void EmptyField(int BeC_GameField[MAX_Y][MAX_X])
{
        for(int y=0; y < MAX_Y; y++) 
        {  
                for(int x=0; x < MAX_X; x++)
                {
                        BeC_GameField[y][x] = FREE;
                }
        }

}


void BeC_CreateObstacles(int obst_num, int BeC_GameField[MAX_Y][MAX_X])
{
        /*Variable in main() uebergeben*/
        printf("Es werden %u Hindernisse eingefügt\n", obst_num);

        int count = 0;
        int y, x;

        /***BEFÜLLEN mit Hindernissen***/
        if (count < (obst_num))
        {
                for(y=rand() % MAX_Y; count < obst_num ; ) 
                {  
                        for(x=rand() % MAX_X; count < obst_num ; x=rand() % MAX_X, y=rand() % MAX_Y)
                        {
                                if (BeC_GameField[y][x] == FREE)
                                {
                                        BeC_GameField[y][x] = OBST;
                                        ++count;
                                }
                                // printf("Obstcount: %d\n", count);
                        }
                }
        }
}


/***Hindernisse nach gewünschtem Prozentsatz***/
void BeC_CreateObstaclesPercent(int BeC_GameField[MAX_Y][MAX_X])
{       
        /*Prozentberechnung zu Anzahl Hindernisse
          int _tmp = MAX_Y;      // MAX_Y(8)
          _tmp *= MAX_X;        // 8 * MAX_X(8) = 64                                                                   
          _tmp *= PROZENT;       // 64 * PROZENT(15)
          _tmp += 50;            // 960 + 50 = 1010
          _tmp /= 100;           // 1010 / 100 = 10,1 -> int _tmp = 10
         */


        int _tmp2 = (int) ceil((MAX_Y*MAX_X)*(PROZENT/100)); // aufrunden -> (8*8) * (15/100)
        // printf("Uebergabe ANZAHL = %d || PROZENT=%.2f\n", _tmp2,(PROZENT/100)); // DEBUG
        BeC_CreateObstacles(_tmp2, BeC_GameField); // übergibt der Funktion den "neuen" Parameter
}  


/***NÄCHSTES FELD***/
/*      Eine lokale Variable übernimmt die aktuelle Position des Roboters.
        Die der aktuellen Position folgende wird anhand der aktuellen Blickrichtung
        des Roboters erkannt.
        Es wird anschließend auf eine Kollision überprüft.
        Je nach Matrikelnummer bewegt sich der Roboter entweder wie bei einem Hinderniss
        oder er bewegt sich rundherum zu der anderen Seite.
        Am Ende wird die sich daraus ergebende nächste Position aus der tmp-Variable entnommen  */

void Preview(robot_t *robot, int *next_x, int *next_y)
{
        int is_border_like_obstical = MAT&1; //entspricht MAT%2 == 1 -> siehe Angabe
        int vec_x = 0, vec_y = 0, _ypos = robot->ypos, _xpos = robot->xpos;

        switch(robot->view)
        {
                case UP:
                        vec_y = -1;
                        break;
                case RIGHT:
                        vec_x =  1;
                        break;
                case DOWN:
                        vec_y =  1;
                        break;
                case LEFT:
                        vec_x = -1;
                        break;
        }

        _ypos += vec_y;
        _xpos += vec_x;
        // printf ("_ypos: %d | xpos: %d\n", _ypos, _xpos);

        if(_xpos < 0 || _ypos < 0 || _xpos >= MAX_X || _ypos >= MAX_Y) // Kontrolliere Wandkollesion
        {
                if(is_border_like_obstical) // links oder rechts
                {
                        // keine bewegung
                        *next_x = robot->xpos;
                        *next_y = robot->ypos;
                        return;
                }
                else // jump
                {
                        // kleiner als null
                        if(_xpos < 0) 
                        {
                                _xpos += MAX_X; // jump
                        }
                        if(_ypos < 0)
                        {
                                _ypos += MAX_Y; // jump
                        }

                        // groesser max
                        _xpos = _xpos % MAX_X; //damit innerhalb vom feld
                        _ypos = _ypos % MAX_Y;
                }
        }

        *next_x = (int) _xpos;
        *next_y = (int) _ypos;
}


/***ROBOTER DREHEN***/
void TurnAround(robot_t *robot) 
{
        int turn_r = MAT>=5; // Angabe = X>=5 -> rechts oder X<5 -> links
        char new_dir = '\0';
        switch(robot->view) // aktuelle Blickrichtung vom Roboter
        {       // je nach Matrikelnummer wird hier entschieden
                case UP:
                        new_dir = turn_r ? RIGHT : LEFT ;
                        break;
                case RIGHT:
                        new_dir = turn_r ? DOWN  : UP   ;
                        break;
                case DOWN:
                        new_dir = turn_r ? LEFT  : RIGHT;
                        break;
                case LEFT:
                        new_dir = turn_r ? UP    : DOWN ;
                        break;
        }
        robot->view = new_dir; // neue Richtung übernehmen
}


/***UM 1 POSITION BEWEGEN***/
void BeC_MoveOneStep (int BeC_GameField[MAX_Y][MAX_X], robot_t *robot, const int win_points, const int cost_points, int* points)
{
        int new_x;
        int new_y;
        int _points = *points;
        Preview(robot, &new_x, &new_y);

        if ( 
                        (BeC_GameField[new_y][new_x] == 35 ) ||               // Wenn der Roboter wo anläuft 0;
                        (new_x == robot->xpos && new_y == robot->ypos) // nicht ueberspringbare wand
           ){
                TurnAround(robot);
                // printf("output: %d\n", BeC_GameField[new_y][new_x]);
                _points += win_points;
                printf("Points: %d\n", _points);
                BeC_GameField[new_y][new_x] = FREE;

        }
        else
        {
                robot->xpos = new_x;
                robot->ypos = new_y;
                // printf("output: %d\n", BeC_GameField[new_y][new_x]);
                _points -= cost_points;
                printf("Points: %d\n", _points);
        }
        *points = _points;
}


void CLEARSCREEN()
{
        printf("\e[1;1H\e[2J"); // https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c/7660837#7660837
}

void BeC_PrintGame (int BeC_GameField[MAX_Y][MAX_X], struct BeC_robot *robot)
{
        CLEARSCREEN();


        // printf("Position im Array\nypos: %d\nxpos: %d\nview: %d\n", robot->ypos,robot->xpos, robot->view);

        for(int y=0; y < MAX_Y; y++) 
        {
                for(int x=0; x < MAX_X; x++) 
                {
                        if (x == robot->xpos && y == robot->ypos)
                        {
                                printf("\tO ");
                        }
                        else
                        {
                                printf("\t%c ",BeC_GameField[y][x]);
                        }
                }

                printf("\n\n");
        }
        printf("\n\n");

}


void BeC_Game(int BeC_GameField[MAX_Y][MAX_X], struct BeC_robot *robot)
{
        char zeile[10024];
        zeile[0] = 0; // damit der str 0 lang ist
        int points = START_POINTS;

                while(strcmp(zeile, "quit\n") != 0 && points >= 1)
        {
                BeC_PrintGame (BeC_GameField, robot);
                printf("Steuerung:\n");
                printf("\tw rauf\n");
                printf("\td rechts\n");
                printf("\ts runter\n");
                printf("\ta links\n");
                printf("\n");

                printf("\nPOINTS: %i\n\n", points);
                //         printf("Mehrfacheingaben möglich, mit enter bestätigen!\n");
                if(fgets(zeile, 1024, stdin) == NULL) // etwas einlesen
                {
                        // konnte nicht lesen
                        return;
                }
                for(char* inp=zeile; *inp != '\0' && points >= 1; ++inp)
                {
                        printf("Eingabe: %c\n", *inp);
                        switch(*inp)
                        {
                                case 'w':
                                        robot->view = UP;
                                        BeC_MoveOneStep (BeC_GameField, robot, WIN, COST, &points);
                                        break;
                                case 'd':
                                        robot->view = RIGHT;
                                        BeC_MoveOneStep (BeC_GameField, robot, WIN, COST, &points);
                                        break;
                                case 's':
                                        robot->view = DOWN;
                                        BeC_MoveOneStep (BeC_GameField, robot, WIN, COST, &points);
                                        break;
                                case 'a':
                                        robot->view = LEFT;
                                        BeC_MoveOneStep (BeC_GameField, robot, WIN, COST, &points);
                                        break;
                        }
                }

        }
}



int main()
{
        /***SPIELFELD***/        

        int BeC_GameField[MAX_Y][MAX_X];     /* [8][8] */
        // int obst_num;
        // int *points;

        time_t t;
        srand((unsigned) time(&t));  



        /***Startpunkt Robo***/
        int posy = ('B'%8)-1;
        int posx = ('C'%8)-1;
        //     printf("posy: %d\nposx: %d\n\n", (posy+1), (posx+1));


        /***Zugriff auf Robo Position***/
        robot_t robby = { posy, posx, 0};


        /***SPIEL zeichnen (Feld, Hürden, Robo)***/
        EmptyField(BeC_GameField);
        BeC_CreateObstaclesPercent(BeC_GameField);


        BeC_Game(BeC_GameField, &robby);
}

