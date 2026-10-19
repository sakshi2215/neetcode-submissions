class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string encodedString = "";
        for(int i=0; i<strs.size();i++){
            encodedString.append(to_string(strs[i].size()));
            encodedString.push_back('#');
            encodedString.append(strs[i]);
            
        }
        return encodedString;
    }

    vector<string> decode(string s) {

        if(s.empty()) return {};

        vector<string>res;
        int i=0;
        while(i < s.size()){
            int j = i;
            while(s[j]!='#'){
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            i = j+1;
            j= i+length;
            res.push_back(s.substr(i, length));
            i=j;

        }
        return res;

    }
};
