#include "phonebook.h"
void display_contact(CONTACT *head)
{
        CONTACT *temp;
        int i;
        if(head==NULL)
        {
                printf("phonebook is empty\n");
                return ;
        }
        temp=head;
        int cnt=1;
        while(temp!=NULL)
        {
                printf("\n===============");
                printf("CONTACT %d",cnt++);
                printf("===============\n");
                printf("Name: %s\n",temp->name);
                for(i=0;i<temp->phone_count;i++)
                {
                        printf("phone number[%d] : %s\n",i+1,temp->phone[i]);
                }
                printf("Email: %s\n",temp->email);
                printf("Address: %s\n",temp->address);
                temp=temp->next;
        }
         printf("\n=============== ->THE END<-  ===============\n\n");
}
