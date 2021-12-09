#include <iostream>
#include <vector>

using namespace std;
// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 子数组 是数组中的一个连续部分。
// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。


int maxSubArray(vector<int>& nums) {
  int size = nums.size();
  if (size == 0) {
    return 0;
  }
  if (size == 1) {
    return nums[0];
  }

  // 假设dp[i]表示以nums[i]为结尾的子串的最大值
  // 那么以nums[i+1]为结尾的子串，其最大值是多少呢？
  // 有如下两种情况：
  // 1. dp[i+1] = dp[i] + nums[i+1]; nums[i+1]加入到这个子串里
  // 2. dp[i+1] = nums[i+1]; nums[i+1]单独成一个子串
  vector<int> dp(size);
  int max = nums[0];
  dp[0] = nums[0];

  for (int i = 1; i < size; i++) {
    dp[i] = dp[i-1] + nums[i] > nums[i] ? dp[i-1] + nums[i] : nums[i];
    if (max < dp[i]) {
      max = dp[i];
    }
  }
  return max;
}

int main() {
}