class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        int n = mices.size();
        int ans = -1;
        for(int i=0; i<n; i++){
            ans = max(ans, abs(mices[i] - holes[i]));
        }
        return ans;
    }
};