/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:50:47 by ljh               #+#    #+#             */
/*   Updated: 2023/10/04 22:41:58 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_push(t_stack *stack, int num);
int 	ft_pop(t_stack *stack);
int     ft_isnum(char *str);
int     ft_peek(t_stack *stack);
int		ft_size(t_stack *stack);
int     ft_is_empty(t_stack *stack);
void    ft_swap(t_stack *stack);
void    *ft_elem_generate(int num);
void    ft_print(void *num);
int		ft_push(t_stack *stack, int num);
void    ft_rotate(t_dlst *head, t_dlst *tail);
void	ft_rev_rotate(t_dlst *head, t_dlst *tail);

void	check_leak(void)
{
	system("leaks --list push_swap");
}

int main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
    int     i;

	if (argc < 1)
        return (-1);
    (void)dlst_init(&stack_a.head, &stack_a.tail);
	(void)dlst_init(&stack_b.head, &stack_b.tail);
    i = 1;
    while (i < argc)
	{
		if (ft_isnum(argv[i]) < 0)
		{
			ft_printf("Error\nNot num!");
			return (-1);
		}
		ft_push(&stack_a, ft_atoi(argv[i++]));
	}
	ft_printf("Stack A : %d\n", ft_size(&stack_a));
	dlst_print(stack_a.head, ft_print);
	ft_printf("\n");
	dlst_rev_print(stack_a.tail, ft_print);
	ft_printf("\n");
	ft_rev_rotate(stack_a.head, stack_a.tail);
	ft_printf("\n");
	dlst_print(stack_a.head, ft_print);
	ft_printf("\n");
	dlst_rev_print(stack_a.tail, ft_print);
	ft_printf("\n");
	ft_rev_rotate(stack_a.head, stack_a.tail);
	ft_printf("\n");
	dlst_print(stack_a.head, ft_print);
	ft_printf("\n");
	dlst_rev_print(stack_a.tail, ft_print);
	ft_printf("\n");
	ft_rev_rotate(stack_a.head, stack_a.tail);
	ft_printf("\n");
	dlst_print(stack_a.head, ft_print);
	ft_printf("\n");
	dlst_rev_print(stack_a.tail, ft_print);
	ft_printf("\n");
	ft_printf("Stack B : %d\n", ft_size(&stack_b));
	dlst_print(stack_b.head, ft_print);
	ft_printf("\n");
	dlst_del_all(stack_a.head, free);	
	dlst_del_all(stack_b.head, free);	
	atexit(check_leak);
    return (0);
}

int	ft_stack_init(t_stack *stack)
{
	if (dlst_init(&stack->head, &stack->tail) < 0)
		return (-1);
	stack->top = stack->head;
	return (1);
}

int	ft_push(t_stack *stack, int num)
{
	void	*elem;

	elem = ft_elem_generate(num);
	if (elem == NULL)
		return (-1);
	if (dlst_add_last(stack->tail, elem) < 0)
		return (-1);
	return (1);
}

int ft_pop(t_stack *stack)
{
	int	num;

	num = ft_peek(stack);
	dlst_del_last(stack->tail, free);
	return (num);
}

void    *ft_elem_generate(int num)
{
    void    *elem;

    elem = (void *)malloc(sizeof(int));
	if (elem == NULL)
		return (NULL);
    *(int *)elem = num;
    return (elem);
}

void    ft_print(void *num)
{
	if (num == NULL)
		ft_printf("NULL ");
	else
    	ft_printf("%d ", *(int *)num);
}

int ft_isnum(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
    while (*str)
    {
        if (ft_isdigit(*(str)) == 0)
            return (-1);
        str++;
    }
    return (1);
}

int ft_peek(t_stack *stack)
{
	return (*(int *)dlst_last_elem(stack->tail));
}

int		ft_size(t_stack *stack)
{
	t_dlst	*node;
	int		size;

	size = 0;
	node = stack->head->next;
	while (node->next)
	{
		size++;
		node = node->next;
	}
	return (size);
}

int ft_is_empty(t_stack *stack)
{
	if (ft_size(stack) == 0)
		return (1);
	return (0);
}

void    ft_swap(t_stack *stack)
{
	void	*tmp;
	t_dlst	*last_node;

	if (ft_size(stack) < 2)
		return ;
	last_node = stack->tail->prev;
	tmp = last_node->elem;
	last_node->elem = last_node->prev->elem;
	last_node->prev->elem = tmp;	
}

void    ft_rotate(t_dlst *head, t_dlst *tail)
{
	t_dlst	*node;

	node = tail->prev;
	node->prev->next = tail;
	tail->prev = node->prev;
	node->next = head->next;
	head->next->prev = node;
	node->prev = head;
	head->next = node;
}

void	ft_rev_rotate(t_dlst *head, t_dlst *tail)
{
	t_dlst	*node;

	node = head->next;
	head->next = node->next;
	node->next->prev = head;
	tail->prev->next = node;
	node->prev = tail->prev;
	tail->prev = node;
	node->next = tail;
}