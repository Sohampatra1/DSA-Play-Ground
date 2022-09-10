class Solution final {
public:
    std::vector<int> findRightInterval(const std::vector<std::vector<int>>& intervals) const {
        std::vector<int> response;
        std::map<int, int> startingTimes;
        std::map<int, int>::iterator j;

        for (int i = 0; i < intervals.size(); ++i) {
            startingTimes[intervals[i][0]] = i;
        }

        for (int i = 0; i < intervals.size(); ++i) {
            j = startingTimes.lower_bound(intervals[i][1]);

            if (j != startingTimes.end()) {
                response.push_back(j->second);
            } else {
                response.push_back(-1);
            }
        }

        return response;
    }
};
