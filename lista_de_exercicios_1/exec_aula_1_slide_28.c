#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Rafael Montagna Copes
// 19100930

// Eu programo eu inglês para o código poder
// ser lido por todo mundo.

// Fiz usando somente ponteiros.

#define MAX_NAME_SIZE 20

typedef struct _contact {
    char name[MAX_NAME_SIZE];
    long int number;
} Contact;

typedef struct _variables {
    int i;
    int j;
    int k;
    int op;
    int contactQuantity;
    char name[MAX_NAME_SIZE];
    long int number;
} Variables;

void addContact() ;
void deleteContact();
void listContacts();
int contactNameExists(char *name);

void *pBuffer;
Variables *variables;

int main() {
    pBuffer = malloc(sizeof(Variables));

    if (pBuffer == NULL) {
        printf("Error in memory allocation!\n");
        return 0;
    }

    variables = pBuffer;
    variables->contactQuantity = 0;
    variables->op = 0;

    while (variables->op != 4) {

        printf("Choose an option:\n\n");
        printf("1: Add Contact\n");
        printf("2: Remove Contact\n");
        printf("3: List Contacts\n");
        printf("4: Exit\n\n");
        printf("Option: ");
        scanf("%d", &variables->op);

        switch (variables->op)
        {
            case 1:
               addContact();
            break;
            case 2: 
               deleteContact();
            break; 
            case 3: 
               listContacts();
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

int contactNameExists(char *name) {
    for (variables->i = 0; variables->i < variables ->contactQuantity; variables->i++) {
        Contact *contact;
        contact = pBuffer + (sizeof(Variables) + ((variables->i) * sizeof(Contact)));

        if (strcasecmp(name, contact->name) == 0) {
            return 1;
        }
    }
    return 0;
}

void addContact() {
    pBuffer = realloc(pBuffer, sizeof(Variables) + ((variables->contactQuantity + 1) * sizeof(Contact)));
    variables = pBuffer;

    printf("\nContact Name: ");
    scanf("%s", variables->name);
    getchar();

    if (contactNameExists(variables->name)) {
        printf("\nThis name already exists in the agenda!\n\n");

        return;
    }

    printf("Contact Number: ");
    scanf("%ld", &variables->number);

    Contact *newContact;
    newContact = pBuffer + (sizeof(Variables) + ((variables->contactQuantity) * sizeof(Contact)));

    strcpy(newContact->name, variables->name);
    newContact->number = variables->number;

    variables->contactQuantity++;
    printf("\nThe new contact has been added!\n\n");
}

void deleteContact() {
    printf("\nWhat contact do you want to remove? ");
    scanf("%s", variables->name);
    getchar();

    variables->j = 0;

    for (variables->i = 0; variables->i < variables->contactQuantity; variables->i++) {
        Contact *contact;
        contact = pBuffer + (sizeof(Variables) + ((variables->i) * sizeof(Contact)));

        if (variables->j == 1) {
            variables->k = variables->i - 1;

            Contact *personToDelete;
            personToDelete = pBuffer + (sizeof(Variables) + ((variables->k) * sizeof(Contact)));
            
            strcpy(personToDelete->name, contact->name);
            personToDelete->number = contact->number;
        } else if (strcmp(contact->name, variables->name) == 0) {
            variables->j = 1;
        }
    }

    if (variables->j == 1) {
        printf("\nThe contact has been deleted!\n\n");
        
        variables->contactQuantity--;

        pBuffer = realloc(pBuffer, (sizeof(Variables) + ((variables->contactQuantity) * sizeof(Contact))));

        variables = pBuffer;
    } else {
        printf("\nName not found!\n\n");
    }
}

void listContacts() {
    if (variables->contactQuantity > 0) {
        printf("\nYou have %d contacts in your agenda:\n\n", variables->contactQuantity);

        for (variables->i = 0; variables->i < variables->contactQuantity; variables->i++) {
        Contact *contact;
        contact = pBuffer + (sizeof(Variables) + ((variables->i) * sizeof(Contact)));

        printf("Name: %s - Number: %ld\n", contact->name, contact->number);
    }
    } else {
        printf("\nYou do not have any contact in your agenda.\n");
    }
    
    printf("\n");
}