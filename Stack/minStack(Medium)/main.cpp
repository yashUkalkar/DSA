#include <iostream>
#include <stack>
using namespace std;

//* Link - https://leetcode.com/problems/min-stack/

class MinStack {
   private:
    stack<int> base_stack;
    stack<int> min_stack;

   public:
    MinStack() {}

    void push(int val) {
        this->base_stack.push(val);

        if (min_stack.empty() || (val < min_stack.top()))
            this->min_stack.push(val);
        else
            this->min_stack.push(min_stack.top());
    }

    void pop() {
        this->base_stack.pop();
        this->min_stack.pop();
    }

    int top() { return this->base_stack.top(); }

    int getMin() { return this->min_stack.top(); }
};

int main() {
    MinStack* obj = new MinStack();

    obj->push(10);
    obj->push(1);
    obj->push(5);
    obj->push(7);

    obj->pop();

    cout << obj->top() << endl;

    cout << obj->getMin() << endl;

    return 0;
}