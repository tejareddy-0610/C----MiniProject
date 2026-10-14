#include "phonebook.h"

void load_contacts(CONTACT **head)
{
    CONTACT *temp;
    CONTACT *newnode;
    FILE *fp;
    int i;

    fp = fopen("phonebook.dat", "r");

    if(fp == NULL)
    {
        return;
    }

    while(1)
    {
        newnode = (CONTACT *)malloc(sizeof(CONTACT));

        if(newnode == NULL)
        {
            printf("memory allocation failed\n");
            fclose(fp);
            return;
        }
        if(fscanf(fp, "%*[^\n]\n") == EOF)
        {
            free(newnode);
            break;
        }
        if(fscanf(fp, "Name :%[^\n]\n", newnode->name) != 1)
        {
            free(newnode);
            break;
        }
        if(fscanf(fp, "Count :%d\n", &newnode->phone_count) != 1)
        {
            free(newnode);
            break;
        }

        for(i = 0; i < newnode->phone_count; i++)
        {
            if(fscanf(fp, "Phone number[%*d] :%[^\n]\n",newnode->phone[i]) != 1)
            {
                free(newnode);
                fclose(fp);
                return;
            }
        }
        if(fscanf(fp, "Email :%[^\n]\n",newnode->email) != 1)
        {
            free(newnode);
            break;
        }
        if(fscanf(fp, "Address :%[^\n]\n",newnode->address) != 1)
        {
            free(newnode);
            break;
        }

        newnode->next = NULL;
        if(*head == NULL)
        {
            *head = newnode;
        }
        else
        {
            temp = *head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    fclose(fp);
}
