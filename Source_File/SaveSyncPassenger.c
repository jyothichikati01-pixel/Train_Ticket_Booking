#include"myheaders.h"
void save(PASSENGER *head)
{
    FILE *fp;
    PASSENGER *ptr=head;

    if (ptr == NULL)
    {
        printf("List is empty\n");
        return;
    }
    fp = fopen("Passenger_info.txt", "w");
    if (fp == NULL)
    {
        perror("File open failed");
        return;
    }

    while (ptr)
    {
        fprintf(fp,"%s %d %s %d %c %d %d %d %d\n",
		ptr->train_num,
                ptr->seat_no,
                ptr->name,
                ptr->age,
                ptr->gender,
		ptr->status,
		ptr->doj.day,
		ptr->doj.month,
		ptr->doj.year);

        ptr = ptr->link;   // move to next node
    }

    fclose(fp);
}
PASSENGER * SyncPassengers(PASSENGER *head)
{
        PASSENGER *nu=NULL,*temp=NULL;
        FILE *fp;
        fp=fopen("Passenger_info.txt","r");
        if(fp==NULL)
        {
                return head;
        }
	while(1)
	{
		nu=calloc(1,sizeof(PASSENGER));
		if(nu==NULL)
			return head;
		if(fscanf(fp,"%s %d %s %d %c %d %d %d %d",nu->train_num,&nu->seat_no,nu->name,&nu->age,&nu->gender,&nu->status,&nu->doj.day,&nu->doj.month,&nu->doj.year)!=9)
		{
			free(nu);
			break;
		}
		nu->link=NULL;
		if(head==NULL)
		{
			head=nu;
		}
		else
		{
			for(temp=head;temp->link;temp=temp->link);
			temp->link=nu;
		}
	}
        fclose(fp);
        return head;
}
