class Solution {
  public:
    int bitwise(int num){
        int count = 0;
        while(num>0){
            if(num%2 == 1){
                count++;
            }
            num /= 2;
        }
        return count;
    }
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<pair<int,int>> check;
        for(int i = 0; i < n; i++){
            check.push_back({bitwise(arr[i]), arr[i]});
        }
        stable_sort(check.begin(), check.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });
        vector<int> result;
        for(auto &p : check){
            result.push_back(p.second);
        }
        return result;
    }
};