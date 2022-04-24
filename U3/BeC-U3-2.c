#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dist(double Px, double Py, double Tx, double Ty)
{
        double x = Px-Tx;
        double y = Py-Ty;

        return sqrt(pow(x,2)+pow(y,2));
}

int main()
{
        int Fx = 0;
        int Fy = 0;
        printf("Koords of F (x y): ");
        scanf("%d %d", &Fx, &Fy);

        int Zx = 0;
        int Zy = 0;
        printf("Koords of Z (x y): ");
        scanf("%d %d", &Zx, &Zy);

        while(Fx != Zx && Fy != Zy)
        {
                printf("%d/%d: ", Fx, Fy);
                int vx = Zx - Fx;
                int vy = Zy - Fy;
                if ( abs(vx) == abs(vy) ) // diagonal
                {
                        if(vx > 0 && vy > 0)
                        {
                               printf("NE ");
                               Fx += 1;
                               Fy += 1;
                        }
                        else if(vx > 0 && vy < 0)
                        {
                               printf("SE ");
                               Fx += 1;
                               Fy += -1;
                        }
                        else if(vx < 0 && vy > 0)
                        {
                               printf("NW ");
                               Fx += -1;
                               Fy += 1;
                        }
                        else
                        {
                               printf("SW ");
                               Fx += -1;
                               Fy += -1;
                        }
                }
                else
                {
                        if(abs(vx) > abs(vy)) // links/rechts ist staerker
                        {
                                if(vx > 0) // nach rechts
                                {
                                        printf("E ");
                                        Fx += 1;
                                }
                                else // nach links
                                {
                                        printf("W ");
                                        Fx += -1;
                                }

                        }
                        else // oben/unten ist staerker
                        {
                                if(vy > 0) // nach oben
                                {
                                        printf("N ");
                                        Fy += 1;
                                }
                                else // nach unten
                                {
                                        printf("S ");
                                        Fy += -1;
                                }

                        }
                }      
                printf("-> %d/%d\n", Fx, Fy); 
        }
}
