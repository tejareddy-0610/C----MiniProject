#include "phonebook.h"
#include <ctype.h>

/* compares two names ignoring upper/lower case: <0, 0 or >0 */
static int compare_names(const char *a, const char *b)
{
	while(*a != '\0' && *b != '\0')
	{
		int ca = tolower((unsigned char)*a);
		int cb = tolower((unsigned char)*b);
		if(ca != cb)
		{
			return ca - cb;
		}
		a++;
		b++;
	}
	return tolower((unsigned char)*a) - tolower((unsigned char)*b);
}

/* sorts the linked list by name (A to Z) by relinking the nodes */
void sort_contacts(CONTACT **head)
{
	CONTACT *sorted = NULL;
	CONTACT *current;
	CONTACT *next;
	CONTACT *pos;

	if(*head == NULL || (*head)->next == NULL)
	{
		printf("nothing to sort\n");
		return;
	}

	current = *head;
	while(current != NULL)
	{
		next = current->next;

		if(sorted == NULL || compare_names(current->name, sorted->name) < 0)
		{
			current->next = sorted;
			sorted = current;
		}
		else
		{
			pos = sorted;
			while(pos->next != NULL && compare_names(pos->next->name, current->name) <= 0)
			{
				pos = pos->next;
			}
			current->next = pos->next;
			pos->next = current;
		}
		current = next;
	}

	*head = sorted;
	printf("contacts sorted by name\n");
}
