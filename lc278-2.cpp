//non-recursive:
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        bool resultFound = false;
        while(true){
            int half = start + (end - start)/2;
            bool isBad = isBadVersion(half);
            if(isBad){
                if(half - start > 1){
                    end = half;
                }
                else{
                    if(isBadVersion(start)){
                        return start;
                    }
                    else{
                        return half;
                    }
                }
            }
            else{
                if(end - half > 1){
                    start = half;
                }
                else{
                    return end;
                }
            }
        }
    }
};
