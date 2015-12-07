//recursion:

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return findBadVersion(1, n);
    }
    int findBadVersion(int lastBegin, int lastEnd) {
        int half = ((long long)lastBegin + (long long)lastEnd) /2;
        bool check = isBadVersion(half);
        if(check){
            cout<<half<<" found"<<endl;
            if(half - lastBegin > 1){
                return findBadVersion(lastBegin, half);
            }
            else{
                if(isBadVersion(lastBegin)){
                    return lastBegin;
                }
                else{
                    return half;
                }
            }
        }
        else{
            cout<<half<<" not found"<<endl;
            if(lastEnd - half > 1){
                return findBadVersion(half, lastEnd);
            }
            else{
                return lastEnd;
            }
        }
    }
};
