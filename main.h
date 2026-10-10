typedef struct seats_info
{
    int total_seats;
    int waiting_list;
    int current_booking_seat_number;

} SeatsInfo;


typedef struct train_info
{
    int train_number;
    char train_name[50];
    char source[50];
    char destination[50];

    SeatsInfo seats;

    struct train_info *next;

} Train;


typedef struct passenger_info
{
    int train_number;
    char date[20];

    int seat_number;

    char name[50];
    int age;
    char gender[10];

    struct passenger_info *next;

} Passenger;


#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPECIAL_USER_ID "railway"

void menu1();
void menu2();
void special_menu(); 

void signup();
int user_exists(char username[]);
int valid_password(char password[]);
int signin(char username[]);

void reserve_ticket();
void cancel_ticket();
void booking_details();

void add_train();
void show_trains();
void save_trains();
void load_trains();
int train_exists(int train_number, char train_name[]);

void reserve_ticket();
int seat_is_booked(int train_number, char date[], int seat_number);
void save_passenger(Passenger *new_passenger);

void save_passenger(Passenger *new_passenger);
int get_next_seat(int train_number, char date[], int total_seats);
Train *find_train(int train_number);

int valid_date(char current_date[], char booking_date[]);
int days_in_month(int month, int year);
#endif

