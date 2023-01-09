#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date{
    int day;
    int month;
    int year;
};

void swap(struct Date *a, struct Date *b) {
    int t = a->day; a->day=b->day; b->day=t;
    t = a->year; a->year=b->year; b->year=t;
    t = a->month; a->month=b->month; b->month=t;
}

int comp(struct Date *a, struct Date *b){
    if(a->year>b->year) return 1;
    else if(a->year<b->year) return 0;
    if(a->month>b->month) return 1;
    else if(a->month<b->month) return 0;
    if(a->day>b->day) return 1;
    return 0;   
}

void bubbleSort(struct Date* a, int n){
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(comp(&a[j], &a[j+1])){
                swap(&a[j], &a[j+1]);
            }
        }
    }
}

void findMonth(struct Date* d, char c1, char c2, char c3){
    if(c1=="J" && c2=="a" && c3=="n") d->month=0;
    if(c1=="F" && c2=="e" && c3=="b") d->month=1;
    if(c1=="M" && c2=="a" && c3=="r") d->month=2;
    if(c1=="A" && c2=="p" && c3=="r") d->month=3;
    if(c1=="M" && c2=="a" && c3=="y") d->month=4;
    if(c1=="J" && c2=="u" && c3=="n") d->month=5;
    if(c1=="J" && c2=="u" && c3=="l") d->month=6;
    if(c1=="A" && c2=="u" && c3=="g") d->month=7;
    if(c1=="S" && c2=="e" && c3=="p") d->month=8;
    if(c1=="O" && c2=="c" && c3=="t") d->month=9;
    if(c1=="N" && c2=="o" && c3=="v") d->month=10;
    if(c1=="D" && c2=="e" && c3=="c") d->month=11;
}

int main(){
    int n,m;
    n=10000, m=10;
    char months[36] = "JanFebMarAprMayJunJulAugSepOctNovDec";
    char cfile[] = "i10k.txt";
    char bfile[] = "bd10k.txt";
    for(int x=0; x<10; x++){
        sprintf(cfile, "i%dk.txt", m);
        sprintf(bfile, "bd%dk.txt", m);
        FILE *fp;
        fp = fopen(cfile, "r");
        struct Date b[n];
        char junk,juk,c1,c2,c3;
        for(int i=0; i<n; i++){
            fscanf(fp, "%d%c%c%c%c%c%d", &b[i].day, &junk, &c1, &c2, &c3, &juk, &b[i].year);
            findMonth(&b[i],c1,c2,c3);
        }
        fclose(fp);
        bubbleSort(b, n);
        FILE *fb;
        fb = fopen(bfile, "w");
        for(int i=0; i<n; i++){
            int mint = b[i].month;
            fprintf(fb, "%02d-%c%c%c-%d\n", b[i].day, months[3*mint], months[3*mint+1], months[3*mint+2], b[i].year);
        }
        fclose(fb);
        free(b);
        m*=2; n*=2;
    }
    return 0;
}