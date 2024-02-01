#include "monty.h"

/**
 * del_node_idx - Delete a specific node in stack_t type list
 * @head: Head of the stack
 * @idx: index of the node to delete, starting at 0
 * Return: 1 success or -1 if it fails
 */

int del_node_idx(stack_t **head, unsigned int idx)
{
    stack_t *node, *del_node;
    unsigned int i = 0;

    if (*head == NULL)
        return (-1);
    node = *head;
    while (node && i < idx)
    {
        node = node->next;
        i++;
    }
    if (i < idx)
        return (-1);
    if (i == 0 && node->next)
    {
        del_node = node;
        node = node->next;
        node->prev = NULL;
        *head = node;
        free(del_node);
        return (1);
    }
    else if (i > 0)
    {
        del_node = node;
        node = node->prev;
        node->next = del_node->next;
        free(del_node);
    }
    else
    {
        *head = node->next;
        free(node);
    }
    return (1);
}

/**
 * len_stack - Calculates the length of the stack
 * @head: Head of the stack dlist
 * Return: number of nodes in the stack
 */

size_t len_stack(const stack_t *head)
{
    unsigned int len = 0;

    while (head != NULL)
    {
        head = head->next;
        len++;
    }
    return (len);
}

/**
 * swap - Swap the top two element of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: line number
 * Return: Nothing (void)
 */

void swap(stack_t **stack, unsigned int line_number)
{
    char mess[100];
    stack_t *first, *second;
    int temp;

    if (len_stack(*stack) < 2 || *stack == NULL)
    {
        sprintf(mess, "L%u: can't swap, stack too short", line_number);
        error_mes(mess, "", stack);
    }

    first = *stack;
    second = first->next;
    temp = second->n;
    second->n = first->n;
    first->n = temp;
}

/**
 * rotl - Rotate the stack up one, the top element shift to the bottom
 * @stack: Pointer to the head of the stack
 * @line_number: line number
 * Return: Nothing (void)
 */

void rotl(stack_t **stack, unsigned int line_number)
{
    int temp;
    stack_t *help, *new, *root;

    (void)line_number;
    help = *stack;
    if (*stack == NULL)
        return;
    if (len_stack(*stack) > 1)
    {
        temp = help->n;
        del_node_idx(stack, 0);
        new = malloc(sizeof(*new));
        if (!new)
            error_mes("Error: malloc failed", "", stack);
        root = *stack;
        new->n = temp;
        new->next = NULL;
        if (help == NULL)
        {
            new->prev = NULL;
            help = new;
        }
        while (root->next)
            root = root->next;
        new->prev = root;
        root->next = new;
    }
}

/**
 * rotr - Rotate the stack down one, the bottom element shift to the top
 * @stack: Pointer to the head of the stack
 * @line_number: line number
 * Return: Nothing (void)
 */

void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *element1, *element2;

    (void)line_number;
    element1 = *stack;
    if (element1 == NULL)
        return;
    element2 = element1;
    if (element1->next == NULL)
        ;
    else
    {
        while (element2->next != NULL)
            element2 = element2->next;
        element2->prev->next = NULL;
        element2->prev = NULL;
        element2->next = element1;
        element1->prev = element2;
        *stack = element2;
    }
}
