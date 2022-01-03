#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#define MAX 20
#define VACIO 0
#define ACTIVO 1
#define BORRADO 2


struct agenda{
    char nombre [50];
    long int dni ;
    char email[25];
    char direccion [20];
    int edad ;
    int estado;
};

typedef struct agenda agenda;

void menu();

void alta(agenda diario[20]);
void baja(agenda diario[20]);
void mostrar(agenda diario[20]);
void mostrarActivos(agenda diario[20]);
void grafico(agenda diario[20]);
void buscar(agenda diario[20]);
int main()
{


    agenda diario[20];
    init(diario);

    int op = 0;
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1 : alta(diario); break;
            case 2 : baja(diario); break;
            case 3 : buscar(diario); break;
            case 4 : mostrarActivos(diario); break;
            case 5 : mostrar(diario); break;
            case 6 : grafico(diario);break;
            case 7: op=7; break;
            system("cls");
        }

    }while(op!= 7);
    return 0;
}

void menu(){
    system("color F0");
    printf("|--------------------------------------------------------------------------------------------------------------------|\n");
    printf("|                                                                                                                    |\n");
    printf("|                                       Elija una opcion del menu \a                                                   |\n");
    printf("|                                                                                                                    |\n");
    printf("|                                             1.Agregar persona                                                      |\n");
    printf("|                                                                                                                    |\n");
    printf("|                                             2.Borrar persona                                                       |\n");
    printf("|                                                                                                                    |\n");
    printf("|                                             3.Busqueda de nombre                                                   |\n");
    printf("|                                                                                                                    |\n");
    printf("|                                             4.Activos                                                              |\n");
    printf("|                                                                                                                    |\n");
    printf("|                                             5.Imprimir lista ordenada por  nombre                                  |\n");
    printf("|                                                                                                                    |\n");
    printf("|                                             6.Imprimir grafico                                                     |\n");
    printf("|                                                                                                                    |\n");
    printf("|                                             7.Salir                                                                |\n");
    printf("|                                                                                                                    |\n");
    printf("|--------------------------------------------------------------------------------------------------------------------|\n");
    printf("                                                                                                                      \n");
    printf("                                           Seleccione una opcion: " );
}

void alta(agenda diario[MAX]){
    system("cls");
    printf("                                                                                                                      \n");
    printf("                                             ___________________________                                                ");
    printf("                                            |                           |                                               ");
  printf("\n                                            |     1.Agregar persona     |                                             \n");
    printf("                                            |___________________________|                                             \n");
    for(int i = 0 ; i < MAX ; i++){
        if(diario[i].estado == VACIO){
            fflush(stdin);
            printf("\n                   -------->      Ingrese nombre y apellido : "  );

            scanf("%s" , diario[i].nombre);

            fflush(stdin);
            printf("\n                   -------->      Ingrese numero de DNI: "  );
            scanf("%ld" , &diario[i].dni);

            fflush(stdin);
            printf("\n                   -------->      Ingrese email: "  );
            scanf("%s" , &diario[i].email);

            fflush(stdin);
            printf("\n                   -------->      Ingrese direccion : "  );
            scanf("%s" , diario[i].direccion);

            fflush(stdin);
            printf("\n                   -------->      Ingrese edad : "  );
            scanf("%d" , &diario[i].edad);
            printf("\n                                      Ingresado correctamente\n ");
            printf("                                                                                                                    \n");
            system("pause");
            system("cls");

            diario[i].estado = ACTIVO;

            break;

        }
    }

}

void baja(agenda diario[MAX]){
    system("cls");
    char aux[10];
    fflush(stdin);
    printf("                                         ___________________________ \n");
    printf("                                        |                           |\n");
	printf("                                        |         2.borrado         |\n");
    printf("                                        |___________________________|\n\n");
    printf("\n                      ------->   Ingrese el nombre que quiere eliminar:   ");
    scanf("%s", aux);
    system("cls");
    for(int i=0;i <20;i++){
            if(strcmp(diario[i].nombre, aux)==0){
                diario[i].estado=BORRADO;

            }
        }
    printf("                                        ___________________________ \n\n");
    printf("                                        |                           |\n");
	printf("                                        |         Nombre borrado    |\n");
    printf("                                        |___________________________|\n\n");
}


void buscar(agenda diario[MAX]){
	char busca[20];
	int i;

	//system("cls");

	fflush(stdin);
    system("cls");
	printf("                                         ___________________________ \n");
    printf("                                        |                           |\n");
	printf("                                        |     3.Buscar contacto     |\n");
    printf("                                        |___________________________|\n\n\n\n");
    printf("                                Ingrese nombre del contacto: ");
	gets(busca);

	for(i=0;i<MAX;i++){
		if(strcmpi(busca,diario[i].nombre)==0){
			printf("\n                          Nombre del contacto: %s\n\n", diario[i].nombre);
			printf("                          DNI: %ld\n\n", diario[i].dni);
			printf("                          Email: %s\n\n", diario[i].email);
			printf("                          Direccion: %s\n\n", diario[i].direccion);
			printf("                          Edad: %d\n\n", diario[i].edad);
		}
	}
    system("pause");
    system("cls");

}

void init(agenda diario[MAX]){
    for(int i = 0 ; i < MAX ; i++){
       strcpy(diario[i].nombre,"");
       diario[i].dni = 0;
       strcpy(diario[i].email,"NULA");
       strcpy(diario[i].direccion,"NULA");
       diario[i].edad = 0;
       diario[i].estado = VACIO;
    }
}
void mostrar(agenda diario[MAX]){
    system("cls");
	int  i, j;
	char auxc[50],aux;



	for(i=0;i<MAX-1;i++){
		for(j=0;j<MAX-1-i;j++){
			if(strcmp(diario[j].nombre,diario[j+1].nombre)>0){

				strcpy(auxc,diario[j].nombre);
				strcpy(diario[j].nombre,diario[j+1].nombre);
				strcpy(diario[j+1].nombre,auxc);

				//aux = diario[j].dni;
                //diario[j].dni = diario[j+1].dni;
				//diario[j+1].dni = auxc;

				//aux = diario[j].email;
				//diario[j].email = diario[j+1].email;
				//diario[j+1].email = aux;

				//strcpy(auxc,diario[j].direccion);
				//strcpy(diario[j].direccion,diario[j+1].direccion);
				//strcpy(diario[j+1].direccion,auxc);

				//cpy(auxc,diario[j].edad);
				//strcpy(diario[j].edad,diario[j+1].edad);
				//strcpy(diario[j+1].edad,auxc);

				//strcpy(auxc,diario[j].estado);
				//strcpy(diario[j].estado,diario[j+1].estado);
				//strcpy(diario[j+1].estado,auxc);
			}
		}
	}

    printf("                                  _________________________________________________ \n ");
    printf("                                |                                                 |\n ");
    printf("                                |     5.Agenda organizada alfabeticamente         |\n ");
    printf("                                |_________________________________________________|\n \n \n ");

	for(i=0;i<MAX;i++){

            if(strcmp(diario[i].nombre, "") !=0)
        {
            printf("\n                                 ---------->    Nombre: %s\n", diario[i].nombre);
        }


		//printf("DNI: %l\n", diario[i].dni);
		//printf("E-mail: %d\n", diario[i].email);
		//printf("Dirección: %s\n", diario[i].direccion);
		//printf("Edad: %s\n", diario[i].edad);
		//printf("Estado: %s\n", diario[i].estado);
	}
        system("pause");
        system("cls");

}



void mostrarActivos(agenda diario[20]){
    system("cls");
    printf("                                          ___________________________ \n");
    printf("                                         |                           |\n");
	printf("                                         |    4.Lista de activos     |\n");
    printf("                                         |___________________________|\n\n\n");
    for(int i = 0 ; i < MAX ; i++){
        if(diario[i].estado == ACTIVO){
        printf("\nNombre del contacto: %s\n", diario[i].nombre);
        printf("DNI: %ld\n", diario[i].dni);
        printf("Email: %s\n", diario[i].email);
        printf("Direccion: %s\n", diario[i].direccion);
        printf("Edad: %d\n", diario[i].edad);
        }

    }
        system("pause");
        system("cls");
}
void grafico(agenda diario[20])
{
    system("cls");
    int i, j, mayor = 0, fila;
    int cont[3];

    printf("                                  _________________________________________________\n ");
    printf("                                |                                                 |\n ");
    printf("                                |           6. Estadisticas de edades             |\n ");
    printf("                                |_________________________________________________|\n \n \n ");
    printf("                                                 G R A F I C O                                                         \n\n\n\n");

    for (i = 0; i < 3; i++) {
        cont[i] = 0;
    }

    for (i = 0; i < MAX; i++) {
        if (diario[i].edad > 0 && diario[i].edad < 19  && diario[i].nombre!="")
        {
            cont[0]++;
        }
        else {
            if (diario[i].edad > 18 && diario[i].edad < 36   && diario[i].nombre!="")
            {
                cont[1]++;
            }
            if (diario[i].edad > 35 && diario[i].nombre!="" )
            {
                cont[2]++;
            }
        }
    }

    if (cont[0] >= cont[1] && cont[0] >= cont[2])
    {
        mayor = cont[0];
    }
    else
    {
        if (cont[1] >= cont[0] && cont[1] >= cont[2])
        {
            mayor = cont[1];
        }
        if (cont[2] >= cont[0] && cont[2] >= cont[1])
        {
            mayor = cont[2];
        }
    }
    fila = mayor;

    for (i = 0; i < mayor; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (cont[j] >= fila)
            {
                printf("  |_|_|\t");

            }
            else
            {
                printf(" \t");
            }
        }
        fila--;
        printf("\n");
    }

    printf("   <18    19<35    35>\n\n");
    system("pause");
    system("cls");


}


