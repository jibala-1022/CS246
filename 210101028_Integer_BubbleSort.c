#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int* a, int n){
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

int main(){
    int n,m;
    n=10000, m=10;
    char cfile[] = "i10k.txt";
    char bfile[] = "bi10k.txt";

    FILE *fo;
    fo = fopen("210101028-output.txt","a");
    fprintf(fo,"--------------------------------------------------------------\n");
    fprintf(fo,"                        Bubble Sort                            \n");
    fprintf(fo,"--------------------------------------------------------------\n");
    fprintf(fo,"Description        Only Sorting    Sorting & Writing to File  \n");
    fprintf(fo,"--------------------------------------------------------------\n");
    fclose(fo);

    for(int x=0; x<10; x++){
        double time_sort=0.0;
        double time_sortwrite=0.0;

        sprintf(cfile, "i%dk.txt", m);
        sprintf(bfile, "bi%dk.txt", m);

        FILE *fc;
        fc = fopen(cfile, "r");
        int* b = (int*)malloc(n*sizeof(int));
        int num=0;
        for(int i=0; i<n; i++){
            fscanf(fc, "%d", &b[i]);
        }
        fclose(fc);

        clock_t begin1 = clock();
        bubbleSort(b, n);

        clock_t begin2 = clock();
        FILE *fb;
        fb = fopen(bfile, "w");
        for(int i=0; i<n; i++){
            fprintf(fb, "%d\n", b[i]);
        }
        fclose(fb);
        free(b);

        clock_t end = clock();
        time_sort += (double)(end-begin2)/CLOCKS_PER_SEC;
        time_sortwrite += (double)(end-begin1)/CLOCKS_PER_SEC;

        FILE* fo;
        fo = fopen("210101028-output.txt","a");
        fprintf(fo, "Integers %dK \t\t %.3f \t\t %.3f \n", m, time_sort, time_sortwrite);
        fclose(fo);
        m*=2; n*=2;
    }
    return 0;
}