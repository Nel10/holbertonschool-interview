#include "lists.h"
/**
 * insert_node - insert node in a singly linked list
 * @head: head fot the linked list
 * @number: data
 * Return: newNode
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *newNode = NULL;

	if (head == NULL || *head == NULL)
	{
		return (NULL);
	}
	node = *head;
	newNode = malloc(sizeof(listint_t));
	if (newNode == NULL)
		return (NULL);

	newNode->n = number;
	if (node->n > number)
	{
		newNode->next = *head;
		*head = newNode;
	}
	else
	{
		while (node->next->n < number && node->next != NULL)
		{
			node = node->next;
		}
		newNode->next = node->next;
		node->next = newNode;
	}
	return (newNode);
}
