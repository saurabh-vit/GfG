class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        int n = s.size();
        if(n<=1){
            return 0;
        }
        
        vector<int> freq(256, 0);
        
        for(char c : s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                freq[c]++;
            }
        }
        
        long long ans = 1;
        int unique = 0;
        for(char v : {'a', 'e', 'i', 'o', 'u'}){
            if(freq[v]>0){
                ans *= freq[v];
                unique++;
            }
        }
        if(unique == 0){
            return 0;
        }
        
        int fact = 1;
        for(int i = 1; i<=unique; i++){
            fact *= i;   
        }
        return ans*fact;
    }
};