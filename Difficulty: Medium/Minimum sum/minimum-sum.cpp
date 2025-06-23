class Solution {
  public:
    string add(string nums1, string nums2){
        string result = "";
        int i = nums1.size()-1, j=nums2.size()-1, carry = 0;
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            if(i>=0){
                sum += nums1[i--]-'0';
            }if(j>=0){
                sum+=nums2[j--]-'0';
            }
            carry = sum/10;
            result += (sum%10)+'0';
        }
        reverse(result.begin(), result.end());
        int pos = 0;
        while(pos<result.size() && result[pos]=='0'){
            pos++;
        }
        if(pos==result.size()) return 0;
        return result.substr(pos);
    }
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        string s1 = "", s2 = "";
        for(int i = 0; i<n; i++){
            if(i%2==0){
                s1 += to_string(arr[i]);
            }
            else{
                s2 += to_string(arr[i]);
            }
        }
        return add(s1, s2);
    }
};