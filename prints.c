#include "monty.h"

/**
 * is_ascii - Check if a char is valid ASCII
 * @c: char to check
 * Return: 0 no ascii, 1 on ascii
 */

int is_ascii(int c)
{
    if (c < 0 || c > 127)
        return (0);
    return (1);
}

/**
 * pall - Print all the values on the stack, starting with the top
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: Nothing (void)
 */

void pall(stack_t **stack, unsigned int line_number)
{
    const stack_t *help;

    (void)line_number;
    help = *stack;
    while (help != NULL)
    {
        printf("%d\n", help->n);
        help = help->next;
    }
}

/**
 * pint - Print the value at the top of the stack, followed by a new line
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: Nothing (void)
 */

void pint(stack_t **stack, unsigned int line_number)
{
    const stack_t *help;
    char mess[100];
    unsigned int len_stack = 0;

    help = *stack;
    /** calculate the length of the stack */
    while (help != NULL)
    {
        help = help->next;
        len_stack++;
    }

    if (*stack == NULL || len_stack < 1)
    {
        sprintf(mess, "L%u: can't pint, stack empty", line_number);
        error_mes(mess, "", stack);
    }
    printf("%d\n", (*stack)->n);
}

/**
 * pChar - Print the char at the top of the stack, followed by a new line.
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: Nothing (void)
 */

void pChar(stack_t **stack, unsigned int line_number)
{
    int i;
    stack_t *temp;
    char mess[100];

    temp = *stack;
    if (temp == NULL)
    {
        sprintf(mess, "L%u: can't pChar, stack empty", line_number);
        error_mes(mess, "", stack);
    }
    i = temp->n;
    if (!(is_ascii(i)))
    {
        sprintf(mess, "L%u: can't pChar, value out of range", line_number);
        error_mes(mess, "", stack);
    }
    putchar(i);
    putchar('\n');
}

/**
 * pStr - Print the string starting at the top of the stack,
 * followed by a new line.
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: Nothing (void)
 */

void pStr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    int i;

    (void)line_number;
    temp = *stack;
    while (temp != NULL && temp->n != 0 && is_ascii(temp->n))
    {
        i = temp->n;
        putchar(i);
        temp = temp->next;
    }
    putchar('\n');
}
