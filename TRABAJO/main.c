#include <stdio.h>

int main() {
    printf("El programa obtiene el gasto promedio de litro por kilometro recorrido con respecto a su precio. \n");
    printf("Consumo por litro en kilometraje del motor. \n");
    printf("Consumo de galones en todo el recorrido. \n");
    printf("Seguro basado en el valor del vehiculo y su incremento en la tasa prima. \n");
    printf("Gastos de mantenimiento. \n");
    printf("Gastos de cambio de neumatico. \n");
    printf("Gasto de cambio de aceite. \n");

    char nombre[50];
    printf("\nIngrese su nombre: ");
    scanf("%s", nombre);

    int distancia;
    printf("\nIngrese la distancia recorrida en KM: ");
    scanf("%d", &distancia);

    float consumo;
    printf("\nIngrese el consumo de litros en un rango de 8-16 litros de consumo por cada 100 km: ");
    scanf("%f", &consumo);

    if (consumo < 8.0 || consumo > 16.0) {
        printf("\nSu consumo no esta en el rango establecido.\n");
        return 0;
    }



    int edadConductor;
    float valorVehiculo;
    float valorMinimo = 100000;

    printf("\nIngrese la edad del conductor: ");
    scanf("%d", &edadConductor);

    printf("\nIngrese el valor del vehiculo: ");
    scanf("%f", &valorVehiculo);

    float tasaPrima = 0.0;
    float tasaPrimaIncremento = 0.05;

    if (edadConductor >= 18 && edadConductor < 25) {
        tasaPrima = 1.02;
    } else if (edadConductor >= 25 && edadConductor < 65) {
        tasaPrima = 1.05;
    }

    int incremento = 50000;
    int CumulodeIncremento= (valorVehiculo/50000)-2;

    if (incremento = valorMinimo+ (100000/2)) {
        tasaPrima = tasaPrima + (0.05* CumulodeIncremento);
    }
    else if(incremento += 50000){
        tasaPrima = tasaPrima + tasaPrimaIncremento;
    }



    int anosUso;
    float costoAnualMantenimiento;


    printf("\nIngrese la cantidad de anos de uso del carro: ");
    scanf("%d", &anosUso);

    printf("\nIngrese el costo promedio anual de mantenimiento: ");
    scanf("%f", &costoAnualMantenimiento);

    float CostoTotalMantenimiento;



    int cantidadNeumaticos ;
    float costoPorNeumatico;

    printf("\nIngrese la cantidad de neumaticos que necesita cambiar: ");
    scanf("%d", &cantidadNeumaticos);

    if (cantidadNeumaticos> 4){
        printf ("\nLa cantidad de gomas no esta en el rango establecido\n");
    }

    printf("\nIngrese el costo promedio por neumatico: ");
    scanf("%f", &costoPorNeumatico);





    float Costo_Galones_de_Aceite;
    float Litros_de_Aceite;

    float Gasto_de_Aceite;

    printf ("\nIngrese la cantidad de litros de aceite de su motor: ");
    scanf("%f", &Litros_de_Aceite);

    float Galones_de_Aceite = Litros_de_Aceite * 0.264172;

    printf ("\nSu cantidad de Galones de aceite es de: %f \n", Galones_de_Aceite);

    printf("\nIngrese el costo por litro de aceite: ");
    scanf("%f", &Costo_Galones_de_Aceite);



//--------------------------------TABLA-----------------------------------\\

    printf("+----------------------------------+----------------------+\n");
    printf("|       Gasto de Combustible       |      Información     |\n");
    printf("+----------------------------------+----------------------+\n");

    float consumo_por_distancia = (consumo * distancia) / 100;
    printf("+----------------------------------+----------------------+\n");
    printf("| Consumo en litros                | %.2f litros          |\n", consumo_por_distancia);
    printf("+----------------------------------+----------------------+\n");

    float Compra_Gasolina_Galones = 192.00;
    float Galones_de_Litros = consumo_por_distancia;
    float Galones_Resultado = Galones_de_Litros * 0.264172;
    printf("+----------------------------------+----------------------+\n");
    printf("| Consumo en galones               | %f galones     |\n", Galones_Resultado);
    printf("+----------------------------------+----------------------+\n");

    float Gasto_Combustible_Promedio = (Galones_Resultado * Compra_Gasolina_Galones) / distancia;
    printf("+----------------------------------+----------------------+\n");
    printf("| Gasto promedio                   | %.2f DOP por km      |\n", Gasto_Combustible_Promedio);
    printf("+----------------------------------+----------------------+\n");

    printf("+----------------------------------+----------------------+\n");
    printf("|Tasa de prima                     |%.2f                  |\n", tasaPrima);
    printf("+----------------------------------+----------------------+\n");

    float prima = valorVehiculo * tasaPrima;
    printf("+----------------------------------+----------------------+\n");
    printf("|Prima a pagar                     |%.2f             |\n", prima);
    printf("+----------------------------------+----------------------+\n");
    if (CostoTotalMantenimiento >= 0){
    float CostoTotalMantenimiento = costoAnualMantenimiento * anosUso;
    }
    printf("+----------------------------------+----------------------+\n");
    printf("|Costo de mantenimiento en %d       |%.2f DOP            |\n", anosUso, costoAnualMantenimiento, CostoTotalMantenimiento);
    printf("+----------------------------------+----------------------+\n");

    float gastoTotal = cantidadNeumaticos * costoPorNeumatico;
    printf("+----------------------------------+----------------------+\n");
    printf("|Gasto de cambio de neumaticos     |%.2f DOP            |\n", gastoTotal);
    printf("+----------------------------------+----------------------+\n");

    float Gasto_Total_de_Aceite = Galones_de_Aceite * Costo_Galones_de_Aceite;
    printf("+----------------------------------+----------------------+\n");
    printf("|Gasto de cambio de aceite         |%.2f DOP           |\n", Gasto_Total_de_Aceite);
    printf("+----------------------------------+----------------------+\n");






    return 0;
}
