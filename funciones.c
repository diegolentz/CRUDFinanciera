#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "funciones.h"

struct  Creditos{
    int orden;
    char nombreCliente[50];
    float importe;
    char tipoDeCredito[20];
    int dia ;
    int mes ;
    int ano ;
    int NroCuotas;
    float importeCuotas;
    float IVA;
    float totalCuota;
    int activo;
};

struct CreditoAuxiliar{
    int orden;
    char nombre[25];
    char apellido[25];
    float importe;
    char tipoDeCredito[20];
    int dia ;
    char mesCad[4];
    int ano ;
    int NroCuotas;
    float importeCuotas;
    float IVA;
    float totalCuota;
    int activo;
};

void bienvenido(){
    printf("\n ....................................................................................................................\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t  TP FINAL\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t  Laboratorio de computacion II\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t      1ER cuatrimestre 2023\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t       FINANCIERA: REGISTRO DE OPERACIONES\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\  Lentz, Diego Alejandro\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\t\t\t\t\t    :\n");
    printf(" :\t\t\t\t\t\t\t\t\t\  Entrega: 20/06/2023\t\t\t    :\n");
    printf(" :..................................................................................................................:\n");

    getchar();
    system("cls");
}

//PUNTO 4:
void leerDatosCSV(FILE *archivo) {
    archivo=fopen("prestamos.csv","r");

    if(archivo==NULL){
        printf("ERROR AL ABRIR EL ARCHIVO!\n");
        return;
    }
    char linea[2000],no[30],tc[30];
    int or,di,me,an,nc;
    float im,ic,iv,t;

    fgets(linea,sizeof(linea),archivo); // Leer y descartar la primera línea

    printf(".........................................................................................................................\n");
    printf(": %4s  :    %-13s  : %7s  : %11s :%12s    : %10s :%4s :%6s   :%10s :\n", "ORDEN", "NOMBRE", "IMPORTE", "TIPO CREDITO", "FECHA", "NUM.CUOTAS","IMP. CUOTA","IVA","TOTAL CUOTA");
    printf(".........................................................................................................................\n");

    while (fgets(linea,sizeof(linea),archivo)){
        leer(linea,&or,no,&im,tc,&di,&me,&an,&nc,&ic,&iv,&t);
        printf(": %-4d   : %-16s  : %-8.2f : %-1s : %-2d : %-1d : %-5d :  %9d : %-9.2f : %-7.2f : %10.2f :\n", or, no, im, tc, di, me, an, nc, ic, iv, t);
        printf(".........................................................................................................................\n");
    }
    fclose(archivo);
    printf("\n\n");
    system("pause");
    system("cls");
}
void leer(char *linea,int *or,char *no,float *im,char *tc,int *di,int *me,int *an,int *nc,float *ic,float *iv,float *t){

    char *orden, *nombre, *importe, *tipocredito, *dia, *mes, *anio, *numerocuotas,*importecuotas, *iva,*importet,*ok;
    ok=strtok(linea,";");
    orden=(ok);
    *or=atoi(orden);

    nombre=strtok(NULL,";");
    strcpy(no,nombre);

    importe=strtok(NULL,";");
    *im=atol(importe);

    tipocredito=strtok(NULL,";");
    strcpy(tc,tipocredito);

    dia=strtok(NULL,";");
    *di=atol(dia);

    mes=strtok(NULL,";");
    *me=atol(mes);

    anio=strtok(NULL,";");
    *an=atol(anio);

    numerocuotas=strtok(NULL,";");
    *nc=atol(numerocuotas);

    importecuotas=strtok(NULL,";");
    *ic=atol(importecuotas);

    iva=strtok(NULL,";");
    *iv=atol(iva);

    importet=strtok(NULL,";");
    *t=atol(importet);
}

//PUNTO 5:
void crearArchivo(FILE *ArchivoCreado,char archivoBinario[] ){

    ArchivoCreado =fopen(archivoBinario, "w");
      if(ArchivoCreado != NULL){
        system("cls");
        printf("\n\nARCHIVO CREADO EXITOSAMENTE!\n\n\n");
        fclose(ArchivoCreado);
    }
    else{
        printf("\n\nERROR EN LA CREACION DEL ARCHIVO!\n");
    }
    system("pause");
    system("cls");
}

//PUNTO 6:
void migrar(FILE *archivo, FILE *archivoCreado , char *archivoBinario){
    int i = 0;
    char* meses[] = {"ene", "feb", "mar", "abr", "may", "jun", "jul", "ago", "sep", "oct", "nov", "dic"};

    archivo = fopen("prestamos.csv","r");
    archivoCreado = fopen(archivoBinario,"rb+");

    char linea[2000],no[30],tc[30];
    int or,di,me,an,nc;
    float im,ic,iv,t;

    struct CreditoAuxiliar aux;

    fseek(archivoCreado, 0*sizeof(struct Creditos), SEEK_SET);

    if(archivo!=NULL){
        fgets(linea,2000,archivo);//Leo primer linea  descarto

        while(!feof(archivo)){
            leer(linea,&or,no,&im,tc,&di,&me,&an,&nc,&ic,&iv,&t);

//pasar variables del csv al struct

            aux.orden=or;

//mayusculizo variables

            mayusculizador(no);
            mayusculizador(tc);


//separo nombre de apellido

            char* token = strtok(no, " "); // Se utiliza el espacio como delimitador

            if (token != NULL) {
                strcpy(aux.nombre, token); // Copiar el primer token (nombre) en la variable nombre
                    token = strtok(NULL, " "); // Obtener el siguiente token (apellido)
                if (token != NULL) {
                        strcpy(aux.apellido, token); // Copiar el segundo token (apellido) en la variable apellido
                }
            }

            aux.importe=im;
            strcpy(aux.tipoDeCredito,tc);
            aux.dia=di;

            i = me;
            strcpy(aux.mesCad,meses[i-1]);
            aux.ano=an;
            aux.NroCuotas= nc;
            aux.importeCuotas=ic;
            aux.IVA=iv;
            aux.totalCuota=t;
            aux.activo=1;

//imprime en el binario
            fwrite(&aux, sizeof(struct Creditos), 1, archivoCreado);
            fgets(linea,2000,archivo);
            }
        fclose(archivo);
        fclose(archivoCreado);
        printf("\n\n\n\nDATOS MIGRADOS CORRECTAMENTE!\n\n\n\n\n");
    }
    else{
        printf("\n\n\n\nERROR EN LA MIGRACION!");
    }
    system("pause");
    system("cls");
}
void mayusculizador(char *mayus){
   while (*mayus) {
        *mayus = toupper(*mayus);
        mayus++;
    }
}

//punto 7
void imprimirTodo(FILE *ArchivoCreado,char archivoBinario[]){

    ArchivoCreado=fopen(archivoBinario,"rb");

     if (ArchivoCreado != NULL) {

        struct CreditoAuxiliar registro;
           // Leer y descartar la primera línea del archivo
        fread(&registro, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado);

            printf("..................................................................................................................................................\n");
            printf(": %-1s  :  %-4s    : %7s   : %s  : %8s : %s :%4s :%6s :%10s : %s : %-7s : %s : %s :\n", "ORDEN", "NOMBRE", "APELLIDO", "IMPORTE", "TIPO CREDITO", "DIA","MES","ANIO","NUMERO CUOTAS","IMPORTE CUOTA","IVA","TOTAL CUOTA","ACTIVO");
            printf("..................................................................................................................................................\n");


          while (fread(&registro, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado) == 1) {
             printf(": %-4d   : %-9s  : %-9s  : %-8.2f : %-1s : %-2d  : %-1s : %4d  :  %9d   : %-9.2f     : %-7.2f : %10.2f  : %-5d  :\n", registro.orden, registro.nombre, registro.apellido, registro.importe, registro.tipoDeCredito, registro.dia, registro.mesCad, registro.ano, registro.NroCuotas, registro.importeCuotas, registro.IVA,registro.totalCuota,registro.activo);
            printf("..................................................................................................................................................\n");
            }
    }else{
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
    }
    fclose(ArchivoCreado);
}
void imprimirActivos(FILE *ArchivoCreado, char archivoBinario[]) {
    ArchivoCreado = fopen(archivoBinario, "rb");
    struct CreditoAuxiliar registro;

    if (ArchivoCreado == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("..................................................................................................................................................\n");
    printf(": %-1s  :  %-4s    : %7s   : %s  : %8s : %s :%4s :%6s :%10s : %s : %-7s : %s : %s :\n", "ORDEN", "NOMBRE", "APELLIDO", "IMPORTE", "TIPO CREDITO", "DIA", "MES", "ANIO", "NUMERO CUOTAS", "IMPORTE CUOTA", "IVA", "TOTAL CUOTA", "ACTIVO");
    printf("..................................................................................................................................................\n");
    fread(&registro, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado);
    while (fread(&registro, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado) == 1) {
        if (registro.activo == 1) {
            printf(": %-4d   : %-9s  : %-9s  : %-8.2f : %-1s : %-2d  : %-1s : %4d  :  %9d   : %-9.2f     : %-7.2f : %10.2f  : %-5d  :\n", registro.orden, registro.nombre, registro.apellido, registro.importe, registro.tipoDeCredito, registro.dia, registro.mesCad, registro.ano, registro.NroCuotas, registro.importeCuotas, registro.IVA, registro.totalCuota, registro.activo);
            printf("..................................................................................................................................................\n");
        }
    }

    fclose(ArchivoCreado);
}
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void obtenerpalabra(char palabra[]) {


    int palabraValida = 0;

    while (!palabraValida) {
        printf("\n\nTIPEE EL TIPO DE CREDITO\n\n");
        printf("A SOLA FIRMA / CON GARANTIA\n\n\n\n");
        printf("\n\n\n");
        fflush(stdin);
        scanf(" %[^\n]s", palabra);

        mayusculizador(palabra);

        // Verificar si la palabra es válida
        if (strcmp(palabra, "A SOLA FIRMA") == 0 || strcmp(palabra, "CON GARANTIA") == 0) {
            palabraValida = 1;
        } else {
            system("cls");
            printf("PALABRA INVALIDA, INTENTELO NUEVAMENTE.\n");
        }
    }
    system("cls");
}
void leerArchivoBinario(FILE *ArchivoCreado,char palabra[]){
    ArchivoCreado = fopen("creditos.dat", "rb");
    if (ArchivoCreado == NULL) {
        printf("\nERROR AL ABRIR EL ARCHIVO\n");
        return;
    }

    struct CreditoAuxiliar credito;
     printf("..................................................................................................................................................\n");
            printf(": %-1s  :  %-4s    : %7s   : %s  : %8s : %s :%4s :%6s :%10s : %s : %-7s : %s : %s :\n", "ORDEN", "NOMBRE", "APELLIDO", "IMPORTE", "TIPO CREDITO", "DIA","MES","ANIO","NUMERO CUOTAS","IMPORTE CUOTA","IVA","TOTAL CUOTA","ACTIVO");
            printf("..................................................................................................................................................\n");


    while (fread(&credito, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado) == 1) {
        if (strcmp(credito.tipoDeCredito, palabra) == 0) {
              printf(": %-4d   : %-9s  : %-9s  : %-8.2f : %-1s : %-2d  : %-1s : %4d  :  %9d   : %-9.2f     : %-7.2f : %10.2f  : %-5d  :\n", credito.orden, credito.nombre, credito.apellido, credito.importe, credito.tipoDeCredito, credito.dia, credito.mesCad, credito.ano, credito.NroCuotas, credito.importeCuotas, credito.IVA,credito.totalCuota,credito.activo);
            printf("..................................................................................................................................................\n");
            }
    }

    fclose(ArchivoCreado);
}
void obtenerrango(float* menorvalor, float* mayorvalor) {

    printf("INGRESE VALOR MINIMO DE BUSQUEDA: \n\n");
    scanf("%f", menorvalor);

    // Validar monto inicial no negativo
    while (*menorvalor < 0) {
        printf("\n\nEL MONTO NO PUEDE SER NEGATIVO, INTENTELO NUEVAMENTE: ");
        scanf("%f", menorvalor);
    }
    printf("VALOR INGRESADO: %.2f\n\n", *menorvalor);
    system("cls");

    printf("INGRESE VALOR MAXIMO DE BUSQUEDA: \n\n");
    scanf("%f", mayorvalor);

    // Validar monto máximo no supere los 1000000
    while (*mayorvalor > 1000000) {
        printf("EL VALOR MAXIMO NO PUEDE SUPERAR  $$ 1000000. INTENTELO NUEVAMENTE: \n\n");
        scanf("%f", mayorvalor);
    }
    printf("VALOR INGRESADO %.2f\n\n", *mayorvalor);
    system("pause");
    system("cls");

}
void filtrocash(FILE *ArchivoCreado,float *menorvalor,float *mayorvalor,char palabra[]){
     ArchivoCreado = fopen(palabra, "rb");
    if (ArchivoCreado == NULL) {
        system("cls");
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
        return;
    }

    struct CreditoAuxiliar cash;

    while (fread(&cash, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado) == 1) {
        if (cash.totalCuota >= *menorvalor && cash.totalCuota <= *mayorvalor) {
            printf("..................................................................................................................................................\n");
            printf(": %-1s  :  %-4s    : %7s   : %s  : %8s : %s :%4s :%6s :%10s : %s : %-7s : %s : %s :\n", "ORDEN", "NOMBRE", "APELLIDO", "IMPORTE", "TIPO CREDITO", "DIA","MES","ANIO","NUMERO CUOTAS","IMPORTE CUOTA","IVA","TOTAL CUOTA","ACTIVO");
            printf("..................................................................................................................................................\n");


          while (fread(&cash, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado) == 1) {
             printf(": %-4d   : %-9s  : %-9s  : %-8.2f : %-1s : %-2d  : %-1s : %4d  :  %9d   : %-9.2f     : %-7.2f : %10.2f  : %-5d  :\n", cash.orden, cash.nombre, cash.apellido, cash.importe, cash.tipoDeCredito, cash.dia, cash.mesCad, cash.ano, cash.NroCuotas, cash.importeCuotas, cash.IVA,cash.totalCuota,cash.activo);
            printf("..................................................................................................................................................\n");
            }
        }
    }
    fclose(ArchivoCreado);
}
void registrarCliente(FILE *ArchivoCreado,char archivoBinario[30]) {
    ArchivoCreado = fopen(archivoBinario, "rb+");
    if (ArchivoCreado == NULL) {
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
        return;
    }
    struct CreditoAuxiliar cliente;
    int nuevoOrden = 0;

// Solicitar datos del cliente al usuario
// Orden

    while (1) {
        while (1) {
            printf("ORDEN: ");
            if (scanf("%d", &nuevoOrden) != 1) {
                printf("ERROR, DEBE INGRESAR UN NUMERO ENTERO POSITIVO, INTENTELO NUEVAMENTE.\n");
                while (getchar() != '\n');  // Limpiar el búfer de entrada
                continue;
            }
            break;
        }
        if (!validarEnteroPositivo(nuevoOrden,archivoBinario)) {
            continue;
        }
        if (verificarExistenciaOrden(ArchivoCreado,nuevoOrden,archivoBinario)) {
            printf("ERROR, EL NUMERO DE ORDEN QUE SE PRETENDE INGRESAR YA EXISTE\n");
            printf("INTENTE NUEVAMENTE\n");
        } else {
            break;
        }
    }

// Obtener la cantidad total de registros en el archivo
    int totalRegistros = obtenerTotalRegistros(ArchivoCreado);

// Actualizar los registros intermedios con orden 0
    actualizarRegistrosIntermedios(ArchivoCreado, totalRegistros, nuevoOrden);

// Asignar el nuevo orden al cliente actual
    cliente.orden = nuevoOrden;
    system("cls");
// Nombre
    char nombre[25];
    while (1) {
        printf("NOMBRE: ");
        scanf("%s", nombre);
        int i;
        int soloCaracteres = 1;
        for (i = 0; nombre[i] != '\0'; i++) {
            if (!isalpha(nombre[i])) {
                soloCaracteres = 0;
                break;
            }
        }
        if (!soloCaracteres) {
            printf("ERROR, EL NOMBRE SOLO PUEDE TENER CARACTERES, INTENTE DE NUEVO.\n");
            while (getchar() != '\n');  // Limpiar el búfer de entrada
            continue;
        }
        break;
    }
    strncpy(cliente.nombre, nombre, sizeof(cliente.nombre));
    system("cls");

// Apellido
    char apellido[25];
    while (1) {
        printf("APELLIDO: ");
        scanf("%s", apellido);
        int i;
        int soloCaracteres = 1;
        for (i = 0; apellido[i] != '\0'; i++) {
            if (!isalpha(apellido[i])) {
                soloCaracteres = 0;
                break;
            }
        }
        if (!soloCaracteres) {
            printf("ERROR, EL APELLIDO SOLO PUEDE TENER CARACTERES, INTENTE DE NUEVO.\n");
            while (getchar() != '\n');  // Limpiar el búfer de entrada
            continue;
        }
        break;
    }
    strncpy(cliente.apellido, apellido, sizeof(cliente.apellido));
    system("cls");

//Importe
    char importeStr[25];
    while (1) {
        printf("IMPORTE: ");
        scanf("%s", importeStr);
        int i;
        int soloNumeros = 1;
        for (i = 0; importeStr[i] != '\0'; i++) {
            if (!isdigit(importeStr[i])) {
                soloNumeros = 0;
                break;
            }
        }
        if (!soloNumeros) {
            printf("ERROR, EL IMPORTE DEBE SER NUMERICO, INTENTE NUEVAMENTE.\n");
            while (getchar() != '\n');  // Limpiar el búfer de entrada
            continue;
        }
        break;
    }
    cliente.importe = atof(importeStr);
    system("cls");

//tipo de credito
    obtenerTipoCredito(cliente.tipoDeCredito);

//fecha
    int dia = 0;
    int mesent = 0;
    int ultimo;
    int fechaValida = 0; // Variable para controlar la condición de salida del bucle

    while (fechaValida == 0) {
        printf("INGRESE ANIO:\n");
        if (scanf("%d", &ultimo) != 1) {
            printf("ERROR, EL ANIO DEBE SER NUMERICO, INTENTE NUEVAMENTE.\n");
          // while (getchar() != '\n');  // Limpiar el búfer de entrada
            continue;
        }
         cliente.ano = ultimo;
        system("cls");
        while (getchar() != '\n');  // Limpiar el búfer de entrada

                printf("INGRESE MES:\n");
                if (scanf("%d", &mesent) != 1) {
                    fflush(stdin);
                    printf("ERROR, EL ANIO DEBE SER NUMERICO, INTENTE NUEVAMENTE.\n");
                    fflush(stdin);
                    continue;
                }
                system("cls");
          //          cliente.ano = ultimo;
                    fflush(stdin);
//printf("ingreso el ano %d \n",ultimo);
                    printf("INGRESE EL DIA:\n");
                    if (scanf("%d", &dia) != 1) {
                        fflush(stdin);
                        printf("ERROR, EL DIA DEBE SER NUMERICO, INTENTE NUEVAMENTE.\n");
                        fflush(stdin);
                        continue;
                    }
                    system("cls");
                    fflush(stdin);
//VALIDO FECHA
                if (!validarFecha(&ultimo, &mesent, &dia)) {
                    printf("ERROR, FECHA INVALIDA. INTENTE NUEVAMENTE.\n");
                } else {
                    printf("\nFECHA VALIDA.\n");
                    system("pause");
                    system("cls");
                    char mesCadena[3];
                    mesCadena[5]='\0'; // Ajuste: cambiar el tamaño a 4 para incluir el terminador nulo

                    convertirMes(&mesent,mesCadena);   //convierte  mes
                    cliente.dia = dia;
                    strncpy(cliente.mesCad, mesCadena, sizeof(cliente.mesCad));


                    fechaValida = 1; // La fecha es válida, se establece la condición de salida del bucle
                }
    }
    while (1) {
        fflush(stdin);
        printf("NUMERO DE CUOTAS: ");
        if (scanf("%d", &(cliente.NroCuotas)) != 1) {
                printf("ERROR, EL NUMERO DE CUOTAS DEBE SER NUMERICO, INTENTE NUEVAMENTE.\n");
                fflush(stdin);
                continue;
        }
        fflush(stdin);
        if (!validarEnteroPositivo(cliente.NroCuotas,archivoBinario)) {
            printf("Error: El número de cuotas debe ser un entero positivo. Intente nuevamente.\n");
            continue;
        }

        break;
    }

    cliente.importeCuotas=(cliente.importe/cliente.NroCuotas);
    cliente.IVA=(cliente.importeCuotas*0.21);
    cliente.totalCuota=(cliente.importeCuotas+cliente.IVA);
    cliente.activo = 1;

// Escribir los datos del cliente en el archivo
    fseek(ArchivoCreado, (nuevoOrden) * sizeof(struct CreditoAuxiliar), SEEK_SET);
    fwrite(&cliente, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado);
    /*
    printf(".........................................................................................................................\n");
    printf(": %4s  :    %-13s  : %7s  : %11s :%12s    : %10s :%4s :%6s   :%10s :\n", "ORDEN", "NOMBRE", "IMPORTE", "TIPO CREDITO", "FECHA", "NUM.CUOTAS","IMP. CUOTA","IVA","TOTAL CUOTA");
    printf(".........................................................................................................................\n");


     while (fread(&cliente, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado) == 1) {
            printf(": %-4d   : %-9s  : %-9s  : %-8.2f : %-1s : %-2d  : %-1s : %4d  :  %9d   : %-9.2f     : %-7.2f : %10.2f  : %-5d  :\n", cliente.orden, cliente.nombre, cliente.apellido, cliente.importe, cliente.tipoDeCredito, cliente.dia, cliente.mesCad, cliente.ano, cliente.NroCuotas, cliente.importeCuotas, cliente.IVA,cliente.totalCuota,cliente.activo);
            printf("..................................................................................................................................................\n");
            }
*/
// Cerrar el archivo
    fclose(ArchivoCreado);

    printf("\n\CLIENTE CREADO EXITOSAMENTE.\n");
}

int verificarExistenciaOrden(FILE *ArchivoCreado,int nuevoOrden,char arcivoBinario[]) {
    ArchivoCreado= fopen(arcivoBinario, "rb+");
    if (ArchivoCreado == NULL) {
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
        return 0;
    }

    struct CreditoAuxiliar cliente;

    while (fread(&cliente, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado) == 1) {
        if (cliente.orden == nuevoOrden) {
            printf("ERROR\n\n");
            fclose(ArchivoCreado);
            return 1; // El orden ya existe en el archivo
        }
    }

    fclose(ArchivoCreado);
    return 0; // El orden no existe en el archivo
}

int validarEnteroPositivo(int valor,char arcivoBinario[]) {
    if (valor < 0) {
        printf("ERROR, EL VALOR DEBE SER POSITIVO, INTENTE NUEVAMENTE.\n");
        return 0;
    }
    return 1;
}

int validarFlotantePositivo(float valor) {
    if (valor < 0) {
        printf("ERROR, EL VALOR DEBE SER POSITIVO, INTENTE NUEVAMENTE.\n");
        return 0;
    }
    return 1;
}

void obtenerTipoCredito(char tipoCredito[]) {
    system("cls");
    printf("Tipo de Crédito:\n");

    printf("1-> A SOLA FIRMA\n");
    printf("2-> CON GARANTIA\n");

    while (1) {
        printf("INGRESE UNA OPCION (1-> A SOLA FIRMA / 2-> CON GARANTIA): ");
        char input[100];
        scanf("%s", input);

        // Verificar si el input es un número
        int esNumero = 1;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                esNumero = 0;
                break;
            }
        }

        // Verificar si el número ingresado es válido (1 o 2)
        if (esNumero) {
            int opcion = atoi(input);
            if (opcion == 1) {
                strcpy(tipoCredito, "A SOLA FIRMA");
                break;
            } else if (opcion == 2) {
                strcpy(tipoCredito, "CON GARANTIA");
                break;
            }
        }

        printf("\n\nERROR, OPCION INVALIDA... INTENTE NUEVAMENTE.\n");
        system("cls");
    }
    system("cls");
}

int obtenerTotalRegistros(FILE* archivo) {
    fseek(archivo, 0, SEEK_END); // Mover el puntero al final del archivo
    long totalBytes = ftell(archivo); // Obtener la posición actual del puntero (que corresponde al tamaño total en bytes)
    int totalRegistros = totalBytes / sizeof(struct CreditoAuxiliar); // Calcular la cantidad de registros dividiendo el tamaño total entre el tamaño de un registro
    return totalRegistros;
}



void actualizarRegistrosIntermedios(FILE *ArchivoCreado, int totalRegistros, int nuevoOrden) {

    struct CreditoAuxiliar registros[totalRegistros+1]; // Agregamos uno para el nuevo registro
    nuevoOrden++;

    // Leer todos los registros del archivo
    fseek(ArchivoCreado, 0, SEEK_SET);
    fread(registros, sizeof(struct CreditoAuxiliar), totalRegistros, ArchivoCreado);

    // Desplazar los registros hacia abajo desde el último hasta el nuevo orden - 1
    int i;
    for (i = totalRegistros - 1; i >= 0; i--) {
        if (registros[i].orden < nuevoOrden) {
            break;
        }


    // Llenar el registro intermedio con valores de cero
    struct CreditoAuxiliar nuevoRegistro;

        printf(": %-4d        : %-9s  : %-9s  : %-8.2f : %-1s            : %-2d  : %-1s : %4d  :  %9d   : %-9.2f     : %-7.2f : %10.2f  : %-5d  :\n", registros->orden, registros->nombre, registros->apellido, registros->importe, registros->tipoDeCredito, registros->dia, registros->mesCad, registros->ano, registros->NroCuotas, registros->importeCuotas, registros->IVA,registros->totalCuota,registros->activo);
        printf("..................................................................................................................................................\n");



        registros[i + 1] = registros[i];
    }
/*
    registros[nuevoOrden - 1] = nuevoRegistro;

    Volver al inicio del archivo
    fread(&nuevoRegistro, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado);
    fseek(ArchivoCreado, 0, SEEK_SET);
    Escribir todos los registros actualizados en el archivo
*/
    fwrite(registros, sizeof(struct CreditoAuxiliar), totalRegistros + 1, ArchivoCreado);

}



void convertirMayusculas(char *cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        cadena[i] = toupper(cadena[i]);
        i++;
    }
}


int validarFecha(int *ultimo, int *mesent, int *dia) {
// Validar año
    if (*ultimo < 1900 || *ultimo > 2100) {
        printf("\n\nANIO INCORRECTO.\n");
        return 0;
    }

// Validar mes
    if (*mesent < 1 || *mesent > 12) {
        printf("\n\nMES INCORRECTO.\n");
        return 0;
    }

// Validar día
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int diasEnMes = diasPorMes[*mesent - 1];

// Si es febrero y el año es bisiesto, ajustar el número de días
    if (*mesent == 2 && ((*ultimo % 4 == 0 && *ultimo % 100 != 0) || *ultimo % 400 == 0)) {
        diasEnMes = 29;
    }
//dia
    if (*dia < 1 || *dia > diasEnMes) {
        printf("DIA INCORRECTO.\n");
        return 0;
    }
    return 1;
}
void convertirMes(int *mes, char mesCad[]) {
 switch (*mes) {
        case 1:
            strcpy(mesCad, "ene");
            break;
        case 2:
            strcpy(mesCad, "feb");
            break;
        case 3:
            strcpy(mesCad, "mar");
            break;
        case 4:
            strcpy(mesCad, "abr");
            break;
        case 5:
            strcpy(mesCad, "may");
            break;
        case 6:
            strcpy(mesCad, "jun");
            break;
        case 7:
            strcpy(mesCad, "jul");
            break;
        case 8:
            strcpy(mesCad, "ago");
            break;
        case 9:
            strcpy(mesCad, "sep");
            break;
        case 10:
            strcpy(mesCad, "oct");
            break;
        case 11:
            strcpy(mesCad, "nov");
            break;
        case 12:
            strcpy(mesCad, "dic");
            break;
        default:
            strcpy(mesCad, ""); // Cadena vacía para el caso de un mes inválido
            break;
    }
}

void busqueda(FILE *ArchivoCreado,char archivoBinario[]) {
    int opcion;
    printf("\nCOMO DESEA BUSCAR?:\n");
    printf("1-> POR NUMERO DE ORDEN\n");
    printf("2-> POR APELLIDO\n");
    printf("\n\nOPCION: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            buscarPorNumeroOrden(ArchivoCreado,archivoBinario);
            break;
        case 2:
            buscarPorApellido(ArchivoCreado,archivoBinario);
            break;
        default:
            printf("\n\nOPCION INVALIDA\n");
    }
}
void buscarPorNumeroOrden(FILE *ArchivoCreado,char archivoBinario[]) {
    ArchivoCreado = fopen(archivoBinario, "rb");
    if (ArchivoCreado == NULL) {
        printf("\n\nERROR AL ABRIR EL ARCHIVO.\n");
        return;
    }

    int numeroOrden;
    printf("INGRESE NUMERO DE ORDEN: ");
    scanf("%d", &numeroOrden);

    struct CreditoAuxiliar cliente;

    rewind(ArchivoCreado); // Regresar al inicio del archivo

    // Buscar el registro con el número de orden especificado
    while (fread(&cliente, sizeof(struct Creditos), 1, ArchivoCreado) == 1) {
        if (cliente.orden == numeroOrden) {
            // El registro con el número de orden especificado fue encontrado

            // Imprimir los datos del cliente encontrado
            printf("\nDATOS DEL CLIENTE OBTENIDO:\n");
            printf("ORDEN: %d\n", cliente.orden);
            printf("NOMBRE: %s\n", cliente.nombre);
            printf("APELLIDO: %s\n", cliente.apellido);
            printf("IMPORTE: %.2f\n", cliente.importe);
            printf("TIPO DE CREDITO: %.2f\n", cliente.tipoDeCredito);
            printf("FECHA: %d-%d-%d\n", cliente.dia, cliente.mesCad, cliente.ano);
            printf("NUMERO DE CUOTAS: %d\n", cliente.NroCuotas);
            printf("IMPORTE CUOTAS: %d\n", cliente.importeCuotas);
            printf("IVA: %d\n", cliente.IVA);
            printf("TOTAL CUOTA: %d\n", cliente.NroCuotas);
            printf("ACTIVO: %d\n", cliente.activo);

            fclose(ArchivoCreado); // Cerrar el archivo después de usarlo
                return; // Salir de la función después de encontrar el registro
        }
    }

    printf("NO SE ENCONTRO NINGUN CLIENTE CON EL NUMERO DE ORDEN INGRESADO.\n");

    fclose(ArchivoCreado); // Cerrar el archivo al finalizar la función
}
void buscarPorApellido(FILE *ArchivoCreado,char archivoBinario[]) {
        ArchivoCreado = fopen(archivoBinario, "rb");
    if (ArchivoCreado == NULL) {
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
        return;
    }

    char apellido[25];
    printf("\n\nINGRESE EL APELLIDO: \n");
    scanf("%s", apellido);

    convertirMayusculas(apellido);

    struct CreditoAuxiliar cliente;

    fseek(ArchivoCreado, 0, SEEK_SET);

    while (fread(&cliente, sizeof(struct Creditos), 1, ArchivoCreado) == 1) {
        if (strcmp(cliente.apellido, apellido) == 0) {
            // Imprimir los datos del cliente encontrado
            printf("\n\nDATOS DEL CLIENTE:\n");
            printf("ORDEN: %d\n", cliente.orden);
            printf("NOMBRE: %s\n", cliente.nombre);
            printf("IMPORTE: %.2f\n", cliente.importe);
            printf("FECHA: %d-%d-%d\n", cliente.dia, cliente.mesCad, cliente.ano);
            printf("NUMERO DE CUOTAS: %d\n", cliente.NroCuotas);
            // Imprimir otros campos si es necesario

            fclose(ArchivoCreado); // Cerrar el archivo después de usarlo
            return; // Salir de la función después de encontrar el registro
        }
    }

    printf("NO SE ENCONTRO UN CLIENTE CON EL APELLIDO INGRESADO.\n");

    fclose(ArchivoCreado); // Cerrar el archivo al finalizar la función
}
void modifica(FILE *ArchivoCreado, char archivoBinario[]) {
    int numeroOrden;
    char yesno;

    printf("\t\t\t\INGRESE NUMERO DE ORDEN: ");
    scanf("%d", &numeroOrden);

    // Buscar el cliente por número de orden
    struct CreditoAuxiliar cliente;
    int encontrado = 0;

    ArchivoCreado = fopen(archivoBinario, "r+b");
    if (ArchivoCreado == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("..................................................................................................................................................\n");
    printf(": %-1s  :  %-4s    : %7s   : %s  : %8s : %s :%4s :%6s :%10s : %s : %-7s : %s : %s :\n", "ORDEN", "NOMBRE", "APELLIDO", "IMPORTE", "TIPO CREDITO", "DIA", "MES", "ANIO", "NUMERO CUOTAS", "IMPORTE CUOTA", "IVA", "TOTAL CUOTA", "ACTIVO");
    printf("..................................................................................................................................................\n");

    while (fread(&cliente, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado) == 1) {
        if (cliente.orden == numeroOrden) {
            encontrado = 1;
            break;
        }

    }

    if (!encontrado) {
        printf("No se encontró un cliente con el número de orden especificado.\n");
        fclose(ArchivoCreado);
        return;
    }

    // Mostrar otros campos si es necesario
        // Mostrar los datos del cliente encontrado
        printf(": %-4d   : %-9s  : %-9s  : %-8.2f : %-1s : %-2d  : %-1s : %4d  :  %9d   : %-9.2f     : %-7.2f : %10.2f  : %-5d  :\n", cliente.orden, cliente.nombre, cliente.apellido, cliente.importe, cliente.tipoDeCredito, cliente.dia, cliente.mesCad, cliente.ano, cliente.NroCuotas, cliente.importeCuotas, cliente.IVA, cliente.totalCuota, cliente.activo);
        printf("..................................................................................................................................................\n");

    // Confirmar la modificación
    printf("\nEstá seguro que desea modificar los datos de este cliente? (S/N): ");
    fflush(stdin);
    scanf(" %c", &yesno);

    if (toupper(yesno) == 'S') {
        // Modificar los datos
        printf("\nIngrese el nuevo importe: ");
        fflush(stdin);
        scanf("%f", &cliente.importe);

        printf("Seleccione el nuevo tipo de crédito:\n");
        printf("1- A SOLA FIRMA\n");
        printf("2- CON GARANTIA\n");

        int op;
        scanf(" %d", &op);

        switch (op) {
            case 1:
                strcpy(cliente.tipoDeCredito, "A SOLA FIRMA");
                break;
            case 2:
                strcpy(cliente.tipoDeCredito, "CON GARANTIA");
                break;
            default:
                printf("OPCION INVALIDA, NO SE REALIZARON MODIFICACIONES.\n");
                fclose(ArchivoCreado);
                return;
        }

        // Escribir los datos modificados en el archivo
        fseek(ArchivoCreado, -sizeof(struct CreditoAuxiliar), SEEK_CUR);
        fwrite(&cliente, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado);
        printf("\nDATOS MODIFICADOS CORRECTAMENTE.\n");
    } else {
        printf("\nNO SE REALIZARON MODIFICACIONES.\n");
    }

    fclose(ArchivoCreado);
}

void bajaLogica(FILE *ArchivoCreado, char archivoBinario[]){
   ArchivoCreado = fopen(archivoBinario, "r+b");
    if (ArchivoCreado == NULL) {
        printf("ERROR AL ABRIR EL ARCHIVO.\n");
        return;
    }

    int numeroOrden;
    char confirmacion;

    printf("INGRESE EL NUMERO DE ORDEN QUE DESEE DAR BAJA LOGICA: ");
    scanf("%d", &numeroOrden);

    // Buscar el cliente por número de orden
    struct CreditoAuxiliar cliente;
    int encontrado = 0;
     printf("..................................................................................................................................................\n");
    printf(": %-1s  :  %-4s    : %7s   : %s  : %8s : %s :%4s :%6s :%10s : %s : %-7s : %s : %s :\n", "ORDEN", "NOMBRE", "APELLIDO", "IMPORTE", "TIPO CREDITO", "DIA", "MES", "ANIO", "NUMERO CUOTAS", "IMPORTE CUOTA", "IVA", "TOTAL CUOTA", "ACTIVO");
    printf("..................................................................................................................................................\n");

    // Buscar el cliente en el archivo
    while (fread(&cliente, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado) == 1) {
        if (cliente.orden == numeroOrden) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("NO SE ENCONTRO UN CLIENTE CON EL NUMERO DE ORDEN INGRESADO.\n");
        fclose(ArchivoCreado);
        return;
    }

     // Mostrar los datos del cliente encontrado
        printf(": %-4d   : %-9s  : %-9s  : %-8.2f : %-1s : %-2d  : %-1s : %4d  :  %9d   : %-9.2f     : %-7.2f : %10.2f  : %-5d  :\n", cliente.orden, cliente.nombre, cliente.apellido, cliente.importe, cliente.tipoDeCredito, cliente.dia, cliente.mesCad, cliente.ano, cliente.NroCuotas, cliente.importeCuotas, cliente.IVA, cliente.totalCuota, cliente.activo);
        printf("..................................................................................................................................................\n");


    // Confirmar la baja
    printf("\nESTA SEGURO QUE DESEA DAR DE BAJA AL CLIENTE? (S/N): ");
    fflush(stdin);
    scanf("%c", &confirmacion);

    if (toupper(confirmacion) == 'S') {
        // Realizar la baja lógica (marcar como inactivo)
        cliente.activo = 0;  // Marcar como inactivo cambiando el valor del campo activo

        // Escribir los datos modificados en el archivo
        fseek(ArchivoCreado, -(long)sizeof(struct CreditoAuxiliar), SEEK_CUR);
        fwrite(&cliente, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado);
        printf("\BAJA LOGICA EXITOSA!\n");
    } else {
        printf("\nNO SE REALIZARON MODIFICACIONES.\n");
    }
    system("cls");
    // Mostrar la lista de clientes activos
    printf("\n LISTA DE CLIENTES ACTIVOS:\n");
    rewind(ArchivoCreado);  // Regresar al inicio del archivo
    printf("..................................................................................................................................................\n");
    printf(": %-1s  :  %-4s    : %7s   : %s  : %8s : %s :%4s :%6s :%10s : %s : %-7s : %s : %s :\n", "ORDEN", "NOMBRE", "APELLIDO", "IMPORTE", "TIPO CREDITO", "DIA", "MES", "ANIO", "NUMERO CUOTAS", "IMPORTE CUOTA", "IVA", "TOTAL CUOTA", "ACTIVO");
    printf("..................................................................................................................................................\n");

    fread(&cliente, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado);
    while (fread(&cliente, sizeof(struct CreditoAuxiliar), 1, ArchivoCreado) == 1) {
        // Mostrar solo los clientes activos (activo = 1)
        if (cliente.activo == 1) {
            // Mostrar los datos del cliente encontrado
        printf(": %-4d   : %-9s  : %-9s  : %-8.2f : %-1s : %-2d  : %-1s : %4d  :  %9d   : %-9.2f     : %-7.2f : %10.2f  : %-5d  :\n", cliente.orden, cliente.nombre, cliente.apellido, cliente.importe, cliente.tipoDeCredito, cliente.dia, cliente.mesCad, cliente.ano, cliente.NroCuotas, cliente.importeCuotas, cliente.IVA, cliente.totalCuota, cliente.activo);
        printf("..................................................................................................................................................\n");

        }
    }

    fclose(ArchivoCreado);
}







//
