#include <stdio.h>
#include "matrixmath.h"
#include "grayscale.h"

int main(){
    MD a,b,p;
    create_matrix(&a,2,2);
    create_matrix(&b,2,2);
    create_matrix(&p,2,2);
    assign_value(&a);
    assign_value(&b);
    multiply(&p,&a,&b);
    // print(&p);
    memfree(&a);
    memfree(&b);
    memfree(&p);
    
    grayscale();

    return 0;
}