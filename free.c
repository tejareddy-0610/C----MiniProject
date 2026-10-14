#include "phonebook.h"
void free_contacts(CONTACT **head)
{
	CONTACT *temp;
	while(*head!=NULL)
	{
		temp=*head;
		*head=(*head)->next;
		free(temp);
	}
}
