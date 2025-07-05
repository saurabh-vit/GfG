class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        stack<int> s;
        int n = arr.size();
        int maxsum = INT_MIN;
        for(int i = 0; i<n; i++){
            while(!s.empty() && s.top() > arr[i]){
                int top = s.top();
                s.pop();
                maxsum = max(maxsum, top+arr[i]);
            }
            if(!s.empty()){
                maxsum = max(maxsum, s.top()+arr[i]);
            }
            s.push(arr[i]);
        }
        return maxsum;
    }
};