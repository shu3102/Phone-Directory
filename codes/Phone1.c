#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Phone.h"
#define Alphabet 27
// ASCII initialization
#define BACKSPACE 8
#define TAB 9
#define ENTER 13
#define SPACE 32

// get memory of size node to store new character
node *getnode()
{
    node *nn = (node *)malloc(sizeof(node));
    if (nn)
    {
        // initialization of nodes
        nn->flag = 0;
        for (int i = 0; i < Alphabet; i++)
        {
            // make all pointer of the node characters to NULL
            nn->children[i] = NULL;
        }
        return nn;
    }
    else
        printf("cant allocate node ; memory full \n");
    return nn;
}

// Validation for Number.
void isvalid_number(Person *e)
{
    while (1)
    {
        if ((strlen(e->NUMBER) != 10))
        {
            printf("Inserted %s number is not valid. \nNumber should count 10 and should Not contain the characters other than the digits.\n", e->NUMBER);
            e->NUMBER = (char *)malloc(sizeof(char) * 10);
            while (1)
            {
                printf("Please enter a valid number\n");
                scanf("%s", e->NUMBER);
                if ((strlen(e->NUMBER) == 10))
                    break;
            }
        }

        // To check the number contains characters other than digit or not.
        while (1)
        {
            int b = 0;
            for (int h = 0; h < strlen(e->NUMBER); h++)
            {
                if ((e->NUMBER[h] >= '0') && (e->NUMBER[h] <= '9'))
                    b++;
            }
            if (b == 10)
                return;
            else
            {
                printf("Please enter a valid number \n");
                scanf("%s", e->NUMBER);

                // To reenter the number if it contains special character.
            }
        }
        return;
    }
}

// insert contacts to phonebook
void insert(Phonebook *t, char *s, Person _check)
{
    // i index is for maintining index of string to insert in phonebook
    int i = 0;
    // make copy of root pointer to iterate
    node *p = *t;
    // loop to find perfect place for comming name
    while (s[i] != '\0')
    {
        int side = 0;
        // if node is not present then create.
        if (s[i] == ' ')
        {
            // at space there is no node
            if (!p->children[26])
            {
                p->children[26] = getnode();
            }
            side = 1;
        }
        // make node for character a-z, if not present
        else if (!p->children[s[i] - 'a'])
        {
            p->children[s[i] - 'a'] = getnode();
        }
        if (side)
            p = p->children[26];
        else
            p = p->children[s[i] - 'a'];
        // name increment
        i++;
    }
    // full name inserted
    // mark current node as leaf
    p->flag = 1;
    isvalid_number(&_check);
    p->member = _check;
    return;
}

// function to print all the names of phonebook
void printall(Phonebook *t, char s[], int index)
{
    // printf("out from insert ");
    node *temp_ = *t;
    if (temp_->flag)
    {
        s[index] = '\0';
        // puts(s);
        // printf("               Name                 Number                   Address\n");
        printf("_____________________________________________________________________________________\n");
        printf(" %15s %20s %15s %20s\n", s, temp_->member.NUMBER, temp_->member.address, temp_->member.email);
        // printf("_____________________________________________________________________________________\n");

        // printf("Name : %s \n", s);
        // printf("Number : %s \n", temp_->member.NUMBER);
    }
    node *nn = *t;
    for (int i = 0; i < Alphabet; i++)
    {
        if (nn->children[i])
        {
            if (i == 26)
            {
                s[index] = ' ';
            }
            else
                s[index] = i + 'a';
            printall(&nn->children[i], s, index + 1);
        }
    }
    return;
}

// function to print all the names of phonebook
void printall_reverse(Phonebook *t, char s[], int index)
{
    // printf("out from insert ");
    node *temp_ = *t;

    if (temp_->flag)
    {
        s[index] = '\0';
        // puts(s);
        // printf("               Name                 Number                   Address\n");
        printf("_____________________________________________________________________________________\n");
        printf(" %15s %20s %15s %20s\n", s, temp_->member.NUMBER, temp_->member.address, temp_->member.email);
        // printf("_____________________________________________________________________________________\n");
    }
    node *nn = *t;
    for (int i = Alphabet - 1; i >= 0; i--)
    {
        if (nn->children[i])
        {
            if (i == 26)
            {
                s[index] = ' ';
            }
            else
                s[index] = i + 'a';
            printall_reverse(&nn->children[i], s, index + 1);
        }
    }
    return;
}

// Returns 1 if key presents in trie,
// else return 0
int search_perticular(Phonebook root, const char *key)
{
    // initialization part
    int i;                    // i for sting index traversing
    int length = strlen(key); // length for storing the length of sting
    int index;                // index is for referring pointer name in trie

    // p is the pointer to the nodes of trie
    node *p = root;

    // actual checking of the occurrence of the name
    for (i = 0; i < length; i++)
    {
        // if the present character is not space
        // then assign pointer number to the index
        if (key[i] != ' ')
            index = (key[i] - 'a');
        else // if this is space then assign it to 26 because 26 is the pointer for space
            index = 26;

        // if index number of pointer is not available then return false ie 0
        if (!p->children[index])
            return 0;
        // pointer available go to that node
        p = p->children[index];
    }

    // if that node exist and flag of that node is true then
    // that person exist
    return (p != NULL && p->flag);
}

// backspace remaining
// error on space
void search_all(Phonebook *t)
{
    printf("Searching \n");
    char name__s[50] = "";
    char pass_name[50];
    int i = 0, index;
    char ch;

    node *p = *t;

    while (1)
    {

        printf("Enter Name : ");
        printf("%s", name__s);
        ch = getc(stdin);
        // printf("\n");
        printf("%c", ch);
        printf("\n************************************************************* \n");
        if (ch == ENTER)
        {
            name__s[i] = '\0';
            break;
        }
        // if the present character is not space
        // then assign pointer number to the index
        if (ch != ' ')
        {
            name__s[i] = ch;
            // name__[i+1] = '\0';
            i++;
            index = (ch - 'a');
            p = p->children[index];
        }
        else
        { // if this is space then assign it to 26 because 26 is the pointer for space
            index = 26;
            name__s[i] = ch;
            // name__[i+1] = '\0';
            i++;
            p = p->children[index];
        }

        strcpy(pass_name, name__s);
        // printf("passing name %s \n", pass_name);
        printall(&p, pass_name, i);

        printf("************************************************************* \n\n");
        // printf("Enter Name : ");
        // printf("%s", name__s);

    } // end of while
}

// **************************************************************

// Returns true if root has no children, else false
int isEmpty(Phonebook root)
{
    node *p = root;
    for (int i = 0; i < Alphabet; i++)
        if (p->children[i])
            return 0;
    return 1;
}

// Recursive function to delete a key from given Trie
Phonebook remove_(Phonebook *root, char *key, int depth, stack *s)
{
    // If tree is empty

    if (!root)
        return NULL;

    node *p = *root;

    // If last character of key is being processed
    if (depth == strlen(key))
    {

        // This node is no more end of word after
        // removal of given key
        if (p->flag)
            p->flag = 0;

        // If given is not prefix of any other word
        if (isEmpty(p))
        {
            push_stack(s, p->member);
            free(p);
            p = NULL;
        }
        return p;
    }

    // If not last character, recur for the child
    // obtained using ASCII value
    int index;
    if (key[depth] != ' ')
        index = key[depth] - 'a';
    else // if this is space then assign it to 26 because 26 is the pointer for space
        index = 26;
    p->children[index] = remove_(&p->children[index], key, depth + 1, s);

    // If p does not have any child (its only child got
    // deleted), and it is not end of another word.
    if (isEmpty(p) && p->flag == 0)
    {
        // push_stack(s, p->member);
        free(p);
        p = NULL;
    }
    return p;
}

// add contacts to favourite
void Make_Favourite(Phonebook root, char *key, list *l)
{

    int i;                    // i for sting index traversing
    int length = strlen(key); // length for storing the length of sting
    int index;                // index is for referring pointer name in trie

    // p is the pointer to the nodes of trie
    node *p = root;

    // actual checking of the occurrence of the name
    for (i = 0; i < length; i++)
    {

        // if the present character is not space
        // then assign pointer number to the index
        if (key[i] != ' ')
            index = (key[i] - 'a');
        else // if this is space then assign it to 26 because 26 is the pointer for space
            index = 26;

        // if index number of pointer is not available then return false ie 0
        if (!p->children[index])
        {
            printf("%s is not available in the phone \n", key);
            return;
        }
        // pointer available go to that node
        p = p->children[index];
    }

    // if that node exist and flag of that node is true then
    // that person exist
    if (p != NULL && p->flag)
    {
        append(l, p->member);
        printf("%s added successfully in the Favourite phone \n", key);
        return;
    }
    else
    {
        printf("%s is not available in the phone \n", key);
    }
    return;
}

// Function to split nodes of the given doubly linked list into
// two halves using the fast/slow pointer strategy
void split(list *head, list *a, list *b)
{
    link_node *slow = *head;
    link_node *fast = slow->next;

    // advance `fast` by two nodes, and advance `slow` by a single node
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *b = slow->next;
    slow->next = NULL;
}

// Recursive function to merge nodes of two sorted lists
// into a single sorted list
list merge(list a, list b)
{
    // base cases
    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

    // pick either `a` or `b`, and recur
    if (strcmp(a->data.name, b->data.name) < 0)
    {
        a->next = merge(a->next, b);
        a->next->prev = a;
        a->prev = NULL;
        return a;
    }
    else
    {
        b->next = merge(a, b->next);
        b->next->prev = b;
        b->prev = NULL;
        return b;
    }
}

// Function to sort a doubly-linked list using merge sort algorithm
void mergesort(list *head)
{

    // base case: 0 or 1 node
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    // split head into `a` and `b` sublists
    link_node *a = *head, *b = NULL;

    split(head, &a, &b);

    // recursively sort the sublists
    mergesort(&a);
    mergesort(&b);

    // merge the two sorted lists
    *head = merge(a, b);
}

void modify_Person(Person *p, char *del_name, Phonebook *root)
{

Again:
{
    int ch;
    printf("Which Information you want to modify \n");
    printf("\t 1. Name,  \t 2. Number, \n\t 3. Email, \t 4. Date of birth, \n\t 5. Address\n");
    printf("\tChoice : ");
    scanf("%d", &ch);
    char _name[30];

    if (ch == 1)
    {

        Person *safe = p;
        stack s; // temp stack no use
        init_stack(&s, 1);
        remove_(root, del_name, 0, &s);
        printf("Enter Name : ");
        scanf("%s", _name);
        // scanf("%[^\n]s", _name);
        // gets(_name);
        char *temp = (char *)malloc(sizeof(char) * strlen(_name));
        strcpy(temp, _name);
        safe->name = temp;
        insert(root, temp, *safe);
        return;
    }

    else if (ch == 2)
    {
        printf("Enter Number : ");
        scanf("%s", _name);
        char *temp;
        temp = (char *)malloc(sizeof(char) * strlen(_name));
        strcpy(temp, _name);
        p->NUMBER = temp;
        isvalid_number(p);
        return;
    }

    else if (ch == 3)
    {
        printf("Enter Email : ");
        char _num[20];
        scanf("%s", _num);
        char *temp = (char *)malloc(sizeof(char) * strlen(_num));
        strcpy(temp, _num);
        p->email = temp;
        return;
    }

    else if (ch == 4)
    {
        printf("Enter DOB : ");
        int _DOB;
        scanf("%d", &_DOB);
        p->DOB = _DOB;
        return;
    }

    else if (ch == 5)
    {
        printf("Enter Address : ");
        scanf("%s", _name);
        char *temp;
        temp = (char *)malloc(sizeof(char) * strlen(_name));
        strcpy(temp, _name);
        p->address = temp;
        return;
    }

    else
    {
        printf("Invalid Choice \n");
        goto Again;
    }

} // label

    return;
}

void edit_contact(Phonebook *root)
{

    char fun1_name[30] = "";

    printf("Enter Which Contact you want to modify ?\n");
    printf("Name -? ");
    // gets(fun1_name);
    scanf("%s", fun1_name);
    // initialization part
    // i for sting index traversing
    int length = strlen(fun1_name); // length for storing the length of sting
    int index = 0;                  // index is for referring pointer fun1_name in trie

    // p is the pointer to the nodes of trie
    node *p = *root;

    // actual checking of the occurrence of the fun1_name
    for (int i = 0; i < length; i++)
    {

        // if the present character is not space
        // then assign pointer number to the index
        if (fun1_name[i] != ' ')
            index = fun1_name[i] - 'a';
        else // if this is space then assign it to 26 because 26 is the pointer for space
            index = 26;

        // if index number of pointer is not available then return false ie 0
        if (!p->children[index])
        {
            printf("Entered name %s is not present in Phonebook %c \n", fun1_name, fun1_name[i]);
            return;
        }
        // pointer available go to that node
        p = p->children[index];
    }

    // if that node exist and flag of that node is true then
    // that person exist
    if (p != NULL && p->flag)
    {
        // Person mod_per = p->member;
        modify_Person(&p->member, fun1_name, root);
        return;
        // *********************************************************************************************************************************************
    }
    printf("Entered name %s is not present in Phonebook \n", fun1_name);
    return;
}

void add_Person(Phonebook *root)
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

    insert(root, p->name, *p);

    return;
}

// get person
Person *get_Person()
{

    char _name[30];

    Person *p = (Person *)malloc(sizeof(Person));

    printf("Enter Name : ");
    scanf("%s", _name);
    // scanf("%[^\n]s", _name);
    // gets(_name);
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
    char _num[20] = "";
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

    return p;
}

// inserting contact to the private phonebook
void restore(Pri_Phonebook *t, stack *s, Phonebook *tt)
{

    int chance = 3;

    printf("\n \t *** Adding Private Contact *** \n");

    while (chance > 1)
    {

        int temp = strcmp("Shu", Get_password());

        if (temp == 0)
        {
            printf("\n *** Password is Correct ***\n");
            Person p = peek_Stack(*s);
            insert(tt, p.name, p);
            pop_stack(s);
            printf("\n Contact Restored Successfully  \n");
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
