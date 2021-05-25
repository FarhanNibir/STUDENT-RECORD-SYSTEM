#include<stdio.h>
#include<string.h>
typedef struct Student Student;
struct Student{
    char ID[15];
    char Year[3];
    char Semester[3];
    char CGPA[6];
    char Name[50];
    char Phone[20];
    char Email[40];
    char Address[50];
};
void show_info(){
    printf("\t\t\t\t\t\t*Information of The Students*\n\n");
    Student stu[1000];
    int i;
    FILE *fp=fopen("record.txt","r");
    if(fp==0)
        printf("\t\t\t\t\t\t*Error in Opening the file*\n\n");
    else{
        while(fscanf(fp,"%s",stu[i].ID)!=EOF){
                printf("ID: %s\n",stu[i].ID);
                fscanf(fp," %[^\n]s",stu[i].Name);
                printf("Name: %s\n",stu[i].Name);
                fscanf(fp,"%s",&stu[i].Year);
                printf("Year: %s\n",stu[i].Year);
                fscanf(fp,"%s",&stu[i].Semester);
                printf("Semester: %s\n",stu[i].Semester);
                fscanf(fp,"%s",&stu[i].CGPA);
                printf("CGPA: %s\n",stu[i].CGPA);
                fscanf(fp,"%s",&stu[i].Phone);
                printf("Phone No: %s\n",stu[i].Phone);
                fscanf(fp,"%s",&stu[i].Email);
                printf("Email: %s\n",stu[i].Email);
                fscanf(fp," %[^\n]s",&stu[i].Address);
                printf("Address: %s\n\n",stu[i].Address);
        }
    }
    return  ;
}
void add_student_info(){
    Student stu[1000];
    int i,n;
    printf("\t\t\t\t\t\t*Add Student Information*\n\n");
    printf("How many students information do you want to add: ");
    scanf("%d",&n);
    char temp,temp2;
    for(i=1; i<=n; i++){
        printf("\n\nStudent No: %d\n",i);
        scanf("%c",&temp);
        printf("ID: ");
        gets(stu[i].ID);
        printf("Name: ");
        gets(stu[i].Name);
        printf("Year: ");
        scanf("%s",&stu[i].Year);
        printf("Semester: ");
        scanf("%s",&stu[i].Semester);
        printf("CGPA: ");
        scanf("%s%c",&stu[i].CGPA,&temp2);
        printf("Phone Number: ");
        gets(stu[i].Phone);
        printf("Email: ");
        gets(stu[i].Email);
        printf("Address: ");
        gets(stu[i].Address);
    }
    FILE *fp = fopen("record.txt","a");
    if (fp==0)
            printf("\t\t\t\t\t\t*Error in Opening the file*\n\n");
        else{
        for(i=1; i<=n; i++){
            fprintf(fp,"%s\n",stu[i].ID);
            fprintf(fp,"%s\n",stu[i].Name) ;
            fprintf(fp,"%s\n",stu[i].Year);
            fprintf(fp,"%s\n",stu[i].Semester);
            fprintf(fp,"%s\n",stu[i].CGPA);
            fprintf(fp,"%s\n",stu[i].Phone);
            fprintf(fp,"%s\n",stu[i].Email);
            fprintf(fp,"%s\n",stu[i].Address);
        }
    }
    fclose(fp);
    puts("\n");
    puts("\t\t\t\t\t*The record is successfully ADDED*\n\n\n");
    return;
}
void remove_student_info(){
    printf("\t\t\t\t\t\t**Remove Student Information**\n\n");
    Student stu[1000];
    int i,n;
    int count=0,loop;
    char temp[1];
    char r[15];
    FILE *fp = fopen("record.txt", "r");
    printf("Enter the ID of the student you want to remove information: ");
    scanf("%s", &r);
    for(i=1;i<=1000;i++){
        loop=fscanf(fp,"%s",&stu[i].ID);
                fscanf(fp," %[^\n]s",&stu[i].Name);
                fscanf(fp,"%s",&stu[i].Year);
                fscanf(fp,"%s",&stu[i].Semester);
                fscanf(fp,"%s",&stu[i].CGPA);
                fscanf(fp,"%s",&stu[i].Phone);
                fscanf(fp,"%s",&stu[i].Email);
                fscanf(fp," %[^\n]s",&stu[i].Address);
        if(loop==EOF){
            break;
        }
        count++;
    }
    fclose(fp);
    for (i=0;i<=count;i++){
        if (strcmp(r, stu[i].ID) == 0){
            n = 1;
            break;
        }
    }
    if (n == 1){
        strcpy(stu[i].ID,temp);
        strcpy(stu[i].Name,temp);
        strcpy(stu[i].Year,temp);
        strcpy(stu[i].Semester,temp);
        strcpy(stu[i].CGPA,temp);
        strcpy(stu[i].Phone,temp);
        strcpy(stu[i].Email,temp);
        strcpy(stu[i].Address,temp);
        fp = fopen("record.txt", "w");
        if (fp == 0)
            printf("Error in Opening the file\n\n");
        else{
            for (i=1; i <= count; i++){
            fprintf(fp,"%s\n",stu[i].ID);
            fprintf(fp,"%s\n",stu[i].Name);
            fprintf(fp,"%s\n",stu[i].Year);
            fprintf(fp,"%s\n",stu[i].Semester);
            fprintf(fp,"%s\n",stu[i].CGPA);
            fprintf(fp,"%s\n",stu[i].Phone);
            fprintf(fp,"%s\n",stu[i].Email);
            fprintf(fp,"%s\n",stu[i].Address);
            }
            fclose(fp);
            puts("\n");
            puts("\t\t\t\t\t**The record is successfully REMOVED**\n\n\n");
        }
    }
    else{
        puts("\n");
        printf("\n\t\t\t\t\t**Sorry, No record found in the database**\n\n");
    }
    return ;
}
void modify_info(){
    printf("\t\t\t\t\t\t**Modify Student Information**\n\n");
    Student stu[1000];
    int i,n=0,count=0,m;
    char temp, temp2;
    char r[15],uid[15],uname[50],upn[20],ue[40],ua[50],ucgpa[6],us[3],uy[3];
    FILE *fp = fopen("record.txt","r");
    printf("Enter the ID of the student you want to modify information: ");
    scanf("%s", &r);
    for(i=1;i<=1000;i++){
        m=fscanf(fp,"%s",&stu[i].ID);
                fscanf(fp," %[^\n]s",&stu[i].Name);
                fscanf(fp,"%s",&stu[i].Year);
                fscanf(fp,"%s",&stu[i].Semester);
                fscanf(fp,"%s",&stu[i].CGPA);
                fscanf(fp,"%s",&stu[i].Phone);
                fscanf(fp,"%s",&stu[i].Email);
                fscanf(fp," %[^\n]s",&stu[i].Address);
        if(m==EOF){
            break;
        }
        count++;
    }
    fclose(fp);
    for (i=1;i<=count;i++){
        if (strcmp(r,stu[i].ID)==0){
            n=1;
            break;
        }
    }
    if (n==1){
        puts("\t\t\t\t\t\t*Enter Information to Modify*");
        scanf("%c", &temp);
        printf("Updated Name: ");
        gets(uname);
        printf("Updated ID: ");
        gets(uid);
        printf("Updated Year: ");
        scanf("%s",&uy);
        printf("Updated Semester: ");
        scanf("%s",&us);
        printf("Updated CGPA: ");
        scanf("%s%c",&ucgpa,&temp2);
        printf("Updated Phone Number: ");
        gets(upn);
        printf("Updated Email: ");
        gets(ue);
        printf("Updated Address: ");
        gets(ua);
        strcpy(stu[i].ID,uid);
        strcpy(stu[i].Name,uname);
        strcpy(stu[i].Year,uy);
        strcpy(stu[i].Semester,us);
        strcpy(stu[i].CGPA,ucgpa);
        strcpy(stu[i].Phone,upn);
        strcpy(stu[i].Email,ue);
        strcpy(stu[i].Address,ua);
        if (fp==0)
            printf("\t\t\t\t\t\t*Error in Opening the file*\n\n");
        else{
            fp = fopen("record.txt", "w");
            for (i=1;i<=count;i++){
            fprintf(fp,"%s\n",stu[i].ID);
            fprintf(fp,"%s\n",stu[i].Name);
            fprintf(fp,"%s\n",stu[i].Year);
            fprintf(fp,"%s\n",stu[i].Semester);
            fprintf(fp,"%s\n",stu[i].CGPA);
            fprintf(fp,"%s\n",stu[i].Phone);
            fprintf(fp,"%s\n",stu[i].Email);
            fprintf(fp,"%s\n",stu[i].Address);
            }
            fclose(fp);
            puts("\n");
            puts("\t\t\t\t\t*The record is successfully MODIFIED*\n\n\n");
        }
    }
    else{
        puts("\n");
        printf("\n\t\t\t\t\t*Sorry, No record found in the database*\n\n");
    }
    return ;
}
void search_info(){
    printf(" \t\t\t\t\t\t**Search Student Information**\n\n");
    Student stu[1000];
    char n[15];
    char temp;
    int i,count=0;
    printf("Enter the ID of the student you want to search information: ");
    scanf("%c",&temp);
    gets(n);
    FILE *fp=fopen("record.txt","r");
    if (fp == 0)
            printf("\t\t\t\t\t\t*Error in Opening the file*\n\n");
        else{
    for(i=0;i<1000;i++){
        fscanf(fp,"%s",stu[i].ID);
        if(strcmp(n,stu[i].ID)==0){
            count=1;
            break;
        }
    }
    if(count==1){
        printf("\t\t\t\t\t\t\t*Record Found*\n\n");
        fscanf(fp," %[^\n]s",stu[i].Name);
        printf("Name: %s\n",stu[i].Name);
        printf("ID: %s\n",stu[i].ID);
        fscanf(fp,"%s",&stu[i].Year);
        printf("Year: %s\n",stu[i].Year);
        fscanf(fp,"%s",&stu[i].Semester);
        printf("Semester: %s\n",stu[i].Semester);
        fscanf(fp,"%s",&stu[i].CGPA);
        printf("CGPA: %s\n",stu[i].CGPA);
        fscanf(fp,"%s",&stu[i].Phone);
        printf("Phone No: %s\n",stu[i].Phone);
        fscanf(fp,"%s",&stu[i].Email);
        printf("Email: %s\n",stu[i].Email);
        fscanf(fp," %[^\n]s",&stu[i].Address);
        printf("Address: %s\n",stu[i].Address);
    }
    else{
        printf("\n\t\t\t\t\t*Sorry, No record found in the database*\n\n");
    }
    fclose(fp);
    }
    return ;
}
void marksheet(){
    char id[15];
    char name[50];
    char temp;
    double a,b,c,d,e,total;
    int i,n;
    printf("\t\t\t\t\t\t**Generate Marksheets**\n\n");
    printf("How Many Students' Marksheets do You Want to Generate: ");
    scanf("%d",&n);
    FILE *ft=fopen("Marksheets.txt","a");
    if (ft == 0)
            printf("\t\t\t\t\t\t*Error in Opening the file*\n\n");
        else{
    for (i=1; i<=n; i++){
        printf("\n\nStudent No: %d\n",i);
        scanf("%c",&temp);
        printf("Enter Students ID: ");
        gets(id);
        printf("Enter Students Name: ");
        gets(name);
        printf("CGPA of CSE 103: ");
        scanf("%lf",&a);
        printf("CGPA of CSE 104: ");
        scanf("%lf",&b);
        printf("CGPA of CSE 105: ");
        scanf("%lf",&c);
        printf("CGPA of CHEM 111: ");
        scanf("%lf",&d);
        printf("CGPA of EEE 121: ");
        scanf("%lf",&e);
        total=(a+b+c+d+e)/5;
        fprintf(ft,"ID: %s\n",id);
        fprintf(ft,"NAME: %s\n",name);
        fprintf(ft,"CGPA of CSE 103: %.2lf\n",a);
        fprintf(ft,"CGPA of CSE 104: %.2lf\n",b);
        fprintf(ft,"CGPA of CSE 105: %.2lf\n",c);
        fprintf(ft,"CGPA of CHEM 111: %.2lf\n",d);
        fprintf(ft,"CGPA of EEE 121: %.2lf\n",e);
        fprintf(ft,"TOTAL CGPA: %.2lf\n",total);
        if(total<2)
            fprintf(ft,"TOTAL GRADE: F\n\n");
        else if(total<2.25)
            fprintf(ft,"TOTAL GRADE: D\n\n");
        else if(total<2.5)
            fprintf(ft,"TOTAL GRADE: C\n\n");
        else if(total<2.75)
            fprintf(ft,"TOTAL GRADE: C+\n\n");
        else if(total<3)
            fprintf(ft,"TOTAL GRADE: B-\n\n");
        else if(total<3.25)
            fprintf(ft,"TOTAL GRADE: B\n\n");
        else if(total<3.5)
            fprintf(ft,"TOTAL GRADE: B+\n\n");
        else if(total<3.75)
            fprintf(ft,"TOTAL GRADE: A-\n\n");
        else if(total<4)
            fprintf(ft,"TOTAL GRADE: A\n\n");
        else if(total==4)
            fprintf(ft,"TOTAL GRADE: A+\n\n");
    }
    printf("\n\n\n\t\t\t\t\t*Marksheets Successfully Generated*\n\n");
    fclose(ft);
    }
    return ;
}
void change(){
    puts("\t\t\t\t\t\t*Enter Information to Change*\n");
    int ts,ps,fs;
    printf("Enter the UPDATED number of Total Student: ");
    scanf("%d",&ts);
    printf("Enter the UPDATED number of Passed Student: ");
    scanf("%d",&ps);
    printf("Enter the UPDATED number of Failed Student: ");
    scanf("%d",&fs);
    FILE*fp=fopen("rating.txt","w");
    fprintf(fp,"%d\n%d\n%d",ts,ps,fs);
    fclose(fp);
    puts("\t\t\t\t\t*The Numbers are successfully UPDATED*\n\n\n");
    return;
}
void show_rating(){
     double ts,ps,fs,r,r2;
    char a='%';
    FILE*fp=fopen("rating.txt","r");
    fscanf(fp,"%lf",&ts);
    printf("\t\t\t\t\tThe number of total student: %.lf\n",ts);
    fscanf(fp,"%lf",&ps);
    printf("\t\t\t\t\tThe number of passed student: %.lf\n",ps);
    fscanf(fp,"%lf",&fs);
    printf("\t\t\t\t\tThe number of failed student: %.lf\n",fs);
    fclose(fp);
    if(ps+fs==ts){
        r=(ps*100)/ts;
        r2=(fs*100)/ts;
        printf("\n\t\t\t\t\tPercentage of passed student: %.2lf%c\n",r,a);
        printf("\t\t\t\t\tPercentage of failed student: %.2lf%c\n\n",r2,a);
    }
    else if(ps+fs>ts)
       printf("\n\t\t*ERROR..The number of passed and failed students are more than total students.*\n\n");
    else
        printf("\n\t\t*ERROR..The number of passed and failed students are less than total students.*\n\n");
    return ;
}
void rating(){
        while(1){
        printf("\t\t\t\t\t\t**Total Student Rating**\n\n");
        puts("1. Update the Numbers.\n");
        puts("2. Show the rating.\n");
        puts("3. Back to Main Menu.\n");
        int c;
        printf("What do you want to do? Enter your choice:");
        scanf("%d",&c);
            if(c==1)
                change();
            if(c==2)
                show_rating();
            if(c==3)
                return;
            if(c>3||c<1)
            printf("\n\n\n\t\t\t\t*ERROR...OPTION NOT FOUND.ENTER YOUR CHOICE CORRECTLY.*\n\n\n\n");
}
   }
int main (){
    while(1){
        printf("\t\t\t\t\t\t***STUDENT RECORD SYSTEM***\n\n");
        puts("1. Shows All The Information.\n");
        puts("2. Add Student Information.\n");
        puts("3. Remove Student Information.\n");
        puts("4. Modify Student Information.\n");
        puts("5. Search Student Information.\n");
        puts("6. Generate Marksheets.\n");
        puts("7. Total Student Rating.\n");
        puts("8. Exit.\n");
        int choice;
        printf("What do you want to do? Enter your choice:");
        scanf("%d",&choice);
        if(choice==1)
            show_info();
        if(choice==2)
            add_student_info();
        if(choice==3)
            remove_student_info();
        if(choice==4)
            modify_info();
        if(choice==5)
            search_info();
        if(choice==6)
            marksheet();
        if(choice==7)
            rating();
        if(choice==8)
            break;
        if(choice>8||choice<1)
            printf("\n\n\n\t\t\t\t*ERROR...OPTION NOT FOUND.ENTER YOUR CHOICE CORRECTLY.*\n\n\n\n");
    }
    return 0;
}

