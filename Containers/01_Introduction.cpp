/*
#__ Introduction in C++ __# 🎗️

    - STL: Standard Template Library
    - It consist of three components:
        a. Container
        b. Iterator
        c. Algorithm
         
#__ Containers __# 🎗️

    - Containers or container classes store objects and data.

    1. Sequence Containers: 
       Implement data structures which can be accessed in a sequential manner.

       - arrays          : array represents a static contiguous array 
       - vector          : vector represents a dynamic contiguous array
       - inplace_vector  : resizable, fixed capicity, inplace contiguous array
       - hive            : collection that reuses erase elements memory
       - forward_list    : forward_list represents a singly-linked list
       - list            : list represents a doubly-linked list
       - deque           : deque represents a double-ended queue, where elements can 
       .                   be added to the front or back of the queue.

    2. Container Adaptors : 
       provide a different interface for sequential containers.

       - queue
       - priority_queue
       - stack
       - flat_set
       - flat_map
       - flat_multiset
       - flat_multimap

    3. Associative Containers : 
       Implement sorted data structures that can be quickly searched (O(log n) complexity).

       - set       : set is a collection of unique keys, sorted by keys
       - multiset  : multiset is a collection of keys, sorted by keys
       - map       : map is a collection of key-value pairs, sorted by keys
       - multimap  : multimap is a collection of key-value pairs, sorted by keys

    4. Unordered Associative Containers : 
       Implement unordered data structures that can be quickly searched

       - unordered_set      : unordered set is a collection of unique keys, hashed by keys
       - unordered_multiset : unordered_multiset is a collection of keys, hashed by keys
       - unordered_map      : unordered_map is a collection of unique key-value pairs, hashed by keys
       - unordered_multimap : unordered_multimap is a collection of key-value pairs, hashed by keys


#__ Iterators __# 🎗️

+ Operations of Iterators
    1.begin() 
      Pointer pointing to first element
      Syntax : begin()  
    2.end()    
      Pointer pointing next of last element
      Syntax : end()  
    3.advance()
      Increment the iterator position to given distance
      Not generate the new iterator
      Not return iterator
      Syntax : advance(iterator it , int distance)  
    4.next()   
      Increment the iterator position
      Generator the new iterator
      Return iterator
      Syntax : next(iterator it , int n)  
    5.prev()  
      Decrement the iterator position 
      Syntax : prev(iterator it , int n)
    6.inserter()
      Insert the elements at any position in container
      Syntax : insertor(container& cName , iterator it)
*/

// Iterators
#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v {10,20,30,40,50} ;
    vector<int>::iterator it = v.begin();
    cout << &it << endl ;
    cout << *(it) << endl ;
    for(auto value : v){
        cout << *it << " " ;
        it++ ;
    }
    return 0;
}