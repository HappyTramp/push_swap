#ifndef ACTION_H
# define ACTION_H

# include "stack.h"

void swap_a(t_stack *a);
void swap_b(t_stack *b);
void swap_both(t_stack *a, t_stack *b);
void push_a(t_stack *a, t_stack *b);
void push_b(t_stack *b, t_stack *a);
void rotate_a(t_stack *a);
void rotate_b(t_stack *b);
void rotate_both(t_stack *a, t_stack *b);
void reverse_rotate_a(t_stack *a);
void reverse_rotate_b(t_stack *b);
void reverse_rotate_both(t_stack *a, t_stack *b);


#endif
