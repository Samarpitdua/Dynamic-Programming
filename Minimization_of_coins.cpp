/*Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,…,cn: the value of each coin.*/
//Code
#include <bits/stdc++.h>
#define ll long long
long long i, j;
#define IO                   \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define en cout << "\n";
#define array(a, n)            \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define f(i, a, b) for (int i = a; i < b; i++)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define take  \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;
#define MOD 1000000007
typedef pair<int, int> pi;
ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}
ll solve_with_dp(int n, vector<ll> &dp,vector<ll>& coins,int sum)
{
    if(sum<0)
        return INT_MAX;
    if(n<=0 and sum>0)
        return INT_MAX;
    if(sum==0)
        return 0;
    if(dp[sum]!=-1)
        return dp[sum];
    ll ans = INT_MAX;
    for (int i = 0; i < n;i++)
    {
        if(sum>=coins[i])
        {
            ll temp = 1 + solve_with_dp(n, dp, coins, sum - coins[i]);
            if(ans>temp)
                ans=temp;
        }
 
    }
    dp[sum] = ans;
    return dp[sum];
 
 //   return -1;
}
 
int main()
{
    ll n, ans = 0, sum = 0;
    cin >> n>>sum;
    vector<ll> coins(n+1);
    vector<ll> dp(sum+1,-1);
    f(i, 0, n) cin >> coins[i];
    ans = solve_with_dp(n, dp,coins,sum);
    
    if(ans==INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << ans;
   // cout << ans;
    return 0;
}
