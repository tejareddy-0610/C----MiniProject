#include "phonebook.h"
void create_contact(CONTACT **head)
{
        CONTACT *newnode;
        CONTACT *temp;
        char choice;
        newnode=(CONTACT *)malloc(sizeof(CONTACT));
        if(newnode==NULL)
        {
                printf("memory allocation failed\n");
                return ;
        }
        newnode->phone_count=0;
        newnode->next=NULL;
        printf("Enter name:\n");
        scanf(" %[^\n]s",newnode->name);
        temp=*head;
        while(temp!=NULL)
        {
                if(strcmp(temp->name,newnode->name)==0)
                {
                        printf("Contact name already exists\n");
                        free(newnode);
                        return ;
                }
                temp=temp->next;
        }

        printf("Enter the phonenumber:\n");
        //scanf(" %[^\n]s",newnode->phone[0]);
        scanf(" %10[^\n]", newnode->phone[0]);
        while(getchar() != '\n');   /* discard extra characters */
        newnode->phone_count=1;
        while(newnode->phone_count<=MAX_NUMBERS)
        {
                printf("Do you want to add another number to the same name (Y/N): ");
                scanf(" %c", &choice);
                if(choice == 'Y' || choice == 'y')
                {
                        printf("Enter phone number %d: ",newnode->phone_count + 1); 
					scanf(" %[^\n]s",newnode->phone[newnode->phone_count]);
                        newnode->phone_count++;
                }
                else if (choice == 'N' || choice == 'n')
                {
                        break;
                }
                else
                {
                        printf("Invalid choice\n");
                }
        }
        strcpy(newnode->email, "Not Available");
        printf("Do you want to add email (Y/N): ");
        scanf(" %c", &choice);
        if (choice == 'Y' || choice == 'y')
        {
                printf("Enter email: ");
                scanf(" %[^\n]s", newnode->email);
        }

        strcpy(newnode->address, "Not Available");
        printf("Do you want to add address (Y/N): ");
        scanf(" %c", &choice);
        if(choice == 'Y' || choice == 'y')
        {
                printf("Enter address: ");
                scanf(" %[^\n]s", newnode->address);
        }

        if (*head == NULL)
        {
                *head = newnode;
        }
        else
        {
                temp = *head;
                while(temp->next != NULL)
                {
                        temp = temp->next;
					temp->next = newnode;
        }
        printf("Contact created successfully\n");
}
