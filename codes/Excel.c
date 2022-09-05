
// all excel file related functionality

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Phone.h"

// import contacts
void excel(char filename[], Phonebook *phone)
{
    printf(" Hello user you have opened %s excel file \n", filename);

    FILE *P = fopen(filename, "r+");

    if (!P)
    {
        printf("Error opening %s file ", filename);
        return;
        // exit(1);
    }
    char line[250];
    Person *temp_person;

    while (fgets(line, sizeof(line), P))
    {
        char *token;

        temp_person = (Person *)malloc(sizeof(Person));
        // Person teperson;

        token = strtok(line, ",");
        int i = 1;

        // printf("kas kay \n");

        // perticulur contact
        while (token != NULL)
        {

            if (i == 2)
            {
                char *name_ = (char *)malloc(sizeof(char) * strlen(token));
                strcpy(name_, token);
                temp_person->name = name_;
            }

            if (i == 3)
            {
                char *email_ = (char *)malloc(sizeof(char) * strlen(token));
                strcpy(email_, token);
                temp_person->email = email_;
            }

            if (i == 4)
            {
                char *address_ = (char *)malloc(sizeof(char) * strlen(token));
                strcpy(address_, token);
                temp_person->address = address_;
            }
            // printf("Name -=-=-=->  \n");
            if (i == 5)
            {
                // printf(" Number is %s \t", token);
                char *NUMBER_ = (char *)malloc(sizeof(char) * strlen(token));
                strcpy(NUMBER_, token);
                temp_person->NUMBER = NUMBER_;
            }

            i++;
            // getchar();
            token = strtok(NULL, ",");
        }

        // printf("name is before entering ---> %s\n", temp_person->name);
        insert(phone, temp_person->name, *temp_person);
        // printf(" shubham may be here\n");
    }
    printf("\t *# File added successfully. \n");
    return;
}

// function to print all the names of phonebook
void print_Excel(Phonebook *t, FILE *fp)
{
    // printf("out from insert ");
    node *temp_ = *t;

    if (temp_->flag)
    {
        // here print statement
        fprintf(fp, "%s, %s, %s, %d, %s\n", temp_->member.name, temp_->member.NUMBER, temp_->member.email, temp_->member.DOB, temp_->member.address);
    }
    node *nn = *t;
    for (int i = 0; i < Alphabet; i++)
    {
        if (nn->children[i])
        {
            print_Excel(&nn->children[i], fp);
        }
    }
    return;
}

// Export contacts
void main_ex(Phonebook *t)
{

    // open csv file
    FILE *fp = fopen("output.csv", "w");

    if (!fp)
    {
        // Error in file opening
        printf("Can't open file\n");
        return;
    }

    fprintf(fp, "%s, %s, %s, %s, %s\n", "Name", "Number", "Email", "Bob", "Address");

    print_Excel(t, fp);

    // printf("\nNew Account added to record");

    fclose(fp);

    printf("contacts are in output.csv\n");

    return;
}

/*
char *name;
char *NUMBER;
char *email;
int DOB;
char *address;
*/
