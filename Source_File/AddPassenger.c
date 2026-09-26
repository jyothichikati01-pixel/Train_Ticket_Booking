#include"myheaders.h"
PASSENGER *AddPassenger(PASSENGER * head)
{
        PASSENGER *nu=NULL,*temp=NULL;
        /** creation of node **/
        nu=calloc(1,sizeof(PASSENGER));
        if(nu==NULL)
        {
                printf("node not created\n");
        }
        else
        {
                /*** node created successfully ***/
                /** initialise the node ***/

                printf("enter the name of the passenger\n");
                scanf("%s",nu->name);
                printf("enter the age\n");
                scanf("%d",&nu->age);
                printf("enter the gender\n");
                scanf("%c",&nu->gender);
                //nu->seat_no=rand()%50+1;

                /**** linking to list ***/

                if(head==NULL)
                {/** list is empty so assign nu node as first node ***/
                        head=nu;
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
        return head; // returning first node address
}

