#include"myheaders.h"
void AdminMenu()
{
        int choice;
        TRAIN *head=NULL;
        head=SyncTrainInfo(head);
	while(1)
	{
        printf("enter your choice 1.display trains 2.add train 3.quit\n");
        scanf("%d",&choice);
        switch(choice)
        {
                case 1:printTrainInfo();
                       break;
                case 2:head=AddTrain(head);
                       saveTrain(head);
                       break;
                case 3:exit(0);
		default:printf("invalid choice for admin menu\n");
        }
	}
}
