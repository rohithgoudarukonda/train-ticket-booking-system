#include "main.h"

void signup()
{
    char username[50];
    char password[50];

    FILE *fp;

    printf("\n----------- SIGN-UP -----------\n");

    printf("Enter username: ");
    scanf("%s", username);

    if(user_exists(username))
    {
	    printf("Username already exists!\n");
	    return;
    }

    printf("Enter password: ");
    scanf("%s", password);

    if (!valid_password(password))
    {
      printf("Invalid password!\n");
      printf("Password must contain:\n");
      printf("- Minimum 8 characters\n");
      printf("- At least one uppercase letter\n");
      printf("- At least one lowercase letter\n");
      printf("- At least one number\n");
      printf("- At least one special character\n");

      return;
    }

    fp = fopen("data/usr_logins.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);

    fclose(fp);

    printf("\nAccount created successfully!\n");
}
int user_exists(char username[])
{
    FILE *fp;

    char file_username[50];
    char file_password[50];

    fp = fopen("data/usr_logins.txt", "r");

    if (fp == NULL)
    {
        return 0;
    }

    while (fscanf(fp, "%s %s", file_username, file_password) == 2)
    {
        if (strcmp(username, file_username) == 0)
        {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);

    return 0;
}
int valid_password(char password[])
{
    int i = 0;
    int uppercase = 0;
    int lowercase = 0;
    int digit = 0;
    int special = 0;

    if (strlen(password) < 8)
    {
            printf("password must be 8 charecters!\n");
	    return 0;
    }

    while (password[i] != '\0')
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            uppercase = 1;
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            lowercase = 1;
        }
        else if (password[i] >= '0' && password[i] <= '9')
        {
            digit = 1;
        }
        else
        {
            special = 1;
        }

        i++;
    }

    if (uppercase && lowercase && digit && special)
    {
        return 1;
    }

    return 0;
}
int signin(char username[])
{
    FILE *fp;

    char password[50];

    char file_username[50];
    char file_password[50];
    
    int attempts =0;
    while(attempts<3)
    {
    printf("\n----------- SIGN-IN -----------\n");

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, SPECIAL_USER_ID) == 0 && strcmp(password, "Railway@123") == 0)
      {
        return 1;
      }

    fp = fopen("data/usr_logins.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening login file!\n");
        return 0;
    }

    while (fscanf(fp, "%s %s", file_username, file_password) == 2)
    {
        if (strcmp(username, file_username) == 0 &&
            strcmp(password, file_password) == 0)
        {
            fclose(fp);

            printf("\nLogin successful!\n");

            return 1;
        }
    }

    fclose(fp);

    attempts++;
    printf("\nInvalid username or password\n");
    printf("attempts remaining : %d\n",3-attempts);
    }

    printf("\nTIME OUT!\n");
    printf("\n Please wait 5 minutes and try again\n");

    return 0;
}
