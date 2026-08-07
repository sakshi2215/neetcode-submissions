class Solution {
public:
    bool isAlphanumeric(char ch){
        if((ch >='A' && ch <='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        int i=0;
        int j = n-1;

       // bool flag = true;

        while(i < j){


            while(i< j && !isAlphanumeric(s[i])){
                i++;
            }
            while(i<j && !isAlphanumeric(s[j])){
                j--;
            }


            if(tolower(s[i])!= tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
