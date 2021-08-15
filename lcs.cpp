class Solution {
public:
    int solve(string s,string t,int n,int m,vector<vector<int>>& dp)
    {
        if(n==0 or m==0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        else if(s[n-1]==t[m-1])
            return dp[n][m]= 1+solve(s,t,n-1,m-1,dp);
        else
            return dp[n][m]=max(solve(s,t,n-1,m,dp),solve(s,t,n,m-1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            if(i==0 or j==0)
                dp[i][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
                
        }
        // for(int i=0;i<=n;i++)
        // {
        //     for(int j=0;j<=m;j++)
        //         cout<<dp[i][j]<<" ";
        // cout<<endl;
        // }
            return dp[n][m];
        
    }
};
