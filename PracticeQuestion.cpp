/*
================================================================================
        C++ STL — 50 Practice Questions
================================================================================
   Topics Covered:
   vector | list | stack | queue | priority_queue |
   pair | map | set | unordered_map | iterators | functors | algorithms
================================================================================
*/


// ============================================================
// 🟢 EASY (Q1 - Q15)
// ============================================================

/*
Q1.
    Ek vector banao jisme 1 se 10 tak numbers ho.
    Phir us vector ko reverse karo aur print karo.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>nums(10);
    iota(nums.begin(),nums.end(),1);
    reverse(nums.begin(),nums.end());
    for(auto value : nums) cout << value << " " ;

    return 0 ;
}

/*    
Q2.
    Ek stack banao aur usme 5 elements push karo.
    Ab stack ko completely pop karo aur har pop pe
    element print karo. (LIFO order me print hoga)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s;
    s.emplace(10);
    s.emplace(20);
    s.emplace(30);
    s.emplace(40);
    s.emplace(50);
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop();
    }
    return 0 ;
}


/*
Q3.
    Ek queue banao aur usme 5 students ke naam push karo.
    Phir unhe FIFO order me print karte hue remove karo.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<string> q ;
    q.emplace("Ankit");
    q.emplace("Nandini");
    q.emplace("Dev");
    q.emplace("Himanshu");
    q.emplace("Harshit");

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0 ;
}

/*    
Q4.
    Ek vector of pairs banao jisme {roll_number, marks} ho.
    5 students ka data store karo aur marks ke basis pe
    ascending order me sort karo.
*/
#include<bits/stdc++.h>
using namespace std;

struct SortFunctor {
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second < b.second;   // marks ke basis pe ascending
    }
};

int main(){
    vector<pair<int,int>> student;   // khali vector

    student.emplace_back(1, 56);
    student.emplace_back(2, 77);
    student.emplace_back(3, 42);
    student.emplace_back(4, 33);
    student.emplace_back(5, 95);

    sort(student.begin(), student.end(), SortFunctor());

    for(auto val : student){
        cout << "Roll: " << val.first 
             << " | Marks: " << val.second << "\n";
    }

    return 0;
}

/*
Q5.
    Ek max-heap priority_queue banao.
    {5, 2, 8, 1, 9, 3} ye numbers push karo.
    Phir top 3 elements print karo.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> pq ;
    pq.emplace(5);
    pq.emplace(2);
    pq.emplace(8);
    pq.emplace(1);
    pq.emplace(9);
    pq.emplace(3);

    int temp = 3 ;
    while(temp){
        cout << pq.top() << " " ;
        pq.pop();
        temp-- ;
    }

    return 0;
}


/*
Q6.
    Ek string vector banao — {"banana", "apple", "mango", "cherry"}.
    Isko alphabetically sort karo aur print karo.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<string> fruits {"banana", "apple", "mango", "cherry"} ;
    sort(fruits.begin() , fruits.end());
    for(auto val:fruits) cout << val << " " ;
    return 0;
}


/* 
Q7.
    Ek vector mein {1,2,3,4,5,6,7,8,9,10} ho.
    Sirf EVEN numbers ko print karo — STL algorithm use karo.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> numbers {1,2,3,4,5,6,7,8,9,10};
    // Method 1 
    for_each(numbers.begin() , numbers.end() , [](int value){
        if(value % 2 == 0) cout << value << " " ;
    });

    // Method 2 — copy_if se alag vector mein nikalo
    vector<int> evens;
    copy_if(numbers.begin(), numbers.end(), 
        back_inserter(evens), 
        [](int x){ return x % 2 == 0; });
    return 0;
}

/*
Q8.
    Do pairs banao:
    p1 = {10, 'A'}
    p2 = {20, 'B'}
    Dono ko swap karo aur result print karo.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    pair<int,int> p1 = make_pair(1,100);
    pair<int,int> p2 = make_pair(2,200);
    p1.swap(p2);

    cout << p1.first << " " << p1.second << endl ;
    cout << p2.first << " " << p2.second << endl ;
    
    return 0;
}

/*
Q9.
    Ek list banao {10, 20, 30, 40, 50}.
    Front aur back dono se ek ek element remove karo.
    Final list print karo.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    list<int> l {10, 20, 30, 40, 50};
    l.pop_front();
    l.pop_back();
    for(auto val:l) cout << val << " " ;
    return 0;
}

/*
Q10.
    Ek vector mein duplicate values hain — {1,2,2,3,3,3,4,5,5}.
    Unique elements ki count print karo.
    (Hint: std::unique use karo)
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v {1,2,2,3,3,3,4,5,5};
    auto it = unique(v.begin(),v.end());
    for(auto val : v) cout << val << " ";
    v.erase(it, v.end());
    cout << "Count of unique element : " << v.size() << " " ;
    return 0;
}

/*
Q11.
    Ek min-heap priority_queue banao.
    {15, 3, 8, 1, 12} push karo.
    Saare elements ascending order me print karo.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int , vector<int>, greater<int>> pq ;
    pq.push(15);
    pq.push(3);
    pq.push(8);
    pq.push(1);
    pq.push(12);
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}

/*
Q12.
    Ek functor banao "IsOdd" jo check kare ki number odd hai ya nahi.
    Vector {1,2,3,4,5,6,7,8} pe count_if se odd numbers count karo.
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    
    return 0;
}

/*
Q13.
    Ek vector {5, 3, 8, 1, 9, 2, 7} hai.
    Maximum aur minimum element find karo — STL algorithm use karo.

Q14.
    Ek stack use karke string "HELLO" ko reverse karo.
    Output: "OLLEH"

Q15.
    Ek vector of pairs {{1,50},{2,30},{3,80},{4,10}} hai.
    Second value (marks) ke basis pe DESCENDING order me sort karo.


// ============================================================
// 🟡 MEDIUM (Q16 - Q35)
// ============================================================

Q16.
    Ek vector {1,2,3,4,5} hai.
    std::transform use karke har element ka SQUARE nikalo
    aur result ek naye vector mein store karo.

Q17.
    Stack ka use karke check karo ki given string ke
    parentheses balanced hain ya nahi.
    Test cases: "({[]})" → Balanced
                "({[)}" → Not Balanced

Q18.
    Ek list {30, 10, 50, 20, 40} ko:
    a) Sort karo (ascending)
    b) Reverse karo
    c) Final result print karo

Q19.
    Ek functor "Multiplier" banao jo constructor se ek
    factor le. Use transform() ke saath vector
    {1,2,3,4,5} ke har element ko 3 se multiply karo.

Q20.
    Do sorted vectors merge karo ek sorted vector mein.
    v1 = {1, 3, 5, 7}
    v2 = {2, 4, 6, 8}
    Result: {1,2,3,4,5,6,7,8}
    (Hint: std::merge use karo)

Q21.
    Ek priority_queue use karke "Kth Largest Element" find karo.
    Array: {3, 2, 1, 5, 6, 4}, K = 2
    Output: 5

Q22.
    Ek vector {1,2,3,4,5,6,7,8,9,10} hai.
    std::partition use karke even aur odd numbers alag karo.
    Even numbers pehle, odd baad mein.

Q23.
    Nested pairs use karke 3 students ka data store karo:
    {roll, {name_initial, marks}}
    Marks ke basis pe sort karo.

Q24.
    Ek functor "RunningAverage" banao jo:
    - Har call pe ek number le
    - Running average maintain kare (state!)
    - Current average print kare
    Test: 10, 20, 30, 40 — averages: 10, 15, 20, 25

Q25.
    Queue use karke "Hot Potato" game simulate karo.
    5 players: {"A","B","C","D","E"}
    7 baar rotation ke baad kaunsa player out hoga?
    (Front wala rotate hoga — queue se nikalo, wapas push karo)

Q26.
    Ek vector of pairs {{name, score}} hai:
    {{"Ankit",85}, {"Rahul",92}, {"Priya",78}, {"Sneha",95}}
    Score ke basis pe descending sort karo aur
    rank 1,2,3,4 assign karo.

Q27.
    STL built-in functors use karo:
    a) plus<int>    se do vectors add karo element-wise
    b) negate<int>  se vector ke saare elements negate karo
    (transform() use karo)

Q28.
    Ek list mein {1,2,3,2,4,2,5} hai.
    remove() use karke saare 2 hata do.
    Phir remove_if() se saare even numbers hata do.

Q29.
    Stack use karke infix expression "3 + 4" evaluate karo.
    (Simplified: sirf numbers push karo, operator pe pop karke calculate karo)

Q30.
    Ek vector {-5, 3, -1, 8, -4, 2, -7, 6} hai.
    a) Positive numbers ka sum nikalo
    b) Negative numbers ko hata do
    c) Remaining elements sort karo
    (std::accumulate, remove_if, sort use karo)

Q31.
    Ek priority_queue use karke "Merge K Sorted Arrays" karo.
    Arrays: {1,4,7}, {2,5,8}, {3,6,9}
    Output: 1 2 3 4 5 6 7 8 9
    (Hint: pair<value, index> store karo)

Q32.
    Ek list use karke "Josephus Problem" solve karo.
    N=6 logon ka circle, har 2nd person out hota hai.
    Kon bachega?

Q33.
    Functor "BetweenRange" banao jo constructor se
    low aur high le. count_if se vector {1..20} mein
    5 se 15 ke beech ke numbers count karo.

Q34.
    std::for_each aur ek stateful functor use karke
    vector {1,2,3,4,5} ke:
    a) Sum nikalo
    b) Product nikalo
    Dono ek hi pass mein (ek functor mein dono maintain karo)

Q35.
    Do lists ko merge() se merge karo. Pehle sort karo.
    l1 = {5, 1, 3}
    l2 = {4, 2, 6}
    Result: {1,2,3,4,5,6}


// ============================================================
// 🔴 HARD (Q36 - Q50)
// ============================================================

Q36.
    Stack use karke "Next Greater Element" find karo.
    Array: {4, 5, 2, 25, 7, 8}
    Output: {5, 25, 25, -1, 8, -1}
    (Har element ke liye uske right mein pehla bada element)

Q37.
    Priority queue use karke "Top K Frequent Elements" find karo.
    Array: {1,1,1,2,2,3}, K=2
    Output: {1, 2}

Q38.
    Stack use karke "Largest Rectangle in Histogram" solve karo.
    Heights: {2, 1, 5, 6, 2, 3}
    Output: 10 (max rectangle area)

Q39.
    Ek custom functor-based comparator banao jo
    strings ko LENGTH ke basis pe sort kare (chhoti pehle).
    Length same ho toh alphabetically sort kare.
    Input: {"banana","kiwi","apple","fig","mango"}

Q40.
    Queue aur Stack dono use karke check karo ki
    given sequence palindrome hai ya nahi.
    {1, 2, 3, 2, 1} → Palindrome
    {1, 2, 3, 4, 5} → Not Palindrome

Q41.
    Priority queue use karke "Kth Smallest Element"
    find karo — MAX heap use karo (min heap nahi).
    Array: {7, 10, 4, 3, 20, 15}, K=3
    Output: 7

Q42.
    Functor chain banao:
    Step 1: Double karo (x*2)
    Step 2: Add 10 karo (x+10)
    Step 3: Square karo (x*x)
    Vector {1,2,3,4,5} pe teen alag transform() calls mein apply karo.

Q43.
    Stack use karke "Valid Parentheses" ka extended version:
    Input string mein '(', ')', '{', '}', '[', ']' sab hain.
    "()[]{}"   → Valid
    "([)]"     → Invalid
    "{[]}"     → Valid

Q44.
    Do priority queues use karke "Median of a Stream" find karo.
    Max-heap (lower half) + Min-heap (upper half)
    Stream: {5, 15, 1, 3}
    After each insertion median print karo: 5, 10, 5, 4

Q45.
    Ek template functor "Accumulator<T>" banao jo:
    - Kisi bhi type ke values add kar sake (int, double, string)
    - Total maintain kare (state)
    - Current total return kare
    Test with int, double, aur string concatenation.

Q46.
    List use karke "LRU Cache" implement karo (simplified).
    Capacity: 3
    Operations: put(1), put(2), put(3), get(1), put(4)
    get(4) ke baad cache mein kya hoga? (2 evict hoga)

Q47.
    Stack use karke "Decode String" problem solve karo.
    Input: "3[a]2[bc]"
    Output: "aaabcbc"
    Input: "2[abc]3[cd]ef"
    Output: "abcabccdcdcdef"

Q48.
    Custom priority queue banao jo {priority, task_name} store kare.
    Higher priority number = pehle execute hoga.
    Tasks: {3,"Cook"},{1,"Sleep"},{4,"Code"},{2,"Eat"}
    Execution order print karo.

Q49.
    Functor use karke "Function Pipeline" banao:
    Pipeline: {double, addFive, square}
    Input 3 → double → 6 → addFive → 11 → square → 121
    Vector of functors store karo aur sequentially apply karo.

Q50.
    Infix to Postfix conversion karo using Stack.
    Input:  "A+B*C-D"
    Output: "ABC*+D-"
    (Operators: +, -, *, / with proper precedence)
*/