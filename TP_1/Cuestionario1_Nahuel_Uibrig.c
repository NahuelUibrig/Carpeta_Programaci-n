/*  Trabajo Practico Nro 1
 *    Temas: Mascaras, structs, unions
 *
 * 
 */


/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

typedef enum{
  PERRO   = 1,
  GATO    = 2,
  TORTUGA = 3,
  CONEJO  = 4,
  PAJARO  = 5
}especie_t;

typedef enum{
  MAIL = 1,
  TELEFONO,
  CELULAR
}contacto_t;

typedef struct{
  especie_t especie;
  char nombre[20];
  char sexo;
  float edad;
  unsigned short id;
  contacto_t tipo_contacto;
  union contacto{
    char mail[50];
    unsigned long long telefono;
    unsigned long long celular ;
  }contacto;
}pet_id_t;

int main(void){

  /* USER CODE BEGIN Variable declaration */
  pet_id_t mascota,mascota_masvieja,buscar;
  FILE *archivo,*temp;
  mascota_masvieja.edad=-1;
  unsigned short id_decimal=0;
  int errores=0,especie_ingresada,encontrada = 0,macho=0,hembra=0;
  char especie_palabra[10];
  /* USER CODE END Variable declaration */


  /* USER CODE BEGIN Ejercicio 1 */
  printf("----------------------------------------------------------------------------------\n\n");
  printf("Ejercicio 1:\n\n");
  archivo = fopen("mascotas.dat", "rb"); 
  if (archivo == NULL) { 
      perror("Error al abrir el archivo");
      return 1;
  }
  while (fread(&mascota, sizeof(pet_id_t), 1, archivo) == 1) {
    
    if (mascota.edad > mascota_masvieja.edad) {
        mascota_masvieja = mascota; 
    }    
  }
  printf("Nombre de la mascota mas vieja: %s\n", mascota_masvieja.nombre); 
  printf("Contacto de la mascota mas vieja: ");
        switch (mascota_masvieja.tipo_contacto) {
            case MAIL:
                printf("%s (Correo Electrónico)\n", mascota_masvieja.contacto.mail);
                break;
            case TELEFONO:
                printf("%llu (Teléfono)\n", mascota_masvieja.contacto.telefono);
                break;
            case CELULAR:
                printf("%llu (Celular)\n", mascota_masvieja.contacto.celular);
                break;
            default:
                printf("Desconocido\n");
        }
  printf("Edad de la mascota mas vieja: %.faños\n", mascota_masvieja.edad); 
  fclose(archivo);
  
  /* USER CODE END Ejercicio 1 */


  

  /* USER CODE BEGIN Ejercicio 2 */
  printf("\n");
  printf("----------------------------------------------------------------------------------\n\n");
  printf("Ejercicio 2:\n\n");
  archivo = fopen("mascotas.dat", "rb"); 
  if (archivo == NULL) { 
      perror("Error al abrir el archivo");
      return 1;
  }

  temp = fopen("temp.dat", "wb");
  if (temp == NULL) { 
      perror("Error al crear el archivo temporal");
      fclose(archivo);
      return 1;
    }
  printf("----------------------------Mascotas con ID incorrecto----------------------------\n\n");  
  printf("Nombre         Especie        ID Decimal        ID Binario\n\n");
  while (fread(&mascota, sizeof(pet_id_t), 1, archivo) == 1) {
    id_decimal =mascota.id >> 13;  // Extrae los 3 bits más significativos
    if (id_decimal != mascota.especie) {
      
      printf("%-15s", mascota.nombre); 

      switch (mascota.especie) {
        case PERRO:
            printf("Perro          ");
            break;
        case GATO:
            printf("Gato           ");
            break;
        case TORTUGA:
            printf("Tortuga        ");
            break;
         case CONEJO:
            printf("Conejo         ");
            break;
        case PAJARO:
            printf("Pajaro         ");
             break;
         default:
            printf("Desconocido    ");
      }
    
      printf("%-5d", mascota.id);
      printf("             ");
      for (int i = 2; i >= 0; i--) {
      printf("%d", (mascota.id >> i) & 1);  // Imprime cada bit de los 3 bits más significativos
      }

      mascota.id = ((mascota.especie & 0b000000000111) << 13) | (mascota.id & 0b0000111111111111);
      errores++;
      printf("\n");
    }
    fwrite(&mascota, sizeof(pet_id_t), 1, temp);
  }
  if(errores==0){
      printf("N/A            N/A            N/A               N/A\n");
    }
  fclose(archivo);
  fclose(temp);
  if (remove("mascotas.dat") == 0) {
    if (rename("temp.dat", "mascotas.dat") == 0) {
    } 
    else {
      perror("Error al renombrar el archivo temporal");
      return 1;
    }
  } 
  else {
    perror("Error al eliminar el archivo original");
    return 1;
  }
  /* USER CODE END Ejercicio 2 */



  /* USER CODE BEGIN Ejercicio 3 */
  printf("\n");
  printf("----------------------------------------------------------------------------------\n");
  printf("Ejercicio 3:\n\n");

  archivo = fopen("mascotas.dat", "rb"); 
  if (archivo == NULL) { 
      perror("Error al abrir el archivo");
      return 1;
  }
  printf("Ingrese la especie que desea buscar, opciones:\n");
  printf("PERRO\nGATO\nTORTUGA\nCONEJO\nPAJARO\n");
  scanf("%s", especie_palabra);
  printf("\nEspecie ingresada: %s\n", especie_palabra);
  if (strcmp(especie_palabra, "PERRO") == 0) {
    especie_ingresada = PERRO;
  } else if (strcmp(especie_palabra, "GATO") == 0) {
    especie_ingresada = GATO;
  } else if (strcmp(especie_palabra, "TORTUGA") == 0) {
    especie_ingresada = TORTUGA;
  } else if (strcmp(especie_palabra, "CONEJO") == 0) {
    especie_ingresada = CONEJO;
  } else if (strcmp(especie_palabra, "PAJARO") == 0) {
    especie_ingresada = PAJARO;
  } else {
    printf("Especie ingresada incorrecta\n");
    fclose(archivo);
    return 1;
  }
  printf("\n---------------------------------Mascotas encontradas----------------------------------\n\n");

  printf("Nombre         Edad        Sexo        ID\n\n");
  while (fread(&buscar, sizeof(pet_id_t), 1, archivo) == 1) {
    if(buscar.especie==especie_ingresada){
      printf("%-15s", buscar.nombre); 
      printf("%-12.1f", buscar.edad);
      printf("%-12c", buscar.sexo);
      printf("%-10hu", buscar.id);
      printf("\n");
      encontrada++;
    }
  
  }
  if(encontrada==0){
    printf("\nNo se encontraron mascotas de esa especie\n");
  }
  printf("--------------------------------------------------------------------------------------\n");
  printf("\n");
  fclose(archivo);
  printf("----------------------------------------------------------------------------------\n");
  printf("Cuestionario:\n\n");
  archivo = fopen("mascotas.dat", "rb"); 
  if (archivo == NULL) { 
      perror("Error al abrir el archivo");
      return 1;
  }

  while (fread(&buscar, sizeof(pet_id_t), 1, archivo) == 1) {
    if(buscar.sexo=='M'){
      macho++;
    }
    else
    hembra++;
  }
  printf("%d Machos\n", macho);
  printf("%d Hembras\n", hembra);



  fclose(archivo);

  /* USER CODE END Ejercicio 3 */


  return 0;
}