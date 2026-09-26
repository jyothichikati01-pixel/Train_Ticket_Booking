#include"myheaders.h"
TRAIN * AddTrain(TRAIN *head)
{
        TRAIN *nu=NULL,*temp=NULL;
        //head=SyncTrainInfo(head);
        /** creation of node **/
        nu=calloc(1,sizeof(TRAIN));
        if(nu==NULL)
        {
                printf("node not created\n");
        }
        else
        {
                /*** node created successfully ***/
                /** initialise the node ***/

                printf("enter the train num\n");
                scanf("%s",nu->train_num);
                printf("enter the train name\n");
                scanf("%s",nu->train_name);
                printf("enter the source\n");
                scanf("%s",nu->source);
                printf("enter the destination\n");
                scanf("%s",nu->destination);
                printf("enter number of seats\n");
                scanf("%d",&nu->seat.total_seats);
		nu->seat.available_seats=nu->seat.total_seats;
		nu->seat.current_booking_seat_number=1;
		nu->seat.waiting_list=0;
		nu->link=NULL;

		/*duplicate train check*/
		temp=head;
		while(temp)
		{
			if(!strcmp(temp->train_num,nu->train_num)||!strcmp(temp->train_name,nu->train_name))
			{
				printf("duplicat train number or name not allowed\n");
				free(nu);
				return head;
			}
			temp=temp->link;
		}

                /**** linking to list ***/

                if(head==NULL)
                {/** list is empty so assign nu node as first node ***/
                        head=nu;
                }
                else
                {
                        /** list already created **/
                        /** so traverse up to last node , link newnode to last node **/

                        temp=head;
                        while(temp->link)
                        {
                                temp=temp->link; // moving to next node
                        }
                        /** linking newnode to last node **/
                        temp->link=nu;
                }

        }
        //saveTrain(head);
	printf("train added successfully\n");
        return head; // returning first node address
}
