#include <queue>

using namespace std;

class Stack
{
 public:
 Stack () : currentSize(0) {}
 void push(int);
 void pop();
 int top();
 int size();
 private:
 queue<int> q1;
 queue<int> q2;
 int currentSize;
};