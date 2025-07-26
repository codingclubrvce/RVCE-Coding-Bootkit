/*
Question: Write a program to calculate electricity bill based on units consumed.

Description:
Create a program that calculates electricity bill based on the following slabs:
- First 50 units: Rs. 0.50/unit
- Next 100 units: Rs. 0.75/unit
- Next 100 units: Rs. 1.20/unit
- Above 250 units: Rs. 1.50/unit
Additional surcharge: 20% of total amount

For example:
- Units: 300
  First 50 units: 50 × 0.50 = 25
  Next 100 units: 100 × 0.75 = 75
  Next 100 units: 100 × 1.20 = 120
  Remaining 50 units: 50 × 1.50 = 75
  Total: 295 + 20% surcharge = 354

Input:
1. Number of units consumed

Output:
1. Bill amount for each slab (if applicable)
2. Total bill amount including surcharge

Note: Display detailed breakup of bill calculation
*/

#include <stdio.h>

int main()
{
    int units;
    int code;
    float amount = 0.0;

    printf("Enter the number of electricity units consumed:  ");
    scanf("%d", &units);

    int quotient = units / 100;

    switch (code) 
    {
        case 0:
            amount = units * 1.5;

        case 1:
            amount = units * 2.5;
        
        case 2:
            amount = units * 4;
        
        case 3:
            amount = units * 4;
        
        default:
            amount = units * 6;
    }

    printf("%f\n", amount);
    return 0;
}