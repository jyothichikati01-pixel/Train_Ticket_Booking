a.out:AppTest.o SaveSyncTrain.o SaveSyncPassenger.o AddPassenger.o AddTrain.o AdminMenu.o ReserveTickets.o PrintTrain.o signTest.o CancelTicket.o BookingDetails.o
	cc AppTest.o SaveSyncTrain.o SaveSyncPassenger.o AddPassenger.o AddTrain.o AdminMenu.o ReserveTickets.o PrintTrain.o signTest.o CancelTicket.o BookingDetails.o
AppTest.o:AppTest.c
	cc -c AppTest.c
SaveSyncTrain.o:SaveSyncTrain.c
	cc -c SaveSyncTrain.c
SaveSyncPassenger.o:SaveSyncPassenger.c
	cc -c SaveSyncPassenger.c
AddPassenger.o:AddPassenger.c
	cc -c AddPassenger.c
AddTrain.o: AddTrain.c
	cc -c AddTrain.c
AdminMenu.o: AdminMenu.c
	cc -c AdminMenu.c
ReserveTickets.o:ReserveTickets.c
	cc -c ReserveTickets.c
PrintTrain.o: PrintTrain.c
	cc -c PrintTrain.c
signTest.o:signTest.c
	cc -c signTest.c
CancelTicket.o: CancelTicket.c
	cc -c  CancelTicket.c
BookingDetails.o:BookingDetails.c
	cc -c BookingDetails.c

