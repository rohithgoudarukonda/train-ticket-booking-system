# Train Ticket Booking System in C

## 1. Project Overview

The **Train Ticket Booking System** is a menu-driven application developed using the C programming language. It allows users to manage train information and perform basic railway ticket booking operations.

This project demonstrates the practical use of structures, singly linked lists, functions, and file handling in C.

## 2. Features

- User sign-up and sign-in
- Password validation
- Add train information using a special user account
- Display train information
- Reserve train tickets
- View booking details
- Cancel ticket reservations
- Store user, train, and passenger information in files
- Support for booking dates based on the application's date rules
- Menu-driven interface for easy navigation

## 3. Technologies Used

- **Programming Language:** C
- **Compiler:** GCC
- **Data Structures:** Structures and singly linked lists
- **Data Storage:** File handling
- **Build Tool:** Makefile
- **Operating System:** Linux

## 4. Project Structure

| File or Directory | Description |
|---|---|
| `main.c` | Main program entry point |
| `main.h` | Structure definitions and function declarations |
| `user.c` | User sign-up and sign-in operations |
| `train.c` | Train information management |
| `booking.c` | Ticket reservation, cancellation, and booking details |
| `menu.c` | Application menus |
| `utility.c` | Utility functions |
| `Makefile` | Instructions for compiling the project |
| `data/` | Directory for application data files |

## 5. Data Files

The application uses the following files to store information:

- `data/usr_logins.txt` — Stores user login information
- `data/trains_info.txt` — Stores train information
- `data/passengers_info.txt` — Stores passenger and booking information

These files support persistent storage so that application information can be retained between program executions.

Ensure the required data directory and files are available before running the application, if they are not created automatically by the program.

## 6. Compilation

Make sure GCC and Make are installed on your system.

Open a terminal in the project directory and run:

" make "

This compiles the source files and creates the executable `a.out`.

To remove the compiled object files and executable, run:


" make clean "

## 7. Execution

After successful compilation, start the application using:

" ./a.out "

Run the program from the project directory so that the relative paths used for the data files work correctly.

## 8. Special User Login (For Evaluation)

The following demo credentials are provided for the evaluator to access the special user functionality.

- **User ID:** `railway`
- **Password:** `Railway@123`

The special user account is intended for managing train information, including adding trains.

**Note:** These credentials are provided for academic project evaluation and testing.

## 9. Normal User Operations

A normal user can:

1. Create an account using the sign-up option.
2. Sign in with the registered credentials.
3. View train information.
4. Reserve train tickets.
5. View their own booking details.
6. Cancel tickets.
7. Log out of the application.

## 10. Password Validation Rules

The application enforces the following password requirements:

- Minimum 8 characters
- At least one uppercase letter
- At least one lowercase letter
- At least one number
- At least one special character

## 11. Booking Date Rules

The application allows ticket bookings for the following dates, according to its implemented rules:

- Today
- Tomorrow
- The day after tomorrow

## 12. Important Notes

- Run the application from the project directory.
- Ensure the required data files are available before using the application.
- Avoid deleting existing data files if you want to preserve saved information.
- Use the special user credentials above when evaluating the train-management functionality.
- Use demo data for testing and avoid entering real personal information.

## 13. Learning Outcomes

This project provides practical experience in:

- C programming and modular program design
- Structures and singly linked lists
- File handling and persistent data storage
- User authentication and password validation
- Menu-driven application development
- Compilation using GCC and Makefile

## 14. Conclusion

The Train Ticket Booking System demonstrates how fundamental C programming concepts can be combined to develop a menu-driven application for train information management and ticket reservations.

The project serves as an academic demonstration of data structures, file handling, and modular programming in C.

---

**Project Name:** Train Ticket Booking System  
**Programming Language:** C  
**Compiler:** GCC  
**Build Tool:** Makefile
