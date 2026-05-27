/*

TOPIC: std::array

    Syntax:   array<object_type, arr_size> arr_name;
    
    In order to utilize arrays, we need to include the array header: 
        #include <array> 

    NOTES:
    1. std::array is a container that encapsulates fixed size arrays.
    2. arraysize is needed at compile time.
    3. Assign by value is actually by value.
    4. Zero-sized arrays are valid, but they should not be dereferenced.

    5. Access Elements:
        a. at()      -> access specified element with bounds checking.
        b. []        -> access specified element.
        c. front()   -> access the first element.
        d. back()    -> access the last element.
        e. data()    -> gives access to the underlying array.

    6. Capacity
        a. empty()   -> checks whether the container is empty.
        b. size()    -> returns the number of elements.
        c. max_size  -> returns the maximum possible number of elements.

    7. Operators
        a. fill()    -> fill the container with specified value.
        b. swap()    -> swaps the contents.
        c. sort()    -> sort value in ascending order.

    8. Iterators
       a. begin()    -> returns an iterator to the beginning.
          cbegin()
       b. end()      -> returns an iterator to the end.
          cend()
       c. rbegin()   -> returns a reverse iterator to the beginning.
          crbegin()
       d. rend()     -> returns a reverse iterator to the end.
          crend()

    ============================================================
    QUICK COMPARISON TABLE
    ============================================================
    METHOD                             | = SIGN | VALUES AT DECLARE | STYLE
    -----------------------------------|--------|-------------------|--------
    array<int,5> a;                    |   No   |       No (garbage)| declare only
    array<int,5> a = {1,2,3,4,5};      |  Yes   |       Yes         | initializer list
    array<int,5> a {1,2,3,4,5};        |   No   |       Yes         | uniform init (modern)
    array<int,5> a; a = {1,2,3,4,5};   |  Yes   |  No, then assign  | two-step assignment
*/

#include<iostream>
#include<array>
using namespace std;
int main(){
    // Declare
    std::array<int, 5> myarray;
    // Initilization
    std::array<int, 5> myarray = {1, 2, 3, 4, 5}; // initilizer list
    std::array<int, 5> myarray2 {1, 2, 3, 4, 5};  // uniform initilization
    // Assign using initilizer list
    std::array<int, 5> myarray;
    myarray = {1, 2, 3, 4, 5};
    return 0;
}


/*
================================================================================
        C++ std::array — All Methods
        Format: Topic | Syntax | Definition | Imp Points | Example
================================================================================
*/

#include <iostream>
#include <array>
#include <algorithm>   // sort(), reverse()
using namespace std;


// ============================================================
// 1. at()
// ============================================================
/*
  SYNTAX:
      array.at(index);

  DEFINITION:
      Kisi bhi element ko uske index number se access karta hai.
      myarray.at(i) aur myarray[i] dono same kaam karte hain,
      lekin at() bounds checking karta hai.

  IMP POINTS:
      - Index 0 se shuru hota hai — pehla element at(0) hai
      - at() aur array[i] dono same output dete hain
      - at() bounds check karta hai — invalid index pe error milega
      - Loop ke saath milake use karna best practice hai
*/

void demo_at() {
    cout << "\n===== at() =====\n";

    array<int, 5> myarray;

    for (int i = 0; i < (int)myarray.size(); i++) {
        cout << "Enter value of myarray[" << i + 1 << "]: ";
        cin >> myarray.at(i);
    }

    for (int j = 0; j < (int)myarray.size(); j++) {
        cout << "myarray[" << j + 1 << "] = " << myarray.at(j) << "\n";
    }
}


// ============================================================
// 2. front() | back()
// ============================================================
/*
  SYNTAX:
      array.front();    // pehla element
      array.back();     // aakhri element

  DEFINITION:
      front() array ka pehla element return karta hai,
      back() array ka aakhri element return karta hai —
      bina index number likhe.

  IMP POINTS:
      - front() = array[0]
      - back()  = array[n-1]
      - Dono O(1) operations hain — bahut fast
      - Empty array pe call karne se undefined behavior hota hai
*/

void demo_front_back() {
    cout << "\n===== front() | back() =====\n";

    array<double, 4> arr = {5.6, 4.5, 4.7, 4.5};
    cout << "front(): " << arr.front() << "\n";   // 5.6

    array<char, 6> ch = {'a', 'b', 'c', 'd', 'e', 'f'};
    cout << "back() : " << ch.back()  << "\n";    // f
}


// ============================================================
// 3. empty()
// ============================================================
/*
  SYNTAX:
      array.empty();

  DEFINITION:
      Check karta hai ki array khali hai ya nahi.
      Size 0 ho to 1 (true) return karta hai,
      warna 0 (false) return karta hai.

  IMP POINTS:
      - Return type: bool — 1 (empty) ya 0 (not empty)
      - std::array ka size compile time pe fix hota hai
      - if(arr.empty()) condition mein use karna common hai
      - std::vector ke saath bhi same syntax kaam karta hai
*/

void demo_empty() {
    cout << "\n===== empty() =====\n";

    array<int, 2> a1 = {1, 2};
    array<int, 0> a2;

    cout << "a1.empty(): " << a1.empty() << "\n";   // 0 (not empty)
    cout << "a2.empty(): " << a2.empty() << "\n";   // 1 (empty)
}


// ============================================================
// 4. max_size()
// ============================================================
/*
  SYNTAX:
      array.max_size();

  DEFINITION:
      Batata hai ki array mein maximum kitne elements aa sakte hain.
      std::array mein yeh hamesha size() ke barabar hoti hai
      kyunki size compile time pe fixed hoti hai.

  IMP POINTS:
      - std::array ke liye: max_size() == size() hamesha
      - std::vector ke liye yeh alag hota hai
      - Return type: size_t (unsigned integer)
      - Generic/portable code mein useful hai
*/

void demo_max_size() {
    cout << "\n===== max_size() =====\n";

    array<int, 8> arr;
    cout << "max_size(): " << arr.max_size() << "\n";   // 8
}


// ============================================================
// 5. fill()
// ============================================================
/*
  SYNTAX:
      array.fill(value);

  DEFINITION:
      Array ke SAARE elements ko ek hi given value se bhar deta hai.
      Ek baar mein poora array set ho jata hai.

  IMP POINTS:
      - Poore array ko ek value se initialize karna ho to fill() use karo
      - Pehle se existing values overwrite ho jaati hain
      - O(n) time complexity
      - 0 ya -1 se initialize karna bahut common use case hai
*/

void demo_fill() {
    cout << "\n===== fill() =====\n";

    array<int, 4> arr = {1, 2, 3, 4};
    arr.fill(2);

    for (int i = 0; i < (int)arr.size(); i++) {
        cout << "arr[" << i << "] = " << arr[i] << "\n";   // sab 2
    }
}


// ============================================================
// 6. swap()
// ============================================================
/*
  SYNTAX:
      a1.swap(a2);    // method form
      swap(a1, a2);   // function form

  DEFINITION:
      Do arrays ke saare elements aapas mein exchange ho jaate hain.
      Dono arrays ka type aur size same hona chahiye.

  IMP POINTS:
      - Dono tarike kaam karte hain: a1.swap(a2) aur swap(a1, a2)
      - Type aur size bilkul same hone chahiye dono arrays ke
      - O(n) time — har element ek-ek karke swap hota hai
      - Koi extra memory (temp array) nahi lagti
*/

void demo_swap() {
    cout << "\n===== swap() =====\n";

    array<int, 4> a1 = {1, 2, 3, 4};
    array<int, 4> a2 = {5, 6, 7, 8};

    swap(a1, a2);

    cout << "Elements of a1: ";
    for (int j = 0; j < (int)a1.size(); j++) cout << a1[j] << " ";
    cout << "\n";   // 5 6 7 8

    cout << "Elements of a2: ";
    for (int j = 0; j < (int)a2.size(); j++) cout << a2[j] << " ";
    cout << "\n";   // 1 2 3 4
}


// ============================================================
// 7. sort()
// ============================================================
/*
  SYNTAX:
      sort(array.begin(), array.end());

  DEFINITION:
      Array ke elements ko ascending order (chhote se bade) mein
      sort karta hai. Yeh <algorithm> header mein hota hai.

  IMP POINTS:
      - #include <algorithm> header zaroori hai
      - begin() aur end() iterators dene hote hain
      - Descending ke liye: sort(a.begin(), a.end(), greater<int>())
      - Average time complexity: O(n log n)
*/

void demo_sort() {
    cout << "\n===== sort() =====\n";

    array<int, 4> a = {47, 23, 90, 1};

    sort(a.begin(), a.end());

    cout << "Ascending : ";
    for (auto i = a.begin(); i != a.end(); ++i) cout << *i << " ";
    cout << "\n";   // 1 23 47 90

    sort(a.begin(), a.end(), greater<int>());

    cout << "Descending: ";
    for (auto i = a.begin(); i != a.end(); ++i) cout << *i << " ";
    cout << "\n";   // 90 47 23 1
}


// ============================================================
// 8. reverse()
// ============================================================
/*
  SYNTAX:
      reverse(array.begin(), array.end());

  DEFINITION:
      Array ke elements ka order ulta (reverse) kar deta hai.
      Yeh bhi <algorithm> header mein hota hai.

  IMP POINTS:
      - #include <algorithm> header zaroori hai
      - In-place reverse — naya array nahi banta
      - O(n/2) swaps hote hain internally
      - sort() ke baad reverse() = descending order
*/

void demo_reverse() {
    cout << "\n===== reverse() =====\n";

    array<int, 4> a = {47, 23, 90, 1};

    reverse(a.begin(), a.end());

    cout << "Reversed: ";
    for (auto i = a.begin(); i != a.end(); ++i) cout << *i << " ";
    cout << "\n";   // 1 90 23 47
}


// ============================================================
// 9. Multidimensional Array
// ============================================================
/*
  SYNTAX:
      std::array<std::array<int, cols>, rows> a;

  DEFINITION:
      Array ke andar array — 2D grid banane ke liye use hota hai.
      Outer array rows ko represent karta hai,
      inner array columns ko.

  IMP POINTS:
      - Syntax: array<array<int, cols>, rows>
      - Access: a[row][col] format se
      - Nested loop se traverse — outer=rows, inner=cols
      - Memory mein row-major order mein store hota hai
*/

void demo_multidimensional() {
    cout << "\n===== Multidimensional Array =====\n";

    array<array<int, 3>, 3> a = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }
    // Output:
    // 1   2   3
    // 4   5   6
    // 7   8   9
}


// ============================================================
// MAIN — sab demos ek saath chalao
// ============================================================

int main() {
    // demo_at();          // user input maangta hai, uncomment karke test karo

    demo_front_back();
    demo_empty();
    demo_max_size();
    demo_fill();
    demo_swap();
    demo_sort();
    demo_reverse();
    demo_multidimensional();

    return 0;
}

/*
  COMPILE & RUN:
      g++ array_methods.cpp -o array_methods
      ./array_methods
*/