/*
 * ArrayEmployees.h
 *
 *  Created on: 7 oct. 2020
 *      Author: Gaston
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct {

	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

} Employee;

int initEmployees(Employee *arrayEmployee, int len);
int menu(Employee *arrayEmployee, int len);

int printEmployees(Employee *arrayEmployee, int len);

int enterEmployeeData(Employee *arrayEmployee, int len, Employee *temp);
int addEmployee(Employee *arrayEmployee, int len, int id, char name[],
		char lastName[], float salary, int sector);

int findEmployeeById(Employee *arrayEmployee, int len, int id);

int orderEmployeesByLastName(Employee *arrayEmployee, int len);
#endif /* ARRAYEMPLOYEES_H_ */
