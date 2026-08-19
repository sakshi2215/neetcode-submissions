class Solution {
public:
    string minWindow(string s, string t) {
        int i =0;
        int j = 0;
        unordered_map<char, int>mpp;
        int count = t.size();
        int x = 0;
        int y = 0; 

        int minLength = INT_MAX;

        for(int k =0; k<t.size(); k++){
            mpp[t[k]]++;
        }

        while(j < s.size()){
            
            //while we are in valid window keep decreasing the window
            
            if(mpp.find(s[j])!=mpp.end()){
                if(mpp[s[j]] > 0)
                    count--;
                mpp[s[j]]--;
            }
            
            
            while(count == 0){
                if(minLength > j - i + 1){
                    minLength = j-i+1;
                    x = i;
                    y = j; 
                }
                if(mpp.find(s[i])!=mpp.end()){
                    mpp[s[i]]++;
                    if (mpp[s[i]] > 0) {
                        count++;
                    }
                }  
                i++;
                
            }
            j++;

        }
        if(minLength == INT_MAX) return "";
        return s.substr(x, y - x + 1);

    }
};
