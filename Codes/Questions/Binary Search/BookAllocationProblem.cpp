#include <iostream>
#include <vector>
#include <numeric> // Required for std::accumulate

// Use the standard namespace to avoid writing std:: before every command
using namespace std;

bool isPossible(vector<int>& nums, int n, int m, int mid) {
    int studentCount = 1; // Start with the first student
    int pageSum = 0;      // Current number of pages assigned to the student

    // Iterate through all the books
    for (int i = 0; i < n; i++) {
        // Check if the current book can be assigned to the current student
        if (pageSum + nums[i] <= mid) {
            // If yes, add the pages of this book to the student's total
            pageSum += nums[i];
        } else {
            // If no, we need a new student
            studentCount++;

            // Check if we've exceeded the student limit or if a single book is too large
            if (studentCount > m || nums[i] > mid) {
                return false; // Allocation is not possible
            }
            // Assign the current book to the new student
            pageSum = nums[i];
        }
    }
    return true; // A valid allocation was found
}


int allocateBooks(vector<int>& nums, int n, int m) {
    // Edge case: if there are more students than books, it's impossible to allocate
    // NOTE: This check isn't strictly necessary for the binary search to work,
    // but it's a good practice for clarity and efficiency.
    if (m > n) {
        return -1; // Or handle as per problem specification
    }
    
    // The search space for our answer starts from 0
    int start = 0;
    // The maximum possible answer is the sum of all pages (if one student reads all books)
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
    }
    int end = sum;
    int ans = -1;

    // Apply binary search on the possible range of answers
    while (start <= end) {
        // Calculate mid-point to avoid potential integer overflow
        int mid = start + (end - start) / 2;

        // Check if 'mid' is a possible solution
        if (isPossible(nums, n, m, mid)) {
            // If it is, this could be our answer. Store it and
            // try to find an even smaller (better) answer in the left half.
            ans = mid;
            end = mid - 1;
        } else {
            // If 'mid' is not a possible solution, we need to allow more pages.
            // Move to the right half of the search space.
            start = mid + 1;
        }
    }
    return ans;
}

// --- Main Function to Run the Code ---
int main() {
    // Example Input
    vector<int> books = {10, 20, 30, 40}; // Pages in each book
    int m = 2; // Number of students

    // Get the number of books
    int n = books.size();

    // Call the function to find the minimum of the maximum pages
    int result = allocateBooks(books, n, m);

    // Print the result
    cout << "The minimum of the maximum pages a student must read is: " << result << endl;
    // Expected Output for this example is 60.
    // Allocation 1: {10, 20, 30} = 60
    // Allocation 2: {40} = 40
    // The maximum is 60.

    return 0;
}