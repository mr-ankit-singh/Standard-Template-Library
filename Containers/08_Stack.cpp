/*
================================================================================
        C++ STL — std::stack (LIFO Container Adaptor)
        Format: Title | Syntax | Definition | Examples
================================================================================

   WHAT IS std::stack?
   - LIFO (Last In, First Out) structure implement karta hai
   - Sirf TOP se kaam hota hai — insert bhi, delete bhi
   - Ye ek Container Adaptor hai — internally deque use karta hai (default)
   - Random access NAHI hota — sirf top element visible hota hai
   - sort(), reverse(), insert() — kuch nahi hota stack mein

   LIFO Visualization:
       push(10) → push(20) → push(30)

       | 30 |  ← TOP (yahan se access / delete hota hai)
       | 20 |
       | 10 |
       |____|

   HEADER: #include <stack>

   CATEGORIES:
   1. Element Access  -> top()
   2. Capacity        -> empty(), size()
   3. Modifiers       -> push(), emplace(), pop(), swap()
*/


//==============================================================================
// DECLARATION & INITIALIZATION
//==============================================================================
/*
  TITLE:
      std::stack Declaration aur Initialization

  SYNTAX:
      std::stack<datatype> name;
      std::stack<datatype> name2(name1);        // copy constructor
      std::stack<datatype, deque<datatype>> st; // custom container

  DEFINITION:
      std::stack ko directly initializer list se initialize NAHI kar sakte —
      pehle ek container banao (deque/vector/list), phir us se stack banao.
      Ya seedha khali declare karo aur push() se elements daalo.
*/
#include <iostream>
#include <stack>
#include <deque>
using namespace std;
int main(){
    // Method 1 - empty stack
    std::stack<int> st1;
    st1.push(10);
    st1.push(20);
    st1.push(30);

    // Method 2 - deque se initialize
    std::deque<int> dq {1, 2, 3, 4, 5};
    std::stack<int> st2(dq);   // deque ka top element = 5

    // Method 3 - copy constructor
    std::stack<int> st3(st1);

    // print st1
    cout << "st1 top : " << st1.top() << endl;   // 30
    cout << "st2 top : " << st2.top() << endl;   // 5
    cout << "st3 top : " << st3.top() << endl;   // 30 (copy of st1)

    return 0;
}


//==============================================================================
// PRINT / TRAVERSE
//==============================================================================
/*
  TITLE:
      std::stack Print karna (Traversal)

  SYNTAX:
      while(!st.empty()) { st.top(); st.pop(); }

  DEFINITION:
      stack mein iterator NAHI hota — range-based for loop bhi NAHI chalta.
      Sirf ek hi tarika hai — top() se dekho aur pop() se hatao.
      Dhyan rakho — print karne ke baad stack EMPTY ho jaata hai.
      Agar preserve karna ho to ek aur stack use karo.
*/
#include <iostream>
#include <stack>
using namespace std;
int main(){
    std::stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Method 1 - traverse (stack destroy ho jaata hai)
    cout << "Mtd 1 (destructive) : ";
    std::stack<int> temp = st;   // pehle copy banao
    while(!temp.empty()){
        cout << temp.top() << " ";   // 40 30 20 10
        temp.pop();
    }
    cout << endl;

    // Method 2 - original preserve karke print
    cout << "Mtd 2 (preserved)   : ";
    std::stack<int> helper;
    while(!st.empty()){
        cout << st.top() << " ";   // 40 30 20 10
        helper.push(st.top());
        st.pop();
    }
    // wapas restore karo
    while(!helper.empty()){
        st.push(helper.top());
        helper.pop();
    }
    cout << endl;

    cout << "st still intact - top : " << st.top() << endl;   // 40

    return 0;
}


//==============================================================================
// CATEGORY 1 - ELEMENT ACCESS
// a) top() -> Returns top element (last pushed)
//==============================================================================


//------------------------------------------------------------------------------
// a) top()
//------------------------------------------------------------------------------
/*
  TITLE:
      top() - Stack ka top element access karna

  SYNTAX:
      st.top();

  DEFINITION:
      Stack ka SABSE UPAR wala element return karta hai —
      matlab jo element sabse baad mein push hua tha.
      Isse read bhi kar sakte ho aur modify bhi kar sakte ho.
      pop() se alag hai — top() sirf dekhta hai, hatata nahi.
      Empty stack pe top() call karna undefined behaviour hai.
*/
#include <iostream>
#include <stack>
using namespace std;
int main(){
    std::stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    // Example 1 - top element read karo
    cout << "top()          : " << st.top() << endl;   // 30

    // Example 2 - top() se modify karo
    st.top() = 99;
    cout << "After top()=99 : " << st.top() << endl;   // 99

    // Example 3 - pop ke baad naya top
    st.pop();
    cout << "After pop()    : " << st.top() << endl;   // 20

    return 0;
}


//==============================================================================
// CATEGORY 2 - CAPACITY
// a) empty()  -> Check whether stack is empty
// b) size()   -> Number of elements in stack
//==============================================================================


//------------------------------------------------------------------------------
// a) empty()
//------------------------------------------------------------------------------
/*
  TITLE:
      empty() - Stack khali hai ya nahi check karna

  SYNTAX:
      st.empty();

  DEFINITION:
      Stack mein koi element hai ya nahi check karta hai.
      1 (true) return karta hai agar stack empty ho, warna 0 (false).
      pop() ya top() call karne se pehle hamesha empty() check karo.
*/
#include <iostream>
#include <stack>
using namespace std;
int main(){
    std::stack<int> st1;
    std::stack<int> st2;
    st2.push(10);
    st2.push(20);

    // Example 1 - empty stack
    cout << "st1.empty() : " << st1.empty() << endl;   // 1 (empty)

    // Example 2 - non-empty stack
    cout << "st2.empty() : " << st2.empty() << endl;   // 0 (not empty)

    // Example 3 - pop ke baad check
    st2.pop();
    st2.pop();
    cout << "st2.empty() after 2 pop() : " << st2.empty() << endl;   // 1

    // Example 4 - safe traversal mein use
    std::stack<int> st3;
    st3.push(5); st3.push(10); st3.push(15);
    while(!st3.empty()){
        cout << st3.top() << " ";   // 15 10 5
        st3.pop();
    }
    cout << endl;

    return 0;
}


//------------------------------------------------------------------------------
// b) size()
//------------------------------------------------------------------------------
/*
  TITLE:
      size() - Stack mein kitne elements hain

  SYNTAX:
      st.size();

  DEFINITION:
      Stack mein abhi kitne elements hain woh count return karta hai.
      push() karne se size badhta hai, pop() se ghatta hai.
*/
#include <iostream>
#include <stack>
using namespace std;
int main(){
    std::stack<int> st;

    // Example 1 - empty stack
    cout << "size() initially      : " << st.size() << endl;   // 0

    // Example 2 - push ke baad
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "size() after 3 push() : " << st.size() << endl;   // 3

    // Example 3 - pop ke baad
    st.pop();
    cout << "size() after 1 pop()  : " << st.size() << endl;   // 2

    // Example 4 - string stack
    std::stack<string> ss;
    ss.push("Hello");
    ss.push("World");
    cout << "string stack size()   : " << ss.size() << endl;   // 2

    return 0;
}


//==============================================================================
// CATEGORY 3 - MODIFIERS
// a) push()    -> Insert element at top
// b) emplace() -> Construct and insert at top
// c) pop()     -> Remove top element
// d) swap()    -> Swap two stacks
//==============================================================================


//------------------------------------------------------------------------------
// a) push()
//------------------------------------------------------------------------------
/*
  TITLE:
      push() - Top pe element add karna

  SYNTAX:
      st.push(value);

  DEFINITION:
      Stack ke TOP pe ek naya element add karta hai.
      Har push() ke baad naya element top ban jaata hai.
      Size 1 se badhta hai.
*/
#include <iostream>
#include <stack>
using namespace std;
int main(){
    std::stack<int> st;

    // Example 1 - elements push karo
    st.push(10);
    cout << "After push(10) - top : " << st.top() << endl;   // 10

    st.push(20);
    cout << "After push(20) - top : " << st.top() << endl;   // 20

    st.push(30);
    cout << "After push(30) - top : " << st.top() << endl;   // 30

    // Example 2 - size track karo
    cout << "Final size()         : " << st.size() << endl;   // 3

    // Example 3 - string stack
    std::stack<string> ss;
    ss.push("C++");
    ss.push("STL");
    ss.push("Stack");
    cout << "string stack top     : " << ss.top() << endl;   // Stack

    return 0;
}


//------------------------------------------------------------------------------
// b) emplace()
//------------------------------------------------------------------------------
/*
  TITLE:
      emplace() - Top pe in-place construct karke add karna

  SYNTAX:
      st.emplace(value);
      st.emplace(arg1, arg2, ...);   // complex objects ke liye

  DEFINITION:
      push() jaisa hi kaam karta hai — lekin element seedha
      stack ke andar construct hota hai (no copy, no move).
      Simple types (int, string) ke liye push() se koi fark nahi.
      Complex objects (pair, struct) ke liye emplace() zyada efficient hai
      kyunki temporary object nahi banta.
*/
#include <iostream>
#include <stack>
#include <utility>   // pair ke liye
using namespace std;
int main(){
    // Example 1 - basic emplace (int)
    std::stack<int> st;
    st.emplace(10);
    st.emplace(20);
    st.emplace(30);
    cout << "After 3 emplace() - top  : " << st.top() << endl;   // 30
    cout << "size()                   : " << st.size() << endl;   // 3

    // Example 2 - emplace vs push (pair example)
    std::stack<pair<int,int>> pst;

    // push — pehle pair banana padta hai
    pst.push(make_pair(1, 2));

    // emplace — seedha arguments de do, pair andar banta hai
    pst.emplace(3, 4);   // zyada efficient ✅

    cout << "pair stack top           : {"
         << pst.top().first << ", "
         << pst.top().second << "}" << endl;   // {3, 4}

    // Example 3 - string emplace
    std::stack<string> ss;
    ss.emplace("Hello");
    ss.emplace("World");
    cout << "string stack top         : " << ss.top() << endl;   // World

    return 0;
}


//------------------------------------------------------------------------------
// c) pop()
//------------------------------------------------------------------------------
/*
  TITLE:
      pop() - Top element delete karna

  SYNTAX:
      st.pop();

  DEFINITION:
      Stack ka SABSE UPAR wala element hata deta hai.
      Koi value return NAHI karta — sirf hatata hai.
      Agar value chahiye to pehle top() se lo, phir pop() karo.
      Empty stack pe pop() call karna undefined behaviour hai.
      Size 1 se ghatta hai.
*/
#include <iostream>
#include <stack>
using namespace std;
int main(){
    std::stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // Example 1 - pop karne se pehle top() lo
    cout << "top() before pop()  : " << st.top() << endl;   // 40
    st.pop();
    cout << "top() after 1 pop() : " << st.top() << endl;   // 30

    // Example 2 - multiple pop
    st.pop();
    st.pop();
    cout << "top() after 2 pop() : " << st.top() << endl;   // 10
    cout << "size() now          : " << st.size() << endl;  // 1

    // Example 3 - safe pop pattern (hamesha aise karo)
    std::stack<int> st2;
    st2.push(100); st2.push(200); st2.push(300);

    while(!st2.empty()){
        cout << "Processing : " << st2.top() << endl;
        st2.pop();
    }
    // Processing : 300
    // Processing : 200
    // Processing : 100

    return 0;
}


//------------------------------------------------------------------------------
// d) swap()
//------------------------------------------------------------------------------
/*
  TITLE:
      swap() - Do stacks ke contents exchange karna

  SYNTAX:
      st1.swap(st2);

  DEFINITION:
      Do stacks ke saare elements aapas mein exchange ho jaate hain.
      Dono stacks ka type same hona chahiye — size alag bhi ho sakta hai.
      O(1) time mein hota hai — elements move nahi hote, pointers swap hote hain.
*/
#include <iostream>
#include <stack>
using namespace std;
int main(){
    std::stack<int> st1;
    st1.push(1); st1.push(2); st1.push(3);

    std::stack<int> st2;
    st2.push(10); st2.push(20);

    cout << "Before swap :" << endl;
    cout << "st1 - top() : " << st1.top() << " | size() : " << st1.size() << endl;   // 3, 3
    cout << "st2 - top() : " << st2.top() << " | size() : " << st2.size() << endl;   // 20, 2

    st1.swap(st2);

    cout << "After swap  :" << endl;
    cout << "st1 - top() : " << st1.top() << " | size() : " << st1.size() << endl;   // 20, 2
    cout << "st2 - top() : " << st2.top() << " | size() : " << st2.size() << endl;   // 3, 3

    return 0;
}


//==============================================================================
// BONUS — REAL WORLD USE CASES
//==============================================================================


//------------------------------------------------------------------------------
// Use Case 1 - Balanced Parentheses Check
//------------------------------------------------------------------------------
/*
  TITLE:
      Stack se Parentheses balance check karna

  DEFINITION:
      Stack ka sabse classic use case — opening bracket push karo,
      closing bracket pe pop karo aur match check karo.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isBalanced(string s){
    std::stack<char> st;
    for(char c : s){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        } else {
            if(st.empty()) return false;
            char top = st.top();
            st.pop();
            if(c == ')' && top != '(') return false;
            if(c == '}' && top != '{') return false;
            if(c == ']' && top != '[') return false;
        }
    }
    return st.empty();
}
int main(){
    // Example 1 - balanced
    cout << "({[]}) : " << (isBalanced("({[]})") ? "Balanced" : "Not Balanced") << endl;  // Balanced

    // Example 2 - not balanced
    cout << "({[)}) : " << (isBalanced("({[)})") ? "Balanced" : "Not Balanced") << endl;  // Not Balanced

    // Example 3 - only opening
    cout << "(((   : " << (isBalanced("(((")   ? "Balanced" : "Not Balanced") << endl;  // Not Balanced

    return 0;
}


//------------------------------------------------------------------------------
// Use Case 2 - Reverse a String using Stack
//------------------------------------------------------------------------------
/*
  TITLE:
      Stack se String reverse karna

  DEFINITION:
      String ke characters push karo — LIFO ki wajah se
      pop karte waqt reverse order mein aate hain.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    string s = "ANKIT";
    std::stack<char> st;

    // Example 1 - push all characters
    for(char c : s) st.push(c);

    // Example 2 - pop to get reversed string
    string reversed = "";
    while(!st.empty()){
        reversed += st.top();
        st.pop();
    }
    cout << "Original : " << s        << endl;   // ANKIT
    cout << "Reversed : " << reversed << endl;   // TIKNA

    return 0;
}


/*
================================================================================
  QUICK SUMMARY
================================================================================

  CATEGORY 1 - ELEMENT ACCESS
      top()            -> top element access / modify karo
                          (empty stack pe call mat karo!)

  CATEGORY 2 - CAPACITY
      empty()          -> khali hai ya nahi (1/0)
                          pop() se pehle hamesha check karo
      size()           -> current elements ka count

  CATEGORY 3 - MODIFIERS
      push(val)        -> top pe element add karo
      emplace(args)    -> top pe in-place construct karke add karo
                          complex objects ke liye push() se efficient
      pop()            -> top element hatao (return nahi karta!)
                          value chahiye to pehle top() lo
      swap(st2)        -> do stacks ke contents exchange karo

  IMPORTANT RULES:
      ✅ top()  — sirf dekhta hai, hatata nahi
      ✅ pop()  — sirf hatata hai, return nahi karta
      ✅ hamesha: value = st.top(); st.pop(); — dono saath use karo
      ❌ iterator nahi hota — range-based for loop nahi chalta
      ❌ sort(), reverse(), insert(), remove() — kuch nahi hota stack mein
      ❌ random access nahi — sirf top visible hota hai

  STACK vs LIST vs QUEUE:
      stack   top()              LIFO — sirf top se kaam
      queue   front() / back()   FIFO — front se nikalo, back pe daalo
      list    front() / back()   dono ends + middle access bhi

  UNDERLYING CONTAINER:
      default              -> deque<T>
      stack<T, vector<T>>  -> vector use karo
      stack<T, list<T>>    -> list use karo

================================================================================
  COMPILE & RUN:
      g++ stack_methods.cpp -o stack_methods
      ./stack_methods
================================================================================
*/