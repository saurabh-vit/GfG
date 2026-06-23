class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int count = 0, total = 0;
        int x = 1;
        while(total <= p){
            int next = x*x;
            total += next;
            if(total<=p){
                count++;
            }
            x++;
        }
        return count;
    }
};
