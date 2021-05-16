#include <iostream>
#include <unordered_map>
#include <forward_list>
#include <vector>

using namespace std;

bool ifContainsArray(int arr1[],int arr2[],int m,int n)
{
    unordered_map<int,int> map;
    int size1=m;
    int size2=n;
    for(int i=0;i<size1;i++)
    {
        cout<<"arr1(i)"<<arr1[i]<<endl; 
        map[arr1[i]]=arr1[i];
    }
    for(int i=0;i<size2;i++)
    {
       auto it=map.find(arr2[i]);
        if(it==map.end())
        {
            return false;
        }
    }
    return true;
}

vector<int> intersectionLists(const forward_list<int> &lst1,const forward_list<int> &lst2)
{
    vector<int> temp;
    unordered_map<int,int> map;
    for(auto it=lst1.cbegin();it!=lst1.cend();it++)
    {
        map[*it]=*it;
    }
    for(auto it=lst2.cbegin();it!=lst2.cend();it++)
    {
        auto lst2iter = map.find(*it);
        if(lst2iter!=map.end())
        {
            temp.push_back(lst2iter->second);
        }
    }
    return temp;
}

vector<int> unionLists(const forward_list<int> &lst1,const forward_list<int> &lst2)
{
    vector<int> temp;
    unordered_map<int,int> map;
    for(auto it=lst1.cbegin();it!=lst1.cend();it++)
    {
        map[*it]=*it;
        temp.push_back(*it);
    }
    for(auto it=lst2.cbegin();it!=lst2.cend();it++)
    {
        auto lst2iter = map.find(*it);
        if(lst2iter==map.end())
        {
            temp.push_back(*it);
        }
    }
    return temp;
}

int main()
{
    forward_list<int> l1={1,2,3,4,5,6,7,8};
    forward_list<int> l2={2,5,6,7,0,9,10};

    vector<int> temp=unionLists(l1,l2);
    for(auto it=temp.begin();it!=temp.end();it++)
    {
        cout<<*it<<endl;
    }
}