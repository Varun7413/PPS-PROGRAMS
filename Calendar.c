#include <stdio.h>

int main()
{
    int year, i, j;
    int days, day = 0;

    char *months[] = {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    int monthDays[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    printf("Enter year: ");
    scanf("%d", &year);

    // Check leap year
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
    {
        monthDays[1] = 29;
    }

    // Calculate first day of the year
    int y = year - 1;
    day = (y * 365 + y / 4 - y / 100 + y / 400 + 1) % 7;

    // Print calendar
    for (i = 0; i < 12; i++)
    {
        printf("\n\n     %s %d\n", months[i], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        days = monthDays[i];

        for (j = 0; j < day; j++)
        {
            printf("    ");
        }

        for (j = 1; j <= days; j++)
        {
            printf("%3d ", j);

            day++;

            if (day == 7)
            {
                printf("\n");
                day = 0;
            }
        }

        if (day != 0)
        {
            printf("\n");
        }
    }

    return 0;
}
