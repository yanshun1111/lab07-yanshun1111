// heap.cpp
// Shun Yan

#include "heap.h"
#include <iostream>
using namespace std;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
    vdata.push_back(value);
    int index = vdata.size() - 1;
        while(index > 0 && vdata[(index-1)/2] > vdata[index]){
            swap(vdata[index], vdata[(index-1)/2]);
            index = (index-1)/2;
        }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
    if(vdata.empty()) return;
    vdata[0] = vdata.back();
    vdata.pop_back();
    int idex = 0;
    while(true){
        int left_child = 2*idex + 1, right_child = 2*idex + 2, temp = idex;
        if(left_child < vdata.size() && vdata[left_child] < vdata[temp])
            temp = left_child;
        if(right_child < vdata.size() && vdata[right_child] < vdata[temp])
            temp = right_child;
        if(temp == idex) break;
        std::swap(vdata[idex], vdata[temp]);
        idex = temp;
        }
}

// Returns the minimum element in the heap
int Heap::top() const{
  if(vdata.empty()) return -1;
  return vdata.front();
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty() const{
  return vdata.empty();
}
    