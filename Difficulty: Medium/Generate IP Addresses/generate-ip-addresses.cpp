class Solution {
  public:
  
    bool valid(string part){
        if(part.size() > 1 && part[0] == '0') return false;
        int num = stoi(part);
        return num >= 0 && num <= 255;
    }
    
    void solve(int index, string &s, vector<string> &path, vector<string> &ans){
        
        if(path.size() == 4){
            if(index == s.size()){
                string ip = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
                ans.push_back(ip);
            }
            return;
        }
        
        for(int len = 1; len <= 3; len++){
            
            if(index + len > s.size()) break;
            
            string part = s.substr(index, len);
            
            if(valid(part)){
                path.push_back(part);
                solve(index + len, s, path, ans);
                path.pop_back();
            }
        }
    }
    
    vector<string> generateIp(string &s) {
        
        vector<string> ans;
        vector<string> path;
        
        solve(0, s, path, ans);
        
        return ans;
    }
};