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

    printf("\nYour current balance is %f. Have good day...\n", balance);
    return 0;
}

// initialising wallet function.
float deposit()
{
    // bill type of array
    bill input[BILLTYPES];

    input[0].value = 200.0;
    input[1].value = 100.0;
    input[2].value = 50.0;
    input[3].value = 20.0;
    input[4].value = 10.0;
    input[5].value = 5.0;
    input[6].value = 1.0;
    input[7].value = 0.5;
    input[8].value = 0.25;
    input[9].value = 0.10;
    input[10].value = 0.05;

    input[0].name = "200 bill";
    input[1].name = "100 bill";
    input[2].name = "50 bill";
    input[3].name = "20 bill";
    input[4].name = "10 bill";
    input[5].name = "5 bill";
    input[6].name = "1 lira";
    input[7].name = "50 kurus";
    input[8].name = "25 kurus";
    input[9].name = "10 kurus";
    input[10].name = "5 kurus";

    // This loop asks user to how many bills they want to deposit for every bill type than multipies that information with value of
    // the bill and adds to balance
    for (int i = 0; i < BILLTYPES; i++)
    {
        printf("\nHow many %s you want to deposit: ", input[i].name);
        scanf("%i", &input[i].amount);
        balance += (float) input[i].amount * input[i].value;
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
        printf("\nYou are trying to pay %i for %i days but your balance is %f. Please try to deposit more or pay acording to your "
               "balance.\n",
               cost, days, balance);
        printf("If you like to deposit more type '0' or If you like to continue to payment type '1'.");
        scanf("%i", &answer);

        do
        {
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