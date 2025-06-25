class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        unordered_map<char, int> charFreq;
        for (char c : s)
            charFreq[c]++;
        unordered_map<int, int> freqCount;
        for (auto& entry : charFreq)
            freqCount[entry.second]++;
        if (freqCount.size() == 1)
            return true;
        if (freqCount.size() > 2)
            return false;
        auto it = freqCount.begin();
        int f1 = it->first, c1 = it->second;
        it++;
        int f2 = it->first, c2 = it->second;
        if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1))
            return true;
        if ((abs(f1 - f2) == 1) && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1)))
            return true;
    
        return false;
    }
};