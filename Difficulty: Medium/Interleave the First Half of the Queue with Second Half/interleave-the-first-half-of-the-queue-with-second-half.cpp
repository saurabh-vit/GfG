class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n = q.size();
        if (n % 2 != 0) return; // safety check
    
        queue<int> firstHalf;
    
        // Step 1: Store first half in another queue
        for (int i = 0; i < n / 2; i++) {
            firstHalf.push(q.front());
            q.pop();
        }
    
        // Step 2: Interleave first half with second half
        while (!firstHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();
    
            q.push(q.front());
            q.pop();
        }
    }
};