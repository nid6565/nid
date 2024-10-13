#include "monty.h"

/**
 * exec_loop - Split and execute opcode commands
 * @a: Global struct for buffers.
 */
void exec_loop(buf_struct *a)
{
    stack_t *stack = NULL;
    int line_n = 1, i = 0;

    while (a->list_cmd[i])
    {
        split_spaces(a->list_cmd[i], a);
        if (strcmp(a->tok_cmd[0], "push") == 0)
        {
            if (!a->tok_cmd[1] || !digits_only(a->tok_cmd[1]))
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_n);
                free_stack(stack); // Free stack before exiting
                exit(EXIT_FAILURE);
            }
            int value = atoi(a->tok_cmd[1]);
            if (value == 0 && strcmp(a->tok_cmd[1], "0") != 0)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_n);
                free_stack(stack); // Free stack before exiting
                exit(EXIT_FAILURE);
            }
            push(&stack, value);
        }
        else
        {
            void (*operation)(stack_t **, unsigned int) = get_op_func(a->tok_cmd[0]);
            if (operation == NULL)
            {
                fprintf(stderr, "L%d: unknown instruction %s\n", line_n, a->tok_cmd[0]);
                free_stack(stack); // Free stack before exiting
                exit(EXIT_FAILURE);
            }
            operation(&stack, line_n);
        }
        line_n++;
        i++;
    }
    free_stack(stack); // Free stack at the end of execution
}

/**
 * get_op_func - selects the correct function to perform
 * @s: name of function
 * Return: pointer to function
 */
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
    instruction_t cmd[] = {
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"sub", sub},
        {"div", _div},
        {"mod", mod},
        {"mul", mul},
        {"nop", nop},
        {"pchar", pchar},
        {"pstr", pstr},
        {"rotl", rotl},
        {"rotr", rotr},
        {"queue", queue},
        {"stack", stack},  // Ensure this points to the correct function
        {NULL, NULL}
    };
    
    for (int i = 0; cmd[i].opcode; i++)
    {
        if (strcmp(s, cmd[i].opcode) == 0)
        {
            return (cmd[i].f);
        }
    }

    // Handle unknown instructions gracefully
    fprintf(stderr, "Unknown instruction: %s\n", s);
    return nop; // Return nop as a default operation
}

