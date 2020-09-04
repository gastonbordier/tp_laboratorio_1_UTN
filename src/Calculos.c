/*
 * Calculos.c
 *
 *  Created on: 4 sep. 2020
 *      Author: Administrador
 */

float getSuma(float x, float y) {

	return x + y;
}
float getResta(float x, float y) {

	return x - y;
}
float getMultiplicacion(float x, float y) {

	return x*y;
}
float getDivision(float x, float y) {

	return x / y;
}
float getFactorial(int z) {

	int totalFx = 1;

	for (int i = 1; i <= z; i++) {
		totalFx = totalFx * i;

		return totalFx;
	}

}
