class Solution {
public:
    string decodeString(string s) {
        stack<int> brac;
        stack<string> let;
        string dummain;
        string dumdum;
        string dumnum;
        string ans;

        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                dumnum += s[i];
            }
            else if(s[i] == '['){
                brac.push(stoi(dumnum));
                dumnum = "";

                let.push(dumdum);
                dumdum = "";
            }
            else if(s[i] == ']'){
                int n = brac.top();
                brac.pop();

                string previous = let.top();
                let.pop();

                for(int j = 0; j < n; j++){
                    dummain += dumdum;
                }

                dumdum = previous + dummain;
                dummain = "";
            }
            else{
                dumdum += s[i];
            }
        }

        ans = dumdum;
        return ans;
    }
};