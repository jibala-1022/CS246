#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(long *a, long *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(long* a, int n){
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

int monthIndex(char c1, char c2, char c3){
    if(c1=='J' && c2=='a' && c3=='n') return 0;
    if(c1=='F' && c2=='e' && c3=='b') return 1;
    if(c1=='M' && c2=='a' && c3=='r') return 2;
    if(c1=='A' && c2=='p' && c3=='r') return 3;
    if(c1=='M' && c2=='a' && c3=='y') return 4;
    if(c1=='J' && c2=='u' && c3=='n') return 5;
    if(c1=='J' && c2=='u' && c3=='l') return 6;
    if(c1=='A' && c2=='u' && c3=='g') return 7;
    if(c1=='S' && c2=='e' && c3=='p') return 8;
    if(c1=='O' && c2=='c' && c3=='t') return 9;
    if(c1=='N' && c2=='o' && c3=='v') return 10;
    if(c1=='D' && c2=='e' && c3=='c') return 11;
    return 12;
}

int main(){
    int n,m1;
    n=10000, m1=10;
    char months[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char cfile[] = "i10k.txt";
    char bfile[] = "bd10k.txt";
    for(int x=0; x<10; x++){
        sprintf(cfile, "i%dk.txt", m1);
        sprintf(bfile, "bd%dk.txt", m1);

        FILE *fp;
        fp = fopen(cfile, "r");
        long* b = (long *)malloc(n*sizeof(long));
        char junk,juk,c1,c2,c3;
        for(int i=0; i<n; i++){
            long day, mon, year;
            fscanf(fp, "%d%c%c%c%c%c%d", &day, &junk, &c1, &c2, &c3, &juk, &year);
            mon = monthIndex(c1,c2,c3);
            b[i] = year*10000 + mon*100 + day;
        }
        fclose(fp);
        // printf("%d %d %d", d[0], m[0], y[0]);

        bubbleSort(b, n);

        // printf("%d %d %d", d[0], m[0], y[0]);
        FILE *fb;
        fb = fopen(bfile, "w");
        for(int i=0; i<n; i++){
            int monind = (b[i]/100) % 100;
            fprintf(fb, "%02d-%s-%d\n", b[i]%100, months[monind], b[i]/10000);
        }
        fclose(fb);
        free(b);
        m1*=2; n*=2;
    }
    return 0;
}