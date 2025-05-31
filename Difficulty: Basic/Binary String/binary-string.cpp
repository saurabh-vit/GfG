
class Solution {
  public:
    // Function to count the number of substrings that start and end with 1.
    
    int count(int n, string &a, int i){
        if(i==n){
            return 0;
        }
        return (a[i]=='1' ? 1:0) + count(n, a, i+1);
    }
    
    long binarySubstring(int n, string a) {

        // Your code here
        int one = count(n, a, 0);
        return (long)one * (one-1)/2;
    }
};