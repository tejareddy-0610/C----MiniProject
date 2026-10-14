#include "phonebook.h"
void save_contacts(CONTACT *head)
{
	CONTACT *temp;
	int count=1;
	FILE *fp;
	fp=fopen("phonebook.dat","wb");
	if(fp==NULL)
	{
		printf("file not found\n");
		return ;
	}
	temp=head;
	while(temp!=NULL)
	{
		fprintf(fp,"===============");
		fprintf(fp,"CONTACT %d",count);
		fprintf(fp,"===============\n");
		//fwrite(temp->name,sizeof(temp->name),1,fp);
		//fwrite(&temp->phone_count,sizeof(temp->phone_count),1,fp);
		//fwrite(temp->phone,sizeof(temp->phone),1,fp);
		//fwrite(temp->email,sizeof(temp->email),1,fp);
		//fwrite(temp->address,sizeof(temp->address),1,fp);
		fprintf(fp, "Name    :%s\n", temp->name);
        	fprintf(fp, "Count   :%d\n", temp->phone_count);
		for(int i = 0; i < temp->phone_count; i++)
        	{
            		fprintf(fp, "Phone number[%d] :%s\n",i+1, temp->phone[i]);
        	}
		fprintf(fp, "Email    :%s\n", temp->email);
        	fprintf(fp, "Address  :%s\n", temp->address);
		temp=temp->next;
		count++;
	}
	fclose(fp);
}
