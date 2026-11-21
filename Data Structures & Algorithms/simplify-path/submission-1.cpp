class Solution {
   public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string item;
        vector<string>st;
        
        while (getline(ss, item, '/')) {
            if(item==".."){
                if(!st.empty()) st.pop_back();
            }
            else if(item=="" || item==".") continue;
            else{
                st.push_back(item);
            }
        }
        string result = "";

        for(string dir : st) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};