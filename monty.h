#ifndef MONTY_H
#define MONTY_H
/* ########## GLOBAL VARIABLES ########### */
extern char *global_n_value;

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/* ########## STRUCURES ########### */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* ########## PROTOTYPES ########### */

char **split(char *, char *);
int count_tokens(char *, char *);
size_t print_nodes(const stack_t *stack);
stack_t *add_node_to_end(stack_t **stack, const int n);
stack_t *add_node_to_beg(stack_t **satck, const int n);
void push_opcode (stack_t **stack, unsigned int line_number);
void pall_opcode (stack_t **stack, unsigned int line_number);
void (*get_op_func(char *s))(stack_t ** pepe, unsigned int h);

int free_string_list(char **list);
void free_dlistint(stack_t *head);



#endif
