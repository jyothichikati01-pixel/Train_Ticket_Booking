#include "myheaders.h"
#define CONFIRMED 1
#define WAITING 0
#define CANCELLED -1

void BookingDetails()
{
    PASSENGER *headp = NULL,*tempp=NULL;
    TRAIN *headt=NULL,*tempt=NULL;
    int found=0;
   // char current_train[20]="";

    headp = SyncPassengers(headp);
    headt=SyncTrainInfo(headt);

    if (headp == NULL||headt==NULL)
    {
        printf("No bookings found\n");
        return;
    }

    printf("\n------ BOOKING DETAILS ------\n");
    for (tempt = headt; tempt; tempt = tempt->link)
    {
        found = 0;

        /* Check if this train has any passenger */
        for (tempp = headp; tempp; tempp = tempp->link)
        {
            if (strcmp(tempp->train_num, tempt->train_num) == 0 &&
                tempp->status != -1)
            {
                found = 1;
                break;
            }
        }

        if (!found)
            continue;   // no bookings for this train

        printf("\nTrain Number: %s\n", tempt->train_num);
        printf("-----------------------------------\n");
        printf("SeatNo   Name    Age  Gender     Date      Status\n");

        /* Print all passengers of this train */
        for (tempp = headp; tempp; tempp = tempp->link)
        {
            if (strcmp(tempp->train_num, tempt->train_num) == 0)
            {
                if (tempp->status == 1)
                {
                    printf("%-6d %-10s %-4d %-2c       %02d-%02d-%02d     CONFIRMED\n",
                           tempp->seat_no, tempp->name, tempp->age, tempp->gender,tempp->doj.day,tempp->doj.month,tempp->doj.year);
                }
                else if (tempp->status == 0)
                {
                    printf("WL     %-10s %-4d %-2c       %02d-%02d-%02d     WAITING\n",
                           tempp->name, tempp->age, tempp->gender,tempp->doj.day,tempp->doj.month,tempp->doj.year);
                }
                /*else if (tempp->status == -1)
                {
                    printf("CL     %-10s %-4d %-7c CANCELLED\n",
                           tempp->name, tempp->age, tempp->gender);
                }*/
            }
        }
    }
}
