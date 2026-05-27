/*
================================================================================
        C++ STL — Iterators (Sab Kuch Easy Way Mein)
        Format: Title | Syntax | Definition | Examples
================================================================================

   WHAT IS AN ITERATOR?
   - Iterator ek POINTER jaisi cheez hai — container ke elements pe point karta hai
   - Seedha index use karne ki jagah iterator se traverse karte hain
   - Sab STL containers ke saath kaam karta hai — vector, list, map, set, sab
   - Algorithms (sort, find, reverse) iterators ke through hi kaam karte hain

   VISUALIZATION:
       vector<int> v = {10, 20, 30, 40, 50};
                         ↑                  ↑
                      begin()             end()
                      (pehla)        (last ke baad)

   HEADER: #include <iterator>  (mostly auto-included hota hai)

   CATEGORIES:
   1. Types            -> input, output, forward, bidirectional, random access
   2. Basic Iterators  -> begin(), end()
   3. Reverse          -> rbegin(), rend()
   4. Constant         -> cbegin(), cend(), crbegin(), crend()
   5. Operations       -> advance(), next(), prev(), distance()
   6. Iterator Arithmetic
   7. Iterator with Algorithms
   8. Iterator per Container (vector, list, map, set)
*/


//==============================================================================
// ITERATOR TYPES — 5 TYPES
//==============================================================================
/*
  TITLE:
      Iterator ke 5 Types — Kaunsa Container Kaunsa Support Karta Hai

  DEFINITION:
      Har iterator type ke alag capabilities hote hain.
      Neeche se upar — har type neeche waale ki sabse zyada
      capabilities support karta hai.

  ┌─────────────────────────────────────────────────────────────────┐
  │  TYPE               │ CONTAINERS        │ CAN DO               │
  ├─────────────────────────────────────────────────────────────────┤
  │  Input Iterator     │ istream           │ sirf read, aage       │
  │  Output Iterator    │ ostream           │ sirf write, aage      │
  │  Forward Iterator   │ forward_list      │ read+write, aage      │
  │  Bidirectional      │ list, map, set    │ aage + peeche         │
  │  Random Access      │ vector, deque,    │ sab kuch + jump       │
  │                     │ array, string     │ (it+5, it-3, it[2])   │
  └─────────────────────────────────────────────────────────────────┘

  NOTE:
      Random Access sabse powerful hai — vector iska use karta hai.
      list mein Random Access NAHI hota — sirf Bidirectional hota hai.
*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main(){
    // Random Access Iterator (vector)
    vector<int> v = {10, 20, 30, 40, 50};
    auto it1 = v.begin();
    cout << "it1 + 2  : " << *(it1 + 2) << "\n";   // 30 (jump allowed)
    cout << "it1[3]   : " << it1[3]     << "\n";   // 40 (index allowed)

    // Bidirectional Iterator (list)
    list<int> l = {10, 20, 30};
    auto it2 = l.begin();
    ++it2;   // aage ja sakte ho
    --it2;   // peeche bhi ja sakte ho
    cout << "list it  : " << *it2 << "\n";   // 10

    // it2 + 2;  // ❌ Error — list mein jump nahi hota

    return 0;
}


//==============================================================================
// CATEGORY 1 — BASIC ITERATORS
// a) begin() -> Pehle element ka iterator
// b) end()   -> Last element ke BAAD ka iterator
//==============================================================================


//------------------------------------------------------------------------------
// a) begin()
//------------------------------------------------------------------------------
/*
  TITLE:
      begin() - Pehle element ka iterator lena

  SYNTAX:
      container.begin();
      std::begin(container);   // global version

  DEFINITION:
      Container ke PEHLE element ka iterator return karta hai.
      * (dereference) se value access karte hain.
      ++ se agle element pe jaate hain.
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};

    // Example 1 - pehla element access karo
    auto it = v.begin();
    cout << "begin()  : " << *it << "\n";   // 10

    // Example 2 - modify karo via iterator
    *it = 99;
    cout << "After *it = 99 : " << v[0] << "\n";   // 99

    // Example 3 - aage badhao
    ++it;
    cout << "After ++it : " << *it << "\n";   // 20

    return 0;
}


//------------------------------------------------------------------------------
// b) end()
//------------------------------------------------------------------------------
/*
  TITLE:
      end() - Last element ke BAAD ka iterator (sentinel)

  SYNTAX:
      container.end();

  DEFINITION:
      end() last element pe POINT NAHI karta — last ke EK BAAD wali
      position pe point karta hai. Ise "past-the-end" iterator kehte hain.
      *end() kabhi mat karo — undefined behaviour hoga.
      Loop condition mein it != end() use karte hain.
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};

    // Example 1 - end() se pehle wala (last element)

    auto it = v.end();
    --it;   // ek peeche aao
    cout << *(v.end()-1) ;
    cout << "Last element : " << *it << "\n";   // 50

    // Example 2 - begin to end traverse
    cout << "Full traverse : ";
    for(auto i = v.begin(); i != v.end(); ++i){
        cout << *i << " ";   // 10 20 30 40 50
    }
    cout << "\n";

    // Example 3 - *v.end() mat karo ❌
    // cout << *v.end(); // ❌ Undefined Behaviour!

    return 0;
}


//==============================================================================
// CATEGORY 2 — REVERSE ITERATORS
// a) rbegin() -> Last element ka reverse iterator
// b) rend()   -> Pehle element se PEHLE (reverse sentinel)
//==============================================================================


//------------------------------------------------------------------------------
// a) rbegin()
//------------------------------------------------------------------------------
/*
  TITLE:
      rbegin() - Last element se shuru hone wala reverse iterator

  SYNTAX:
      container.rbegin();

  DEFINITION:
      Container ke LAST element ka reverse iterator return karta hai.
      ++ karne pe PEECHE jaata hai (ulta hota hai normal se).
      Reverse traversal ke liye use hota hai.
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};

    // Example 1 - last element
    auto rit = v.rbegin();
    cout << "rbegin() : " << *rit << "\n";   // 50

    // Example 2 - ++ se peeche jaana
    ++rit;
    cout << "After ++rit : " << *rit << "\n";   // 40

    // Example 3 - reverse traverse
    cout << "Reverse : ";
    for(auto i = v.rbegin(); i != v.rend(); ++i){
        cout << *i << " ";   // 50 40 30 20 10
    }
    cout << "\n";

    return 0;
}


//------------------------------------------------------------------------------
// b) rend()
//------------------------------------------------------------------------------
/*
  TITLE:
      rend() - Reverse traversal ka sentinel (pehle se pehle)

  SYNTAX:
      container.rend();

  DEFINITION:
      rend() pehle element se EK PEHLE wali position pe point karta hai.
      Reverse loop mein condition: rit != rend()
      *rend() kabhi mat karo — undefined behaviour.
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};

    // Example 1 - rend() se ek baad (pehla element)
    auto rit = v.rend();
    --rit;
    cout << "rend()-1 (first element) : " << *rit << "\n";   // 10

    // Example 2 - reverse loop
    cout << "Reverse loop : ";
    for(auto i = v.rbegin(); i != v.rend(); ++i){
        cout << *i << " ";   // 50 40 30 20 10
    }
    cout << "\n";

    return 0;
}


//==============================================================================
// CATEGORY 3 — CONSTANT ITERATORS
// a) cbegin()  / cend()   -> Read-only forward
// b) crbegin() / crend()  -> Read-only reverse
//==============================================================================


//------------------------------------------------------------------------------
// a) cbegin() / cend()
//------------------------------------------------------------------------------
/*
  TITLE:
      cbegin() / cend() - Read-only iterator (modify nahi kar sakte)

  SYNTAX:
      container.cbegin();
      container.cend();

  DEFINITION:
      'c' = constant — yahan se value READ kar sakte ho, MODIFY nahi.
      *cit = 99;  // ❌ Error — const iterator se modification nahi hoti
      Jab sirf read karna ho tab use karo — accidental modification se bachata hai.
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};

    // Example 1 - cbegin se read
    auto cit = v.cbegin();
    cout << "cbegin() : " << *cit << "\n";   // 10

    // *cit = 99;  // ❌ Error — read-only hai

    // Example 2 - cbegin to cend traverse
    cout << "const traverse : ";
    for(auto i = v.cbegin(); i != v.cend(); ++i){
        cout << *i << " ";   // 10 20 30 40 50
    }
    cout << "\n";

    return 0;
}


//------------------------------------------------------------------------------
// b) crbegin() / crend()
//------------------------------------------------------------------------------
/*
  TITLE:
      crbegin() / crend() - Read-only reverse iterator

  SYNTAX:
      container.crbegin();
      container.crend();

  DEFINITION:
      rbegin() + cbegin() ka combination — reverse + read-only.
      Reverse traverse karo, lekin modify nahi kar sakte.
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};

    // Example 1 - reverse read-only traverse
    cout << "crbegin traverse : ";
    for(auto i = v.crbegin(); i != v.crend(); ++i){
        cout << *i << " ";   // 50 40 30 20 10
    }
    cout << "\n";

    // *v.crbegin() = 99;  // ❌ Error — const hai

    return 0;
}


//==============================================================================
// CATEGORY 4 — ITERATOR OPERATIONS
// a) advance()   -> Iterator ko N steps aage/peeche move karo
// b) next()      -> N steps aage wala naya iterator lo
// c) prev()      -> N steps peeche wala naya iterator lo
// d) distance()  -> Do iterators ke beech distance nikalo
//==============================================================================


//------------------------------------------------------------------------------
// a) advance()
//------------------------------------------------------------------------------
/*
  TITLE:
      advance() - Iterator ko N steps move karna (in-place)

  SYNTAX:
      std::advance(it, n);    // n aage
      std::advance(it, -n);   // n peeche (bidirectional/random only)

  DEFINITION:
      Iterator ko N steps aage ya peeche move karta hai — ORIGINAL iterator badalta hai.
      next() se alag — advance() original ko modify karta hai.
      Negative n ke liye bidirectional ya random access iterator chahiye.
*/
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};

    // Example 1 - 2 steps aage
    auto it = v.begin();
    advance(it, 2);
    cout << "After advance(it, 2)  : " << *it << "\n";   // 30

    // Example 2 - 1 step peeche
    advance(it, -1);
    cout << "After advance(it, -1) : " << *it << "\n";   // 20

    // Example 3 - list mein advance (bidirectional)
    list<int> l = {10, 20, 30, 40};
    auto lit = l.begin();
    advance(lit, 3);
    cout << "list advance(3)       : " << *lit << "\n";   // 40

    return 0;
}


//------------------------------------------------------------------------------
// b) next()
//------------------------------------------------------------------------------
/*
  TITLE:
      next() - N steps aage wala NAYA iterator lena (original safe)

  SYNTAX:
      std::next(it);       // 1 step aage
      std::next(it, n);    // n steps aage

  DEFINITION:
      Iterator ko N steps aage move karta hai — lekin ORIGINAL nahi badalta.
      Naya iterator return karta hai.
      advance() original modify karta hai — next() naya banata hai.
*/
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};
    auto it = v.begin();

    // Example 1 - 1 step aage (original safe)
    auto it2 = next(it);
    cout << "original it  : " << *it  << "\n";   // 10 (unchanged)
    cout << "next(it)     : " << *it2 << "\n";   // 20

    // Example 2 - 3 steps aage
    auto it3 = next(it, 3);
    cout << "next(it, 3)  : " << *it3 << "\n";   // 40

    // Example 3 - end se pehle wala element (last element)
    auto last = next(v.begin(), v.size() - 1);
    cout << "last element : " << *last << "\n";   // 50

    return 0;
}


//------------------------------------------------------------------------------
// c) prev()
//------------------------------------------------------------------------------
/*
  TITLE:
      prev() - N steps peeche wala NAYA iterator lena (original safe)

  SYNTAX:
      std::prev(it);       // 1 step peeche
      std::prev(it, n);    // n steps peeche

  DEFINITION:
      Iterator ko N steps peeche move karta hai — ORIGINAL nahi badalta.
      Naya iterator return karta hai.
      end() se last element access karne ka sabse clean tarika.
*/
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};
    auto it = v.end();

    // Example 1 - 1 step peeche (last element)
    auto last = prev(it);
    cout << "prev(end)    : " << *last << "\n";   // 50

    // Example 2 - 2 steps peeche
    auto it2 = prev(it, 2);
    cout << "prev(end, 2) : " << *it2 << "\n";   // 40

    // Example 3 - original unchanged
    cout << "original it  : " << (it == v.end() ? "end" : "not end") << "\n";   // end

    return 0;
}


//------------------------------------------------------------------------------
// d) distance()
//------------------------------------------------------------------------------
/*
  TITLE:
      distance() - Do iterators ke beech kitne steps ka fark hai

  SYNTAX:
      std::distance(first, last);

  DEFINITION:
      first se last tak kitne steps hain woh return karta hai.
      Random access iterator mein O(1) — subtraction se.
      List jaise bidirectional mein O(n) — ek ek step count karta hai.
      hamesha first → last direction mein count karo — agar ulta ho to negative aata hai.
*/
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};

    // Example 1 - begin to end
    cout << "distance(begin,end)  : " << distance(v.begin(), v.end()) << "\n";   // 5

    // Example 2 - begin to some iterator
    auto it = v.begin();
    advance(it, 3);
    cout << "distance(begin, it)  : " << distance(v.begin(), it) << "\n";   // 3

    // Example 3 - list mein distance
    list<int> l = {10, 20, 30, 40};
    cout << "list distance        : " << distance(l.begin(), l.end()) << "\n";   // 4

    return 0;
}


//==============================================================================
// CATEGORY 5 — ITERATOR ARITHMETIC (Random Access Only)
//==============================================================================
/*
  TITLE:
      Iterator Arithmetic — Vector / Deque / Array mein hi kaam karta hai

  SYNTAX:
      it + n     // n steps aage
      it - n     // n steps peeche
      it1 - it2  // do iterators ka distance
      it[n]      // nth element access (array style)
      it++       // ek aage
      it--       // ek peeche
      it1 < it2  // comparison

  DEFINITION:
      Random access iterators pe directly +, -, [], comparison sab kaam karta hai.
      list, map, set mein ye NAHI chalta — unhe advance()/next()/prev() use karo.
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};
    auto it = v.begin();

    // Example 1 - it + n
    cout << "*(it + 2) : " << *(it + 2) << "\n";   // 30

    // Example 2 - it - n
    auto it2 = v.end();
    cout << "*(it2 - 1): " << *(it2 - 1) << "\n";   // 50

    // Example 3 - distance via subtraction
    auto it3 = v.begin() + 3;
    cout << "it3 - it  : " << (it3 - it) << "\n";   // 3

    // Example 4 - array style access
    cout << "it[0]     : " << it[0] << "\n";   // 10
    cout << "it[4]     : " << it[4] << "\n";   // 50

    // Example 5 - comparison
    auto a = v.begin();
    auto b = v.begin() + 3;
    cout << "a < b     : " << (a < b) << "\n";   // 1 (true)

    return 0;
}


//==============================================================================
// CATEGORY 6 — ITERATOR WITH STL ALGORITHMS
//==============================================================================
/*
  TITLE:
      Iterators + Algorithms — sort, find, reverse, count, fill

  DEFINITION:
      STL ke saare algorithms iterators ke through kaam karte hain.
      begin() aur end() pass karte hain — algorithm usi range pe kaam karta hai.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main(){
    vector<int> v = {30, 10, 50, 20, 40};

    // Example 1 - sort (begin to end)
    sort(v.begin(), v.end());
    cout << "After sort       : ";
    for(auto x : v) cout << x << " ";   // 10 20 30 40 50
    cout << "\n";

    // Example 2 - reverse
    reverse(v.begin(), v.end());
    cout << "After reverse    : ";
    for(auto x : v) cout << x << " ";   // 50 40 30 20 10
    cout << "\n";

    // Example 3 - find (returns iterator)
    auto found = find(v.begin(), v.end(), 30);
    if(found != v.end()){
        cout << "Found 30 at pos  : " << distance(v.begin(), found) << "\n";   // 2
    }

    // Example 4 - count
    vector<int> v2 = {1, 2, 2, 3, 2, 4};
    cout << "Count of 2       : " << count(v2.begin(), v2.end(), 2) << "\n";   // 3

    // Example 5 - fill (sab ko ek value se bhar do)
    vector<int> v3(5);
    fill(v3.begin(), v3.end(), 7);
    cout << "After fill(7)    : ";
    for(auto x : v3) cout << x << " ";   // 7 7 7 7 7
    cout << "\n";

    // Example 6 - partial range sort (sirf pehle 3)
    vector<int> v4 = {30, 10, 50, 20, 40};
    sort(v4.begin(), v4.begin() + 3);   // sirf pehle 3 sort hoge
    cout << "Partial sort     : ";
    for(auto x : v4) cout << x << " ";   // 10 30 50 20 40
    cout << "\n";

    return 0;
}


//==============================================================================
// CATEGORY 7 — ITERATOR PER CONTAINER
//==============================================================================


//------------------------------------------------------------------------------
// Vector Iterator
//------------------------------------------------------------------------------
/*
  TITLE:
      Vector Iterator — Random Access (sabse powerful)

  DEFINITION:
      Vector ka iterator Random Access hai — +, -, [], comparison sab allowed.
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v = {10, 20, 30, 40, 50};

    // forward
    cout << "Forward  : ";
    for(auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";   // 10 20 30 40 50
    cout << "\n";

    // reverse
    cout << "Reverse  : ";
    for(auto it = v.rbegin(); it != v.rend(); ++it)
        cout << *it << " ";   // 50 40 30 20 10
    cout << "\n";

    // jump access
    auto it = v.begin();
    cout << "Jump +3  : " << *(it + 3) << "\n";   // 40

    return 0;
}


//------------------------------------------------------------------------------
// List Iterator
//------------------------------------------------------------------------------
/*
  TITLE:
      List Iterator — Bidirectional (aage + peeche, jump nahi)

  DEFINITION:
      List ka iterator Bidirectional hai — ++ aur -- dono kaam karte hain
      lekin + 3 ya it[2] NAHI kaam karta. advance()/next() use karo.
*/
#include <iostream>
#include <list>
#include <iterator>
using namespace std;
int main(){
    list<int> l = {10, 20, 30, 40, 50};

    // forward
    cout << "Forward  : ";
    for(auto it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";   // 10 20 30 40 50
    cout << "\n";

    // reverse
    cout << "Reverse  : ";
    for(auto it = l.rbegin(); it != l.rend(); ++it)
        cout << *it << " ";   // 50 40 30 20 10
    cout << "\n";

    // advance se jump
    auto it = l.begin();
    advance(it, 2);
    cout << "advance(it,2) : " << *it << "\n";   // 30

    // it + 2;  // ❌ Error — list mein nahi chalta

    return 0;
}


//------------------------------------------------------------------------------
// Map Iterator
//------------------------------------------------------------------------------
/*
  TITLE:
      Map Iterator — Bidirectional, key-value pair access

  DEFINITION:
      Map ka iterator {key, value} pair return karta hai.
      it->first = key, it->second = value.
      Map sorted rehta hai — traverse hamesha key order mein hoga.
*/
#include <iostream>
#include <map>
using namespace std;
int main(){
    map<string, int> m = {{"Ankit", 25}, {"Priya", 22}, {"Rahul", 23}};

    // forward (key sorted order mein)
    cout << "Map traverse :\n";
    for(auto it = m.begin(); it != m.end(); ++it){
        cout << "  " << it->first << " → " << it->second << "\n";
    }
    // Ankit → 25
    // Priya → 22
    // Rahul → 23

    // find via iterator
    auto found = m.find("Priya");
    if(found != m.end()){
        cout << "Found : " << found->second << "\n";   // 22
    }

    return 0;
}


//------------------------------------------------------------------------------
// Set Iterator
//------------------------------------------------------------------------------
/*
  TITLE:
      Set Iterator — Bidirectional, read-only values

  DEFINITION:
      Set ka iterator Bidirectional hai.
      Set ke elements MODIFY nahi kar sakte via iterator — sorted order maintain rehti hai.
      *it se value read kar sakte ho sirf.
*/
#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> s = {30, 10, 50, 20, 40};

    // forward (sorted order mein)
    cout << "Set traverse : ";
    for(auto it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";   // 10 20 30 40 50
    cout << "\n";

    // reverse
    cout << "Set reverse  : ";
    for(auto it = s.rbegin(); it != s.rend(); ++it)
        cout << *it << " ";   // 50 40 30 20 10
    cout << "\n";

    // *it = 99;  // ❌ Error — set values modify nahi kar sakte

    return 0;
}


/*
================================================================================
  QUICK SUMMARY
================================================================================

  ITERATOR TYPES:
      Random Access    vector, deque, array     +, -, [], comparison — sab
      Bidirectional    list, map, set            ++ aur -- only
      Forward          forward_list              sirf ++
      Input/Output     streams                   sirf read / sirf write

  BASIC:
      begin()          pehla element
      end()            last ke BAAD (kabhi dereference mat karo)
      rbegin()         last element (reverse se shuru)
      rend()           pehle se PEHLE (reverse sentinel)
      cbegin/cend()    read-only forward
      crbegin/crend()  read-only reverse

  OPERATIONS:
      advance(it, n)   original ko n steps move karo (in-place)
      next(it, n)      n steps aage ka NAYA iterator (original safe)
      prev(it, n)      n steps peeche ka NAYA iterator (original safe)
      distance(a, b)   a se b tak kitne steps

  ARITHMETIC (Random Access only):
      it + n     it - n     it1 - it2     it[n]     it1 < it2

  WITH ALGORITHMS:
      sort(begin, end)             puri range sort
      sort(begin, begin+3)         partial sort (sirf pehle 3)
      reverse(begin, end)          reverse karo
      find(begin, end, val)        iterator return karta hai
      count(begin, end, val)       count return karta hai
      fill(begin, end, val)        sab ko ek value se bhar do

  RULES:
      ✅ hamesha it != end() check karo loop mein
      ✅ list/map/set mein advance() / next() use karo — + nahi chalta
      ✅ *end() kabhi mat karo — undefined behaviour
      ✅ const iterator (cbegin) tab use karo jab sirf padhna ho
      ✅ map iterator : it->first (key) | it->second (value)

================================================================================
  COMPILE & RUN:
      g++ iterators.cpp -o iterators
      ./iterators
================================================================================
*/