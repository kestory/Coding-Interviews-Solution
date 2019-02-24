问清楚面试官，是在源字符串上替换（保证字符串后有足够多空余内存），还是创建新字符串

//先计算空格数量，在一个新数组从前向后安置好再复制回去
class Solution {
public:
    void replaceSpace(char *str, int length) {
        int num_of_space = 0;
        for (int i = 0; i < length; ++i)
            if (str[i] == ' ')
                num_of_space++;

        int new_length = num_of_space * 2 + length;

        char *nstr = new char[new_length];
        for (int i = 0,  j = 0; (j < length) && (i < new_length); ++i, ++j)
        {
            if (str[j] == ' ') {
                nstr[i] = '%';
                nstr[i + 1] = '2';
                nstr[i + 2] = '0';
                i += 2;

            }
            else
                nstr[i] = str[j];
        }
        // D(str)D(nstr)
        for (int i = 0; i < new_length; ++i)
            str[i] = nstr[i];


    }
};



//在原字符串上从后往前推进
#include <iostream>
using namespace std;
#define D(x) cout<<#x<<"="<<x<<endl;
#define __tmain main

class Solution {
public:
    void replaceSpace(char *str, int length) {
        int original_length = 0;
        int num_of_space = 0;
        int i = 0;
        while (str[i] != '\0') {
            original_length++;
            if (str[i] == ' ')
                num_of_space++;
            i++;
        }
        int new_length = num_of_space * 2 + original_length;
//      D(original_length)D(num_of_space)D(new_length)
        for (int j = new_length, i = original_length; i >= 0 && j >= 0; --i, --j) {
            if (str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j] = '%';
            }
            else
                str[j] = str[i];
        }
    }
};

int __tmain( )
{
    char str[13] = "We Are Happy";

    Solution solu;
    solu.replaceSpace(str, 12);
    cout << str << endl;

    return 0;
}



//书上源码，带测试
#include <cstdio>
#include <cstring>

void replaceSpace(char *str, int length) {
    int original_length = 0;
    int num_of_space = 0;
    int i = 0;
    while (str[i] != '\0') {
        original_length++;
        if (str[i] == ' ')
            num_of_space++;
        i++;
    }
    int new_length = num_of_space * 2 + original_length;
//      D(original_length)D(num_of_space)D(new_length)
    for (int j = new_length, i = original_length; i >= 0 && j >= 0; --i, --j) {
        if (str[i] == ' ') {
            str[j--] = '0';
            str[j--] = '2';
            str[j] = '%';
        }
        else
            str[j] = str[i];
    }
}



// ====================测试代码====================
void Test(char* testName, char str[], int length, char expected[])
{
    if (testName != NULL)
        printf("%s begins: ", testName);

    replaceSpace(str, length);

    if (expected == NULL && str == NULL)
        printf("passed.\n");
    else if (expected == NULL && str != NULL)
        printf("failed.\n");
    else if (strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, length, "hello%20%20world");
}

// 传入NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();//没搞
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
