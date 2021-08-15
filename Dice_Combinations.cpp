// Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.
// For example, if n=3, there are 4 ways

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef pair<int, int> pi;
ll solve_with_dp(int n, vector<ll> &dp)
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        if (i == 3)
        {
            dp[i] = 1 + dp[i - 1] + dp[i - 2];
        }
        else if (i == 4)
        {
            dp[i] = 1 + dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        else if (i == 5)
        {
            dp[i] = 1 + dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
        }
        else if (i == 6)
        {
            dp[i] = 1 + dp[i - 6] + dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5];
        }
        else
        {
            dp[i] = dp[i - 6] + dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4] + dp[i - 5];
        }
        dp[i] %= 1000000007;
    }
    return dp[n] % 1000000007;
}
void solve()
{
    ll n, i, j, k, p, q, ans = 0, sum = 0;
    cin >> n;
    vector<ll> dp(n + 1, 0);
    ans = solve_with_dp(n, dp);
    cout << ans;
}
int main()
{

    IO
        solve();
    return 0;
}
