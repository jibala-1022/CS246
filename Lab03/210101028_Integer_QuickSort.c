#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
        i++;
        swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}


int main() {
    int n,m;
    printf("Hello\n");
    // Integer input
    n=10000, m=10;
    char cfile[] = "i10k.txt";
    char qfile[] = "qi10k.txt";
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
        free(q);
        m*=2; n*=2;
        clock_t end = clock();
        printf("bye\n");
        time_sort = (double)(end1-begin1)/CLOCKS_PER_SEC;
        time_sortwrite = (double)(end-begin)/CLOCKS_PER_SEC;
        printf("Time to only sort : %f seconds\n", time_sort);
        printf("Time to sort and write : %f seconds\n", time_sortwrite);
    }
}