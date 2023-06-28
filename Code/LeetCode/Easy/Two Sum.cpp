#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> myMap;
        int s = nums.size();

        for (int i = 0; i < s; i++){
            int diff = target - nums[i];
            if (myMap.find(diff) != myMap.end()){
                return {myMap[diff], i};
            }
            else{
                myMap[nums[i]] = i;
            }
        }
        return {};
    }
};