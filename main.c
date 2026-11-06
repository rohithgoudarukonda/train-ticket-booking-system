#include "main.h"

int main()
{
   load_trains();
   menu1();
    return 0;
}

void menu1()
{
    int choice;
    char username[50];

    while (1)
    {
        printf("\n");
        printf("------------------ MENU-1 ------------------\n");
        printf("1. Sign-up\n");
        printf("2. Sign-in\n");
        printf("3. Exit\n");
        printf("--------------------------------------------\n");

        printf("Enter your choice: ");
       if(scanf("%d", &choice)!=1)
	   {
		   printf("\nInvalid input enter numbers only.\n");
		   while(getchar()!='\n');
			   continue;
	   }

        switch (choice)
        {
            case 1:
                signup();
                break;

            case 2:
                   if (signin(username))
                   {
                    if(strcmp(username, SPECIAL_USER_ID) == 0)
                     {
                         special_menu();
                     }
                     else
                     {
                          menu2();
                     }
                   }
		   break;

            case 3:
                printf("Exiting program...\n");
                return;

            default:
                printf("Invalid choice\n");
        }
    }
}
