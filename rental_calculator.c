// Name: Karthikeya Telapalli
/* Description: This code computes hourly(4 hours), daily, and weekly rental prices for four
   types of cleaning equipment. Users choose a kind of equipment and set the rental time 
   in days and hours. The application optimizes rate selection for cost-effectiveness and 
   highlights any problems resulting from improper input hours. The user is then shown 
   the entire charge */


#include <stdio.h>

// Equipment rates written accordingly per 4 hour,day,week
int rental_rates[4][3] = {
    {7, 10, 40},    // rates for Carpet blower
    {27, 39, 156},  // rates for Carpet cleaner
    {61, 87, 348},  // rates for Carpet extractor with heater
    {59, 84, 336}   // rates for Hard flooring cleaner
};

// Here I am Defining constants to improve code readability.
#define FOUR_HOUR_RATE 0
#define PER_DAY_RATE 1
#define PER_WEEK_RATE 2

int main() {
    // Here the code print a popup for the user to choose an equipment number
    printf("Please select from four equipment: 1, 2, 3, and 4\n");

    int chosen_equipment, rental_days, rental_hours = 0;
    int total_charge = 0;

    // Here we ask the user to select equipment required
    printf("Enter equipment selection: ");
    scanf("%d", &chosen_equipment);

    if (chosen_equipment < 1 || chosen_equipment > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 0;
    }

    // Here we ask the user to enter the days rented
    printf("Enter days: ");
    scanf("%d", &rental_days);

    // Here we ask the user to enter the hours rented
    printf("Enter hours: ");
    scanf("%d", &rental_hours);

    // Here the code checks if the hours are below 0 or above 24 and if they are it prints invalid hours
    if (rental_hours < 0 || rental_hours >= 24) {
        printf("Invalid hours.\n");
        return 0;
    }

    // Now we calculate the price based on the number of weeks
    int total_weeks = rental_days / 7;
    total_charge += total_weeks * rental_rates[chosen_equipment - 1][PER_WEEK_RATE];
    rental_days %= 7;  // Here we calculate the days remained after full weeks

    // We calculate the charge for the remaining days here
    if (rental_days >= 5 || (rental_days == 4 && rental_hours > 0)) {
        total_charge += rental_rates[chosen_equipment - 1][PER_WEEK_RATE]; // If the weekly rate is cheaper than the daily rate we use weekly
    } else {
        total_charge += rental_days * rental_rates[chosen_equipment - 1][PER_DAY_RATE]; // Or else we use daily rate

        // Here, we calculate the charge for hours
        if (rental_hours > 0 && rental_hours <= 4) {
            total_charge += rental_rates[chosen_equipment - 1][FOUR_HOUR_RATE];
        } else if (rental_hours > 4) {
            total_charge += rental_rates[chosen_equipment - 1][PER_DAY_RATE];
        }
    }

    printf("Charge($): %d\n", total_charge); // Here we print the final total charge

    return 0;
}
