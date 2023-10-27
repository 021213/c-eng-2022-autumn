#include<iostream>
#include<vector>

class NumArray {
private:
    std::vector<int> nums;
    std::vector<int> rsq;
    //nums = {    -2,  0,  3, -5,  2, -1 }
    //rsq  = { 0, -2, -2,  1, -4, -2, -3 }
    void initRsq(std::vector<int>& nums)
    {
        rsq.push_back(0);
        for (int i = 0; i < nums.size(); ++i)
        {
            rsq.push_back(rsq[rsq.size() - 1] + nums[i]);
        }
    }
public:
    NumArray(std::vector<int>& nums)
    {
        this->nums = nums;
        initRsq(nums);
    }

    int sumRange(int left, int right)
    {
        return this->rsq[right + 1] - this->rsq[left];
    }

    int get(int index)
    {
        return this->rsq[index + 1] - this->rsq[index];
        //return nums[index];
    }

    int size()
    {
        return rsq.size() - 1;
    }

    void update(int left, int right, int x)
    {
        for (int i = left; i <= right; ++i)
        {
            nums[i] = x;
        }

        //nums = {    -2,  0,  3, -5,  2, -1 }
        //rsq  = { 0, -2, -2,  1, -4, -2, -3 }

        //nums = {    -2, 10, 10, -5,  2, -1 }
        //rsq  = { 0, -2,  8, 18, 13, 15, 14 }
        //tmp  = 1
   //rsq - tmp = { 0, -2,  8, 18, 13, -3, -4 }

        int tmp = 0;
        for (int i = left + 1; i <= right + 1; ++i)
        {
            tmp = rsq[i];
            rsq[i] = rsq[i - 1] + x;
        }
        for (int i = right + 2; i < rsq.size(); ++i)
        {
            rsq[i] -= tmp;
            rsq[i] += rsq[right + 1];
        }
    }

    void add(int left, int right, int x)
    {
        for (int i = left; i <= right; ++i)
        {
            nums[i] += x;
        }

        //nums = {    -2, 10, 10, -5,  2, -1,  3,  4 }
        //rsq  = { 0, -2,  8, 18, 13, 15, 14, 17, 21 }

        //nums = {    -2, 10, 10, 5,  12, -1, 3, 4 }
        //rsq  = { 0, -2,  8, 18, 23, 35, 34, 37, 41 }

        int tmpx = 0;
        for (int i = left + 1; i <= right + 1; ++i)
        {
            tmpx += x;
            rsq[i] += tmpx;
        }
        for (int i = right + 2; i < rsq.size(); ++i)
        {
            rsq[i] += tmpx;
        }
        
    }

    friend std::ostream& operator<<(std::ostream& stream, NumArray& numArray)
    {
        for (int i = 0; i < numArray.size(); ++i)
        {
            stream << numArray.get(i) << " ";
        }
        return stream;
    }
};

int main(int argc, char* argv[])
{
    /*
	std::vector<int> vect{ -2, 0, 3, -5, 2, -1, 3, 4 };
	NumArray numArray(vect);
	std::cout << numArray.sumRange(0, 2) << std::endl; // return (-2) + 0 + 3 = 1
	std::cout << numArray.sumRange(2, 5) << std::endl; // return 3 + (-5) + 2 + (-1) = -1
	std::cout << numArray.sumRange(0, 5) << std::endl; // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
    std::cout << numArray << std::endl;
    numArray.update(1, 2, 10);
    std::cout << numArray << std::endl;
    numArray.add(3, 4, 10);
    std::cout << numArray << std::endl;
    */

    std::vector<int> vect;
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x = 0;
        std::cin >> x;
        vect.push_back(x);
    }
    NumArray nums(vect);
    std::cout << nums;
    int m = 0;
    std::cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        std::cout << nums.sumRange(a - 1, b - 1) << " ";
    }
    return EXIT_SUCCESS;
}