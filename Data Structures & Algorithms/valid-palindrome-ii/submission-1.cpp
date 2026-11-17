class Solution {
public:
    bool checkIsAlphanumeric(char ch){
        if((ch <'a' || ch >'z') && (ch<'A' || ch>'Z') && (ch<'0' || ch>'9')) return false;
        return true;
    }
    bool checkPalindrome(int start, int end, string s){
        while(start < end){
            if(tolower(s[start])!=tolower(s[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    bool validPalindrome(string s) {
      int i=0;
      int j = s.size()-1;

      while(i < j){
        if(tolower(s[i])!=tolower(s[j])){
            return checkPalindrome(i+1, j, s) || checkPalindrome(i, j-1, s);
        }
        i++;
        j--;
      }  
      return true;
    }
};