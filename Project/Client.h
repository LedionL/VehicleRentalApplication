#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

void GetNewClient(struct Client **ClientHead, struct reservations *ReservationsHead)
{
    struct Client *newclient, *Ccurr = NULL;
    newclient = (struct Client*)malloc(sizeof(struct Client));
    printf("Enter the client info:\n");
     printf("Enter the ID of the client: ");
   scanf("%d",&newclient->clientID);
    printf("Enter the client's name and surname: ");
    scanf("%s %s",newclient->name, newclient->surname);
    printf("Enter the client's phone number:");
    scanf("%d",&newclient->PhoneNumber);
    printf("Enter the client's passport ID: ");
    scanf("%s",newclient->PassportID);
    printf("Enter the client's state: ");
    scanf("%s",newclient->state);
    newclient->next=NULL;
  Ccurr=*ClientHead;
    if(*ClientHead==NULL)
    {
        *ClientHead=newclient;
    }
    else
    {
        newclient->next=Ccurr;
        *ClientHead=newclient;
    }
    printf("\nEntered\n");
    Clientcnt++;
}



void Showclientinfo(struct Client *ClientHead)
{
    printf("\n");
    if(ClientHead==NULL)
    {
        printf("No clients found.");
    }
    else
    {
        while(ClientHead!=NULL)
        {
            printf("%d %s %s 0%d %s %s\n",ClientHead->clientID,ClientHead->name,ClientHead->surname, ClientHead->PhoneNumber,ClientHead->PassportID, ClientHead->state);
            ClientHead=ClientHead->next;

        }
    }
}

void NewClientInfo(struct Client **ClientHead)
{
    FILE *CLlist=NULL;
    CLlist=fopen("ClientList.txt", "r");
    if(CLlist==NULL)
    {
        printf("List could not be opened.");
        return;
    }

    fscanf(CLlist,"%d", &Clientcnt);

    if(Clientcnt==0)
    {
        printf("No clients found.\n");
        return;
    }

    struct Client *NewClient, *prev;
    for(int i=0; i<Clientcnt; i++)
    {
        NewClient=(struct Client *)malloc(sizeof(struct Client));
        fscanf(CLlist,"%d %s %s 0%d %s %s", NewClient->clientID, NewClient->name, NewClient->surname, NewClient->PhoneNumber, NewClient->PassportID, NewClient->state);
        NewClient->next=NULL;

        if(i==0)
        {
            *ClientHead=NewClient;
        }
        else
        {
            prev->next=NewClient;
        }

        printf("\nClient added");
        prev=NewClient;
        Clientcnt++;

    }

    printf("\nAll clients have been added successfully");
    fclose(CLlist);
}

void UpdateClientInfo(struct Client *ClientHead)
{
    FILE *CLlist1=NULL;
    CLlist1=fopen("ClientList.txt", "w");

    fprintf(CLlist1,"%d\n", Clientcnt);

        while(ClientHead!=NULL)
        {
            fprintf(CLlist1,"%d %s %s %d %s %s",ClientHead->clientID, ClientHead->name, ClientHead->surname, ClientHead->PhoneNumber, ClientHead->PassportID, ClientHead->state);
            ClientHead=ClientHead->next;
        }
        printf("Node added successfully");
    fclose(CLlist1);
}

#endif // CLIENT_H_INCLUDED
