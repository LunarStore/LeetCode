# N刷力扣前100
[我的力扣主页](https://leetcode.cn/u/vvizardly-haibthfp/)

力扣积累刷题：503

上次刷力扣应该是在2023年的暑假（7-8月份的时候）

本次再再刷力扣是因为一次实习岗的面试，虽然是实习岗，但是本来聊天的时候聊的好好的，突然面试官出了一道力扣题目，用栈实现队列，对于刷过算法的人来说，这不有手就行吗？可是我就是在关键的时候掉了链子，然后手斯阶段之后，面试官直接来了一句，今天的面试到此结束。这真的是耻辱！！！

## 2023.12.9 -- [21-25]

备注：使用分治再实现一遍23题。

## 2023.12.11 -- [26-30]

第30题超时，未通过leetcode所有测试。。。

## 2023.12.15 -- [31-33]

鸽了几天，本来来想把6.5840的实验了结再干leetcode的的，但是调试太难了，后面再动态调整吧。今天象征性写了3题，32题超时，需要二维dp降维优化，先mark一下，以后改。

## 2023.12.16 -- [34-35]

1. [34-35]二分。

## 2023.12.17 -- [36-37]

1. [36-37]回溯（解数独），超时优化后通过。

## 2023.12.18 -- [38-40]

1. [38]双指针+滑动窗口

2. [39-40]回溯

## 2023.12.19 -- [41-43]

1. [43]代码实现两数相乘，比较有意思的一道模拟题

## 2024.2.15 -- [51-59]

1. 56、57两到区间合并与插入的算法，在LevelDB中有工程运用，比如查找一层SST文件的重合算法。

## 2024.2.18 -- [60-79]

对于78题，思考一下以下代码的含义。和78的题解有什么区别？？？

```cpp
class Solution {
    void backTrace(int index, vector<int> &nums, vector<int> &temp, vector<vector<int>> &out){
        if(index >= nums.size()){
            out.push_back(temp);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            temp.push_back(nums[i]);
            backTrace(i + 1, nums, temp, out);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        backTrace(0, nums, temp, res);
        return res;
    }
};
```

解释一下72题的插入和删除操作在动态规划中的具体含义。
