class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        vector<int> freq(26, 0);
    queue<char> q;
    string result = "";

    for (char ch : s) {
        freq[ch - 'a']++;
        q.push(ch);

        // Remove repeating characters from front
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // Append answer for current prefix
        if (q.empty())
            result += '#';
        else
            result += q.front();
    }

    return result;
    }
};