#include "Test.h"
#include <iostream>
using namespace std;

vector<int> validate_min_heap(vector<int> min_heap, unsigned int replace_index){
  while(replace_index<min_heap.size()){
    unsigned int left = (replace_index *2) +1;
    unsigned int right = (replace_index *2) +2;
    unsigned int parent = replace_index%2==0? (replace_index -2) /2:(replace_index -1) /2;
    int current = min_heap[replace_index];
    if(left>=0 && left < min_heap.size()
      && min_heap[left]< current
      && (right<min_heap.size() && min_heap[left]<=min_heap[right])
    ){
      min_heap[replace_index] = min_heap[left];
      min_heap[left] = current;
      replace_index = left;
    }else if(right>=0 && right < min_heap.size()
      && min_heap[right]< current
      && (left<min_heap.size() && min_heap[left]<=min_heap[right])
    ){
      min_heap[replace_index] = min_heap[right];
      min_heap[right] = current;
      replace_index = right;
    } else if( parent >=0 && parent < min_heap.size()
          && min_heap[parent]>current
    ){
      min_heap[replace_index] = min_heap[parent];
      min_heap[parent] = current;
      replace_index = parent;
    }else{
      break;
    }
  }
  return min_heap;

}

vector<int> replace(vector<int> min_heap, int replaced_value, int replacement)
{
  unsigned int replace_index = 0;
  for(unsigned int i =0; i < min_heap.size();i++){
    if(min_heap[i] == replaced_value){
      replace_index = i;
      min_heap[i] = replacement;
      break;
    }
  }
    return validate_min_heap(min_heap, replace_index);
}

int main ()
{
    test();
    return 0;
}
