class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        int i = 0;
        for(; i < citations.size(); i++){
            if(citations[i] < i + 1){
                return i;
            }
        }
        return i;
    }
};
