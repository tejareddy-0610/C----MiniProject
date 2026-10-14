#include "phonebook.h"
void edit_contact(CONTACT *head)
{
	CONTACT *temp;
    	CONTACT *check;
    	char old_name[MAX_NAME];
    	char new_name[MAX_NAME];
    	char choice;
    	int i;
    	int new_count;

    	if(head == NULL)
    	{
        	printf("Phone book is empty");
        	return;
    	}

	printf("enter the name to edit\n");
        scanf(" %[^\n]s",old_name);
        temp=head;
        while(temp!=NULL)
        {
                if(strcmp(temp->name,old_name)==0)
                {
                        printf("do you want to edit the name [y/n]\n");
                        scanf(" %c",&choice);
                        if(choice=='Y'||choice=='y')
                        {
                                printf("enter the new name\n");
                                scanf(" %[^\n]s",new_name);
                                check=head;
                                while(check!=NULL)
                                {
                                        if(check!=temp && strcmp(check->name,new_name)==0)
                                        {
                                                printf("contact already exists\n");
                                                break;
                                        }
                                        check=check->next;
                                }
                                if(check==NULL)
                                {
                                        strcpy(temp->name,new_name);
                                }
                        }

                        printf("do you want to edit phone number [y/n]\n");
                        scanf(" %c",&choice);
                        if(choice=='Y'||choice=='y')
                        {
				printf("how many numbers\n");
				scanf("%d",&new_count);
				if(new_count>=1 && new_count<=MAX_NUMBERS)
                		{
					temp->phone_count=new_count;
					for(i=0;i< temp->phone_count;i++)
					{
						printf("enter the number %d:",i+1);
						scanf(" %[^\n]s",temp->phone[i]);
					}
				}
				else
				{
					printf("invalid no of phone numbers\n");
				}
			}

			printf("Do you want to edit email[y/n]\n");
            		scanf(" %c", &choice);

            		if(choice == 'Y' || choice == 'y')
            		{
                		printf("Enter new email: ");
                		scanf(" %[^\n]s", temp->email);
            		}

            		printf("Do you want to edit address[y/n]\n");
            		scanf(" %c", &choice);

            		if (choice == 'Y' || choice == 'y')
            		{
                		printf("Enter new address: ");
                		scanf(" %[^\n]s", temp->address);
            		}

            		printf("Contact updated successfully\n");
            		return;
        	}

        temp = temp->next;
    }
}












