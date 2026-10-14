#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME 50
#define MAX_PHONE 11
#define MAX_EMAIL 50
#define MAX_ADDRESS 100
#define MAX_NUMBERS 5

typedef struct contact
{
	char name[MAX_NAME];
	char phone[MAX_NUMBERS][MAX_PHONE];
	int phone_count;
	char email[MAX_EMAIL];
	char address[MAX_ADDRESS];
	struct contact *next;
} CONTACT;

void create_contact(CONTACT **head);
void display_contact(CONTACT *head);
void delete_contact(CONTACT **head);
void search_contact(CONTACT *head);
void edit_contact(CONTACT*head);
void sort_contacts(CONTACT **head);
void save_contacts(CONTACT *head);
void load_contacts(CONTACT **head);
void free_contacts(CONTACT **head);

#endif
