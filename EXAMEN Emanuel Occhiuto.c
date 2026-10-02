#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>



struct Tanque{
char Sector[40];
char NombreTanque[20];
int Nivel;
}*tanque1;

void IngresoDeInformacion(int x);
void TanquesIngresados(int tanque);
	

int main() {
int x,i,n;
int tanque;
char sector[20];
char nombre[20];
	
printf("Cantidad de tanques a ingresar:");
scanf("%d",&x);
IngresoDeInformacion(x);

printf("Informacion de tanques ingresados:\n\n");
printf("1_Por sector\n");
printf("2_Por nombre\n");
printf("3_Por nivel\n");
printf("Ingrese el n:");
scanf("%d",&n);
switch(n)
{
case 1:
	printf("Por sector:/n");
	for(i=0;i<x;i++)
	{
		printf("%s\n",tanque1[i].Sector);
	}
	printf("Ingrese el sector:");
	scanf("%s",sector);
	Sector(sector,x);
	break;
case 2:
	printf("Por nombre\n");
	for(i=0;i<x;i++)
	{
		printf("%s",tanque1[i].NombreTanque);
	}
	printf("Ingrese el nombre del tanque:");
	scanf("%s",nombre);
	Nombre(nombre);
	break;
case 3:
	printf("Por nivel:\n");
	for(i=0;i<x;i++)
	{
		printf("%d\n",tanque1[i].Nivel);
	}
	printf("Ingrese el NIvel:")
	scanf("%d",&nivel);
	break;
}
	






}





void IngresoDeInformacion(int x)
{
	int nivel,i;
	char sector[20],nombre[20];
	int opcion;
	tanque1=(struct Tanque*)malloc(x*sizeof(struct Tanque));
	for(i=0;i<x;i++)
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
				strcpy(tanque1[i].Sector,sector);
				break;
			case 2:
				printf("Ingrese el nombre del tanque:\n");
				scanf("%s",nombre);
				strcpy(tanque1[i].NombreTanque,nombre);
				break;
			case 3:
				printf("Ingrese el nivel del tanque:\n");
				scanf("%d",&nivel);
				tanque1[i].Nivel=nivel;
				break;
			}
			
		}	
		while(opcion!=4);
	}
	
}
void Sector(char sector,int x)
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
 
	
	

	
	
	
	
	

	
	

	
	


