#include <stdio.h>

int main() {
    printf("El programa obtiene el gasto promedio de litro por kilometro recorrido con respecto a su precio.\n");
    printf("Consumo por litro en kilometraje del motor.\n");
    printf("Consumo de galones en todo el recorrido.\n");

    char nombre[50];
    printf("\nIngrese su nombre: ");
    scanf("%s", nombre);

    float consumo;
    printf("\nIngrese el consumo de litros en un rango de 8-16 litros de consumo por cada 100 km: ");
    scanf("%f", &consumo);

    if (consumo < 8.0 || consumo > 16.0) {
        printf("\nSu consumo no está en el rango establecido.\n");
        return 0;
    }

    int distancia;
    printf("\nIngrese la distancia recorrida en KM: ");
    scanf("%d", &distancia);

    //--------------------------------TABLA-----------------------------------\\

    printf("+----------------------------------+----------------------+\n");
    printf("|       Gasto de Combustible       |      Información     |\n");
    printf("+----------------------------------+----------------------+\n");

    float consumo_por_distancia = (consumo * distancia) / 100;
    printf("| Consumo en litros                | %.2f litros          |\n", consumo_por_distancia);
    printf("+----------------------------------+----------------------+\n");

    float Compra_Gasolina_Galones = 192.00;
    float Galones_de_Litros = consumo_por_distancia;
    float Galones_Resultado = Galones_de_Litros * 0.264172;
    printf("| Consumo en galones               | %.2f galones     |\n", Galones_Resultado);
    printf("+----------------------------------+----------------------+\n");

    float Gasto_Combustible_Promedio = (Galones_Resultado * Compra_Gasolina_Galones);
    printf("| Gasto promedio en combustible    | %.2f DOP            |\n", Gasto_Combustible_Promedio);
    printf("+----------------------------------+----------------------+\n");

    float gasto_mantenimiento = distancia * 10.0; // Supongamos un gasto fijo de 10 DOP por kilómetro en mantenimiento
    printf("| Gasto de mantenimiento           | %.2f DOP            |\n", gasto_mantenimiento);
    printf("+----------------------------------+----------------------+\n");

    float eficiencia = distancia / consumo_por_distancia;
    printf("| Eficiencia del vehículo           | %.2f km/litro       |\n", eficiencia);
    printf("+----------------------------------+----------------------+\n");

    // Guardar los resultados en un archivo de texto

    // Crear el nombre del archivo utilizando el nombre del cliente
    char nombre_archivo[100];
    sprintf(nombre_archivo, "%s.txt", nombre);

    // Abrir el archivo en modo escritura
    FILE* archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL) {
        printf("No se pudo crear el archivo.\n");
        return 0;
    }

    fprintf(archivo, "+----------------------------------+----------------------+\n");
    fprintf(archivo, "|       Gasto de Combustible       |      Información     |\n");
    fprintf(archivo, "+----------------------------------+----------------------+\n");
    fprintf(archivo, "| Consumo en litros                | %.2f litros          |\n", consumo_por_distancia);
    fprintf(archivo, "+----------------------------------+----------------------+\n");
    fprintf(archivo, "| Consumo en galones               | %.2f galones     |\n", Galones_Resultado);
    fprintf(archivo, "+----------------------------------+----------------------+\n");
    fprintf(archivo, "| Gasto promedio en combustible    | %.2f DOP            |\n", Gasto_Combustible_Promedio);
    fprintf(archivo, "+----------------------------------+----------------------+\n");
    fprintf(archivo, "| Gasto de mantenimiento           | %.2f DOP            |\n", gasto_mantenimiento);
    fprintf(archivo, "+----------------------------------+----------------------+\n");
    fprintf(archivo, "| Eficiencia del vehículo           | %.2f km/litro       |\n", eficiencia);
    fprintf(archivo, "+----------------------------------+----------------------+\n");

    // Cerrar el archivo
    fclose(archivo);

printf("El expediente se ha guardado en el archivo: %s\n", nombre_archivo);

    return 0;
}



