#include <iostream>
#include <unordered_map>
#include <forward_list>
#include <vector>
#include <unordered_set>

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

void pairInArray(int arraySize,int sum,const int arr[],pair<int,int> &paramPair)
{
    unordered_set<int> set;
    for(int i=0;i<arraySize;i++)
    {
        int temp=sum-arr[i];
        auto it=set.find(temp);
        if(it!=set.end())
        {
          paramPair = make_pair((arr[i]),(*it));
          return;
        }
        set.insert(arr[i]);
    }

}

std::pair<pair<int,int>,pair<int,int>> equalSum(int arr[],int n)
{
 unordered_map <int,std::pair<int,int>> map;
 for(int i=0;i<n;i++)
 {
     for(int j=i+1;j<n;j++)
     {
        int sum=arr[i]+arr[j];
        if(map.find(sum)!=map.end())
        {
            pair<int,int> temp1=make_pair(arr[i],arr[j]);
            std::pair<pair<int,int>,pair<int,int>> Temp = make_pair((map.find(sum)->second),temp1);
            return Temp;
        }
        map[sum]=make_pair(arr[i],arr[j]);
     }
 }
}

int main()
{
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n  =  sizeof arr / sizeof arr[0];
    std::pair<pair<int,int>,pair<int,int>> sumEle=equalSum(arr, n);
    cout<<"{"<<sumEle.first.first<<","<<sumEle.first.second<<","<<sumEle.second.first<<","<<sumEle.second.second<<"}"<<endl;
}