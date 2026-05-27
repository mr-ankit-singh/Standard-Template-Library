/*
#__ std::priority_queue in STL __#

    - A priority queue is a type of queue where each element has a priority associated with it.
    - Elements with higher priority are served before elements with lower priority.
    - It is typically implemented as a max-heap or min-heap.
    - The default behavior is to create a max-heap, where the largest element has the highest priority.
    - The underlying container is usually a vector or deque.

    - Syntax:
        std::priority_queue<type> pq;                                        // Default max-heap
        std::priority_queue<type, container_type> pq;                        // Custom container
        std::priority_queue<type, container_type, comparator> pq;            // Custom comparator
        std::priority_queue<type, vector<type>, greater<type>> pq;           // Min-heap

    - Member Functions:
        push(value)            : Adds an element to the priority queue.
        pop()                  : Removes the top element (highest priority).
        top()                  : Returns a reference to the top element.
        empty()                : Returns true if the priority queue is empty.
        size()                 : Returns the number of elements.
        swap(other)            : Exchanges the contents with another priority queue.
        emplace(value)         : Constructs an element in place at the top.
        push_range(start, end) : Adds a range of elements to the priority queue.

    - Heap Types:
        Max-Heap (default)     : largest element at top    → std::less<T>    (default)
        Min-Heap               : smallest element at top   → std::greater<T> (manual)
*/


// ============================================================
// DECLARATION & INITIALIZATION
// ============================================================

// Max-Heap — Default 🍁
// Syntax: std::priority_queue<type> pq;
// Description: Sabse bada element top pe hota hai — default behaviour.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    // Method 1 - empty max-heap
    std::priority_queue<int> pq1;
    pq1.push(30); pq1.push(10); pq1.push(50); pq1.push(20);
    std::cout << "Max-Heap top : " << pq1.top() << "\n";   // 50

    // Method 2 - vector se initialize
    std::vector<int> vec = {30, 10, 50, 20};
    std::priority_queue<int> pq2(vec.begin(), vec.end());
    std::cout << "From vector top : " << pq2.top() << "\n";   // 50
}
// Output: Max-Heap top : 50
//         From vector top : 50


// Min-Heap 🍁
// Syntax: std::priority_queue<type, vector<type>, greater<type>> pq;
// Description: Sabse CHHOTA element top pe hota hai.
//              greater<T> comparator use karna padta hai — default nahi hai.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    // Method 1 - empty min-heap
    std::priority_queue<int, vector<int>, greater<int>> pq1;
    pq1.push(30); pq1.push(10); pq1.push(50); pq1.push(20);
    std::cout << "Min-Heap top : " << pq1.top() << "\n";   // 10

    // Method 2 - vector se initialize
    std::vector<int> vec = {30, 10, 50, 20};
    std::priority_queue<int, vector<int>, greater<int>> pq2(vec.begin(), vec.end());
    std::cout << "From vector top : " << pq2.top() << "\n";   // 10
}
// Output: Min-Heap top : 10
//         From vector top : 10


// ============================================================
// TRAVERSAL / PRINT
// ============================================================

// Traverse — Max-Heap 🍁
// Syntax: while(!pq.empty()) { pq.top(); pq.pop(); }
// Description: priority_queue mein iterator nahi hota.
//              Sirf top() + pop() se traverse kar sakte hain.
//              Traverse karne ke baad queue EMPTY ho jaati hai.
#include <iostream>
#include <queue>
using namespace std;
int main() {
    std::priority_queue<int> pq;
    pq.push(30); pq.push(10); pq.push(50); pq.push(20);

    // Method 1 - destructive traverse (sorted descending order mein print hoga)
    std::cout << "Max-Heap order : ";
    while(!pq.empty()){
        std::cout << pq.top() << " ";   // 50 30 20 10
        pq.pop();
    }
    std::cout << "\n";

    // Method 2 - preserve karke traverse
    std::priority_queue<int> pq2;
    pq2.push(30); pq2.push(10); pq2.push(50);

    std::priority_queue<int> temp = pq2;   // copy banao
    std::cout << "Preserved traverse : ";
    while(!temp.empty()){
        std::cout << temp.top() << " ";   // 50 30 10
        temp.pop();
    }
    std::cout << "\n";
    std::cout << "Original top still : " << pq2.top() << "\n";   // 50
}
// Output: Max-Heap order     : 50 30 20 10
//         Preserved traverse : 50 30 10
//         Original top still : 50


// Traverse — Min-Heap 🍁
// Description: Min-heap traverse karne par sorted ascending order mein aata hai.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    std::priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(30); pq.push(10); pq.push(50); pq.push(20);

    std::cout << "Min-Heap order : ";
    while(!pq.empty()){
        std::cout << pq.top() << " ";   // 10 20 30 50
        pq.pop();
    }
    std::cout << "\n";
}
// Output: Min-Heap order : 10 20 30 50


// ============================================================
// MEMBER FUNCTIONS
// ============================================================

// push() 🍁
// Syntax: priority_queue_name.push(value);
// Description: Adds an element to the priority queue.
#include <iostream>
#include <queue>
int main() {
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    std::cout << "Top: " << pq.top() << "\n"; // Output: 20
}
// Output: Top: 20


// pop() 🍁
// Syntax: priority_queue_name.pop();
// Description: Removes the top element (highest priority) from the priority queue.
//              Value return NAHI karta — pehle top() se value lo, phir pop() karo.
#include <iostream>
#include <queue>
int main() {
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.pop(); // Removes 20
    std::cout << "Top: " << pq.top() << "\n"; // Output: 10
}
// Output: Top: 10


// top() 🍁
// Syntax: priority_queue_name.top();
// Description: Returns a reference to the top element (highest priority) in the priority queue.
//              Max-heap mein → sabse bada | Min-heap mein → sabse chhota
#include <iostream>
#include <queue>
int main() {
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    std::cout << "Top: " << pq.top() << "\n"; // Output: 20
}
// Output: Top: 20


// empty() 🍁
// Syntax: priority_queue_name.empty();
// Description: Returns true if the priority queue is empty, false otherwise.
#include <iostream>
#include <queue>
int main() {
    std::priority_queue<int> pq;
    std::cout << "Is priority queue empty? " << (pq.empty() ? "Yes" : "No") << "\n"; // Output: Yes
    pq.push(10);
    std::cout << "Is priority queue empty? " << (pq.empty() ? "Yes" : "No") << "\n"; // Output: No
}
// Output: Is priority queue empty? Yes
//         Is priority queue empty? No


// size() 🍁
// Syntax: priority_queue_name.size();
// Description: Returns the number of elements in the priority queue.
#include <iostream>
#include <queue>
int main() {
    std::priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    std::cout << "Size: " << pq.size() << "\n"; // Output: 2
}
// Output: Size: 2


// swap() 🍁
// Syntax: priority_queue_name.swap(other_priority_queue);
// Description: Exchanges the contents of this priority queue with another priority queue of the same type.
#include <iostream>
#include <queue>
int main() {
    std::priority_queue<int> pq1;
    std::priority_queue<int> pq2;
    pq1.push(10);
    pq2.push(20);
    pq1.swap(pq2); // Swaps contents of pq1 and pq2
    std::cout << "Top of pq1: " << pq1.top() << "\n"; // Output: 20
    std::cout << "Top of pq2: " << pq2.top() << "\n"; // Output: 10
}
// Output: Top of pq1: 20
//         Top of pq2: 10


// emplace() 🍁
// Syntax: priority_queue_name.emplace(value);
// Description: Constructs an element in place at the top of the priority queue.
//              push() se zyada efficient — no temporary object banta hai.
#include <iostream>
#include <queue>
#include <string>
int main() {
    std::priority_queue<std::string> pq;
    pq.emplace("Hello"); // Constructs "Hello" in place
    pq.emplace("World"); // Constructs "World" in place
    std::cout << "Top: " << pq.top() << "\n"; // Output: World
}
// Output: Top: World


// push_range() 🍁
// Syntax: priority_queue_name.push_range(start, end);
// Description: Adds a range of elements to the priority queue.
//              C++23 feature — compiler flag: -std=c++23
#include <iostream>
#include <queue>
#include <vector>
int main() {
    std::priority_queue<int> pq;
    std::vector<int> vec = {10, 20, 30};
    pq.push_range(vec.begin(), vec.end()); // Adds elements from vec to pq
    std::cout << "Top: " << pq.top() << "\n"; // Output: 30
}
// Output: Top: 30


// ============================================================
// CUSTOM COMPARATOR
// ============================================================

// Custom Comparator — Struct 🍁
// Syntax: std::priority_queue<type, vector<type>, CustomComp> pq;
// Description: Apna khud ka comparison logic dena — struct ya lambda use karo.
//              return true  → left ko NEECHE rakho (lower priority)
//              return false → left ko UPAR rakho  (higher priority)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Custom: chhota element pehle (min-heap effect)
struct MinComp {
    bool operator()(int a, int b){
        return a > b;   // a > b → a ko neeche rakho → chhota upar aayega
    }
};

int main() {
    std::priority_queue<int, vector<int>, MinComp> pq;
    pq.push(30); pq.push(10); pq.push(50); pq.push(20);
    std::cout << "Custom MinComp top : " << pq.top() << "\n";   // 10
}
// Output: Custom MinComp top : 10


// Custom Comparator — Pair (sort by second value) 🍁
// Description: Pair ko second value ke basis pe sort karna — competitive programming mein common.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Pair ka second value chhota ho to usse pehle nikalo (min on second)
struct PairComp {
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};

int main() {
    std::priority_queue<pair<int,int>, vector<pair<int,int>>, PairComp> pq;
    pq.push({1, 50});
    pq.push({2, 10});
    pq.push({3, 30});

    std::cout << "Top pair : {" << pq.top().first
              << ", " << pq.top().second << "}\n";   // {2, 10}
}
// Output: Top pair : {2, 10}


// ============================================================
// PRIORITY QUEUE WITH PAIRS
// ============================================================

// Pair Max-Heap (default) 🍁
// Description: Pair ke saath default max-heap — pehle first, phir second compare hota hai.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    std::priority_queue<pair<int,int>> pq;
    pq.push({1, 50});
    pq.push({3, 20});
    pq.push({3, 40});   // same first → second compare hoga
    pq.push({2, 10});

    std::cout << "Pair Max-Heap top : {" << pq.top().first
              << ", " << pq.top().second << "}\n";   // {3, 40}
}
// Output: Pair Max-Heap top : {3, 40}


// Pair Min-Heap 🍁
// Description: Pair ke saath min-heap — greater<pair<int,int>> use karo.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    std::priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({3, 50});
    pq.push({1, 20});
    pq.push({2, 10});

    std::cout << "Pair Min-Heap top : {" << pq.top().first
              << ", " << pq.top().second << "}\n";   // {1, 20}
}
// Output: Pair Min-Heap top : {1, 20}


// ============================================================
// MAX-HEAP vs MIN-HEAP — SIDE BY SIDE
// ============================================================

// Comparison 🍁
// Description: Dono heaps ek saath — clearly difference samajhna.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    vector<int> nums = {30, 10, 50, 20, 40};

    // Max-Heap
    std::priority_queue<int> maxPQ(nums.begin(), nums.end());

    // Min-Heap
    std::priority_queue<int, vector<int>, greater<int>> minPQ(nums.begin(), nums.end());

    std::cout << "Max-Heap top : " << maxPQ.top() << "\n";   // 50
    std::cout << "Min-Heap top : " << minPQ.top() << "\n";   // 10

    std::cout << "Max-Heap (desc) : ";
    while(!maxPQ.empty()){ std::cout << maxPQ.top() << " "; maxPQ.pop(); }
    std::cout << "\n";   // 50 40 30 20 10

    std::cout << "Min-Heap (asc)  : ";
    while(!minPQ.empty()){ std::cout << minPQ.top() << " "; minPQ.pop(); }
    std::cout << "\n";   // 10 20 30 40 50
}
// Output: Max-Heap top    : 50
//         Min-Heap top    : 10
//         Max-Heap (desc) : 50 40 30 20 10
//         Min-Heap (asc)  : 10 20 30 40 50


/*
================================================================================
  QUICK SUMMARY
================================================================================

  DECLARATION:
      Max-Heap (default)  priority_queue<int> pq;
      Min-Heap            priority_queue<int, vector<int>, greater<int>> pq;
      Custom Comp         priority_queue<int, vector<int>, MyComp> pq;

  MEMBER FUNCTIONS:
      push(val)           top pe element add karo
      emplace(val)        top pe in-place construct karo (efficient)
      pop()               top element hatao — value return nahi karta!
      top()               top element dekho — hatata nahi
      empty()             khali hai ya nahi (true/false)
      size()              current elements count
      swap(pq2)           do queues ka content exchange karo
      push_range(s, e)    range se saare elements add karo (C++23)

  HEAP RULES:
      Max-Heap → largest  element always at top  → less<T>    (default)
      Min-Heap → smallest element always at top  → greater<T> (manual)

  IMPORTANT:
      ✅ pehle top() lo, phir pop() karo — pop() return nahi karta
      ✅ traverse karne ke liye temp copy banao — original preserve hoga
      ❌ iterator nahi hota — range-based for loop nahi chalta
      ❌ middle access nahi — sirf top visible hai

  COMPARATOR LOGIC:
      return a > b  →  min-heap effect  (a ko neeche, chhota upar)
      return a < b  →  max-heap effect  (a ko neeche, bada upar)

================================================================================
  COMPILE & RUN:
      g++ priority_queue.cpp -o pq
      ./pq
      (push_range ke liye: g++ -std=c++23 priority_queue.cpp -o pq)
================================================================================
*/