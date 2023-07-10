#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int Counter=0, cnt=0, Clientcnt = 0, Reservationscnt = 0, VehicleCnt=0;
#include "structures.h"
#include "Vehicle.h"
#include "VehicleAvailability.h"
#include "Reservations.h"
#include "Client.h"


int main()
{
    system("Color 3F");
    struct vehicle *head=NULL;
    struct Client *ClientHead=NULL;
    struct reservations *ReservationsHead=NULL;
    int select;
    printf("Vehicle Rental Application.\n");
    printf("By : Ledion Lamce.\n");
    AddNewVehicletoFile(&head);
    GetReservationsDataFromFile(&ReservationsHead);
    ReservationsCheck(ReservationsHead);
    printf("\n");
    while(1){
        printf("-------------------------MENU-------------------------\n");
    printf("Please select which one of the following you want to perform:\n");
    printf("\n");
        printf("1.)Add new car.\n\
2.)Show vehicles.\n\
3.)Store vehicles in file.\n\
4.)Search a vehicle.\n\
5.)Delete a vehicle.\n\
6.)Sort using daily price.\n\
7.)Store available vehicles in file.\n\
8.)Modify information of a present car.\n\
9.)Add a Reservations.\n\
10.)Show all Reservations.\n\
11.)Cancel a reservations\n\
12.)Store Reservations to File:\n\
13.)Show reservations over a specific price point.\n\
14.)Add new client.\n\
15.)Show registered Clients.\n\
16.)Store Clients in file.\n\
17.)Take Client data from file.\n\
18.)Show vehicles which are avalible\n\
19.)Show vehicles which are free after a specific number of days\n\
20.)Delete vehicles which are reserved.\n\
0.)Stop.\n");
        printf("Your choice: ");
        scanf("%d",&select);
        if(select==1)
        {
            AddNewVehicle(&head);
        }
        else if(select==2)
        {
            ShowVehicles(head);
        }
        else if(select==3)
        {
            UpdateFile(head);
        }
        else if(select==4)
        {
            SearchVehicle(head);
        }
        else if(select==5)
        {
            RemoveCertainVehicle(&head);
        }
        else if(select==6)
        {
            SortByPrice(&head);
        }
        else if(select==7)
        {
            UpdateFileWAvailableVehicles(head);
        }
        else if(select==8)
        {
            ModifyVehicle(head);
        }
        else if(select==9)
        {
            AddNewReservation(&ReservationsHead,head,&ClientHead);
        }
        else if(select==10)
        {
            DisplayReservations(ReservationsHead);
        }
        else if(select==11)
        {
            RemoveReservedVehicle(&head, ReservationsHead);
        }
        else if(select==12)
        {
            UpdateReservationFile(ReservationsHead);
        }
        else if(select==13)
        {
            ResWithPriceAboveX(ReservationsHead);
        }
        else if(select==14)
        {
            GetNewClient(&ClientHead, ReservationsHead);
        }
        else if(select==15)
        {
            Showclientinfo(ClientHead);
        }
        else if (select==16)
        {
            UpdateClientInfo(ClientHead);
        }
        else if(select==17)
        {
            NewClientInfo(&ClientHead);
        }
        else if(select==18)
        {
            ShowVehiclesAvailable(head);
        }
        else if(select==19)
        {
            VehicleAvailability(ReservationsHead);
        }
        else if(select==20)
        {
            RemoveReservations(&ReservationsHead);
        }
        else if(select==0)
        {
            printf("Thank you for choosing our service.");
            return 0;
        }
        else
            printf("Invalid input:\n");

    }
}
