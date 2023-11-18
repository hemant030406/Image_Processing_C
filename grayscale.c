#include <stdio.h>
#include "matrixmath.h"

void grayscale(){
    FILE *inf,*outf;
    inf = fopen("./img.ppm","r");

    char imgType[10];
    int height,width,colSize;
    float R,G,B;

    fscanf(inf,"%s",imgType);
    fscanf(inf,"%d %d",&height,&width);
    fscanf(inf,"%d",&colSize);

    MD RED,GREEN,BLUE;

    create_matrix(&RED,1,height*width);
    create_matrix(&GREEN,1,height*width);
    create_matrix(&BLUE,1,height*width);

    int count = 0;
    while(fscanf(inf, "%f %f %f", &R,&G,&B) != EOF){
        RED.A[0][count] = R;
        GREEN.A[0][count] = G;
        BLUE.A[0][count] = B;
        count +=1;
    }

    outf = fopen("./grayscale.ppm","a");

    fprintf(outf,"%s\n","P2");
    fprintf(outf,"%d %d\n",height,width);
    fprintf(outf,"%d\n",colSize);

    for(int i=0; i<=RED.n;i++){
        fprintf(outf,"%d ",(int)(0.3*(RED.A[0][i]) + 0.59*(GREEN.A[0][i]) + 0.11*(BLUE.A[0][i])));
    }
    
    fclose(outf);
    fclose(inf);
}