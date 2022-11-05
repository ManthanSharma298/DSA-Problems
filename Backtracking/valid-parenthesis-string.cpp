

// rec + memo: O(n*n), O(n*n)
class Solution {
public:
    bool rec(int i, int bal, string& s, vector<vector<int>>& dp){
        // base case
        if(bal < 0) return false;
        if(i == s.size()) return dp[i][bal] = (bal == 0);
    
        if(dp[i][bal] != -1) return dp[i][bal];
        
        if(s[i] == '('){
            if(rec(i+1, bal+1, s, dp)) return dp[i][bal] = true;
        }
        else if(s[i] == ')'){
            if(rec(i+1, bal-1, s, dp)) return dp[i][bal] = true;   
        }
        else{
            if(rec(i+1, bal+1, s, dp)) return dp[i][bal] = true;
            
            if(rec(i+1, bal-1, s, dp)) return dp[i][bal] = true;
            
            if(rec(i+1, bal, s, dp)) return dp[i][bal] = true;
        }
        return dp[i][bal] = false;
    }
    
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return rec(0, 0, s, dp);
    }
};