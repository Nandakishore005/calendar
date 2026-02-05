#include <stdio.h>
#include <stdlib.h>

int get_first_weekDay(int year)
{
    int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;
}

int main()
{
    int year, day, dayInMonth, weekDay = 0, startingDay, month;

    printf("Enter your desired year: ");
    scanf("%d", &year);

    char *months[] = {
        "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
        "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"
    };

    int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        monthDays[1] = 29;

    startingDay = get_first_weekDay(year);

    for (month = 0; month < 12; month++)
    {
        dayInMonth = monthDays[month];

        printf("\n\n------------ %s ------------\n", months[month]);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        for (weekDay = 0; weekDay < startingDay; weekDay++)
            printf("    ");

        for (day = 1; day <= dayInMonth; day++)
        {
            printf("%4d", day);

            if (++weekDay > 6)
            {
                printf("\n");
                weekDay = 0;
            }
        }
        startingDay = weekDay;
    }
    return 0;
}