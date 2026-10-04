#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


//Estructura para el manejo de datos del tanque.
struct Tanque{
char Sector[40];
char NombreTanque[20];
int Nivel;
}*tanques;

int cantidadTanques=0;

void IngresoDeInformacion(int x);
void TanquesIngresados(int tanque);
	
//FUNCION MAIN-----------
int main() {
	
	
//declaracion de variables 
int x,i,opcion;
int tanque;
char sector[20];
char nombre[20];




do{
	printf("-----MENU PRINCIPAL-----\n\n");
	printf("1_Ingresar tanques\n");
	printf("2_Buscar/Mostrar tanques\n");
	printf("3_Mostrar los 2 tanques con menor nivel\n");
	printf("4_Salir\n");
	printf("Opcion:");
	scanf("%d",&opcion);
	
	
	switch(opcion){
	case 1:
		printf("Cantidad de tanques a ingresar:");
		scanf("%d",&x);
		IngresoDeInformacion(x);
		break;
	case 2:
		
		
		break;
	case 3:
		
		
		
		break;
	case 4:
		printf("Saliendo.....");
		break;
			
	}
} while(opcion!=4);

return (0);
}





void IngresoDeInformacion(int x)
{
	int nivel,i;
	char sector[20],nombre[20];
	int opcion;
	tanques=(struct Tanque*)realloc(tanques,(cantidadTanques+x)*sizeof(struct Tanque));
	for(i=cantidadTanques;i<(cantidadTanques+x);i++)
	{
		
		do{
			printf("Datos del tanque %d:\n",i+1);
			printf("1_Ingresar el Sector\n");
			printf("2_Ingresar el nombre del Tanque\n");
			printf("3_Ingresar el nivel del Tanque\n");
			printf("4_salir\n");
			printf("Opcion:");
			scanf("%d",&opcion);
			
			switch(opcion)
			{
			case 1:
				printf("Ingrese el Sector del tanque:");
				scanf("%s",sector);
				strcpy(tanques[i].Sector,sector);
				break;
			case 2:
				printf("Ingrese el nombre del tanque:\n");
				scanf("%s",nombre);
				strcpy(tanques[i].NombreTanque,nombre);
				break;
			case 3:
				do{
				printf("Ingrese el nivel del tanque:\n");
				scanf("%d",&nivel);
				if(nivel<0||nivel>0){
					printf("Nivel incorrecto.Intente nuevamente");
				}
				}
				while(nivel<0||nivel>100);
				
				tanques[i].Nivel=nivel;
				break;
				
			}	
		}	
		while(opcion!=4);
	}
	cantidadTanques=cantidadTanques+x;
	
}


//FUNCION DE MENOR NIVEL DE tanques
void TanquesMenorNivel(){
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
void Sector(char sector[],int x)
{
int i,valor;
char *pSector;
int tamaño;
free(pSector);
*pSector=sector;
tamaño=strlen(pSector);
pSector=realloc(pSector,tamaño*sizeof(char));
for(i=0;i<x;i++)
{
valor=strcmp(tanque1[i].Sector,tanque1[i+1].Sector);
if(valor==0)
{
	strcpy(pSector,tanque1[i+1].);
}

}
 
	
	

	
	
	
	
	

	
	

	
	


