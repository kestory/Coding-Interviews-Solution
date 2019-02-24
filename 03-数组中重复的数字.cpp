// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
//        duplication: (输出) 数组中的一个重复的数字
// 返回值:
//        true  - 输入有效，并且数组中存在重复的数字
//        false - 输入无效，或者数组中没有重复的数字
//排序法O(nlogn)
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        sort(numbers, numbers + length);
        for (int i = 0; i < length - 1; ++i)
            if (numbers[i] == numbers[i + 1]) {
                *duplication = numbers[i];
                return true;
            }
        return false;
    }
};

//count()用来查找set中某个某个键值出现的次数。由于一个键值在set只可能出现0或1次，这样就成了判断某一键值是否在set出现过
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        set<int> s;
        for (int i = 0; i < length; i++)
        {
            if (s.count(numbers[i]) != 0) //当前元素已存在set中
            {
                *duplication = numbers[i];
                return true;
            }
            else
                s.insert(numbers[i]);
        }
        return false;
    }
};

//时O(n) 空O(n)
//利用hash表的思想，但用一个nbit的数组来存放判断即可
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {

        bool isDup = false;
        bool flags[length];
        memset(flags, false, sizeof(flags));
        for (int i = 0; i < length; ++i)
        {
            if (flags[numbers[i]] == true)
            {
                *duplication = numbers[i];
                isDup = true;
                break;
            }
            else
                flags[numbers[i]] = true;
        }

        return isDup;
    }
};

//书上的方法
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        for (int i = 0; i < length; ++i)
        {
            if (numbers[i] != i) {
                if (numbers[i] != numbers[numbers[i]]) {
                    int t = numbers[i];
                    numbers[i] = numbers[t];//注意这里复用numbers[numbers[i]]会有问题
                    numbers[t] = t;
                }
                else {
                    *duplication = numbers[i];
                    return true;
                }
            }
            // else
            //     continue;
        }
        return false;

    }
};




是输出任意一个重复数字即可，若是要求输出全部重复数字呢？
如果数据范围不是0~n - 1而是任意范围呢？
若要输出重复的次数呢？
