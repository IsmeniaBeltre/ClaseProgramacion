

#include <stdio.h>
#include <locale.h>
int Res;


    int main() {
    char nombre[50];
    char apellido[50];

     // Establecer la configuración de caracteres a UTF-8
    setlocale(LC_ALL, "spanish");


do{
        printf("El programa obtiene el gasto promedio de litro por kilometro recorrido con respecto a su precio.\n");
        printf("Consumo por litro en kilometraje del motor.\n");
        printf("Consumo de galones en todo el recorrido.\n");


        printf("\nIngrese su nombre completo: ");
        scanf("%s\n", nombre);
        scanf("%s", apellido);

        int eficiencia_min;   // Eficiencia mínima
        int eficiencia_max;  // Eficiencia máxima


        do{
        printf("\nIngrese la eficiencia mínima de litros por km: ");
        scanf("%d", &eficiencia_min);

        printf("\nIngrese la eficiencia máxima de litros por km: ");
        scanf("%d", &eficiencia_max);

        if (eficiencia_min > eficiencia_max){
        printf("La eficiencia mínima no puede ser mayor a la eficiencia máxima ¿Desea volver a intentarlo? Si(1) No (2): ");
        scanf("%d", &Res);
        }
         else {
                break; // Salir del bucle si la eficiencia minima es menor o igual que la eficiencia máxima
            }
         } while (Res == 1);

        float consumo;
        int distancia;
        printf("\nIngrese la distancia recorrida en KM: ");
        scanf("%d", &distancia);

        float valorVehiculo;
        printf("\nIngrese el valor del vehículo: ");
        scanf("%f", &valorVehiculo);

        int incremento = 50000;
        float valor_inicial = 0.82;

        int incrementos_completos = (valorVehiculo / incremento) - 4;
        float incremento_total = incrementos_completos * 0.18;
        float valor_con_incremento = valor_inicial + incremento_total;
        float prima = 1000+(valor_con_incremento * distancia);


        float gasto_neumaticos;
        float gasto_cambio_aceite;
        float gasto_mantenimiento;

        printf("\nIngrese el gasto del cambio de neumáticos: ");
        scanf("%f", &gasto_neumaticos);

        printf("\nIngrese el gasto del cambio de aceite: ");
        scanf("%f", &gasto_cambio_aceite);

        printf("\nIngrese el gasto de mantenimiento anual del vehículo: ");
        scanf("%f", &gasto_mantenimiento);

        char nombreapellidoArchivo[100];
        sprintf(nombreapellidoArchivo, "%s%s.txt", nombre, apellido);

        FILE *archivo;
        archivo = fopen(nombreapellidoArchivo, "w+");

        if (archivo == NULL) {
            printf("No se pudo abrir el archivo.\n");
            return 1;
        }
            printf("\n|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
            printf("|                                                   Cliente %s %s, esta es su tabla de relación con respecto al Consumo promedio de su motor                                                                            |\n", nombre,apellido);
            printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
            printf("|Consumo Promedio(Litros)\tDistancia recorrida(km)\t\tConsumo en litros\tConsumo en galones\tGasto por km(DOP)\t\tGastos varios(DOP)\tEficiencia(km/litro)\tEficiencia(km/galones)|\n");

    int eficiencia_actual;
    for (eficiencia_actual = eficiencia_min; eficiencia_actual <= eficiencia_max; eficiencia_actual++) {
        float consumo_por_distancia_Litros = (eficiencia_actual * distancia) / 100.0;
        float consumo_por_distancia_Galones = consumo_por_distancia_Litros * 0.264172; // Conversión de litros a galones
        float Gasto_Combustible_Promedio = consumo_por_distancia_Galones * 192.00;
        float gastos_varios = prima + gasto_neumaticos + gasto_cambio_aceite + gasto_mantenimiento;


float eficiencia_Litros = distancia / consumo_por_distancia_Litros;
        float eficiencia_Galones = distancia / consumo_por_distancia_Galones;


        printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
        printf("|\t%d\t\t\t\t%.2f\t\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f \t\t\t\t%.2f\t\t\t%.2f\t\t\t%.2f         |\n", eficiencia_actual, (float)distancia, consumo_por_distancia_Litros, consumo_por_distancia_Galones, Gasto_Combustible_Promedio, gastos_varios, eficiencia_Litros, eficiencia_Galones);
        printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    }

    // Cerrar el archivo
    fclose(archivo);
    printf("El expediente se ha guardado en el archivo: %s\n%s\n", nombreapellidoArchivo);

    printf("¿Desea ingresar más datos? Si(1) No (2): ");
        scanf("%d", &Res);
    } while (Res == 1);


    return 1;
}
