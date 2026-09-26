#include"myheaders.h"
void saveTrain(TRAIN *ptr)
{
    FILE *fp;

    if (ptr == NULL)
    {
        printf("List is empty\n");
        return;
    }

    fp = fopen("train_info", "w");   // text file
    if (fp == NULL)
    {
        perror("File open failed");
        return;
    }
   while (ptr)
    {
    	fprintf(fp,
                "%s %s %s %s %d %d %d %d\n",
                ptr->train_num,
                ptr->train_name,
                ptr->source,
                ptr->destination,
                ptr->seat.total_seats,
		ptr->seat.available_seats,
		ptr->seat.waiting_list,
		ptr->seat.current_booking_seat_number);
		//ptr->seat.waiting_list,ptr->seat.current_booking_seat_number);

        ptr = ptr->link;
    }
    /*do
    {
	    if(fprintf(fp,"%9s %9s %9s %9s %5d\n",ptr->train_num,ptr->train_name,ptr->source,ptr->destination,ptr->seat.total_seats)!=5)
		    break;
    }while(ptr=ptr->link);*/

    fclose(fp);
}
TRAIN *SyncTrainInfo(TRAIN * head)
{
        TRAIN *nu=NULL,*temp=NULL;
        FILE *fp,*fpp;
	int found=0;
        fp=fopen("train_info","r");
        if(fp==NULL)
        {
                return NULL;
        }
	fpp=fopen("Passenger_info.txt","r");
	if(fpp==NULL)
	{
		found=1;
	}
	while(1)
	{
		nu=calloc(1,sizeof(TRAIN));
		if(nu==NULL)
		{
			printf("train node not created\n");
			return head;
		}
		if(fscanf(fp,"%s %s %s %s %d %d %d %d",nu->train_num,nu->train_name,nu->source,nu->destination,&nu->seat.total_seats,&nu->seat.available_seats,&nu->seat.waiting_list,&nu->seat.current_booking_seat_number)!=8)
		{
			free(nu);
			break;
		}
		if(found)
		{
			nu->seat.current_booking_seat_number=0;
			nu->seat.waiting_list=0;
			nu->seat.available_seats=nu->seat.total_seats;
		}
		nu->link=NULL;
		if(head==NULL)
		{
			head=nu;
		}
        /*while(fread(&var,sizeof (TRAIN),1,fp)==1)
        {
                nu=calloc(1,sizeof(TRAIN));
                if(nu==NULL)
                {
                        printf("Node not createed\n");
                        return head;
                }
                nu->seat.total_seats=var.seat.total_seats;
                strcpy(nu->train_name,var.train_name);
                strcpy(nu->train_num,var.train_num);
                strcpy(nu->source,var.source);
                strcpy(nu->destination,var.destination);
                if(head==NULL)
                {
                        head=nu;
                }*/
	       	else
                {
                for(temp=head;temp->link;temp=temp->link);
                temp->link=nu;
                }
        }
	if(fpp)
	fclose(fpp);
        fclose(fp);
        return head;
}
