#include <stdio.h>
#include <stdlib.h>

typedef struct  stack_el
{
    int value;
    struct stack_el* next;
} stack_el;

stack_el new_stack_el(int value)
{
    stack_el el = {value, NULL};
    return el;
}

void push(stack_el **ptr, int value)
{
    stack_el* new_element = (stack_el*)malloc(sizeof(stack_el));

    new_element->value = value;
    new_element->next = *ptr;

    *ptr = new_element;
}

int pop(stack_el **ptr)
{
    int value;
    stack_el* old_ptr = *ptr;

    *ptr = (*ptr)->next;
    value=old_ptr->value;

    free(old_ptr);
    return value;
}

int main()
{
    stack_el* stack = NULL;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    pop(&stack);
    pop(&stack);
    pop(&stack);

    return 0;
}