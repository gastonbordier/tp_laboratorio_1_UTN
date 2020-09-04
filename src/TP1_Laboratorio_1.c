/*
 ============================================================================
 Name        : TP1_Laboratorio_1.c
 Author      : Gaston Bordier
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Calculos.h"

int main(void) {
	char salir = 'n';
	float x = 0;
	float y = 0;
	float resultadoSuma, resultadoResta, resultadoMultiplicacion, resultadoDivision, resultadoFactX, resultadoFactY;
	int opciones = 0;


	printf("Bienvenido a Calculadora!\n");

	while (salir != 's') {
		salir = 'n';
		printf("%f", x);

		printf("\nIndique que desea realizar:\n");

		printf("1. Ingresar valor de x\n");
		printf("2. Ingresar valor de y\n");
		printf("3. Calcular la Suma\n");
		printf("4. Calcular la Resta\n");
		printf("5. Calcular la Multiplicacion\n");
		printf("6. Calcular la Division\n");
		printf("7. Calcular el factorial\n");
		printf("8. Salir\n");

		printf("\nValor de x = %.2f . ", x);
		printf("Valor de y = %.2f .\n", y);

		fflush(stdin);
		scanf("%d", &opciones);

		switch (opciones) {

		case 1:
			fflush(stdin);
			scanf("\n%f\n", &x);
			break;
		case 2:
			scanf("\n%f\n", &y);
			break;
		case 3:
			resultadoSuma = getSuma(x, y);
			printf("\nLa suma da como resultado %.2f", resultadoSuma);
			break;
		case 4:
			resultadoResta = getResta(x, y);
			printf("\nLa suma da como resultado %.2f", resultadoResta);
			break;
		case 5:
			resultadoMultiplicacion = getMultiplicacion(x, y);
			printf("\nLa suma da como resultado %.2f", resultadoMultiplicacion);
			break;
		case 6:
			resultadoDivision = getDivision(x, y);
			printf("\nLa suma da como resultado %.2f", resultadoDivision);
			break;
		case 7:
			resultadoFactX = getFactorial(x);
			printf("\nLa suma da como resultado %.2f", resultadoFactX);
			resultadoFactY = getFactorial(y);
			printf("\nLa suma da como resultado %.2f", resultadoFactY);
			break;
		case 8:
			printf("\nEsta seguro que desea salir(s)?\n");
			fflush(stdin);
			scanf("%c", &salir);
			if (salir != 's')
				printf("Se ha cancelado el cierre del programa");
			break;
		default:
			printf("\nHa ingresado una opción incorrecta.\n");

		}

	}
	printf("\nHasta luego!\n");
	system("PAUSE");
}
