#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int*y1, int*m1, int*d1, int*y2, int*m2, int*d2, int*h1, int*mi1, int*s1, int*h2, int*mi2, int*s2) {
    int t=*y1; *y1=*y2; *y2=t;
    t=*m1; *m1=*m2; *m2=t;
    t=*d1; *d1=*d2; *d2=t;
    t=*h1; *h1=*h2; *h2=t;
    t=*mi1; *mi1=*mi2; *mi2=t;
    t=*s1; *s1=*s2; *s2=t;
}
int comp(int y1, int m1, int d1, int y2, int m2, int d2, int h1, int mi1, int s1, int h2, int mi2, int s2) {
    if(y1>y2) return 1;
    if(y1<y2) return 0;
    if(m1>m2) return 1;
    if(m1<m2) return 0;
    if(d1>d2) return 1;
    if(d1<d2) return 0;
    if(h1>h2) return 1;
    if(h1<h2) return 0;
    if(mi1>mi2) return 1;
    if(mi1<mi2) return 0;
    if(s1>s2) return 1;
    return 0;
}

void bubbleSort(int* y, int* m, int* d, int*h, int*mi, int*s, int n){
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(comp(y[j],m[j],d[j],y[j+1],m[j+1],d[j+1],h[j],mi[j],s[j],h[j+1],mi[j+1],s[j+1])){
                swap(&y[j],&m[j],&d[j],&y[j+1],&m[j+1],&d[j+1],&h[j],&mi[j],&s[j],&h[j+1],&mi[j+1],&s[j+1]);
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
    char cfile[] = "dt10k.txt";
    char bfile[] = "bdt10k.txt";

    for(int x=0; x<10; x++){
        double time_sort=0.0;
        double time_sortwrite=0.0;
        sprintf(cfile, "dt%dk.txt", m1);
        sprintf(bfile, "bdt%dk.txt", m1);

        FILE *fp;
        fp = fopen(cfile, "r");
        int *y = (int*)malloc(n*sizeof(int));
        int *m = (int*)malloc(n*sizeof(int));
        int *d = (int*)malloc(n*sizeof(int));
        int *hr = (int*)malloc(n*sizeof(int));
        int *mi = (int*)malloc(n*sizeof(int));
        int *sec = (int*)malloc(n*sizeof(int));
        for(int i=0; i<n; i++){
            char h1,m1,m2,m3,h2,c1,c2;
            fscanf(fp, "%d%c%c%c%c%c%d %d%c%d%c%d", &d[i], &h1, &m1, &m2, &m3, &h2, &y[i], &hr[i], &c1, &mi[i], &c2, &sec[i]);
            m[i] = monthIndex(m1,m2,m3);
        }
        fclose(fp);

        clock_t begin1 = clock();
        bubbleSort(y, m, d, hr, mi, sec, n);

        clock_t begin2 = clock();
        FILE *fb;
        fb = fopen(bfile, "w");
        for(int i=0; i<n; i++){
            fprintf(fb, "%02d-%s-%d %02d:%02d:%02d\n", d[i], months[m[i]], y[i], hr[i], mi[i], sec[i]);
        }
        fclose(fb);
        free(y);
        free(m);
        free(d);
        free(hr);
        free(mi);
        free(sec);

        clock_t end = clock();
        time_sort += (double)(end-begin2)/CLOCKS_PER_SEC;
        time_sortwrite += (double)(end-begin1)/CLOCKS_PER_SEC;

        FILE* fo;
        fo = fopen("210101028-output.txt","a");
        fprintf(fo, "Date & Time %dK \t\t %.3f \t\t %.3f \n", m1, time_sort, time_sortwrite);
        fclose(fo);
        m1*=2; n*=2;
    }
    return 0;
}