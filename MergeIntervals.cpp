/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool comp(Interval i1, Interval i2){
     return i1.start < i2.start;
 }
 
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
    newInterval = Interval(min(newInterval.start, newInterval.end), max(newInterval.start, newInterval.end));
    bool intersect = false;
    vector<Interval> result;
    
    for(int i = 0; i < intervals.size(); ++i) {
        
        if(newInterval.start >= intervals[i].start && newInterval.end <= intervals[i].end) {
            result = intervals;
            intersect = true;
            break;
        }
        else if(newInterval.start < intervals[i].start && newInterval.end > intervals[i].end) {
            
        }
        else if((newInterval.end >= intervals[i].start && newInterval.start <= intervals[i].start) || (newInterval.start <= intervals[i].end && newInterval.end >= intervals[i].end)) {
 
            newInterval = Interval(min(intervals[i].start, newInterval.start), max(intervals[i].end, newInterval.end));
        }
        else if (newInterval.end < intervals[i].start && !intersect) {
            result.push_back(newInterval);
            result.push_back(intervals[i]);
            intersect = true;
        }
        else {
            result.push_back(intervals[i]);
        }
        
    }
    if(!intersect) {
        result.push_back(newInterval);
    }
    return result;
}
