class TwoSum {
private:
unordered_map<int, int> um;

public:
    // Add the number to an internal data structure.
	void add(int number) {
        um[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(unordered_map<int, int>::const_iterator it = um.begin(); it != um.end(); it++){
	        int t = value - it->first;
	        if(t == it->first){
	            if(it->second >= 2) return true;
	        }
	        else if(um.find(t) != um.end()) return true;
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
