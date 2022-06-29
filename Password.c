
// all password related functionality

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "Phone.h"

#define ENTER 13
#define TAB 9
#define BACKSPACE 8
#define SPACE 32

// get memory of size node to store new character
Pri_Phonebook *GetPrivateNode(char *pass)
{
    Pri_Phonebook *p = (Pri_Phonebook *)malloc(sizeof(Pri_Phonebook));
    node *nn = (node *)malloc(sizeof(node));
    if (nn)
    {
        nn->flag = 0;

        for (int i = 0; i < Alphabet; i++)
        {
            // make all pointer of the node characters to NULL
            nn->children[i] = NULL;
        }
        //return nn;
    }
    else
        printf("cant allocate node ; memory full \n");

    char *temp_n = (char *)malloc(sizeof(char) * strlen(pass));
    temp_n = pass;
    p->Phonebook = nn;
    p->password_ = temp_n;

    return p;
}

// take password input
char *Get_password()
{
    //printf("shubham ");

    char *password = (char *)malloc(sizeof(char) * 20);
    int i = 0;
    char ch;

    printf("\n \t Enter Your Password : ");

    while (1)
    {
        ch = getc(stdin);

        if (ch == ENTER)
        {
            password[i] = '\0';
            return password;
        }
        else if (ch == BACKSPACE)
        {

            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
            else
            {
                break;
            }
        }
        else if (ch == TAB || ch == SPACE)
        {
            continue;
        }
        else
        {
            password[i] = ch;
            i++;
            printf("*");
        }
    }

    //printf("\n pass : %s", password);

    return password;
}

// inserting contact to the private phonebook
void insert_private(Pri_Phonebook *t, char *s, Person _check)
{

    int chance = 3;

    printf("\n \t *** Adding Private Contact *** \n");

    while (chance > 1)
    {

        int temp = strcmp(t->password_, Get_password());

        if (temp == 0)
        {
            printf("\n *** Password is Correct ***\n");
            insert(&t->Phonebook, s, _check);
            printf("\n Contact Added Succesfully In Private \n");
            return;
        }
        else
        {
            printf("\n You Entered Wrong Password \n");
        }
        chance--;
    }
    printf("Lot many try\n");
    return;
}

// print private list
void Print_private(Pri_Phonebook *t, char s[], int index)
{

    int chance = 3;

    printf("\n \t *** Printing Private Contact List *** \n");

    while (chance > 1)
    {

        int temp = strcmp(t->password_, Get_password());

        if (temp == 0)
        {
            printf("\n *** Password is Correct ***\n");

            printall(&t->Phonebook, s, index);
            return;
        }
        else
        {
            printf("\n You Entered Wrong Password \n");
        }
        chance--;
    }

    printf("Lot many try\n");
    return;
}

void Private_add_contact(Pri_Phonebook *root)
{

    //    int ch;
    //    printf("Which Information you want to modify \n");
    //    printf("\t 1. Name,  \t 2. Number, \n\t 3. Email, \t 4. Date of birth, \n\t 5. Address\n");
    //    printf("\tChoice : ");
    //    scanf("%d", &ch);
    char _name[30];

    Person *p = (Person *)malloc(sizeof(Person));

    printf("Enter Name : ");
    scanf("%s", _name);
    //scanf("%[^\n]s", _name);
    //gets(_name);
    char *temp = (char *)malloc(sizeof(char) * strlen(_name));
    strcpy(temp, _name);
    p->name = temp;

    printf("Enter Number : ");
    scanf("%s", _name);

    temp = (char *)malloc(sizeof(char) * strlen(_name));
    strcpy(temp, _name);
    p->NUMBER = temp;
    isvalid_number(p);

    printf("Enter Email : ");
    char _num[20];
    scanf("%s", _num);
    temp = (char *)malloc(sizeof(char) * strlen(_num));
    strcpy(temp, _num);
    p->email = temp;

    printf("Enter DOB : ");
    int _DOB;
    scanf("%d", &_DOB);
    p->DOB = _DOB;

    printf("Enter Address : ");
    scanf("%s", _name);

    temp = (char *)malloc(sizeof(char) * strlen(_name));
    strcpy(temp, _name);
    p->address = temp;

    insert_private(root, p->name, *p);

    return;
}
