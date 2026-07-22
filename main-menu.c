#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, num, i, isPrime;
    unsigned long int fact;

    printf("\n\n\t\tLabAlm - O melhor lugar para aprender\n\n\n");

    while (1)
    {
        printf("1. Factorial\n");
        printf("2. Prime\n");
        printf("3. Odd/Even\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number:\n");
            scanf("%d", &num);
            fact = 1;
            for (i = 1; i <= num; i++)
            {
                fact = fact * i;
            }
            printf("\nFactorial value of %d is = %lu\n\n", num, fact);
            break;

        case 2:
            printf("Enter number:\n");
            scanf("%d", &num);

            if (num <= 1)
            {
                printf("\n%d is neither prime nor composite (or <= 1)\n\n", num);
            }
            else
            {
                isPrime = 1; // Assume que é primo
                for (i = 2; i < num; i++)
                {
                    if (num % i == 0)
                    {
                        isPrime = 0; // Encontrou divisor, não é primo
                        break;
                    }
                }

                if (isPrime)
                    printf("\n%d is a Prime number\n\n", num);
                else
                    printf("\n%d is NOT a Prime number\n\n", num);
            }
            break;

        case 3:
            printf("Enter number:\n");
            scanf("%d", &num);

            if (num % 2 == 0)
                printf("\n%d is an Even number\n\n", num);
            else
                printf("\n%d is an Odd number\n\n", num);
            break;

        case 4:
            printf("\n\t\tCoding is Fun !\n\n");
            exit(0);

        default:
            printf("\nInvalid choice! Please try again.\n\n");
            break;
        }
    }

    return 0;
}
