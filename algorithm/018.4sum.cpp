//
// Created by cloudy064 on 2018/6/22.
//


#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include "common.h"

using namespace std;

/// Solution for https://leetcode-cn.com/problems/4sum/description/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 4) return {};

        map<int, int> num_count;
        for (int i = 0; i < len; ++i) {
            int num = nums[i];
            auto it = num_count.find(num);
            if (it != num_count.end()) {
                it->second += 1;
            } else {
                num_count[num] = 1;
            }
        }

        map<int, vector< vector<int> > > two_sums;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 1; ++i) {
            int first = nums[i];
            for (int j = i + 1; j < len; ++j) {
                int second = nums[j];
                int sum = first + second;
                auto it = two_sums.find(sum);
                if (it != two_sums.end()) {
                    it->second.push_back({first, second});
                } else {
                    vector<vector<int>> vec;
                    vec.push_back({first, second});
                    two_sums[sum] = vec;
                }

                for (++j; (j < len) && (nums[j] == second); ++j);
                --j;
            }

            for (++i; (i < len - 1) && (nums[i] == first); ++i);
            --i;
        }

        map<int, int> num_occur;
        set<int> parsed;
        set< vector<int> > result_set;
        for (auto it_a = two_sums.begin(); it_a != two_sums.end(); ++it_a) {
            int first = it_a->first;

            if (parsed.find(first) != parsed.end()) continue;

            parsed.insert(first);
            auto it_b = two_sums.find(target - first);
            if (it_b == two_sums.end()) continue;

            parsed.insert(target-first);
            auto& vav = it_a->second;
            auto& vbv = it_b->second;

            for (int i = 0; i < vav.size(); ++i) {
                auto& va = vav[i];
                for (int j = 0; j < vbv.size(); ++j) {
                    num_occur.clear();
                    auto& vb = vbv[j];
                    bool valid = true;
                    auto it = num_occur.find(va[0]);
                    if (it != num_occur.end()) {
                        it->second += 1;
                    } else {
                        num_occur[va[0]] = 1;
                    }

                    it = num_occur.find(va[1]);
                    if (it != num_occur.end()) {
                        it->second += 1;
                    } else {
                        num_occur[va[1]] = 1;
                    }

                    it = num_occur.find(vb[0]);
                    if (it != num_occur.end()) {
                        it->second += 1;
                    } else {
                        num_occur[vb[0]] = 1;
                    }

                    it = num_occur.find(vb[1]);
                    if (it != num_occur.end()) {
                        it->second += 1;
                    } else {
                        num_occur[vb[1]] = 1;
                    }

                    vector<int> temp;
                    for (it = num_occur.begin(); it != num_occur.end(); ++it) {
                        if (it->second > num_count[it->first]) {
                            valid = false;
                            break;
                        }

                        temp.insert(temp.end(), it->second, it->first);
                    }

                    if (valid) {
                        result_set.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> result;
        for (auto it = result_set.begin(); it != result_set.end(); ++it) {
            result.push_back(*it);
        }

        return result;
    }
};

class Test018Solution : public ::testing::Test {
public:
    Solution sln;
};

TEST_F(Test018Solution, t1)
{
    vector<int> v = {1,2,3,4,5};
    int target = 14;
    auto result = sln.fourSum(v, target);
    char c = 'c';
}


GTEST_MAIN