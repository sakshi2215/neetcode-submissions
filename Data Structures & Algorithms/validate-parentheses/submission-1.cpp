class Solution {
public:
    bool isValid(string st) {
        stack<char>s;

        for(int i=0; i<st.size(); i++){
            if(st[i]=='(' || st[i] =='{' || st[i]=='['){
                s.push(st[i]);
            }
            else{
                if(s.empty()) return false;
                if(st[i]=='}'){
                    if(!s.empty() && s.top()!='{') return false;
                    s.pop();
                }
                else if(st[i]==']' ){
                    if(!s.empty() && s.top()!='[') return false;
                    s.pop();
                }
                else if(st[i]==')'){
                    if(!s.empty() && s.top()!='(') return false;
                    s.pop();
                }
                
            }
        }
        if(!s.empty()) return false;
        return true;
    }
};
