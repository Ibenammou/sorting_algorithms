#include "deck.h"

/**
 * _strcmp - compare 2 string
 * @s1: 1st one
 * @s2: 2ns one
 * Return: s1 - s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * card_value - returns the card value
 * @card: card in a deck
 * Return: value between 1 and 52
 */
char card_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}


/**
 * list_deck - function to return length of list
 * @deck: head of list
 *
 * Return: length
 */
void list_deck(deck_node_t **deck)
{
	deck_node_t *runn, *insid, *temp;

	for (runn = (*deck)->next; runn != NULL; runn = temp)
	{
		temp = runn->next;
		insid = runn->prev;
		while (insid != NULL && insid->card->kind > runn->card->kind)
		{
			insid->next = runn->next;
			if (runn->next != NULL)
				runn->next->prev = insid;
			runn->prev = insid->prev;
			runn->next = insid;
			if (insid->prev != NULL)
				insid->prev->next = runn;
			else
				*deck = runn;
			insid->prev = runn;
			insid = runn->prev;
		}
	}
}

/**
 * swap_n - function to swap two nodes in a doubly-linked list
 * @deck: pointer to the head
 * Return: nothing
 */
void swap_n(deck_node_t **deck)
{
	deck_node_t *runn, *insid, *temp;

	for (runn = (*deck)->next; runn != NULL; runn = temp)
	{
		temp = runn->next;
		insid = runn->prev;
		while (insid != NULL &&
				insid->card->kind == runn->card->kind &&
				card_value(insid) > card_value(runn))
		{
			insid->next = runn->next;
			if (runn->next != NULL)
				runn->next->prev = insid;
			runn->prev = insid->prev;
			runn->next = insid;
			if (insid->prev != NULL)
				insid->prev->next = runn;
			else
				*deck = runn;
			insid->prev = runn;
			insid = runn->prev;
		}
	}
}

/**
 * sort_deck - sorts a deck
 * @deck: doubly linked list to sort
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	list_deck(deck);
	swap_n(deck);
}
