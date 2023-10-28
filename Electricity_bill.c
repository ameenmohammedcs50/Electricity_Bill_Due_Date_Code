// the program calculates the electricity bill based on the units consumed and then calculates the due date as requested by the user
#include <stdio.h>

void duedate(int day, int month, int year);
void calculatedate();

int main()
{
    char custname[100];
    int units;
    float billamt = 0.0;

    printf("\nEnter the name of the customer: ");
    scanf("%s", custname);
    printf("\nEnter the number of units consumed: ");
    scanf("%d", &units);

    if (units <= 200)
    {
        billamt = units * 0.8 + 100;
    }
    else if (units > 200 && units <= 300)
    {
        billamt = (200 * 0.8) + ((units - 200) * 0.9) + 100;
    }
    else
    {
        billamt = (200 * 0.8) + (100 * 0.9) + ((units - 300) * 1.0) + 100;
    }

    if (billamt > 400)
    {
        billamt = billamt + billamt * 0.15;
    }

    printf("\n===================================");
    printf("\nElectricity Bill");
    printf("\n===================================\n");
    printf("\nCustomer Name\t: %s", custname);
    printf("\nUnits Consumed\t: %d", units);
    printf("\nBill Amount\t: %0.2f Rupees\n\n", billamt);
    printf("\n===================================\n");

    calculatedate();

    return 0;
}

void calculatedate()
{
    int day = 0;
    int month = 0;
    int year = 0;

    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);

    if (month >= 1 && month <= 12)
    {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if (day >= 1 && day <= 31)
            {
                duedate(day, month, year);
            }
            else
            {
                printf("Invalid date.\n");
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day >= 1 && day <= 30)
            {
                duedate(day, month, year);
            }
            else
            {
                printf("Invalid date.\n");
            }
        }
        else if (month == 2)
        {
            if (year % 4 == 0)
            {
                if (year % 100 == 0)
                {
                    if (year % 400 == 0)
                    {
                        if (day >= 1 && day <= 29)
                        {
                            duedate(day, month, year);
                        }
                        else
                        {
                            printf("Invalid date.\n");
                        }
                    }
                    else
                    {
                        if (day >= 1 && day <= 28)
                        {
                            duedate(day, month, year);
                        }
                        else
                        {
                            printf("Invalid date.\n");
                        }
                    }
                }
                else
                {
                    if (day >= 1 && day <= 29)
                    {
                        duedate(day, month, year);
                    }
                    else
                    {
                        printf("Invalid date.\n");
                    }
                }
            }
            else
            {
                if (day >= 1 && day <= 28)
                {
                    duedate(day, month, year);
                }
                else
                {
                    printf("Invalid date.\n");
                }
            }
        }
    }
    else
    {
        printf("Invalid date.\n");
    }
}

void duedate(int day, int month, int year)
{
    int n = 0;
    printf("Enter number of days for due date: ");
    scanf("%d", &n);

    while (n > 0)
    {
        int days_in_month;
        if (month == 12)
        {
            days_in_month = 31;
        }
        else if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                days_in_month = 29; // Leap year
            }
            else
            {
                days_in_month = 28; // Non-leap year
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            days_in_month = 30;
        }
        else
        {
            days_in_month = 31;
        }

        if (day + n > days_in_month)
        {
            n -= (days_in_month - day + 1);
            day = 1;
            if (month == 12)
            {
                month = 1;
                year++;
            }
            else
            {
                month++;
            }
        }
        else
        {
            day += n;
            n = 0;
        }
    }

    printf("The due date is: %d-%d-%d\n", day, month, year);
}
