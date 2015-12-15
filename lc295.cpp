class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if(maxHeap.size() == minHeap.size()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        if(!minHeap.empty() && minHeap.top() < maxHeap.top()){
            minHeap.push(maxHeap.top());
            maxHeap.push(minHeap.top());
            minHeap.pop();
            maxHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(maxHeap.empty() && minHeap.empty()) return 0.0;
        if(maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
