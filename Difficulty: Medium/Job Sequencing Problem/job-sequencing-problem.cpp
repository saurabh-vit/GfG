//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    struct Job{
        int id, deadline, profit;
    };
    static bool compare(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        int n = id.size();
        vector<Job> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i].id = id[i];
            jobs[i].deadline = deadline[i];
            jobs[i].profit = profit[i];
        }
        sort(jobs.begin(), jobs.end(), compare);
        vector<bool> slots(n, false);
        int totalJobs = 0, totalProfit = 0;
        for (int i = 0; i < n; i++) {
            for (int j = jobs[i].deadline - 1; j >= 0; j--) {
                if (!slots[j]){
                    slots[j] = true;
                    totalJobs++;
                    totalProfit += jobs[i].profit;
                    break;
                }
            }
        }
        return {totalJobs, totalProfit};
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends