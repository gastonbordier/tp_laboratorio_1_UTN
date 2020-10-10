/*
 ============================================================================
 Name        : EmployeePayrol.c
 Author      : Gaston Bordier
 Description : Employee Database
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "validations.h"
#define MAX 15

int main(void) {
	setbuf(stdout, NULL);
	int idEntry;

	int choice;
	int firstBucle = 1;
	int flagCorrectData = 0;
	int arraySearched = 0;
	int flagOk = 0;

	Employee arrayEmployee[MAX];
	Employee temp;

	initEmployees(arrayEmployee, MAX);

/*	 addEmployee(arrayEmployee, MAX, 101, "Juan", "Fernandez", 35000.00, 1);
	 addEmployee(arrayEmployee, MAX, 102, "Juan", "Dieguez", 50000.00, 2);
	 addEmployee(arrayEmployee, MAX, 103, "Juan", "Bordier", 12000.00, 4);
	 addEmployee(arrayEmployee, MAX, 104, "Juan", "Entel", 32000.00, 1);
	 addEmployee(arrayEmployee, MAX, 105, "Juan", "Fernandez", 45000.00, 2);
	 addEmployee(arrayEmployee, MAX, 106, "Juan", "Goriostiaga", 15000.00, 4);
	 addEmployee(arrayEmployee, MAX, 107, "Juan", "Antioquia", 44000.00, 3);
	 addEmployee(arrayEmployee, MAX, 108, "Juan", "Fernandez", 20000.00, 3);
	 addEmployee(arrayEmployee, MAX, 109, "Juan", "Cruz", 10000.00, 2);
	 addEmployee(arrayEmployee, MAX, 110, "Juan", "Bordier", 25000.00, 2);
*/

	do {

		if (firstBucle == 0) {
			system("pause");
			system("cls");
		} else {
			--firstBucle;
		}


		choice = menu(arrayEmployee, MAX);

		switch (choice) {
		case 1:

			flagCorrectData = enterEmployeeData(arrayEmployee, MAX, &temp);

			if (flagCorrectData != -1)
				addEmployee(arrayEmployee, MAX, temp.id, temp.name,
						temp.lastName, temp.salary, temp.sector);
			flagCorrectData = 0;
			break;
		case 2:
			printf("Ingrese el numero del legajo que desea modificar\n");
			scanf("%d", &idEntry);

			arraySearched = findEmployeeById(arrayEmployee, MAX, idEntry);
			printf("Se completo la busqueda del legajo %i \n",
					arrayEmployee[arraySearched].id);
			printf("Que desea modificar?\n");
			printf("1 - Nombre : %s  \n", arrayEmployee[arraySearched].name);
			printf("2 - Apellido: %s \n",
					arrayEmployee[arraySearched].lastName);
			printf("3 - Salario : %f \n", arrayEmployee[arraySearched].salary);
			printf("4 - Sector : %d\n", arrayEmployee[arraySearched].sector);

			int option2;
			scanf("%i", &option2);

			switch (option2) {

			case 1:

				fflush(stdin);
				flagOk = setString(temp.name, "Ingrese el nombre del empleado",
						"Ingreso de nombre cancelado", 2, 25, 3);
				break;
			case 2:

				fflush(stdin);
				flagOk = setString(temp.lastName,
						"Ingrese el apellido del empleado",
						"Ingreso de apellido cancelado", 2, 25, 3);
				break;
			case 3:

				flagOk = setFloat(&temp.salary,
						"Ingrese el salario del empleado(1000-200.000)",
						"Ingreso de salario cancelado", 1000, 200000, 3);

				break;
			case 4:

				fflush(stdin);

				flagOk = setInt(&temp.sector,
						"Ingrese el sector del empleado(1-6)",
						"Ingreso de sector cancelado", 1, 6, 3);
				break;
			}
			if (flagOk == 0) {
				switch (option2) {
				case 1:
					strcpy(arrayEmployee[arraySearched].name, temp.name);
					break;

				case 2:
					strcpy(arrayEmployee[arraySearched].lastName,
							temp.lastName);
					break;
				case 3:
					arrayEmployee[arraySearched].salary = temp.salary;
					break;
				case 4:
					arrayEmployee[arraySearched].sector = temp.sector;
					break;

				}
			} else {
				printf("Modificacion cancelada\n");
			}
			break;
		case 3:
			;												//baja

			char confirmation3 = 'n';

			do {

				printf(
						"Ingrese el numero del legajo del cual desea borrar los datos\n");
				scanf("%d", &idEntry);

				int arraySearched = findEmployeeById(arrayEmployee, MAX,
						idEntry);
				if (arraySearched != -1) {
					printf("Se completo la busqueda del legajo %i \n",
							arrayEmployee[arraySearched].id);

					printf("Nombre y Apellido: %s %s \n",
							arrayEmployee[arraySearched].name,
							arrayEmployee[arraySearched].lastName);
					printf("Salario : %.2f \n",
							arrayEmployee[arraySearched].salary);
					printf("Sector : %d\n",
							arrayEmployee[arraySearched].sector);
					printf(
							"Desea borrar los datos del empleado y dejar el numero de legajo libre?(s/n)\n");

					fflush(stdin);
					scanf("%c", &confirmation3);
				}

				if (confirmation3 == 's') {
					strcpy(arrayEmployee[arraySearched].name, "Empty");
					strcpy(arrayEmployee[arraySearched].lastName, "Empty");
					arrayEmployee[arraySearched].salary = 0;
					arrayEmployee[arraySearched].sector = 0;
					arrayEmployee[arraySearched].isEmpty = 1;
					confirmation3 = 's';
					printf("Operación realizada\n");
				} else {
					arraySearched = -1;
				}

				if (arraySearched == -1) {
					printf("Operacion Cancelada\n");
					confirmation3 = 's';
				}
			} while (confirmation3 != 's');

			break;
		case 4:
			;										//informar
			char menu4;

			do {

				printf("1. Listado de empleados ordenado alfabeticamente y por sector\n");
				printf("2. Suma de salarios, promedio y cantidad de empleados por encima de el\n");
				fflush(stdin);
				scanf("%c", &menu4);

				if (menu4 != '1' && menu4 != '2' && menu4 != 's')
					printf("Opcion Incorrecta\n");

				switch (menu4) {
				case '1':

					orderEmployeesByLastName(arrayEmployee, MAX);

					break;
				case '2':
					printEmployees(arrayEmployee, MAX);
					;
					int contSalaries = 0;
					int contSalariesBiggerThanAverage = 0;
					float totalSalaries = 0;
					for (int i = 0; i < MAX; i++) {
						if (arrayEmployee[i].isEmpty == 0) {
							++contSalaries;
							totalSalaries += arrayEmployee[i].salary;
						}
					}

					float averageSalary = totalSalaries / (float) contSalaries;
					for (int i = 0; i < MAX; i++) {
						if (arrayEmployee[i].isEmpty == 0
								&& arrayEmployee[i].salary >= averageSalary) {
							++contSalariesBiggerThanAverage;
						}
					}

					printf(
							"El total de los salarios es %.2f y su promedio es %.2f.\n",
							totalSalaries, averageSalary);
					printf(
							"La cantidad de empleados que suman el salario promedio es %d\n",
							contSalariesBiggerThanAverage);

					break;
				}

			} while (menu4 != '1' && menu4 != '2' && menu4 != 's');
			printf("Volvemos al menu\n");
			break;
		case 5:											//salir

			printf("Esta seguro de salir?(s/n)\n");
			char exitKey;

			fflush(stdin);
			scanf("%c", &exitKey);
			if (exitKey != 's' && exitKey != 'S') {
				choice = 0;
				printf("Eligio no salir\n");
			}
			break;
		}

	} while (choice != 5);

	printf("Adios!");

	return EXIT_SUCCESS;
}

