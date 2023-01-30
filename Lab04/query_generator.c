// GENERATE QUERIES FOR ALL TASKS
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *f_in, *f_out;
    int counter;

    // Task  2
    f_in = fopen("hss_electives.csv", "r");
    f_out = fopen("task2b.sql", "w");
    fprintf(f_out, "INSERT INTO hss_table01 (sno, roll_number, sname, cid, cname) VALUES \n");
    counter=1431;
    while(true){
        int sno;
        int roll_number;
        char sname[50];
        char cid[10];
        char cname[60];
        fscanf(f_in, "%d%*c%d%*c%[^,]%*c%[^,]%*c%[^\n]%*c", &sno, &roll_number, sname, cid, cname);
        fprintf(f_out, "( %d, %d, '%s', '%s', '%s' )", sno, roll_number, sname, cid, cname);
        counter--;
        if(!counter) break;
        fprintf(f_out, " ,\n");
    }
    fprintf(f_out, " ;");
    fclose(f_in);
    fclose(f_out);

    // Task 3
    f_in = fopen("hss_electives.csv", "r");
    f_out = fopen("task3b.sql", "w");
    fprintf(f_out, "INSERT INTO hss_table02 (sno, roll_number, sname, cid, cname) VALUES \n");
    counter=1431;
    while(true){
        int sno;
        int roll_number;
        char sname[50];
        char cid[10];
        char cname[60];
        fscanf(f_in, "%d%*c%d%*c%[^,]%*c%[^,]%*c%[^\n]%*c", &sno, &roll_number, sname, cid, cname);
        fprintf(f_out, "( %d, %d, '%s', '%s', '%s' )", sno, roll_number, sname, cid, cname);
        counter--;
        if(!counter) break;
        fprintf(f_out, " ,\n");
    }
    fprintf(f_out, " ;");
    fclose(f_in);
    fclose(f_out);

    // Task 4
    f_in = fopen("hss_electives.csv", "r");
    f_out = fopen("task4b_1.sql", "w");
    fprintf(f_out, "INSERT INTO hss_table03 (sno, roll_number, sname, cid, cname) VALUES \n");
    int sno4 = 0;
    counter=1431;
    while(true){
        sno4++;
        int sno;
        int roll_number;
        char sname[50];
        char cid[10];
        char cname[60];
        fscanf(f_in, "%d%*c%d%*c%[^,]%*c%[^,]%*c%[^\n]%*c", &sno, &roll_number, sname, cid, cname);
        fprintf(f_out, "( %d, %d, '%s', '%s', '%s' )", sno4, roll_number, sname, cid, cname);
        counter--;
        if(!counter) break;
        fprintf(f_out, " ,\n");
    }
    fprintf(f_out, " ;");
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("additional_hss_course.csv", "r");
    f_out = fopen("task4b_2.sql", "w");
    fprintf(f_out, "INSERT INTO hss_table03 (sno, roll_number, sname, cid, cname) VALUES \n");
    counter=9;
    while(true){
        sno4++;
        int sno;
        int roll_number;
        char sname[50];
        char cid[10];
        char cname[60];
        fscanf(f_in, "%d%*c%d%*c%[^,]%*c%[^,]%*c%[^\n]%*c", &sno, &roll_number, sname, cid, cname);
        fprintf(f_out, "( %d, %d, '%s', '%s', '%s' )", sno4, roll_number, sname, cid, cname);
        counter--;
        if(!counter) break;
        fprintf(f_out, " ,\n");
    }
    fprintf(f_out, " ;");
    fclose(f_in);
    fclose(f_out);

    // Task 6
    f_in = fopen("hss_courses.csv", "r");
    f_out = fopen("task6c_1.sql", "w");
    fprintf(f_out, "INSERT INTO hss_course01 (cid, cname) VALUES \n");
    counter=21;
    while(true){
        char cid[10];
        char cname[60];
        fscanf(f_in, "%[^,]%*c%[^\n]%*c", cid, cname);
        fprintf(f_out, "( '%s', '%s' )", cid, cname);
        counter--;
        if(!counter) break;
        fprintf(f_out, " ,\n");
    }
    fprintf(f_out, " ;");
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("hss_electives.csv", "r");
    f_out = fopen("task6c_2.sql", "w");
    fprintf(f_out, "INSERT INTO hss_table05 (sno, roll_number, sname, cid, cname) VALUES \n");
    int sno6=0;
    counter=1431;
    while(true){
        sno6++;
        int sno;
        int roll_number;
        char sname[50];
        char cid[10];
        char cname[60];
        fscanf(f_in, "%d%*c%d%*c%[^,]%*c%[^,]%*c%[^\n]%*c", &sno, &roll_number, sname, cid, cname);
        fprintf(f_out, "( %d, %d, '%s', '%s', '%s' )", sno6, roll_number, sname, cid, cname);
        counter--;
        if(!counter) break;
        fprintf(f_out, " ,\n");
    }
    fprintf(f_out, " ;");
    fclose(f_in);
    fclose(f_out);

    f_in = fopen("violate_fk.csv", "r");
    f_out = fopen("task6d.sql", "w");
    fprintf(f_out, "INSERT INTO hss_table05 (sno, roll_number, sname, cid, cname) VALUES \n");
    counter=9;
    while(true){
        sno6++;
        int sno;
        int roll_number;
        char sname[50];
        char cid[10];
        char cname[60];
        fscanf(f_in, "%d%*c%d%*c%[^,]%*c%[^,]%*c%[^\n]%*c", &sno, &roll_number, sname, cid, cname);
        fprintf(f_out, "( %d, %d, '%s', '%s', '%s' )", sno6, roll_number, sname, cid, cname);
        counter--;
        if(!counter) break;
        fprintf(f_out, " ,\n");
    }
    fprintf(f_out, " ;");
    fclose(f_in);
    fclose(f_out);
    
    return 0;
}