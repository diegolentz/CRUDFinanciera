#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED




void bienvenido();//mensaje bienvenida

void leerDatosCSV(FILE *archivo);//imprime los datos del archivo.csv
void leer(char *linea,int *orden, char *nombre,float *importe,char *tipoCredito,int *dia, int *mes ,int *ano ,int *nroCutoas, float *importeCuotas ,float *IVA, float *totalCuotas);//lee los datos del archivo.csv
void crearArchivo(FILE *ArchivoCreado,char archivoBinario[]);//crea archivo binario

void migrar(FILE *archivo,FILE *archivoCreado,char archivoBinario[]);//migra los datos del archivo.csv a creditos.dat
void mayusculizador(char *mayus);//mayusculiza algunos campos

void imprimirActivos(FILE *ArchivoCreado, char archivoBinario[]);//imprime solo los activos
void imprimirTodo(FILE *ArchivoCreado,char archivoBinario[]);//imprime todos los clientes del archivo binario

//void filtrarporcredito(FILE *ArchivoCreado);//imprime por tipo de credito
void limpiarBuffer();
void obtenerpalabra(char palabra[]);//pide al usuario que elija la palabra para filtrar
void leerArchivoBinario(FILE *ArchivoCreado, char palabra[]);//lee archivo y busca segun la palabra seleccionada

void obtenerrango(float *menorvalor,float *mayorvalor);//solicita al usuario que ingrese rango de busqueda
void filtrocash(FILE *ArchivoCreado,float *menorvalor,float *mayorvalor,char palabra[]);//filtra segun rango

void registrarCliente(FILE *ArchivoCreado,char archivoBinario[]);//registra cliente
int verificarExistenciaOrden(FILE *ArchivoCreado,int orden,char arcivoBinario[]);//valida si el nro orden existe
int validarEnteroPositivo(int valor,char palabra[]);//valida que sea entero positivo
int validarFlotantePositivo(float valor);//valida que sea float positivo
void obtenerTipoCredito(char tipoCredito[]);//obtiene tipo de credito
void obtenerFecha(struct CreditoAuxiliar* cliente);//obtiene fecha
void obtenerFechad(struct CreditoAuxiliar* cliente);//obtiene dia
void obtenerFecham(struct CreditoAuxiliar* cliente);//obtiene mes
void obtenerFechaa(struct CreditoAuxiliar* cliente);//obtiene ano
void obtenerNombre(struct CreditoAuxiliar* cliente);//obtiene nombre
void obtenerApellido(struct CreditoAuxiliar* cliente);//obtiene apellido
void calcularCuotaIVA(struct CreditoAuxiliar* cliente);//calcula iva
int obtenerTotalRegistros(FILE* archivo);//calcula todos los registros

//void limpiarRegistro(struct CreditoAuxiliar *registro);
void actualizarRegistrosIntermedios(FILE* ArchivoCreado, int totalRegistros, int nuevoOrden);//agrega ceros entre cliente y cliente
void convertirMayusculas(char *cadena);//convierte a mayuscula
int validarFecha(int *ultimo, int *mesent, int *dia);//valida fecha

void busqueda(FILE *ArchivoCreado,char archivoBinario[]);//pide que elija como buscar
void buscarPorNumeroOrden(FILE *ArchivoCreado,char archivoBinario[]);//busca por numero de orden
void buscarPorApellido(FILE *ArchivoCreado,char archivoBinario[]);//busca por apellido

void modifica(FILE *ArchivoCreado,char archivoBinario[]);//modifica datos en el bin

void bajaLogica(FILE *ArchivoCreado, char archivoBinario[]);//coloca en 0 el campo activo
#endif
