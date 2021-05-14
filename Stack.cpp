#include "stack.h"

void Stack::push(int param1)
{
    q2.push(param1);
    currentSize++;
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    queue<int> q= q1;
    q1=q2;
    q2=q;
}

void Stack::pop()
{
  if(q1.empty())
    return;
  q1.pop();
  currentSize--;
}

int Stack::top()
{
    if(q1.empty())
        return -1;
    return q1.front();
}

int Stack::size()
{
    return currentSize;
}