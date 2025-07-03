
class Solution {
  public:
    bool isBalanced(string& k) {
        // code here
        stack<char> stack;
        unordered_map<char, char> matching = {
            {')','('},
            {']','['},
            {'}','{'}
        };
        for(char c : k){
            if(matching.count(c)){
                if(stack.empty() || stack.top() != matching[c]){
                    return false;
                }
                stack.pop();
            }else{
                stack.push(c);
            }
        }
        return stack.empty();
    }
};