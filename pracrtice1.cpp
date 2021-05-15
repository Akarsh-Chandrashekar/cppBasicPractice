#include<iostream>
#include<list>
#include <stack>
#include <vector>
#include <queue>
#include "stack.h"

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

class Queue
{
  public:
  void push(int);
  void pop();
  Queue() : cnt(0){};
  private:
  std::stack<int> s1;
  std::stack<int> s2;
  int cnt;

};

void Queue::push(int a)
{
    if(s1.empty())
    {
        s1.push(a);
        cnt++;
    }
    else
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(a);
        cnt++;
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
}

void Queue::pop()
{
    if(!s1.empty())
    {
        s1.pop();
    }
}

class stackMax
{
    public:
    void push(int);
    void pop();
    int getMax();
    private:
    stack<int> st;
    int max;
};

void stackMax::push(int item)
{
    if(st.empty())
    {
        st.push(item);
        max=item;
    }
    else
    {
        if(item<=max)
         st.push(item);
        if(item>max)
        {
            st.push((2*item)-max);
            max=item;
        }
    }
}

void stackMax::pop()
{
    if(st.top()<=max)
    {
        st.pop();
    }
    else if(st.top()>max)
    {
        max=(2*max-(st.top()));
        st.pop();
    }
}

void reverseSTack(stack<int> &a)
{
    stack<int> temp;
    while(!a.empty())
    {
      temp.push(a.top());
      a.pop();
    }
    swap(a,temp);
}

 void reverseQueue(queue<int> &a)
 {
     stack<int> temp;
     while(!a.empty())
     {
         temp.push(a.front());
         a.pop();
     }
     while(!temp.empty())
     {
         a.push(temp.top());
         temp.pop();
     }
 }

template <typename T>
class stackFromList
{
public:
stackFromList(list<T> a)
{
    lst.assign(a.begin(),a.end());
}
T top();
void push(T a);
void pop();
private:
list<T> lst;
};

template <typename T>
void stackFromList<T>::push(T a)
{
    lst.push_front(a);
}

template <typename T>
void stackFromList<T>::pop()
{
    if(lst.empty())
    {
       throw std::out_of_range("empty stack");
    }
    else
    {
        lst.pop_front();
    }
}

template <typename T>
T stackFromList<T>::top()
{
 auto it=lst.cbegin();
 return *it;
}

int main()
{
char myint[]={'e','d','c','b','a'};
list<char> l1(myint,myint+5);
stackFromList<char> sl(l1);
char al=sl.top();
sl.push('i');
sl.push('l');
sl.pop();
char bl=sl.top();
int k;
}