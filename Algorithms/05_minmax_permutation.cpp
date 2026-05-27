// ============================================================
//  STL ALGORITHMS - PART 5: MIN/MAX, PERMUTATIONS & LEXICOGRAPHIC
//  Header: #include <algorithm>
// ============================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <numeric>
using namespace std;

void print(const string& label, const vector<int>& v) {
    cout << label << ": [ ";
    for (int x : v) cout << x << " ";
    cout << "]\n";
}

// ============================================================
// 1. min / max
//    Kya karta hai: Do values mein se chhota/bada return karta hai
//    Return: const reference to min/max
// ============================================================
void demo_min_max() {
    cout << "\n===== min / max =====\n";

    // Ex 1: Basic comparison
    int a = 5, b = 3;
    cout << "min(5,3) = " << min(a, b) << "\n";
    cout << "max(5,3) = " << max(a, b) << "\n";

    // Ex 2: Initializer list se min/max (C++11)
    cout << "min of {3,1,4,1,5} = " << min({3, 1, 4, 1, 5}) << "\n";
    cout << "max of {3,1,4,1,5} = " << max({3, 1, 4, 1, 5}) << "\n";

    // Ex 3: Custom comparator
    string s1 = "hello", s2 = "world";
    cout << "Shorter string: " << min(s1, s2, [](const string& a, const string& b){
        return a.length() < b.length();
    }) << "\n";

    // Ex 4: Boundary clamping ke liye
    int speed = 150;
    int minSpeed = 0, maxSpeed = 120;
    int clamped = min(max(speed, minSpeed), maxSpeed);
    cout << "Clamped speed: " << clamped << "\n";
}

// ============================================================
// 2. minmax   [C++11]
//    Kya karta hai: Ek saath min aur max return karta hai
//    Return: pair{min, max}
// ============================================================
void demo_minmax() {
    cout << "\n===== minmax =====\n";

    // Ex 1: Do values
    auto [mn, mx] = minmax(7, 3);
    cout << "minmax(7,3): min=" << mn << ", max=" << mx << "\n";

    // Ex 2: Initializer list
    auto [lo, hi] = minmax({5, 2, 8, 1, 9, 3});
    cout << "minmax({5,2,8,1,9,3}): min=" << lo << ", max=" << hi << "\n";

    // Ex 3: Array bounds check
    vector<int> v = {3, 7, 1, 9, 4};
    auto [small, large] = minmax({3, 7, 1, 9, 4});
    cout << "Range: " << small << " to " << large << "\n";
}

// ============================================================
// 3. clamp   [C++17]
//    Kya karta hai: Value ko [lo, hi] range mein rakhta hai
//    Return: lo agar value < lo, hi agar value > hi, else value
// ============================================================
void demo_clamp() {
    cout << "\n===== clamp (C++17) =====\n";

    // Ex 1: Basic clamping
    cout << "clamp(3, 1, 10)  = " << clamp(3, 1, 10) << "\n";   // 3 (within)
    cout << "clamp(-5, 1, 10) = " << clamp(-5, 1, 10) << "\n";  // 1 (too low)
    cout << "clamp(15, 1, 10) = " << clamp(15, 1, 10) << "\n";  // 10 (too high)

    // Ex 2: Game mein health clamp
    int health = 150;
    health = clamp(health, 0, 100);
    cout << "Health (clamped): " << health << "\n";

    // Ex 3: Volume control
    double volume = -0.5;
    volume = clamp(volume, 0.0, 1.0);
    cout << "Volume (clamped): " << volume << "\n";

    // Ex 4: Multiple values clamp
    vector<int> v = {-3, 5, 15, 2, -1, 8};
    vector<int> clamped(v.size());
    transform(v.begin(), v.end(), clamped.begin(), [](int x){ return clamp(x, 0, 10); });
    print("Clamped to [0,10]", clamped);
}

// ============================================================
// 4. min_element / max_element
//    Kya karta hai: Range mein minimum/maximum element dhundta hai
//    Return: Iterator to min/max element
// ============================================================
void demo_min_max_element() {
    cout << "\n===== min_element / max_element =====\n";

    vector<int> v = {3, 7, 1, 9, 4, 6};
    print("Vector", v);

    // Ex 1: min_element
    auto minIt = min_element(v.begin(), v.end());
    cout << "Min element: " << *minIt << " at index " << distance(v.begin(), minIt) << "\n";

    // Ex 2: max_element
    auto maxIt = max_element(v.begin(), v.end());
    cout << "Max element: " << *maxIt << " at index " << distance(v.begin(), maxIt) << "\n";

    // Ex 3: Custom comparator - absolute value se compare
    vector<int> v2 = {-5, 3, -1, 8, -9};
    auto absMax = max_element(v2.begin(), v2.end(), [](int a, int b){
        return abs(a) < abs(b);
    });
    cout << "Max by absolute value: " << *absMax << "\n";

    // Ex 4: Struct mein max dhundho
    struct Product { string name; double price; };
    vector<Product> products = {{"Apple", 50.0}, {"Mango", 80.0}, {"Banana", 20.0}};
    auto mostExpensive = max_element(products.begin(), products.end(),
                                      [](const Product& a, const Product& b){ return a.price < b.price; });
    cout << "Most expensive: " << mostExpensive->name << " ₹" << mostExpensive->price << "\n";
}

// ============================================================
// 5. minmax_element   [C++11]
//    Kya karta hai: Ek saath min aur max element dhundta hai
//    Return: pair of iterators
// ============================================================
void demo_minmax_element() {
    cout << "\n===== minmax_element =====\n";

    vector<int> v = {3, 7, 1, 9, 4, 6};

    // Ex 1: Ek baar mein min aur max
    auto [minIt, maxIt] = minmax_element(v.begin(), v.end());
    cout << "Min: " << *minIt << ", Max: " << *maxIt << "\n";
    cout << "Range span: " << (*maxIt - *minIt) << "\n";

    // Ex 2: Marks mein topper aur lowest
    vector<int> marks = {75, 92, 58, 88, 65};
    auto [low, high] = minmax_element(marks.begin(), marks.end());
    cout << "Lowest marks: " << *low << ", Highest: " << *high << "\n";
}

// ============================================================
// 6. next_permutation / prev_permutation
//    Kya karta hai: Lexicographically agle/pehle permutation pe jaata hai
//    Return: bool (true = permutation found, false = wrap around hua)
// ============================================================
void demo_permutations() {
    cout << "\n===== next_permutation / prev_permutation =====\n";

    // Ex 1: Ek ek karke saare permutations
    vector<int> v = {1, 2, 3};
    cout << "All permutations of {1,2,3}:\n";
    do {
        cout << "  ";
        for (int x : v) cout << x << " ";
        cout << "\n";
    } while (next_permutation(v.begin(), v.end()));

    // Ex 2: String permutations
    string s = "abc";
    cout << "\nAll permutations of 'abc':\n";
    sort(s.begin(), s.end());  // start from smallest
    do {
        cout << "  " << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    // Ex 3: prev_permutation
    vector<int> v2 = {3, 2, 1};  // last permutation
    cout << "\nprev_permutation from {3,2,1}:\n";
    for (int i = 0; i < 3; i++) {
        prev_permutation(v2.begin(), v2.end());
        cout << "  ";
        for (int x : v2) cout << x << " ";
        cout << "\n";
    }

    // Ex 4: Count permutations
    vector<int> v3 = {1, 2, 3, 4};
    sort(v3.begin(), v3.end());
    int count = 0;
    do { count++; } while (next_permutation(v3.begin(), v3.end()));
    cout << "\nTotal permutations of {1,2,3,4}: " << count << " (= 4! = 24)\n";
}

// ============================================================
// 7. is_permutation   [C++11]
//    Kya karta hai: Check karta hai ki do ranges ek doosre ke permutations hain
//    Return: bool
// ============================================================
void demo_is_permutation() {
    cout << "\n===== is_permutation =====\n";

    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = {4, 2, 1, 3};
    vector<int> v3 = {1, 2, 3, 5};

    // Ex 1: Basic check
    cout << "v2 is permutation of v1? " << (is_permutation(v1.begin(), v1.end(), v2.begin()) ? "Yes" : "No") << "\n";
    cout << "v3 is permutation of v1? " << (is_permutation(v1.begin(), v1.end(), v3.begin()) ? "Yes" : "No") << "\n";

    // Ex 2: Anagram check
    string s1 = "listen";
    string s2 = "silent";
    cout << "'" << s1 << "' anagram of '" << s2 << "'? "
         << (is_permutation(s1.begin(), s1.end(), s2.begin()) ? "Yes" : "No") << "\n";
}

// ============================================================
// 8. lexicographical_compare
//    Kya karta hai: Do ranges ko dictionary order mein compare karta hai
//    Return: true agar first < second
// ============================================================
void demo_lexicographical_compare() {
    cout << "\n===== lexicographical_compare =====\n";

    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {1, 2, 4};
    vector<int> v3 = {1, 2, 3};

    // Ex 1: Basic comparison
    cout << "v1 < v2? " << (lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()) ? "Yes" : "No") << "\n";
    cout << "v2 < v1? " << (lexicographical_compare(v2.begin(), v2.end(), v1.begin(), v1.end()) ? "Yes" : "No") << "\n";
    cout << "v1 < v3? " << (lexicographical_compare(v1.begin(), v1.end(), v3.begin(), v3.end()) ? "Yes" : "No") << "\n";

    // Ex 2: Case-insensitive string compare
    string s1 = "apple";
    string s2 = "Banana";
    bool s1_less = lexicographical_compare(s1.begin(), s1.end(),
                                            s2.begin(), s2.end(),
                                            [](char a, char b){ return tolower(a) < tolower(b); });
    cout << "'" << s1 << "' < '" << s2 << "' (case-insensitive)? " << (s1_less ? "Yes" : "No") << "\n";

    // Ex 3: Version comparison
    vector<int> ver1 = {1, 2, 3};
    vector<int> ver2 = {1, 3, 0};
    cout << "v1.2.3 < v1.3.0? " << (lexicographical_compare(ver1.begin(), ver1.end(), ver2.begin(), ver2.end()) ? "Yes" : "No") << "\n";
}

// ============================================================
// 9. sample   [C++17]
//    Kya karta hai: Range se N random elements choose karta hai (without replacement)
// ============================================================
void demo_sample() {
    cout << "\n===== sample (C++17) =====\n";

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> sampled;

    // Ex 1: 4 random elements choose karo
    mt19937 rng(42);
    sample(v.begin(), v.end(), back_inserter(sampled), 4, rng);
    print("Random sample of 4", sampled);

    // Ex 2: Lottery - 6 numbers choose karo from 1-49
    vector<int> lottery(49);
    iota(lottery.begin(), lottery.end(), 1);  // 1 to 49
    vector<int> winning;
    sample(lottery.begin(), lottery.end(), back_inserter(winning), 6, rng);
    sort(winning.begin(), winning.end());
    print("Lottery numbers", winning);
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "===========================================\n";
    cout << "  MIN/MAX, PERMUTATION & MISC ALGORITHMS  \n";
    cout << "===========================================\n";

    demo_min_max();
    demo_minmax();
    demo_clamp();
    demo_min_max_element();
    demo_minmax_element();
    demo_permutations();
    demo_is_permutation();
    demo_lexicographical_compare();
    demo_sample();

    cout << "\n===========================================\n";
    cout << "  QUICK REFERENCE:\n";
    cout << "  min/max(a,b)         → do values compare\n";
    cout << "  min/max({...})       → initializer list\n";
    cout << "  clamp(v, lo, hi)     → bound karo (C++17)\n";
    cout << "  min/max_element      → iterator to min/max\n";
    cout << "  minmax_element       → pair{min_it, max_it}\n";
    cout << "  next_permutation     → next in lex order\n";
    cout << "  is_permutation       → anagram check\n";
    cout << "  lex_compare          → dictionary compare\n";
    cout << "  sample               → random selection\n";
    cout << "===========================================\n";

    return 0;
}
