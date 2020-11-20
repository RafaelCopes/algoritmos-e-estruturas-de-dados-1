#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 20

typedef struct _contact {
    char name[MAX_NAME_SIZE];
    unsigned long int number;
} Contact;

typedef struct _doubly_linked_list_node {
    Contact *contact;
    struct _doubly_linked_list_node *prev;
    struct _doubly_linked_list_node *next;
} DoublyLinkedListNode;

typedef struct _priority_queue_node {
    Contact *contact;
    struct _priority_queue_node *next;
} PriorityQueueNode;

typedef struct _variables {
    int i;
    int j;
    int k;
    int op;
    int parameter;
    int contactQuantity;
    int queueQuantity;
    int listQuantity;
    char name[MAX_NAME_SIZE];
    long int number;
} Variables;

void addContact();
void deleteContact();
void listContacts();
int contactNameExists(char *name);
void orderedListing();
DoublyLinkedListNode* newDoublyLinkedListNode(Contact *contact);
void pushToLinkedList(Contact *contact);
void deleteLinkedListNode(DoublyLinkedListNode* node);
void popFromLinkedList(Contact *contact);
void printLinkedList();
PriorityQueueNode* newPriorityQueueNode(Contact *contact);
void pushToQueueAlphabetically(PriorityQueueNode **queueHead, Contact *contact);
void pushToQueueByNumber(PriorityQueueNode **queueHead, Contact *contact);
void printQueue(PriorityQueueNode **queueHead);
void freeQueue();

void *pBuffer = NULL;
Variables *variables = NULL;
DoublyLinkedListNode *listHead = NULL;

int main() {
    pBuffer = malloc(sizeof(Variables));

    if (pBuffer == NULL) {
        printf("Error in memory allocation!\n");

        return 0;
    }

    variables = pBuffer;

    variables->contactQuantity = 0;
    variables->queueQuantity = 0;
    variables->listQuantity = 0;
    variables->op = 0;

    while (variables->op != 6) {

        printf("Choose an option:\n\n");
        printf("1: Add Contact\n");
        printf("2: Remove Contact\n");
        printf("3: List Contacts\n");
        printf("4: Ordered Listing\n");
        printf("5: Print Doubly Linked List\n");
        printf("6: Exit\n\n");
        printf("Option: ");
        scanf("%d", &variables->op);

        switch (variables->op) {
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
                printf("\nWhats the ordination parameter?\n\n");
                printf("1: Alphabetically\n");
                printf("2: By number\n\n");
                printf("Option: ");
                scanf("%d", &variables->parameter);

                orderedListing();
            break; 
            case 5: 
                printLinkedList();
            break;  
            case 6: 
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
    DoublyLinkedListNode **tracer = &listHead;

    while(*tracer) {
        if (strcasecmp(name, (*tracer)->contact->name) == 0) return 1;

        tracer = &(*tracer)->next;
    }

    return 0;
}

void addContact() {
    pBuffer = realloc(pBuffer, sizeof(Variables) + ((variables->contactQuantity + 1) * sizeof(Contact)));

    printf("\nContact Name: ");
    scanf("%s", variables->name);
    getchar();

    if (contactNameExists(variables->name)) {
        printf("\nThis name already exists in the agenda!\n\n");

        return;
    }

    printf("Contact Number: ");
    scanf("%ld", &variables->number);

    Contact *newContact = pBuffer + (sizeof(Variables) + ((variables->contactQuantity) * sizeof(Contact)));

    strcpy(newContact->name, variables->name);
    newContact->number = variables->number;

    variables->contactQuantity++;

    printf("\nThe new contact has been added!\n\n");

    pushToLinkedList(newContact);
}

void deleteContact() {
    printf("\nWhat contact do you want to remove? ");
    scanf("%s", variables->name);
    getchar();

    variables->j = 0;

    for (variables->i = 0; variables->i < variables->contactQuantity; variables->i++) {
        Contact *contact = pBuffer + (sizeof(Variables) + ((variables->i) * sizeof(Contact)));

        if (variables->j == 1) {
            variables->k = variables->i - 1;

            Contact *personToDelete = pBuffer + (sizeof(Variables) + ((variables->k) * sizeof(Contact)));
            
            strcpy(personToDelete->name, contact->name);
            personToDelete->number = contact->number;

        } else if (strcmp(contact->name, variables->name) == 0) {
            variables->j = 1;
            popFromLinkedList(contact);
        }
    }

    if (variables->j == 1) {
        printf("\nThe contact has been deleted!\n\n");
        
        variables->contactQuantity--;

        pBuffer = realloc(pBuffer, (sizeof(Variables) + ((variables->contactQuantity) * sizeof(Contact))));
    } else 
        printf("\nName not found!\n\n");
}

void listContacts() {
    if (variables->contactQuantity > 0) {
        printf("\nYou have %d contacts in your agenda:\n\n", variables->contactQuantity);

        for (variables->i = 0; variables->i < variables->contactQuantity; variables->i++) {
            Contact *contact = pBuffer + (sizeof(Variables) + ((variables->i) * sizeof(Contact)));

            printf("Name: %s - Number: %ld\n", contact->name, contact->number);
        }
    } else
        printf("\nYou do not have any contact in your agenda.\n");
    
    printf("\n");
}

DoublyLinkedListNode* newDoublyLinkedListNode(Contact *contact) {
    DoublyLinkedListNode *newNode = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));

    if (newNode == NULL) {
        printf("Error in memory allocation!\n");

        return 0;
    }

    newNode->contact = contact;
    newNode->prev = NULL;
    newNode->next = NULL;

    variables->listQuantity++;

    return newNode;
};

void pushToLinkedList(Contact *contact) {
    DoublyLinkedListNode **tracer = &listHead;
    DoublyLinkedListNode **prev = NULL;

    DoublyLinkedListNode *node = newDoublyLinkedListNode(contact);

    while (*tracer) {
        prev = tracer;
        tracer = &(*tracer)->next;
    }

    node->next = *tracer;

    if (prev)
        node->prev = *prev;

    *tracer = node;
};

void deleteLinkedListNode(DoublyLinkedListNode* node) { 
    if (listHead == NULL || node == NULL) return; 
    
    variables->listQuantity--;
    
    if (listHead == node) 
        listHead = node->next; 
  
    if (node->next != NULL) 
        node->next->prev = node->prev; 
  
    if (node->prev != NULL) 
        node->prev->next = node->next; 
    
    free(node); 
} 

void popFromLinkedList(Contact *contact) {
    DoublyLinkedListNode **tracer = &listHead;

    while ((*tracer) && (strcmp((*tracer)->contact->name, contact->name) != 0))
        tracer = &(*tracer)->next;

    deleteLinkedListNode(*tracer);
};

void printLinkedList() {
    if (variables->listQuantity > 0) {
        DoublyLinkedListNode **tracer = &listHead;

        printf("\nThe created Doubly Linked List is: \n\n");

        while(*tracer) {
            printf("Name: %s - Number: %ld\n", (*tracer)->contact->name, (*tracer)->contact->number);
            tracer = &(*tracer)->next;
        }

        printf("\n");
    } else 
        printf("\nThere are no contacts on the Linked List!\n\n");
};

PriorityQueueNode* newPriorityQueueNode(Contact *contact) {
    pBuffer = realloc(pBuffer, sizeof(Variables) + ((variables->contactQuantity) * sizeof(Contact)) + ((variables->queueQuantity + 1) * sizeof(PriorityQueueNode)));

    PriorityQueueNode *newNode = pBuffer + (sizeof(Variables) + ((variables->contactQuantity) * sizeof(Contact)) + ((variables->queueQuantity) * sizeof(PriorityQueueNode)));

    newNode->contact = contact;
    newNode->next = NULL;

    variables->queueQuantity++;

    return newNode;
};

void pushToQueueAlphabetically(PriorityQueueNode **queueHead, Contact *contact) {
    PriorityQueueNode **tracer = queueHead;
    
    PriorityQueueNode *node = newPriorityQueueNode(contact);

    while ((*tracer) && (strcmp((*tracer)->contact->name, contact->name) < 1)) 
        tracer = &(*tracer)->next;

    node->next = *tracer;
    *tracer = node;
};

void pushToQueueByNumber(PriorityQueueNode **queueHead, Contact *contact) {
    PriorityQueueNode **tracer = queueHead;

    PriorityQueueNode *node = newPriorityQueueNode(contact);

    while((*tracer) && ((*tracer)->contact->number < contact->number))
        tracer = &(*tracer)->next;

    node->next = *tracer;
    *tracer = node;
};

void printQueue(PriorityQueueNode **queueHead) {
    PriorityQueueNode **tracer = queueHead;

    while (*tracer) {
        printf("Name: %s - Number: %ld\n", (*tracer)->contact->name, (*tracer)->contact->number);
        tracer = &(*tracer)->next;
    }

    printf("\n");
};

void freeQueue() {
    pBuffer = realloc(pBuffer, sizeof(Variables) + ((variables->contactQuantity) * sizeof(Contact)));

    variables->queueQuantity = 0;
};

void orderedListing() {
    if (variables->listQuantity > 0) {
        DoublyLinkedListNode **tracer = &listHead;
        PriorityQueueNode *queueHead = NULL;

        switch (variables->parameter) {
            case 1:
                printf("\nQueue of contacts ordered alphabetically:\n\n");
        
                while(*tracer) {
                    Contact *contact = (*tracer)->contact;
                    tracer = &(*tracer)->next;

                    pushToQueueAlphabetically(&queueHead, contact);   
                }
            break;
            case 2:
                printf("\nQueue of contacts ordered by number:\n\n");
        
                while(*tracer) {
                    Contact *contact = (*tracer)->contact;
                    tracer = &(*tracer)->next;

                    pushToQueueByNumber(&queueHead, contact);   
                }
            break;
            default:
                printf("\nInvalid Option.\n\n");
            break;
        }

        printQueue(&queueHead);
        freeQueue();
    } else {
        printf("\nYou do not have any contact in your agenda.\n\n");
    }
};
