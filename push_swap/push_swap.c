/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:50:47 by ljh               #+#    #+#             */
/*   Updated: 2023/10/09 20:25:46 by ljh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int		ft_stack_init(t_stack *stack);
int		ft_push(t_stack *stack, int num);
int 	ft_pop(t_stack *stack);
int     ft_isnum(char *str);
int     ft_peek(t_stack *stack);
int		ft_size(t_stack *stack);
int     ft_is_empty(t_stack *stack);
void    ft_swap(t_stack *stack, char a_or_b);
void    *ft_elem_generate(int num);
void    ft_print(void *num);
int		ft_push(t_stack *stack, int num);
void    ft_rotate(t_stack *stack, char a_or_b);
void	ft_rev_rotate(t_stack *stack, char a_or_b);
void	two_stack_print(t_stack a, t_stack b);
int		ft_push_other(t_stack *src, t_stack *des, char a_or_b);

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
	(void)ft_stack_init(&stack_a);
	(void)ft_stack_init(&stack_b);
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
	two_stack_print(stack_a, stack_b);
	ft_swap(&stack_a, 'a');
	(void)ft_push_other(&stack_a, &stack_b, 'b');

	dlst_del_all(stack_a.head, free);	
	dlst_del_all(stack_b.head, free);	
	// atexit(check_leak);
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
	stack->top = stack->top->next;
	return (1);
}

int ft_pop(t_stack *stack)
{
	int	num;

	num = ft_peek(stack);
	stack->top = stack->top->prev;
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
	return (*(int *)(stack->top->elem));
}

int	ft_size(t_stack *stack)
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

void    ft_swap(t_stack *stack, char a_or_b)
{
	void	*tmp;
	t_dlst	*last_node;

	if (ft_size(stack) < 2)
		return ;
	last_node = stack->tail->prev;
	tmp = last_node->elem;
	last_node->elem = last_node->prev->elem;
	last_node->prev->elem = tmp;
	if (a_or_b == 'a')
		ft_printf("sa\n");
	else if (a_or_b == 'b')
		ft_printf("sb\n");
}

void    ft_rotate(t_stack *stack, char a_or_b)
{
	t_dlst	*node;
	t_dlst	*head;
	t_dlst	*tail;

	head = stack->head;
	tail = stack->tail;
	node = tail->prev;
	node->prev->next = tail;
	tail->prev = node->prev;
	node->next = head->next;
	head->next->prev = node;
	node->prev = head;
	head->next = node;
	stack->top = stack->tail->prev;
	if (a_or_b == 'a')
		ft_printf("ra\n");
	else if (a_or_b == 'b')
		ft_printf("rb\n");
}

void	ft_rev_rotate(t_stack *stack, char a_or_b)
{
	t_dlst	*node;
	t_dlst	*head;
	t_dlst	*tail;

	head = stack->head;
	tail = stack->tail;
	node = head->next;
	head->next = node->next;
	node->next->prev = head;
	tail->prev->next = node;
	node->prev = tail->prev;
	tail->prev = node;
	node->next = tail;
	stack->top = stack->tail->prev;
	if (a_or_b == 'a')
		ft_printf("rra\n");
	else if (a_or_b == 'b')
		ft_printf("rrb\n");
}

void	two_stack_print(t_stack a, t_stack b)
{
	int		a_size;
	int		b_size;
	int		i;
	t_dlst	*a_tmp;
	t_dlst	*b_tmp;

	a_size = ft_size(&a);
	b_size = ft_size(&b);
	a_tmp = a.tail->prev;
	b_tmp = b.tail->prev;
	if (a_size > b_size)
		i = a_size;
	else
		i = b_size;
	printf("------------------------\n");
	while (i > 0)
	{
		if (i == a_size)
		{
			printf("%10d ", *(int *)a_tmp->elem);
			a_size--;
			a_tmp = a_tmp->prev;
		}
		else
			printf("  ");
		if (i == b_size)
		{
			printf("%10d ", *(int *)b_tmp->elem);
			b_size--;
			b_tmp = b_tmp->prev;
		}
		printf("\n");
		i--;
	}
	printf("%10c %10c\n", '-', '-');
	printf("%10c %10c\n", 'a', 'b');
	printf("------------------------\n");
	printf("\n");
}

int	ft_push_other(t_stack *src, t_stack *des, char a_or_b)
{
	int	num;

	if (ft_size(src) == 0)
		return (0);
	num = ft_pop(src);
	if (ft_push(des, num) < 0)
		return (-1);
	if (a_or_b == 'a')
		ft_printf("pa\n");
	else if (a_or_b == 'b')
		ft_printf("pb\n");
	return (1);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a, '1');
	ft_swap(b, '1');
	ft_printf("ss\n");
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a, '1');
	ft_rotate(b, '1');
	ft_printf("rr\n");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rev_rotate(a, '1');
	ft_rev_rotate(b, '1');
	ft_printf("rrr\n");
}