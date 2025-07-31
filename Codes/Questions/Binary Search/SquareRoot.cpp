#include <iostream>
#include <iomanip> // Required for std::setprecision

// Using the standard namespace to avoid prefixing with std::
using namespace std;

// Function to find the integer part of a square root using binary search.
// I've renamed it to integerSqrt for clarity.
long long int integerSqrt(int x) {
    if (x < 0) return -1; // Square root of negative is not a real number
    int start = 0;
    int end = x;
    long long int ans = 0;

    while (start <= end) {
        // Using long long for mid and its square to prevent potential overflow.
        long long int mid = start + (end - start) / 2;
        if (mid * mid == x) {
            return mid; // Found perfect square
        }
        if (mid * mid < x) {
            ans = mid; // This is a possible answer, store it and search for a better one.
            start = mid + 1;
        } else {
            end = mid - 1; // The answer must be in the smaller half.
        }
    }
    return ans;
}

// Function to add decimal precision to the square root.
double morePrecision(int n, int precision, int intPart) {
    // CORRECTION: 'ans' must be a double to correctly store decimal values.
    double ans = intPart;
    double factor = 1;

    // Loop for the number of decimal places required.
    for (int i = 0; i < precision; i++) {
        // Decrease the factor for each decimal place (0.1, 0.01, 0.001...).
        factor = factor / 10;
        // Increment answer by the factor until its square is just under n.
        for (double j = ans; j * j < n; j = j + factor) {
            ans = j; // Update ans with the most precise value found so far.
        }
    }
    return ans;
}

// New main function to drive the program.
int main() {
    int number;
    int precision;

    // Prompt the user for input.
    cout << "Enter a non-negative integer: ";
    cin >> number;
    cout << "Enter the desired decimal precision: ";
    cin >> precision;

    // Get the integer part of the square root.
    int intPart = integerSqrt(number);
    // Calculate the final answer with added precision.
    double finalAnswer = morePrecision(number, precision, intPart);

    // Display the result formatted to the requested precision.
    cout << "The square root of " << number << " is: "<< fixed << setprecision(precision) << finalAnswer << endl;

    // Return 0 to indicate successful execution.
    return 0;
}