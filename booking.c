#include "main.h"

void reserve_ticket()
{
    int train_number;
    char date[20];
    char current_date[20];
    int number_of_seats;
    int i;
    int booked_count = 0;
    int waiting_count = 0;

    Train *train;
    Passenger passenger;

    printf("\n----------- RESERVE TICKET -----------\n");

    printf("Enter train number: ");
    scanf("%d", &train_number);

    train = find_train(train_number);

    if (train == NULL)
    {
        printf("\nTrain not found!\n");
        return;
    } 

    printf("Enter current date (DD-MM-YYYY): ");
    scanf("%s", current_date);

    printf("Enter booking date (DD-MM-YYYY): ");
    scanf("%s", date);

    if (!valid_date(current_date, date))
     {
        printf("\nBooking is allowed only for 3 days!\n");
        return;
     }

    printf("Enter number of seats: ");
    scanf("%d", &number_of_seats);

    for (i = 1; i <= number_of_seats; i++)
    {
        passenger.seat_number = get_next_seat(train_number, date,train->seats.total_seats);

        if (passenger.seat_number == 0)
        {
           waiting_count++;
	   //printf("\nNo more seats available!\n");
            continue;
        }

        printf("\n----------- PASSENGER %d -----------\n", i);

        printf("Enter passenger name: ");
        scanf(" %[^\n]", passenger.name);

        printf("Enter age: ");
        scanf("%d", &passenger.age);

        printf("Enter gender: ");
        scanf("%s", passenger.gender);

        passenger.train_number = train_number;

        strcpy(passenger.date, date);

        passenger.next = NULL;

        save_passenger(&passenger);

	train->seats.current_booking_seat_number = passenger.seat_number;

        booked_count++;

        printf("\nTicket booked successfully!\n");
        printf("Seat Number : %d\n", passenger.seat_number);
    }

    train->seats.waiting_list = train->seats.waiting_list + waiting_count;
    save_trains();

    printf("\nRequested seats : %d\n", number_of_seats);
    printf("Booked seats    : %d\n", booked_count);
    printf("Waiting list    : %d\n", waiting_count);

    if (booked_count < number_of_seats)
    {
        printf("\nRequested seats : %d\n", number_of_seats);
        printf("Booked seats    : %d\n", booked_count);
        printf("Some seats were not available.\n");
    }
}

void save_passenger(Passenger *new_passenger)
{
    FILE *fp;

    fp = fopen("data/passengers_info.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening passenger file!\n");
        return;
    }

    fprintf(fp, "%d|%s|%d|%s|%d|%s\n",
            new_passenger->train_number,
            new_passenger->date,
            new_passenger->seat_number,
            new_passenger->name,
            new_passenger->age,
            new_passenger->gender);

    fclose(fp);
}

int seat_is_booked(int train_number, char date[], int seat_number)
{
    FILE *fp;

    int file_train_number;
    int file_seat_number;

    char file_date[20];
    char file_name[50];
    int file_age;
    char file_gender[10];

    fp = fopen("data/passengers_info.txt", "r");

    if (fp == NULL)
    {
        return 0;
    }

    while (fscanf(fp, "%d|%19[^|]|%d|%49[^|]|%d|%9[^\n]\n",
                  &file_train_number,
                  file_date,
                  &file_seat_number,
                  file_name,
                  &file_age,
                  file_gender) == 6)
    {
        if (file_train_number == train_number &&
            strcmp(file_date, date) == 0 &&
            file_seat_number == seat_number)
        {
            fclose(fp);

            return 1;
        }
    }

    fclose(fp);

    return 0;
}

int get_next_seat(int train_number, char date[], int total_seats)
{
    int seat;

    for (seat = 1; seat <= total_seats; seat++)
    {
        if (!seat_is_booked(train_number, date, seat))
        {
            return seat;
        }
    }

    return 0;
}


void booking_details()
{
    FILE *fp;

    int search_train;
    int train_number;
    int seat_number;
    int age;
    int found = 0;

    char search_date[20];
    char date[20];
    char name[50];
    char gender[10];

    printf("\nEnter train number: ");
    scanf("%d", &search_train);

    printf("Enter journey date (DD-MM-YYYY): ");
    scanf("%19s", search_date);

    fp = fopen("data/passengers_info.txt", "r");

    if (fp == NULL)
    {
        printf("No booking details found.\n");
        return;
    }

    printf("\n");
    printf("==========================================================================\n");
    printf("%-8s %-12s %-6s %-20s %-5s %-8s %-10s\n",
           "Train", "Date", "Seat", "Name", "Age", "Gender", "Status");
    printf("==========================================================================\n");

    while (fscanf(fp, "%d|%19[^|]|%d|%49[^|]|%d|%9[^\n]",
                  &train_number, date, &seat_number,
                  name, &age, gender) == 6)
    {
        if (train_number == search_train &&
            strcmp(date, search_date) == 0)
        {
            printf("%-8d %-12s %-6d %-20s %-5d %-8s %-10s\n",
                   train_number, date, seat_number,
                   name, age, gender, "BOOKED");

            found = 1;
        }
    }

    printf("==========================================================================\n");

    if (found == 0)
    {
        printf("No bookings found for this train and date.\n");
    }

    fclose(fp);
}


void cancel_ticket()
{
    int train_number;
    int seat_number;
    char date[20];

    FILE *fp;
    FILE *temp;

    int file_train_number;
    int file_seat_number;
    int file_age;

    char file_date[20];
    char file_name[50];
    char file_gender[10];

    int found = 0;

    printf("\n----------- CANCEL TICKET -----------\n");

    printf("Enter train number: ");
    scanf("%d", &train_number);

    printf("Enter date (DD-MM-YYYY): ");
    scanf("%s", date);

    printf("Enter seat number: ");
    scanf("%d", &seat_number);

    fp = fopen("data/passengers_info.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo booking file found!\n");
        return;
    }

    temp = fopen("data/temp.txt", "w");

    if (temp == NULL)
    {
        printf("\nError creating temporary file!\n");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "%d|%19[^|]|%d|%49[^|]|%d|%9[^\n]\n",
                  &file_train_number,
                  file_date,
                  &file_seat_number,
                  file_name,
                  &file_age,
                  file_gender) == 6)
    {
        if (file_train_number == train_number &&
            strcmp(file_date, date) == 0 &&
            file_seat_number == seat_number)
        {
            found = 1;
            continue;
        }

        fprintf(temp, "%d|%s|%d|%s|%d|%s\n",
                file_train_number,
                file_date,
                file_seat_number,
                file_name,
                file_age,
                file_gender);
    }

    fclose(fp);
    fclose(temp);

    remove("data/passengers_info.txt");
    rename("data/temp.txt", "data/passengers_info.txt");

    if (found == 1)
    {
        Train *train;

        train = find_train(train_number);

        if (train != NULL)
           {
               train->seats.current_booking_seat_number = seat_number;
           }

        save_trains();

        printf("\nTicket cancelled successfully!\n");
     }


    else
    {
        printf("\nNo booking found for this seat!\n");
    }
}
