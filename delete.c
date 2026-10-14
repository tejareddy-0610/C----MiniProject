#include "phonebook.h"
void delete_contact(CONTACT **head)
{
        CONTACT *temp;
        CONTACT *prev;
        char name[MAX_NAME];
        if(*head==NULL)
        {
                printf("phonebook is empty\n");
                return ;
        }
        printf("enter the name to be deleted\n");
        scanf(" %[^\n]s",name);
        temp=*head;
        prev=NULL;
        while(temp!=NULL)
        {
                if(strcmp(temp->name,name)==0)
                {
                        if(prev==NULL)
                        {
                                *head=temp->next;
                        }
                        else
                        {
                                prev->next=temp->next;
                        }
                        free(temp);
                        printf("Contact deleted successfully\n");
                        return ;
                }
                prev=temp;
                temp=temp->next;
        }
        printf("Contact not found\n");
}
