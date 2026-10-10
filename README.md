
TRAIN TICKET BOOKING APP
========================

1. PROJECT DESCRIPTION

This project is a Train Ticket Booking Application developed using C.
It uses structures, singly linked lists, file handling, and functions.

Main features:
- User sign-up and sign-in
- Password validation
- Add and display train information
- Reserve train tickets
- View booking details
- Cancel tickets
- Save information permanently in files
- Special user ID for adding trains

2. FILES USED

main.c       - Main program
main.h       - Structures and function declarations
user.c       - Sign-up and sign-in
train.c      - Train information management
booking.c    - Reservation, cancellation, and booking details
menu.c       - Application menus
utility.c    - Utility functions
Makefile     - Compiles the project

3. DATA FILES

data/usr_logins.txt
data/trains_info.txt
data/passengers_info.txt

These files store login, train, and passenger information.

4. COMPILATION

Open a terminal in the project directory.

Run:

make

5. EXECUTION

On Linux:

./a.out

On Windows, if compiled with MinGW:

a.exe

6. SPECIAL USER LOGIN

Username: railway
Password: Railway@123

The special user can add train information.

7. NORMAL USER

Create an account using Sign-up.
Then sign in to reserve tickets, view booking details,
and cancel tickets.

8.USER CAN

1.View train information
2.Reserve ticket
3.Cancel ticket
4.View own booking details
5.Logout

9.PASSWORD RULES

Minimum 8 charecters
one uppercase letter
one lowercase letter
one special charecter
one number

10.BOOKING DATE RULE

Only three dates from the present date are allowed:-
Today
Tomorrow
Day after tomorrow


11. IMPORTANT

Run the program from the project directory so that the
relative data file paths work correctly.

Do not delete the data files if you want to preserve
previously saved information.

12. CLEANING THE BUILD

Run:

make clean

This removes the compiled executable. It does not delete
the saved data files.

