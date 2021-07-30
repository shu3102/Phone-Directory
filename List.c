
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Phone.h"




// initialization of the link_node
void init_List(list *l){
   *l = NULL;
    return;
}




//traversing the link list
void traverse_List(list l){
    printf("\n\t * | Favourite Contact list | *\n");
    link_node *p;
    p = l;
    printf("                Name                   Number                Address\n");
    printf("_______________________________________________________________________________\n");
    printf("\n");

    while(p){
        printf("%20s %25s %24s\n", p->data.name, p->data.NUMBER, p->data.address);
        //printf("%s ", p->data.name);
        p = p->next;
    }
    printf("_______________________________________________________________________________\n");
    printf("\n");
    return;
}




// find lenght of link list
int lenght( list *l) {
    link_node *p = *l;
    int c = 0;
    while(p) {
        c++;
        p = p->next;
    }
    return c;

}



// appending the node at the last of link list
void append(list *l, Person d) {
    link_node *p, *newnode;
    newnode = (link_node*)malloc(sizeof(link_node));
    if(newnode){
        newnode -> data = d;
        newnode -> next = NULL;
        newnode -> prev = NULL;
    }
    else return;

    if(*l == NULL){
        *l = newnode;
        return;
    }
    p = *l;

    while(p -> next) {
        p = p->next;
    }

    p->next = newnode;
    newnode->prev = p;
    return;
}


