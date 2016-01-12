/* 
 * File:   main.cpp
 * Author: stan
 *
 * Created on December 6, 2014, 12:04 PM
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <unordered_map>
#include<list> //linked list
#include <vector> 
#include <algorithm>  //sort, binary_search
#include <queue>
#include <bits/hashtable.h> // priority_queue
#include <stack>
#include <functional>
#include <unordered_set>
using namespace std;

int main () {
  //1. linked list
    list<char>seq;
    list<char>::iterator it=find(seq.begin(),seq.end(),'c');
    cout<<*it<<endl;
    seq.front(), seq.back(),
    seq.end();
    seq.pop_front();
    seq.push_back('c');
  //2. map
    unordered_map<int,int>a;
    a.find(10);
    
  //3. priority_queue
    int myint[]={10,60,50,20};
    priority_queue<int, vector<int>, greater<int>> third(myint,myint+4); // 10 at the top
    third.push(10);
  // 4. vector
    vector<int>t;
    t.push_back(5);
    sort(t.begin(),t.end()); // ascending order
    bool result=binary_search(t.begin(),t.end(),5);
    reverse(t.begin(),t.end());
    swap(t[1],t[2]);
  //5. unordered_set
    unordered_set<int>breakder;
    breakder.insert(1);
    breakder.find(1) != breakder.end();
  // 6. stack
     stack<int>st;
     st.top();
     st.pop();
  return 0;
}

// how to use find_if();
bool odd(int x){return x%2;}
void f(vector<int>& v){
    auto p=find_if(v.begin(),v.end(),odd);
    if(p!=v.end()){
        // find it!
    }
    function<int(double)>fun;
    
}
