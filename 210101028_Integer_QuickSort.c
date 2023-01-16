#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int*a, int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
        i++;
        swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quickSort(int*a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}


int main() {
    int m=10;
    long long n=10000;
    char cfile[] = "i10k.txt";
    char qfile[] = "qi10k.txt";

    FILE *fo;
    fo = fopen("210101028-output.txt","a");
    fprintf(fo,"--------------------------------------------------------------\n");
    fprintf(fo,"                       Quick Sort                             \n");
    fprintf(fo,"--------------------------------------------------------------\n");
    fprintf(fo,"Description        Only Sorting    Sorting & Writing to File  \n");
    fprintf(fo,"--------------------------------------------------------------\n");
    fclose(fo);

    for(int x=0; x<10; x++){
        double time_sort=0.0;
        double time_sortwrite=0.0;
        clock_t begin = clock();

        sprintf(cfile, "i%dk.txt", m);
        sprintf(qfile, "qi%dk.txt", m);

        FILE *fp;
        fp = fopen(cfile, "r");
        int* q = (int*)malloc(n*sizeof(int));
        int num=0;
        for(int i=0; i<n; i++){
            fscanf(fp, "%d", &q[i]);
        }
        fclose(fp);

        clock_t begin1 = clock();
        quickSort(q, 0, n-1);

        clock_t end1 = clock();
        FILE *fq;
        fq = fopen(qfile, "w");
        for(int i=0; i<n; i++){
            fprintf(fq, "%d\n", q[i]);
        }
        fclose(fq);
        clock_t end = clock();
        free(q);
        time_sort = (double)(end1-begin1)/CLOCKS_PER_SEC;
        time_sortwrite = (double)(end-begin)/CLOCKS_PER_SEC;

        FILE *fo;
        fo = fopen("210101028-output.txt","a");
        fprintf(fo, "Integers %dK \t %.3f \t %.3f \n", m, time_sort, time_sortwrite);
        fclose(fo);
        m*=2; n*=2;
    }
}