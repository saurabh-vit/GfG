class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        sort(words.begin(), words.end());
        unordered_set<string> valid;
        string ans = "";
        for(string &word : words){
            if(word.size()==1 || valid.count(word.substr(0, word.size()-1))){
                if(word.size()>ans.size() || (word.size()==ans.size() && word<ans)){
                    ans = word;
                }
                valid.insert(word);
            }
        }
        return ans;
    }
};