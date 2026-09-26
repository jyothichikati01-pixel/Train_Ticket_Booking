
#include"myheaders.h"
void printTrainInfo()
{
        FILE *fp;
        TRAIN *head=NULL,*t=NULL;
	head=SyncTrainInfo(head);
	t=head;
 	if(t==NULL)
	{
		printf("train data not found\n");
		return;
	}
	printf("\n..................AVAILABLE TRAINS..................\n");
	printf("TrainNo    TrainName           Source      Destination    TotalSeats   Available   Waiting    \n");
	while(t)
        {
                printf("%-9s %-20s %-12s %-12s %5d %10d %6d\n",t->train_num,t->train_name,t->source,t->destination,t->seat.total_seats,t->seat.available_seats,t->seat.waiting_list);
		t=t->link;
        }
}
