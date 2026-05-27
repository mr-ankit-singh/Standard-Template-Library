/*
================================================================================
        C++ STL — std::list (Doubly Linked List)
        Format: Title | Syntax | Definition | Examples
================================================================================

   WHAT IS std::list?
   - Doubly Linked List implement karta hai
   - Har node NEXT aur PREVIOUS dono ko jaanta hai
   - Non-contiguous memory allocation hoti hai
   - Fast insertion aur deletion — slow random access
   - Comparison lexicographically hoti hai

   NULL <-- prev | node | next --> prev | node | next --> NULL
             10                     20                   30

   HEADER: #include <list>

   CATEGORIES:
   1. Element Access  -> front(), back()
   2. Capacity        -> empty(), size(), max_size()
   3. Modifiers       -> assign(), push_back(), push_front(), pop_back(),
                         pop_front(), insert(), emplace(), emplace_back(),
                         emplace_front(), swap(), resize(), clear()
   4. Operations      -> splice(), remove(), remove_if(), unique(),
                         merge(), sort(), reverse()
*/


//==============================================================================
// DECLARATION & INITIALIZATION
//==============================================================================
/*
  TITLE:
      std::list Declaration aur Initialization

  SYNTAX:
      std::list<datatype> name;
      std::list<datatype> name (size);
      std::list<datatype> name (size, value);
      std::list<datatype> name {1, 2, 3};

  DEFINITION:
      std::list ek doubly linked list hai. Isko 4 tareekon se
      declare/initialize kar sakte ho — khali, sirf size ke saath,
      size + default value ke saath, ya seedhi values de ke.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l;                   // empty list
    std::list<int> l1 (7);              // size 7, all zeros
    std::list<int> l2 (5, 10);          // size 5, all values = 10
    std::list<int> myList {1, 2, 3};    // values: 1 2 3

    // print l2
    cout << "l2 (5 times 10) : ";
    for(auto val : l2) cout << val << " ";   // 10 10 10 10 10
    cout << endl;

    // print myList
    cout << "myList          : ";
    for(auto val : myList) cout << val << " ";   // 1 2 3
    cout << endl;

    return 0;
}


//==============================================================================
// PRINT / TRAVERSE
//==============================================================================
/*
  TITLE:
      std::list Print karna (Traversal)

  SYNTAX:
      for(auto val : lst) { }
      for(it = lst.begin(); it != lst.end(); it++)

  DEFINITION:
      list mein index se direct access nahi hota — isliye iterator ya
      range-based for loop use karte hain. begin() pehle element ka
      iterator deta hai, end() last ke baad ka.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> lst {10, 20, 30, 40, 50};

    // Mtd 1 - range-based for (sabse easy)
    cout << "Mtd 1 (range-based) : ";
    for(auto val : lst) cout << val << " ";   // 10 20 30 40 50
    cout << endl;

    // Mtd 2 - iterator loop
    cout << "Mtd 2 (iterator)    : ";
    std::list<int>::iterator it;
    for(it = lst.begin(); it != lst.end(); it++){
        cout << *it << " ";   // 10 20 30 40 50
    }
    cout << endl;

    return 0;
}


//==============================================================================
// CATEGORY 1 - ELEMENT ACCESS
// a) front() -> Returns first element
// b) back()  -> Returns last element
//==============================================================================


//------------------------------------------------------------------------------
// a) front()
//------------------------------------------------------------------------------
/*
  TITLE:
      front() - Pehla element access karna

  SYNTAX:
      lst.front();

  DEFINITION:
      list ka pehla element return karta hai.
      Isse read bhi kar sakte ho aur modify bhi.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> lst {10, 20, 30, 40, 50};

    // Example 1 - pehla element read
    cout << "front() : " << lst.front() << endl;   // 10

    // Example 2 - front() se modify
    lst.front() = 99;
    cout << "After front() = 99 : ";
    for(auto val : lst) cout << val << " ";   // 99 20 30 40 50
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// b) back()
//------------------------------------------------------------------------------
/*
  TITLE:
      back() - Aakhri element access karna

  SYNTAX:
      lst.back();

  DEFINITION:
      list ka aakhri (last) element return karta hai.
      Isse read bhi kar sakte ho aur modify bhi.
      forward_list mein back() nahi hota — list mein hota hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> lst {10, 20, 30, 40, 50};

    // Example 1 - aakhri element read
    cout << "back() : " << lst.back() << endl;   // 50

    // Example 2 - back() se modify
    lst.back() = 99;
    cout << "After back() = 99 : ";
    for(auto val : lst) cout << val << " ";   // 10 20 30 40 99
    cout << endl;

    return 0;
}


//==============================================================================
// CATEGORY 2 - CAPACITY
// a) empty()    -> Check whether list is empty
// b) size()     -> Number of elements in list
// c) max_size() -> Maximum possible elements
//==============================================================================


//------------------------------------------------------------------------------
// a) empty()
//------------------------------------------------------------------------------
/*
  TITLE:
      empty() - List khali hai ya nahi check karna

  SYNTAX:
      lst.empty();

  DEFINITION:
      list mein koi element hai ya nahi check karta hai.
      1 (true) return karta hai agar list empty ho, warna 0 (false).
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l1 {10, 20, 30};
    std::list<int> l2;

    // Example 1 - non-empty list
    cout << "l1.empty() : " << l1.empty() << endl;   // 0 (not empty)

    // Example 2 - empty list
    cout << "l2.empty() : " << l2.empty() << endl;   // 1 (empty)

    // Example 3 - clear ke baad
    l1.clear();
    cout << "l1.empty() after clear() : " << l1.empty() << endl;   // 1

    return 0;
}


//------------------------------------------------------------------------------
// b) size()
//------------------------------------------------------------------------------
/*
  TITLE:
      size() - List mein kitne elements hain

  SYNTAX:
      lst.size();

  DEFINITION:
      list mein abhi kitne elements hain woh count return karta hai.
      forward_list mein size() nahi hota — list mein hota hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l1 {10, 20, 30, 40, 50};
    std::list<int> l2;

    // Example 1 - normal list
    cout << "l1.size() : " << l1.size() << endl;   // 5

    // Example 2 - empty list
    cout << "l2.size() : " << l2.size() << endl;   // 0

    // Example 3 - push ke baad
    l2.push_back(1);
    l2.push_back(2);
    cout << "l2.size() after 2 push_back : " << l2.size() << endl;   // 2

    return 0;
}


//------------------------------------------------------------------------------
// c) max_size()
//------------------------------------------------------------------------------
/*
  TITLE:
      max_size() - Maximum kitne elements aa sakte hain

  SYNTAX:
      lst.max_size();

  DEFINITION:
      System ke hisaab se maximum elements ki limit batata hai.
      Yeh value bahut badi hoti hai — practically kabhi reach nahi hoti.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int>    li;
    std::list<double> ld;

    // Example 1 - int list
    cout << "int max_size()    : " << li.max_size() << endl;

    // Example 2 - double list
    cout << "double max_size() : " << ld.max_size() << endl;

    return 0;
}


//==============================================================================
// CATEGORY 3 - MODIFIERS
// a) assign()        -> Assign new content
// b) push_back()     -> Insert at end
// c) push_front()    -> Insert at beginning
// d) pop_back()      -> Delete last element
// e) pop_front()     -> Delete first element
// f) insert()        -> Insert before iterator position
// g) emplace()       -> Construct and insert at position
// h) emplace_back()  -> Construct and insert at end
// i) emplace_front() -> Construct and insert at beginning
// j) swap()          -> Swap two lists
// k) resize()        -> Change size of list
// l) clear()         -> Remove all elements
//==============================================================================


//------------------------------------------------------------------------------
// a) assign()
//------------------------------------------------------------------------------
/*
  TITLE:
      assign() - List mein nai values assign karna

  SYNTAX:
      lst.assign({1, 2, 3});
      lst.assign(count, value);
      lst.assign(other.begin(), other.end());

  DEFINITION:
      list ki purani values hatakar nai values daalta hai.
      Teen tareekon se use kar sakte ho - seedha values do,
      ek value baar baar do, ya kisi aur list se copy karo.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l1, l2, l3;

    // Example 1 - initializer list se
    l1.assign({1, 2, 3, 4, 5});
    cout << "l1 (list)       : ";
    for(auto val : l1) cout << val << " ";   // 1 2 3 4 5
    cout << endl;

    // Example 2 - 4 baar value 7
    l2.assign(4, 7);
    cout << "l2 (4 times 7)  : ";
    for(auto val : l2) cout << val << " ";   // 7 7 7 7
    cout << endl;

    // Example 3 - l1 se copy
    l3.assign(l1.begin(), l1.end());
    cout << "l3 (copy of l1) : ";
    for(auto val : l3) cout << val << " ";   // 1 2 3 4 5
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// b) push_back()
//------------------------------------------------------------------------------
/*
  TITLE:
      push_back() - End mein element add karna

  SYNTAX:
      lst.push_back(value);

  DEFINITION:
      list ke bilkul END mein ek naya element add karta hai.
      Har baar push_back() karo to naya element aakhir mein aa jaata hai.
      Size 1 se badhta hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l;

    // Example 1 - elements add karna
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);
    cout << "After 3 push_back : ";
    for(auto val : l) cout << val << " ";   // 10 20 30
    cout << endl;

    // Example 2 - existing list mein add
    l.push_back(40);
    cout << "After push_back(40): ";
    for(auto val : l) cout << val << " ";   // 10 20 30 40
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// c) push_front()
//------------------------------------------------------------------------------
/*
  TITLE:
      push_front() - Shuru mein element add karna

  SYNTAX:
      lst.push_front(value);

  DEFINITION:
      list ke bilkul SHURU mein ek naya element add karta hai.
      Har baar push_front() karo to naya element pehle aa jaata hai.
      Size 1 se badhta hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l {30, 40, 50};

    // Example 1 - ek element add
    l.push_front(20);
    cout << "After push_front(20) : ";
    for(auto val : l) cout << val << " ";   // 20 30 40 50
    cout << endl;

    // Example 2 - multiple push_front
    l.push_front(10);
    l.push_front(5);
    cout << "After 2 more         : ";
    for(auto val : l) cout << val << " ";   // 5 10 20 30 40 50
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// d) pop_back()
//------------------------------------------------------------------------------
/*
  TITLE:
      pop_back() - Aakhri element delete karna

  SYNTAX:
      lst.pop_back();

  DEFINITION:
      list ka AAKHRI element hata deta hai.
      Koi value return nahi karta. Size 1 se ghatta hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l {10, 20, 30, 40, 50};

    // Example 1 - ek baar pop
    l.pop_back();
    cout << "After 1 pop_back  : ";
    for(auto val : l) cout << val << " ";   // 10 20 30 40
    cout << endl;

    // Example 2 - do baar pop
    l.pop_back();
    l.pop_back();
    cout << "After 2 more pops : ";
    for(auto val : l) cout << val << " ";   // 10 20
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// e) pop_front()
//------------------------------------------------------------------------------
/*
  TITLE:
      pop_front() - Pehla element delete karna

  SYNTAX:
      lst.pop_front();

  DEFINITION:
      list ka PEHLA element hata deta hai.
      Koi value return nahi karta. Size 1 se ghatta hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l {10, 20, 30, 40, 50};

    // Example 1 - ek baar pop
    l.pop_front();
    cout << "After 1 pop_front : ";
    for(auto val : l) cout << val << " ";   // 20 30 40 50
    cout << endl;

    // Example 2 - do baar pop
    l.pop_front();
    l.pop_front();
    cout << "After 2 more pops : ";
    for(auto val : l) cout << val << " ";   // 40 50
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// f) insert()
//------------------------------------------------------------------------------
/*
  TITLE:
      insert() - Iterator position ke PEHLE element insert karna

  SYNTAX:
      lst.insert(iterator, value);
      lst.insert(iterator, count, value);
      lst.insert(iterator, {1, 2, 3});

  DEFINITION:
      Jo iterator point kar raha hai us element ke PEHLE naya element daalta hai.
      list mein insert() seedha position pe kaam karta hai —
      forward_list wali insert_after() wali limitation nahi hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    // Example 1 - begin() se pehle insert
    std::list<int> l1 {10, 20, 30, 40};
    l1.insert(l1.begin(), 5);
    cout << "insert(begin, 5)         : ";
    for(auto val : l1) cout << val << " ";   // 5 10 20 30 40
    cout << endl;

    // Example 2 - end() se pehle insert (matlab end mein)
    std::list<int> l2 {10, 20, 30};
    l2.insert(l2.end(), 99);
    cout << "insert(end, 99)          : ";
    for(auto val : l2) cout << val << " ";   // 10 20 30 99
    cout << endl;

    // Example 3 - count times same value
    std::list<int> l3 {10, 20, 30};
    l3.insert(l3.begin(), 3, 7);
    cout << "insert(begin, 3, 7)      : ";
    for(auto val : l3) cout << val << " ";   // 7 7 7 10 20 30
    cout << endl;

    // Example 4 - initializer list insert
    std::list<int> l4 {10, 20, 30};
    l4.insert(l4.begin(), {1, 2, 3});
    cout << "insert(begin, {1, 2, 3}) : ";
    for(auto val : l4) cout << val << " ";   // 1 2 3 10 20 30
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// g) emplace()
//------------------------------------------------------------------------------
/*
  TITLE:
      emplace() - Kisi position pe in-place construct karke insert karna

  SYNTAX:
      lst.emplace(iterator, value);

  DEFINITION:
      insert() jaisa hi kaam karta hai — lekin element seedha
      list ke andar construct hota hai (no copy, no move).
      Jo iterator point kar raha hai us ke PEHLE insert hota hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l {10, 20, 30, 40};

    // Example 1 - begin ke pehle
    l.emplace(l.begin(), 5);
    cout << "After emplace(begin, 5)  : ";
    for(auto val : l) cout << val << " ";   // 5 10 20 30 40
    cout << endl;

    // Example 2 - end ke pehle (matlab aakhir mein)
    l.emplace(l.end(), 99);
    cout << "After emplace(end, 99)   : ";
    for(auto val : l) cout << val << " ";   // 5 10 20 30 40 99
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// h) emplace_back()
//------------------------------------------------------------------------------
/*
  TITLE:
      emplace_back() - End mein in-place construct karke add karna

  SYNTAX:
      lst.emplace_back(value);

  DEFINITION:
      push_back() jaisa hi kaam karta hai — lekin element seedha
      list ke andar construct hota hai (no copy, no move).
      Simple types (int) ke liye koi fark nahi — complex objects ke
      liye push_back() se zyada efficient hota hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l {10, 20, 30};

    // Example 1 - basic emplace_back
    l.emplace_back(40);
    cout << "After emplace_back(40) : ";
    for(auto val : l) cout << val << " ";   // 10 20 30 40
    cout << endl;

    // Example 2 - multiple emplace_back
    l.emplace_back(50);
    l.emplace_back(60);
    cout << "After 2 more           : ";
    for(auto val : l) cout << val << " ";   // 10 20 30 40 50 60
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// i) emplace_front()
//------------------------------------------------------------------------------
/*
  TITLE:
      emplace_front() - Shuru mein in-place construct karke add karna

  SYNTAX:
      lst.emplace_front(value);

  DEFINITION:
      push_front() jaisa hi kaam karta hai — lekin element seedha
      list ke andar construct hota hai (no copy, no move).
      Simple types (int) ke liye push_front() se koi fark nahi.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l {10, 20, 30};

    // Example 1 - basic emplace_front
    l.emplace_front(5);
    cout << "After emplace_front(5) : ";
    for(auto val : l) cout << val << " ";   // 5 10 20 30
    cout << endl;

    // Example 2 - multiple emplace_front
    l.emplace_front(2);
    l.emplace_front(1);
    cout << "After 2 more           : ";
    for(auto val : l) cout << val << " ";   // 1 2 5 10 20 30
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// j) swap()
//------------------------------------------------------------------------------
/*
  TITLE:
      swap() - Do lists ke contents exchange karna

  SYNTAX:
      l1.swap(l2);

  DEFINITION:
      Do lists ke saare elements aapas mein exchange ho jaate hain.
      Dono lists ka type same hona chahiye — size alag bhi ho sakta hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l1 {1, 2, 3};
    std::list<int> l2 {10, 20, 30, 40, 50};

    l1.swap(l2);

    // Example 1
    cout << "l1 after swap : ";
    for(auto val : l1) cout << val << " ";   // 10 20 30 40 50
    cout << endl;

    // Example 2
    cout << "l2 after swap : ";
    for(auto val : l2) cout << val << " ";   // 1 2 3
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// k) resize()
//------------------------------------------------------------------------------
/*
  TITLE:
      resize() - List ka size change karna

  SYNTAX:
      lst.resize(new_size);
      lst.resize(new_size, value);

  DEFINITION:
      list ka size badha ya ghata sakta hai.
      Agar size badhao to nai jagah 0 (ya given value) se fill hoti hai.
      Agar size ghataao to extra elements end se cut ho jaate hain.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    // Example 1 - size badhana (0 se fill)
    std::list<int> l1 {10, 20, 30};
    l1.resize(6);
    cout << "After resize(6)      : ";
    for(auto val : l1) cout << val << " ";   // 10 20 30 0 0 0
    cout << endl;

    // Example 2 - size badhana with value
    std::list<int> l2 {10, 20, 30};
    l2.resize(6, 99);
    cout << "After resize(6, 99)  : ";
    for(auto val : l2) cout << val << " ";   // 10 20 30 99 99 99
    cout << endl;

    // Example 3 - size ghataana
    std::list<int> l3 {10, 20, 30, 40, 50};
    l3.resize(3);
    cout << "After resize(3)      : ";
    for(auto val : l3) cout << val << " ";   // 10 20 30
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// l) clear()
//------------------------------------------------------------------------------
/*
  TITLE:
      clear() - List ke saare elements delete karna

  SYNTAX:
      lst.clear();

  DEFINITION:
      list ke SAARE elements ek baar mein hata deta hai.
      Baad mein empty() check karo to 1 (true) aata hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l {10, 20, 30, 40, 50};

    // Example 1 - clear ke pehle
    cout << "Before clear - size()  : " << l.size()  << endl;   // 5
    cout << "Before clear - empty() : " << l.empty() << endl;   // 0

    l.clear();

    // Example 2 - clear ke baad
    cout << "After clear  - size()  : " << l.size()  << endl;   // 0
    cout << "After clear  - empty() : " << l.empty() << endl;   // 1

    return 0;
}


//==============================================================================
// CATEGORY 4 - OPERATIONS
// a) splice()    -> Insert another list into this list
// b) remove()    -> Remove elements with specific value
// c) remove_if() -> Remove elements fulfilling condition
// d) unique()    -> Remove duplicate values
// e) merge()     -> Merge two sorted lists
// f) sort()      -> Sort elements in list
// g) reverse()   -> Reverse the order of elements
//==============================================================================


//------------------------------------------------------------------------------
// a) splice()
//------------------------------------------------------------------------------
/*
  TITLE:
      splice() - Ek list ke elements doosri list mein transfer karna

  SYNTAX:
      l1.splice(iterator, l2);            // poori l2 transfer
      l1.splice(iterator, l2, pos);       // l2 ka ek element transfer
      l1.splice(iterator, l2, first, last); // l2 ka range transfer

  DEFINITION:
      l2 ke elements l1 mein move ho jaate hain — copy nahi, move hota hai.
      forward_list ke splice_after() jaisa hai — lekin yahan seedha
      position pe insert hota hai (before_begin() ki zaroorat nahi).
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    // Example 1 - poori list begin pe transfer
    std::list<int> l1 {1, 2, 3};
    std::list<int> l2 {10, 20, 30};
    l1.splice(l1.begin(), l2);
    cout << "l1 after splice(begin, l2) : ";
    for(auto val : l1) cout << val << " ";   // 10 20 30 1 2 3
    cout << endl;
    cout << "l2 after splice            : ";
    cout << (l2.empty() ? "empty" : "not empty") << endl;   // empty

    // Example 2 - end pe splice (aakhir mein add)
    std::list<int> l3 {1, 2, 3};
    std::list<int> l4 {10, 20, 30};
    l3.splice(l3.end(), l4);
    cout << "l3 after splice(end, l4)   : ";
    for(auto val : l3) cout << val << " ";   // 1 2 3 10 20 30
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// b) remove()
//------------------------------------------------------------------------------
/*
  TITLE:
      remove() - Specific value ke saare elements hatana

  SYNTAX:
      lst.remove(value);

  DEFINITION:
      List mein jo value batao — jitni baar bhi aaye sab instances
      ek saath hata deta hai.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    std::list<int> l {10, 30, 20, 30, 40, 30, 50};

    // Example 1 - value ke saare instances remove
    l.remove(30);
    cout << "After remove(30) : ";
    for(auto val : l) cout << val << " ";   // 10 20 40 50
    cout << endl;

    // Example 2 - value jo exist nahi (kuch nahi hoga)
    l.remove(99);
    cout << "After remove(99) : ";
    for(auto val : l) cout << val << " ";   // 10 20 40 50
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// c) remove_if()
//------------------------------------------------------------------------------
/*
  TITLE:
      remove_if() - Condition ke basis pe elements hatana

  SYNTAX:
      lst.remove_if([](int x){ return condition; });

  DEFINITION:
      Ek condition (lambda function) do — jo elements us condition ko
      satisfy karte hain woh sab hata do.
      remove() se zyada flexible hai kyunki custom condition de sakte ho.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    // Example 1 - 30 se bade sab hato
    std::list<int> l1 {10, 20, 30, 40, 50, 60};
    l1.remove_if([](int x){ return x > 30; });
    cout << "After remove_if(x > 30) : ";
    for(auto val : l1) cout << val << " ";   // 10 20 30
    cout << endl;

    // Example 2 - even numbers hato
    std::list<int> l2 {1, 2, 3, 4, 5, 6, 7, 8};
    l2.remove_if([](int x){ return x % 2 == 0; });
    cout << "After remove_if(even)   : ";
    for(auto val : l2) cout << val << " ";   // 1 3 5 7
    cout << endl;

    // Example 3 - negative numbers hato
    std::list<int> l3 {-5, 10, -3, 20, -1, 30};
    l3.remove_if([](int x){ return x < 0; });
    cout << "After remove_if(x < 0) : ";
    for(auto val : l3) cout << val << " ";   // 10 20 30
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// d) unique()
//------------------------------------------------------------------------------
/*
  TITLE:
      unique() - Consecutive duplicate values hatana

  SYNTAX:
      lst.unique();

  DEFINITION:
      Ek ke baad ek aane wale SAME elements mein se extra copies hata deta hai.
      IMPORTANT: Sirf consecutive duplicates hataata hai —
      isliye pehle sort() karo, phir unique() complete deduplication ke liye.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    // Example 1 - consecutive duplicates
    std::list<int> l1 {10, 10, 20, 20, 20, 30, 40};
    l1.unique();
    cout << "After unique() (consecutive) : ";
    for(auto val : l1) cout << val << " ";   // 10 20 30 40
    cout << endl;

    // Example 2 - sort pehle phir unique
    std::list<int> l2 {30, 10, 20, 10, 30, 20};
    l2.sort();
    l2.unique();
    cout << "After sort() + unique()      : ";
    for(auto val : l2) cout << val << " ";   // 10 20 30
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// e) merge()
//------------------------------------------------------------------------------
/*
  TITLE:
      merge() - Do sorted lists ko ek mein merge karna

  SYNTAX:
      l1.merge(l2);

  DEFINITION:
      Do already sorted lists ko merge karke ek sorted list bana deta hai.
      l2 ke elements l1 mein aa jaate hain aur l2 empty ho jaati hai.
      IMPORTANT: Dono lists pehle se sorted honi chahiye.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    // Example 1 - basic merge
    std::list<int> l1 {10, 20, 30, 40};
    std::list<int> l2 {15, 25, 35, 55};
    l1.merge(l2);
    cout << "After merge()      : ";
    for(auto val : l1) cout << val << " ";   // 10 15 20 25 30 35 40 55
    cout << endl;
    cout << "l2 after merge     : " << (l2.empty() ? "empty" : "not empty") << endl;

    // Example 2 - sort karo phir merge
    std::list<int> l3 {50, 10, 30};
    std::list<int> l4 {40, 20, 60};
    l3.sort();
    l4.sort();
    l3.merge(l4);
    cout << "After sort + merge : ";
    for(auto val : l3) cout << val << " ";   // 10 20 30 40 50 60
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// f) sort()
//------------------------------------------------------------------------------
/*
  TITLE:
      sort() - List ko sort karna

  SYNTAX:
      lst.sort();                  // ascending (default)
      lst.sort(greater<int>());    // descending

  DEFINITION:
      list ke elements ko sort karta hai.
      NOTE: std::sort() list ke saath kaam nahi karta kyunki list ke
      iterators random access support nahi karte —
      isliye lst.sort() (member function) use karte hain.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    // Example 1 - ascending sort
    std::list<int> l1 {2, 1, 6, 3, 5, 4};
    l1.sort();
    cout << "Ascending  : ";
    for(auto val : l1) cout << val << " ";   // 1 2 3 4 5 6
    cout << endl;

    // Example 2 - descending sort
    std::list<int> l2 {2, 1, 6, 3, 5, 4};
    l2.sort(greater<int>());
    cout << "Descending : ";
    for(auto val : l2) cout << val << " ";   // 6 5 4 3 2 1
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// g) reverse()
//------------------------------------------------------------------------------
/*
  TITLE:
      reverse() - List ka order ulta karna

  SYNTAX:
      lst.reverse();

  DEFINITION:
      list ke saare elements ka order reverse kar deta hai.
      Pehla element aakhri ban jaata hai aur aakhri element pehla.
      NOTE: std::reverse() list ke saath kaam nahi karta —
      isliye lst.reverse() (member function) use karte hain.
*/
#include <iostream>
#include <list>
using namespace std;
int main(){
    // Example 1 - basic reverse
    std::list<int> l1 {1, 2, 3, 4, 5};
    l1.reverse();
    cout << "After reverse()        : ";
    for(auto val : l1) cout << val << " ";   // 5 4 3 2 1
    cout << endl;

    // Example 2 - sort karo phir reverse (descending effect)
    std::list<int> l2 {30, 10, 50, 20, 40};
    l2.sort();
    l2.reverse();
    cout << "After sort + reverse() : ";
    for(auto val : l2) cout << val << " ";   // 50 40 30 20 10
    cout << endl;

    return 0;
}


/*
================================================================================
  QUICK SUMMARY
================================================================================

  CATEGORY 1 - ELEMENT ACCESS
      front()          -> pehla element access / modify
      back()           -> aakhri element access / modify

  CATEGORY 2 - CAPACITY
      empty()          -> khali hai ya nahi (1/0)
      size()           -> current elements ka count
      max_size()       -> max elements ki limit

  CATEGORY 3 - MODIFIERS
      assign()         -> nai values assign karo (3 tarike)
      push_back()      -> end mein add
      push_front()     -> shuru mein add
      pop_back()       -> end se delete
      pop_front()      -> shuru se delete
      insert()         -> kisi position ke PEHLE add
      emplace()        -> kisi position pe in-place construct karke add
      emplace_back()   -> end mein in-place construct karke add
      emplace_front()  -> shuru mein in-place construct karke add
      swap()           -> do lists exchange karo
      resize()         -> size badha ya ghataao
      clear()          -> sab kuch hatao

  CATEGORY 4 - OPERATIONS
      splice()         -> doosri list ke elements move karo
      remove()         -> specific value ke sab instances hatao
      remove_if()      -> condition se hatao (lambda)
      unique()         -> consecutive duplicates hatao
      merge()          -> do sorted lists ek karo
      sort()           -> ascending / descending sort
      reverse()        -> order ulta karo

  LIST vs FORWARD_LIST
      front()          -> dono mein hai
      back()           -> sirf list mein
      size()           -> sirf list mein
      insert()         -> list: PEHLE insert | forward_list: insert_after()
      splice()         -> list | forward_list: splice_after()
      pop_back()       -> sirf list mein
      push_back()      -> sirf list mein

================================================================================
  COMPILE & RUN:
      g++ list_methods.cpp -o list_methods
      ./list_methods
================================================================================
*/