//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		struct Node{
        char data;
        int freq;
        Node* left;
        Node* right;
        Node(char data, int freq) {
            this->data = data;
            this->freq = freq;
            left=right=nullptr;
        }
    };
    struct compare {
        bool operator()(Node* l, Node* r) {
            return l->freq > r->freq;
        }
    };
    void preorder(Node* root, string code) {
        if(root==nullptr)return;
        if(!root->left && !root->right) {
            cout<<code<<" ";
        }
        preorder(root->left, code+"0");
        preorder(root->right, code+"1");
    }
    Node* buildHuffmanTree(string S, vector<int>& f) {
        int n = S.size();
        priority_queue<Node*, vector<Node*>, compare> pq;
        for (int i = 0; i < n; i++) {
            pq.push(new Node(S[i], f[i]));
        }
        while (pq.size() > 1) {
            Node* left = pq.top();
            pq.pop();
            Node* right = pq.top();
            pq.pop();
            Node* internal = new Node('$', left->freq + right->freq);
            internal->left = left;
            internal->right = right;
            pq.push(internal);
        }
        return pq.top();
    }
    vector<string> huffmanCodes(string S, vector<int>& f, int N) {
        Node* root = buildHuffmanTree(S, f);
        vector<string> codes;
        preorderHelper(root, "", codes);
        return codes;
    }
    void preorderHelper(Node* root, string code, vector<string>& codes) {
        if (root == nullptr) return;
        if (!root->left && !root->right) {
            codes.push_back(code);
        }
        preorderHelper(root->left, code + "0", codes);
        preorderHelper(root->right, code + "1", codes);
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends