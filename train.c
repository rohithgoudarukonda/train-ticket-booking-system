#include "main.h"
Train *head = NULL;

void add_train()
{
    Train *new_train;
    Train *temp;

    new_train = malloc(sizeof(Train));

    if (new_train == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\n----------- ADD TRAIN -----------\n");

    printf("Enter train number: ");
    scanf("%d", &new_train->train_number);

    printf("Enter train name: ");
    scanf(" %[^\n]", new_train->train_name);

    if (train_exists(new_train->train_number,
                 new_train->train_name))
    {
      printf("\nTrain already exists!\n");

      free(new_train);

      return;
    }

    printf("Enter source: ");
    scanf(" %[^\n]", new_train->source);

    printf("Enter destination: ");
    scanf(" %[^\n]", new_train->destination);

    printf("Enter total seats: ");
    scanf("%d", &new_train->seats.total_seats);

    new_train->seats.waiting_list = 0;
    new_train->seats.current_booking_seat_number = 1;

    new_train->next = NULL;

    if (head == NULL)
    {
        head = new_train;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_train;
    }

    printf("\nTrain added successfully!\n");
    save_trains();
}

void show_trains()
{
    Train *temp;

    if (head == NULL)
    {
        printf("\nNo trains available.\n");
        return;
    }

    temp = head;

    printf("\n----------- TRAIN LIST -----------\n");

    while (temp != NULL)
    {
        printf("\nTrain Number : %d\n", temp->train_number);
        printf("Train Name   : %s\n", temp->train_name);
        printf("Source       : %s\n", temp->source);
        printf("Destination  : %s\n", temp->destination);
        printf("Total Seats  : %d\n", temp->seats.total_seats);
        printf("Waiting list : %d\n", temp->seats.waiting_list);
        temp = temp->next;
    }
}

void save_trains()
{
    FILE *fp;
    Train *temp;

    fp = fopen("data/trains_info.txt", "w");

    if (fp == NULL)
    {
        printf("Error opening trains file!\n");
        return;
    }

    temp = head;

    while (temp != NULL)
    {
        fprintf(fp, "%d|%s|%s|%s|%d|%d|%d\n",
        temp->train_number,
        temp->train_name,
        temp->source,
        temp->destination,
        temp->seats.total_seats,
        temp->seats.waiting_list,
        temp->seats.current_booking_seat_number);
        temp = temp->next;
    }

    fclose(fp);

    printf("\nTrain information saved successfully!\n");
}

void load_trains()
{
    FILE *fp;
    Train *new_train;
    Train *temp;

    fp = fopen("data/trains_info.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    while (1)
    {
        new_train = malloc(sizeof(Train));

        if (new_train == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(fp);
            return;
        }
           if (fscanf(fp, "%d|%49[^|]|%49[^|]|%49[^|]|%d|%d|%d\n",
           &new_train->train_number,
           new_train->train_name,
           new_train->source,
           new_train->destination,
           &new_train->seats.total_seats,
           &new_train->seats.waiting_list,
           &new_train->seats.current_booking_seat_number) != 7)
       	{
            free(new_train);
            break;
        }

        new_train->next = NULL;

        if (head == NULL)
        {
            head = new_train;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = new_train;
        }
    }

    fclose(fp);
}

int train_exists(int train_number, char train_name[])
{
    Train *temp;

    temp = head;

    while (temp != NULL)
    {
        if (temp->train_number == train_number || strcmp(temp->train_name, train_name) == 0)
        {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

Train *find_train(int train_number)
{
    Train *temp;

    temp = head;

    while (temp != NULL)
    {
        if (temp->train_number == train_number)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}
