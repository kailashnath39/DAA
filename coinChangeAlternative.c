#include <stdio.h>

void printDPTable(int dp[][11], int numCoins, int amount) {
    printf("DP Table:\n");
    for (int i = 0; i <= numCoins; i++) {
        for (int j = 0; j <= amount; j++) {
            printf("%3d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int coin_change_ways(int coins[], int numCoins, int amount) {
    // Create a 2D array to store solutions to subproblems
    int dp[numCoins + 1][amount + 1];
    
    // Initialize the table
    for (int i = 0; i <= numCoins; i++)
        dp[i][0] = 1; // One way to make change for amount 0
    
    // Fill the table using bottom-up dynamic programming
    for (int i = 1; i <= numCoins; i++) {
        for (int j = 1; j <= amount; j++) {
            // Include the current coin
            int includeCurrentCoin = (j - coins[i - 1] >= 0) ? dp[i][j - coins[i - 1]] : 0;
            
            // Exclude the current coin
            int excludeCurrentCoin = dp[i - 1][j];
            
            // Total ways to make change is the sum of including and excluding the current coin
            dp[i][j] = includeCurrentCoin + excludeCurrentCoin;

            // Print the intermediate DP table at each step
            printDPTable(dp, numCoins, amount);
        }
    }
    
    // The result is stored in dp[numCoins][amount]
    return dp[numCoins][amount];
}

int main() {
    int coins[] = {1, 2, 5};
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    int amount = 10;

    int ways = coin_change_ways(coins, numCoins, amount);

    printf("Number of ways to make change for %d: %d\n", amount, ways);

    return 0;
}
