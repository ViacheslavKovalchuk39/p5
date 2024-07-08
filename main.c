#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdio.h>

#define MOD 12345

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    scanf("%d", &n);
    long long dp[n+1][3];
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = dp[i-1][0];
        dp[i][2] = dp[i-1][1];
    }
    long long result = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
    printf("%lld\n", result);
    return 0;
}

