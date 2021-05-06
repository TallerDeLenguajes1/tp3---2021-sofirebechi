#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
};

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
struct Producto *Productos //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
};
void CargarCliente(struct Cliente *Clientes, int cantidad);
void CargarProductos(struct Producto *producto, int cant);
int totalProducto(int cantidad, float precio);
void mostrarProductos(struct producto * productos, int cant);
void mostrarCliente( struct clientes * Clientes, int cant);



int main(){
    int cantidadClientes;

 printf ("Ingrese la cantidad de clientes del día:");
 scanf(%d,&cantidadClientes);

 Cliente *pClientes;

pClientes= (Cliente*) malloc(sizeof(Cliente)*cantidadClientes);

cargarCliente(pClientes, cantidadClientes);
mostrarCliente(pClientes, cantidadClientes);
getchar();

return 0;

}
void CargarCliente(struct Cliente *Clientes, int cantidad){
    for(int i=0; i < cantidad; i++){
        Cliente[i].ClienteID = i + 1;
        Cliente[i].NombreCliente = (char*)malloc(sizeof(char)*100);
        printf("Ingrese el nombre del cliente: \n");
        scanf(%s,&Cliente[i].NombreCliente);
        Cliente[i].CantidadProductosAPedir = rand() % 6 + 1;
        Cliente[i].Productos = (Producto*)malloc(sizeof(Producto)*Cliente[i].CantidadProductosAPedir);
        cargarProductos(Cliente[i].Productos, Cliente[i].CantidadProductosAPedir);

    }
}

void CargarProductos(struct Producto *producto, int cant){
    for(int i=0; i < cantidad; i++){
        Producto[i].ProductoID = i + 1;
        Producto[i].Cantidad = rand() % 11 +1 ; 
        Producto[i].TipoProducto = tiposProducto[rand() % 6 + 1];
        Producto[i].PrecioUnitario = rand () % 101 + 10; 
        
    }
}

int totalProducto(int cantidad, float precio){
    float aux;
    aux= cantidad * precio ;
    return (aux);
}
void mostrarProductos(struct producto * productos, int cant){
    float total = 0;
     for(int i=0; i < cantidad; i++){
         printf("ID del producto: %d \n", Producto[i].ProductoID);
         printf("Cantidad: %d \n", Producto[i].Cantidad);
         printf("Tipo de producto: %s \n", Producto[i].TipoProductos);
         printf("Precio unitario: %f \n", Producto[i].PrecioUnitario);
         total+= totalProducto(&producto[i]);
     }
}

void mostrarCliente(struct clientes * Clientes, int cant){
    float total = 0;
    for(int i=0; i < cantidad; i++){
         printf("IDdel cliente: %d \n", Cliente[i].ClienteID);
         printf("Nombre del cliente: %s \n", Cliente[i].NombreCliente);
         printf("Cantidad de productos a pedir: %d \n", Cliente[i].CantidadProductosAPedir);
         printf("Productos pedidos: %s \n", Cliente[i].Productos);

         total = mostrarProductos(Cliente[i].Productos, Cliente[i].CantidadProductosAPedir);

        printf("Total a pagar del cliente: %f \n", total);
     }
}