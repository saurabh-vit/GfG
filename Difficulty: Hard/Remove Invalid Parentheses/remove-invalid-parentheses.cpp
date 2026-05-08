class Solution {
  public:
    bool isValid(string &s){
        int count = 0;
        
        for(char c : s){
            if(c == '('){
                count++;
            }
            else if(c == ')'){
                count--;
                
                if(count < 0){
                    return false;
                }
            }
        }
        
        return count == 0;
    }
    
    vector<string> validParenthesis(string &s) {
        // code here
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;
        
        q.push(s);
        visited.insert(s);
        
        bool found = false;
        
        while(!q.empty()){
            
            string curr = q.front();
            q.pop();
            
            if(isValid(curr)){
                ans.push_back(curr);
                found = true;
            }
            
            if(found){
                continue;
            }
            
            for(int i = 0; i < curr.size(); i++){
                
                if(curr[i] != '(' && curr[i] != ')'){
                    continue;
                }
                
                string temp = curr.substr(0, i) + curr.substr(i + 1);
                
                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push(temp);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
