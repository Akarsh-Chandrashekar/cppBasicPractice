#include<iostream>
#include<list>

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

int main()
{
  
  int myints[] = {1,2,3,4,5,6,7,8,9};
  list<int> one(myints,myints + sizeof(myints) / sizeof(int));
  auto k= splitChunks(one,2);
  
}