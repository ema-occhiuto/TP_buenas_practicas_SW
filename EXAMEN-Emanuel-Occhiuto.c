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
void TanquesMenorNivel();
void BusquedadTanques();
	
//FUNCION MAIN-----------
int main() {
	
	
//declaracion de variables 
int x,opcion;



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
		if(cantidadTanques==0)
		{
			printf("Tienes que ingresar tanques\n\n\n");
			break;
		}
		
		BusquedadTanques();
		break;
	case 3:
		printf("---------Tanques con menor nivel:------------\n\n\n\n");
		TanquesMenorNivel();
		
		
		break;
	case 4:
		free(tanques);
		printf("Saliendo.....");
		break;
			
	}
} while(opcion!=4);

return (0);
}





void IngresoDeInformacion(int x)
{
	struct Tanque *ptanque;
	int nivel,i;
	char sector[20],nombre[20];
	int opcion;
	tanques=(struct Tanque*)realloc(tanques,(cantidadTanques+x)*sizeof(struct Tanque));
	for(i=cantidadTanques;i<(cantidadTanques+x);i++)
	{
		ptanque=&tanques[i];
		do{
			printf("Datos del tanque %d:\n\n",i+1);
			printf("1_Ingresar el Sector\n");
			printf("2_Ingresar el nombre del Tanque\n");
			printf("3_Ingresar el nivel del Tanque\n");
			printf("4_salir\n");
			printf("Opcion:");
			scanf("%d",&opcion);
			
			switch(opcion)
			{
			case 1:
				printf("Ingrese el Sector del tanque:\n");
				scanf("%s",sector);
				strcpy(ptanque->Sector,sector);
				break;
			case 2:
				printf("Ingrese el nombre del tanque:\n");
				scanf("%s",nombre);
				strcpy(ptanque->NombreTanque,nombre);
				break;
			case 3:
				do{
				printf("Ingrese el nivel del tanque:\n");
				scanf("%d",&nivel);
				if(nivel<0||nivel>100){
					printf("Nivel incorrecto.Intente nuevamente\n\n");
				}
				}
				while(nivel<0||nivel>100);
				
				ptanque->Nivel=nivel;
				break;
				
			}	
		}	
		while(opcion!=4);
	}
	cantidadTanques=cantidadTanques+x;
	
}


//FUNCION DE MENOR NIVEL DE tanques
void TanquesMenorNivel()
{
	int i;
	int menor1,menor2;
	//Necesitamos almenos 2 tanques
	if(cantidadTanques<2){
		printf("Debe haber almenos 2 tanques cargados\n\n\n");
		return;
	}
	//Comparamos los primeros dos tanques
	
	if(tanques[0].Nivel<tanques[1].Nivel){
		menor1=0;
		menor2=1;
	}
	else{
		menor1=1;
		menor2=0;
	}
	
	//Recorremos los tanques restantes 
	for(i=2;i<cantidadTanques;i++)
	{
		if(tanques[i].Nivel<tanques[menor1].Nivel)
		{
			menor2=menor1;
			menor1=i;
		}
		else
		{
			if(tanques[i].Nivel<tanques[menor2].Nivel)
			{
				menor2=i;
			}
		}
	}
	
	//Mostramos el tanque con menor nivel
	printf("-----Primer tanque con menor nivel:\n");
	printf("Sector: %s\n",tanques[menor1].Sector);
	printf("Nombre del tanque: %s\n",tanques[menor1].NombreTanque);
	printf("Nivel de agua:%d%%\n",tanques[menor1].Nivel);
	
	
	//mostramos el segundo
	printf("\n--- SEGUNDO TANQUE CON MENOR NIVEL ---\n");
	printf("Sector: %s\n", tanques[menor2].Sector);
	printf("Nombre del tanque: %s\n", tanques[menor2].NombreTanque);
	printf("Nivel: %d%%\n", tanques[menor2].Nivel);
	
}
	
//Funcion para la busquedad de tanques 

void BusquedadTanques()
{
	int opcionBusqueda;
	char sector[40];
	int i,nivel;
	char nombre[40];
	printf("\n----Buscar tanques-----\n");
	printf("1_Por sector\n");
	printf("2_Por nombre\n");
	printf("3_Por nivel de agua\n");
	printf("Opcion:\n\n");
	scanf("%d",&opcionBusqueda);
	
	switch(opcionBusqueda)
	{
	case 1:
		//buscar por sector
		printf("Ingrese el sector a buscar:");
		scanf("%s",sector);
		for(i=0;i<cantidadTanques;i++)
		{
			if(strcmp(tanques[i].Sector,sector)==0)
			{
				printf("Nombre:%s\n",tanques[i].NombreTanque);
				printf("Sector: %s\n",tanques[i].Sector);
				printf("Nivel:%d%%\n",tanques[i].Nivel);
			}
		}
		break;
	case 2:
		//Buscar por nombre
		printf("Ingrese el nombre del tanque a buscar:");
		scanf("%s",nombre);
		for(i=0;i<cantidadTanques;i++)
		{
			if(strcmp(tanques[i].NombreTanque,nombre)==0)
			{
				printf("Nombre: %s\n", tanques[i].NombreTanque);
				printf("Sector: %s\n", tanques[i].Sector);
				printf("Nivel: %d%%\n", tanques[i].Nivel);
			}
		}
		break;
	case 3:
		//buscar por nivel
		printf("Ingrese el nivel a buscar\n");
		scanf("%d",&nivel);
		for(i=0;i<cantidadTanques;i++)
		{
			if(tanques[i].Nivel==nivel)
			{
			printf("Nombre: %s\n", tanques[i].NombreTanque);
			printf("Sector: %s\n", tanques[i].Sector);
			printf("Nivel: %d%%\n", tanques[i].Nivel);
			}
		}
		break;
	}
}
	
	
	
	
	
	
	
	
	
	
	

