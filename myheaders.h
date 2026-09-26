#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
//#include<stdio_ext.h>
#include<ctype.h>

typedef struct user
{
        char name[20];
        char password[20];
}USER;
typedef struct seat
{
        int total_seats;
	int available_seats;
	int current_booking_seat_number;
	int waiting_list;
}SEAT;
typedef struct train
{
        char train_num[20],train_name[30],source[20],destination[20];
        SEAT seat;
        struct train *link;
}TRAIN;
typedef struct date
{
	int day;
	int month;
	int year;
}DATE;
typedef struct passenger
{
	char train_num[20];
        int seat_no;
        char name[20];
        int age;
        char gender;
        int status;
	DATE doj;
        struct passenger *link;
}PASSENGER;
int signUp();
int signIn();
void ReserveTickets();
void printTrainInfo();
void AdminMenu();
void save(PASSENGER *);
PASSENGER *AddPassenger(PASSENGER *);
TRAIN *AddTrain(TRAIN *);
TRAIN *SyncTrainInfo(TRAIN *);
PASSENGER *SyncPassengers(PASSENGER *);
void saveTrain(TRAIN *);
void CancelTicket(void);
void BookingDetails(void);
int isValidDate(DATE *,int,int,int);
