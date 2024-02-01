#include "monty.h"
/**
 * add - Calculates the sum of the top 2 elements on stack or queue.
 * @stack: Stack.
 * @line_number: Line number.
 */
void add(stack_t **stack, unsigned int line_number)
{
    char mess[100];

    sprintf(mess, "L%d: can't add, stack too short", line_number);
    if (!stack)
        error_mes("No stack present.", "", stack);
    if (!*stack || !(*stack)->next)
        error_mes(mess, "", stack);
    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}
/**
 * sub - Calculates the substraction of the top 2 elements on stack or queue.
 * @stack: Stack.
 * @line_number: Line number.
 */
void sub(stack_t **stack, unsigned int line_number)
{
    char mess[100];

    sprintf(mess, "L%d: can't sub, stack too short", line_number);
    if (!stack)
        error_mes("No stack present.", "", stack);
    if (!*stack || !(*stack)->next)
        error_mes(mess, "", stack);
    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}
/**
 * divv - Calculates the divvsion of the top 2 elements on stack or queue.
 * @stack: Stack.
 * @line_number: Line number.
 */
void divv(stack_t **stack, unsigned int line_number)
{
    char mess[100];

    sprintf(mess, "L%d: can't divv, stack too short", line_number);
    if (!stack)
        error_mes("No stack present.", "", stack);
    if (!*stack || !(*stack)->next)
        error_mes(mess, "", stack);
    sprintf(mess, "L%d: divvsion by zero", line_number);
    if (!(*stack)->n)
        error_mes(mess, "", stack);
    (*stack)->next->n /= (*stack)->n;
    pop(stack, line_number);
}
/**
 * mul - Calculates the multiplication of the top 2 elements on stack or queue.
 * @stack: Stack.
 * @line_number: Line number.
 */
void mul(stack_t **stack, unsigned int line_number)
{
    char mess[100];

    sprintf(mess, "L%d: can't mul, stack too short", line_number);
    if (!stack)
        error_mes("No stack present.", "", stack);
    if (!*stack || !(*stack)->next)
        error_mes(mess, "", stack);
    (*stack)->next->n *= (*stack)->n;
    pop(stack, line_number);
}
/**
 * mod - Calculates the modulus of the top 2 elements on stack or queue.
 * @stack: Stack.
 * @line_number: Line number.
 */
void mod(stack_t **stack, unsigned int line_number)
{
    char mess[100];

    sprintf(mess, "L%d: can't mod, stack too short", line_number);
    if (!stack)
        error_mes("No stack present.", "", stack);
    if (!*stack || !(*stack)->next)
        error_mes(mess, "", stack);
    sprintf(mess, "L%d: divvsion by zero", line_number);
    if (!(*stack)->n)
        error_mes(mess, "", stack);
    (*stack)->next->n %= (*stack)->n;
    pop(stack, line_number);
}
