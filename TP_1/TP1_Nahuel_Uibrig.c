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
  pet_id_t mascota,mascota_masvieja;
  FILE *archivo;
  mascota_masvieja.edad=-1;
  unsigned short id_decimal=0,id_binario=0;
  /* USER CODE END Variable declaration */


  /* USER CODE BEGIN Ejercicio 1 */
  printf("\n");
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
  printf("Edad de la mascota mas vieja:%.1faños\n", mascota_masvieja.edad); 

  fclose(archivo);
  printf("\n");
  /* USER CODE END Ejercicio 1 */


  

  /* USER CODE BEGIN Ejercicio 2 */
  printf("\n");
  archivo = fopen("mascotas.dat", "rb"); 
  if (archivo == NULL) { 
      perror("Error al abrir el archivo");
      return 1;
  }
  while (fread(&mascota, sizeof(pet_id_t), 1, archivo) == 1) {
    id_decimal = (mascota.id >> 12) & 0b00001111;  // Extrae los 4 bits más significativos
    if (!((id_decimal == 1 && mascota.especie == PERRO) ||
              (id_decimal == 2 && mascota.especie == GATO) ||
              (id_decimal == 3 && mascota.especie == TORTUGA) ||
              (id_decimal == 4 && mascota.especie == CONEJO) ||
              (id_decimal == 5 && mascota.especie == PAJARO))) {
      printf("\n----------------------------------------------------------\n");
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
      printf("\n----------------------------------------------------------\n");

    }
    else{
      printf("\nNo hay nada que corregir\n");
      break;
    }
    
        
  }
  fclose(archivo);
  printf("\n");

  /* USER CODE END Ejercicio 2 */



  /* USER CODE BEGIN Ejercicio 3 */


  /* USER CODE END Ejercicio 3 */


  return 0;
}