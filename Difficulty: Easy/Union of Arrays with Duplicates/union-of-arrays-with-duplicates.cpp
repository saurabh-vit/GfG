class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        unordered_set<int> s;
        
        // Insert elements of array a
        for(int i = 0; i < a.size(); i++){
            s.insert(a[i]);
        }
        
        // Insert elements of array b
        for(int i = 0; i < b.size(); i++){
            s.insert(b[i]);
        }
        
        // Convert set to vector
        vector<int> result;
        for(auto it : s){
            result.push_back(it);
        }
        
        return result;
    }
};