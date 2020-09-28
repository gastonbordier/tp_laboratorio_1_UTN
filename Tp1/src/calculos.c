#include <stdio.h>
#include <stdlib.h>

double operandoUno;
double operandoDos;


/*
 *\brief pide al usuario que ingrese un numero y lo almacena en una variable
 *\return devuelve el numero ingresado
 */
double ingresoUno() {
	printf("\nIngrese el primer operando\n");
	fflush(stdin);
	scanf("%lf", &operandoUno);
	return operandoUno;
}
/*
 *\brief pide al usuario que ingrese un numero y lo almacena en una variable
 *\return devuelve el numero ingresado
 */
double ingresoDos() {
	printf("\nIngrese el segundo operando\n");
	fflush(stdin);
	scanf("%lf", &operandoDos);
	return operandoDos;
}
/*
 *\brief suma dos numeros
 *\param x Es el primer numero
 *\param y Es el segundo numero
 *\return devuelve el resultado de la suma
 */
double getSuma(double x, double y) {

	double total = x + y;

	return total;
}
/*
 *\brief resta dos numeros
 *\param x Es el primer numero
 *\param y Es el segundo numero
 *\return devuelve el resultado de la resta
 */
double getResta(double x, double y) {

	double total = x - y;

	return total;
}
/*
 *\brief multiplica dos numeros
 *\param x Es el primer numero
 *\param y Es el segundo numero
 *\return devuelve el resultado de la multiplicacion
 */
double getProducto(double x, double y) {

	double total = x * y;

	return total;
}
/*
 *\brief divide un numero por otro
 *\param x Es el dividendo
 *\param y Es el divisor
 *\return devuelve el resultado de la division, si el divisor es cero devuelve cero
 */
double getDivision(double x, double y) {

	double total;

	if (y == 0) {
		printf("\nNo es posible dividir por cero\n");
		total = 0;
	} else {
		total = x / y;
	}
	return total;
}
/*
 *\brief calcula el factorial de un numero
 *\param x el numero a factorear
 *\return devuelve el resultado de la operacion. si x no es entero, lo trunca a su valor entero. Si es negativo, el resultado es 1
 */
double getFactorial(double x) {

	double total = 1;
	for (int i = 1; i <= (int)x; i++) {

		total = total * i;

	}
	if ( x == 0){
		total = 0;
	}
	return total;

}

