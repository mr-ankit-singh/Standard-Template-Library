/* ----------   Pairs  ---------- */
/*
    - A pair is a container that combine two elements of the same or different data types. 
    - The pair container defined under <utility> header file.

    - Syntax : pair<datatype1 , datatype2> pairName ;

    - Properties
      pair.first  => Access the first element
      pair.second => Access the second element
      pair.size() => Returns the number of elements in the pair (always 2)
      pair.empty() => Returns true if the pair is empty (always false)
      pair.swap(pair) => Swaps the contents of two pairs

    - Important Functions
      - std::pair()           : default constructor
      - std::tie()            : unpack a pair into multiple variables
      - std::get<index>(pair) : get the value of the pair at index 0 or 1
      - std::make_tuple()     : make a tuple from a pair
      - std::make_pair()      : make a pair from a tuple
      - std::swap()           : swap two pairs


*/

// Different ways to initionalize pairs
#include <utility>      // std::pair
#include <iostream>     // std::cout
using namespace std;

int main(){
    // Mtd : 1
    pair<int,char> p ;
    p.first = 0 ;
    p.second = '0' ;
    // Mtd : 2
    pair<int,int> p1(1,10);
    // Mtd : 3
    pair<int,int> p2 = {2,20};
    // Mtd : 4
    pair<int,int> p3 = make_pair(3,30);
    // Mtd : 5
    pair<int,int> p4(p3);

    // Array of pair
    pair<int,int> p5[10] ;

    return 0;
}

// Get element (tuple interface)
// Returns a reference to member first if I is 0, 
// or a reference to member second if I is 1.

// accessing pairs with get
#include <utility>      // std::pair, std::get
#include <iostream>     // std::cout

int main () {
  std::pair <int,char> foo (10,'x');

  std::get<0>(foo) = 50;

  std::cout << "foo contains: ";
  std::cout << std::get<0>(foo) << " and " << std::get<1>(foo) << '\n';

  return 0;
}


// pair::swap 
#include <utility>      // std::pair
#include <iostream>     // std::cout

int main () {
  std::pair<int,char> foo (10,'a');
  std::pair<int,char> bar (90,'z');

  foo.swap(bar);

  std::cout << "foo contains: " << foo.first;
  std::cout << " and " << foo.second << '\n';

  return 0;
}

// swap (pair overload)
#include <utility>      // std::pair
#include <iostream>     // std::cout

int main () {
  std::pair<int,char> foo (10,'a');
  std::pair<int,char> bar (90,'z');

  swap (foo,bar);

  std::cout << "foo contains: " << foo.first;
  std::cout << " and " << foo.second << '\n';

  return 0;
}

// Unpacking a Pair 🍁
// The tie() function is used to unpack a pair into multiple variables.
// The tie() function takes two references to variables and assigns the values of the pair to them.
#include <utility>      // std::pair, std::tie
#include <iostream>     // std::cout

int main () {
  std::pair<int,char> foo (10,'a');
  int x;
  char y;

  std::tie(x,y) = foo;

  std::cout << "foo contains: " << x;
  std::cout << " and " << y << '\n';

  return 0;
}