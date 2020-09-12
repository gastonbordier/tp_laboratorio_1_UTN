#include <stdio.h>
#include <stdlib.h>

float operandoUno;
float operandoDos;


/*
 *\brief pide al usuario que ingrese un numero y lo almacena en una variable
 *\return devuelve el numero ingresado
 */
float ingresoUno() {
	printf("\nIngrese el primer operando\n");
	fflush(stdin);
	scanf("%f", &operandoUno);
	return operandoUno;
}
/*
 *\brief pide al usuario que ingrese un numero y lo almacena en una variable
 *\return devuelve el numero ingresado
 */
float ingresoDos() {
	printf("\nIngrese el segundo operando\n");
	fflush(stdin);
	scanf("%f", &operandoDos);
	return operandoDos;
}
/*
 *\brief suma dos numeros
 *\param x Es el primer numero
 *\param y Es el segundo numero
 *\return devuelve el resultado de la suma
 */
float getSuma(float x, float y) {

	float total = x + y;

	return total;
}
/*
 *\brief resta dos numeros
 *\param x Es el primer numero
 *\param y Es el segundo numero
 *\return devuelve el resultado de la resta
 */
float getResta(float x, float y) {

	float total = x - y;

	return total;
}
/*
 *\brief multiplica dos numeros
 *\param x Es el primer numero
 *\param y Es el segundo numero
 *\return devuelve el resultado de la multiplicacion
 */
float getProducto(float x, float y) {

	float total = x * y;

	return total;
}
/*
 *\brief divide un numero por otro
 *\param x Es el dividendo
 *\param y Es el divisor
 *\return devuelve el resultado de la division, si el divisor es cero devuelve cero
 */
float getDivision(float x, float y) {

	float total;

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
float getFactorial(float x) {
	int numero = (int) x;
	int total = 1;
	for (int i = 1; i <= numero; i++) {

		total = total * i;

	}
	return total;

}

