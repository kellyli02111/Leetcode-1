class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
    	reverse(num2.begin(), num2.end());
    	string res = "";
    	int n = num2.size();
    	for (int i = 0; i < n; i++) {
    		string temp = multiply(num1, (num2[i] - '0'));
    		if(temp != "0"){
        		for (int j = 0; j < i; j++) {
        			temp = '0' + temp;
        		}
    		}
    		res = addStr(res, temp);
    	}
    	reverse(res.begin(), res.end());
    	return res;
    }
        
    string addStr(string str1, string str2) {
    	int n1 = str1.size();
    	int n2 = str2.size();
    	int carry = 0;
    	string res = "";
    	for (int i = 0; (i < n1 || i < n2 || carry); i++) {
    		int temp = 0;
    		if (i < n1) {
    			temp = temp + (str1[i] - '0');
    		}
    		if (i < n2) {
    			temp = temp + (str2[i] - '0');
    		}
    		temp = temp + carry;
    		char bit = '0' + temp % 10;
    		carry = temp / 10;
    		res = res + bit;
    	}
    	return res;
    }
    
    string multiply(string input, int num) {
        if(num == 0){
            return "0";
        }
    	int carry = 0;
    	int n = input.size();
    	string res = "";
    	for (int i = 0; i < n; i++) {
    		char bit = '0' + ((input[i] - '0') * num + carry) % 10;
    		res = res + bit;
    		carry = ((input[i] -'0') * num + carry) / 10;
    	}
    	if (carry != 0) {
    		char bit = '0' + carry;
    		res = res + bit;
    	}
    	return res;
    }
};
