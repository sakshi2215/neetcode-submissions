#include <iostream>
#include <string>
class Solution {
public:
    string decodeString(string s) {
        string str = "";
        int number = 0;
        stack<string>st;
        stack<int>nt;

        for(int i=0; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9'){
                number = number*10 + s[i]-'0';
            }
            else if(s[i]=='['){
                st.push(str);
                str = "";
                nt.push(number);
                number = 0;
            }
            else if(s[i]==']'){
                string temp = str;
                number = nt.top();
                nt.pop();
                str = st.top();
                for(int i=0; i<number; i++){
                    str+=temp;
                }
                
                st.pop();
                number = 0;

            }
            else{
                str+=s[i];
            }
        }
        return str;
    }
};