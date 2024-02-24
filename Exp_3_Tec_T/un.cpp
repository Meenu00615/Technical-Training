#include<iostream>
#include<vector>
using namespace std;

// In this code, we are trying to find the maximum equal sum of every stack
// Removal of the top/head stack element is allowed
int maxSum(vector<int> & stack1, vector<int> & stack2, vector<int> & stack3)
{
    int sum1 = 0, sum2 = 0, sum3 = 0;
    // checking the initial sum of stack 1
    for(unsigned int i = 0; i < stack1.size(); i++)
        sum1 += stack1[i];

    for(unsigned int i = 0; i < stack2.size(); i++)
        sum2 += stack2[i];

    for(unsigned int i = 0; i < stack3.size(); i++)
        sum3 += stack3[i];

    unsigned int top1 = 0, top2 = 0, top3 = 0;
    while(true) {
        // There condition could be like that a stack is empty
        // Defining first element as the top of the stack
        // for the empty stack
        if(top1 == stack1.size() || top2 == stack2.size() || top3 == stack3.size())
            return 0;
        // Here we are checking if stacks are similar or not.
        // By removing the head element
        if(sum1 == sum2 && sum2 == sum3)
            return sum1;
        if(sum1 >= sum2 && sum1 >= sum3)
            sum1 -= stack1[top1++];
        else if(sum2 >= sum1 && sum2 >= sum3)
            sum2 -= stack2[top2++];
        else if(sum3 >= sum2 && sum3 >= sum1)
            sum3 -= stack3[top3++];

        // Managing the stacks heights as needed
        while(sum1 != sum2 || sum2 != sum3) {
            int maxSum = max(sum1, max(sum2, sum3));
            if(maxSum == sum1)
                sum1 -= stack1[top1++];
            else if(maxSum == sum2)
                sum2 -= stack2[top2++];
            else
                sum3 -= stack3[top3++];
        }
    }
}

int main()
{
    vector<int> stack1, stack2, stack3;
    int n1, n2, n3, element;

    cout << "Enter Stack[1]'s Element:";
    cin >> n1;
    cout << "Enter the elements of stack:";
    for(int i = 0; i < n1; ++i) {
        cout << "Enter element " << i + 1 << ":";
        cin >> element;
        stack1.push_back(element);
    }

    cout << "Enter Stack[2]'s Element:";
    cin >> n2;
    cout << "Enter the elements of stack[2]:";
    for(int i = 0; i < n2; ++i) {
        cout << "Enter element " << i + 1 << ":";
        cin >> element;
        stack2.push_back(element);
    }

    cout << "Enter Stack[3]'s Element:";
    cin >> n3;
    cout << "Enter the elements of stack[3]:";
    for(int i = 0; i < n3; ++i) {
        cout << "Enter element " << i + 1 << ":";
        cin >> element;
        stack3.push_back(element);
    }

    cout << "Maximum possible common height: " << maxSum(stack1, stack2, stack3) << endl;
    return 0;
}
