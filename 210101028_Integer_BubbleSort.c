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
    printf("Hello\n");
    // Integer input
    n=10000, m=10;
    char cfile[] = "i10k.txt";
    char bfile[] = "bi10k.txt";
    for(int x=0; x<10; x++){
        double time_sort=0.0;
        double time_sortwrite=0.0;
        clock_t begin = clock();
        sprintf(cfile, "i%dk.txt", m);
        sprintf(bfile, "bi%dk.txt", m);
        FILE *fp;
        fp = fopen(cfile, "r");
        int* b = (int*)malloc(n*sizeof(int));
        int num=0;
        for(int i=0; i<n; i++){
            fscanf(fp, "%d", &b[i]);
        }
        fclose(fp);
        clock_t begin1 = clock();
        bubbleSort(b, n);
        clock_t end1 = clock();
        FILE *fb;
        fb = fopen(bfile, "w");
        for(int i=0; i<n; i++){
            fprintf(fb, "%d\n", b[i]);
        }
        fclose(fb);
        free(b);
        m*=2; n*=2;
        clock_t end = clock();
        time_sort += (double)(end1-begin1)/CLOCKS_PER_SEC;
        time_sortwrite += (double)(end-begin)/CLOCKS_PER_SEC;
        printf("bye\n");
        printf("Time to only sort : %f seconds\n", time_sort);
        printf("Time to sort and write : %f seconds\n", time_sortwrite);
    }
    return 0;
}