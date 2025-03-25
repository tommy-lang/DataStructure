#include <iostream>
#include <stack>

int factorial_iter(int n)
{
    std::stack<int> stk;
    int result = 1;

    // 将 1 到 n 依次入栈
    for (int i = 1; i <= n; i++)
    {
        stk.push(i);
    }

    // 依次弹出栈顶元素，并计算阶乘
    while (!stk.empty())
    {
        result =result* stk.top();
        stk.pop();
    }

    return result;
}

int main()
{
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Factorial of " << n << " is: " << factorial_iter(n) <<std:: endl;
    return 0;
}
