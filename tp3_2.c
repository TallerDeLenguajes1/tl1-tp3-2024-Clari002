#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 5
#define M 12

int main()
{
    int m[N][M];
    int i, j;
    int incremento1=0, incremento2=0, incremento3=0, incremento4=0, incremento5=0;
    float promedio ;
    srand(time(NULL));

    for ( i = 0; i < N; i++)
    {
        for (j = 0; j< M; j++)
        {
            m[i][j] = 10000+ rand()  % 50001;       
        }   
    }

    printf("\n\t\t\t\tMATRIZ CARGADA\n");
    for ( i = 0; i < N; i++)
    {
        for (j = 0; j< M; j++)
        {
            printf("%d  ", m[i][j]);      
        }   
        printf("\n");
    }
    
    //calcular ganancia por añp
    printf("\n\n-------------PROMEDIO DE GANANCIA CADA A%cO-------------", 164);
    for (int j = 0; j < M; j++)
    {
            incremento1 = incremento1 + m[0][j];
    }
    printf("\n1er a%co: %c%d", 164, 36, incremento1/M);

    for (int j = 0; j < M; j++)
    {
            incremento2 = incremento2 + m[1][j];
    }
    printf("\n2do a%co: %c%d", 164, 36, incremento2/M);

    for (int j = 0; j < M; j++)
    {
            incremento3 = incremento3 + m[2][j];
    }
    printf("\n3er a%co: %c%d", 164, 36, incremento3/M);

    for (int j = 0; j < M; j++)
    {
            incremento4 = incremento4 + m[3][j];
    }
    printf("\n4to a%co: %c%d", 164, 36, incremento4/M);

    for (int j = 0; j < M; j++)
    {
            incremento5 = incremento5 + m[4][j];
    }
    printf("\n5to a%co: %c%d", 164, 36, incremento5/M);


    return 0;
}