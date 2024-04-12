#include <iostream>
#include <vector>

using namespace std;

// Function to check if there exists a subset with the given sum
bool isSubsetSum(vector<int>& set, int sum) {
    int n = set.size();
    vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1, false));

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            // If the current element is greater than the sum, skip it
            if (set[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
        }
    }

    return dp[n][sum];
}

int main() {
    vector<int> set;
    int num, sum;

    // Input set of numbers
    cout << "Enter the number of elements in the set: ";
    cin >> num;
    cout << "Enter the elements of the set:\n";
    for (int i = 0; i < num; ++i) {
        int temp;
        cin >> temp;
        set.push_back(temp);
    }

    // Input target sum
    cout << "Enter the target sum: ";
    cin >> sum;

    // Check if there is a subset with the given sum
    if (isSubsetSum(set, sum))
        cout << "Subset with sum " << sum << " exists.\n";
    else
        cout << "Subset with sum " << sum << " does not exist.\n";

    return 0;
}

