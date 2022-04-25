// Carola Berger
// BeC-U6-1.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <math.h> // BeC_CreateObstaclesPercent -> aufrunden

/***USER-DATEN***/
#define MAT 29
#define V 'C'
#define N 'B'



/***FELDINHALTE***/
// emoji brauchen mehr als 1 char, darum string. 
// Globale strings zum einfachen vergleich auf deren pointer addresse
char* OBST="🍖";
char* FREE="🌱";
char* TOT="🦴";
char* ROBOT="🐕";
char* DROP="💩";
char* TRACE="🐾";

/***VORGABEN***/
#define PROZENT 15.00
#define OBST_NUM (int)ceil((MAX_Y*MAX_X)*(PROZENT/100))

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
void EmptyField(char* BeC_GameField[MAX_Y][MAX_X])
{
        for(int y=0; y < MAX_Y; y++) 
        {  
                for(int x=0; x < MAX_X; x++)
                {
                        BeC_GameField[y][x] = FREE;
                }
        }

}


void BeC_CreateObstacles(int obst_num, char* BeC_GameField[MAX_Y][MAX_X])
{
        /*Variable in main() uebergeben*/
        printf("Es werden %u Hindernisse eingefügt\n", obst_num);

        int count = 0;
        int y, x;

        /***BEFÜLLEN mit Hindernissen***/
        if (count < (obst_num))
        {
                for(
                        x=rand() % MAX_X, y=rand() % MAX_Y; 
                        count < obst_num; 
                        x=rand() % MAX_X, y=rand() % MAX_Y
                ) // in while-Schleife umwandeln
                {
                        if (BeC_GameField[y][x] == FREE)
                        {
                                BeC_GameField[y][x] = OBST;
                                ++count;
                        }
                }
        }
}




/***NÄCHSTES FELD***/
/*      Eine lokale Variable übernimmt die aktuelle Position des Roboters.
        Die der aktuellen Position folgende wird anhand der aktuellen Blickrichtung
        des Roboters erkannt.
        Es wird anschließend auf eine Kollision überprüft.
        Am Ende wird die sich daraus ergebende nächste Position aus der tmp-Variable entnommen  */

void Preview(robot_t *robot, int *next_x, int *next_y)
{
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

        if(_xpos < 0 || _ypos < 0 || _xpos >= MAX_X || _ypos >= MAX_Y) // Kontrolliere Wandkollesion
        {
                // keine bewegung
                *next_x = robot->xpos;
                *next_y = robot->ypos;
                return;
        }
        else 
        {

                *next_y = (_ypos);
                *next_x = (_xpos);
        }
}

/***UM 1 POSITION BEWEGEN***/
void BeC_MoveOneStep (
                        char* BeC_GameField[MAX_Y][MAX_X],
                        robot_t *robot,
                        const int win_points, const int cost_points, int* points,
                        int* obst_num)
{
        int new_x = robot->xpos;
        int new_y = robot->ypos;
        int _points = *points;
        int _num = *obst_num;
        
        Preview(robot, &new_x, &new_y);

        if (BeC_GameField[new_y][new_x] == OBST ) // nicht ueberspringbare wand
        {
                // printf("output: %d\n", BeC_GameField[new_y][new_x]);

                _points += win_points;
                printf("\a");
                _num -= 1;
                BeC_GameField[new_y][new_x]  = TOT;

        }
        else
        {
                // printf("output: %d\n", BeC_GameField[new_y][new_x]);
                if(new_x != robot->xpos || new_y != robot->ypos)
                {
                        _points -= cost_points;
                }
        }
        robot->xpos = new_x;
        robot->ypos = new_y;

        *points = _points;
        *obst_num = _num;
}


void CLEARSCREEN() // eCampus-Alternative verwenden
{
        printf("\e[1;1H\e[2J"); // https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c/7660837#7660837
}

void BeC_PrintGame (char* BeC_GameField[MAX_Y][MAX_X], struct BeC_robot *robot)
{
        CLEARSCREEN();


        // printf("Position im Array\nypos: %d\nxpos: %d\nview: %d\n", robot->ypos,robot->xpos, robot->view);

        for(int y=0; y < MAX_Y; y++) 
        {
                for(int x=0; x < MAX_X; x++) 
                {
                        if (x == robot->xpos && y == robot->ypos)
                        {
                                printf("\t%s ", ROBOT);
                        }
                        else
                        {
                                printf("\t%s ",BeC_GameField[y][x]);
                        }
                }

                printf("\n\n");
        }
        printf("\n\n");

}


void BeC_Game(char* BeC_GameField[MAX_Y][MAX_X], struct BeC_robot *robot)
{
        int points = START_POINTS;
        int num = OBST_NUM;

        while(points >= 1 && num > 0)
        {
                if(BeC_GameField[robot->ypos][robot->xpos] == FREE)
                {
                        BeC_GameField[robot->ypos][robot->xpos] = TRACE;
                }
                BeC_PrintGame (BeC_GameField, robot);
                printf("Steuerung:\n");
                printf("\tw | ^ rauf\n");
                printf("\td | > rechts\n");
                printf("\ts | v runter\n");
                printf("\ta | < links\n");
                printf("\n");
                // printf("Hindernisse %d\n", num);

                printf("\nPOINTS: %i\n%s übrig: %i\n", points, OBST, num);
                //         printf("Mehrfacheingaben möglich, mit enter bestätigen!\n");
                // printf("Eingabe: %c\n", *inp);
                int inp = getchar();
                printf("keycode=%d\n", inp); // DEBUG
                switch(inp)
                {
                        case 65:
                        case 'w':
                                robot->view = UP;
                                BeC_MoveOneStep (BeC_GameField, robot, WIN, COST, &points, &num);
                                break;
                        case 67:
                        case 'd':
                                robot->view = RIGHT;
                                BeC_MoveOneStep (BeC_GameField, robot, WIN, COST, &points, &num);
                                break;
                        case 66:
                        case 's':
                                robot->view = DOWN;
                                BeC_MoveOneStep (BeC_GameField, robot, WIN, COST, &points, &num);
                                break;
                        case 68:
                        case 'a':
                                robot->view = LEFT;
                                BeC_MoveOneStep (BeC_GameField, robot, WIN, COST, &points, &num);
                                break;
                        case 'p':
                                BeC_GameField[robot->ypos][robot->xpos] = DROP;
                }

        }
        BeC_PrintGame (BeC_GameField, robot); // Mache letzten Schritt
        if(num <= 0)
        {
                printf("%s ist satt 🥰\n", ROBOT);
        }
        else
        {
                printf("%s ist zu hungrig um weiterzugehen 😔\n", ROBOT);
        }
}



int main()
{
        // https://stackoverflow.com/a/1798833
        static struct termios oldt, newt;
        tcgetattr( STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~((unsigned) ICANON);
        tcsetattr( STDIN_FILENO, TCSANOW, &newt);


        /***SPIELFELD***/        

        char* BeC_GameField[MAX_Y][MAX_X];     /* [8][8] */

        srand((unsigned) time(NULL));  // mit aktueller uhrzeit seeden



        /***Startpunkt Robo***/
        int posy = (N%8)-1;
        int posx = (V%8)-1;
        //     printf("posy: %d\nposx: %d\n\n", (posy+1), (posx+1));


        /***Zugriff auf Robo Position***/
        robot_t robby = { posy, posx, 0};


        /***SPIEL zeichnen (Feld, Hürden, Robo)***/
        EmptyField(BeC_GameField);
        BeC_CreateObstacles(OBST_NUM,BeC_GameField);


        BeC_Game(BeC_GameField, &robby);
}

