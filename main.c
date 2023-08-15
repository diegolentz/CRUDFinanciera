#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <ctype.h>
#include <time.h>
#include "funciones.h"
#define N 100

struct  Creditos{
    int orden;
    char nombreCliente[30];
    float importe;
    char tipoDeCredito;
    int dia ;
    int mes ;
    int ano ;
    int NroCuotas;
    float importeCuotas;
    float IVA;
    float totalCuota;
    int activo;
};

int main(){

    int opcion;
    int opcion6;
    int opcion2;
    int opcion3;
    char archivoBinario[30]= "creditos.dat";
    char yesno;
    char palabra[20];
    float menorvalor;
    float mayorvalor;
    FILE *archivo = NULL;
    FILE *ArchivoCreado= NULL;

    struct Creditos * aux;

    bienvenido();

    do{ printf("\n\n");
        printf("\n\t\t\t\t\t BIENVENIDO AL MENU.\n");
        printf("\n\n\t\t\t\t\t QUE TAREA DESEA REALIZAR?");
        printf("\n\n\t\t\t\t\t 1-> LISTAR CSV");
        printf("\n\n\t\t\t\t\t 2-> CREAR NUEVO ARCHIVO BINARIO");
        printf("\n\n\t\t\t\t\t 3-> MIGRAR DATOS DE CSV A ARCHIVO BINARIO");
        printf("\n\n\t\t\t\t\t 4-> FILTRAR DATOS DE LOS CLIENTES");
        printf("\n\n\t\t\t\t\t 5-> CREAR NUEVO CLIENTE");
        printf("\n\n\t\t\t\t\t 6-> BUSQUEDA (NUM. ORDEN / APELLIDO)");
        printf("\n\n\t\t\t\t\t 7-> MODIFICA CLIENTE");
        printf("\n\n\t\t\t\t\t 8-> BAJA LOGICA ");
        printf("\n\n\t\t\t\t\t 9-> BAJA FISICA");//FALTA REALIZAR
        printf("\n\n\t\t\t\t\t 10-> BAJA LISTAR XYZ \n");//FALTA REALIZAR
        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                    system("cls");
                    printf("LISTANDO...\n");
                    printf("\n\n");
                    leerDatosCSV(archivo);
                   break;
            case 2:
                    system("cls");
                    printf("\n\n\n\n CREACION DE ARCHIVO BINARIO\n\n");
                    printf("\n\n\n\n SE CREA ARCHIVO'creditos.dat' EN CARPETA 'BINARIOS'. \n");
                    printf("\n\n\n\n DESEA CONTINUAR? [S/N] : \n \n");
                    fflush(stdin);
                    scanf("%c",&yesno);


                    if((yesno== 's')||(yesno== 'S')){                 //VALIDA LA OPCION QUE ELIGIO EL USUARIO
                        crearArchivo(ArchivoCreado,archivoBinario);
                        system("cls");
                    }else{
                        system("cls");
                        printf("\n\n\n\n\EL ARCHIVO NO FUE CREADO!");
                        printf("\n\n\n\n");
                        system("pause");
                        system("cls");                    }
                    break;
                    system("cls");
            case 3:
                    system("cls");
                    migrar(archivo,ArchivoCreado,archivoBinario);
                    break;
            case 4:
                    system("cls");

                    do {
                        printf("\n\n\n\n\COMO PREFIERE FILTRAR?");
                        printf("\n\n\n\n\ 1-> TODOS (ACTIVOS E INACTIVOS)");
                        printf("\n\n\n\n\ 2-> SOLO ACTIVOS");
                        printf("\n\n\n\n\ 3-> POR TIPO DE CREDITO (INGRESO POR TECLADO)");
                        printf("\n\n\n\n\ 4-> POR RANGO ""TOTAL CUOTA""");
                        printf("\n\n\n\n\PRESIONE 5 PARA REGRESAR \n");
                        scanf("%d", &opcion2);
                        system("cls");

                        switch (opcion2) {
                            case 1:
                                system("cls");                                printf("LISTADO (ACTIVOS / INACTIVOS)\n");
                                imprimirTodo(ArchivoCreado,archivoBinario);
                                system("pause");
                                system("cls");

                                break;
                            case 2:
                                system("cls");
                                printf("Listando solo los clientes activos\n");
                                imprimirActivos(ArchivoCreado,archivoBinario);
                                system("pause");
                                system("cls");
                                break;
                            case 3:
                                system("cls");
                                printf("FILTRAR POR TIPO DE CREDITO\n");
                                obtenerpalabra(palabra);//obtengo palabra
                                leerArchivoBinario(ArchivoCreado,palabra);
                                system("pause");
                                system("cls");
                                break;
                            case 4:
                                system("cls");
                                printf("LISTAR POR RANGO (TOTAL CUOTA)\n\n");
                                obtenerrango(&menorvalor,&mayorvalor);//pongo un rango de valores
                                filtrocash(ArchivoCreado,&menorvalor,&mayorvalor,archivoBinario);
                                system("pause");
                                system("cls");
                                break;
                            default:
                                printf("""\n");
                                break;
                        }
                    } while (opcion2 < 5);
                    break;
             case 5:
                    system("cls");
                    printf("CREAR NUEVO CLIENTE\n");
                    registrarCliente(ArchivoCreado,archivoBinario);
                    system("pause");
                    system("cls");
                    break;
            case 6:
                    system("cls");
                    printf("BUSCAR CLIENTE (1-> ORDENo 2-> APELLIDO)\n");
                    busqueda(ArchivoCreado,archivoBinario);
                    system("pause");
                    system("cls");
                    break;
             case 7:
                    system("cls");
                    printf("MODIFICAR (IMPORTE/TIPO DE CREDITO)\n");
                    modifica(ArchivoCreado,archivoBinario);
                    system("pause");
                    system("cls");
                    break;
            case 8:
                    system("cls");
                    printf("BAJA LOGICA\n");
                    bajaLogica(ArchivoCreado,archivoBinario);
                    system("pause");
                    system("cls");
                    break;
             case 9:
                    system("cls");
                    printf("EJERCICIO FALTA HACER  \n");
                    system("pause");
                    system("cls");
                    break;
             case 10:
                    system("cls");
                    printf("EJERCICIO LISTAR XYZ FALTA HACER \n");
                    system("pause");
                    system("cls");
                    break;
            default:
                    printf("OPCION INVALIDA.\n");
        }
    }while(opcion > 0);
return 0;
}
