#include <stdio.h>

// defining consts
#define BILLTYPES 11
#define MEALCOST 15

// creating a data type containing bills name, value and amount for deposit function
typedef struct
{
    char *name;
    float value;
    int amount;
} bill;

// declaring a functions
float deposit();
int payment();

// creating a global varible for balance
float balance = 0.0;

int main(void)
{
    printf("Welcome to IKCU cafeteria!\n");
    balance = deposit();
    balance -= payment();

    printf("\nYour current balance is %2.f. Have good day...\n", balance);
    return 0;
}

// initialising wallet function.
float deposit()
{
    // bill type of array
    bill data[BILLTYPES];

    data[0].value = 200.0;
    data[1].value = 100.0;
    data[2].value = 50.0;
    data[3].value = 20.0;
    data[4].value = 10.0;
    data[5].value = 5.0;
    data[6].value = 1.0;
    data[7].value = 0.5;
    data[8].value = 0.25;
    data[9].value = 0.10;
    data[10].value = 0.05;

    data[0].name = "200 bill";
    data[1].name = "100 bill";
    data[2].name = "50 bill";
    data[3].name = "20 bill";
    data[4].name = "10 bill";
    data[5].name = "5 bill";
    data[6].name = "1 lira";
    data[7].name = "50 kurus";
    data[8].name = "25 kurus";
    data[9].name = "10 kurus";
    data[10].name = "5 kurus";

    // This loop asks user to how many bills they want to deposit for every bill type than multipies that information with value of
    // the bill and adds to balance
    for (int i = 0; i < BILLTYPES; i++)
    {
        printf("\nHow many %s you want to deposit: ", data[i].name);
        scanf("%i", &data[i].amount);
        balance += (float) data[i].amount * data[i].value;
    }
    return balance;
}

// initialising payment function.
int payment()
{
    int days = 0;
    int cost = 0;

    // asking user prompt for days info to calc total cost
    printf("\nHow many days do you had meal? ");
    scanf("%i", &days);

    cost = MEALCOST * days;

    // if users balance greater or even than total cost function will return cost
    if (balance >= cost)
    {
        return cost;
    }
    // if user's balance is less than total cost program will ask user to deposit more or try to pay less days than acording to
    // answer will forward
    if (balance < cost)
    {
        int answer;
        printf("\nYou are trying to pay %i for %i days but your balance is %2.f. Please try to deposit more or pay acording to your "
               "balance.\n",
               cost, days, balance);
        printf("If you like to deposit more type '0' or If you like to continue to payment type '1'.");

        do
        {
            scanf("%i", &answer);
            if (answer < 0 || 1 < answer)
            {
                printf("Please only type 1 or 0.");
            }
            if (answer == 0)
            {
                balance = deposit();
                cost = payment();
            }
            if (answer == 1)
            {
                cost = payment();
            }
        }
        while (answer < 0 || 1 < answer);
    }
    return cost;
}
