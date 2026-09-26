#include"myheaders.h"
int main()
{
        char ch,choice;
	int ret;
        printf("enter the choice for 1.SignUp 2.SignIn\n");
sign:   scanf(" %c",&ch);
        if(ch=='1')
        {
                if(signUp())
                        printf("successfully sign up done\n");
                else
                {
                        printf("failed to signup\n");
                        return 0;
                }
        }
        else if(ch=='2')
        {
		ret=signIn();
                if(ret<0)
                {
                        printf("successfully log in the admin\n");
                        AdminMenu();
                        return 0;
                }
                else if(ret)
                {
                        printf("successfuly log in\n");
                }
                else
                {
                        printf("failed to log in\n");
                        return 0;
                }
        }
        else
        {
                printf("enter valid choice\n");
                goto sign;
        }
        printTrainInfo();
	while(1)
	{
choice: printf("enter your choice R/r:Reserve C/c:Cancel B/b:Booking details Q/q:quit\n");
        scanf(" %c",&choice);
        switch(choice)
        {
                case 'R':
                case 'r':ReserveTickets();
                         break;
                case 'C':
                case 'c':CancelTicket();
                         break;
                case 'B':
                case 'b':BookingDetails();
                         break;
                case 'Q':
                case 'q':exit(0);
                default:printf("enter valid choice\n");
                        goto choice;
        }
	}
}
