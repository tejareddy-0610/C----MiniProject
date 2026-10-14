#include "phonebook.h"
int main()
{
	CONTACT *head=NULL;
	char choice;
	load_contacts(&head);
	while(1)
	{
		printf("c/C:create p/P:display d/D:delete f/F:find e/E:edit o/O:sort s/S:save q/Q:quit\n");
		printf("enter the choice\n");
		scanf(" %c",&choice);
		switch(choice)
		{
			case 'c':
		 	case 'C':
				create_contact(&head);
				break;

			case 'p':
			case 'P':
				display_contact(head);
				break;

			case 'd':
			case 'D':
				delete_contact(&head);
				break;

			case 'f':
            		case 'F':
                		search_contact(head);
                		break;

            		case 'e':
            		case 'E':
                		edit_contact(head);
                		break;

            		case 'o':
            		case 'O':
                		sort_contacts(&head);
                		break;

            		case 's':
            		case 'S':
                		save_contacts(head);
                		break;

            		case 'q':
            		case 'Q':
                		save_contacts(head);
                		printf("Contacts saved automatically\n");
                		free_contacts(&head);
                		printf("Exiting Phone Book...\n");
                		exit(0);
				//break;

            		default:
                		printf("Invalid choice!\n");
        	}
    	}
}
