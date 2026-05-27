/*

TOPIC: std::vector

    Syntax: std::vector<datatype> array_name;

    NOTES:
    1. std::vector is a sequence container and also known as Dynamic Array or Array List.
    2. Its size can grow and shrink dynamically, and no need to provide size at compile time.
    3. Vector supports Dynamic array and provide memory flexiblity.

    4. Access Elements:
        a. at()    -> access specified element with bounds checking.
        b. []      -> access specified element.
        c. front() -> access the first element.
        d. back()  -> access the last element.
        e. data()  -> gives access to the underlying array.
    
    5. Capacity
        a. empty()          -> checks whether the container is empty.
        b. size()           -> returns the number of elements in the vector.
        c. max_size()       -> returns the maximum possible number of elements.
        d. reserse()        -> reserve storage.
        e. capacity()       -> returns the storage space allocated for the vector.
        f. resize()         -> resizes the container. 
        g. shrink_to_fit()  -> reduces memory usage by freeing unused memory.

    6. Modifiers
        a. assign()         -> assigns new contents to the vector and replaces its current contents.
        b. push_back()      –> push the elements into a vector from the back.
        c. pop_back()       –> remove elements from a vector from the back.
        d. insert()         –> inserts new elements before the element at the specified position.
        e. erase()          –> remove elements from a container from the specified position or range.
        f. swap()           –> swap the contents of one vector with another vector of same type. Sizes may differ.
        g. clear()          –> remove all the elements of the vector container.
        h. emplace()        –> It extends the container by inserting new element at position.
        i. emplace_back()   –> insert a new element into the vector container, the new element is added to the end of the vector.

    7. Iterators
       a. begin()     -> returns an iterator to the beginning.
          cbegin()
       b. end()       -> returns an iterator to the end.
          cend()
       c. rbegin()    -> returns a reverse iterator to the beginning.
          crbegin()
       d. rend()      -> returns a reverse iterator to the end.
          crend()
      
*/
//==============================================================================
#include<iostream>
#include<vector>
using namespace std;
int main(){
    // Decleration
    std::vector<int> arr1; // zero length vector
    std::vector<int> arr2 (5); // five length vector
    std::vector<int> arr3 = {1, 2, 3, 4, 5}; // initilizer list
    std::vector<int> arr4 {1, 2, 3, 4, 5};  // uniform initilization
    std::vector<int> arr5 (5,10); // five length vector having value 10 in all
    // Accessing Elements
    arr2[3] = 10;
    arr2.at(3) = 10;
    // size of vector
    cout << arr5.size();
    return 0;
}
 
//==============================================================================
// Length of std::vector  -> the size() function returns the length
#include <iostream>
#include <vector>
 
int main()
{
    std::vector<int> marks1(10);  // yeh per hm size mention kr reha hai
    std::vector<int> marks2 = {50, 45, 47, 65, 80};
    marks2 = {50, 47, 60};
    std::vector<int> marks3 (5,99);
    std::cout << "length of array1 : " << marks1.size() << std::endl;
    std::cout << "length of array2 : " << marks2.size() << std::endl;
    std::cout << "length of array3 : " << marks3.size() << std::endl;
    return 0;
}
 
//==============================================================================
// at() -> at function is used to access the element at specified position (index). 
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> marks = {50, 45, 47, 65, 80};
    marks.at(2) = 74;
    for(int i = 0; i < marks.size() ; i++){
        std::cout << "marks[" << i << "] = " << marks.at(i) << std::endl;
    }
    return 0;
}
 
//==============================================================================
// front() -> function returns the first element of a vector.
// back()  -> function returns the last element of a vector.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> marks = {50, 45, 47, 65, 80};
    std::cout << marks.front() << std::endl;
    std::cout << marks.back() << std::endl;
    return 0;
}
 
//==============================================================================
// data() -> It returns a direct pointer to the memory array used internally by the vector.
// Using this pointer we can access and modify elements directly like a normal array.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v1 = {10, 20, 30, 40, 50};
    int* ptr = v1.data();  // pointer to first element
    std::cout << "pointer to first element : " << ptr << std::endl ; 
    std::cout << "First element via data() : " << *ptr << std::endl;   // 10
    std::cout << "Third element via data() : " << *(ptr + 2) << std::endl; // 30
    return 0;
}
 
//==============================================================================
// empty() -> It checks whether a vector contains any element or not. 
// It returns 1 if the length of a vector is 0 and 0 if it contains some element
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v1 = {5, 6};
    std::vector<int> v2;
    std::cout << v1.empty() << std::endl;
    std::cout << v2.empty() << std::endl;
    return 0;
}
 
//==============================================================================
// resize() -> It resizes a vector so that it contains the specified number of elements. 
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v1 = {5, 6};
    v1.resize(5);
    for(int i = 0; i < v1.size() ; i++){
        std::cout << v1[i] << std::endl;
    }
    return 0;
}
 
//==============================================================================
// max_size() -> It returns the maximum number of elements that the vector can hold.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::cout << v1.size() << std::endl;
    std::cout << v1.max_size() << std::endl;
    return 0;
}

//==============================================================================
// capacity() -> This function returns the storage space allocated for the vector. 
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v1;
    for(int i = 0; i < 50; i++){
        v1.push_back(1);
    }
    std::cout << "size : " << v1.size() << std::endl;
    std::cout << "max_size : " << v1.max_size() << std::endl;
    std::cout << "capacity : " << v1.capacity() << std::endl;
    return 0;
}
 
//==============================================================================
// shrink_to_fit() -> It reduces the capacity of the vector to fit its size.
// Extra allocated memory (unused capacity) is freed.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v1;
    v1.reserve(100);  // capacity = 100, size = 0
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    std::cout << "capacity before shrink : " << v1.capacity() << std::endl;  // 100
    v1.shrink_to_fit();
    std::cout << "capacity after shrink  : " << v1.capacity() << std::endl;  // 3
    std::cout << "size                   : " << v1.size() << std::endl;      // 3
    return 0;
}

//==============================================================================
// reserve() -> It requests that the vector capacity be at least enough to contain n elements.
// It does NOT change the size, only allocates memory in advance to avoid reallocation.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v1;
    std::cout << "capacity before reserve : " << v1.capacity() << std::endl;  // 0
    v1.reserve(10);  // allocate memory for 10 elements
    std::cout << "capacity after reserve  : " << v1.capacity() << std::endl;  // 10
    std::cout << "size after reserve      : " << v1.size() << std::endl;      // 0 (size unchanged)
    return 0;
}
 

 
//==============================================================================
// assign() -> It assigns new contents to the vector and replaces its current contents. 
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v;
    v.assign(7, 40);  // 7 elements each of value 40
    std::cout << v.size() << std::endl;
    for(auto val : v) std::cout << val << " " ;
    return 0;
}
 
//==============================================================================
// push_back() -> This function adds a new element at the end of the vector
//                push_back() — Copy/Move karta hai ( 2 step follow krta hai )
// pop_back()  -> This function removes the last element in the vector

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // push_back()
    std::vector<int> v = {4, 5, 6, 7, 8};
    v.push_back(47);
    //printing values of v
    std::cout << "elements of v" << std::endl;
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;
    }
    // pop_back()
    std::vector<int> v = {4, 5, 6, 7, 8};
    v.pop_back();
    //printing values of v
    std::cout << "elements of v" << endl;
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;
    }
 
    return 0;
}
 
//==============================================================================
// insert() -> It inserts new elements before the element at the specified position.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    v.insert(v.begin() + 2, 99);  // insert 99 at index 2
    std::cout << "elements of v after insert" << std::endl;
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;  // 1 2 99 3 4 5
    }
    return 0;
}

//==============================================================================
// emplace() -> It inserts a new element at the specified position in the vector.
// More efficient than insert() as it constructs the element in-place.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    v.emplace(v.begin() + 2, 99);  // insert 99 at index 2
    std::cout << "elements of v after emplace" << std::endl;
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;  // 1 2 99 3 4 5
    }
    return 0;
}
 
//==============================================================================
// emplace_back() -> It inserts a new element at the end of the vector.
// More efficient than push_back() as it constructs the element in-place.
// emplace_back() — Directly construct karta hai ( 1 step )
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    v.emplace_back(99);  // add 99 at the end
    std::cout << "elements of v after emplace_back" << std::endl;
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;  // 1 2 3 4 5 99
    }
    return 0;
}

//==============================================================================
// erase() -> It removes elements from a vector at specified position or range.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    v.erase(v.begin() + 2);  // remove element at index 2 (value 3)
    std::cout << "elements of v after erase" << std::endl;
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << std::endl;  // 1 2 4 5
    }
    return 0;
}
 
//==============================================================================
// clear() -> clear removes all elements of a vector.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v1 = {4, 5, 6, 7, 8};
    v1.clear();
    for (auto i: v1){
        std::cout << i << std::endl;
    }
 
    return 0;
}
 
//==============================================================================
// swap() -> This function swaps the contents i.e. it exchanges the value of one vector with that of another.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};
    v1.swap(v2);
    std::cout << "Vector v1" << std::endl;
    for (auto i: v1){
        std::cout << i << std::endl;
    }
    std::cout << "Vector v2" << std::endl;
    for (auto i: v2){
        std::cout << i << std::endl;
    }
 
    return 0;
}
 

// Note : Real difference — Complex objects mein dikhai deta hai
// Difference between puch_back() and emplace_back()
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) {
        cout << "Constructor called\n";
    }
};

int main() {
    vector<Point> v;

    cout << "--- push_back ---\n";
    v.push_back(Point(1, 2));   // Point pehle bahar banta hai, phir copy/move

    cout << "--- emplace_back ---\n";
    v.emplace_back(3, 4);       // seedha (3,4) pass karo — andar hi banta hai
}


// **Output:**
// --- push_back ---
// Constructor called        ← bahar bana
// --- emplace_back ---
// Constructor called        ← seedha andar bana (no extra step)



//==============================================================================
// sort() -> It sorts the elements of a vector in ascending order by default.
// We need to add a header algorithm to use it.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    std::vector<int> v = {47, 23, 90, 1, 56};
    sort(v.begin(), v.end());
    std::cout << "Ascending : ";
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";  // 1 23 47 56 90
    }
    std::cout << std::endl;
    sort(v.begin(), v.end(), greater<int>());
    std::cout << "Descending: ";
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";  // 90 56 47 23 1
    }
    std::cout << std::endl;
    return 0;
}

//==============================================================================
// reverse() -> It reverses the order of elements in a vector.
// We need to add a header algorithm to use it.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    std::vector<int> v = {47, 23, 90, 1, 56};
    reverse(v.begin(), v.end());
    std::cout << "Reversed: ";
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";  // 56 1 90 23 47
    }
    std::cout << std::endl;
    return 0;
}