/*
================================================================================
        C++ STL — forward_list (Singly Linked List)
        Format: Title | Syntax | Definition | Examples
================================================================================

   WHAT IS forward_list?
   - Singly Linked List implement karta hai — har node sirf NEXT ko jaanta hai
   - Insertion, deletion, moving operations mein list se faster hai
   - Backward traversal NAHI ho sakta — sirf aage ja sakte ho
   - Direct element access NAHI hota (no index like array)

   forward_list  -->  next  -->  next  -->  next  -->  NULL
   list  <-->  prev/next  <-->  prev/next  <-->  prev/next

   HEADER: #include <forward_list>

   CATEGORIES:
   1. Element Access  -> front()
   2. Capacity        -> empty(), max_size()
   3. Modifiers       -> assign(), push_front(), pop_front(), emplace_front(),
                         emplace_after(), insert_after(), erase_after(),
                         swap(), resize(), clear()
   4. Operations      -> splice_after(), remove(), remove_if(), unique(),
                         merge(), sort(), reverse()
*/


//==============================================================================
// PRINT / TRAVERSE
//==============================================================================
/*
  TITLE:
      Forward List Print karna (Traversal)

  SYNTAX:
      for(auto val : flist) { }
      for(auto it = flist.begin(); it != flist.end(); it++)
      while(it != flist.end()) { ++it; }

  DEFINITION:
      forward_list mein index se access nahi hota, isliye loop lagake
      ek ek element print karte hain. Teen tarike hain — teeno ka output same hota hai.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> flist {10, 20, 30, 40, 50};

    // Mtd 1 - range-based for (sabse easy)
    cout << "Mtd 1 (range-based): ";
    for(auto val : flist) cout << val << " ";   // 10 20 30 40 50
    cout << endl;

    // Mtd 2 - while loop
    cout << "Mtd 2 (while loop) : ";
    auto it = flist.begin();
    while(it != flist.end()){ cout << *it << " "; ++it; }   // 10 20 30 40 50
    cout << endl;

    // Mtd 3 - for loop with iterator
    cout << "Mtd 3 (for loop)   : ";
    for(auto it = flist.begin(); it != flist.end(); it++) cout << *it << " ";
    cout << endl;   // 10 20 30 40 50

    return 0;
}


//==============================================================================
// CATEGORY 1 - ELEMENT ACCESS
// a) front() -> Access first element
//==============================================================================


//------------------------------------------------------------------------------
// a) front()
//------------------------------------------------------------------------------
/*
  TITLE:
      front() - Pehla element access karna

  SYNTAX:
      flist.front();

  DEFINITION:
      forward_list ka pehla (first) element return karta hai.
      Isse read bhi kar sakte ho aur modify bhi kar sakte ho.
      forward_list mein back() nahi hota - sirf front() hota hai.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> flist {10, 20, 30, 40};

    // Example 1 - pehla element read karna
    cout << "front() : " << flist.front() << endl;   // 10

    // Example 2 - front() se value modify karna
    flist.front() = 99;
    cout << "After front() = 99 : ";
    for(auto val : flist) cout << val << " ";   // 99 20 30 40
    cout << endl;

    return 0;
}


//==============================================================================
// CATEGORY 2 - CAPACITY
// a) empty()    -> Test whether list is empty
// b) max_size() -> Return maximum size
//==============================================================================


//------------------------------------------------------------------------------
// a) empty()
//------------------------------------------------------------------------------
/*
  TITLE:
      empty() - List khali hai ya nahi check karna

  SYNTAX:
      flist.empty();

  DEFINITION:
      Check karta hai ki forward_list mein koi element hai ya nahi.
      1 (true) return karta hai agar list empty ho, warna 0 (false).
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> fl1 {10, 20, 30};
    forward_list<int> fl2;

    // Example 1 - non-empty list
    cout << "fl1.empty() : " << fl1.empty() << endl;   // 0 (not empty)

    // Example 2 - empty list
    cout << "fl2.empty() : " << fl2.empty() << endl;   // 1 (empty)

    // Example 3 - clear ke baad check
    fl1.clear();
    cout << "fl1.empty() after clear() : " << fl1.empty() << endl;   // 1

    return 0;
}


//------------------------------------------------------------------------------
// b) max_size()
//------------------------------------------------------------------------------
/*
  TITLE:
      max_size() - Maximum kitne elements store ho sakte hain

  SYNTAX:
      flist.max_size();

  DEFINITION:
      System ke available memory ke hisaab se maximum elements ki limit batata hai.
      Yeh value bahut badi hoti hai - practically kabhi reach nahi hoti.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int>    fi;
    forward_list<double> fd;

    // Example 1 - int forward_list
    cout << "int max_size()    : " << fi.max_size() << endl;

    // Example 2 - double forward_list (int se thoda kam hoga)
    cout << "double max_size() : " << fd.max_size() << endl;

    return 0;
}


//==============================================================================
// CATEGORY 3 - MODIFIERS
// a) assign()        -> Assign content
// b) push_front()    -> Insert element at beginning
// c) pop_front()     -> Delete first element
// d) emplace_front() -> Construct and insert element at beginning
// e) emplace_after() -> Construct and insert element in-place after an element
// f) insert_after()  -> Insert elements after an element
// g) erase_after()   -> Erase elements after an element
// h) swap()          -> Swap content
// i) resize()        -> Changes the number of elements stored
// j) clear()         -> Clear content
//==============================================================================


//------------------------------------------------------------------------------
// a) assign()
//------------------------------------------------------------------------------
/*
  TITLE:
      assign() - List mein nai values assign karna

  SYNTAX:
      flist.assign({1, 2, 3});
      flist.assign(count, value);
      flist.assign(other.begin(), other.end());

  DEFINITION:
      forward_list ki purani values hatakar nai values daalta hai.
      Teen tareekon se use kar sakte ho - seedha values do,
      ek value baar baar do, ya kisi aur list se copy karo.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> fl1, fl2, fl3;

    // Example 1 - initializer list se
    fl1.assign({1, 2, 3, 4});
    cout << "fl1 (list)       : ";
    for(int& a : fl1) cout << a << " ";   // 1 2 3 4
    cout << endl;

    // Example 2 - 5 baar value 10
    fl2.assign(5, 10);
    cout << "fl2 (5 times 10) : ";
    for(int& b : fl2) cout << b << " ";   // 10 10 10 10 10
    cout << endl;

    // Example 3 - fl1 se copy
    fl3.assign(fl1.begin(), fl1.end());
    cout << "fl3 (copy fl1)   : ";
    for(int& c : fl3) cout << c << " ";   // 1 2 3 4
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// b) push_front()
//------------------------------------------------------------------------------
/*
  TITLE:
      push_front() - Shuru mein element add karna

  SYNTAX:
      flist.push_front(value);

  DEFINITION:
      forward_list ke bilkul SHURU mein ek naya element add karta hai.
      Har baar push_front() karo to naya element pehle aa jaata hai.
      Size 1 se badhta hai.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> flist {10, 20, 30};

    // Example 1 - ek element add
    flist.push_front(5);
    cout << "After push_front(5)    : ";
    for(auto val : flist) cout << val << " ";   // 5 10 20 30
    cout << endl;

    // Example 2 - multiple push_front
    flist.push_front(1);
    flist.push_front(2);
    cout << "After 2 more pushes    : ";
    for(auto val : flist) cout << val << " ";   // 2 1 5 10 20 30
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// c) pop_front()
//------------------------------------------------------------------------------
/*
  TITLE:
      pop_front() - Pehla element delete karna

  SYNTAX:
      flist.pop_front();

  DEFINITION:
      forward_list ka PEHLA element hata deta hai.
      Koi value return nahi karta. Size 1 se ghatta hai.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> flist {10, 20, 30, 40, 50};

    // Example 1 - ek baar pop
    flist.pop_front();
    cout << "After 1 pop_front : ";
    for(auto val : flist) cout << val << " ";   // 20 30 40 50
    cout << endl;

    // Example 2 - do baar pop
    flist.pop_front();
    flist.pop_front();
    cout << "After 2 more pops : ";
    for(auto val : flist) cout << val << " ";   // 40 50
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// d) emplace_front()
//------------------------------------------------------------------------------
/*
  TITLE:
      emplace_front() - Shuru mein element construct karke add karna

  SYNTAX:
      flist.emplace_front(value);

  DEFINITION:
      push_front() jaisa hi kaam karta hai - lekin element ko
      SEEDHA list ke andar construct karta hai (no copy, no move).
      Simple types (int) ke liye koi fark nahi - complex objects ke
      liye push_front() se zyada efficient hota hai.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> flist {10, 20, 30};

    // Example 1 - basic emplace_front
    flist.emplace_front(5);
    cout << "After emplace_front(5) : ";
    for(auto val : flist) cout << val << " ";   // 5 10 20 30
    cout << endl;

    // Example 2 - multiple emplace_front
    flist.emplace_front(1);
    flist.emplace_front(2);
    cout << "After 2 more           : ";
    for(auto val : flist) cout << val << " ";   // 2 1 5 10 20 30
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// e) emplace_after()
//------------------------------------------------------------------------------
/*
  TITLE:
      emplace_after() - Kisi element ke baad construct karke insert karna

  SYNTAX:
      flist.emplace_after(iterator, value);

  DEFINITION:
      insert_after() jaisa kaam karta hai - lekin element seedha
      list ke andar construct hota hai (no copy, no move).
      Jo iterator point kar raha hai us element ke BAAD naya element aata hai.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> flist {10, 20, 30, 40};

    // Example 1 - begin() ke baad
    flist.emplace_after(flist.begin(), 99);
    cout << "After emplace_after(begin, 99)        : ";
    for(auto val : flist) cout << val << " ";   // 10 99 20 30 40
    cout << endl;

    // Example 2 - before_begin() ke baad (bilkul shuru mein)
    flist.emplace_after(flist.before_begin(), 55);
    cout << "After emplace_after(before_begin, 55) : ";
    for(auto val : flist) cout << val << " ";   // 55 10 99 20 30 40
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// f) insert_after()
//------------------------------------------------------------------------------
/*
  TITLE:
      insert_after() - Kisi bhi position ke BAAD element insert karna

  SYNTAX:
      flist.insert_after(iterator, value);
      flist.insert_after(iterator, count, value);
      flist.insert_after(iterator, {1, 2, 3});

  DEFINITION:
      Jo iterator point kar raha hai us element ke BAAD naya element daalta hai.
      before_begin() use karo to bilkul shuru mein insert ho -
      begin() use karo to pehle element ke baad insert ho.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    // Example 1 - begin() ke baad single value
    forward_list<int> fl1 {10, 20, 30, 40};
    fl1.insert_after(fl1.begin(), 99);
    cout << "insert_after(begin, 99)          : ";
    for(auto val : fl1) cout << val << " ";   // 10 99 20 30 40
    cout << endl;

    // Example 2 - before_begin() ke baad (bilkul shuru mein)
    forward_list<int> fl2 {10, 20, 30, 40};
    fl2.insert_after(fl2.before_begin(), 99);
    cout << "insert_after(before_begin, 99)   : ";
    for(auto val : fl2) cout << val << " ";   // 99 10 20 30 40
    cout << endl;

    // Example 3 - initializer list insert
    forward_list<int> fl3 {10, 20, 30};
    fl3.insert_after(fl3.before_begin(), {1, 2, 3});
    cout << "insert_after(before_begin,1,2,3) : ";
    for(auto val : fl3) cout << val << " ";   // 1 2 3 10 20 30
    cout << endl;

    // Example 4 - count times same value
    forward_list<int> fl4 {10, 20, 30};
    fl4.insert_after(fl4.before_begin(), 2, 11);
    cout << "insert_after(before_begin,2,11)  : ";
    for(auto val : fl4) cout << val << " ";   // 11 11 10 20 30
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// g) erase_after()
//------------------------------------------------------------------------------
/*
  TITLE:
      erase_after() - Kisi element ke BAAD wala element delete karna

  SYNTAX:
      flist.erase_after(iterator);
      flist.erase_after(first_it, last_it);

  DEFINITION:
      Jo iterator point kar raha hai us element ke BAAD wala element hata deta hai.
      forward_list mein seedha kisi position pe erase nahi ho sakta -
      hamesha BAAD wala element erase hota hai.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    // Example 1 - begin() ke baad wala delete
    forward_list<int> fl1 {10, 20, 30, 40, 50};
    fl1.erase_after(fl1.begin());   // 20 delete hoga
    cout << "erase_after(begin)        : ";
    for(auto val : fl1) cout << val << " ";   // 10 30 40 50
    cout << endl;

    // Example 2 - before_begin() ke baad wala (pehla element)
    forward_list<int> fl2 {10, 20, 30, 40, 50};
    fl2.erase_after(fl2.before_begin());   // 10 delete hoga
    cout << "erase_after(before_begin) : ";
    for(auto val : fl2) cout << val << " ";   // 20 30 40 50
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// h) swap()
//------------------------------------------------------------------------------
/*
  TITLE:
      swap() - Do forward_lists ke contents exchange karna

  SYNTAX:
      fl1.swap(fl2);

  DEFINITION:
      Do forward_lists ke saare elements aapas mein exchange ho jaate hain.
      Dono lists ka size alag bhi ho sakta hai - koi issue nahi.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> fl1 {1, 2, 3};
    forward_list<int> fl2 {10, 20, 30, 40, 50};

    fl1.swap(fl2);

    // Example 1
    cout << "fl1 after swap : ";
    for(auto val : fl1) cout << val << " ";   // 10 20 30 40 50
    cout << endl;

    // Example 2
    cout << "fl2 after swap : ";
    for(auto val : fl2) cout << val << " ";   // 1 2 3
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// i) resize()
//------------------------------------------------------------------------------
/*
  TITLE:
      resize() - List ka size change karna

  SYNTAX:
      flist.resize(new_size);
      flist.resize(new_size, value);

  DEFINITION:
      forward_list ka size badha ya ghata sakta hai.
      Agar size badhao to nai jagah 0 (ya given value) se fill hoti hai.
      Agar size ghataao to extra elements end se cut ho jaate hain.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    // Example 1 - size badhana (nai jagah 0 se fill)
    forward_list<int> fl1 {10, 20, 30};
    fl1.resize(6);
    cout << "After resize(6)      : ";
    for(auto val : fl1) cout << val << " ";   // 10 20 30 0 0 0
    cout << endl;

    // Example 2 - size badhana with value
    forward_list<int> fl2 {10, 20, 30};
    fl2.resize(6, 99);
    cout << "After resize(6, 99)  : ";
    for(auto val : fl2) cout << val << " ";   // 10 20 30 99 99 99
    cout << endl;

    // Example 3 - size ghataana
    forward_list<int> fl3 {10, 20, 30, 40, 50};
    fl3.resize(3);
    cout << "After resize(3)      : ";
    for(auto val : fl3) cout << val << " ";   // 10 20 30
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// j) clear()
//------------------------------------------------------------------------------
/*
  TITLE:
      clear() - List ke saare elements delete karna

  SYNTAX:
      flist.clear();

  DEFINITION:
      forward_list ke SAARE elements ek baar mein hata deta hai.
      Baad mein empty() check karo to 1 (true) aata hai.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> flist {10, 20, 30, 40, 50};

    // Example 1 - clear ke pehle
    cout << "Before clear - empty() : " << flist.empty() << endl;   // 0

    flist.clear();

    // Example 2 - clear ke baad
    cout << "After clear  - empty() : " << flist.empty() << endl;   // 1
    cout << "Elements after clear   : (empty)" << endl;

    return 0;
}


//==============================================================================
// CATEGORY 4 - OPERATIONS
// a) splice_after() -> Transfer elements from another forward_list
// b) remove()       -> Remove elements with specific value
// c) remove_if()    -> Remove elements fulfilling condition
// d) unique()       -> Remove duplicate values
// e) merge()        -> Merge sorted lists
// f) sort()         -> Sort elements in container
// g) reverse()      -> Reverse the order of elements
//==============================================================================


//------------------------------------------------------------------------------
// a) splice_after()
//------------------------------------------------------------------------------
/*
  TITLE:
      splice_after() - Ek list ke elements doosri list mein transfer karna

  SYNTAX:
      fl1.splice_after(iterator, fl2);
      fl1.splice_after(iterator, fl2, pos);
      fl1.splice_after(iterator, fl2, first, last);

  DEFINITION:
      fl2 ke elements fl1 mein move ho jaate hain - copy nahi, move hota hai.
      Jis iterator pe splice karo us ke BAAD elements insert hote hain.
      fl2 ke jo elements transfer hue woh fl2 se hata jaate hain.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    // Example 1 - poori list begin ke baad transfer
    forward_list<int> fl1 {1, 2, 3};
    forward_list<int> fl2 {10, 20, 30};
    fl1.splice_after(fl1.begin(), fl2);
    cout << "fl1 after splice_after(begin)        : ";
    for(auto val : fl1) cout << val << " ";   // 1 10 20 30 2 3
    cout << endl;
    cout << "fl2 after splice                     : ";
    cout << (fl2.empty() ? "empty" : "not empty") << endl;   // empty

    // Example 2 - before_begin pe splice (bilkul shuru mein)
    forward_list<int> fl3 {1, 2, 3};
    forward_list<int> fl4 {10, 20, 30};
    fl3.splice_after(fl3.before_begin(), fl4);
    cout << "fl3 after splice_after(before_begin) : ";
    for(auto val : fl3) cout << val << " ";   // 10 20 30 1 2 3
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
      flist.remove(value);

  DEFINITION:
      List mein jo value batao - jitni baar bhi aaye sab instances
      ek saath hata deta hai. Ek baar mein saare duplicates bhi remove ho jaate hain.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> flist {10, 40, 20, 40, 30, 40, 50};

    // Example 1 - single value ke saare instances remove
    flist.remove(40);
    cout << "After remove(40) : ";
    for(int& c : flist) cout << c << " ";   // 10 20 30 50
    cout << endl;

    // Example 2 - value jo exist nahi karti (kuch nahi hoga)
    flist.remove(99);
    cout << "After remove(99) : ";
    for(int& c : flist) cout << c << " ";   // 10 20 30 50
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
      flist.remove_if([](int x){ return condition; });

  DEFINITION:
      Ek condition (lambda function) do - jo elements us condition ko
      satisfy karte hain woh sab hata do.
      remove() se zyada flexible hai kyunki custom condition de sakte ho.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    // Example 1 - 20 se bade sab hato
    forward_list<int> fl1 {10, 20, 30, 25, 40, 15, 50};
    fl1.remove_if([](int x){ return x > 20; });
    cout << "After remove_if(x > 20) : ";
    for(int& c : fl1) cout << c << " ";   // 10 20 15
    cout << endl;

    // Example 2 - even numbers hato
    forward_list<int> fl2 {1, 2, 3, 4, 5, 6, 7, 8};
    fl2.remove_if([](int x){ return x % 2 == 0; });
    cout << "After remove_if(even)   : ";
    for(int& c : fl2) cout << c << " ";   // 1 3 5 7
    cout << endl;

    // Example 3 - negative numbers hato
    forward_list<int> fl3 {-5, 10, -3, 20, -1, 30};
    fl3.remove_if([](int x){ return x < 0; });
    cout << "After remove_if(x < 0) : ";
    for(int& c : fl3) cout << c << " ";   // 10 20 30
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
      flist.unique();

  DEFINITION:
      Ek ke baad ek aane wale SAME elements mein se extra copies hata deta hai.
      IMPORTANT: Sirf consecutive duplicates hataata hai -
      isliye pehle sort() karo, phir unique() lagao complete deduplication ke liye.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    // Example 1 - consecutive duplicates
    forward_list<int> fl1 {10, 10, 20, 20, 20, 30, 40};
    fl1.unique();
    cout << "After unique() (consecutive) : ";
    for(auto val : fl1) cout << val << " ";   // 10 20 30 40
    cout << endl;

    // Example 2 - sort pehle phir unique (complete deduplication)
    forward_list<int> fl2 {30, 10, 20, 10, 30, 20};
    fl2.sort();
    fl2.unique();
    cout << "After sort() + unique()      : ";
    for(auto val : fl2) cout << val << " ";   // 10 20 30
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
      fl1.merge(fl2);

  DEFINITION:
      Do already sorted forward_lists ko merge karke ek sorted list bana deta hai.
      fl2 ke elements fl1 mein aa jaate hain aur fl2 empty ho jaati hai.
      IMPORTANT: Dono lists pehle se sorted honi chahiye.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    // Example 1 - basic merge
    forward_list<int> fl1 {10, 20, 30, 40};
    forward_list<int> fl2 {15, 25, 35, 55};
    fl1.merge(fl2);
    cout << "After merge()      : ";
    for(auto val : fl1) cout << val << " ";   // 10 15 20 25 30 35 40 55
    cout << endl;
    cout << "fl2 after merge    : " << (fl2.empty() ? "empty" : "not empty") << endl;

    // Example 2 - sort karo phir merge
    forward_list<int> fl3 {50, 10, 30};
    forward_list<int> fl4 {40, 20, 60};
    fl3.sort();
    fl4.sort();
    fl3.merge(fl4);
    cout << "After sort + merge : ";
    for(auto val : fl3) cout << val << " ";   // 10 20 30 40 50 60
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// f) sort()
//------------------------------------------------------------------------------
/*
  TITLE:
      sort() - Forward list ko sort karna

  SYNTAX:
      flist.sort();                  // ascending (default)
      flist.sort(greater<int>());    // descending

  DEFINITION:
      forward_list ke elements ko sort karta hai.
      NOTE: std::sort() yahan kaam nahi karta kyunki forward_list ke
      iterators random access support nahi karte -
      isliye flist.sort() (member function) use karte hain.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    // Example 1 - ascending sort
    forward_list<int> fl1 {10, 90, 20, 80, 30, 70, 50};
    fl1.sort();
    cout << "Ascending  : ";
    for(auto val : fl1) cout << val << " ";   // 10 20 30 50 70 80 90
    cout << endl;

    // Example 2 - descending sort
    forward_list<int> fl2 {10, 90, 20, 80, 30, 70, 50};
    fl2.sort(greater<int>());
    cout << "Descending : ";
    for(auto val : fl2) cout << val << " ";   // 90 80 70 50 30 20 10
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// g) reverse()
//------------------------------------------------------------------------------
/*
  TITLE:
      reverse() - Forward list ka order ulta karna

  SYNTAX:
      flist.reverse();

  DEFINITION:
      forward_list ke saare elements ka order reverse kar deta hai.
      Pehla element aakhri ban jaata hai aur aakhri element pehla.
      NOTE: std::reverse() yahan kaam nahi karta -
      isliye flist.reverse() (member function) use karte hain.
*/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    // Example 1 - basic reverse
    forward_list<int> fl1 {10, 20, 30, 40, 50};
    fl1.reverse();
    cout << "After reverse()        : ";
    for(auto val : fl1) cout << val << " ";   // 50 40 30 20 10
    cout << endl;

    // Example 2 - sort karo phir reverse (descending effect)
    forward_list<int> fl2 {30, 10, 50, 20, 40};
    fl2.sort();
    fl2.reverse();
    cout << "After sort + reverse() : ";
    for(auto val : fl2) cout << val << " ";   // 50 40 30 20 10
    cout << endl;

    return 0;
}


/*
================================================================================
  QUICK SUMMARY
================================================================================

  CATEGORY 1 - ELEMENT ACCESS
      front()          -> pehla element access / modify

  CATEGORY 2 - CAPACITY
      empty()          -> khali hai ya nahi (1/0)
      max_size()       -> max elements ki limit

  CATEGORY 3 - MODIFIERS
      assign()         -> nai values assign karo (3 tarike)
      push_front()     -> shuru mein add
      pop_front()      -> shuru se delete
      emplace_front()  -> shuru mein in-place construct karke add
      emplace_after()  -> kisi ke BAAD in-place construct karke add
      insert_after()   -> kisi ke BAAD add (single / count / list)
      erase_after()    -> kisi ke BAAD wala delete
      swap()           -> do lists exchange karo
      resize()         -> size badha ya ghataao
      clear()          -> sab kuch hatao

  CATEGORY 4 - OPERATIONS
      splice_after()   -> doosri list ke elements move karo
      remove()         -> specific value ke sab instances hatao
      remove_if()      -> condition se hatao (lambda)
      unique()         -> consecutive duplicates hatao
      merge()          -> do sorted lists ek karo
      sort()           -> ascending / descending sort
      reverse()        -> order ulta karo

================================================================================
  COMPILE & RUN:
      g++ forward_list_methods.cpp -o forward_list_methods
      ./forward_list_methods
================================================================================
*/