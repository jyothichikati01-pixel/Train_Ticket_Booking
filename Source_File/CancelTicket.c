#include "myheaders.h"
#define CONFIRMED 1
#define CANCELLED -1
#define WAITING 0

void CancelTicket()
{
    PASSENGER *head = NULL, *temp = NULL;
    TRAIN *headt=NULL,*tempt=NULL;
    char train_num[20];
    int seat_no,found=0;
    DATE doj;

    head = SyncPassengers(head);
    headt=SyncTrainInfo(headt);
    if (head == NULL||headt==NULL)
    {
        printf("No bookings found\n");
        return;
    }
    printf("Enter train number:\n");
    scanf("%s",train_num);

    printf("enter journey date(DD-MM-YYYY)\n");
    scanf("%d %d %d",&doj.day,&doj.month,&doj.year);

    printf("Enter seat number to cancel: ");
    scanf("%d", &seat_no);

    /*search train*/
    tempt=headt;
    while(tempt)
    {
	    if(!strcmp(tempt->train_num,train_num))
		    break;
	    tempt=tempt->link;
    }
    if(!tempt)
    {
	    printf("Train not found\n");
	    return;
    }

    /*search passenger*/
    temp = head;
    while (temp)
    {
        if (!strcmp(temp->train_num,train_num)&&temp->seat_no == seat_no&&temp->status==CONFIRMED&&
            temp->doj.day == doj.day &&
            temp->doj.month == doj.month &&
            temp->doj.year == doj.year)
        {
		temp->status=CANCELLED;
		found=1;
		tempt->seat.available_seats++;
		break;
        }
        temp = temp->link;
    }
    if(!found)
    {
	    printf("Booking not found\n");
	    return ;
    }
    /*moving waiting list to confirmed*/
    temp=head;
    while(temp)
    {
	    if(!strcmp(temp->train_num,train_num)&&temp->status==WAITING&&
            temp->doj.day == doj.day &&
            temp->doj.month == doj.month &&
            temp->doj.year == doj.year)
	    {
		    temp->status=CONFIRMED;
		    temp->seat_no=seat_no;
		    printf("Waiting Passenger moved to confirmed with seat no:%d\n",seat_no);
		    tempt->seat.available_seats--;
		    tempt->seat.waiting_list--;
		    break;
	    }
	    temp=temp->link;
    }
    save(head);
    saveTrain(headt);

    printf("Ticket cancelled successfully\n");
    return;
}
