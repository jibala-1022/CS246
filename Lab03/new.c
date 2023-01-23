#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student{
    char stdname[30];
    char rollno[10];
};

int main(){
    FILE *fp,*f1;
    char row[1024];
    char *token;
    fp = fopen("students01.csv","r");
    f1 = fopen("students02.csv","w");
    struct student st[158];
    int i=0;
    while(!feof(fp)){
        fscanf(fp, "%[^,]%*c%[^\n]%*c", st[i].stdname, st[i].rollno);
        fprintf(f1, "StdName: %s %d\n",st[i].stdname, i);
        fprintf(f1, "RollNo: %s %d\n",st[i].rollno, i);
        i++;
    }
    fclose(fp);
    return 0;
}