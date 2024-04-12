#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int unboundedKnapsack(int k, vector<int>& arr) {
    vector<int> dp(k + 1, 0);

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] <= i) {
                dp[i] = max(dp[i], dp[i - arr[j]] + arr[j]);
            }
        }
    }

    return dp[k];
}

int main() {
    // Input number of test cases
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--) {
        // Input length of array and target sum
        int n, k;
        cout << "Enter the length of array and the target sum: ";
        cin >> n >> k;

        // Input array elements
        vector<int> arr(n);
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Call the unboundedKnapsack function
        int result = unboundedKnapsack(k, arr);

        // Output the result
        cout << "Maximum sum: " << result << endl;
    }

    return 0;
}

