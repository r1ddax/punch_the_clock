#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Class Employee:
typedef struct Employee Employee;

struct Employee {
	// Parameters
	char name[16];
	char code[16];

	// Methods
	void (*ptrParamDefine)(Employee *);
};

// Prototypes Employee:
void settingEmployee(Employee *obj);
void defineParam(Employee *obj);
void tryGetChar(char stgwrite[32], char *p);
void print(Employee *obj);

// Program:
int main() {
	printf("\n --- [P1] New Object --- \n");
	Employee *P1 = (Employee *)calloc(1, sizeof(Employee));
	settingEmployee(P1);

	printf("\n --- [P2] New Object --- \n");
	Employee *P2 = (Employee *)calloc(1, sizeof(Employee));
	settingEmployee(P2);

	printf("\n --- Objects --- \n");
	printf(" > [P1] Name Object: %s \t\t [P2] Name Object: %s \n", P1->name, P2->name);
	printf(" > [P1] Code Object: %s \t\t [P2] Code Object: %s \n", P1->code, P2->code);

}

// Functions

void settingEmployee(Employee *obj) {
    // Creating Employee and defining name/codes.
	obj->ptrParamDefine = defineParam;
    obj->ptrParamDefine(obj);
}

void defineParam(Employee *obj) {
    // Call functions to define name, code and print.
    tryGetChar(" > Write the employee NAME: ", obj->name); // Str for name.
    tryGetChar(" > Write the employee CODE: ", obj->code); // Str for code.
    print(obj);
}

void tryGetChar(char stgwrite[32], char *p){
    // Function to get some char with 16 letter or less.
	char _select = 'n';

	while (_select != 'y')
	{
    int n; char ch;

        do
        {
		printf("\n%s",stgwrite);
		scanf("%15s", p);
		for (n = 0; (ch = getchar()) != '\n' && ch != EOF; ++n);
		if (n) printf("\n > Please try 16 chars or less");
        } while (n);

	printf("\n > You wrote <%s>, is it right? (y/n): ", p);
	scanf(" %c", &_select);
	_select = tolower(_select);
	}

}

void print(Employee *obj) {
    // Print name and code.
    printf("\n > Name: [%s] | > Code: [%s]\n", obj->name, obj->code);
}


/*

Author: r1ddax
Date: 04.14.21
Time: 12:18 AM
Relase: Document, Git, Github and Code organization.

*/