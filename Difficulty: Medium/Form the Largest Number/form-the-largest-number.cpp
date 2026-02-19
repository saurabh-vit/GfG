class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string> nums;
        for(int num : arr){
            nums.push_back(to_string(num));
        }
        
        // Step 2: Custom sort
        sort(nums.begin(), nums.end(), [](string &a, string &b){
            return a + b > b + a;
        });
        
        // Step 3: Edge case (all zeros)
        if(nums[0] == "0")
            return "0";
        
        // Step 4: Concatenate result
        string result = "";
        for(string &s : nums){
            result += s;
        }
        
        return result;
    }
};