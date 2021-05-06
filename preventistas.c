#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}Cliente;

void CargarCliente(Cliente *Clientes, int cantidad);
void CargarProductos(Producto *producto, int cant);
int totalProducto(int cantidad, float precio);
void mostrarProductos(Producto *productos, int cant);
void mostrarCliente(Cliente *Clientes, int cant);

int main(){
    int cantidadClientes;

    printf ("Ingrese la cantidad de clientes del dia:");
    scanf("%d", &cantidadClientes);
    Cliente *pClientes;
    pClientes= (Cliente*) malloc(sizeof(Cliente)*cantidadClientes);

    CargarCliente(pClientes, cantidadClientes);
    mostrarCliente(pClientes, cantidadClientes);
    getchar();
    getchar();
    return 0;

}
void CargarCliente(Cliente *Clientes, int cantidad){
    for(int i=0; i < cantidad; i++){
        Clientes[i].ClienteID = i + 1;
        Clientes[i].NombreCliente = (char*)malloc(sizeof(char)*100);
        printf("Ingrese el nombre del cliente: \n");
        fflush(stdin);
        gets(Clientes[i].NombreCliente);
        Clientes[i].CantidadProductosAPedir = rand() % 6 + 1;
        Clientes[i].Productos = (Producto*)malloc(sizeof(Producto)*Clientes[i].CantidadProductosAPedir);
        CargarProductos(Clientes[i].Productos, Clientes[i].CantidadProductosAPedir);
    }
}

void CargarProductos(Producto *Productos, int cant){
    for(int i=0; i < cant; i++){
        Productos[i].ProductoID = i + 1;
        Productos[i].Cantidad = rand() % 11 + 1 ; 
        Productos[i].TipoProducto = TiposProductos[rand() % 5];
        Productos[i].PrecioUnitario = rand () % 101 + 10;
    }
}

int totalProducto(int cantidad, float precio){
    float aux;
    aux= cantidad * precio ;
    return (aux);
}
void mostrarProductos(Producto *Productos, int cant){
    float total = 0;
     for(int i=0; i < cant; i++){
        printf("ID del producto: %d \n", Productos[i].ProductoID);
        printf("Cantidad: %d \n", Productos[i].Cantidad);
        printf("Tipo de producto: %s \n", Productos[i].TipoProducto);
        printf("Precio unitario: %f \n", Productos[i].PrecioUnitario);
        total+= totalProducto(Productos[i].Cantidad, Productos[i].PrecioUnitario);
     }
     printf("Precio total: %f \n", total);
}

void mostrarCliente(Cliente *Clientes, int cant){
    char prod;
    for(int i=0; i < cant; i++){
        printf("ID del cliente: %d \n", Clientes[i].ClienteID);
        printf("Nombre del cliente: %s \n", Clientes[i].NombreCliente);
        printf("Cantidad de productos a pedir: %d \n", Clientes[i].CantidadProductosAPedir);
        //printf("Productos pedidos: %s \n", Clientes[i].Productos);

        mostrarProductos(Clientes[i].Productos, Clientes[i].CantidadProductosAPedir);

       
        
     }
}