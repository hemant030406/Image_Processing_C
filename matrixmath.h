#ifndef MATRIX
#define MATRIX

typedef struct matrixDef{
    int m,n;
    float **A;
} MD;

void create_matrix(MD*,int,int);
void assign_value(MD*);
void print(MD*);
void multiply(MD*,MD*,MD*);
void memfree(MD*);

#endif