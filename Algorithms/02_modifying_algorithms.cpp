// ============================================================
//  STL ALGORITHMS - PART 2: MODIFYING SEQUENCE OPERATIONS
//  Yeh algorithms data MODIFY karte hain
//  Header: #include <algorithm>
// ============================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <iterator>
#include <chrono>
using namespace std;

void print(const string& label, const vector<int>& v) {
    cout << label << ": [ ";
    for (int x : v) cout << x << " ";
    cout << "]\n";
}

// ============================================================
// 1. copy / copy_if
//    Kya karta hai: Elements ek range se doosri range mein copy karta hai
//    Return: Iterator to end of destination
// ============================================================
void demo_copy() {
    cout << "\n===== copy / copy_if =====\n";

    vector<int> src = {1, 2, 3, 4, 5};
    vector<int> dst(5);

    // Ex 1: Poori range copy karo
    copy(src.begin(), src.end(), dst.begin());
    print("Copied", dst);

    // Ex 2: copy_if - sirf even copy karo
    vector<int> evens;
    copy_if(src.begin(), src.end(), back_inserter(evens),
            [](int x){ return x % 2 == 0; });
    print("Only evens copied", evens);

    // Ex 3: Copy to cout (print karo directly)
    cout << "Direct print: ";
    copy(src.begin(), src.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";

    // Ex 4: Partial copy
    vector<int> partial(3);
    copy(src.begin(), src.begin() + 3, partial.begin());
    print("First 3 copied", partial);
}

// ============================================================
// 2. copy_n   [C++11]
//    Kya karta hai: Exactly N elements copy karta hai
// ============================================================
void demo_copy_n() {
    cout << "\n===== copy_n =====\n";

    vector<int> src = {10, 20, 30, 40, 50};
    vector<int> dst(3);

    // Ex 1: Pehle 3 copy karo
    copy_n(src.begin(), 3, dst.begin());
    print("copy_n (3 elements)", dst);

    // Ex 2: Middle se 2 copy karo
    vector<int> dst2(2);
    copy_n(src.begin() + 2, 2, dst2.begin());
    print("copy_n from index 2", dst2);
}

// ============================================================
// 3. copy_backward
//    Kya karta hai: End se start ki taraf copy karta hai
//    Use: Overlapping ranges mein safe copy ke liye
// ============================================================
void demo_copy_backward() {
    cout << "\n===== copy_backward =====\n";

    vector<int> v = {1, 2, 3, 4, 5};

    // Ex 1: Elements shift right karo (overlap safe)
    copy_backward(v.begin(), v.begin() + 4, v.begin() + 5);
    v[0] = 99;
    print("After copy_backward + shift", v);

    // Ex 2: Normal backward copy
    vector<int> src = {1, 2, 3};
    vector<int> dst(5, 0);
    copy_backward(src.begin(), src.end(), dst.end());
    print("copy_backward to end", dst);
}

// ============================================================
// 4. move / move_backward   [C++11]
//    Kya karta hai: Elements ko move karta hai (copy se fast, source empty ho sakta hai)
// ============================================================
void demo_move() {
    cout << "\n===== move / move_backward =====\n";

    vector<string> src = {"Hello", "World", "India"};
    vector<string> dst(3);

    // Ex 1: Strings move karo
    move(src.begin(), src.end(), dst.begin());
    cout << "After move, dst: ";
    for (auto& s : dst) cout << s << " ";
    cout << "\n";
    cout << "src after move (may be empty strings): ";
    for (auto& s : src) cout << "[" << s << "] ";
    cout << "\n";
}

// ============================================================
// 5. swap / iter_swap / swap_ranges
//    Kya karta hai: Elements swap karta hai
// ============================================================
void demo_swap() {
    cout << "\n===== swap / iter_swap / swap_ranges =====\n";

    // Ex 1: swap - do values swap karo
    int a = 5, b = 10;
    swap(a, b);
    cout << "After swap: a=" << a << ", b=" << b << "\n";

    // Ex 2: iter_swap - iterators ke through swap
    vector<int> v = {1, 2, 3, 4, 5};
    iter_swap(v.begin(), v.begin() + 4);
    print("After iter_swap(0,4)", v);

    // Ex 3: swap_ranges - do ranges ke elements swap karo
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {7, 8, 9};
    swap_ranges(v1.begin(), v1.end(), v2.begin());
    print("v1 after swap_ranges", v1);
    print("v2 after swap_ranges", v2);
}

// ============================================================
// 6. transform
//    Kya karta hai: Har element pe function apply karke result store karta hai
//    Return: Iterator to end of output
// ============================================================
void demo_transform() {
    cout << "\n===== transform =====\n";

    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> result(5);

    // Ex 1: Har element square karo
    transform(v.begin(), v.end(), result.begin(),
              [](int x){ return x * x; });
    print("Squares", result);

    // Ex 2: String uppercase
    string s = "hello world";
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << "Uppercase: " << s << "\n";

    // Ex 3: Do vectors add karo element-wise
    vector<int> a = {1, 2, 3};
    vector<int> b = {10, 20, 30};
    vector<int> sum(3);
    transform(a.begin(), a.end(), b.begin(), sum.begin(),
              [](int x, int y){ return x + y; });
    print("Element-wise sum", sum);

    // Ex 4: Celsius to Fahrenheit
    vector<double> celsius = {0, 100, 37, -40};
    vector<double> fahrenheit(celsius.size());
    transform(celsius.begin(), celsius.end(), fahrenheit.begin(),
              [](double c){ return c * 9.0/5.0 + 32; });
    cout << "Fahrenheit: ";
    for (double f : fahrenheit) cout << f << " ";
    cout << "\n";
}

// ============================================================
// 7. replace / replace_if
//    Kya karta hai: Elements ki value replace karta hai
// ============================================================
void demo_replace() {
    cout << "\n===== replace / replace_if =====\n";

    vector<int> v = {1, 2, 3, 2, 4, 2};

    // Ex 1: replace - specific value replace karo
    replace(v.begin(), v.end(), 2, 99);
    print("After replace 2→99", v);

    // Ex 2: replace_if - condition wale replace karo
    vector<int> v2 = {1, -2, 3, -4, 5};
    replace_if(v2.begin(), v2.end(), [](int x){ return x < 0; }, 0);
    print("After replace negatives with 0", v2);
}

// ============================================================
// 8. replace_copy / replace_copy_if
//    Kya karta hai: Original change kiye bina new range mein replace karke copy karta hai
// ============================================================
void demo_replace_copy() {
    cout << "\n===== replace_copy / replace_copy_if =====\n";

    vector<int> src = {1, 2, 3, 2, 5};
    vector<int> dst(5);

    // Ex 1: replace_copy - 2 ko 99 se replace karke copy karo
    replace_copy(src.begin(), src.end(), dst.begin(), 2, 99);
    print("Source (unchanged)", src);
    print("replace_copy result", dst);

    // Ex 2: replace_copy_if
    vector<int> dst2(5);
    replace_copy_if(src.begin(), src.end(), dst2.begin(),
                    [](int x){ return x % 2 == 0; }, -1);
    print("replace_copy_if (even→-1)", dst2);
}

// ============================================================
// 9. fill / fill_n
//    Kya karta hai: Range ko ek value se bharta hai
// ============================================================
void demo_fill() {
    cout << "\n===== fill / fill_n =====\n";

    vector<int> v(6, 0);

    // Ex 1: fill - poori range ko 7 se bharo
    fill(v.begin(), v.end(), 7);
    print("After fill(7)", v);

    // Ex 2: Partial fill
    fill(v.begin(), v.begin() + 3, 1);
    print("After partial fill(1)", v);

    // Ex 3: fill_n - N elements bharo
    fill_n(v.begin(), 4, 42);
    print("After fill_n(4, 42)", v);

    // Ex 4: String reset
    string s(10, '?');
    fill(s.begin(), s.end(), '*');
    cout << "Filled string: " << s << "\n";
}

// ============================================================
// 10. generate / generate_n
//     Kya karta hai: Generator function se values bharta hai
// ============================================================
void demo_generate() {
    cout << "\n===== generate / generate_n =====\n";

    vector<int> v(5);

    // Ex 1: Sequence 0,1,2,3,4 generate karo
    int counter = 0;
    generate(v.begin(), v.end(), [&counter](){ return counter++; });
    print("Generated sequence", v);

    // Ex 2: Random numbers
    mt19937 rng(42);
    generate(v.begin(), v.end(), [&rng](){ return rng() % 100; });
    print("Random numbers", v);

    // Ex 3: generate_n - sirf 3 generate karo
    int n = 1;
    generate_n(v.begin(), 3, [&n](){ return n *= 2; });
    print("Powers of 2 (first 3)", v);
}

// ============================================================
// 11. remove / remove_if
//     Kya karta hai: Elements "remove" karta hai - actually end ki taraf shift karta hai
//     IMPORTANT: Actual erase ke liye erase() bhi call karo → "erase-remove idiom"
//     Return: New logical end iterator
// ============================================================
void demo_remove() {
    cout << "\n===== remove / remove_if =====\n";

    vector<int> v = {1, 2, 3, 2, 4, 2, 5};
    print("Before remove", v);

    // Ex 1: remove + erase idiom (sahi tarika)
    auto newEnd = remove(v.begin(), v.end(), 2);
    v.erase(newEnd, v.end());  // ← zaroor karo!
    print("After remove(2) + erase", v);

    // Ex 2: remove_if - negative remove karo
    vector<int> v2 = {1, -2, 3, -4, 5, -6};
    auto it = remove_if(v2.begin(), v2.end(), [](int x){ return x < 0; });
    v2.erase(it, v2.end());
    print("After remove negatives", v2);

    // Ex 3: String se spaces hatao
    string s = "Hello World India";
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    cout << "Spaces removed: " << s << "\n";
}

// ============================================================
// 12. remove_copy / remove_copy_if
//     Kya karta hai: Original change kiye bina, elements skip karke copy karta hai
// ============================================================
void demo_remove_copy() {
    cout << "\n===== remove_copy / remove_copy_if =====\n";

    vector<int> src = {1, 2, 3, 2, 4, 2};
    vector<int> dst;

    // Ex 1: 2 skip karke copy karo
    remove_copy(src.begin(), src.end(), back_inserter(dst), 2);
    print("Source", src);
    print("remove_copy (skip 2)", dst);

    // Ex 2: Odd skip karke copy karo (sirf even chahiye)
    vector<int> evens;
    remove_copy_if(src.begin(), src.end(), back_inserter(evens),
                   [](int x){ return x % 2 != 0; });
    print("Only evens (remove_copy_if)", evens);
}

// ============================================================
// 13. unique / unique_copy
//     Kya karta hai: Consecutive duplicates hatata hai
//     NOTE: Pehle sort karo phir unique karo
// ============================================================
void demo_unique() {
    cout << "\n===== unique / unique_copy =====\n";

    vector<int> v = {1, 1, 2, 3, 3, 3, 4, 5, 5};

    // Ex 1: Consecutive duplicates hataao (erase-unique idiom)
    auto newEnd = unique(v.begin(), v.end());
    v.erase(newEnd, v.end());
    print("After unique", v);

    // Ex 2: Unsorted mein bhi kaam karta hai (sirf consecutive)
    vector<int> v2 = {1, 2, 1, 3, 2};  // pehle sort karo
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    print("Sort + unique", v2);

    // Ex 3: unique_copy - copy karte waqt unique
    vector<int> src = {1, 1, 2, 3, 3, 4};
    vector<int> dst;
    unique_copy(src.begin(), src.end(), back_inserter(dst));
    print("unique_copy result", dst);
}

// ============================================================
// 14. reverse / reverse_copy
//     Kya karta hai: Range ko ulta karta hai
// ============================================================
void demo_reverse() {
    cout << "\n===== reverse / reverse_copy =====\n";

    vector<int> v = {1, 2, 3, 4, 5};

    // Ex 1: In-place reverse
    reverse(v.begin(), v.end());
    print("After reverse", v);

    // Ex 2: Palindrome check
    string s = "madam";
    string rev = s;
    reverse(rev.begin(), rev.end());
    cout << "'" << s << "' is palindrome? " << (s == rev ? "Yes" : "No") << "\n";

    // Ex 3: reverse_copy - original theek rakho
    vector<int> src = {1, 2, 3};
    vector<int> dst(3);
    reverse_copy(src.begin(), src.end(), dst.begin());
    print("Source (unchanged)", src);
    print("reverse_copy result", dst);
}

// ============================================================
// 15. rotate / rotate_copy
//     Kya karta hai: Range ko rotate karta hai — ek element ko new beginning banata hai
// ============================================================
void demo_rotate() {
    cout << "\n===== rotate / rotate_copy =====\n";

    vector<int> v = {1, 2, 3, 4, 5};

    // Ex 1: 2 position left rotate
    rotate(v.begin(), v.begin() + 2, v.end());
    print("After rotate by 2", v);  // {3,4,5,1,2}

    // Ex 2: Right rotation (n-k position se rotate)
    vector<int> v2 = {1, 2, 3, 4, 5};
    int k = 2;  // right by 2
    rotate(v2.begin(), v2.begin() + (v2.size() - k), v2.end());
    print("Right rotate by 2", v2);  // {4,5,1,2,3}

    // Ex 3: rotate_copy
    vector<int> src = {1, 2, 3, 4, 5};
    vector<int> dst(5);
    rotate_copy(src.begin(), src.begin() + 1, src.end(), dst.begin());
    print("rotate_copy by 1", dst);
}

// ============================================================
// 16. shuffle   [C++11]
//     Kya karta hai: Range ko randomly shuffle karta hai
// ============================================================
void demo_shuffle() {
    cout << "\n===== shuffle =====\n";

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    print("Before shuffle", v);

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    shuffle(v.begin(), v.end(), rng);
    print("After shuffle", v);

    // Ex 2: Cards shuffle karna
    vector<string> cards = {"A", "K", "Q", "J", "10"};
    shuffle(cards.begin(), cards.end(), rng);
    cout << "Shuffled cards: ";
    for (auto& c : cards) cout << c << " ";
    cout << "\n";
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "===========================================\n";
    cout << "  STL MODIFYING ALGORITHMS - NOTES        \n";
    cout << "===========================================\n";

    demo_copy();
    demo_copy_n();
    demo_copy_backward();
    demo_move();
    demo_swap();
    demo_transform();
    demo_replace();
    demo_replace_copy();
    demo_fill();
    demo_generate();
    demo_remove();
    demo_remove_copy();
    demo_unique();
    demo_reverse();
    demo_rotate();
    demo_shuffle();

    cout << "\n===========================================\n";
    cout << "  KEY POINTS:\n";
    cout << "  remove()  → sirf shift karta hai, erase() bhi karo!\n";
    cout << "  unique()  → pehle sort() karo\n";
    cout << "  transform → do range version bhi hai\n";
    cout << "  shuffle   → mt19937 rng use karo (C++11)\n";
    cout << "===========================================\n";

    return 0;
}
