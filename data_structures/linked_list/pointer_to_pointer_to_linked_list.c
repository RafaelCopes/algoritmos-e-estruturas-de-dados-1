#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _player { 
	char *name;
	struct _player *next;
} PLAYER;

PLAYER *head = NULL;

PLAYER* newPlayer(char *text);
void insertPlayer(PLAYER **head, PLAYER *player);
void removePlayer(PLAYER **head, char *text);
void printList(PLAYER **head);

int main() {
    insertPlayer(&head, newPlayer("zzzz"));
    insertPlayer(&head, newPlayer("aaaa"));
    insertPlayer(&head, newPlayer("yyyy"));
    insertPlayer(&head, newPlayer("dddd"));
    insertPlayer(&head, newPlayer("bbbbb"));

    printList(&head);

    return 0;
}                  

PLAYER* newPlayer(char *text) {
    PLAYER *newPlayer = (PLAYER*)malloc(sizeof(PLAYER));
    newPlayer->name = (char*)malloc(strlen(text) + 1);
    strcpy(newPlayer->name, text);
    newPlayer->next = NULL;

    return newPlayer;
};

void insertPlayer(PLAYER **head, PLAYER *player) {
    PLAYER **tracer;
    tracer = head;

    while ((*tracer) && (strcmp((*tracer)->name, player->name) < 1)) {
        tracer = &(*tracer)->next;
    }

    player->next = *tracer;
    *tracer = player;
};

void removePlayer(PLAYER **head, char *text);

void printList(PLAYER **head) {
    PLAYER **tracer;
    tracer = head;

    while (*tracer) {
        printf("%s \n", (*tracer)->name);
        tracer = &(*tracer)->next;
    }
};