#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,m;
    char cfile[] = "i10k.txt";
    // Integer input generator
    // n=10000, m=10;
    // for(int x=0; x<10; x++){
    //     sprintf(cfile, "i%dk.txt", m);
    //     FILE *fp;
    //     fp = fopen(cfile, "w");
    //     for(int i=0; i<n; i++){
    //         int rint = rand() % 1000001;
    //         fprintf(fp, "%d\n", rint);
    //     }
    //     fclose(fp);
    //     m*=2; n*=2;
    // }
    // Date input generator
    n=10000, m=10;
    // char months[36] = "JanFebMarAprMayJunJulAugSepOctNovDec";
    char months[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for(int x=0; x<10; x++){
        sprintf(cfile, "d%dk.txt", m);
        FILE *fp;
        fp = fopen(cfile, "w");
        for(int i=0; i<n; i++){
            char date[11];
            int yint, mint, dint;
            //year
            yint = rand() % 77 + 1947;
            //month
            if(yint==2023) mint=0;
            else if(yint==1947) mint = rand() % 4 + 7;
            else mint = rand() % 12;
            //day
            if(yint%4==0) days[1]=29;
            dint = days[mint];
            dint = rand() % dint + 1;
            // fprintf(fp, "%02d-%c%c%c-%d\n", dint, months[3*mint], months[3*mint+1], months[3*mint+2], yint);
            fprintf(fp, "%02d-%s-%d\n", dint, months[mint], yint);

        }
        fclose(fp);
        m*=2; n*=2;
    }
    // // Date Time input generator
    // n=10000, m=10;
    // for(int x=0; x<10; x++){
    //     sprintf(cfile, "dt%dk.txt", m);
    //     FILE *fp;
    //     fp = fopen(cfile, "w");
    //     for(int i=0; i<n; i++){
    //         char date[11];
    //         int yint, mint, dint;
    //         //year
    //         yint = rand() % 77 + 1947;
    //         //month
    //         if(yint==2023) mint=0;
    //         else if(yint==1947) mint = rand() % 4 + 7;
    //         else mint = rand() % 12;
    //         //day
    //         if(yint%4==0) days[1]=29;
    //         dint = days[mint];
    //         dint = rand() % dint + 1;
    //         //time
    //         int sint = rand() % 60, mmint = rand() % 60, hint = rand() % 24;
    //         fprintf(fp, "%02d-%s-%d %02d:%02d:%02d\n", dint, months[mint], yint, hint, mmint, sint);
    //     }
    //     fclose(fp);
    //     m*=2; n*=2;
    // }
    return 0;
}