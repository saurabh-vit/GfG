// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<pair<double, int>> ratio;
        for(int i = 0; i<n; i++){
            ratio.push_back({(double)val[i]/wt[i], i});
        }
        auto comp=[&](auto &a, auto &b){
            return a.first>b.first;
        };
        sort(ratio.begin(), ratio.end(), comp);
        double ans = 0.0;
        for(int i = 0; i<n; i++){
            int idx = ratio[i].second;
            if(wt[idx]<=capacity){
                ans += val[idx];
                capacity -= wt[idx];
            }else{
                ans += ratio[i].first * capacity;
                capacity = 0;
            }
        }
        return ans;
    }
};