/*
 ============================================================================
 Name        : main.c
 Author      : Gaston Bordier
 Description : Programa con funciones para realizar calculos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "calculos.h"

double operandoUno = 0;
double operandoDos = 0;
char salir = 'n';
int opcion = 0;

double resultadoSuma = 0;
double resultadoResta = 0;
double resultadoMultiplicacion = 0;
double resultadoDivision = 0;
double resultadoFactorialUno = 0;
double resultadoFactorialDos = 0;

int validacionResultados = 0;
int validacionDivisorCero = 0;

int validacionNegativoParaFactorialUno = 0;
int validacionNegativoParaFactorialDos = 0;
int validacionEnteroParaFactorialUno = 0;
int validacionEnteroParaFactorialDos = 0;

int validacionOperaciones = 0;

int main() {

	setbuf(stdout, NULL);
	printf("Bienvenido a Calculadora!");

	while (salir != 's') {
		opcion = 0;

		printf("\nElija la operacion que quiere realizar:");
		printf("\n1.- Ingresar el primer operando");
		printf("\n2.- Ingresar el segundo operando");
		printf(
				"\n3.- Realizar operaciones entre los numeros(suma, resta, multiplicacion, division y factorial de ambos)");
		printf("\n4.- Mostrar los resultados");
		printf("\n5.- Salir del programa\n");

		printf("\nValor de operando 1: %.2lf.		Valor de operando 2: %.2lf\n",
				operandoUno, operandoDos);

		if (validacionOperaciones == 1) {
			printf(
					"\nLas operaciones fueron realizadas y el resultado fue grabado.");
		}

		if (validacionResultados == 1) {

			printf("\nEl resultado de la suma es %.2lf.\n", resultadoSuma);
			printf("\nEl resultado de la resta es %.2lf.\n", resultadoResta);
			printf("\nEl resultado de la multiplicacion es %.2lf.\n",
					resultadoMultiplicacion);

		}


		if (validacionResultados == 1 && validacionDivisorCero == 0) {
			printf("\nEl resultado de la division es %.2lf.\n",
					resultadoDivision);
		} else if (validacionResultados == 1 && validacionDivisorCero == 1) {
			printf("\nNo se puede dividir por cero.\n");
		}

		if (validacionResultados == 1) {

			if (validacionNegativoParaFactorialUno != 0)
				printf(
						"\nNo se puede calcular el factorial de un numero negativo. Se ha usado el valor absoluto del primer numero");
			if (validacionEnteroParaFactorialUno != 0)
				printf(
						"\nEl primer numero ha sido truncado en su valor entero.");

			printf("\nEl resultado del factorial del primer numero es %.0lf\n",
					resultadoFactorialUno);

			if (validacionNegativoParaFactorialDos != 0)
				printf(
						"\nNo se puede calcular el factorial de un numero negativo. Se ha usado el valor absoluto del segundo numero");
			if (validacionEnteroParaFactorialDos != 0)
				printf(
						"\nEl segundo numero ha sido truncado en su valor entero.");

			printf("\nEl resultado del factorial del segundo numero es %.0lf\n",
					resultadoFactorialDos);
		}

		fflush(stdin);
		scanf("%d", &opcion);

		switch (opcion) {

		case 1:
			reseteoValidaciones();
			ingresoUno();
			break;
		case 2:
			reseteoValidaciones();
			ingresoDos();
			break;
		case 3:
			reseteoValidaciones();
			resultadoSuma = getSuma(operandoUno, operandoDos);
			resultadoResta = getResta(operandoUno, operandoDos);
			resultadoMultiplicacion = getProducto(operandoUno, operandoDos);
			resultadoDivision = getDivision(operandoUno, operandoDos);

			double temp= operandoUno;
			int validacionTemp;

			if (operandoUno < 0) {
				temp = -operandoUno;
				validacionTemp = 1;
			}
			if ((temp - (int) temp) != 0) {
				temp = (int) temp;
				validacionTemp = 1;
			}
			if (validacionTemp == 1) {
				resultadoFactorialUno = getFactorial(temp);
			} else {
				resultadoFactorialUno = getFactorial(operandoUno);
			}

			temp = operandoDos;
			validacionTemp = 0;

			if (operandoDos < 0) {
				temp = -operandoDos;
				validacionTemp = 1;
			}
			if ((temp - (int) temp) != 0) {
				temp = (int) temp;
				validacionTemp = 1;
			}
			if (validacionTemp == 1) {
				resultadoFactorialDos = getFactorial(temp);
			} else {
				resultadoFactorialDos = getFactorial(operandoDos);
			}

			validacionOperaciones = 1;
			break;
		case 4:
			reseteoValidaciones();
			validacionResultados = 1;

			if (operandoDos == 0)
				validacionDivisorCero = 1;

			if (operandoUno < 0)
				validacionNegativoParaFactorialUno = 1;
			if (operandoDos < 0)
				validacionNegativoParaFactorialDos = 1;
			if ((operandoUno - (int) operandoUno) != 0)
				validacionEnteroParaFactorialUno = 1;
			if ((operandoDos - (int) operandoDos) != 0)
				validacionEnteroParaFactorialDos = 1;

			break;
		case 5:
			reseteoValidaciones();

			printf(
					"\nDesea salir(s) o seguir en Calculadora(cualquier otra tecla)?");
			fflush(stdin);
			scanf("%c", &salir);

			break;
		}

		system("CLS");
	}

	system("PAUSE");
	return EXIT_SUCCESS;

}

int reseteoValidaciones() {

	validacionResultados = 0;
	validacionOperaciones = 0;
	validacionDivisorCero = 0;
	validacionEnteroParaFactorialUno = 0;
	validacionEnteroParaFactorialDos = 0;
	validacionNegativoParaFactorialUno = 0;
	validacionNegativoParaFactorialDos = 0;
	return 0;
}

