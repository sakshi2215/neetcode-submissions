class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j =0;
        string newWord = "";
        while(i<word1.size() && j < word2.size()){
            newWord = newWord + word1[i] + word2[j];
            i++;
            j++;
        }
        if(i<word1.size()) newWord = newWord+word1.substr(i);
        if(j < word2.size()) newWord = newWord + word2.substr(j);
        return newWord;
    }
};