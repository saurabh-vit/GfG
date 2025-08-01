class Solution {
  public:
  
    bool isvolume(char ch){
        return ch=='a'|ch=='e'|ch=='i'|ch=='o'|ch=='u';
    }
    
    int countBalanced(vector<string>& arr) {
        // code here
        unordered_map<int, int> diffcount;
        diffcount[0] = 1;
        
        int vol = 0, alpha = 0, result = 0;
        for(string& s : arr){
            for(char ch :s){
                if(isvolume(ch)){
                    vol++;
                }else{
                    alpha++;
                }
            }
            int diff = vol - alpha;
            result += diffcount[diff];
            diffcount[diff]++;
        }
        return result;
    }
};