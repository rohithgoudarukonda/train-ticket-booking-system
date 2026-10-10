#include "main.h"

void menu2()
{
	show_trains();
    char choice;

    while (1)
    {
        printf("\n");
        printf("------------------ MENU-2 ------------------\n");
        printf("R/r - Reserve Ticket\n");
        printf("C/c - Cancel Ticket\n");
        printf("B/b - Booking Details\n");
        printf("Q/q - Quit\n");
        printf("--------------------------------------------\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'R':
            case 'r':
                reserve_ticket();
                break;

            case 'C':
            case 'c':
                cancel_ticket();
                break;

            case 'B':
            case 'b':
                booking_details();
                break;

            case 'Q':
            case 'q':
                printf("Returning to MENU-1...\n");
                return;

            default:
		printf("Invalid choice\n");
		break;

	}
    }
}

void special_menu()
{
    int choice;

    while (1)
    {
        printf("\n----------- SPECIAL USER MENU -----------\n");
        printf("1. Add Train\n");
        printf("2. Show Trains\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                add_train();
                break;

            case 2:
                show_trains();
                break;

            case 3:
                return;

            default:
                printf("\nInvalid choice!\n");
        }
    }
}
