#include<iostream>
#include<list>
#include <stack>
#include <vector>
#include <queue>


using namespace std;

std::list<int> splitList(const std::list<int> &lstorigin)
{
    auto it=lstorigin.begin();
    for(int i=0;i<(lstorigin.size()/2);i++)
    {
        it++;
    }
    std::list<int> temp(lstorigin.begin(),it);
    return temp;
}

list<list<int>> splitChunks(const list<int> &lstPar,int n)
{
   auto beginIter=lstPar.begin();
   list<list<int>> tempRet;
   int noChunks=int(lstPar.size())/n;
   for(int i=0;i<noChunks;i++)
   {
      auto limitIter=beginIter;
      advance(limitIter,n);
      // while creating temp limititer element is not added temp contains only  previous element of *limititer
      list<int> temp(beginIter,limitIter);  
      tempRet.push_back(temp);
      advance(beginIter,n);
   }
   cout<<lstPar.size();
   if(lstPar.size()>(n*noChunks))
   {
       list<int> temp(beginIter,lstPar.end());
       tempRet.push_back(temp);
       int y=1;
   }
   return tempRet;
} 

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
int main()
{
  
Stack s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);

s.pop();
s.pop();
s.pop();
   
}