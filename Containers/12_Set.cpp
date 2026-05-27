/*
#__ std::set in STL __#

    - A set is a collection of unique elements.
    - It is implemented as a balanced binary search tree.
    - Elements are stored in a sorted order.
    - Duplicate elements are not allowed.
    - The set is typically implemented as a red-black tree.

    - Syntax:
        std::set<type> set_name; // Default set
        std::set<type, comparator> set_name; // Custom comparator for ordering
        std::set<type, allocator> set_name; // Custom allocator for memory management

    - Member Functions:
        insert(value)            : Inserts an element into the set.
        insert_range(start, end) : Inserts a range of elements into the set.
        erase(value)             : Removes an element from the set.
        find(value)              : Returns an iterator to the element if found, otherwise returns end().
        contains(value)          : Returns true if the set contains the value, false otherwise.
        count(value)             : Returns the number of occurrences of the value in the set (0 or 1).
        empty()                  : Returns true if the set is empty, false otherwise.
        size()                   : Returns the number of elements in the set.
        clear()                  : Removes all elements from the set.
        swap(other_set)          : Exchanges the contents of this set with another set of the same type.
        extract(value)           : Removes and returns the element from the set.
        merge(other_set)         : Merges another set into this set.
        equal_range(value)       : Returns a pair of iterators representing the range of elements equal to the value.
        lower_bound(value)       : Returns an iterator to the first element not less than the value.
        upper_bound(value)       : Returns an iterator to the first element greater than the value.
        swap(other_set)          : Exchanges the contents of this set with another set of the same type.
        emplace(value)           : Constructs an element in place in the set.
        emplace_hint(position, value) : Constructs an element in place at the specified position.

*/


// insert() 🍁
// Syntax: set_name.insert(value);
// Description: Inserts an element into the set.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(10); // Inserts 10 into the set
    s.insert(20); // Inserts 20 into the set
    std::cout << "Set contains: ";
    for (const auto& elem : s) {
        std::cout << elem << " "; // Output: 10 20
    }
    std::cout << "\n";
}
// Output: Set contains: 10 20


// insert_range() 🍁
// Syntax: set_name.insert_range(start, end);
// Description: Inserts a range of elements into the set.
#include <iostream>
#include <set>
#include <vector>
int main() {
    std::set<int> s;
    std::vector<int> vec = {30, 40, 50};
    s.insert_range(vec.begin(), vec.end()); // Inserts elements from the vector into the set
    std::cout << "Set contains: ";
    for (const auto& elem : s) {
        std::cout << elem << " "; // Output: 30 40 50
    }
    std::cout << "\n";
}
// Output: Set contains: 30 40 50


// erase() 🍁
// Syntax: set_name.erase(value);
// Description: Removes an element from the set.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(10); // Inserts 10 into the set
    s.insert(20); // Inserts 20 into the set
    s.erase(10);  // Removes 10 from the set
    std::cout << "Set contains: ";
    for (const auto& elem : s) {
        std::cout << elem << " "; // Output: 20
    }
    std::cout << "\n";
}
// Output: Set contains: 20



// find() 🍁
// Syntax: set_name.find(value);
// Description: Returns an iterator to the element if found, otherwise returns end().
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(10); // Inserts 10 into the set
    s.insert(20); // Inserts 20 into the set
    auto it = s.find(10); // Finds 10 in the set
    if (it != s.end()) {
        std::cout << "Found: " << *it << "\n"; // Output: Found: 10
    } else {
        std::cout << "Not found\n";
    }
}
// Output: Found: 10



// contains() 🍁
// Syntax: set_name.contains(value);
// Description: Returns true if the set contains the value, false otherwise.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(10); // Inserts 10 into the set
    s.insert(20); // Inserts 20 into the set
    if (s.contains(10)) {
        std::cout << "Set contains 10\n"; 
    } else {
        std::cout << "Set does not contain 10\n";
    }
}
// Output: Set contains 10



// count() 🍁
// Syntax: set_name.count(value);
// Description: Returns the number of occurrences of the value in the set (0 or 1).
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(10); // Inserts 10 into the set
    s.insert(20); // Inserts 20 into the set
    s.insert(30); // Inserts 30 into the set
    s.insert(30); // Inserts 30 again (duplicate, ignored)
    s.insert(40); // Inserts 40 into the set
    std::cout << "Count of 10: " << s.count(10) << "\n"; // Output: 1
    std::cout << "Count of 30: " << s.count(30) << "\n"; // Output: 1
}
// Output: Count of 10: 1 Count of 30: 1



// empty() 🍁
// Syntax: set_name.empty();
// Description: Returns true if the set is empty, false otherwise.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    if (s.empty()) {
        std::cout << "Set is empty\n"; // Output: Set is empty
    } else {
        std::cout << "Set is not empty\n";
    }
    s.insert(10); // Inserts 10 into the set
    if (s.empty()) {
        std::cout << "Set is empty\n";
    } else {
        std::cout << "Set is not empty\n"; // Output: Set is not empty
    }
}
// Output: Set is empty Set is not empty



// size() 🍁
// Syntax: set_name.size();
// Description: Returns the number of elements in the set.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(10); // Inserts 10 into the set
    s.insert(20); // Inserts 20 into the set
    std::cout << "Size of set: " << s.size() << "\n"; // Output: 2
}
// Output: Size of set: 2



// clear() 🍁
// Syntax: set_name.clear();
// Description: Removes all elements from the set.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(10); // Inserts 10 into the set
    s.insert(20); // Inserts 20 into the set
    s.clear();    // Removes all elements from the set
    std::cout << "Size after clear: " << s.size() << "\n"; // Output: 0
}
// Output: Size after clear: 0



// swap() 🍁
// Syntax: set_name.swap(other_set);
// Description: Exchanges the contents of this set with another set of the same type.
#include <iostream>
#include <set>
int main() {
    std::set<int> s1, s2;
    s1.insert(10); // Inserts 10 into s1
    s2.insert(20); // Inserts 20 into s2
    s1.swap(s2);   // Swaps contents of s1 and s2
    std::cout << "Set 1 contains: ";
    for (const auto& elem : s1) {
        std::cout << elem << " "; // Output: 20
    }
    std::cout << "\nSet 2 contains: ";
    for (const auto& elem : s2) {
        std::cout << elem << " "; // Output: 10
    }
    std::cout << "\n";
}
// Output: Set 1 contains: 20 Set 2 contains: 10



// extract() 🍁
// Syntax: set_name.extract(value);
// Description: Removes and returns the element from the set.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(10); // Inserts 10 into the set
    s.insert(20); // Inserts 20 into the set
    auto node = s.extract(10); // Extracts 10 from the set
    std::cout << "Extracted: " << node.value() << "\n"; // Output: Extracted: 10
    std::cout << "Set contains: ";
    for (const auto& elem : s) {
        std::cout << elem << " "; // Output: 20
    }
    std::cout << "\n";
}
// Output: Extracted: 10 Set contains: 20
// Output: Set contains: 20



// merge() 🍁
// Syntax: set_name.merge(other_set);
// Description: Merges another set into this set.
#include <iostream>
#include <set>
int main() {
    std::set<int> s1, s2;
    s1.insert(10); // Inserts 10 into s1
    s2.insert(20); // Inserts 20 into s2
    s1.merge(s2);   // Merges s2 into s1
    std::cout << "Set contains: ";
    for (const auto& elem : s1) {
        std::cout << elem << " "; // Output: 10 20
    }
    std::cout << "\n";
}
// Output: Set contains: 10 20



// equal_range() 🍁
// Syntax: set_name.equal_range(value);
// Description: Returns a pair of iterators representing the range of elements equal to the value.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(10); // Inserts 10 into the set
    s.insert(20); // Inserts 20 into the set
    auto range = s.equal_range(10); // Gets the range of elements equal to 10
    std::cout << "Range: " << *range.first << " to " << *range.second << "\n"; // Output: 10 to 10
}
// Output: Range: 10 to 10



// lower_bound() 🍁
// Syntax: set_name.lower_bound(value);
// Description: Returns an iterator to the first element not less than the value.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(10); // Inserts 10 into the set
    s.insert(20); // Inserts 20 into the set
    auto it = s.lower_bound(15); // Gets the first element not less than 15
    std::cout << "Lower bound: " << *it << "\n"; // Output: 20
}
// Output: Lower bound: 20




// upper_bound() 🍁
// Syntax: set_name.upper_bound(value);
// Description: Returns an iterator to the first element greater than the value.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.insert(10); // Inserts 10 into the set
    s.insert(20); // Inserts 20 into the set
    auto it = s.upper_bound(15); // Gets the first element greater than 15
    std::cout << "Upper bound: " << *it << "\n"; // Output: 20
}
// Output: Upper bound: 20



// emplace() 🍁
// Syntax: set_name.emplace(value);
// Description: Constructs an element in place in the set.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    s.emplace(10); // Constructs 10 in place in the set
    s.emplace(20); // Constructs 20 in place in the set
    std::cout << "Set contains: ";
    for (const auto& elem : s) {
        std::cout << elem << " "; // Output: 10 20
    }
    std::cout << "\n";
}
// Output: Set contains: 10 20



// emplace_hint() 🍁
// Syntax: set_name.emplace_hint(position, value);
// Description: Constructs an element in place at the specified position.
#include <iostream>
#include <set>
int main() {
    std::set<int> s;
    auto it = s.emplace_hint(s.end(), 10); // Constructs 10 in place at the end of the set
    std::cout << "Inserted: " << *it << "\n"; // Output: Inserted: 10
    s.emplace_hint(it, 20); // Constructs 20 in place before the iterator
    std::cout << "Set contains: ";
    for (const auto& elem : s) {
        std::cout << elem << " "; // Output: 10 20
    }
    std::cout << "\n";
}
// Output: Inserted: 10 Set contains: 10 20
// Output: Set contains: 10 20












