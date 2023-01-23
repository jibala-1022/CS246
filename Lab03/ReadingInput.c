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
    // struct student *st = (struct student*)malloc(158*sizeof(struct student));
    struct student st[158];
    int i=0;
    while(!feof(fp)){
        fgets(row, 1024, fp);
        fprintf(f1, "Row: %s\n",row);
        token = strtok(row,",");
        fprintf(f1, "%d\n", strlen(token));
        for(int j=0; j<strlen(token); j++){
            st[i].stdname[j] = token[j];
        }
        st[i].stdname[strlen(token)]='\0';
        fprintf(f1, "%d\n", strlen(st[i].stdname));
        fprintf(f1, "StdName: %s\n",st[i].stdname);
        token = strtok(NULL,",");
        fprintf(f1, "%d\n", strlen(token));
        for(int j=0; j<strlen(token); j++){
            st[i].rollno[j] = token[j];
        }
        fprintf(f1, "%d\n", strlen(st[i].rollno));
        fprintf(f1, "Rollno: %s\n",st[i].rollno);
    }
    fclose(fp);
    return 0;
}