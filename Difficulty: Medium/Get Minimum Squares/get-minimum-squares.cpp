class Solution {
  public:
    bool is_square(int x){
        int r = (int)floor(sqrt(x));
        return r*r == x;
    }
    
    int minSquares(int n){
        if(is_square(n)) return 1;
    
        // check 2
        for(int i = 1; i*i <= n; ++i){
            if(is_square(n - i*i)) return 2;
        }
    
        // Legendre's condition for 4
        int m = n;
        while(m % 4 == 0) m /= 4;
        if(m % 8 == 7) return 4;
    
        return 3;
    }
};