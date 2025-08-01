#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

// Use the standard namespace to avoid writing std:: before every command
using namespace std;

bool isPossible(vector<int>& boards, int k, int mid) {
    int painterCount = 1; // Start with the first painter.
    int boardSum = 0;     // Keeps track of the length assigned to the current painter.
    int n = boards.size();

    // Iterate through each board.
    for (int i = 0; i < n; i++) {
        // If the current board's length is greater than the max allowed, it's impossible.
        if (boards[i] > mid) {
            return false;
        }

        // Check if the current painter can take this board.
        if (boardSum + boards[i] <= mid) {
            // If yes, assign the board to the current painter.
            boardSum += boards[i];
        } else {
            // If no, we need a new painter.
            painterCount++;

            // Check if we have run out of painters.
            if (painterCount > k) {
                return false;
            }
            // Assign the current board to the new painter.
            boardSum = boards[i];
        }
    }
    // If we get through all boards, the allocation is possible.
    return true;
}


int findLargestMinDistance(vector<int>& boards, int k) {
    // The search space for our answer starts at 0.
    int start = 0;
    
    // The maximum possible answer is the sum of all board lengths (if 1 painter does all the work).
    long long sum = 0;
    int n = boards.size();
    for (int i = 0; i < n; i++) {
        sum += boards[i];
    }
    int end = sum;
    
    int ans = -1;

    // Apply binary search on the range of possible answers.
    while (start <= end) {
        // Calculate mid-point to avoid potential integer overflow.
        int mid = start + (end - start) / 2;

        // Check if 'mid' is a feasible amount of max work.
        if (isPossible(boards, k, mid)) {
            // If 'mid' is a possible solution, it might be our answer.
            // Store it and try for an even smaller (better) max value in the left half.
            ans = mid;
            end = mid - 1;
        } else {
            // If 'mid' is not a possible solution, the max work allowed is too small.
            // We need to increase it, so we search in the right half.
            start = mid + 1;
        }
    }
    // Return the best possible answer found.
    return ans;
}

// --- Main Function to Run the Code ---
int main() {
    // Example Input
    vector<int> boards = {10, 20, 30, 40}; // Length of boards
    int k = 2; // Number of painters

    // Call the function to find the optimal distribution
    int result = findLargestMinDistance(boards, k);

    // Print the result
    cout << "The minimum of the maximum work for any painter is: " << result << endl;
    // Expected Output for this example is 60.
    // Painter 1 takes {10, 20, 30}, total = 60.
    // Painter 2 takes {40}, total = 40.
    // The maximum work done by any painter is 60. This is the minimum possible maximum.

    return 0;
}