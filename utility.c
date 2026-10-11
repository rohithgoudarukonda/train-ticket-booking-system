#include "main.h"
#include "time.h"

int days_in_month(int month, int year)
{
    if (month == 2)
    {
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            return 29;

        return 28;
    }

    if (month == 4 || month == 6 ||
        month == 9 || month == 11)
        return 30;

    return 31;
}



int valid_date(char current_date[], char booking_date[])
{
    int current_day, current_month, current_year;
    int booking_day, booking_month, booking_year;

    int current_value;
    int booking_value;

    sscanf(current_date, "%d-%d-%d",
           &current_day, &current_month, &current_year);

    sscanf(booking_date, "%d-%d-%d",
           &booking_day, &booking_month, &booking_year);

    current_value = current_year * 10000
                  + current_month * 100
                  + current_day;

    booking_value = booking_year * 10000
                  + booking_month * 100
                  + booking_day;

    if (booking_value < current_value)
    {
        return 0;
    }

    if (booking_year == current_year &&
        booking_month == current_month)
    {
        if (booking_day <= current_day + 3)
            return 1;
    }

    if (booking_year == current_year &&
        booking_month == current_month + 1)
    {
        if (current_month == 12)
            return 0;

        if (booking_day <= 3 - (days_in_month(current_month, current_year) - current_day))
            return 1;
    }

    return 0;
}


