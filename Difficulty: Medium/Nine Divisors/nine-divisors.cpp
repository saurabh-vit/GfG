class Solution {
  public:
    int countNumbers(int n) {
        // Code Here
        vector<int> prime;
        vector<bool> isPrime(sqrt(n)+2, true);
        isPrime[0] = isPrime[1] = false;
        for(int i=2; i*i<=n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<=sqrt(n); j+=i){
                    isPrime[j] = false;
                }
            }
        }
        for(int i=2; i<=sqrt(n); i++){
            if(isPrime[i])
                prime.push_back(i);
        }
        int count = 0;
        for(int i=0; i<prime.size(); i++){
            long long p8 = 1;
            for(int j=0; j<8; j++){
                p8 *= prime[i];
                if(p8 > n) break;
            }
            if(p8 <= n)
                count++;
        }
        int sz = prime.size();
        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                long long num = (long long)prime[i]*prime[i]*prime[j]*prime[j];
                if(num <= n)
                    count++;
                else
                    break;
            }
        }
        return count;
    }
};