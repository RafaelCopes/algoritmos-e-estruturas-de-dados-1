#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Rafael Montagna Copes
// 19100930

// Eu programo eu inglês para o código poder
// ser lido por todo mundo.

// Fiz usando somente ponteiros.

#define MAX_NAME_SIZE 20

typedef struct {
    int i;
    int j;
    int k;
    int op;
    int nameCounter;
    char tmpName[MAX_NAME_SIZE];
} Variables;

void addName();
void deleteName();
void listNames();

void *pBuffer;
Variables *variables;

int main() {
    pBuffer = malloc(sizeof(Variables));

    if (pBuffer == NULL) {
        printf("Error in memory allocation!\n");
        return 0;
    }
 
    variables = pBuffer;

    variables->op = 0;
    variables->nameCounter = 0;

    while (variables->op != 4) {

        printf("Choose an option:\n\n");
        printf("1: Add Name\n");
        printf("2: Remove Name\n");
        printf("3: List Names\n");
        printf("4: Exit\n\n");
        printf("Option: ");
        scanf("%d", &variables->op);

        switch (variables->op)
        {
            case 1: 
               addName();
            break;
            case 2: 
               deleteName();
            break; 
            case 3: 
               listNames();
            break; 
            case 4: 
                printf("\nBye!\n\n");
            break; 
            default:
                printf("\n\nInvalid Option.\n\n");
            break;
        }
    }

    free(pBuffer);

    return 0;
}

void addName() {
    pBuffer = realloc(pBuffer, (sizeof(Variables) + ((variables->nameCounter + 1) * (MAX_NAME_SIZE * sizeof(char)))));

    variables = pBuffer;
        
    printf("\nName: ");
    scanf("%s", variables->tmpName);
    getchar();

    char *name;
    name = pBuffer + (sizeof(Variables) + (variables->nameCounter * (MAX_NAME_SIZE * sizeof(char))));

    strcpy(name, variables->tmpName);

    variables->nameCounter++;

    printf("\nThe name was added to the buffer!\n\n");
};

void deleteName() {
    printf("\nWhich name do you want to delete? ");
    scanf("%s", variables->tmpName);
    getchar();

    variables->j = 0;
    
    for (variables->i = 0; variables->i < variables->nameCounter; variables->i++) {
        char *name;
        name = pBuffer + (sizeof(Variables) + ((variables->i) * (MAX_NAME_SIZE * sizeof(char))));

        if (variables-> j == 1) {
            variables->k = variables->i - 1; 

            char *nameToDelete;
            nameToDelete = pBuffer + (sizeof(Variables) + ((variables->k) * (MAX_NAME_SIZE * sizeof(char))));

            strcpy(nameToDelete, name);
        } else if (strcmp(name, variables->tmpName) == 0) {
            variables->j = 1;
        }
    }

    if (variables->j == 1) {
        printf("\nThe name has been deleted!\n\n");

        variables->nameCounter--;

        pBuffer = realloc(pBuffer, (sizeof(Variables) + (variables->nameCounter * (MAX_NAME_SIZE * sizeof(char)))));

        variables = pBuffer;
    } else {
        printf("\nName not found!\n\n");
    }
};

void listNames() {
    if (variables->nameCounter > 0) {
        printf("\nThere are %d names in the buffer:\n\n", variables->nameCounter);

        for (variables->i = 0; variables->i < variables->nameCounter; variables->i++) {
            char *name;
            name = pBuffer + (sizeof(Variables) + (variables->i * (MAX_NAME_SIZE * sizeof(char))));

            printf("%s", name);
        }
    } else {
        printf("\nThere buffer is empty.");
    }
    printf("\n\n");
};
