#include <stdio.h>

int main() {
    // Declare variables
    int n;          // To store the number of elements
    float big;      // To store the largest number found

    // Prompt the user for the number of elements
    printf("Enter the number of elements you wish to find the greatest element of: ");
    scanf("%d", &n);

    // Check if the input is valid
    if (n <= 0) {
        printf("Please enter a positive number of elements.\n");
        return 1;  // Exit with error code
    }

    // Prompt for the first number and initialize 'big' with it
    printf("Enter %d numbers:\n", n);
    printf("Enter element 1: ");
    scanf("%f", &big);

    // Process remaining numbers using a loop
    for (int i = 2; i <= n; i++) {
        float current;  // Variable to store the current number

        // Prompt for the current number
        printf("Enter element %d: ", i);
        scanf("%f", &current);

        // Compare with the current largest
        if (current > big) {
            big = current;  // Update 'big' if current number is larger
        }
    }

    // Display the result
    printf("The largest of the %d numbers is %.2f\n", n, big);

    return 0;
}
