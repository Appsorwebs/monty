#include "monty.h"

/**
 * delete_dnodeint_at_index - a function that Deletes a node
 *                            at specified index
 * @head: A pointer to the pointer which inturn points to the head of the list.
 * @index: The index at which an element to be deleted.
 * Return: 1 if it succeeded, -1 if it failed
 *
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *traverse = *head;

	if (*head == NULL)
		return (-1);
	for (; index != 0; index--)
	{
		if (traverse == NULL)
			return (-1);
		traverse = traverse->next;
	}

	if (traverse == *head)
	{
		*head = traverse->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		traverse->prev->next = traverse->next;
		if (traverse->next != NULL)
			traverse->next->prev = traverse->prev;
	}
	free(traverse);
	return (1);
}

/**
 * free_dlistint - a fucntion that frees a dlistint_t list
 * @head: A pointer to the head of the list
 * Return: nothing
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}

	head = NULL;
}