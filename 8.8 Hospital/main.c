#include <stdio.h>
#include <string.h>

typedef struct {
    char cal[20];    // Calle
    int num;         // Número
    char col[20];    // Colonia
    char cp[5];      // Código Postal
    char ciu[20];    // Ciudad
} domicilio;

typedef struct {
    char nom[20];    // Nombre y apellido
    int edad;
    char sexo;
    int con;         // Condición
    domicilio dom;   // Estructura domicilio
    char tel[10];    // Teléfono
} paciente;

void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

void main(void) {
    paciente HOSPITAL[100];   // Arreglo unidimensional de tipo estructura paciente
    int TAM;
    do {
        printf("Ingrese el número de pacientes: ");
        scanf("%d", &TAM);
    } while (TAM > 100 || TAM < 1);   // Verificar tamaño del arreglo

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);
}

void Lectura(paciente A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("\nPaciente %d", I + 1);
        fflush(stdin);
        printf("\nNombre: ");
        scanf("%s", A[I].nom);
        printf("Edad: ");
        scanf("%d", &A[I].edad);
        printf("Sexo (F-M): ");
        scanf(" %c", &A[I].sexo);
        printf("Condición (1..5): ");
        scanf("%d", &A[I].con);
        fflush(stdin);
        printf("\tCalle: ");
        scanf("%s", A[I].dom.cal);
        printf("\tNúmero: ");
        scanf("%d", &A[I].dom.num);
        fflush(stdin);
        printf("\tColonia: ");
        scanf("%s", A[I].dom.col);
        fflush(stdin);
        printf("\tCódigo Postal: ");
        scanf("%s", A[I].dom.cp);
        fflush(stdin);
        printf("\tCiudad: ");
        scanf("%s", A[I].dom.ciu);
        fflush(stdin);
        printf("Teléfono: ");
        scanf("%s", A[I].tel);
    }
}

void F1(paciente A[], int T) {
    int I, FEM = 0, MAS = 0, TOT;
    for (I = 0; I < T; I++) {
        switch (A[I].sexo) {
            case 'F':
                FEM++;
                break;
            case 'M':
                MAS++;
                break;
        }
    }
    TOT = FEM + MAS;
    printf("\nPorcentaje de Hombres: %.2f%%", (float)MAS / TOT * 100);
    printf("\nPorcentaje de Mujeres: %.2f%%", (float)FEM / TOT * 100);
}

void F2(paciente A[], int T) {
    int I, C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0;
    for (I = 0; I < T; I++) {
        switch (A[I].con) {
            case 1:
                C1++;
                break;
            case 2:
                C2++;
                break;
            case 3:
                C3++;
                break;
            case 4:
                C4++;
                break;
            case 5:
                C5++;
                break;
        }
    }
    printf("\nNúmero pacientes en condición 1: %d", C1);
    printf("\nNúmero pacientes en condición 2: %d", C2);
    printf("\nNúmero pacientes en condición 3: %d", C3);
    printf("\nNúmero pacientes en condición 4: %d", C4);
    printf("\nNúmero pacientes en condición 5: %d", C5);
}

void F3(paciente A[], int T) {
    int I;
    printf("\nPacientes ingresados en estado de gravedad");
    for (I = 0; I < T; I++) {
        if (A[I].con == 5) {
            printf("\nNombre: %s\tTeléfono: %s", A[I].nom, A[I].tel);
        }
    }
}

