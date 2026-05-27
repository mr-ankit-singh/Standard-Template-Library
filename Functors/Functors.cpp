/*
================================================================================
        C++ — Functors (Function Objects)
        Format: Title | Syntax | Definition | Examples
================================================================================

   WHAT IS A FUNCTOR?
   - Functor = Function + Object — dono ka combination
   - Ek class/struct jisme operator() overload hota hai
   - Isse object ko function ki tarah call kar sakte ho
   - Regular function se zyada powerful — STATE store kar sakta hai
   - STL algorithms (sort, transform, for_each) mein extensively use hota hai

   VISUALIZATION:
       Regular Function  →  greet("Ankit")       // sirf call, no state
       Functor           →  MyFunc obj;
                            obj("Ankit");          // object call hua function ki tarah
                            obj.count;             // state bhi store hai andar!

   HEADER: No special header — built-in C++ feature
           STL functors ke liye: #include <functional>

   CATEGORIES:
   1. Basic Functor               -> operator() overload
   2. Functor with State          -> member variables
   3. Functor with Parameters     -> constructor se config
   4. Built-in STL Functors       -> less<>, greater<>, plus<> etc.
   5. Functor vs Function         -> difference
   6. Functor vs Lambda           -> difference
   7. Functor in STL Algorithms   -> sort, for_each, transform
   8. Predicate Functor           -> bool return karne wale
   9. Advanced                    -> template functor, functor chain
*/


//==============================================================================
// CATEGORY 1 — BASIC FUNCTOR
//==============================================================================
/*
  TITLE:
      Basic Functor - operator() overload karna

  SYNTAX:
      struct MyFunctor {
          void operator()(params) {
              // body
          }
      };
      MyFunctor obj;
      obj(args);   // function ki tarah call karo

  DEFINITION:
      Kisi bhi class/struct mein operator() overload karo —
      woh class ka object ab function ki tarah call ho sakta hai.
      Yahi Functor hai.
*/
#include <iostream>
using namespace std;

struct Greet {
    void operator()(string name) {
        cout << "Hello, " << name << "!\n";
    }
};

struct Square {
    int operator()(int x) {
        return x * x;
    }
};

int main(){
    // Example 1 - void functor
    Greet greet;
    greet("Ankit");    // Hello, Ankit!
    greet("Priya");    // Hello, Priya!

    // Example 2 - return value functor
    Square sq;
    cout << "Square of 5 : " << sq(5)  << "\n";   // 25
    cout << "Square of 9 : " << sq(9)  << "\n";   // 81

    // Example 3 - temporary object se direct call
    cout << "Direct call : " << Square()(7) << "\n";   // 49

    return 0;
}
// Hello, Ankit!
// Hello, Priya!
// Square of 5 : 25
// Square of 9 : 81
// Direct call : 49


//==============================================================================
// CATEGORY 2 — FUNCTOR WITH STATE
//==============================================================================
/*
  TITLE:
      Functor with State - State store karna (regular function se bada advantage)

  SYNTAX:
      struct MyFunctor {
          int count = 0;   // state
          void operator()() {
              count++;     // state update
          }
      };

  DEFINITION:
      Functor ka sabse bada advantage — STATE store kar sakta hai.
      Regular function ya lambda (without capture) ye nahi kar sakti.
      Member variables mein har call ke baad state update hoti rehti hai.
*/
#include <iostream>
using namespace std;

// Call counter functor
struct CallCounter {
    int count = 0;   // state

    void operator()(string msg) {
        count++;
        cout << "[Call #" << count << "] " << msg << "\n";
    }
};

// Running sum functor
struct RunningSum {
    int total = 0;

    int operator()(int n) {
        total += n;
        return total;
    }
};

int main(){
    // Example 1 - call count track karo
    CallCounter logger;
    logger("Server started");     // [Call #1] Server started
    logger("User logged in");     // [Call #2] User logged in
    logger("Data fetched");       // [Call #3] Data fetched
    cout << "Total calls : " << logger.count << "\n";   // 3

    // Example 2 - running sum
    RunningSum rs;
    cout << rs(10) << "\n";   // 10
    cout << rs(20) << "\n";   // 30
    cout << rs(30) << "\n";   // 60
    cout << "Final total : " << rs.total << "\n";   // 60

    return 0;
}
// [Call #1] Server started
// [Call #2] User logged in
// [Call #3] Data fetched
// Total calls : 3
// 10  30  60
// Final total : 60


//==============================================================================
// CATEGORY 3 — FUNCTOR WITH PARAMETERS (Constructor se Config)
//==============================================================================
/*
  TITLE:
      Functor with Parameters - Constructor se behaviour configure karna

  SYNTAX:
      struct MyFunctor {
          int threshold;
          MyFunctor(int t) : threshold(t) {}
          bool operator()(int x) { return x > threshold; }
      };

  DEFINITION:
      Constructor se functor ko configure kar sakte ho — ek baar set karo,
      baar baar use karo. Ye flexibility regular functions mein nahi hoti.
      Alag alag configurations ke liye alag alag objects banao.
*/
#include <iostream>
using namespace std;

// Multiplier — constructor se multiplier set karo
struct Multiplier {
    int factor;
    Multiplier(int f) : factor(f) {}

    int operator()(int x) {
        return x * factor;
    }
};

// Threshold checker
struct IsGreaterThan {
    int threshold;
    IsGreaterThan(int t) : threshold(t) {}

    bool operator()(int x) {
        return x > threshold;
    }
};

// Adder — kisi bhi number mein fixed value add karo
struct AddN {
    int n;
    AddN(int n) : n(n) {}

    int operator()(int x) {
        return x + n;
    }
};

int main(){
    // Example 1 - Multiplier
    Multiplier triple(3);
    Multiplier double2(2);
    cout << "triple(5) : " << triple(5) << "\n";    // 15
    cout << "double(5) : " << double2(5) << "\n";   // 10

    // Example 2 - Threshold checker
    IsGreaterThan gt10(10);
    IsGreaterThan gt50(50);
    cout << "gt10(15) : " << gt10(15) << "\n";   // 1 (true)
    cout << "gt10(5)  : " << gt10(5)  << "\n";   // 0 (false)
    cout << "gt50(60) : " << gt50(60) << "\n";   // 1 (true)

    // Example 3 - AddN
    AddN add5(5);
    AddN add100(100);
    cout << "add5(10)   : " << add5(10)   << "\n";   // 15
    cout << "add100(42) : " << add100(42) << "\n";   // 142

    return 0;
}
// triple(5) : 15
// double(5) : 10
// gt10(15) : 1
// gt10(5)  : 0
// gt50(60) : 1
// add5(10)   : 15
// add100(42) : 142


//==============================================================================
// CATEGORY 4 — BUILT-IN STL FUNCTORS
//==============================================================================
/*
  TITLE:
      Built-in STL Functors - <functional> header mein ready-made functors

  SYNTAX:
      #include <functional>
      less<T>{}(a, b)       // a < b
      greater<T>{}(a, b)    // a > b
      plus<T>{}(a, b)       // a + b
      equal_to<T>{}(a, b)   // a == b

  DEFINITION:
      C++ STL mein ready-made functors milte hain <functional> header mein.
      In functors ko algorithms mein comparator ya operation ke roop mein
      directly pass kar sakte ho — apna functor banana nahi padta.

  ARITHMETIC FUNCTORS:
      plus<T>         a + b
      minus<T>        a - b
      multiplies<T>   a * b
      divides<T>      a / b
      modulus<T>      a % b
      negate<T>       -a

  COMPARISON FUNCTORS:
      equal_to<T>         a == b
      not_equal_to<T>     a != b
      less<T>             a < b
      greater<T>          a > b
      less_equal<T>        a <= b
      greater_equal<T>    a >= b

  LOGICAL FUNCTORS:
      logical_and<T>   a && b
      logical_or<T>    a || b
      logical_not<T>   !a
*/
#include <iostream>
#include <functional>
using namespace std;

int main(){
    // Example 1 - Arithmetic functors
    plus<int>       add;
    minus<int>      sub;
    multiplies<int> mul;
    divides<int>    div;
    modulus<int>    mod;
    negate<int>     neg;

    cout << "plus       : " << add(10, 5) << "\n";   // 15
    cout << "minus      : " << sub(10, 5) << "\n";   // 5
    cout << "multiplies : " << mul(10, 5) << "\n";   // 50
    cout << "divides    : " << div(10, 5) << "\n";   // 2
    cout << "modulus    : " << mod(10, 3) << "\n";   // 1
    cout << "negate     : " << neg(10)    << "\n";   // -10

    // Example 2 - Comparison functors
    less<int>     lt;
    greater<int>  gt;
    equal_to<int> eq;

    cout << "less(3,5)     : " << lt(3, 5)  << "\n";   // 1 (true)
    cout << "greater(3,5)  : " << gt(3, 5)  << "\n";   // 0 (false)
    cout << "equal_to(5,5) : " << eq(5, 5)  << "\n";   // 1 (true)

    // Example 3 - Logical functors
    logical_and<bool> land;
    logical_or<bool>  lor;
    logical_not<bool> lnot;

    cout << "AND(true,false) : " << land(true, false) << "\n";   // 0
    cout << "OR(true,false)  : " << lor(true, false)  << "\n";   // 1
    cout << "NOT(true)       : " << lnot(true)         << "\n";   // 0

    return 0;
}


//==============================================================================
// CATEGORY 5 — FUNCTOR vs FUNCTION
//==============================================================================
/*
  TITLE:
      Functor vs Regular Function — Kab kya use karein

  DEFINITION:
      Regular function  → simple, stateless operations ke liye
      Functor           → state chahiye, config chahiye, STL mein pass karna ho
*/
#include <iostream>
using namespace std;

// Regular function — state nahi rakh sakti
int squareFn(int x) {
    return x * x;
}

// Functor — state rakh sakti hai + configurable
struct PowerOf {
    int exp;
    PowerOf(int e) : exp(e) {}
    int operator()(int x) {
        int result = 1;
        for(int i = 0; i < exp; i++) result *= x;
        return result;
    }
};

int main(){
    // Regular function
    cout << "squareFn(4) : " << squareFn(4) << "\n";   // 16

    // Functor — ek baar configure, baar baar use
    PowerOf square(2);
    PowerOf cube(3);
    PowerOf quad(4);

    cout << "square(4)   : " << square(4) << "\n";   // 16
    cout << "cube(3)     : " << cube(3)   << "\n";   // 27
    cout << "quad(2)     : " << quad(2)   << "\n";   // 16

    return 0;
}
// squareFn(4) : 16
// square(4)   : 16
// cube(3)     : 27
// quad(2)     : 16

/*
  COMPARISON TABLE:
  ┌─────────────────┬──────────────┬──────────────┐
  │ Feature         │ Function     │ Functor      │
  ├─────────────────┼──────────────┼──────────────┤
  │ State store     │ ❌ Nahi      │ ✅ Haan      │
  │ Configurable    │ ❌ Nahi      │ ✅ Haan      │
  │ STL mein pass   │ ✅ Haan      │ ✅ Haan      │
  │ Inline optimize │ ❌ Kam       │ ✅ Zyada     │
  │ Simple syntax   │ ✅ Simple    │ ❌ Verbose   │
  └─────────────────┴──────────────┴──────────────┘
*/


//==============================================================================
// CATEGORY 6 — FUNCTOR vs LAMBDA
//==============================================================================
/*
  TITLE:
      Functor vs Lambda — Modern C++ mein kya prefer karein

  DEFINITION:
      Lambda   → short, one-time use, simple captures ke liye
      Functor  → reusable, complex state, multiple methods chahiye ho
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Functor version
struct IsEven {
    bool operator()(int x) {
        return x % 2 == 0;
    }
};

int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    // Lambda version — concise, one-time use
    int countLambda = count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
    cout << "Lambda  - even count : " << countLambda << "\n";   // 4

    // Functor version — reusable
    IsEven isEven;
    int countFunctor = count_if(v.begin(), v.end(), isEven);
    cout << "Functor - even count : " << countFunctor << "\n";  // 4

    return 0;
}
// Lambda  - even count : 4
// Functor - even count : 4

/*
  COMPARISON TABLE:
  ┌──────────────────┬──────────────────┬──────────────────┐
  │ Feature          │ Lambda           │ Functor          │
  ├──────────────────┼──────────────────┼──────────────────┤
  │ Syntax           │ ✅ Concise       │ ❌ Verbose       │
  │ Reusability      │ ❌ One-time      │ ✅ Reusable      │
  │ State            │ ✅ Capture se    │ ✅ Member var se │
  │ Multiple methods │ ❌ Nahi          │ ✅ Haan          │
  │ Debugging        │ ❌ Mushkil       │ ✅ Aasaan        │
  │ C++ version      │ C++11+           │ Classic C++      │
  └──────────────────┴──────────────────┴──────────────────┘
*/


//==============================================================================
// CATEGORY 7 — FUNCTOR IN STL ALGORITHMS
//==============================================================================


//------------------------------------------------------------------------------
// a) sort() with Functor
//------------------------------------------------------------------------------
/*
  TITLE:
      sort() mein Functor — Custom order se sort karna

  SYNTAX:
      sort(v.begin(), v.end(), FunctorObject);
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Descending sort functor
struct Descending {
    bool operator()(int a, int b) {
        return a > b;
    }
};

// Sort by absolute value
struct AbsoluteSort {
    bool operator()(int a, int b) {
        return abs(a) < abs(b);
    }
};

int main(){
    vector<int> v1 = {30, 10, 50, 20, 40};
    vector<int> v2 = {-5, 3, -1, 4, -2};

    // Example 1 - descending sort
    sort(v1.begin(), v1.end(), Descending());
    cout << "Descending      : ";
    for(int x : v1) cout << x << " ";   // 50 40 30 20 10
    cout << "\n";

    // Example 2 - sort by absolute value
    sort(v2.begin(), v2.end(), AbsoluteSort());
    cout << "Absolute sort   : ";
    for(int x : v2) cout << x << " ";   // -1 -2 3 -5 4
    cout << "\n";

    // Example 3 - built-in greater<> functor
    vector<int> v3 = {3, 1, 4, 1, 5, 9};
    sort(v3.begin(), v3.end(), greater<int>());
    cout << "greater<int>()  : ";
    for(int x : v3) cout << x << " ";   // 9 5 4 3 1 1
    cout << "\n";

    return 0;
}


//------------------------------------------------------------------------------
// b) for_each() with Functor
//------------------------------------------------------------------------------
/*
  TITLE:
      for_each() mein Functor — Har element pe action karna

  SYNTAX:
      for_each(v.begin(), v.end(), FunctorObject);
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct PrintWithIndex {
    int index = 0;
    void operator()(int x) {
        cout << "[" << index++ << "] " << x << "\n";
    }
};

struct MultiplyAndPrint {
    int factor;
    MultiplyAndPrint(int f) : factor(f) {}
    void operator()(int x) {
        cout << x << "*" << factor << "=" << x*factor << "  ";
    }
};

int main(){
    vector<int> v = {10, 20, 30, 40, 50};

    // Example 1 - index ke saath print (state!)
    cout << "With index :\n";
    for_each(v.begin(), v.end(), PrintWithIndex());

    // Example 2 - configured functor
    cout << "Multiply by 3 : ";
    for_each(v.begin(), v.end(), MultiplyAndPrint(3));
    cout << "\n";

    return 0;
}
// With index :
// [0] 10
// [1] 20
// [2] 30
// [3] 40
// [4] 50
// Multiply by 3 : 10*3=30  20*3=60  30*3=90  40*3=120  50*3=150


//------------------------------------------------------------------------------
// c) transform() with Functor
//------------------------------------------------------------------------------
/*
  TITLE:
      transform() mein Functor — Har element ko transform karna

  SYNTAX:
      transform(v.begin(), v.end(), result.begin(), FunctorObject);
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Double { int operator()(int x) { return x * 2; } };
struct Negate { int operator()(int x) { return -x; } };

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> result(5);

    // Example 1 - double karo
    transform(v.begin(), v.end(), result.begin(), Double());
    cout << "Doubled  : ";
    for(int x : result) cout << x << " ";   // 2 4 6 8 10
    cout << "\n";

    // Example 2 - negate karo
    transform(v.begin(), v.end(), result.begin(), Negate());
    cout << "Negated  : ";
    for(int x : result) cout << x << " ";   // -1 -2 -3 -4 -5
    cout << "\n";

    // Example 3 - built-in negate<> functor
    transform(v.begin(), v.end(), result.begin(), negate<int>());
    cout << "STL negate : ";
    for(int x : result) cout << x << " ";   // -1 -2 -3 -4 -5
    cout << "\n";

    return 0;
}


//==============================================================================
// CATEGORY 8 — PREDICATE FUNCTOR
//==============================================================================
/*
  TITLE:
      Predicate Functor - bool return karne wale functors

  DEFINITION:
      Predicate = ek functor ya function jo bool return karta hai.
      STL algorithms jaise count_if, find_if, remove_if mein use hota hai.
      Unary Predicate  → ek argument leta hai
      Binary Predicate → do arguments leta hai
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Unary predicate
struct IsPositive {
    bool operator()(int x) { return x > 0; }
};

struct IsDivisibleBy {
    int divisor;
    IsDivisibleBy(int d) : divisor(d) {}
    bool operator()(int x) { return x % divisor == 0; }
};

// Binary predicate
struct AbsLess {
    bool operator()(int a, int b) { return abs(a) < abs(b); }
};

int main(){
    vector<int> v = {-3, 5, -1, 8, -4, 2, 7, -6};

    // Example 1 - count_if with unary predicate
    int pos = count_if(v.begin(), v.end(), IsPositive());
    cout << "Positive count    : " << pos << "\n";   // 4

    // Example 2 - configured predicate
    int div2 = count_if(v.begin(), v.end(), IsDivisibleBy(2));
    cout << "Divisible by 2    : " << div2 << "\n";   // 4

    // Example 3 - find_if
    auto it = find_if(v.begin(), v.end(), IsPositive());
    if(it != v.end())
        cout << "First positive    : " << *it << "\n";   // 5

    // Example 4 - remove_if (negative numbers hatao)
    v.erase(remove_if(v.begin(), v.end(), [](int x){ return x < 0; }), v.end());
    cout << "After remove neg  : ";
    for(int x : v) cout << x << " ";   // 5 8 2 7
    cout << "\n";

    // Example 5 - binary predicate in sort
    vector<int> v2 = {-5, 3, -1, 4, -2};
    sort(v2.begin(), v2.end(), AbsLess());
    cout << "Sort by abs value : ";
    for(int x : v2) cout << x << " ";   // -1 -2 3 4 -5
    cout << "\n";

    return 0;
}


//==============================================================================
// CATEGORY 9 — ADVANCED
//==============================================================================


//------------------------------------------------------------------------------
// a) Template Functor
//------------------------------------------------------------------------------
/*
  TITLE:
      Template Functor - Har type ke saath kaam karne wala functor

  SYNTAX:
      struct MyFunctor {
          template<typename T>
          T operator()(T a, T b) { return a + b; }
      };
*/
#include <iostream>
#include <string>
using namespace std;

struct Add {
    template<typename T>
    T operator()(T a, T b) {
        return a + b;
    }
};

struct Print {
    template<typename T>
    void operator()(T val) {
        cout << "Value : " << val << "\n";
    }
};

int main(){
    Add add;
    cout << "int    : " << add(10, 20)          << "\n";   // 30
    cout << "double : " << add(3.14, 2.71)      << "\n";   // 5.85
    cout << "string : " << add(string("Hello"), string(" World")) << "\n";   // Hello World

    Print print;
    print(42);         // Value : 42
    print(3.14);       // Value : 3.14
    print("Ankit");    // Value : Ankit

    return 0;
}


//------------------------------------------------------------------------------
// b) Functor returning Functor (Function Composition)
//------------------------------------------------------------------------------
/*
  TITLE:
      Functor jo Functor return karta hai — Function Composition

  DEFINITION:
      Ek functor doosra functor return kar sakta hai — advanced pattern.
      Factory pattern ki tarah kaam karta hai.
*/
#include <iostream>
#include <functional>
using namespace std;

struct Adder {
    int n;
    Adder(int n) : n(n) {}
    int operator()(int x) { return x + n; }
};

// Factory functor — Adder functor return karta hai
struct MakeAdder {
    Adder operator()(int n) {
        return Adder(n);
    }
};

int main(){
    MakeAdder factory;

    auto add5  = factory(5);
    auto add10 = factory(10);
    auto add100 = factory(100);

    cout << "add5(3)    : " << add5(3)   << "\n";   // 8
    cout << "add10(3)   : " << add10(3)  << "\n";   // 13
    cout << "add100(3)  : " << add100(3) << "\n";   // 103

    return 0;
}
// add5(3)    : 8
// add10(3)   : 13
// add100(3)  : 103


/*
================================================================================
  QUICK SUMMARY
================================================================================

  BASIC SYNTAX:
      struct MyFunctor {
          returnType operator()(params) {
              // body
          }
      };
      MyFunctor obj;
      obj(args);          // function ki tarah call

  CATEGORIES:
      Basic Functor       operator() overload — simple use
      State Functor       member variables se state maintain karo
      Param Functor       constructor se configure karo
      Predicate Functor   bool return — count_if, find_if, remove_if mein
      Template Functor    har type ke saath kaam kare

  BUILT-IN STL FUNCTORS (<functional>):
      Arithmetic          plus, minus, multiplies, divides, modulus, negate
      Comparison          equal_to, not_equal_to, less, greater, less_equal, greater_equal
      Logical             logical_and, logical_or, logical_not

  STL ALGORITHMS MEIN USE:
      sort()              custom order se sort
      for_each()          har element pe action
      transform()         har element ko convert
      count_if()          condition se count
      find_if()           pehla match dhundo
      remove_if()         condition se hatao

  FUNCTOR vs FUNCTION vs LAMBDA:
      Function    → simple, stateless, easy syntax
      Functor     → reusable, stateful, configurable, multiple methods
      Lambda      → concise, one-time, C++11+, capture se state

  WHEN TO USE FUNCTOR:
      ✅ State maintain karni ho
      ✅ Constructor se configure karna ho
      ✅ STL algorithms mein reuse karna ho
      ✅ Multiple operator overloads chahiye hon
      ❌ Simple one-time operation → Lambda prefer karo

================================================================================
  COMPILE & RUN:
      g++ functors.cpp -o functors
      ./functors
      (template functor ke liye: g++ -std=c++17 functors.cpp -o functors)
================================================================================
*/  