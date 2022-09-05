#define Alphabet 27
#define STACK_CAPACITY 5



typedef struct Person{
    char *name;
    char *NUMBER;
    char *email;
    int DOB;
    char *address;
}Person;


typedef struct node{
    Person member;
    struct node *children[Alphabet];
    int flag;
}node;

typedef node* Phonebook;




typedef struct stack{
    Person *a;
    int size;
    int top;
}stack;



void pop_stack(stack *s);
void push_stack(stack *s, Person d);
int isEmpty_stack(stack s);
int isFull_stack(stack s);
void init_stack(stack *s, int len);
void traverse_stack(stack l);
Person peek_Stack(stack s);



//creation of link_node
typedef struct link_node{
    Person data;
    struct link_node *next, *prev;
}link_node;

// creating or changing name to list
typedef link_node* list;


int lenght( list *l);
void append(list *l, Person d);
void init_List(list *l);
void traverse_List(list l);






// functions
node* getnode();
void insert(Phonebook *t, char* s, Person _check);
//void printall(Phonebook *t, char s[], int level);
void printall(Phonebook *t, char s[], int i);

void printall_reverse(Phonebook *t, char s[], int index);

void excel(char filename[], Phonebook *phone);
void main_ex(Phonebook *t);
int search_perticular(Phonebook root, const char *key);
void search_all(Phonebook *t);
Phonebook remove_(Phonebook* root, char* key, int depth, stack *s);
void edit_contact(Phonebook *root);
void add_Person(Phonebook *root);
void isvalid_number(Person* e);
void Make_Favourite(Phonebook root, char *key, list *l);
Person* get_Person();




// private phonebook
typedef struct Pri_Phonebook{
    node* Phonebook;
    // password for phomebook
    char *password_;

}Pri_Phonebook;


Pri_Phonebook* GetPrivateNode(char* pass);
void insert_private(Pri_Phonebook *t, char* s, Person _check);
void Print_private(Pri_Phonebook *t, char s[], int index);
void Private_add_contact(Pri_Phonebook *t);
void mergesort(list* head);
char* Get_password();
void restore(Pri_Phonebook *t, stack *s, Phonebook *tt);
