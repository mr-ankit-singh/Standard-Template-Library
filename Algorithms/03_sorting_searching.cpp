// ============================================================
//  STL ALGORITHMS - PART 3: SORTING, PARTITIONING & BINARY SEARCH
//  Header: #include <algorithm>
// ============================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void print(const string& label, const vector<int>& v) {
    cout << label << ": [ ";
    for (int x : v) cout << x << " ";
    cout << "]\n";
}

// ============================================================
// 1. sort
//    Kya karta hai: Range ko ascending order mein sort karta hai
//    Complexity: O(n log n) average
//    Stable? NO - same elements ki order guarantee nahi
// ============================================================
void demo_sort() {
    cout << "\n===== sort =====\n";

    vector<int> v = {5, 2, 8, 1, 9, 3};
    print("Before sort", v);

    // Ex 1: Default ascending sort
    sort(v.begin(), v.end());
    print("After sort (ascending)", v);

    // Ex 2: Descending sort
    sort(v.begin(), v.end(), greater<int>());
    print("After sort (descending)", v);

    // Ex 3: Custom comparator - sort by length
    vector<string> words = {"banana", "apple", "kiwi", "cherry"};
    sort(words.begin(), words.end(), [](const string& a, const string& b){
        return a.length() < b.length();
    });
    cout << "Sorted by length: ";
    for (auto& w : words) cout << w << " ";
    cout << "\n";

    // Ex 4: Sort struct by field
    struct Student { string name; int marks; };
    vector<Student> students = {{"Raj", 85}, {"Priya", 92}, {"Amit", 78}};
    sort(students.begin(), students.end(), [](const Student& a, const Student& b){
        return a.marks > b.marks;  // highest first
    });
    cout << "Students by marks (desc): ";
    for (auto& s : students) cout << s.name << "(" << s.marks << ") ";
    cout << "\n";
}

// ============================================================
// 2. stable_sort
//    Kya karta hai: Sort karta hai lekin same elements ki ORIGINAL ORDER maintain karta hai
//    Complexity: O(n log^2 n)
//    Stable? YES
// ============================================================
void demo_stable_sort() {
    cout << "\n===== stable_sort =====\n";

    struct Item { string name; int priority; };
    vector<Item> v = {{"Task A", 2}, {"Task B", 1}, {"Task C", 2}, {"Task D", 1}};

    // Ex 1: Priority se sort karo, same priority mein original order rakho
    stable_sort(v.begin(), v.end(), [](const Item& a, const Item& b){
        return a.priority < b.priority;
    });
    cout << "stable_sort by priority: ";
    for (auto& item : v) cout << item.name << "(p=" << item.priority << ") ";
    cout << "\n";

    // NOTE: Task B aur Task D (both p=1) original order mein rahenge
}

// ============================================================
// 3. partial_sort
//    Kya karta hai: Sirf pehle K elements sorted karta hai
//    Use: Top-K dhundne ke liye
//    Complexity: O(n log k)
// ============================================================
void demo_partial_sort() {
    cout << "\n===== partial_sort =====\n";

    vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4};
    print("Before", v);

    // Ex 1: Sirf pehle 3 sorted karo
    partial_sort(v.begin(), v.begin() + 3, v.end());
    print("partial_sort (first 3)", v);  // first 3 sorted, rest kuch bhi

    // Ex 2: Top 3 largest dhundho
    vector<int> v2 = {5, 2, 8, 1, 9, 3, 7};
    partial_sort(v2.begin(), v2.begin() + 3, v2.end(), greater<int>());
    cout << "Top 3 largest: " << v2[0] << " " << v2[1] << " " << v2[2] << "\n";
}

// ============================================================
// 4. partial_sort_copy
//    Kya karta hai: Source se sorted elements destination mein copy karta hai
// ============================================================
void demo_partial_sort_copy() {
    cout << "\n===== partial_sort_copy =====\n";

    vector<int> src = {5, 2, 8, 1, 9, 3};
    vector<int> dst(3);

    // Ex 1: Src se 3 smallest elements sorted copy karo
    partial_sort_copy(src.begin(), src.end(), dst.begin(), dst.end());
    print("Source (unchanged)", src);
    print("3 smallest sorted", dst);
}

// ============================================================
// 5. nth_element
//    Kya karta hai: nth position pe correct element rakhta hai
//    (nth se pehle elements <= nth, baad mein elements >= nth)
//    Complexity: O(n) average
// ============================================================
void demo_nth_element() {
    cout << "\n===== nth_element =====\n";

    vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4};
    int n = 3;  // 4th smallest (0-indexed)

    nth_element(v.begin(), v.begin() + n, v.end());
    cout << "4th smallest element: " << v[n] << "\n";
    cout << "Elements before it are all <= " << v[n] << ": ";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << "\n";

    // Ex 2: Median dhundho
    vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6};
    nth_element(data.begin(), data.begin() + data.size()/2, data.end());
    cout << "Median: " << data[data.size()/2] << "\n";
}

// ============================================================
// 6. is_sorted / is_sorted_until   [C++11]
//    Kya karta hai: Check karta hai ki range sorted hai ya nahi
// ============================================================
void demo_is_sorted() {
    cout << "\n===== is_sorted / is_sorted_until =====\n";

    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 5, 3, 4};

    // Ex 1: is_sorted
    cout << "v1 sorted? " << (is_sorted(v1.begin(), v1.end()) ? "Yes" : "No") << "\n";
    cout << "v2 sorted? " << (is_sorted(v2.begin(), v2.end()) ? "Yes" : "No") << "\n";

    // Ex 2: is_sorted_until - kitna sorted hai
    auto it = is_sorted_until(v2.begin(), v2.end());
    cout << "v2 is sorted until index: " << distance(v2.begin(), it) << "\n";
    // index 3 pe 3 < 5 nahi hai, toh wahan tak sorted hai
}

// ============================================================
// 7. partition / stable_partition
//    Kya karta hai: Elements ko do groups mein divide karta hai
//    - Condition true wale pehle
//    - Condition false wale baad mein
// ============================================================
void demo_partition() {
    cout << "\n===== partition / stable_partition =====\n";

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    // Ex 1: Even pehle, odd baad mein
    auto pivot = partition(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
    print("After partition (even first)", v);
    cout << "Partition point at index: " << distance(v.begin(), pivot) << "\n";

    // Ex 2: stable_partition - original relative order maintain karo
    vector<int> v2 = {1, 2, 3, 4, 5, 6};
    stable_partition(v2.begin(), v2.end(), [](int x){ return x % 2 == 0; });
    print("stable_partition (even first)", v2);

    // Ex 3: Practical - pass/fail separate karo
    vector<int> marks = {45, 32, 78, 29, 55, 40, 90};
    auto it = stable_partition(marks.begin(), marks.end(), [](int m){ return m >= 35; });
    cout << "Passed: ";
    for (auto p = marks.begin(); p != it; ++p) cout << *p << " ";
    cout << "\nFailed: ";
    for (auto p = it; p != marks.end(); ++p) cout << *p << " ";
    cout << "\n";
}

// ============================================================
// 8. partition_copy   [C++11]
//    Kya karta hai: Do alag destinations mein partition karta hai
// ============================================================
void demo_partition_copy() {
    cout << "\n===== partition_copy =====\n";

    vector<int> src = {1, 2, 3, 4, 5, 6};
    vector<int> evens, odds;

    partition_copy(src.begin(), src.end(),
                   back_inserter(evens),  // true wale
                   back_inserter(odds),   // false wale
                   [](int x){ return x % 2 == 0; });

    print("Evens", evens);
    print("Odds", odds);
}

// ============================================================
// 9. is_partitioned / partition_point   [C++11]
//    Kya karta hai: Check karta hai ki range partitioned hai
//    partition_point: Partition boundary dhundta hai
// ============================================================
void demo_partition_check() {
    cout << "\n===== is_partitioned / partition_point =====\n";

    vector<int> v = {2, 4, 6, 1, 3, 5};  // even pehle

    bool partitioned = is_partitioned(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
    cout << "Is partitioned (even first)? " << (partitioned ? "Yes" : "No") << "\n";

    if (partitioned) {
        auto pt = partition_point(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
        cout << "Partition point at index: " << distance(v.begin(), pt) << "\n";
    }
}

// ============================================================
// 10. binary_search
//     Kya karta hai: Sorted range mein element dhundta hai
//     Return: bool (milaa ya nahi)
//     PREREQUISITE: Range sorted honi chahiye!
// ============================================================
void demo_binary_search() {
    cout << "\n===== binary_search =====\n";

    vector<int> v = {1, 3, 5, 7, 9, 11, 13};

    // Ex 1: Value dhundho
    cout << "7 found? " << (binary_search(v.begin(), v.end(), 7) ? "Yes" : "No") << "\n";
    cout << "6 found? " << (binary_search(v.begin(), v.end(), 6) ? "Yes" : "No") << "\n";

    // Ex 2: Strings mein
    vector<string> names = {"Amit", "Priya", "Rahul", "Sneha"};
    sort(names.begin(), names.end());
    cout << "'Rahul' found? " << (binary_search(names.begin(), names.end(), "Rahul") ? "Yes" : "No") << "\n";
}

// ============================================================
// 11. lower_bound / upper_bound
//     lower_bound: Pehla element >= value
//     upper_bound: Pehla element > value
//     PREREQUISITE: Range sorted honi chahiye!
// ============================================================
void demo_bounds() {
    cout << "\n===== lower_bound / upper_bound =====\n";

    vector<int> v = {1, 2, 4, 4, 4, 7, 9};
    print("Sorted vector", v);

    // Ex 1: lower_bound - pehla element >= 4
    auto lb = lower_bound(v.begin(), v.end(), 4);
    cout << "lower_bound(4) index: " << distance(v.begin(), lb) << " value: " << *lb << "\n";

    // Ex 2: upper_bound - pehla element > 4
    auto ub = upper_bound(v.begin(), v.end(), 4);
    cout << "upper_bound(4) index: " << distance(v.begin(), ub) << " value: " << *ub << "\n";

    // Ex 3: Count occurrences of 4
    cout << "Count of 4s: " << distance(lb, ub) << "\n";

    // Ex 4: Insertion position dhundho
    auto pos = lower_bound(v.begin(), v.end(), 5);
    cout << "Insert 5 at index: " << distance(v.begin(), pos) << "\n";
}

// ============================================================
// 12. equal_range
//     Kya karta hai: lower_bound aur upper_bound dono return karta hai
//     Return: pair of iterators
// ============================================================
void demo_equal_range() {
    cout << "\n===== equal_range =====\n";

    vector<int> v = {1, 2, 4, 4, 4, 7, 9};

    // Ex 1: 4 ka range dhundho
    auto [lo, hi] = equal_range(v.begin(), v.end(), 4);
    cout << "4 starts at index: " << distance(v.begin(), lo) << "\n";
    cout << "4 ends before index: " << distance(v.begin(), hi) << "\n";
    cout << "Count of 4: " << distance(lo, hi) << "\n";

    // Ex 2: Element nahi mila to same iterator return hoga
    auto [lo2, hi2] = equal_range(v.begin(), v.end(), 5);
    cout << "5 not found: lo==hi? " << (lo2 == hi2 ? "Yes" : "No") << "\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "===========================================\n";
    cout << "  STL SORTING & SEARCHING ALGORITHMS      \n";
    cout << "===========================================\n";

    demo_sort();
    demo_stable_sort();
    demo_partial_sort();
    demo_partial_sort_copy();
    demo_nth_element();
    demo_is_sorted();
    demo_partition();
    demo_partition_copy();
    demo_partition_check();
    demo_binary_search();
    demo_bounds();
    demo_equal_range();

    cout << "\n===========================================\n";
    cout << "  SORTING CHEATSHEET:\n";
    cout << "  sort()         → O(n log n), not stable\n";
    cout << "  stable_sort()  → O(n log^2 n), stable\n";
    cout << "  partial_sort() → Top-K ke liye, O(n log k)\n";
    cout << "  nth_element()  → Median ke liye, O(n) avg\n";
    cout << "  binary_search  → SORTED range mein dhundho\n";
    cout << "  lower_bound    → First >= value\n";
    cout << "  upper_bound    → First > value\n";
    cout << "  equal_range    → dono boundaries ek saath\n";
    cout << "===========================================\n";

    return 0;
}
