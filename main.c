#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "codes/Phone.h"

int main(int argc, char *argv[])
{
    printf("Hello Shubham!\n");

    stack My_Del;
    init_stack(&My_Del, STACK_CAPACITY);

    list Favourite;
    init_List(&Favourite);

    char name[40];
    Phonebook l = getnode();

    Pri_Phonebook *My_personal = GetPrivateNode("Shu");

    printf("Commands are \n");
    printf("\t add : to add the contact to phonebook\n");
    printf("\t edit : to edit the contact of phonebook\n");
    printf("\t mfev : to make current contact favourite\n");
    printf("\t modify : to modify the contact of phonebook\n");
    printf("\t show : to print all the contacts to phonebook\n");
    printf("\t delete : to delete the contact from phonebook\n");
    printf("\t ispresent : to check is the contact present in phonebook\n");
    printf("\t search : to prefix search \n");
    printf("\t rexcel : to import excel file to phonebook\n");
    printf("\t wexcel : to export the phonebook\n");
    printf("\t prinsert : to insert the contact to Private phonebook\n");
    printf("\t prshow : to print the contact of Private phonebook\n");
    printf("\t showrd : to print the recently deleted contact of phonebook\n");
    printf("\t showfc : to print the Favourite contact of phonebook\n");
    printf("\t sortfev : to sort the fevourite contact of phonebook\n");

    // excel("Contact_Information.csv", &l);
    // printall(&l, name, 0);

    while (1)
    {

        // take input from user
        char inputcom[10] = "";
        printf("\n> ");
        scanf("%s", inputcom);

        // add the person information to phonebook
        if (strcmp(inputcom, "add") == 0)
        {
            add_Person(&l);
        }

        // add the person information to favourite
        else if (strcmp(inputcom, "mfev") == 0)
        {

            printf("Enter name : ");
            char fav[30];
            // gets(fav);
            // fgets(fav, 30, stdin);
            scanf("%s", fav);
            Make_Favourite(l, fav, &Favourite);
        }

        // modify the contact information
        else if (strcmp(inputcom, "modify") == 0)
        {
            edit_contact(&l);
        }

        // show full the contact information
        else if (strcmp(inputcom, "show") == 0)
        {
            // printall(&l, name, 0);
            printall_reverse(&l, name, 0);
        }

        // delete the contact information
        else if (strcmp(inputcom, "delete") == 0)
        {
            char favdel[30];
            printf("Enter name to delete : ");
            // gets(favdel);
            scanf("%s", favdel);
            remove_(&l, favdel, 0, &My_Del);
        }

        // search the contact information
        else if (strcmp(inputcom, "ispresent") == 0)
        {
            char serc[30] = "";
            printf("Enter name to search : ");
            // gets(serc);
            scanf("%s", serc);
            int search_result = search_perticular(l, serc);
            if (search_result)
            {
                printf("%s name is present in Phone. \n", serc);
            }
            else
            {
                printf("%s name is NOT present in Phone. \n", serc);
            }
        }

        // search the full the contact information
        else if (strcmp(inputcom, "search") == 0)
        {
            search_all(&l);
        }

        // import full the contact file
        else if (strcmp(inputcom, "rexcel") == 0)
        {
            char file_name[30] = "";
            printf("Enter file name : ");
            // gets(file_name);
            scanf("%s", file_name);
            excel(file_name, &l);
            printf("File Added Successfully \n");
        }

        // print the full the contact information into csv file
        else if (strcmp(inputcom, "wexcel") == 0)
        {
            main_ex(&l);
        }

        // insert the contact information to private
        else if (strcmp(inputcom, "prinsert") == 0)
        {
            Person *ad = get_Person();
            insert_private(My_personal, ad->name, *ad);
        }

        // priting the full the private contact information
        else if (strcmp(inputcom, "prshow") == 0)
        {
            Print_private(My_personal, name, 0);
        }

        // show  recently deleted contacts
        else if (strcmp(inputcom, "showrd") == 0)
        {
            traverse_stack(My_Del);
        }

        // show  favourite contacts
        else if (strcmp(inputcom, "showfc") == 0)
        {
            traverse_List(Favourite);
        }

        // show  favourite contacts
        else if (strcmp(inputcom, "sortfev") == 0)
        {
            mergesort(&Favourite);
        }
        else if (strcmp(inputcom, "restore") == 0)
        {
            restore(My_personal, &My_Del, &l);
        }
        else
        {
            printf("Invalid command\n");
        }
    }

    return 0;
}
