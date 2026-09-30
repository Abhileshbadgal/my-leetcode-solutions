class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.length();
        string result="";
        int i=0;
        unordered_map<string,string> mp;
        for(vector<string> temp:knowledge){
            string key=temp[0];
            string value=temp[1];
            mp[key]=value;
        }
        while(i<n){
            if(s[i]=='('){
                i++;
                string word="";
                while(s[i]!=')'){
                      word+=s[i];
                      i++;
                }
                if(s[i]==')') i++;
                if(mp.count(word)){
                    result+=mp[word];
                }else {
                    result+="?";
                }
            }
            else{
            result+=s[i];
            i++;}
        }
        return result;
    }
};
