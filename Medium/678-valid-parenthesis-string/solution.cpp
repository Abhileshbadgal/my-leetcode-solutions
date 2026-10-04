class Solution {
public:
    vector<vector<int >>dp;
 int solve(string s,int ct,int i)
    {
        if(i==s.size())
        {
            if(ct==0)return 1;
            return 0;
        }
        if(ct<0)return false;
        if(dp[i][ct]!=-1)return dp[i][ct];
        if(s[i]=='(')return dp[i][ct]=solve(s,ct+1,i+1);
        else if(s[i]==')' && ct==0)return 0;
        else if(s[i]==')' )return dp[i][ct]=solve(s,ct-1,i+1);
        return dp[i][ct]= (solve(s,ct+1,i+1) ||solve(s,ct-1,i+1)||solve(s,ct,i+1));
 
    }
    bool checkValidString(string s) {
        dp.resize(101,vector<int>(101,-1));
        return solve(s,0,0);
        
    }
};
