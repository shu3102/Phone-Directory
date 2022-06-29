
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Phone.h"

void traverse_stack(stack l)
{
    int t = l.top;
    while (t >= 0)
    {
        printf("________________________________________________________________________________\n");
        printf(" %20s %25s %24s\n", l.a[t].name, l.a[t].NUMBER, l.a[t].address);
        //printf("________________________________________________________________________________\n");
        t--;
    }
}

//Defination of all function
void init_stack(stack *s, int len)
{
    s->a = (Person *)malloc(sizeof(Person) * len);
    s->size = len;
    s->top = -1;
}

int isFull_stack(stack s)
{
    if (s.top == s.size - 1)
        return 1;
    else
        return 0;
}

int isEmpty_stack(stack s)
{
    if (s.top == -1)
        return 1;
    else
        return 0;
}

void push_stack(stack *s, Person d)
{
    if (isFull_stack(*s))
        return;
    else
    {
        s->top++;
        s->a[s->top] = d;
        return;
    }
}

void pop_stack(stack *s)
{
    if (isEmpty_stack(*s))
        return;
    else
    {
        //t = s->a[s->top];
        s->top--;
    }
    return;
}

Person peek_Stack(stack s)
{
    Person t = {" ", " ", " ", INT_MIN, " "};
    if (isEmpty_stack(s))
        return t;
    else
    {
        t = s.a[s.top];
    }
    return t;
}
