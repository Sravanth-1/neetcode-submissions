/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * };
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        for (auto &it : intervals) {
            mp[it.start]++;
            mp[it.end]--;
        }

        int rooms = 0;
        int maxRooms = 0;

        for (auto &it : mp) {
            rooms += it.second;
            maxRooms = max(maxRooms, rooms);
        }

        return maxRooms;
    }
};