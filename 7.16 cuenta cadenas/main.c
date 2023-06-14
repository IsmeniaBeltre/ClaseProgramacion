#include <stdio.h>
#include <string.h>

void main(void) {
    char cad1[50], cad2[50], cad0[50] = "";
    int i = 0;

    printf("\nIngrese la primera cadena de caracteres: ");
    fgets(cad1, sizeof(cad1), stdin);
    printf("Ingrese la cadena a buscar: ");
    fgets(cad2, sizeof(cad2), stdin);

    cad1[strcspn(cad1, "\n")] = '\0'; // Eliminar el carácter de nueva línea en cad1
    cad2[strcspn(cad2, "\n")] = '\0'; // Eliminar el carácter de nueva línea en cad2

    strcpy(cad0, cad1);
    char *cad0_ptr = cad0;
    char *substring_ptr = strstr(cad0_ptr, cad2);

    while (substring_ptr != NULL) {
        i++;
        cad0_ptr = substring_ptr + 1;
        substring_ptr = strstr(cad0_ptr, cad2);
    }

    printf("El número de veces que aparece la segunda cadena es: %d\n", i);
}

