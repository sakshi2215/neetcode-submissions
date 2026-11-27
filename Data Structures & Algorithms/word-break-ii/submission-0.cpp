class Solution {
public:
    vector<string>ans;
    unordered_map<string, int>contains;
    vector<string>temp;

    string join(vector<string>&temp){
        string sentence = "";
        for(int i=0; i<temp.size(); i++){
            sentence = sentence + " " + temp[i];
        }
        return sentence.substr(1, sentence.size());
    }
    void solve(int index, string s){
        if(index==s.size()){
            ans.push_back(join(temp));
        }

        for(int i= index; i<s.size(); i++){
            string word = s.substr(index, i-index+1);
            if(contains.find(word)!=contains.end()){
                temp.push_back(word);
                solve(i+1, s);
                temp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        
        for(int i=0; i<wordDict.size(); i++){
            contains[wordDict[i]]++;
        }
        solve(0, s);
        return ans;
    }
};