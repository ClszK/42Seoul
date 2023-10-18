/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljh <ljh@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 17:50:47 by ljh               #+#    #+#             */
/*   Updated: 2023/10/16 06:53:43 by ljh              ###   ########.fr       */
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

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int tmp;

	i = size;
	while ((--i) > 0)
	{
		j = 0;
		while (j < i)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
	}
}

int	find_top(t_stack *b, t_node *top)
{
	t_node	*tmp;
	int		cnt;

	cnt = 0;
	tmp = b->top;
	if (tmp->prev == top)
		return (0);
	while (tmp != top)
	{
		tmp = tmp->prev;
		cnt++;
	}
	return (cnt);
}

int	find_bottom(t_stack *b, t_node *bottom)
{
	t_node	*tmp;
	int		cnt;

	cnt = 0;
	tmp = b->head->next;
	while (tmp != bottom)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}

void	top_command(t_stackset *stack, t_node *top, int *min, int *max, int *num_arr)
{
	if (stack->b.top->prev == top)
		ft_swap(&stack->b, 'b');
	else
		while (stack->b.top != top)
			ft_rotate(&stack->b, 'b');
	ft_push_other(&stack->b, &stack->a, 'a');
	if (num_arr[*max] != ft_peek(&stack->a))
	{
		*min += 1;
		ft_rotate(&stack->a, 'a');
	}
	else
		*max -= 1;
}

void	bottom_command(t_stackset *stack, t_node *bottom, int *min, int *max, int *num_arr)
{
	while (stack->b.head->next != bottom)
		ft_rev_rotate(&stack->b, 'b');
	ft_rev_rotate(&stack->b, 'b');
	ft_push_other(&stack->b, &stack->a, 'a');
	if (num_arr[*max] != ft_peek(&stack->a))
	{
		*min += 1;
		ft_rotate(&stack->a, 'a');
	}
	else
		*max -= 1;
}

void	greedy(t_stackset *stack, int *min, int *max, int *num_arr)
{
	t_node	*bottom;
	t_node	*top;
	int		top_find;
	int		bottom_find;

	top = stack->b.top;
	bottom = stack->b.head->next;
	top_find = 0;
	bottom_find = 0;
	while (top != bottom)
	{
		if (top_find == 0 &&(!(*(int *)top->elem == num_arr[*min] || *(int *)top->elem == num_arr[*max])))
			top = top->prev;
		else
			top_find = 1;
		if (bottom_find == 0 && (!(*(int *)bottom->elem == num_arr[*min] || *(int *)bottom->elem == num_arr[*max])))
			bottom = bottom->next;
		else
			bottom_find = 1;
		if (top->prev == bottom || (top_find == 1 && bottom_find == 1))
			break ;
	}
	if(find_top(&stack->b, top) < find_bottom(&stack->b, bottom) + 1)
		top_command(stack, top, min, max, num_arr);
	else
		bottom_command(stack, bottom, min, max, num_arr);
}

void	partition(t_stackset *stack, int start, int end, int *num_arr)
{
	int		size;
	int		rb_cnt;
	t_stack	*a;
	t_stack	*b;
	int		firstEnd;
	int		secondEnd;

	a = &stack->a;
	b = &stack->b;
	firstEnd = start + (end - start) / 3;
	secondEnd = start + (end - start) / 3 * 2 + 1;
	size = end - start;
	rb_cnt = 0;

	while (size-- > 0)
	{
		if (*(int *)a->top->elem <= num_arr[firstEnd])
		{
			if (ft_is_empty(b))
				ft_push_other(a, b, 'b');
			else
			{
				ft_push_other(a, b, 'b');
				ft_rotate(b, 'b');
				rb_cnt++;
			}
		}
		else if (*(int *)a->top->elem <= num_arr[secondEnd])
			ft_push_other(a, b, 'b');
		else
		{
			ft_rotate(a, 'a');
			rb_cnt++;
		}
	}
	while (rb_cnt-- >= 0)
		ft_push_other(a, b, 'b');
}

// void	quicksort(t_stackset *stack, int start, int end, int *num_arr)
// {
// 	int	firstEnd;
// 	int	secondEnd;

// 	stack->sort_cnt = 0;

// 	if (end - start < 2)
// 	// printf("%d %d\n", num_arr[start], num_arr[end]);
// 	partition(stack, start, end ,num_arr);
// 	firstEnd = start + (end - start) / 3;
// 	secondEnd = start + (end - start) / 3 * 2 + 1;
// 	printf("pos : %d %d\n", start, end);
// 	printf("first, second : %d %d\n", firstEnd, secondEnd);
// 	quicksort(stack, secondEnd + 1, end, num_arr);
// 	quicksort(stack, firstEnd + 1, secondEnd, num_arr);
// 	quicksort(stack, start, firstEnd, num_arr);
// }

void	test(t_stack *a, t_stack *b)
{
	int	size;

	size = ft_size(a);

	while (size-- > 0)
	{
		if (*(int *)a->top->elem <= 6)
		{
			if (ft_is_empty(b))
				ft_push_other(a, b, 'b');
			else
			{
				ft_push_other(a, b, 'b');
				ft_rotate(b, 'b');
			}
		}
		else if (*(int *)a->top->elem <= 12)
			ft_push_other(a, b, 'b');
		else
			ft_rotate(a, 'a');
	}
}

void	test2(t_stack *a, t_stack *b)
{
	int	size;

	size = ft_size(a);

	while (size-- > 0)
	{
		if (*(int *)a->top->elem <= 15)
		{
			if (ft_is_empty(b))
				ft_push_other(a, b, 'b');
			else
			{
				ft_push_other(a, b, 'b');
				ft_rotate(b, 'b');
			}
		}
		else if (*(int *)a->top->elem <= 17)
			ft_push_other(a, b, 'b');
		else
			ft_rotate(a, 'a');
	}
}

void	test3(t_stack *a, t_stack *b)
{
	int	size;

	size = ft_size(a);

	while (size-- > 0)
	{
		if (*(int *)a->top->elem <= 15)
		{
			if (ft_is_empty(b))
				ft_push_other(a, b, 'b');
			else
			{
				ft_push_other(a, b, 'b');
				ft_rotate(b, 'b');
			}
		}
		else if (*(int *)a->top->elem <= 17)
			ft_push_other(a, b, 'b');
		else
			ft_rotate(a, 'a');
		two_stack_print(*a, *b);
	}
}

int main(int argc, char *argv[])
{
	t_stackset	stack;
    int     i;
	int		*num_arr;
	int		min;
	int		max;

	if (argc < 1)
        return (-1);
	(void)ft_stack_init(&stack.a);
	(void)ft_stack_init(&stack.b);
    i = argc - 1;
	min	= 0;
	max = argc - 2;
	num_arr = (int *)malloc(sizeof(int) * (argc - 1));
    while (i >= 1)
	{
		if (ft_isnum(argv[i]) < 0)
		{
			ft_printf("Error\nNot num!");
			return (-1);
		}
		num_arr[i - 1] = ft_atoi(argv[i]);
		ft_push(&stack.a, ft_atoi(argv[i--]));
	}
	ft_sort_int_tab(num_arr, argc - 1);
	partition(&stack, 0, argc - 1, num_arr);
	i = 0;
	while(i++ < argc - 1)
		greedy(&stack, &min, &max, num_arr);
	while (*(int *)stack.a.head->next->elem != num_arr[argc - 2])
		ft_rev_rotate(&stack.a, 'a');
	dlst_del_all(stack.a.head, free);	
	dlst_del_all(stack.b.head, free);	
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
	t_node	*node;
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
	t_node	*last_node;

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
	t_node	*node;
	t_node	*head;
	t_node	*tail;

	if (ft_size(stack) <= 1)
		return ;
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
	t_node	*node;
	t_node	*head;
	t_node	*tail;

	if (ft_size(stack) <= 1)
		return ;
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
	int		x;
	t_node	*a_tmp;
	t_node	*b_tmp;

	a_size = ft_size(&a);
	b_size = ft_size(&b);
	a_tmp = a.tail->prev;
	b_tmp = b.tail->prev;
	if (a_size > b_size)
		i = a_size;
	else
		i = b_size;
	printf("------------------------------------------------\n");
	while (i > 0)
	{
		// if (i == a_size)
		// {
		// 	printf("%10d ", *(int *)a_tmp->elem);
		// 	a_size--;
		// 	a_tmp = a_tmp->prev;
		// }
		// else
		// 	printf("  ");
		// if (i == b_size)
		// {
		// 	printf("%10d ", *(int *)b_tmp->elem);
		// 	b_size--;
		// 	b_tmp = b_tmp->prev;
		// }
		if (i == a_size)
		{
			for(x = 20; x >= 0; x--)
			{
				if (x < *(int *)a_tmp->elem)
					printf("*");
				else
					printf(" ");
			}
			a_size--;
			a_tmp = a_tmp->prev;
		}
		else 
			printf("                     ");
		printf("     ");
		if (i == b_size)
		{
			for(x = 0; x < 20; x++)
			{
				if (x < *(int *)b_tmp->elem)
					printf("*");
				else
					printf(" ");
			}
			b_size--;
			b_tmp = b_tmp->prev;
		}
		printf("\n");
		i--;
	}
	printf("%20c %20c\n", '-', '-');
	printf("%20c %20c\n", 'a', 'b');
	printf("------------------------------------------------\n");
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