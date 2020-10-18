#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Rafael Montagna Copes
// 19100930

// Eu programo eu inglês para o código poder
// ser lido por todo mundo.

// Fiz usando somente ponteiros.

// Estou considerando que todos os inputs do
// usuário sejam válidos.

int** createMatrix(int m, int n) ;
void readMatrix(int **matrix, int m, int n);
int sumMatrix(int **matrix, int m, int n);
int* columnMatrix(int **matrix, int m, int nColumn);
void freeMatrix(int **matrix, int m);
void printMatrix(int **matrix ,int m, int n);
void printVector(int *vector, int n);

typedef struct {
   int op;
   int m;
   int n;
   int sum;
   int nColumn;
   int created;
} Variables;

Variables *variables;

int main() {
   int **matrix;
   int *vector;

   variables = (Variables*)malloc(sizeof(Variables));
   variables->created = 0;
   variables->m = 0;
   variables->n = 0;
   variables->op = 0;

   while (variables->op != 6) {

      printf("Choose an option:\n\n");
      printf("1: Create/Resize Matrix M x N\n");
      printf("2: Read Matrix Elements\n");
      printf("3: Sum of the Matrix Elements\n");
      printf("4: Get the Elements at a certain Column\n");
      printf("5: Print Matrix\n");
      printf("6: Exit\n\n");
      printf("Option: ");
      scanf("%d", &variables->op);

      switch (variables->op)
      {
         case 1:
            printf("\nNumber of columns: ");
            scanf("%d", &variables->n);

            printf("Number of rows: ");
            scanf("%d", &variables->m);

            printf("\n");

            matrix = createMatrix(variables->m, variables->n);
         break;
         case 2: 
            if ((variables->m && variables->n) == 1) {
               printf("\nFill up the matrix: \n");

               readMatrix(matrix, variables->m, variables->n);

               variables->created = 1;

               printf("\n");
            } else {
               printf("\nYou have not created a Matrix!\n\n");
            }
         break; 
         case 3: 
            if ((variables->m && variables->n && variables->created) == 1) {
               variables->sum = sumMatrix(matrix, variables->m, variables->n);

               printf("\nThe sum of the matrix elements is: %d\n\n", variables->sum);
            } else {
               printf("\nYou have not created or filled a Matrix!\n\n");
            }      
         break; 
         case 4: 
            if ((variables->m && variables->n && variables->created) == 1) {
               printf("\nWhich column: ");
               scanf("%d", &variables->nColumn);

               vector = columnMatrix(matrix, variables->m, variables->nColumn);

               printf("\n");
               printVector(vector, variables->m);
               printf("\n");
            } else {
               printf("\nYou have not created or filled a Matrix!\n\n");
            }      
         break; 
         case 5: 
            if ((variables->m && variables->n && variables->created) == 1) {
               printf("\n");
               printMatrix(matrix, variables->m, variables->n);
               printf("\n");
            } else {
               printf("\nYou have not created or filled a Matrix!\n\n");
            }    
         break; 
         case 6: 
               printf("\nBye!\n\n");
         break; 
         default:
               printf("\nInvalid Option.\n\n");
         break;
      }
   }

   if ((variables->m && variables->n) == 1) {
      freeMatrix(matrix, variables->m);
      
      if (variables->created == 1) {
         free(vector);
      }
   }

   free(variables);

   return 0;
}

int** createMatrix(int m, int n) {
   int **matrix;

   matrix = (int**)malloc(n * sizeof(int*));

   if (matrix == NULL) {
      printf("Error in memory allocation!\n");
      return NULL;
   }

   for (int i = 0; i < n; i++) {
      matrix[i] = (int*)malloc(m * sizeof(int));

      if (matrix[i] == NULL) {
         printf("Error in memory allocation!\n");
         return NULL;
      }
   }

   return matrix;
};

void readMatrix(int **matrix, int m, int n) {
   for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }
};

int sumMatrix(int **matrix, int m, int n) {
   int sum = 0;

   for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         sum += matrix[i][j];
      }
   }

   return sum;
};

int* columnMatrix(int **matrix, int m, int nColumn) {
   int *vector;
   vector = (int*)malloc(m * sizeof(int));

   if (vector == NULL) {
      printf("Error in memory allocation!\n");
   }

   for(int i = 0; i < m; i++) {
      vector[i] = matrix[i][nColumn];
   }

   return vector;
};

void freeMatrix(int **matrix, int m) {
   for (int i = 0; i < m; i++) {
      free(matrix[i]);
   }

   free(matrix);
};

void printMatrix(int **matrix, int m, int n) {
   for (int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
         printf("%d ", matrix[i][j]);
      }
      printf("\n");
   }
};

void printVector(int *vector, int n) {
   for (int i = 0; i < n; i++) {
      printf("%d ", vector[i]);
   }
   
   printf("\n");
};
