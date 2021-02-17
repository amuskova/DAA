#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
#define MOD 1000000007

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    vector<long> dp(n + 1);
    vector<long> lastBlue(n + 1);
    vector<long> lastNotBlue(n + 1);

    dp[1] = k, lastBlue[1] = 1, lastNotBlue[1] = k - 1;

    for (int i = 2; i <= n; ++i) {
        lastBlue[i] = lastNotBlue[i-1];
        dp[i] = (lastBlue[i-1] * (k - 1) % MOD + lastNotBlue[i-1] * k % MOD) % MOD;
        lastNotBlue[i] = (dp[i] - lastBlue[i] + MOD) % MOD;
    }

    printf("%d\n", dp[n]);
    return  0;
}
