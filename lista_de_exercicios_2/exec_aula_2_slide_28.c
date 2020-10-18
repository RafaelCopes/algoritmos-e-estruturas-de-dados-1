#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Eu programo eu inglês para o código poder
// ser lido por todo mundo.

// Fiz usando somente ponteiros.

// Quando um nome for preenchido com 0
// vai sair do loop.

#define MAX_NAME_SIZE 30

typedef struct {
    char name[MAX_NAME_SIZE];
    int age;
    int height;
} Person;

void addName(int **nameCounter, Person *tmpPerson);
void listNames(int **nameCounter, int **loopHandler);

void *pBuffer; 

int main() {
    pBuffer = malloc((2 * sizeof(int)));

    if (pBuffer == NULL) {
        printf("Error in memory allocation!\n");
        return 0;
    }

    int *nameCounter;
    nameCounter = pBuffer;
    *nameCounter = 0;

    int *loopHandler;
    loopHandler = pBuffer + sizeof(int);
    *loopHandler = 0;

    while (1) {
        Person *tmpPerson;

        pBuffer = realloc(pBuffer, ((2 * sizeof(int)) + sizeof(Person) + ((*nameCounter + 1) * (sizeof(Person)))));

        nameCounter = pBuffer;
        loopHandler = pBuffer + sizeof(int);
        tmpPerson =  pBuffer + (2 * sizeof(int));

        
        printf("Name: ");
        scanf("%s", tmpPerson->name);

        if (strcmp(tmpPerson->name, "0") == 0) {
            break;
        }

        printf("Age: ");
        scanf("%d", &tmpPerson->age);


        printf("Height: ");
        scanf("%d", &tmpPerson->height);

        addName(&nameCounter, tmpPerson);
    }

    listNames(&nameCounter, &loopHandler);

    free(pBuffer);

    return 0;
}

void addName(int **nameCounter, Person *tmpPerson) {
    Person *person;
    person = pBuffer + ((2 * sizeof(int)) + sizeof(Person) + ((**nameCounter) * (sizeof(Person))));

    person->age = tmpPerson->age;
    person->height = tmpPerson->height;

    strcpy(person->name, tmpPerson->name);

    **nameCounter = **nameCounter + 1;

    printf("\nThe person data has been added!\n\n");
};

void listNames(int **nameCounter, int **loopHandler) {
    printf("\nThere are %d uploaded people:\n\n", **nameCounter);

    for (**loopHandler = 0; **loopHandler < **nameCounter; **loopHandler = **loopHandler + 1) {
        Person *person;
        person = pBuffer + ((2 * sizeof(int)) + sizeof(Person) + ((**loopHandler) * (sizeof(Person))));

        printf("Name: %s\n", person->name);
        printf("Age: %d\n", person->age);
        printf("Height: %d\n", person->height);
        printf("\n");
    }
};
