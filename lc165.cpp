class Solution {
public:
    int compareVersion(string version1, string version2) {
        for(int begin1 = 0, begin2 = 0; begin1 < version1.size() || begin2 < version2.size(); begin1++, begin2++){
            int len1 = give(version1, begin1);
            int len2 = give(version2, begin2);
            if(len1 > len2) return 1;
            if(len1 < len2) return -1;
            for(int i = 0; i < len1; i++){
                if(version1[begin1] > version2[begin2]) return 1;
                if(version1[begin1] < version2[begin2]) return -1;
                begin1++;
                begin2++;
            }
        }
        return 0;
    }
    
    int give(string &s, int& begin){
        for(; begin < s.size() && s[begin] == '0'; begin++);
        int end = begin;
        for(; end < s.size() && s[end] != '.'; end++);
        return end - begin;
    }
};
