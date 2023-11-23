#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUBJECTS 7

void create_account(void);
int login();
void display(char*);
void student_record(char*);
void student_details(char*);
int logout();
int calc();

struct student
{
    char fi_name[50];
    char la_name[50];
    float marks;
    char result[50];
};

struct data
{
    char first_name[50];
    char last_name[50];
    char email[50];
    char username[50];
    int password;
};

int main()
{
    int choice;
    struct data d1;
    printf("******************************* Welcome to School Manager *******************************");
    printf("\n");   
    printf("Enter your choice:");
    printf("\n");
    printf("1:Create account");
    printf("\n");
    printf("2:Login");
    printf("\n");
    printf("*****************************************************************************************");
    printf("\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    if(choice==1)
    {
        create_account();
    }
    else if(choice==2)
    {
        login();
    }
    else
    {
        printf("Enter a valid choice!");
    }
    return 0;
}

void create_account(void)
{
    char username[50];
    int password;
    struct data d1;
    FILE *fp=NULL;
    fp = fopen("student.bin", "ab");
    printf("Enter your first name:");
    scanf("%s", d1.first_name);
    printf("Enter your last name:");
    scanf("%s", d1.last_name);
    printf("Enter your Email:");
    scanf("%s", d1.email);
    printf("Enter your username:");
    scanf("%s", d1.username);
    printf("Enter your password:");
    scanf("%d", &d1.password);
    fwrite(&d1, sizeof(d1), 1, fp);
    fclose(fp);
    //fwrite(&d1, sizeof(d1), 1, fp);
    login();
}

int login()
{
    char username[50];
    char password[50];
    FILE *fp;
    struct data d1;
    fp = fopen("student.bin", "rb");
    printf("**************************************Account Login**************************************");
    printf("\n");
    printf("Enter your Username:");
    scanf("%s", username);
    printf("\n");
    printf("Enter your Password:");
    scanf("%s", password);
    while (fread(&d1, sizeof(d1), 1, fp))
    {
        if(strcmp(username, d1.username)==0)
        {
            display(username);
        }
    }
    fclose(fp);
}

void display(char username1[])
{
    int choose;
    char username[50];
    char password[50];
    FILE *fp;
    struct data d1;
    fp = fopen("student.bin", "rb");
    while (fread(&d1, sizeof(d1), 1, fp))
    {
        if(strcmp(username1, d1.username)==0)
        {
            printf("\n");
            printf("######################################### CHOICE ##########################################");
            printf("\n");
            printf("Enter your choice(1 or 2 or 3):");
            printf("\n");
            printf("1:Enter Student Details:");
            printf("\n");
            printf("2:Check Student details:");
            printf("\n");
            printf("3:Logout:");
            printf("\n");
            printf("###########################################################################################");
            printf("\n");
            printf("Enter your choice:");
            scanf("%d", &choose);
            if(choose==1)
            {
                student_record(username1);
                break;
            }
            else if(choose==2)
            {
                student_details(username1);
                break;
            }
            else if(choose==3)
            {
                logout();
                login();
            }
            else
            {
                printf("Enter a valid choice!");
            }
        }
    }
    fclose(fp);
}

void student_record(char username2[])
{
    struct student s1;
    FILE *fm, *fp;
    fp = fopen("student.bin", "rb");
    fm = fopen("details.bin", "ab");
    struct data d1;
    printf("\n");
    printf("######################################### Details ##########################################");
    printf("Enter student first name:");
    scanf("%s", s1.fi_name);
    printf("\n");
    printf("Enter student last name:");
    scanf("%s", s1.la_name);
    printf("\n");
    printf("Enter student marks:");
    scanf("%f", &s1.marks);
    printf("\n");
    printf("Enter student Result:");
    scanf("%s", s1.result);
    printf("\n");
    printf("###########################################################################################");
    printf("\n");
    fwrite(&s1, sizeof(s1), 1, fm);
    fclose(fp);
    fclose(fm);
    display(username2);
}



void student_details(char username2[])
{
    FILE *fm;
    struct student s1;
    struct data d1;
    int i=1;
    char name[50];
    fm = fopen("details.bin", "rb");
    printf("Enter the First name(do not write the Surname) of the student you want to check record of:");
    scanf("%s", name);
    while (fread(&s1, sizeof(s1), 1, fm))
    {
        if(strcmp(name, s1.fi_name)==0)
        {
            printf("\n");
            printf("Sr no: %d", i);
            i++;
            printf("\n");
            printf("Student First Name: %s", s1.fi_name);
            printf("\n");
            printf("Student Last Name: %s", s1.la_name);
            printf("\n");
            printf("Student Marks: %f/700", s1.marks);
            printf("\n");
            printf("Student Result: %s", s1.result);
            printf("\n");
        }
            
    }
    fclose(fm);
    display(username2);
    
}

int logout()
{
    printf("\n");
    printf("please wait, logging out...................................................................");
    printf("\n");
    printf("\n");
    printf("********************************* Sucessfully Logged Out **********************************");
    printf("\n");
    printf("\n");
    return 0;
}
