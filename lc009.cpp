class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int num = 1;
    	while (x / num >= 10) {
    		num = num * 10;
    	}
    	while (x > 0) {
    		if (x % 10 != x / num) {
    			return false;
    		}
    		else {
    			x = (x - x / num * num) / 10;
    			num = num / 100;
    		}
    	}
    	return true;
    }
};
