// ============================================================
//  STL ALGORITHMS - PART 4: SET OPERATIONS, MERGE & HEAP
//  PREREQUISITE: Set operations ke liye ranges SORTED honi chahiye!
//  Header: #include <algorithm>
// ============================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(const string& label, const vector<int>& v) {
    cout << label << ": [ ";
    for (int x : v) cout << x << " ";
    cout << "]\n";
}

// ============================================================
// 1. includes
//    Kya karta hai: Check karta hai ki ek sorted range doosri mein
//                   subset hai ya nahi
//    Return: bool
// ============================================================
void demo_includes() {
    cout << "\n===== includes =====\n";

    vector<int> big   = {1, 2, 3, 4, 5, 6, 7};
    vector<int> sub   = {2, 4, 6};
    vector<int> nosub = {2, 4, 8};

    // Ex 1: Is {2,4,6} subset of big?
    cout << "{2,4,6} ⊆ big? " << (includes(big.begin(), big.end(), sub.begin(), sub.end()) ? "Yes" : "No") << "\n";
    cout << "{2,4,8} ⊆ big? " << (includes(big.begin(), big.end(), nosub.begin(), nosub.end()) ? "Yes" : "No") << "\n";

    // Ex 2: Practical - required skills check karo
    vector<string> available = {"C++", "Java", "Python", "SQL"};
    vector<string> required  = {"C++", "Python"};
    // Already sorted alphabetically
    cout << "Has required skills? " << (includes(available.begin(), available.end(),
                                                   required.begin(), required.end()) ? "Yes" : "No") << "\n";
}

// ============================================================
// 2. set_union
//    Kya karta hai: Do sorted ranges ka union (A ∪ B)
//                   Dono mein se saare unique elements
// ============================================================
void demo_set_union() {
    cout << "\n===== set_union =====\n";

    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 4, 5, 6, 7};
    vector<int> result;

    set_union(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
    print("A", A);
    print("B", B);
    print("A ∪ B (union)", result);

    // Ex 2: Names union
    vector<string> class1 = {"Amit", "Priya", "Rahul"};
    vector<string> class2 = {"Priya", "Sneha", "Vivek"};
    vector<string> allStudents;
    set_union(class1.begin(), class1.end(), class2.begin(), class2.end(),
              back_inserter(allStudents));
    cout << "All students: ";
    for (auto& s : allStudents) cout << s << " ";
    cout << "\n";
}

// ============================================================
// 3. set_intersection
//    Kya karta hai: Do sorted ranges ka intersection (A ∩ B)
//                   Dono mein common elements
// ============================================================
void demo_set_intersection() {
    cout << "\n===== set_intersection =====\n";

    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 4, 5, 6, 7};
    vector<int> common;

    set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(common));
    print("A ∩ B (intersection)", common);

    // Ex 2: Common friends
    vector<string> friends1 = {"Amit", "Priya", "Rahul", "Sneha"};
    vector<string> friends2 = {"Karan", "Priya", "Sneha", "Vivek"};
    vector<string> commonFriends;
    set_intersection(friends1.begin(), friends1.end(),
                     friends2.begin(), friends2.end(),
                     back_inserter(commonFriends));
    cout << "Common friends: ";
    for (auto& f : commonFriends) cout << f << " ";
    cout << "\n";
}

// ============================================================
// 4. set_difference
//    Kya karta hai: A - B → A mein jo elements hain lekin B mein nahi
// ============================================================
void demo_set_difference() {
    cout << "\n===== set_difference =====\n";

    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 4, 5, 6, 7};
    vector<int> diff;

    set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(diff));
    print("A - B", diff);  // {1, 2}

    // Ex 2: B - A
    vector<int> diff2;
    set_difference(B.begin(), B.end(), A.begin(), A.end(), back_inserter(diff2));
    print("B - A", diff2);  // {6, 7}

    // Ex 3: Practical - Jo items ordered hain lekin delivered nahi
    vector<int> ordered   = {101, 102, 103, 104, 105};
    vector<int> delivered = {101, 103, 105};
    vector<int> pending;
    set_difference(ordered.begin(), ordered.end(), delivered.begin(), delivered.end(),
                   back_inserter(pending));
    print("Pending deliveries", pending);
}

// ============================================================
// 5. set_symmetric_difference
//    Kya karta hai: Sirf ek mein hain wale (A △ B) = (A-B) ∪ (B-A)
// ============================================================
void demo_set_symmetric_difference() {
    cout << "\n===== set_symmetric_difference =====\n";

    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 4, 5, 6, 7};
    vector<int> result;

    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
    print("A △ B (symmetric diff)", result);  // {1, 2, 6, 7}
}

// ============================================================
// 6. merge
//    Kya karta hai: Do sorted ranges ko ek sorted range mein combine karta hai
// ============================================================
void demo_merge() {
    cout << "\n===== merge =====\n";

    vector<int> A = {1, 3, 5, 7};
    vector<int> B = {2, 4, 6, 8};
    vector<int> merged(8);

    merge(A.begin(), A.end(), B.begin(), B.end(), merged.begin());
    print("A", A);
    print("B", B);
    print("Merged", merged);

    // Ex 2: Names merge
    vector<string> list1 = {"Alice", "Charlie", "Eve"};
    vector<string> list2 = {"Bob", "Diana", "Frank"};
    vector<string> combined;
    merge(list1.begin(), list1.end(), list2.begin(), list2.end(), back_inserter(combined));
    cout << "Merged names: ";
    for (auto& n : combined) cout << n << " ";
    cout << "\n";
}

// ============================================================
// 7. inplace_merge
//    Kya karta hai: Ek hi vector ke do sorted halves ko in-place merge karta hai
// ============================================================
void demo_inplace_merge() {
    cout << "\n===== inplace_merge =====\n";

    vector<int> v = {1, 3, 5, 2, 4, 6};  // Do sorted halves
    print("Before inplace_merge", v);

    inplace_merge(v.begin(), v.begin() + 3, v.end());
    print("After inplace_merge", v);
}

// ============================================================
// 8. HEAP OPERATIONS
//    Heap = ek tree structure jahan parent >= children (max-heap)
//    make_heap, push_heap, pop_heap, sort_heap, is_heap
// ============================================================
void demo_heap() {
    cout << "\n===== HEAP OPERATIONS =====\n";

    // make_heap: Vector ko heap mein convert karo
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};
    print("Before make_heap", v);

    make_heap(v.begin(), v.end());
    print("After make_heap", v);
    cout << "Max element (front): " << v.front() << "\n";

    // push_heap: Naya element add karo
    v.push_back(100);        // pehle push_back
    push_heap(v.begin(), v.end());  // phir push_heap
    print("After push 100", v);
    cout << "New max: " << v.front() << "\n";

    // pop_heap: Max element hataao
    pop_heap(v.begin(), v.end());  // max ko end pe bhejo
    int maxVal = v.back();
    v.pop_back();                  // phir vector se hataao
    cout << "Popped max value: " << maxVal << "\n";
    print("After pop", v);

    // is_heap: Check karo
    cout << "Is heap? " << (is_heap(v.begin(), v.end()) ? "Yes" : "No") << "\n";

    // sort_heap: Heap ko sort karo (ascending)
    sort_heap(v.begin(), v.end());
    print("After sort_heap (ascending)", v);

    // is_heap_until: Kitna heap hai
    vector<int> v2 = {9, 5, 8, 3, 1, 4, 2};  // Partially heap
    auto it = is_heap_until(v2.begin(), v2.end());
    cout << "Heap valid until index: " << distance(v2.begin(), it) << "\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "===========================================\n";
    cout << "  SET OPERATIONS, MERGE & HEAP ALGORITHMS \n";
    cout << "===========================================\n";

    cout << "\n--- SET OPERATIONS (sorted ranges chahiye!) ---\n";
    demo_includes();
    demo_set_union();
    demo_set_intersection();
    demo_set_difference();
    demo_set_symmetric_difference();

    cout << "\n--- MERGE OPERATIONS ---\n";
    demo_merge();
    demo_inplace_merge();

    cout << "\n--- HEAP OPERATIONS ---\n";
    demo_heap();

    cout << "\n===========================================\n";
    cout << "  HEAP IDIOM (Priority Queue style):\n";
    cout << "  1. make_heap(v.begin(), v.end())\n";
    cout << "  2. v.push_back(x); push_heap(...)  → insert\n";
    cout << "  3. pop_heap(...); v.pop_back()      → extract max\n";
    cout << "  4. v.front()                        → peek max\n";
    cout << "\n  SET OP FORMULA:\n";
    cout << "  Union        → A ∪ B (all unique)\n";
    cout << "  Intersection → A ∩ B (common only)\n";
    cout << "  Difference   → A - B (in A, not in B)\n";
    cout << "  Sym Diff     → A △ B (not in both)\n";
    cout << "===========================================\n";

    return 0;
}
