#include <stdio.h>
#include "libft.h"

void *test(void *s)
{
	char *good;

	good = (char *)s;
	while (*good)
		good++;
	*(good++) = '1';
	*(good++) = '\0';
	return (s);
}

int main()
{
	t_list *head;
	t_list *new_head;
	t_list *node;
	void *one;
	void *one1;
	void *one2;
	void *one3;
	void *one4;

	one = (void *)ft_strdup("one");
	one1 = (void *)ft_strdup("one1");
	one2 = (void *)ft_strdup("one2");
	one3 = (void *)ft_strdup("one3");
	one4 = (void *)ft_strdup("one4");

	node = ft_lstnew(one);
	ft_lstadd_back(&head, node);
	ft_lstadd_back(&head, ft_lstnew(one1));
	ft_lstadd_back(&head, ft_lstnew(one2));
	ft_lstadd_back(&head, ft_lstnew(one3));
	ft_lstadd_back(&head, ft_lstnew(one4));
	new_head = ft_lstmap(head, test, free);
	while (head)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
	printf("\n\n");
	while (new_head)
	{
		printf("%s\n", (char *)new_head->content);
		new_head = new_head->next;
	}

	return (0);
}
