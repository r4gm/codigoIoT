#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 50
void procedimiento_escribir(char direccion[]){
	FILE*fd;
	int i=0, m=0;
	char cad[N];
	fd=fopen(direccion, "w");

	if(fd==NULL){
		printf("Error al crear un archivo");
		 exit(1);
	}
	
	printf("Ingrese el numero de cadenas que desea en un rango de 1-10: "); 
	scanf("%d", &m);
	
	if(m<=10){
		fprintf(fd, "%d \n", m);
	} else{
		while(m>=10){
		printf("Ingrese el numero de cadenas que se quieren desde 1 hasta 10: ");
		scanf("%d", &m);
		}
		fprintf(fd, "%d \n", m);
		fscanf(fd, "%d", &m);
	}
	
	for(i=0; i<m; i++){
		fflush(stdin);
		printf("Dame la cadena: ");
		gets(cad);
		fputs(cad, fd);
		fputs("\n", fd);
	}
	system("cls");	
	fclose(fd);
}

char funcion_sacar_cadena(char matriz[10][N], char cad2[N], int c, int dimension[N]){
	int i=0, j=0;
	for(i=c; i<=c; i++){
		for(j=0; j<dimension[i]; j++){
		 	cad2[j]=matriz[i][j];
		}
	}
	return cad2[j];
}

void funcion_nueva_cadena(char cad2[N], int x, int y){
	int i, j=0, aux=0;

	for(i=x; i<=y; i++){
		printf("%c", cad2[i]);
	}
}

void procedimiento_dibujo(int intentos){
	switch(intentos){
	case 6:
		printf("  ____ \n");
		printf(" |    | \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf("------  \n");
	break;
	case 5:
		printf("  ____ \n");
		printf(" |    | \n");
		printf(" |    O  \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf("------  \n");
	break;
	case 4:
		printf("  ____ \n");
		printf(" |    | \n");
		printf(" |    O  \n");
		printf(" |    | \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf("------  \n");
	break;
	case 3:
		printf("  ____ \n");
		printf(" |    | \n");
		printf(" |    O  \n");
		printf(" |   /| \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf("------  \n");
	break;
	case 2:
		printf("  ____ \n");
		printf(" |    | \n");
		printf(" |    O  \n");
		printf(" |   /|\\ \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf("------  \n");
	break;
	case 1:
		printf("  ____ \n");
		printf(" |    | \n");
		printf(" |    O  \n");
		printf(" |   /|\\ \n");
		printf(" |   /     \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf("------  \n");
	break;
	case 0:
		printf("  ____ \n");
		printf(" |    | \n");
		printf(" |    O  \n");
		printf(" |   /|\\ \n");
		printf(" |   / \\  \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf(" |    \n");
		printf("------  \n");
		printf("\n");
	}
}
int main(){
	FILE *fd;
	int i=0, j=0, m=0, c=0, opc=0, x=0, y=0, intentos=6, p=0, k=0, n=0, repet=0;
	int dimension[N]={'\0'};
	char letra;
	char let[N]={'\0'};
	char cad2[N]={'\0'}, cad3[N]={'\0'};
	char matriz[10][N]={'\0'};
	char direccion[]="D:\\Cadenas\\Cadenas.txt"; //Se escribe la dirección del archivo que se cree en el equipo
	
	procedimiento_escribir(direccion);
	
	fd=fopen(direccion, "r");

	if(fd==NULL){
		printf("Error al leer  un archivo");
		return 1;
	}

	fscanf(fd, "%d", &m);
	
	for(i=0; i<=m; i++){
		if(!feof(fd)){
			fgets(cad2, N, fd);	
			dimension[i]=strlen(cad2);
		for(j=0; j<strlen(cad2)-1; j++){
		 matriz[i][j]=cad2[j];
			}
		}	
	}
	fclose(fd);
	
	printf("Deme el numero de la cadena que desea utilizar: ");
	scanf("%d", &c);
	printf("\tSeleccione una opcion"" \n");
	printf("1.Extraer una subcadena \n");
	printf("2.Jugar ahorcado \n");
	printf("Digite la opcion: ");
	scanf("%d", &opc);

	
	switch(opc){
		case 1:		
	funcion_sacar_cadena(matriz, cad2, c, dimension);
	printf("Dame la primera posicion: ");
	scanf("%d", &x);
	printf("Dame la segunda posicion: ");
	scanf("%d", &y);
	if(x<y && x<=strlen(cad2) && y<=strlen(cad2)){
	funcion_nueva_cadena(cad2, x, y);
	} else{
		printf("No se puede ejecutar porque las posiciones de la cadena son mayores\n");
		printf("El rango es de 0 a: %d", strlen(cad2));
	}
 	break;
	case 2:
	system("cls");
	printf("*********************************************************\n");
	printf("*********************************************************\n");
	printf("\tBienvenidos al juego del ahorcado\n");
	printf("*********************************************************\n");
	printf("*********************************************************\n");
	printf("\n");
	
	printf("\tTienes 6 oportunidades de fallar \n");
	printf("\n");
	
	procedimiento_dibujo(intentos);
	funcion_sacar_cadena(matriz, cad2, c, dimension);
	for(j=0; j<strlen(cad2); j++){
		if(cad2[j]==' '){
			cad3[j]=' ';
		}else{
			cad3[j]='*';
		}
		printf("%c", cad3[j]);
	}printf("\n");
	
	while(intentos != 0){
	printf("Dame una letra: ");
	scanf(" %c", &letra);
	
	for(i=0; i<strlen(let); i++){
		if(let[i]==letra){
			repet=1;
			break;
		}else{
			repet=0;
		}
	}
	n=0;
	if(repet==0){
	for(i=0; i<strlen(cad2); i++){
		if(cad2[i]==letra){
			cad3[i]=letra;
			n=1;		
			}
		}	
	} puts(cad3);
	if(repet==0 &&  n==1){
	procedimiento_dibujo(intentos);
	}
	printf("\n");
		
	if(repet==0){
		if(n==0){
			intentos=intentos-1;
			procedimiento_dibujo(intentos);	
		}
	} else{
		intentos=intentos-1;
		printf("Esa letra ya se repitio");
		printf("\n");
		procedimiento_dibujo(intentos);
	}
	let[k]=letra;
	k++;
	
	if(strcmp(cad2, cad3)==0){
		p=1;
		break;
		}	
	}
	if(intentos==0){
		printf("Lo siento haz perdido, suerte para la proxima \n");
		printf("La palabra era: ");
	} else{
		printf("Felicidades, adivinaste la palabra: ");
	}
	puts(cad2);
	break;
	default: ("Error al ingresar la opcion \n"); break;
	}

	return 0;
}