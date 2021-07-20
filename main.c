#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
# define tam 100

void ingresodatos(int[],char[][tam],float[],float[],int,int[],int[]);
void Mostrardatos(int[],char[][tam],float[tam],float[],int,int[tam],int[tam]);
void consultardatos(int[],char[][tam],float[tam],float[],int,int[tam],int[tam]);
void Modificardatos(int[],char[][tam],float[tam],float[],int,int[tam],int[tam]);
void guardardatos(int[],char[][tam],float[tam],float[],int,int[tam],int[tam]);
void eliminardatos(int[],char[][tam],float[tam],float[],int,int[tam],int[tam]);
void registrarvacunacion(int[],char[][tam],float[tam],float[],int,int[tam],int[tam]);


int main(void) {
  int op,edad[tam];
  char nombre [tam][tam];
  float igg[tam],igm[tam];
int c_pacientes,vacunacion[tam],cedula[tam];
  do{
    printf(" 1. Ingresar datos del paciente \n 2. Mostrar datos del paciente \n 3. Consultar dato especifico \n 4. Modificar Datos de paciente \n 5. Eliminar datos de paciente\n 6. Registrar Vacunacion \n 7. Salir.");

    printf("\n Seleccione una opcion:");
    scanf("%d",&op);

  switch(op){
    case 1:
      do{
      printf("Ingrese la cantidad de pacientes a registrar: ");
      scanf("%d",&c_pacientes);
      } while(c_pacientes <= 0);

      ingresodatos(edad,nombre,igg,igm,c_pacientes,vacunacion,cedula);
      getchar();
      system("clear");

    break;

    case 2:
      Mostrardatos(edad,nombre,igg,igm,c_pacientes,cedula,vacunacion);
      getchar();
     
    break;

    case 3:
      consultardatos(edad ,nombre,igg,igm,c_pacientes,vacunacion,cedula);
    break;

    case 4:
      Modificardatos(edad ,nombre,igg,igm,c_pacientes,vacunacion,cedula);
      getchar();
      system("clear");
    break;

    case 5:
      eliminardatos(edad ,nombre,igg,igm,c_pacientes,vacunacion,cedula);
      getchar();
      system("clear");
    break;

    case 6:
      registrarvacunacion(edad ,nombre,igg,igm,c_pacientes,vacunacion,cedula);
      getchar();
      system("clear");
    break;

    case 7:
      printf("Fin del programa.\n");
      getchar();
      system("clear");
    break;

    default:
      printf("Opcion invalida, intente nuevamente.\n");
    break;
    }
  }while(op != 7);
  return 0;
}

void guardardatos(int edad[tam],char nombre[][tam],float igg[tam],float igm[tam],int c_pacientes,int cedula[tam],int vacunacion[tam]){
int cont;
FILE * archivo;

archivo = fopen("Notas.txt","a");
for(cont=0;cont<c_pacientes;cont++){
  fprintf(archivo,"\nNombre:%s\n",nombre[cont]);
  fprintf(archivo,"Edad:%d\n",edad[cont]);
  fprintf(archivo,"Valor IGG:%f\n",igg[cont]);
  fprintf(archivo,"Valor IGM:%f\n",igm[cont]);
  fprintf(archivo,"Cedula: %d\n",cedula[cont]);
  if(igg[cont]==1){
    fprintf(archivo,"Analisis IGG: %s\n","POSITIVO\n");
  }
  if(igg[cont]==0){
    fprintf(archivo,"Analisis IGG: %s\n","NEGATIVO");
  }
  else if(igg[cont]!= 0 || igg[cont]!= 1){
  fprintf(archivo,"Dato Ingresado Incorrectamente");
  }

  if(igm[cont]==1){
    fprintf(archivo,"Analisis IGM: %s\n","POSITIVO\n");
  }
  if(igm[cont]==0){
    fprintf(archivo,"Analisis IGM: %s\n","NEGATIVO");
  }
  else if(igm[cont]!= 0 || igm[cont]!= 1){
  fprintf(archivo,"Dato Ingresado Incorrectamente\n");
  }
if(vacunacion[cont]==1){
  fprintf(archivo,"Vacuna Aplicada: Pfizer\n");
}
if(vacunacion[cont]==2){
  fprintf(archivo,"Vacuna Aplicada: Astra-Zeneca\n");
}
if(vacunacion[cont]==3){
  fprintf(archivo,"Vacuna Aplicada: Sinovac\n");
}
if(vacunacion[cont]<1 || vacunacion [cont] >3){
  fprintf(archivo,"No Se Pudo Reconocer la Vacuna\n");
}
}
fclose(archivo);
}

void ingresodatos(int edad[tam],char nombre[][tam],float igg[tam],float igm[tam],int c_pacientes, int vacunacion[tam],int cedula[tam]){
int cont,nDigits[tam];
int fecha[tam],vacuna[tam];
char estado[tam];

for(cont=0;cont<c_pacientes;cont++){
  
printf(" Paciente %d\n",cont+1);
getchar();
  printf("Ingrese Nombre :\n");
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


  printf("Ingrese el resultado del valor IGG de %s (0.-Negativo; 1.-Positivo)",nombre[cont]);
  scanf("%f",&igg[cont]);


  printf("Ingrese el resultado del valor IGM de %s (0.-Negativo; 1.-Positivo)",nombre[cont]);
  scanf("%f",&igm[cont]);


printf("Se encuentra %s vacunado contra el COVID-19 ? (1 Si / 2 No)",nombre[cont]);
scanf("%d",&vacunacion[cont]);



//}while(vacunacion[cont] != 1 || vacunacion[cont] != 2);
if(vacunacion[cont] == 1){
  
  getchar();
  printf("Ingrese nombre de la vacuna aplicada a %s: 1. Pfizer 2. Astrazeneca 3. Sinovac\n",nombre[cont]);
  scanf("%d",&vacuna[cont]);
  
}
else if(vacunacion[cont] == 2){
  printf("%s Ha sido registrado como no vacunado.",nombre[cont]);
}}
guardardatos(edad,nombre,igg,igm,c_pacientes,cedula,vacunacion);
}

void consultardatos(int edad [],char nombre[][tam],float igg[tam],float igm[tam],int c_pacientes,int vacunacion[tam],int cedula[tam]){

int cont,bandera;
char busqueda[tam][tam];

getchar();

 printf("Ingrese Nombre del Paciente a buscar:");
 fgets(busqueda[cont],tam,stdin);

for(cont=0;cont<c_pacientes;cont++){
  

  if(strcmp(busqueda[cont],nombre[cont])==0){
    printf("Datos %s\n",nombre[cont]);
    printf("Edad: %d\n",edad[cont]);
    printf("IGG:%f\n",igg[cont]);
    printf("IGM:%f\n",igg[cont]);
    printf("Cedula:%d\n",cedula[cont]);
    
    //printf("Vacuna Aplicada: %s",vacunacion[cont]);
    bandera = 1;
    break;
  }
  else{printf("Registro No Encontrado :");
  }
}
guardardatos(edad,nombre,igg,igm,c_pacientes,cedula,vacunacion);
}

void analizarigg(int edad[tam],char nombre[tam][tam],float igg[tam],float igm[tam],int c_pacientes){
FILE * archivo;
archivo = fopen("Notas.txt","a");

int cont;
for(cont=0;cont<c_pacientes;cont++){
}
}

void registrarvacunacion(int edad[tam],char nombre[tam][tam],float igg[tam],float igm[tam],int c_pacientes,int vacunacion[tam],int cedula[tam]){
  
  int cont;
  char vac[tam];
  char beneficiario[tam];
  int edad_v[tam];
   
do{
  do{
    printf("Ingrese edad, valores entre 1 y 116");
    scanf("%d",&edad_v[cont]);
  }while(edad_v[cont]<=0 || edad_v[cont]>=116);

  printf("Ingrese nombre del paciente:");
  fgets(beneficiario,tam,stdin);

  printf("Ingrese Vacuna aplicada a %s",nombre[cont]);
  fgets(vac,tam,stdin);
// faltan Validaciones. 
  }while(edad_v[cont]!=0);
  guardardatos(edad,nombre,igg,igm,c_pacientes,cedula,vacunacion);
}

void Mostrardatos(int edad[tam],char nombre[][tam],float igg[tam],float igm[tam],int c_pacientes, int vacunacion[tam],int cedula[tam]){
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

else if (archivo == NULL) {
  printf("El Archivo No existe.\n");
}

analizarigg(edad,nombre,igg,igm,c_pacientes);
guardardatos(edad,nombre,igg,igm,c_pacientes,cedula,vacunacion);
fclose(archivo);
}

void eliminardatos(int edad[tam],char nombre[tam][tam],float igg[tam],float igm[tam],int c_pacientes,int vacunacion[tam],int cedula[tam]){

int cont,bandera;
char elim [tam][tam];
getchar();
printf("Ingrese el dato que desea eliminar:");
fgets(elim[cont],tam,stdin);
for(cont=0;cont<c_pacientes;cont++){
  if(strcmp(nombre[cont],elim[cont])==0){
    FILE * file = fopen("Notas.txt","w");
    fprintf(file,"-");
    //
    if(file==NULL){
      printf("El registro ha sido eliminado !");
    }
    else{
      printf("Ha habido un error en la eliminacion del archivo, intenta de nuevo mas tarde !");
    }
bandera = 1;
  }
  else{
    printf("El registro que intentas eliminar no existe !");
  }
}
guardardatos(edad,nombre,igg,igm,c_pacientes,cedula,vacunacion);
}

void Modificardatos(int edad[tam],char nombre[tam][tam],float igg[tam],float igm[tam],int c_pacientes,int vacunacion[tam],int cedula[tam]){

int cont,n_digitos[tam];
char modificar[tam][tam];
for(cont=0;cont<c_pacientes;cont++){
  do{
    getchar();
  printf("Ingrese nombre del que desea modificar datos: ");

 fgets(modificar[cont],tam,stdin);
  } while(modificar[cont] == NULL);
do{
  printf("Ingrese la cedula modificada del paciente:");
  scanf("%d",&cedula[cont]);
  n_digitos[cont] = floor(log10(abs(cedula[cont]))) + 1;

}while(n_digitos[cont]<10 || n_digitos[cont]>10);

do{
printf("Ingrese edad de %s",nombre[cont]);
scanf("%d",&edad[cont]);
} while(edad[cont]<=0 || edad[cont]>100);

printf("Ingrese el valor IGG de %s",nombre[cont]);
scanf("%f",&igg[cont]);
printf("Ingrese el valor IGM de %s",nombre[cont]);
scanf("%f",&igm[cont]);


printf("Se encuentra %s vacunado contra el COVID-19?1 si/ 2 no",nombre[cont]);
scanf("%d",&vacunacion[cont]);
}
guardardatos(edad,nombre,igg,igm,c_pacientes,cedula,vacunacion);
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
