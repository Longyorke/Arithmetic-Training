// leetcode209.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//给定一个含有 n 个正整数的数组和一个正整数 target 。
//
//找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl + 1, ..., numsr - 1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。


#include <iostream>
#include <vector>

class Solution {
public:
    //暴力解法
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int subSum = 0;
        int subSize = 0;
        int result = INT32_MAX;//最终结果设为int最大值，利于与subSize比大小
        for (int i = 0; i < nums.size(); i++)//遍历每个元素
        {
            for (int j = i; j < nums.size(); j++)//指定结尾
            {
                subSum = subSum + nums[j];
                if (subSum >= target)//发现子数组元素之和大于目标则更新result
                {
                    subSize = j - i + 1;//子数组长度
                    result = result > subSize ? subSize : result;//取最小数组长度
                    break;//结束子数组相加计算
                }
            }
            subSum = 0;//清空子数组之和
        }
        return result = result < INT32_MAX ? result : 0;//如果没有找到最小数组长度就返回0，否则返回最小数组长度

    }

    //滑动窗口
    
    int minSubArrayLenSlidingWindow(int target, std::vector<int>& nums) {
        int leftIndex = 0;
        int rightIndex = 0;
        int subSum = 0;
        int subSize = 0;
        int result = INT32_MAX;
        for (rightIndex = 0; rightIndex < nums.size(); rightIndex++)
        {
            subSum = subSum + nums[rightIndex];//将滑动窗口右指针右移
            while (subSum >= target)//子数组和大于目标
            {
                subSize = rightIndex - leftIndex + 1;//此时子数组长度
                result = result > subSize ? subSize : result;//保留最小的数组长度
                subSum = subSum - nums[leftIndex];//左指针右移动
                leftIndex++;

            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    //测试数据
    int target = 11;
    std::vector<int> nums = {1,1,1,1,1,1,1,1};
    
    Solution mySolution;
    int result = mySolution.minSubArrayLen(target, nums);
    std::cout << "暴力解法 子数组长度为：" << result <<std::endl;

    int result = mySolution.minSubArrayLenSlidingWindow(target, nums);
    std::cout << "滑动窗口法 子数组长度为：" << result << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
