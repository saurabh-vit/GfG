class Solution {
  public:
    vector<string> generateBinary(int n) {
        // code here
        vector<string> result;
        for(int i = 1; i<=n; i++){
            int ans = 0, pow = 1, num = i;
            while(num>0){
                int rem = num%2;
                num = num/2;
                ans += (rem*pow);
                pow = pow*10;
            }
            result.push_back(to_string(ans));
        }
        return result;
    }
};