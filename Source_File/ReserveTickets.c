#include"myheaders.h"
int isValidDate(DATE *ptr,int cd,int cm,int cy)
{
	if(ptr->year!=2026)
		return 0;
	if(ptr->month<1||ptr->month>12)
		return 0;
	if(ptr->day<1||ptr->day>30)
		return 0;
	int current_days=cy*360+cm*30+cd;
	int journey_days=ptr->year*360+ptr->month*30+ptr->day;
	int diff=journey_days-current_days;
	if(diff>=0&&diff<=3)
		return 1;
	return 0;
}

void ReserveTickets() 
{ 
	char train_num[20];
       	int req_cnt,book_cnt;
       	int found=0,valid=0,cd,cm,cy;

	PASSENGER *headp=NULL,*tempp=NULL,*nu=NULL; 
	TRAIN *headt=NULL,*tempt=NULL; 
	headt=SyncTrainInfo(headt); 
	if(headt==NULL) 
	{ 
		printf("trains data not synced\n");
	       	return ;
       	}
       	headp=SyncPassengers(headp); 
	printf("enter the current date to check\n");
        scanf("%d %d %d",&cd,&cm,&cy);
	printf("enter the train number to reserve tickets\n"); 
	scanf("%s",train_num);	
	printf("enter how many tickets you want to reserve\n"); 
	scanf("%d",&req_cnt); 
	tempt=headt;
       	while(tempt)
       	{
	       	if(!strcmp(train_num,tempt->train_num))
	       	{
		       	found=1;
		       	break;
	       	} 
		tempt=tempt->link; 
	}
       	if(found) 
	{
	       	printf("available seats are %d...\n",tempt->seat.available_seats);
	       	for(int i=0;i<req_cnt;i++) 
		{
		       	nu=calloc(1,sizeof(PASSENGER)); 
			if(nu==NULL) 
			{
			       	printf("node not created\n");
				break;
		       	}
		       	else
		       	{ /*** node created successfully ***/ /** initialise the node ***/ 
				printf("enter the name of the passenger\n");
			       	scanf("%s",nu->name); 
				printf("enter the age\n"); 
				scanf("%d",&nu->age);
			       	printf("enter the gender\n");
			       	scanf(" %c",&nu->gender);
				printf("enter date of journey(DD-MM-YYYY)\n");                              scanf("%d %d %d",&nu->doj.day,&nu->doj.month,&nu->doj.year);                
				valid=isValidDate(&nu->doj,cd,cm,cy);                                       if(!valid)
       				{
                		printf("Invalid date! Reservation allowed only within 3 days from today\n");
                		return;
        			}
			     
				nu->seat_no=tempt->seat.current_booking_seat_number;
				strcpy(nu->train_num,tempt->train_num);
				if(tempt->seat.available_seats>0)
				{
					tempt->seat.current_booking_seat_number++;
					tempt->seat.available_seats--;
					nu->seat_no=tempt->seat.current_booking_seat_number;
					nu->status=1;
				}
				else
				{
					//waiting list
					tempt->seat.waiting_list++;
					nu->seat_no=0;
					nu->status=0;
				}
			       	/**** linking to list ***/ 
				if(headp==NULL) 
				{
					/** list is empty so assign nu node as first node ***/
				       	headp=nu; 
				} 
				else
			       	{ 
					/** list already created **/ /** so traverse up to last node , link newnode to last node **/ 
					tempp=headp; 
					while(tempp->link)
				       	{
					       	tempp=tempp->link; // moving to next node 
					} /** linking newnode to last node **/ 
						tempp->link=nu; 
				} 
		       	}
	       	}
		save(headp);
		saveTrain(headt);
       	}
       	else
       	{
	       	//printf("variable=%s.....from file=%s\n",train_num,tempt->train_num);
	       	printf("train not found\n");
	       	return ;
       	}
       	return ;
}
