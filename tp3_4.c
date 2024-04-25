#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
};

typedef struct Producto Producto;

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
};

typedef struct Cliente Cliente;

//funcion para calcular el total a pagar
float calcularCostoTotal(struct Producto producto) {
    return producto.Cantidad * producto.PrecioUnitario;
}
int main()
{
    srand(time(NULL));

    Cliente **Clientes;
    int cantClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);
    getchar();
    Clientes =(Cliente**)malloc(cantClientes * sizeof(Cliente *));

    char *buff;
    buff= (char *) malloc(100*sizeof(char));//reservo memoria para buff


//cargar clientes
    for (int i = 0; i < cantClientes; i++)
    {
        Clientes[i] = (Cliente*)malloc(sizeof(Cliente));
        
        printf("\nCliente N%d", i+1);
        Clientes[i]->ClienteID=i+1;
        Clientes[i]->NombreCliente = malloc((strlen(buff) + 1) * sizeof(char));
        printf("\nNombre: ");
        fgets(buff, 100, stdin);
        buff[strcspn(buff, "\n")] = '\0'; // Eliminar el carácter de nueva línea del final    
        strcpy(Clientes[i]->NombreCliente,buff);
        Clientes[i]->CantidadProductosAPedir= 1+ rand()  % 5;

        //reservo memoria para producto
        Clientes[i]->Productos = malloc(Clientes[i]->CantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < Clientes[i]->CantidadProductosAPedir; j++)
        {
            Clientes[i]->Productos[j].ProductoID = j+1;
            Clientes[i]->Productos[j].Cantidad = rand()%10;
            Clientes[i]->Productos[j].TipoProducto= TiposProductos[rand()%5];
            Clientes[i]->Productos[j].PrecioUnitario=(rand() % 91)+10;
        }   
    }
  
    printf("\n\n---------------------------RESULTADOS----------------------------");
  //mostrar
  for (int i = 0; i < cantClientes; i++)
  {
    printf("\n-----------------------------------------------------------------");
    printf("\nCliente ID: %d\n", Clientes[i]->ClienteID);
    printf("Nombre del cliente: %s\n",Clientes[i]->NombreCliente);
    printf("Cantidad de Productos a pedir: %d\n", Clientes[i]->CantidadProductosAPedir);

    float totalAPagar = 0;
    for (int j = 0; j < Clientes[i]->CantidadProductosAPedir; j++)
    {
        Producto producto = Clientes[i]->Productos[j];
        printf("\n------------Producto cargado nro. %d\n ", producto.ProductoID);
        printf("Cantidad: %d\n", producto.Cantidad);
        printf("Tipo de producto: %s\n",producto.TipoProducto);
        printf("Precio unitario: %.2f\n", producto.PrecioUnitario);
    
        totalAPagar += calcularCostoTotal(producto);
    
    }
    printf("\n------------Total a Pagar: %.2f\n", totalAPagar);
    }
  //Libero memoria
    for (int i = 0; i < cantClientes; i++) {
        free(Clientes[i]->NombreCliente);
        free(Clientes[i]->Productos);
    }
  
    return 0;
}