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
  int errores=0,especie_ingresada,encontrada = 0;
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
  printf("Nombre de la mascota mas vieja:%s\n", mascota_masvieja.nombre); 
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
  printf("Edad de la mascota mas vieja:%.faños\n", mascota_masvieja.edad); 
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

  while (fread(&mascota, sizeof(pet_id_t), 1, archivo) == 1) {
    id_decimal = (mascota.id >> 12) & 0b000000001111;  // Extrae los 4 bits más significativos
    if (!((id_decimal == 1 && mascota.especie == PERRO) ||
              (id_decimal == 2 && mascota.especie == GATO) ||
              (id_decimal == 3 && mascota.especie == TORTUGA) ||
              (id_decimal == 4 && mascota.especie == CONEJO) ||
              (id_decimal == 5 && mascota.especie == PAJARO))) {
      printf("\n----------------------------Mascotas con ID incorrecto------------------------------\n");
      printf("Nombre:%s", mascota.nombre); 

      switch (mascota.especie) {
        case PERRO:
            printf("   Especie Perro    ");
            break;
        case GATO:
            printf("   Especie Gato    ");
            break;
        case TORTUGA:
            printf("   Especie Tortuga    ");
            break;
         case CONEJO:
            printf("   Especie Conejo    ");
            break;
        case PAJARO:
            printf("   Especie Pajaro    ");
             break;
         default:
            printf("   Desconocido");
      }
    
      printf("ID dec:%d", id_decimal);
      printf("ID bin:");
      for (int i = 3; i >= 0; i--) {
      printf("%d", (id_decimal >> i) & 1);  // Imprime cada bit de los 4 bits más significativos
      }    
      printf("\n----------------------------Mascotas con ID incorrecto------------------------------\n");
      printf("\nSe corregira el ID de: %s", mascota.nombre);
      mascota.id = ((mascota.especie & 0b000000001111) << 12) | (mascota.id & 0b0000111111111111);
      errores++;
    }
    // Mostrar el ID corregido o el original si está correcto----------------------------------------------------------------------------------------------
    printf("ID Corregido: %hu\n", mascota.id);
    fwrite(&mascota, sizeof(pet_id_t), 1, temp);
  }
  if(errores==0){
      printf("Todos los IDs son correctos\n");
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
  printf("Especie ingresada: %s\n", especie_palabra);
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
  
  printf("\nMascotas encontradas:\n");
  
  while (fread(&buscar, sizeof(pet_id_t), 1, archivo) == 1) {
    if(buscar.especie==especie_ingresada){
      printf("Edad:%0.f\n", buscar.edad); 
      printf("Nombre:%s\n", buscar.nombre); 
      printf("Sexo:%c\n", buscar.sexo);
      printf("ID:%hu\n", buscar.id);
      printf("\n                               \n");
      encontrada++;
    }
  
  }
  if(encontrada==0){
    printf("\nNo se encontraron mascotas de esa especie\n");
  }

  fclose(archivo);

  /* USER CODE END Ejercicio 3 */


  return 0;
}