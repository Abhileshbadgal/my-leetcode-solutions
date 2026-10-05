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
//2 recurssion and memomization
class Solution {
public:
    int t[101][101];
    bool solve(string& s,int idx,int open
        if(idx == s.size()){
            return open == 0;
        }
        if(t[idx][open] != -1){
            return t[idx][open];
        }
        if(s[idx] == '('){
            return t[idx][open] = solve(s,idx + 1,open + 1);
        }
        if(s[idx] == ')'){
            if(open > 0){
                return t[idx][open] = solve(s,idx + 1,open - 1);
            }
            return t[idx][open] = false;
        }
        if(s[idx] =='*'){
            if(solve(s,idx + 1,open)){
                return t[idx][open] = true;
            }
            if(solve(s,idx + 1,open + 1)){
                return t[idx][open] = true;
            }
            if(open > 0 && solve(s,idx + 1,open - 1)){
                return t[idx][open] = true;
            }
        }
        return t[idx][open] = false;
    }
    bool checkValidString(string s) {
        memset(t,-1,sizeof(t));
        return solve(s,0,0);
    }
};
