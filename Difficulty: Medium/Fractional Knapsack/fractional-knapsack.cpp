//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    struct Item {
        int value;
        int weight;
        double ratio;
        
        Item(int v, int w) {
            value = v;
            weight = w;
            ratio = (double)v / w; // Calculate value-to-weight ratio
        }
    };
    
    // Function to get the maximum total value in the knapsack
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<Item> items;
        
        // Fill the items array with value, weight, and ratio
        for (int i = 0; i < n; i++) {
            items.push_back(Item(val[i], wt[i]));
        }
        
        // Sort items based on value-to-weight ratio using a lambda function
        sort(items.begin(), items.end(), [](Item a, Item b) {
            return a.ratio > b.ratio;
        });
        
        double totalValue = 0.0;
        int currentWeight = 0;
        
        // Loop through the items and add them to the knapsack
        for (int i = 0; i < n; i++) {
            if (currentWeight + items[i].weight <= capacity) {
                // If the whole item can be added to the knapsack
                currentWeight += items[i].weight;
                totalValue += items[i].value;
            } else {
                // If only part of the item can be added
                int remainingWeight = capacity - currentWeight;
                totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
                break;  // Knapsack is full
            }
        }
        
        return totalValue;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends