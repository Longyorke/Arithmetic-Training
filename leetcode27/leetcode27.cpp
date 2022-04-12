// leetcode27.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，
//如果目标值存在返回下标，否则返回 - 1。





#include <iostream>
#include <vector>


class Solution {
public:
    //暴力破解
    int removeElement(std::vector<int>& nums, int val) {
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++)
        {
            if (nums[i] == val)//如果找到对应元素
            {
                for (int j = i + 1; j < numsSize; j++)
                {
                    nums[j - 1] = nums[j];//移动后面元素
                }
                i--;//下标前移，结束后再移回来，相当于没有移动
                numsSize--;//每移动一次就相当于数组长度-1
            }
        }
        return numsSize;
    }
    //快慢指针
    int removeElementFastSlowIndex(std::vector<int>& nums, int val) {
        int numsSize = nums.size();
        int fastIndex = 0;
        int slowIndex = 0;
        // if (!numsSize)
        // {
        //     return false;
        // }
        while (fastIndex < numsSize)//如果没有结束
        {
            if (nums[fastIndex] == val)//如果快指针指向的元素与我们要删除的元素相同
            {
                fastIndex++;
            }
            else
            {
                nums[slowIndex] = nums[fastIndex];
                fastIndex++;
                slowIndex++;
            }
        }
        return slowIndex;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    std::vector<int> nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int val = 2;
    Solution mySolution;
    int size = mySolution.removeElement(nums, val);
    std::cout << "暴力破解获得的数组长度：" << size << std::endl;

    size = mySolution.removeElementFastSlowIndex(nums, val);
    std::cout << "快慢指针获得的数组长度：" << size << std::endl;

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
