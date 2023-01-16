#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int*y1, int*m1, int*d1, int*y2, int*m2, int*d2) {
    int t=*y1; *y1=*y2; *y2=t;
    t=*m1; *m1=*m2; *m2=t;
    t=*d1; *d1=*d2; *d2=t;
}
int comp(int y1, int m1, int d1, int y2, int m2, int d2) {
    if(y1>y2) return 1;
    if(y1<y2) return 0;
    if(m1>m2) return 1;
    if(m1<m2) return 0;
    if(d1>d2) return 1;
    return 0;
}

void bubbleSort(int* y, int* m, int* d, int n){
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(comp(y[j],m[j],d[j],y[j+1],m[j+1],d[j+1])){
                swap(&y[j],&m[j],&d[j],&y[j+1],&m[j+1],&d[j+1]);
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
        int *y = (int*)malloc(n*sizeof(int));
        int *m = (int*)malloc(n*sizeof(int));
        int *d = (int*)malloc(n*sizeof(int));
        char junk,juk,c1,c2,c3;
        for(int i=0; i<n; i++){
            fscanf(fp, "%d%c%c%c%c%c%d", &d[i], &junk, &c1, &c2, &c3, &juk, &y[i]);
            m[i] = monthIndex(c1,c2,c3);
        }
        fclose(fp);

        bubbleSort(y, m, d, n);

        FILE *fb;
        fb = fopen(bfile, "w");
        for(int i=0; i<n; i++){
            fprintf(fb, "%02d-%s-%d\n", d[i], months[m[i]], y[i]);
        }
        fclose(fb);
        free(y);
        free(m);
        free(d);
        m1*=2; n*=2;
    }
    return 0;
}