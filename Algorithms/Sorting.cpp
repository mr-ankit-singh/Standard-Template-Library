/*
================================================================================
   ███████╗████████╗██╗         ███████╗ ██████╗ ██████╗ ████████╗██╗███╗   ██╗ ██████╗
   ██╔════╝╚══██╔══╝██║         ██╔════╝██╔═══██╗██╔══██╗╚══██╔══╝██║████╗  ██║██╔════╝
   ███████╗   ██║   ██║         ███████╗██║   ██║██████╔╝   ██║   ██║██╔██╗ ██║██║  ███╗
   ╚════██║   ██║   ██║         ╚════██║██║   ██║██╔══██╗   ██║   ██║██║╚██╗██║██║   ██║
   ███████║   ██║   ███████╗    ███████║╚██████╔╝██║  ██║   ██║   ██║██║ ╚████║╚██████╔╝
   ╚══════╝   ╚═╝   ╚══════╝    ╚══════╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝
================================================================================
   C++ STL SORTING FUNCTIONS — COMPLETE NOTES
   Language  : C++
   Header    : <algorithm>  (sab functions isme hain)
================================================================================

   INDEX:
   ══════════════════════════════════════════════════════════════
    1.  Kab Kaun Sa Use Karo — Quick Identification Guide
    2.  sort()
    3.  stable_sort()
    4.  partial_sort()
    5.  partial_sort_copy()
    6.  is_sorted()
    7.  is_sorted_until()
    8.  nth_element()
    9.  Comparators — Custom Sorting (Bohot Important!)
   10.  Side-by-Side Comparison Table
   11.  Interview Tips & Tricks
   ══════════════════════════════════════════════════════════════
*/

#include <bits/stdc++.h>
using namespace std;

// ╔══════════════════════════════════════════════════════════════════════════╗
// ║  PART 1 — KAB KAUN SA USE KARO                                         ║
// ╚══════════════════════════════════════════════════════════════════════════╝
/*
   ┌──────────────────────────────────────────────┬──────────────────────────┐
   │  Situation                                   │  Function                │
   ├──────────────────────────────────────────────┼──────────────────────────┤
   │ Poora array sort karna hai                   │ sort()                   │
   │ Equal elements ki order preserve karni hai   │ stable_sort()            │
   │ Sirf Top K elements sorted chahiye           │ partial_sort()           │
   │ Top K chahiye, original array na badle       │ partial_sort_copy()      │
   │ Check karo sorted hai ya nahi                │ is_sorted()              │
   │ Pata karo KAHAN tak sorted hai               │ is_sorted_until()        │
   │ K-th largest/smallest dhundna hai            │ nth_element()            │
   │ Median dhundni hai (O(n) mein)               │ nth_element()            │
   └──────────────────────────────────────────────┴──────────────────────────┘

   COMPLEXITY EK NAZAR MEIN:
   ──────────────────────────────────────────────
   sort()              →  O(n log n)   avg/worst
   stable_sort()       →  O(n log² n)  worst  |  O(n log n) extra memory ho to
   partial_sort()      →  O(n log k)   ← faster jab k << n
   partial_sort_copy() →  O(n log k)
   is_sorted()         →  O(n)
   is_sorted_until()   →  O(n)
   nth_element()       →  O(n)         avg  ← sabse fast for K-th element!
*/


// ╔══════════════════════════════════════════════════════════════════════════╗
// ║  PART 2 — sort()                                                        ║
// ╚══════════════════════════════════════════════════════════════════════════╝
/*
   KYA KARTA HAI:
   → Array/vector ko sort karta hai
   → Default: ascending order (chhhota → bada)
   → Introsort algorithm use karta hai
     (QuickSort + HeapSort + InsertionSort ka smart combination)

   SYNTAX:
   ────────────────────────────────────────────
   sort(first, last);
   sort(first, last, comparator);

   → first  : starting iterator (v.begin())
   → last   : ending iterator   (v.end())
   → comparator : optional — custom sorting logic

   TIME  : O(n log n)
   SPACE : O(log n)   [recursion stack]
   STABLE: NO  ← equal elements ki order guarantee nahi

   IMPORTANT: sort() STABLE NAHI HAI
   ──────────────────────────────────────────────────────────
   Agar do elements "equal" hain comparator ke according,
   toh unka relative order preserve nahi hoga.
   Equal elements ki order chahiye → stable_sort() use karo.
*/

void sort_examples() {

    // ── Example 1: Default Ascending Sort ──
    vector<int> v = {5, 2, 8, 1, 9, 3};
    sort(v.begin(), v.end());
    // v = {1, 2, 3, 5, 8, 9}

    // ── Example 2: Descending Sort ──
    sort(v.begin(), v.end(), greater<int>());
    // v = {9, 8, 5, 3, 2, 1}

    // ── Example 3: Partial Range Sort (index 1 to 4) ──
    vector<int> v2 = {5, 3, 1, 4, 2};
    sort(v2.begin() + 1, v2.begin() + 4);
    // v2 = {5, 1, 3, 4, 2}  ← sirf index 1,2,3 sort hue

    // ── Example 4: String Sort ──
    vector<string> words = {"banana", "apple", "cherry"};
    sort(words.begin(), words.end());
    // words = {"apple", "banana", "cherry"}

    // ── Example 5: Pair Sort (first element se) ──
    vector<pair<int,string>> students = {{3,"Charlie"}, {1,"Alice"}, {2,"Bob"}};
    sort(students.begin(), students.end());
    // students = {{1,Alice}, {2,Bob}, {3,Charlie}}
    // pair by default first element se sort karta hai

    // ── Example 6: Lambda Comparator ──
    vector<int> v3 = {5, 2, 8, 1, 9, 3};
    sort(v3.begin(), v3.end(), [](int a, int b) {
        return a % 2 < b % 2;   // even pehle, odd baad mein
    });
    // v3 = {2, 8, 5, 1, 9, 3}  (even: 2,8 | odd: 5,1,9,3)

    // ── Example 7: Sort 2D Array / Struct ──
    vector<vector<int>> matrix = {{3,1}, {1,2}, {2,3}};
    sort(matrix.begin(), matrix.end(), [](auto& a, auto& b) {
        if (a[0] != b[0]) return a[0] < b[0];   // pehle column se
        return a[1] < b[1];                       // same to doosre se
    });
    // matrix = {{1,2}, {2,3}, {3,1}}
}


// ╔══════════════════════════════════════════════════════════════════════════╗
// ║  PART 3 — stable_sort()                                                 ║
// ╚══════════════════════════════════════════════════════════════════════════╝
/*
   KYA KARTA HAI:
   → sort() jaisa hi — lekin STABLE hai
   → Equal elements ki RELATIVE ORDER preserve hoti hai
   → Merge Sort algorithm use karta hai

   SYNTAX:
   ────────────────────────────────────────────
   stable_sort(first, last);
   stable_sort(first, last, comparator);

   TIME  : O(n log² n)  → extra memory nahi ho to
           O(n log n)   → extra memory available ho to
   SPACE : O(n)
   STABLE: YES ← yahi fark hai sort() se

   KAB ZAROORI HAI:
   → Multi-key sorting mein (pehle ek criterion se sort, phir doosre se)
   → Original insertion order maintain karni ho equal elements ke liye
   → Database-like sorting jahan ties important hain

   SORT vs STABLE_SORT:
   ──────────────────────────────────────────────────────────
   Maan lo students hain: {90,"Zara"}, {85,"Bob"}, {90,"Alice"}
   Marks ke hisaab se sort karo:

   sort()        → {90,"Alice"}, {90,"Zara"}, {85,"Bob"}  ← order guarantee nahi
   stable_sort() → {90,"Zara"}, {90,"Alice"}, {85,"Bob"}  ← original order same
                        ↑ Zara pehle tha, pehle hi rahega
*/

void stableSort_examples() {

    // ── Example 1: Basic stable sort ──
    vector<pair<int,string>> students = {
        {90, "Zara"}, {85, "Bob"}, {90, "Alice"}, {85, "Charlie"}
    };
    stable_sort(students.begin(), students.end(),
        [](auto& a, auto& b) {
            return a.first > b.first;   // marks descending
        }
    );
    // Result: {90,Zara}, {90,Alice}, {85,Bob}, {85,Charlie}
    // Same marks wale APNI ORIGINAL ORDER mein hain

    // ── Example 2: Multi-key sort using stable_sort ──
    // Pehle department se sort karo, phir salary se
    // (stable_sort se dono criteria simultaneously handle hote hain)
    vector<pair<string,int>> employees = {
        {"HR",50}, {"IT",70}, {"HR",60}, {"IT",55}
    };
    stable_sort(employees.begin(), employees.end(),
        [](auto& a, auto& b) {
            return a.second < b.second;   // salary ascending
        }
    );
    // {HR,50}, {IT,55}, {HR,60}, {IT,70}
}


// ╔══════════════════════════════════════════════════════════════════════════╗
// ║  PART 4 — partial_sort()                                                ║
// ╚══════════════════════════════════════════════════════════════════════════╝
/*
   KYA KARTA HAI:
   → Poore array ko sort NAHI karta
   → Sirf pehle K elements ko sorted form mein laata hai
   → Baki elements kisi bhi order mein ho sakte hain
   → HeapSort use karta hai internally

   SYNTAX:
   ────────────────────────────────────────────
   partial_sort(first, middle, last);
   partial_sort(first, middle, last, comparator);

   → first  : array ka start
   → middle : yahan tak sort karo (exclusive)
               yani [first, middle) range sorted hogi
   → last   : array ka end

   TIME  : O(n log k)   ← sort() se fast jab k << n
   SPACE : O(1)
   STABLE: NO

   VISUALIZATION:
   ──────────────────────────────────────────────────────────
   Array: [5, 2, 8, 1, 9, 3, 7]
   partial_sort(begin, begin+3, end)

   Before: [5, 2, 8, 1, 9, 3, 7]
   After:  [1, 2, 3, | 8, 9, 5, 7]
            ↑ sorted ↑   ↑ unordered ↑
            pehle 3       baki kuch bhi
*/

void partialSort_examples() {

    // ── Example 1: Top 3 smallest ──
    vector<int> v = {5, 2, 8, 1, 9, 3, 7};
    partial_sort(v.begin(), v.begin() + 3, v.end());
    // v = {1, 2, 3, [5,9,8,7]}
    // Pehle 3: 1,2,3 — sorted
    // Baki: koi bhi order

    // ── Example 2: Top 3 largest ──
    partial_sort(v.begin(), v.begin() + 3, v.end(), greater<int>());
    // v = {9, 8, 7, [1,2,3,5]}

    // ── Example 3: Leaderboard Top 5 ──
    vector<pair<int,string>> scores = {
        {85,"Alice"},{92,"Bob"},{78,"Carol"},
        {95,"Dave"},{88,"Eve"},{71,"Frank"}
    };
    partial_sort(scores.begin(), scores.begin() + 3, scores.end(),
        [](auto& a, auto& b) {
            return a.first > b.first;   // highest score pehle
        }
    );
    // Pehle 3: Dave(95), Bob(92), Eve(88)
    // Baki 3: koi bhi order
}


// ╔══════════════════════════════════════════════════════════════════════════╗
// ║  PART 5 — partial_sort_copy()                                           ║
// ╚══════════════════════════════════════════════════════════════════════════╝
/*
   KYA KARTA HAI:
   → partial_sort jaisa — lekin result ALAG ARRAY mein jaata hai
   → Source array UNCHANGED rehta hai
   → Kitne elements copy honge = min(src_size, dst_size)

   SYNTAX:
   ────────────────────────────────────────────
   auto it = partial_sort_copy(src_first, src_last,
                               dst_first, dst_last);

   auto it = partial_sort_copy(src_first, src_last,
                               dst_first, dst_last,
                               comparator);

   RETURN VALUE:
   → Iterator pointing to one past the last copied element in dst
   → Isse pata chalta hai kitne elements actually copy hue

   TIME  : O(n log k)
   SPACE : O(k)  [destination array]
   STABLE: NO

   partial_sort vs partial_sort_copy:
   ──────────────────────────────────────────────────────────
   partial_sort      → original array modify hoti hai
   partial_sort_copy → original safe, result nayi array mein
*/

void partialSortCopy_examples() {

    // ── Example 1: Top 3 smallest in new array ──
    vector<int> src = {5, 2, 8, 1, 9, 3, 7};
    vector<int> dst(3);

    auto it = partial_sort_copy(src.begin(), src.end(),
                                dst.begin(), dst.end());
    // dst = {1, 2, 3}
    // src = {5, 2, 8, 1, 9, 3, 7}  ← UNCHANGED!

    // Return value use karo
    int copiedCount = it - dst.begin();   // = 3

    // ── Example 2: Destination chhoti ho to ──
    vector<int> dst2(10);   // 10 size, par src mein 7 hain
    auto it2 = partial_sort_copy(src.begin(), src.end(),
                                 dst2.begin(), dst2.end());
    // Sirf 7 elements copy honge (src.size() < dst.size())
    // it2 - dst2.begin() = 7

    // ── Example 3: Top 3 largest ──
    vector<int> dst3(3);
    partial_sort_copy(src.begin(), src.end(),
                      dst3.begin(), dst3.end(),
                      greater<int>());
    // dst3 = {9, 8, 7}
    // src unchanged!

    // ── Example 4: Array (non-vector) bhi kaam karta hai ──
    int arr[] = {5, 2, 8, 1, 9};
    vector<int> result(3);
    partial_sort_copy(arr, arr + 5, result.begin(), result.end());
    // result = {1, 2, 5}
}


// ╔══════════════════════════════════════════════════════════════════════════╗
// ║  PART 6 — is_sorted()                                                   ║
// ╚══════════════════════════════════════════════════════════════════════════╝
/*
   KYA KARTA HAI:
   → Check karta hai ki range sorted hai ya nahi
   → true/false return karta hai
   → Sort NAHI karta — sirf check karta hai
   → Pehla unsorted pair milte hi return kar deta (early exit)

   SYNTAX:
   ────────────────────────────────────────────
   bool result = is_sorted(first, last);
   bool result = is_sorted(first, last, comparator);

   TIME  : O(n)   [worst case — best case O(1) agar pehla pair hi unsorted]
   SPACE : O(1)
   RETURN: true  → sorted hai
           false → sorted nahi hai

   RELATIONSHIP WITH is_sorted_until():
   ──────────────────────────────────────────────────────────
   is_sorted(first, last)
   ≡  is_sorted_until(first, last) == last

   Dono same kaam karte hain —
   is_sorted sirf true/false deta hai
   is_sorted_until exact position deta hai
*/

void isSorted_examples() {

    // ── Example 1: Basic check ──
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 3, 2, 4, 5};

    bool r1 = is_sorted(v1.begin(), v1.end());   // true
    bool r2 = is_sorted(v2.begin(), v2.end());   // false

    // ── Example 2: Descending check ──
    vector<int> v3 = {5, 4, 3, 2, 1};
    bool r3 = is_sorted(v3.begin(), v3.end(), greater<int>());   // true

    // ── Example 3: Single element / empty ──
    vector<int> single = {42};
    vector<int> empty  = {};
    bool r4 = is_sorted(single.begin(), single.end());   // true (hamesha)
    bool r5 = is_sorted(empty.begin(),  empty.end());    // true (hamesha)

    // ── Example 4: Binary search se pehle use karo ──
    vector<int> data = {1, 3, 5, 7, 9};
    if (is_sorted(data.begin(), data.end())) {
        // Safe to binary search
        bool found = binary_search(data.begin(), data.end(), 5);
    } else {
        sort(data.begin(), data.end());   // pehle sort karo
    }

    // ── Example 5: Sort karna zaroori hai ya nahi decide karo ──
    vector<int> input = {1, 2, 3, 4, 5};
    if (!is_sorted(input.begin(), input.end())) {
        sort(input.begin(), input.end());
    }
    // Already sorted hai to sort() skip — time bachao!
}


// ╔══════════════════════════════════════════════════════════════════════════╗
// ║  PART 7 — is_sorted_until()                                             ║
// ╚══════════════════════════════════════════════════════════════════════════╝
/*
   KYA KARTA HAI:
   → Pehle unsorted element ka ITERATOR return karta hai
   → Isse pata chalta hai KAHAN TAK sorted hai
   → is_sorted() se zyada information deta hai

   SYNTAX:
   ────────────────────────────────────────────
   auto it = is_sorted_until(first, last);
   auto it = is_sorted_until(first, last, comparator);

   RETURN VALUE:
   → Iterator to the FIRST element jo sorted order tod raha hai
   → Agar poora sorted hai → last (v.end()) return hota hai
   → Agar pehla hi element unsorted hai → first+1 return hota hai

   TIME  : O(n)
   SPACE : O(1)

   VISUALIZATION:
   ──────────────────────────────────────────────────────────
   Array: [1, 2, 3, 7, 5, 8, 9]
                         ↑
   is_sorted_until returns iterator to '5'
   kyunki 7 → 5 sorted order tod raha hai (7 > 5)

   Distance from begin = 4  →  pehle 4 elements sorted hain
*/

void isSortedUntil_examples() {

    // ── Example 1: Basic use ──
    vector<int> v = {1, 2, 3, 7, 5, 8, 9};

    auto it = is_sorted_until(v.begin(), v.end());
    // it → points to 5 (index 4)

    cout << *it << endl;                    // 5  (pehla unsorted)
    cout << (it - v.begin()) << endl;       // 4  (kahan tak sorted)

    // ── Example 2: Poora sorted ho ──
    vector<int> sorted_v = {1, 2, 3, 4, 5};
    auto it2 = is_sorted_until(sorted_v.begin(), sorted_v.end());

    if (it2 == sorted_v.end()) {
        // Poora array sorted hai
    }
    int sortedLen = it2 - sorted_v.begin();   // = 5 (poori length)

    // ── Example 3: Kahan se sort karna start karein ──
    vector<int> partial = {1, 2, 4, 3, 5, 6};
    auto breakPoint = is_sorted_until(partial.begin(), partial.end());

    // breakPoint se end tak sort karo (optimize)
    sort(breakPoint, partial.end());
    // partial = {1, 2, 3, 4, 5, 6}

    // ── Example 4: is_sorted() ko implement karo is_sorted_until se ──
    auto it3 = is_sorted_until(v.begin(), v.end());
    bool isSortedResult = (it3 == v.end());   // same as is_sorted()

    // ── Example 5: Descending check ──
    vector<int> desc = {9, 7, 5, 3, 2, 4};
    auto it4 = is_sorted_until(desc.begin(), desc.end(), greater<int>());
    // it4 → points to 4 (kyunki 2 → 4 order tod raha hai descending mein)
    cout << (it4 - desc.begin()) << endl;   // 5  (pehle 5 elements sorted)
}


// ╔══════════════════════════════════════════════════════════════════════════╗
// ║  PART 8 — nth_element()                                                 ║
// ╚══════════════════════════════════════════════════════════════════════════╝
/*
   KYA KARTA HAI:
   → Nth position pe wo element laata hai jo sorted array mein hota
   → GUARANTEE:
       ✓ v[nth] = wo value jo sorted mein nth pe hoti
       ✓ v[0..nth-1] = sab nth se CHHHOTE ya equal (koi order guarantee nahi)
       ✓ v[nth+1..end] = sab nth se BADE ya equal (koi order guarantee nahi)
   → Introselect algorithm use karta hai (QuickSelect based)

   SYNTAX:
   ────────────────────────────────────────────
   nth_element(first, nth, last);
   nth_element(first, nth, last, comparator);

   → first : array start
   → nth   : iterator to the element jo nth position pe aana chahiye
   → last  : array end

   TIME  : O(n) average  ←  sort() ke O(n log n) se FAST!
   SPACE : O(1)
   STABLE: NO

   VISUALIZATION:
   ──────────────────────────────────────────────────────────
   Array: [5, 2, 8, 1, 9, 3, 7]
   nth_element(begin, begin+2, end)   ← 3rd smallest (index 2)

   Before: [5, 2, 8, 1, 9, 3, 7]
   After:  [1, 2, 3, 5, 9, 8, 7]
                   ↑
                 v[2] = 3 ← guaranteed correct!
                 Left side: {1,2} ← sab 3 se chhhote
                 Right side: {5,9,8,7} ← sab 3 se bade (unordered)

   WHY BETTER THAN SORT FOR K-TH ELEMENT:
   ──────────────────────────────────────────────────────────
   K-th element problem:
   sort()        → O(n log n) — poora sort karo, phir v[k] lo   [slow]
   nth_element() → O(n)       — sirf position guarantee karo     [fast]
*/

void nthElement_examples() {

    // ── Example 1: K-th Smallest Element ──
    vector<int> v = {5, 2, 8, 1, 9, 3, 7};

    // 3rd smallest (0-indexed = 2)
    nth_element(v.begin(), v.begin() + 2, v.end());
    int kthSmallest = v[2];   // = 3

    // ── Example 2: K-th Largest Element ──
    vector<int> v2 = {5, 2, 8, 1, 9, 3, 7};
    int k = 2;   // 2nd largest

    nth_element(v2.begin(), v2.begin() + k - 1, v2.end(), greater<int>());
    int kthLargest = v2[k - 1];   // = 8

    // ── Example 3: Median Dhundho ──
    vector<int> v3 = {5, 2, 8, 1, 9, 3, 7};
    int n = v3.size();

    nth_element(v3.begin(), v3.begin() + n/2, v3.end());
    int median = v3[n/2];   // = 5

    // Even size ke liye:
    // lower median = v[(n-1)/2]
    // upper median = v[n/2]

    // ── Example 4: Top K elements (unordered) dhundho ──
    vector<int> v4 = {5, 2, 8, 1, 9, 3, 7};
    int kk = 3;   // top 3 largest chahiye (order important nahi)

    nth_element(v4.begin(), v4.begin() + kk, v4.end(), greater<int>());
    // v4[0], v4[1], v4[2] = 3 largest elements (kisi bhi order mein)
    // v4 = {9, 8, 7, [5,2,3,1]}  ya koi bhi order

    // ── Example 5: Sort ke saath combine karo ──
    vector<int> v5 = {5, 2, 8, 1, 9, 3, 7};

    // Top 3 SORTED chahiye → nth_element + sort (partial_sort se better nahi)
    nth_element(v5.begin(), v5.begin() + 3, v5.end(), greater<int>());
    sort(v5.begin(), v5.begin() + 3, greater<int>());
    // v5[0..2] = {9, 8, 7}  ← sorted top 3
    // (for this use partial_sort directly — yeh sirf concept ke liye)
}


// ╔══════════════════════════════════════════════════════════════════════════╗
// ║  PART 9 — COMPARATORS (Custom Sorting — Bohot Important!)               ║
// ╚══════════════════════════════════════════════════════════════════════════╝
/*
   COMPARATOR KYA HOTA HAI:
   → Ek function/lambda jo batata hai: kya a, b se PEHLE aana chahiye?
   → Return true  → a pehle aayega
   → Return false → b pehle aayega

   STRICT WEAK ORDERING — MUST FOLLOW:
   ──────────────────────────────────────────────────────────
   1. Irreflexivity  : comp(a, a) = false   (a khud se chhhota nahi)
   2. Asymmetry      : comp(a,b)=true → comp(b,a)=false
   3. Transitivity   : a<b && b<c → a<c

   RULE: comp(a, b) = true matlab "a before b"
         agar comp(a,b) aur comp(b,a) dono false → equal hain

   AGAR YEH RULE FOLLOW NA HO → UNDEFINED BEHAVIOR!
   ──────────────────────────────────────────────────────────
   GALAT:  return a >= b;   // ← crash ya infinite loop
   SAHI:   return a < b;    // ← correct
*/

// ── 3 Ways to Write Comparator ──

// Method 1: Function Pointer
bool myComp(int a, int b) {
    return a < b;   // ascending
}

// Method 2: Functor (struct with operator())
struct MyComparator {
    bool operator()(int a, int b) const {
        return a > b;   // descending
    }
};

// Method 3: Lambda (Modern C++ — Sabse Common)
// [](int a, int b) { return a < b; }

void comparator_examples() {

    vector<int> v = {5, 2, 8, 1, 9};

    // Function pointer
    sort(v.begin(), v.end(), myComp);

    // Functor
    sort(v.begin(), v.end(), MyComparator());

    // Lambda
    sort(v.begin(), v.end(), [](int a, int b) {
        return a < b;
    });

    // ── Common Custom Sorting Scenarios ──

    // 1. String by length
    vector<string> words = {"banana", "fig", "apple", "kiwi"};
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
    // {"fig", "kiwi", "apple", "banana"}

    // 2. String by length, then alphabetically (tie-break)
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        if (a.length() != b.length()) return a.length() < b.length();
        return a < b;   // same length → alphabetical
    });

    // 3. Struct sort by multiple fields
    struct Student { string name; int marks; int age; };
    vector<Student> students = {{"Alice",90,20}, {"Bob",85,22}, {"Carol",90,19}};

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.marks != b.marks) return a.marks > b.marks;   // marks descending
        return a.age < b.age;                                // age ascending (tie-break)
    });

    // 4. Sort indices (original array ko na badle, indices sort karo)
    vector<int> data = {5, 2, 8, 1, 9};
    vector<int> indices(data.size());
    iota(indices.begin(), indices.end(), 0);   // {0,1,2,3,4}

    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return data[a] < data[b];
    });
    // indices = {3, 1, 0, 2, 4}  ← data ke sorted indices
    // data[3]=1, data[1]=2, data[0]=5, data[2]=8, data[4]=9

    // 5. Even numbers pehle, odd baad — same group mein ascending
    vector<int> nums = {5, 2, 8, 1, 9, 3, 6};
    sort(nums.begin(), nums.end(), [](int a, int b) {
        if ((a % 2) != (b % 2)) return (a % 2) < (b % 2);  // even (0) < odd (1)
        return a < b;   // same type → ascending
    });
    // {2, 6, 8, 1, 3, 5, 9}
}


// ╔══════════════════════════════════════════════════════════════════════════╗
// ║  PART 10 — SIDE-BY-SIDE COMPARISON TABLE                                ║
// ╚══════════════════════════════════════════════════════════════════════════╝
/*
   ┌─────────────────────┬──────────────┬─────────┬────────┬──────────────────────────────┐
   │ Function            │ Time         │ Space   │ Stable │ Use Case                     │
   ├─────────────────────┼──────────────┼─────────┼────────┼──────────────────────────────┤
   │ sort()              │ O(n log n)   │ O(log n)│ No     │ General purpose sorting      │
   │ stable_sort()       │ O(n log² n)  │ O(n)    │ Yes    │ Equal elements order matters │
   │ partial_sort()      │ O(n log k)   │ O(1)    │ No     │ Top K sorted, in-place       │
   │ partial_sort_copy() │ O(n log k)   │ O(k)    │ No     │ Top K sorted, new array      │
   │ is_sorted()         │ O(n)         │ O(1)    │ N/A    │ Check sorted ya nahi         │
   │ is_sorted_until()   │ O(n)         │ O(1)    │ N/A    │ Kahan tak sorted hai         │
   │ nth_element()       │ O(n) avg     │ O(1)    │ No     │ K-th element / Median        │
   └─────────────────────┴──────────────┴─────────┴────────┴──────────────────────────────┘

   ALGORITHMS USED INTERNALLY:
   ──────────────────────────────────────────────────────────
   sort()              → Introsort  (QuickSort + HeapSort + InsertionSort)
   stable_sort()       → Merge Sort
   partial_sort()      → Heap Sort  (HeapSelect)
   partial_sort_copy() → Heap Sort
   nth_element()       → Introselect (QuickSelect + MedianOfMedians)
*/


// ╔══════════════════════════════════════════════════════════════════════════╗
// ║  PART 11 — INTERVIEW TIPS & TRICKS                                      ║
// ╚══════════════════════════════════════════════════════════════════════════╝
/*
   TIP 1: K-th Element Problem
   ──────────────────────────────────────────────────────────
   "K-th largest element dhundho" → nth_element() use karo
   sort()        = O(n log n)  [slow]
   nth_element() = O(n)        [fast]  ← always prefer this

   TIP 2: Equal Elements Ka Order
   ──────────────────────────────────────────────────────────
   "Equal elements ki relative order maintain karo" → stable_sort()
   sort() yeh guarantee nahi deta

   TIP 3: Already Sorted Input Optimize Karo
   ──────────────────────────────────────────────────────────
   if (!is_sorted(v.begin(), v.end())) {
       sort(v.begin(), v.end());
   }
   // Agar already sorted hai → O(n) mein check, sort skip!

   TIP 4: Original Array Bachana Ho
   ──────────────────────────────────────────────────────────
   partial_sort()      → original modify hogi
   partial_sort_copy() → original safe, result alag array mein

   TIP 5: Median in O(n)
   ──────────────────────────────────────────────────────────
   // sort() → O(n log n) → v[n/2]
   // nth_element() → O(n) → v[n/2]  ← BETTER
   nth_element(v.begin(), v.begin() + v.size()/2, v.end());
   int median = v[v.size()/2];

   TIP 6: Comparator Common Mistakes
   ──────────────────────────────────────────────────────────
   GALAT: return a >= b;    // strict weak ordering violate!
   GALAT: return a <= b;    // strict weak ordering violate!
   SAHI:  return a < b;     // ascending
   SAHI:  return a > b;     // descending

   TIP 7: Kab Sort Nahi Karna
   ──────────────────────────────────────────────────────────
   → Sirf maximum/minimum chahiye   → *max_element() / *min_element()   O(n)
   → Sirf K-th element chahiye      → nth_element()                     O(n)
   → Sirf check karna hai sorted    → is_sorted()                       O(n)
   Inke liye sort() mat lagao — wasteful hai!

   TIP 8: STL Functions Ki Limits
   ──────────────────────────────────────────────────────────
   sort()        → RandomAccess iterator chahiye (vector, array, deque)
   list ke liye  → list.sort() use karo (member function)
   set/map       → already sorted hote hain, sort() mat lagao

   TIP 9: Interview Mein Bolne Ki Pattern
   ──────────────────────────────────────────────────────────
   "Maine yahan sort() use kiya — O(n log n) time, O(log n) space.
    Agar stable sort chahiye hota toh stable_sort() use karta.
    Agar sirf K-th element chahiye hota toh nth_element() se
    O(n) mein solve hota — jo sort se faster hai."

   Yahi interviewer ko impress karta hai — alternatives jaanna!
*/

int main() {
    // Yeh file reference ke liye hai.
    // Har function ka syntax, example, aur tips upar likhe hain.
    // Practice: LeetCode → "Sort" tag ke problems solve karo.
    return 0;
}

/*
================================================================================
   QUICK DECISION FLOWCHART:
   ──────────────────────────────────────────────────────────
   Sorting chahiye?
      ├── Poora array    → sort() ya stable_sort()
      │     └── Equal elements order chahiye? → stable_sort()
      ├── Sirf Top K     → partial_sort()
      │     └── Original safe rakhni? → partial_sort_copy()
      ├── Sirf Check     → is_sorted()
      │     └── Exactly KAHAN break → is_sorted_until()
      └── K-th Element   → nth_element()    ← O(n), sabse fast!

   "Sort karne se pehle socho — kya sach mein sort zaroori hai?"
================================================================================
*/