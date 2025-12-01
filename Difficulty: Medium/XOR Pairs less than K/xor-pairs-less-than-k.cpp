class Solution {
public:
    struct Trie {
        Trie* child[2];
        int cnt;
        Trie() {
            child[0] = child[1] = nullptr;
            cnt = 0;
        }
    };

    Trie* root = new Trie();
    int MAX_BIT = 15; // numbers <= 50000 (2^16)

    void insert(int num) {
        Trie* node = root;
        for (int i = MAX_BIT; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) {
                node->child[bit] = new Trie();
            }
            node = node->child[bit];
            node->cnt++;
        }
    }

    // count numbers y inserted so far such that (x ^ y) < k
    int countLess(int x, int k) {
        Trie* node = root;
        int result = 0;

        for (int i = MAX_BIT; i >= 0; i--) {
            if (!node) break;

            int xb = (x >> i) & 1;
            int kb = (k >> i) & 1;

            if (kb == 1) {
                // Add the entire same-bit branch
                if (node->child[xb]) {
                    result += node->child[xb]->cnt;
                }
                // Move to the opposite bit (where XOR gives 1)
                node = node->child[xb ^ 1];
            } else {
                // Must stay in same-bit branch
                node = node->child[xb];
            }
        }
        return result;
    }

    int cntPairs(vector<int>& arr, int k) {
        int ans = 0;

        for (int x : arr) {
            ans += countLess(x, k);
            insert(x);
        }

        return ans;
    }
};