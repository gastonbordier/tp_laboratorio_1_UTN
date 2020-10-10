#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * author Gaston
 * \brief valida ingreso de dato de tipo entero
 * \param *pOutput la variable original int a sobreescribir
 * \param message mensaje a mostrar pidiendo el tipo de ingreso
 * \param errorMessage mensaje a mostrar si la validacion falla
 * \param min entero minimo aceptado
 * \param max entero maximo aceptado
 * \param retries numero de reintentos
 * \return 0 si la validacion fue exitosa, 1 si se consumieron todos los reintentos
 */

int setInt(int *pOutput, char message[51], char errorMessage[51], int min,
		int max, int retries) {
	int retorno = -1;
	printf("%s\n", message);

	while (retries > 0) {

		fflush(stdin);
		scanf("%d", pOutput);

		if (*pOutput >= min && *pOutput <= max) {
			printf("Ingreso correcto\n");
			retries = -1;
			retorno = 0;
		} else if (retries > 1) {
			printf("Intentelo nuevamente.\n");
		}

		--retries;
	}
	if (retorno == -1)
		printf("%s\n", errorMessage);
	return retorno;
}

/*
 * author Gaston
 * \brief valida ingreso de dato de tipo array de caracteres
 * \param *pOutput la variable original char[] a sobreescribir
 * \param message mensaje a mostrar pidiendo el tipo de ingreso
 * \param errorMessage mensaje a mostrar si la validacion falla
 * \param min cantidad de caracteres minima aceptada
 * \param max cantidad de caracteres maxima aceptada
 * \param retries numero de reintentos
 * \return 0 si la validacion fue exitosa, 1 si se consumieron todos los reintentos
 */
int setString(char *pOutput, char message[51], char errorMessage[51], int min,
		int max, int retries) {
	int retorno = -1;
	printf("%s\n", message);

	while (retries > 0) {

		fflush(stdin);
		fgets(pOutput, 500, stdin);

		if ((strlen(pOutput) - 1) >= min && (strlen(pOutput) - 1) <= max) {
			printf("Ingreso correcto\n");
			if (pOutput[0] >= 'a' && pOutput[0] <= 'z') {
				pOutput[0] = (char) (('A' - 'a') + pOutput[0]);
				retries = -1;
				retorno = 0;
			} else if (retries > 1) {
				printf("Intentelo nuevamente.\n");
			}

			--retries;
		}
		if (retorno == -1)
			printf("%s\n", errorMessage);
	}
	return retorno;
}

/*
 * author Gaston
 * \brief valida ingreso de dato de tipo flotante
 * \param *pOutput la variable original float a sobreescribir
 * \param message mensaje a mostrar pidiendo el tipo de ingreso
 * \param errorMessage mensaje a mostrar si la validacion falla
 * \param min flotante minimo aceptado
 * \param max flotante maximo aceptado
 * \param retries numero de reintentos
 * \return 0 si la validacion fue exitosa, 1 si se consumieron todos los reintentos
 */
int setFloat(float *pOutput, char message[51], char errorMessage[51], int min,
		int max, int retries) {
	int retorno = -1;
	printf("%s\n", message);

	while (retries > 0) {

		fflush(stdin);
		scanf("%f", pOutput);

		if (*pOutput >= (float) min && *pOutput <= (float) max) {
			printf("Ingreso correcto\n");
			retries = -1;
			retorno = 0;
		} else if (retries > 1) {
			printf("Intentelo nuevamente.\n");
		}

		--retries;
	}
	if (retorno == -1)
		printf("%s\n", errorMessage);
	return retorno;
}
