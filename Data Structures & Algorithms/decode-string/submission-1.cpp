class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        stack<int>numStack;
        string temp = "";
        int number = 0;

        for(int i=0; i<s.size(); i++){
            if (isdigit(s[i])) {
                // Build the complete number (handles 10, 100, etc.)
                number = number * 10 + (s[i] - '0');
            }
            else if(s[i]=='['){
                numStack.push(number);
                st.push(temp);
                number =0;
                temp = "";
            }
            else if(s[i]==']'){
                
                int k = numStack.top();
                numStack.pop();

                string previous = st.top();
                st.pop();

                string decoded_string = "";
                for(int j=0; j<k; j++){
                    decoded_string+=temp;
                }
                temp = previous + decoded_string;
            }
            else{
                temp+=s[i];
            }
        }
        
        return temp;

        
        
    }
};