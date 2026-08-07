class Solution {
public:
    bool isAlphanumeric(char ch){
        if((ch >= 'A' && ch <='Z') || (ch >= 'a' && ch <= 'z') || (ch >='0' && ch<='9')) return true;
        return false;
    }
    bool isPalindrome(string s, int start, int end){
        int l = start;
        int r = end;

        while(l < r){
            if(tolower(s[l])!=tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j = s.size()-1;

        while(i < j){
            if(tolower(s[i])!= tolower(s[j])){
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
            i++;
            j--;
        }
        return true;
    }
};