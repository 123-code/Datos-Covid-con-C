#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
# define tam 100

void ingresodatos(int[],char[tam][tam],float[],int,int[],int[]);
void Mostrardatos(int[],char[tam][tam],float[tam],int,int[tam]);
void consultardatos(int[],char[tam][tam],float[tam],int,int[tam]);
void Modificardatos(int[],char[tam][tam],float[tam],int,int[tam]);
void eliminardatos(int[],char[tam][tam],float[tam],int,int[tam]);
void registrarvacunacion(int[],char[tam][tam],float[tam],int,int[tam]);


int main(void) {
  int op,edad[tam];
  char nombre [tam][tam];
  float igg[tam];
int c_pacientes,vacunacion[tam],cedula[tam];
  do{
  printf(" 1. Ingresar datos del paciente \n 2. Mostrar datos del paciente \n 3. consultar dato especifico \n 4. Modificar Datos de paciente \n 5. Eliminar datos de paciente\n 6. Registrar Vacunacion \n 7. Salir.");

  printf("\n Escoger una opcion:");
  scanf("%d",&op);

  switch(op){
    case 1:
    do{
    printf("Ingrese la cantidad de pacientes a registrar:");
    scanf("%d",&c_pacientes);
    } while(c_pacientes <= 0);

    ingresodatos(edad ,nombre,igg,c_pacientes,vacunacion,cedula);
    getchar();
    system("clear");

    break;

    case 2:
    Mostrardatos(edad,nombre,igg,c_pacientes,vacunacion);
    getchar();
     system("clear");
    break;

    case 3:
consultardatos(edad ,nombre,igg,c_pacientes,vacunacion);
getchar();
 system("clear");
break;

   case 4:

Modificardatos(edad ,nombre,igg,c_pacientes,vacunacion);
getchar();
 system("clear");
break;

case 5:
eliminardatos(edad ,nombre,igg,c_pacientes,vacunacion);
getchar();
 system("clear");
break;

case 6:
registrarvacunacion(edad ,nombre,igg,c_pacientes,vacunacion);
getchar();
 system("clear");
break;

case 7:
printf("Fin del programa.");
getchar();
 system("clear");
break;

default:
printf("Opcion invalida, intente nuevamente.");

break;

  }
  }while(op != 7);
  return 0;
}

void guardardatos(int edad[tam],char nombre[tam][tam],float igg[tam],int c_pacientes){
int cont;
FILE * archivo;

archivo = fopen("Notas.txt","w+");
for(cont=0;cont<c_pacientes;cont++){
  fprintf(archivo,"Nombre:%s\n",nombre[cont]);
  fprintf(archivo,"Edad:%d\n",edad[cont]);
  fprintf(archivo,"Valor Igg:%f\n",igg[cont]);
 
}
fclose(archivo);
}

void ingresodatos(int edad[tam],char nombre[tam][tam],float igg[tam],int c_pacientes, int vacunacion[tam],int cedula[tam]){
int cont,nDigits[tam];
int fecha[tam];
char estado[tam],vacuna[tam];

for(cont=0;cont<c_pacientes;cont++){
  printf("Paciente %d\n:",cont+1);


printf("Ingrese el nombre:\n");
fgets(nombre[cont],tam,stdin);


do{

  
  printf("Ingrese la cedula del paciente:");
  scanf("%d",&cedula[cont]);
  nDigits[cont] = floor(log10(abs(cedula[cont]))) + 1;

}while(nDigits[cont]<10 || nDigits[cont]>10);

do{
printf("Ingrese edad de %s",nombre[cont]);
scanf("%d",&edad[cont]);
} while(edad[cont]<=0 || edad[cont]>100);

printf("Ingrese el valor Igg de %s",nombre[cont]);
scanf("%f",&igg[cont]);
}

printf("Se encuentra %s vacunado contra el COVID-19?1. si/2. no",nombre[cont]);
scanf("%d",&vacunacion[cont]);


//}while(vacunacion[cont] != 1 || vacunacion[cont] != 2);
if(vacunacion[cont] == 1){
  
  printf("Ingrese nombre de la vacuna aplicada a %s: ",nombre[cont]);
  fgets(vacuna,tam,stdin);
  
  printf("Ingrese fecha de vacunacion de %s:",nombre[cont]);
  fgets(fecha,tam,stdin);

}
else if(vacunacion[cont] == 2){
  printf("%s Ha sido registrado como no vacunado.",nombre[cont]);

  
}
guardardatos(edad,nombre,igg,c_pacientes);
}



void consultardatos(int edad[tam],char nombre[tam][tam],float igg[tam],int c_pacientes,int vacunacion[tam]){

int cont,bandera;
char busqueda[tam][tam];
getchar();
printf("Ingrese Nombre A buscar:");
fgets(busqueda[cont],tam,stdin);

for(cont=0;cont<c_pacientes;cont++){
  if(strcmp(nombre[cont],busqueda[cont])==0){
    printf("datos %s\n",nombre[cont]);
printf("Edad: %d\n",edad[cont]);
printf("Igg:%f",igg[cont]);
bandera = 1;
break;
  }
  if(bandera == 0){
    printf("Registro No encontrado :(");

  }
}
guardardatos(edad,nombre,igg,c_pacientes);
}

void analizarigg(int edad[tam],char nombre[tam][tam],float igg[tam],int c_pacientes){

int cont;
for(cont=0;cont<c_pacientes;cont++){
  
}
}

void registrarvacunacion(int edad[tam],char nombre[tam][tam],float igg[tam],int c_pacientes,int vacunacion[tam]){
  
   int cont;
    char vac[tam];
    char beneficiario[tam];
   int edad_v[tam];
   
do{
  do{
    printf("ingrese edad, valores entre 1 y 99");
    scanf("%d",&edad_v[cont]);
  }while(edad_v[cont]<=0 || edad_v[cont]>=100);

    printf("Ingrese nombre del paciente:");
    fgets(beneficiario,tam,stdin);

    printf("Ingrese Vacuna aplicada a %s",nombre[cont]);
    fgets(vac,tam,stdin);
// faltan Validaciones. 
}while(edad_v[cont]!=0);
guardardatos(edad,nombre,igg,c_pacientes);
}

void Mostrardatos(int edad[tam],char nombre[tam][tam],float igg[tam],int c_pacientes,int cedula[tam]){
FILE * archivo;
char c;
archivo = fopen("Notas.txt","r");

if(archivo != NULL){
  printf("\n Contenido del Archivo\n");
 while(1){

	c = fgetc(archivo);		
			if(feof(archivo))		
			break;
			printf("%c", c);
 }
}

else{
  printf("El Archivo No existe.");

}
fclose(archivo);
guardardatos(edad,nombre,igg,c_pacientes);
}

void eliminardatos(int edad[tam],char nombre[tam][tam],float igg[tam],int c_pacientes,int vacunacion[tam]){

int cont,bandera;
char elim [tam][tam];

printf("Ingrese dato que desea eliminar:");
fgets(elim[cont],tam,stdin);
for(cont=0;cont<c_pacientes;cont++){
  if(strcmp(nombre[cont],elim[cont])==0){
    FILE * archivo;
    archivo = fopen("Notas.txt","w+");
    // falta realizar eliminacion del archivo. 
    
bandera = 1;
  }
  else{
if(bandera == 0){
    printf("El registro que intentas eliminar no existe !");
    }
  }
}
guardardatos(edad,nombre,igg,c_pacientes);
}

void Modificardatos(int edad[tam],char nombre[tam][tam],float igg[tam],int c_pacientes,int vacunacion[tam]){

int cont;
char modificar[tam][tam];
for(cont=0;cont<c_pacientes;cont++){
  do{
  printf("Ingrese nombre del que desea modificar datos: ");
 fgets(modificar[cont],tam,stdin);
  } while(modificar[cont] == NULL);

}
}


void leedatos(){
  int c,cont;
  FILE * archivo;
  archivo = fopen("Notas.txt","r");
if(archivo != NULL){
printf("Imprimiendo registro de pacientes..\n");
while(1){
c = fgetc(archivo);
if(feof(archivo)){
  break;
}
}
printf("%c",c);
}
else{
  printf("Ha habido un error Imprimiendo el registro, intente de nuevo mas tarde!!");
}
fclose(archivo);

}
