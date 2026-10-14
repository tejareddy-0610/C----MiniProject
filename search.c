#include "phonebook.h"
#include <ctype.h>

/* returns 1 if key is found anywhere inside text (ignores upper/lower case) */
static int contains_ignore_case(const char *text, const char *key)
{
	int i, j;
	for(i = 0; text[i] != '\0'; i++)
	{
		for(j = 0; key[j] != '\0' && text[i + j] != '\0'; j++)
		{
			if(tolower((unsigned char)text[i + j]) != tolower((unsigned char)key[j]))
			{
				break;
			}
		}
		if(key[j] == '\0')
		{
			return 1;
		}
	}
	return 0;
}

/* returns 1 if the name or any phone number of the contact contains key */
static int is_match(CONTACT *c, const char *key)
{
	int i;
	if(contains_ignore_case(c->name, key))
	{
		return 1;
	}
	for(i = 0; i < c->phone_count; i++)
	{
		if(contains_ignore_case(c->phone[i], key))
		{
			return 1;
		}
	}
	return 0;
}

void search_contact(CONTACT *head)
{
	CONTACT *temp;
	char key[MAX_NAME];
	int found = 0;
	int i;

	if(head == NULL)
	{
		printf("phonebook is empty\n");
		return;
	}

	printf("enter name, letters or phone number to search\n");
	scanf(" %49[^\n]", key);

	temp = head;
	while(temp != NULL)
	{
		if(is_match(temp, key))
		{
			found++;
			printf("name:%s\n", temp->name);
			for(i = 0; i < temp->phone_count; i++)
			{
				printf("phone number[%d] :%s\n", i + 1, temp->phone[i]);
			}
			printf("email:%s\n", temp->email);
			printf("address:%s\n\n", temp->address);
		}
		temp = temp->next;
	}

	if(found == 0)
	{
		printf("no contact found\n");
	}
	else
	{
		printf("%d contact(s) found\n", found);
	}
}
