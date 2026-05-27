// ============================================================
//  STL ALGORITHMS - PART 6: NUMERIC ALGORITHMS
//  Header: #include <numeric>   ← ALAG HEADER HAI!
//  (kuch algorithms #include <algorithm> mein bhi hain)
// ============================================================

#include <iostream>
#include <numeric>    // ← numeric algorithms ke liye
#include <algorithm>
#include <vector>
#include <functional>
#include <random>
#include <string>
using namespace std;

void print(const string& label, const vector<int>& v) {
    cout << label << ": [ ";
    for (int x : v) cout << x << " ";
    cout << "]\n";
}
void printD(const string& label, const vector<double>& v) {
    cout << label << ": [ ";
    for (double x : v) cout << x << " ";
    cout << "]\n";
}

// ============================================================
// 1. accumulate
//    Kya karta hai: Range ke saare elements ko combine karta hai
//    Default: Sum nikalta hai
//    Return: Combined result
// ============================================================
void demo_accumulate() {
    cout << "\n===== accumulate =====\n";

    vector<int> v = {1, 2, 3, 4, 5};

    // Ex 1: Sum (default)
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum = " << sum << "\n";

    // Ex 2: Product (custom operation)
    int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());
    cout << "Product = " << product << "\n";  // 120

    // Ex 3: String join
    vector<string> words = {"Hello", "World", "from", "C++"};
    string joined = accumulate(words.begin(), words.end(), string(""),
                               [](const string& acc, const string& w){
                                   return acc.empty() ? w : acc + " " + w;
                               });
    cout << "Joined: " << joined << "\n";

    // Ex 4: Marks ka average
    vector<double> marks = {85.0, 92.0, 78.0, 88.0, 95.0};
    double avg = accumulate(marks.begin(), marks.end(), 0.0) / marks.size();
    cout << "Average marks = " << avg << "\n";
}

// ============================================================
// 2. iota   [C++11]
//    Kya karta hai: Sequence generate karta hai starting from value
//    Like: value, value+1, value+2, ...
// ============================================================
void demo_iota() {
    cout << "\n===== iota =====\n";

    // Ex 1: 1 to 5
    vector<int> v(5);
    iota(v.begin(), v.end(), 1);
    print("1 to 5", v);

    // Ex 2: 0 to 9
    vector<int> v2(10);
    iota(v2.begin(), v2.end(), 0);
    print("0 to 9", v2);

    // Ex 3: IDs generate karo
    vector<int> ids(5);
    iota(ids.begin(), ids.end(), 101);  // 101, 102, 103...
    print("IDs", ids);

    // Ex 4: iota + shuffle = random unique numbers
    vector<int> deck(52);
    iota(deck.begin(), deck.end(), 1);  // 1 to 52
    mt19937 rng(42);
    shuffle(deck.begin(), deck.end(), rng);
    cout << "First 5 cards from shuffled deck: ";
    for (int i = 0; i < 5; i++) cout << deck[i] << " ";
    cout << "\n";
}

// ============================================================
// 3. inner_product
//    Kya karta hai: Do ranges ka dot product nikalta hai
//    Default: sum(a[i] * b[i])
// ============================================================
void demo_inner_product() {
    cout << "\n===== inner_product =====\n";

    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};

    // Ex 1: Dot product (1*4 + 2*5 + 3*6 = 32)
    int dot = inner_product(a.begin(), a.end(), b.begin(), 0);
    cout << "Dot product = " << dot << "\n";

    // Ex 2: Custom operations
    // sum of max(a[i], b[i])
    int result = inner_product(a.begin(), a.end(), b.begin(), 0,
                                plus<int>(),          // combine results
                                [](int x, int y){ return max(x, y); });  // element-wise op
    cout << "Sum of max pairs = " << result << "\n";  // max(1,4)+max(2,5)+max(3,6) = 4+5+6=15

    // Ex 3: Weighted average
    vector<double> values = {80.0, 90.0, 70.0};
    vector<double> weights = {0.3, 0.5, 0.2};
    double weighted_sum = inner_product(values.begin(), values.end(), weights.begin(), 0.0);
    cout << "Weighted sum = " << weighted_sum << "\n";  // 80*.3 + 90*.5 + 70*.2
}

// ============================================================
// 4. partial_sum
//    Kya karta hai: Running sum/prefix sum calculate karta hai
//    a[0], a[0]+a[1], a[0]+a[1]+a[2], ...
// ============================================================
void demo_partial_sum() {
    cout << "\n===== partial_sum =====\n";

    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> result(5);

    // Ex 1: Prefix sum (running total)
    partial_sum(v.begin(), v.end(), result.begin());
    print("Input", v);
    print("Prefix sum", result);  // {1, 3, 6, 10, 15}

    // Ex 2: Running product
    vector<int> prod(5);
    partial_sum(v.begin(), v.end(), prod.begin(), multiplies<int>());
    print("Running product", prod);  // {1, 2, 6, 24, 120}

    // Ex 3: Practical - cumulative sales
    vector<int> monthly_sales = {100, 150, 200, 120, 180};
    vector<int> cumulative(5);
    partial_sum(monthly_sales.begin(), monthly_sales.end(), cumulative.begin());
    print("Monthly sales", monthly_sales);
    print("Cumulative sales", cumulative);

    // Ex 4: Frequency to cumulative frequency
    vector<int> freq = {5, 3, 8, 2, 7};
    vector<int> cum_freq(5);
    partial_sum(freq.begin(), freq.end(), cum_freq.begin());
    print("Frequency", freq);
    print("Cumulative freq", cum_freq);
}

// ============================================================
// 5. adjacent_difference
//    Kya karta hai: Consecutive elements ka difference nikalta hai
//    result[0] = a[0], result[i] = a[i] - a[i-1]
// ============================================================
void demo_adjacent_difference() {
    cout << "\n===== adjacent_difference =====\n";

    vector<int> v = {1, 3, 6, 10, 15};  // prefix sums
    vector<int> diff(5);

    // Ex 1: Differences (partial_sum ka reverse!)
    adjacent_difference(v.begin(), v.end(), diff.begin());
    print("Input (cumulative)", v);
    print("Differences", diff);  // {1, 2, 3, 4, 5}

    // Ex 2: Stock price changes
    vector<double> prices = {100.0, 105.0, 98.0, 110.0, 108.0};
    vector<double> changes(prices.size());
    adjacent_difference(prices.begin(), prices.end(), changes.begin());
    cout << "Price changes: ";
    for (double c : changes) cout << c << " ";
    cout << "\n";

    // Ex 3: Velocity from position (derivative)
    vector<int> position = {0, 2, 5, 9, 14};  // position at t=0,1,2,3,4
    vector<int> velocity(5);
    adjacent_difference(position.begin(), position.end(), velocity.begin());
    print("Position", position);
    print("Velocity (change per step)", velocity);

    // Ex 4: Custom operation - ratio
    vector<double> v2 = {2.0, 4.0, 8.0, 16.0};
    vector<double> ratios(4);
    adjacent_difference(v2.begin(), v2.end(), ratios.begin(),
                        [](double curr, double prev){ return curr / prev; });
    ratios[0] = v2[0];  // first element same rehta hai
    printD("Ratios (geometric)", ratios);
}

// ============================================================
// 6. reduce   [C++17]
//    Kya karta hai: accumulate jaisa lekin PARALLEL execution support karta hai
//    NOTE: Order guaranteed nahi (non-deterministic)
// ============================================================
void demo_reduce() {
    cout << "\n===== reduce (C++17) =====\n";

    vector<int> v = {1, 2, 3, 4, 5};

    // Ex 1: Default sum
    int sum = reduce(v.begin(), v.end());
    cout << "Sum (reduce) = " << sum << "\n";

    // Ex 2: With initial value
    int sum2 = reduce(v.begin(), v.end(), 100);
    cout << "Sum + 100 = " << sum2 << "\n";

    // Ex 3: Product
    int prod = reduce(v.begin(), v.end(), 1, multiplies<int>());
    cout << "Product = " << prod << "\n";

    // NOTE: accumulate vs reduce
    // accumulate → sequential, order guaranteed
    // reduce     → can be parallel, use when order doesn't matter
}

// ============================================================
// 7. transform_reduce   [C++17]
//    Kya karta hai: Transform karo phir reduce karo (map-reduce!)
// ============================================================
void demo_transform_reduce() {
    cout << "\n===== transform_reduce (C++17) =====\n";

    vector<int> v = {1, 2, 3, 4, 5};

    // Ex 1: Sum of squares
    int sumSq = transform_reduce(v.begin(), v.end(), 0,
                                  plus<int>(),
                                  [](int x){ return x * x; });
    cout << "Sum of squares = " << sumSq << "\n";  // 1+4+9+16+25=55

    // Ex 2: Dot product (two-range version)
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6};
    int dot = transform_reduce(a.begin(), a.end(), b.begin(), 0);
    cout << "Dot product = " << dot << "\n";  // 1*4+2*5+3*6=32

    // Ex 3: Count words total in sentences
    vector<string> sentences = {"Hello World", "C++ is great", "STL rocks"};
    int total_words = transform_reduce(sentences.begin(), sentences.end(), 0,
                                       plus<int>(),
                                       [](const string& s){
                                           return count(s.begin(), s.end(), ' ') + 1;
                                       });
    cout << "Total words = " << total_words << "\n";
}

// ============================================================
// 8. inclusive_scan / exclusive_scan   [C++17]
//    Kya karta hai: partial_sum jaisa lekin parallel execution support
//    inclusive_scan: result[i] includes a[i]
//    exclusive_scan: result[i] excludes a[i] (shifted by 1)
// ============================================================
void demo_scan() {
    cout << "\n===== inclusive_scan / exclusive_scan (C++17) =====\n";

    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> inc(5), exc(5);

    // Ex 1: inclusive_scan - partial_sum jaisa
    inclusive_scan(v.begin(), v.end(), inc.begin());
    print("Input", v);
    print("inclusive_scan", inc);  // {1, 3, 6, 10, 15}

    // Ex 2: exclusive_scan - initial value se shuru (default 0)
    exclusive_scan(v.begin(), v.end(), exc.begin(), 0);
    print("exclusive_scan (init=0)", exc);  // {0, 1, 3, 6, 10}

    // NOTE:
    // inclusive_scan[i] = v[0] + v[1] + ... + v[i]
    // exclusive_scan[i] = v[0] + v[1] + ... + v[i-1]  (v[i] EXCLUDE hai)
}

// ============================================================
//  MAIN
// ============================================================
int main() {
    cout << "===========================================\n";
    cout << "  STL NUMERIC ALGORITHMS - NOTES          \n";
    cout << "  Header: #include <numeric>              \n";
    cout << "===========================================\n";

    demo_accumulate();
    demo_iota();
    demo_inner_product();
    demo_partial_sum();
    demo_adjacent_difference();
    demo_reduce();
    demo_transform_reduce();
    demo_scan();

    cout << "\n===========================================\n";
    cout << "  NUMERIC CHEATSHEET:\n";
    cout << "  accumulate     → sum/fold (#include <numeric>)\n";
    cout << "  iota           → 0,1,2,3... sequence\n";
    cout << "  inner_product  → dot product\n";
    cout << "  partial_sum    → prefix/running sum\n";
    cout << "  adj_difference → consecutive differences\n";
    cout << "  reduce         → parallel-friendly accumulate\n";
    cout << "  transform_reduce → map then reduce\n";
    cout << "  inclusive_scan → parallel partial_sum\n";
    cout << "  exclusive_scan → shifted partial_sum\n";
    cout << "\n  IMPORTANT: partial_sum + adj_difference\n";
    cout << "  are INVERSES of each other!\n";
    cout << "===========================================\n";

    return 0;
}
