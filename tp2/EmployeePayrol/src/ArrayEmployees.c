/*
 * ArrayEmployees.c
 *
 *  Created on: 7 oct. 2020
 *      Author: Gaston
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validations.h"
/*
 * author Gaston
 *\brief inicializa el array de estructuras
 *\param *arrayEmployee El array de estructuras Empleado a manipular
 *\param len la longitud maxima del array
 *\return 0
 *  */
int initEmployees(Employee *arrayEmployee, int len) {

	for (int i = 0; i < len; i++) {	//Inicializo el array de la estructura Employee

		arrayEmployee[i].id = 101 + i;
		strcpy(arrayEmployee[i].name, "Empty");
		strcpy(arrayEmployee[i].lastName, "Empty");
		arrayEmployee[i].salary = 0;
		arrayEmployee[i].sector = 0;
		arrayEmployee[i].isEmpty = 1;
	}

	return 0;
}



/*
 * author Gaston
 * \brief suma la cantidad de empleados y despliega el menu principal. Si son cero, solo permite la primera opcion y salir
 *\param *arrayEmployee El array de estructuras Empleado a manipular
 *\param len la longitud maxima del array
 * \return la opcion elegida
 */
int menu(Employee *arrayEmployee, int len) {

	int flagOk = 0;
	int chosenAction = 0;

	system("cls");

	int contadorEmployees = 0; //suma la cantidad de empleados con datos ingresados
	int emptyArray = 1;

	for (int i = 0; i < len; i++) {

		if (arrayEmployee[i].isEmpty == 0) {
			++contadorEmployees;
		}
	}
	printf("Bienvenido al Sistema de Nomina de Empleados.\n");
	printf("La base actualmente cuenta con los datos de %d empleados.\n",
			contadorEmployees);
	if (contadorEmployees == 0) {
		emptyArray = 1;
		printf(
				"La unica accion valida en este momento es ingresar un empleado. \nPara hacerlo, ingrese 1:\n");
	}

	if (contadorEmployees > 0) {
		emptyArray = 0;
		printf("1 - Ingresar empleado\n");
		printf("2 - Modificar empleado por numero de legajo.\n");
		printf("3 - Remover empleado de la base.\n");
		printf("4 - Informar.\n");
		printf("5 - Salir \n");

	}

	do {
		fflush(stdin);
		scanf("%d", &chosenAction);

		if (emptyArray == 1 && (chosenAction == 5 || chosenAction == 1)) {
			flagOk = 1;
		} else if (emptyArray == 1) {
			printf("Ingreso incorrecto. Intentelo nuevamente\n");

		}

		if (emptyArray == 0 && chosenAction >= 1 && chosenAction <= 5) {
			flagOk = 1;
		} else if (emptyArray == 0
				&& !(chosenAction >= 1 && chosenAction <= 5)) {
			printf("Ingreso incorrecto. Intentelo nuevamente\n");

		}

	} while (flagOk != 1);

	return chosenAction;
}

/*
 * author Gaston
 * \brief imprime la lista de empleados existentes segun orden del index del array
 *\param *arrayEmployee El array de estructuras Empleado a manipular
 *\param len la longitud maxima del array
  * \return 0
 */

int printEmployees(Employee *arrayEmployee, int len) {

	printf("id\tNombre\t\t\t\tSalario\t\t\tSector\t\tisEmpty\n");
	for (int i = 0; i < len; i++) {
		if (arrayEmployee[i].isEmpty == 0) {

			printf("%d\t%s %s\t\t\t%.2f\t\t%2d\t\t%d\n", arrayEmployee[i].id,
					arrayEmployee[i].name, arrayEmployee[i].lastName,
					arrayEmployee[i].salary, arrayEmployee[i].sector,
					arrayEmployee[i].isEmpty);
		}
	}

	return 0;
}

/*
 * author Gaston
 * \brief valida los datos ingresados para crear un nuevo elemento Empleado en el array
 * \param *arrayEmployee El array de estructuras Empleado a manipular
 * \param len la longitud maxima del array
 * \param *temp estructura Empleado temporal donde quedan guardados los datos validados
 * \return 0 si los datos fueron validados, -1 si alguna validacion uso todos sus reintentos
 */
int enterEmployeeData(Employee *arrayEmployee, int len, Employee *temp) {

	int retorno = 0;
	int emptyId;
	int emptyLineArray;
	int entryState = 0;
	int flagOk = 0;

	for (int i = 0; i < len; i++) {
		if (arrayEmployee[i].isEmpty == 1) {

			emptyLineArray = i;
			emptyId = arrayEmployee[i].id;
			break;
		}
	}

	printf("Se agregara un empleado en el legajo %d\n",
			arrayEmployee[emptyLineArray].id);



	if (entryState == 0) {
		fflush(stdin);
		flagOk = setString(temp->name, "Ingrese el nombre del empleado",
				"Ingreso de nombre cancelado", 2, 25, 3);
		if (flagOk == 0)
			++entryState;
	}


	if (entryState == 1) {
	fflush(stdin);
	flagOk = setString(temp->lastName, "Ingrese el apellido del empleado",
			"Ingreso de apellido cancelado", 2, 25, 3);
	if (flagOk == 0)
		++entryState;
	//scanf("%s", &temp->lastName);
	}
	if (entryState == 2) {

	fflush(stdin);
	flagOk = setFloat(&temp->salary,
			"Ingrese el salario del empleado(0-200.000)",
			"Ingreso de salario cancelado", 1000, 200000, 3);
	if (flagOk == 0)
		++entryState;
	}

	if (entryState == 3) {

	fflush(stdin);
	flagOk = setInt(&temp->sector, "Ingrese el sector del empleado(1-6)",
			"Ingreso de sector cancelado", 1, 6, 3);
	if (flagOk == 0)
		++entryState;
	//scanf("%d", &temp->sector);

	}
	if (entryState != 4) {
		printf("Ingreso de empleado cancelado\n");
		retorno = -1;
	}

	temp->id = emptyId;
	temp->isEmpty = 0;

	return retorno;
}

/*
 * author Gaston
 * \brief
 * \param *arrayEmployee El array de estructuras Empleado a manipular
 * \param len la longitud maxima del array
 * \param id el numero de id mas bajo del array, donde se guardaran los datos
 * \param name el dato validado y guardado en la estructura temp
 * \param lastName el dato validado y guardado en la estructura temp
 * \param salary el dato validado y guardado en la estructura temp
 * \param sector el dato validado y guardado en la estructura temp
 * \return 0
 */

int addEmployee(Employee *arrayEmployee, int len, int id, char name[],
		char lastName[], float salary, int sector) {

	int emptyLineArray;

	for (int i = 0; i < len; i++) {
		if (arrayEmployee[i].isEmpty == 1) {

			emptyLineArray = i;

			break;
		}
	}

	strcpy(arrayEmployee[emptyLineArray].name, name);
	strcpy(arrayEmployee[emptyLineArray].lastName, lastName);
	arrayEmployee[emptyLineArray].salary = salary;
	arrayEmployee[emptyLineArray].sector = sector;
	arrayEmployee[emptyLineArray].isEmpty = 0;

	return 0;
}

/*
 * author Gaston
 * \brief encuentra el indice del array usando el elemento id de las estructuras
 * \param *arrayEmployee El array de estructuras Empleado a manipular
 * \param len la longitud maxima del array
 * \param id el id ingresado
 * \return la posicion del array respectiva al id ingresado
 */
int findEmployeeById(Employee *arrayEmployee, int len, int id) {

	char exitConfirmation = 'r';
	char successConfirmation = 'n';
	int arrayPosition = -1;

	do {

		if (exitConfirmation == 'n') {
			printf("Ingrese el numero de legajo correctamente\n");
			fflush(stdin);
			scanf("%d", &id);
		}

		for (arrayPosition = 0; arrayPosition < len; arrayPosition++) {
			if (arrayEmployee[arrayPosition].id == id) {
				break;
			}
		}

		if (arrayPosition != len
				&& (strcmp(arrayEmployee[arrayPosition].name, "Empty") != 0)) {
			successConfirmation = 's';
			exitConfirmation = 's';
		} else if (arrayPosition == len
				|| (strcmp(arrayEmployee[arrayPosition].name, "Empty") == 0)) {
			printf("Numero de Legajo Inexistente\n");
			printf("Desea cancelar el ingreso de legajo?(s/n)\n");
			fflush(stdin);
			scanf("%c", &exitConfirmation);
		}
		if (exitConfirmation == 's' && successConfirmation == 'n') {
			arrayPosition = -1;
		}

	} while (exitConfirmation != 's');

	return arrayPosition;
}

/*
 * author Gaston
 * \brief crea un array temporal con los empleados ordenador alfabeticamente
 * 		  por apellido como criterio principal y numericamente por sector como criterio secundario
 * \param *arrayEmployee El array de estructuras Empleado a manipular
 * \param len la longitud maxima del array
 * \return 0
 */
int orderEmployeesByLastName(Employee *arrayEmployee, int len) {

	Employee temp;
	temp.id = 101;
	strcpy(temp.name, "Empty");
	strcpy(temp.lastName, "Empty");
	temp.salary = 0.00;
	temp.sector = 0;
	temp.isEmpty = 1;

	int compare;

	for (int j = 0; j < (len - 1); j++) {

		for (int i = 0; i < (len - 1); i++) {

			compare = strcmp(arrayEmployee[i].lastName,
					arrayEmployee[i + 1].lastName);
			if (compare == 1) {
				fflush(stdin);
				temp = arrayEmployee[i];
				arrayEmployee[i] = arrayEmployee[i + 1];
				arrayEmployee[i + 1] = temp;
			}
			if (compare == 0) {
				if (arrayEmployee[i].sector > arrayEmployee[i + 1].sector) {
					temp = arrayEmployee[i];
					arrayEmployee[i] = arrayEmployee[i + 1];
					arrayEmployee[i + 1] = temp;
				}
			}
		}
	}

	printf("id\tNombre\t\t\t\tSalario\t\t\tSector\t\tisEmpty\n");
	for (int i = 0; i < len; i++) {
		if (arrayEmployee[i].isEmpty == 0) {

			printf("%d\t%s %s\t\t\t%.2f\t\t%2d\t\t%d\n", arrayEmployee[i].id,
					arrayEmployee[i].name, arrayEmployee[i].lastName,
					arrayEmployee[i].salary, arrayEmployee[i].sector,
					arrayEmployee[i].isEmpty);
		}
	}

	return 0;
}
