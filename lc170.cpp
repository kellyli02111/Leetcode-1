class TwoSum {
public:
unordered_map<int, int> um;

    // Add the number to an internal data structure.
	void add(int number) {
	    if(um.find(number) != um.end()){
	        um[number]++;
	    }
	    else{
	        um[number] = 1;
	    }
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto it = um.begin(); it != um.end(); it++){
	        int t = value - it->first;
	        if(t == it->first){
	            if(it->second >= 2) return true;
	        }
	        else if(um.find(t) != um.end()) return true;
	    }
	    return false;
	}
};
