#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (wt[i-1] <= w) {
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    printf("Enter capacity: ");
    scanf("%d", &n);
    printf("Enter Weight: ");
    scanf("%d", &W);
    printf("\n");
    
    int wt[n], val[n], i;
    for (int i = 0; i < n; i++) 
    {
    printf("Enter value and weight: ");
    scanf("%d %d",  &val[i], &wt[i]);
    }

    int max_val = knapsack(W, wt, val, n);
    printf("\nMaximum value: %d\n", max_val);

    return 0;
}
