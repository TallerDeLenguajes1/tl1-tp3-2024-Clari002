#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMA 5

int main()
{
    char *V[TAMA];
    char *buff;
    int i;

    buff= (char *) malloc(100*sizeof(char));//reservo memoria para buff
    printf("------------------CARGAR NOMBRES------------\n");
    for (i = 0; i < TAMA; i++)
    { 
        printf("Nombre %d%c: ", i+1, 167);
        gets(buff);    
        V[i]=(char *) malloc((strlen(buff)+1)*sizeof(char));//reservo memoria 
        strcpy(V[i],buff);
    }
    printf("\n");

    printf("------------------NOMBRES CARGADOS------------");
    for (i = 0; i < TAMA; i++)
    {
        printf("\nNombre %d%c: %s", i+1,167, V[i]);
       //otra forma de mostrar puts(V[i]);
    }

    for (i = 0; i < TAMA; i++)
    {
        free(V[i]);
    }
    free(buff);

    return 0;
}
 