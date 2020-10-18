#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Eu programo eu inglês para o código poder
// ser lido por todo mundo.

// Fiz usando somente ponteiros.

// Foi necessário usar mais um argumento que chamei de oldSize,
// que pega o tamanho antigo do ponteiro, pois não é possível pegar
// de outra forma. 

void *myRealloc(void *oldPointer, size_t oldSize, size_t newSize);

int main() {
    char *p;

    p = (char*)malloc(6 * sizeof(char));

    if (p == NULL) {
        printf("Error in memory allocation!\n");
    }

    strcpy(p, "Hello");

    p = (char*)myRealloc(p, 6 * sizeof(char), 14 * sizeof(char));

    strcat(p, " Realloc");
    
    printf("\n%s\n\n", p);

    free(p);

    return 0;
}

void *myRealloc(void *oldPointer, size_t oldSize, size_t newSize) {
    if (oldPointer == NULL) {
        return malloc(newSize);
    }
    
    if (newSize == 0) {
        free(oldPointer);
        return NULL;
    }

    if (newSize <= oldSize) {
        return oldPointer;
    }

    void *newPointer;
    newPointer = malloc(newSize);

    if (newPointer == NULL) {
        printf("Error in memory reallocation!\n");
    }

    memcpy(newPointer, oldPointer, oldSize);

    free(oldPointer);

    return newPointer;
}
