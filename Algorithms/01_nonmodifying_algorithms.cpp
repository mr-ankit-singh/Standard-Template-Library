// ============================================================
//  STL ALGORITHMS - PART 1: NON-MODIFYING SEQUENCE OPERATIONS
//  Yeh algorithms sirf READ karte hain, data change nahi karte
//  Header: #include <algorithm>
// ============================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Helper: vector print karo
void print(const string& label, const vector<int>& v) {
    cout << label << ": [ ";
    for (int x : v) cout << x << " ";
    cout << "]\n";
}

// ============================================================
// 1. for_each(first, last, function)
//    Kya karta hai: Range ke har element pe ek function chalata hai
//    Return: function object
// ============================================================
void demo_for_each() {
    cout << "\n===== for_each =====\n";

    vector<int> v = {1, 2, 3, 4, 5};

    // Ex 1: Har element print karo
    cout << "Elements: ";
    for_each(v.begin(), v.end(), [](int x) {
        cout << x << " ";
    });
    cout << "\n";

    // Ex 2: Har element ko 2 se multiply karo (in-place)
    for_each(v.begin(), v.end(), [](int& x) { x *= 2; });
    print("After *2", v);

    // Ex 3: Sum nikalo
    int sum = 0;
    for_each(v.begin(), v.end(), [&sum](int x) { sum += x; });
    cout << "Sum = " << sum << "\n";

    // Ex 4: Sirf even print karo
    cout << "Evens: ";
    for_each(v.begin(), v.end(), [](int x) {
        if (x % 2 == 0) cout << x << " ";
    });
    cout << "\n";
}

// ============================================================
// 2. for_each_n(first, n, function)   [C++17]
//    Kya karta hai: Pehle N elements pe function chalata hai
// ============================================================
void demo_for_each_n() {
    cout << "\n===== for_each_n =====\n";

    vector<int> v = {10, 20, 30, 40, 50};

    // Ex 1: Pehle 3 print karo
    cout << "First 3: ";
    for_each_n(v.begin(), 3, [](int x) { cout << x << " "; });
    cout << "\n";

    // Ex 2: Pehle 4 ko double karo
    for_each_n(v.begin(), 4, [](int& x) { x *= 2; });
    print("After doubling first 4", v);
}

// ============================================================
// 3. all_of / any_of / none_of   [C++11]
//    Kya karta hai: Range pe condition check karta hai
//    Return: bool
// ============================================================
void demo_all_any_none() {
    cout << "\n===== all_of / any_of / none_of =====\n";

    vector<int> v1 = {2, 4, 6, 8};
    vector<int> v2 = {1, 2, 3, 4};
    vector<int> v3 = {1, 3, 5, 7};

    auto isEven = [](int x) { return x % 2 == 0; };
    auto isNeg  = [](int x) { return x < 0; };

    // Ex 1: all_of - saare even hain?
    cout << "v1 all even? " << (all_of(v1.begin(), v1.end(), isEven) ? "Yes" : "No") << "\n";
    cout << "v2 all even? " << (all_of(v2.begin(), v2.end(), isEven) ? "Yes" : "No") << "\n";

    // Ex 2: any_of - koi ek even hai?
    cout << "v2 any even? " << (any_of(v2.begin(), v2.end(), isEven) ? "Yes" : "No") << "\n";
    cout << "v3 any even? " << (any_of(v3.begin(), v3.end(), isEven) ? "Yes" : "No") << "\n";

    // Ex 3: none_of - koi negative nahi hai?
    cout << "v1 none negative? " << (none_of(v1.begin(), v1.end(), isNeg) ? "Yes" : "No") << "\n";

    // Ex 4: Practical use - marks check
    vector<int> marks = {85, 90, 78, 92, 88};
    cout << "Sab pass (>= 35)? " << (all_of(marks.begin(), marks.end(), [](int m){ return m >= 35; }) ? "Yes" : "No") << "\n";
    cout << "Koi distinction (>= 90)? " << (any_of(marks.begin(), marks.end(), [](int m){ return m >= 90; }) ? "Yes" : "No") << "\n";
}

// ============================================================
// 4. count / count_if
//    Kya karta hai: Kitne elements condition satisfy karte hain
//    Return: ptrdiff_t (count)
// ============================================================
void demo_count() {
    cout << "\n===== count / count_if =====\n";

    vector<int> v = {1, 2, 3, 2, 4, 2, 5};

    // Ex 1: count - ek specific value kitni baar hai
    cout << "2 appears: " << count(v.begin(), v.end(), 2) << " times\n";

    // Ex 2: count_if - condition wale count karo
    int evenCount = count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
    cout << "Even numbers: " << evenCount << "\n";

    // Ex 3: String mein vowels count
    string s = "Hello World";
    int vowels = count_if(s.begin(), s.end(), [](char c){
        return string("aeiouAEIOU").find(c) != string::npos;
    });
    cout << "Vowels in '" << s << "': " << vowels << "\n";

    // Ex 4: Greater than threshold
    int above5 = count_if(v.begin(), v.end(), [](int x){ return x > 3; });
    cout << "Elements > 3: " << above5 << "\n";
}

// ============================================================
// 5. find / find_if / find_if_not
//    Kya karta hai: Element dhundta hai
//    Return: Iterator (end() if not found)
// ============================================================
void demo_find() {
    cout << "\n===== find / find_if / find_if_not =====\n";

    vector<int> v = {10, 20, 30, 40, 50};

    // Ex 1: find - exact value dhundho
    auto it = find(v.begin(), v.end(), 30);
    if (it != v.end())
        cout << "Found 30 at index: " << distance(v.begin(), it) << "\n";
    else
        cout << "30 not found\n";

    // Ex 2: find_if - pehla even dhundho
    auto it2 = find_if(v.begin(), v.end(), [](int x){ return x > 25; });
    cout << "First element > 25: " << *it2 << "\n";

    // Ex 3: find_if_not - pehla element jo condition false kare
    vector<int> v2 = {2, 4, 6, 7, 8};
    auto it3 = find_if_not(v2.begin(), v2.end(), [](int x){ return x % 2 == 0; });
    cout << "First odd number: " << *it3 << "\n";

    // Ex 4: String mein character dhundho
    string name = "Rahul Sharma";
    auto it4 = find(name.begin(), name.end(), ' ');
    cout << "Space at position: " << distance(name.begin(), it4) << "\n";
}

// ============================================================
// 6. find_end
//    Kya karta hai: Ek subsequence ka LAST occurrence dhundta hai
// ============================================================
void demo_find_end() {
    cout << "\n===== find_end =====\n";

    vector<int> v = {1, 2, 3, 1, 2, 3, 1, 2};
    vector<int> pattern = {1, 2};

    // Ex 1: Pattern ka last occurrence
    auto it = find_end(v.begin(), v.end(), pattern.begin(), pattern.end());
    cout << "Last occurrence of {1,2} starts at index: "
         << distance(v.begin(), it) << "\n";

    // Ex 2: String mein last "ab" dhundho
    string s = "ababcab";
    string pat = "ab";
    auto it2 = find_end(s.begin(), s.end(), pat.begin(), pat.end());
    cout << "Last 'ab' in '" << s << "' at: " << distance(s.begin(), it2) << "\n";
}

// ============================================================
// 7. find_first_of
//    Kya karta hai: Pehla element dhundta hai jo kisi set mein ho
// ============================================================
void demo_find_first_of() {
    cout << "\n===== find_first_of =====\n";

    vector<int> v = {1, 5, 3, 8, 2, 9};
    vector<int> targets = {8, 2};  // in mein se koi bhi

    // Ex 1: v mein pehla element jo targets mein ho
    auto it = find_first_of(v.begin(), v.end(), targets.begin(), targets.end());
    cout << "First element from targets: " << *it
         << " at index " << distance(v.begin(), it) << "\n";

    // Ex 2: String mein pehla vowel
    string s = "Hello World";
    string vowels = "aeiouAEIOU";
    auto it2 = find_first_of(s.begin(), s.end(), vowels.begin(), vowels.end());
    cout << "First vowel in '" << s << "': " << *it2 << "\n";
}

// ============================================================
// 8. adjacent_find
//    Kya karta hai: Do consecutive equal (ya condition-satisfying) elements dhundta hai
// ============================================================
void demo_adjacent_find() {
    cout << "\n===== adjacent_find =====\n";

    vector<int> v = {1, 2, 3, 3, 4, 5};

    // Ex 1: Pehle do equal adjacent elements
    auto it = adjacent_find(v.begin(), v.end());
    if (it != v.end())
        cout << "First duplicate pair: " << *it << " at index " << distance(v.begin(), it) << "\n";

    // Ex 2: Custom condition - consecutive where second > first*2
    vector<int> v2 = {1, 2, 5, 6, 3};
    auto it2 = adjacent_find(v2.begin(), v2.end(), [](int a, int b){ return b > a * 2; });
    if (it2 != v2.end())
        cout << "Pair where second > first*2: " << *it2 << ", " << *(it2+1) << "\n";
}

// ============================================================
// 9. mismatch
//    Kya karta hai: Do ranges mein pehla mismatch dhundta hai
//    Return: pair of iterators
// ============================================================
void demo_mismatch() {
    cout << "\n===== mismatch =====\n";

    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 9, 4, 5};

    // Ex 1: Pehla mismatch dhundho
    auto [it1, it2] = mismatch(v1.begin(), v1.end(), v2.begin());
    cout << "First mismatch: v1[" << distance(v1.begin(), it1) << "]="
         << *it1 << " vs v2=" << *it2 << "\n";

    // Ex 2: Strings compare
    string s1 = "Rahul";
    string s2 = "Rahil";
    auto [c1, c2] = mismatch(s1.begin(), s1.end(), s2.begin());
    cout << "Strings differ at: '" << *c1 << "' vs '" << *c2 << "'\n";
}

// ============================================================
// 10. equal
//     Kya karta hai: Do ranges equal hain ya nahi
//     Return: bool
// ============================================================
void demo_equal() {
    cout << "\n===== equal =====\n";

    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 2, 3};
    vector<int> v3 = {1, 2, 4};

    // Ex 1: Basic comparison
    cout << "v1 == v2? " << (equal(v1.begin(), v1.end(), v2.begin()) ? "Yes" : "No") << "\n";
    cout << "v1 == v3? " << (equal(v1.begin(), v1.end(), v3.begin()) ? "Yes" : "No") << "\n";

    // Ex 2: Case-insensitive string comparison
    string s1 = "Hello";
    string s2 = "hello";
    bool same = equal(s1.begin(), s1.end(), s2.begin(), [](char a, char b){
        return tolower(a) == tolower(b);
    });
    cout << "'" << s1 << "' == '" << s2 << "' (case-insensitive)? " << (same ? "Yes" : "No") << "\n";
}

// ============================================================
// 11. search
//     Kya karta hai: Ek range mein doosri range (subsequence) dhundta hai
//     Return: Iterator to first occurrence
// ============================================================
void demo_search() {
    cout << "\n===== search =====\n";

    vector<int> v = {1, 2, 3, 4, 5, 3, 4};
    vector<int> pattern = {3, 4};

    // Ex 1: Pattern ka pehla occurrence
    auto it = search(v.begin(), v.end(), pattern.begin(), pattern.end());
    cout << "Pattern {3,4} found at index: " << distance(v.begin(), it) << "\n";

    // Ex 2: Substring search
    string text = "Hello World, Hello India";
    string word = "Hello";
    auto it2 = search(text.begin(), text.end(), word.begin(), word.end());
    cout << "First 'Hello' at: " << distance(text.begin(), it2) << "\n";

    // Ex 3: Not found case
    vector<int> pat2 = {9, 9};
    auto it3 = search(v.begin(), v.end(), pat2.begin(), pat2.end());
    cout << "Pattern {9,9} found? " << (it3 == v.end() ? "No" : "Yes") << "\n";
}

// ============================================================
// 12. search_n
//     Kya karta hai: N consecutive equal elements dhundta hai
// ============================================================
void demo_search_n() {
    cout << "\n===== search_n =====\n";

    vector<int> v = {1, 2, 2, 2, 3, 4};

    // Ex 1: Continuous 3 twos dhundho
    auto it = search_n(v.begin(), v.end(), 3, 2);
    cout << "Three consecutive 2s at index: " << distance(v.begin(), it) << "\n";

    // Ex 2: Continuous 2 threes
    auto it2 = search_n(v.begin(), v.end(), 2, 3);
    cout << "Two consecutive 3s? " << (it2 == v.end() ? "Not found" : "Found") << "\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "===========================================\n";
    cout << "  STL NON-MODIFYING ALGORITHMS - NOTES    \n";
    cout << "===========================================\n";

    demo_for_each();
    demo_for_each_n();
    demo_all_any_none();
    demo_count();
    demo_find();
    demo_find_end();
    demo_find_first_of();
    demo_adjacent_find();
    demo_mismatch();
    demo_equal();
    demo_search();
    demo_search_n();

    cout << "\n===========================================\n";
    cout << "  QUICK REFERENCE:\n";
    cout << "  for_each     → har element pe fn chalao\n";
    cout << "  all_of       → saare satisfy karte hain?\n";
    cout << "  any_of       → koi ek satisfy karta hai?\n";
    cout << "  none_of      → koi nahi satisfy karta?\n";
    cout << "  count        → kitne elements hain\n";
    cout << "  find         → element dhundho\n";
    cout << "  search       → subsequence dhundho\n";
    cout << "  mismatch     → pehla difference dhundho\n";
    cout << "  equal        → do ranges equal hain?\n";
    cout << "===========================================\n";

    return 0;
}
