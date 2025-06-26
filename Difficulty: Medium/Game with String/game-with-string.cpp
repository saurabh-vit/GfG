class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        vector<int> freq(26, 0);
        for(char c : s){
            freq[c - 'a']++;
        }
        
        vector<int> ans;
        for(int f : freq){
            if(f>0){
                ans.push_back(f);
            }
        }
        
        sort(ans.begin(), ans.end(), greater<int>());
        while(k>0){
            sort(ans.begin(), ans.end(), greater<int>());
            if(ans[0]>0){
                ans[0]--;
                k--;
            }else{
                break;
            }
        }
        
        int final = 0;
        for(int val : ans){
            final += val * val;
        }
        return final;
    }
};