/*
#__ std::map in STL __#

    - A map is a collection of key-value pairs, where each key is unique.
    - It is implemented as a balanced binary search tree.
    - The keys are stored in a sorted order.
    - The map is typically implemented as a red-black tree.

    - Syntax:
        std::map<key_type, value_type> map_name; // Default map
        std::map<key_type, value_type, comparator> map_name; // Custom comparator for ordering
        std::map<key_type, value_type, allocator> map_name; // Custom allocator for memory management

    - Member Functions:
        insert({key, value})            : Inserts a key-value pair into the map.
        insert_range(start, end)        : Inserts a range of key-value pairs into the map.
        erase(key)                      : Removes the key-value pair with the specified key from the map.
        find(key)                       : Returns an iterator to the key-value pair if found, otherwise returns end().
        contains(key)                   : Returns true if the map contains the key, false otherwise.
        count(key)                      : Returns the number of occurrences of the key in the map (0 or 1).
        empty()                         : Returns true if the map is empty, false otherwise.
        size()                          : Returns the number of elements in the map.
        clear()                         : Removes all elements from the map.
        swap(other_map)                 : Exchanges the contents of this map with another map of the same type.
        equal_range(key)                : Returns a pair of iterators representing the range of elements equal to the key.
        lower_bound(key)                : Returns an iterator to the first element not less than the key.
        upper_bound(key)                : Returns an iterator to the first element greater than the key.
        swap(other_map)                 : Exchanges the contents of this map with another map of the same type.
        emplace({key, value})           : Constructs a key-value pair in place in the map.
        emplace_hint(position, {key, value}) : Constructs a key-value pair in place at the specified position.

*/


// insert() 🍁
// Syntax: map_name.insert({key, value});
// Description: Inserts a key-value pair into the map.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    m.insert({1, "One"}); // Inserts key-value pair (1, "One")
    m.insert({2, "Two"}); // Inserts key-value pair (2, "Two")
    std::cout << "Map contains:\n";
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << "\n"; // Output: 1: One 2: Two
    }
}
// Output: Map contains: 1: One 2: Two



// insert_range() 🍁
// Syntax: map_name.insert_range(start, end);
// Description: Inserts a range of key-value pairs into the map.
#include <iostream>
#include <map>
#include <vector>
#include <string>
int main() {
    std::map<int, std::string> m;
    std::vector<std::pair<int, std::string>> vec = {{3, "Three"}, {4, "Four"}};
    m.insert_range(vec.begin(), vec.end()); // Inserts range of key-value pairs
    std::cout << "Map contains:\n";
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << "\n"; // Output: 3: Three 4: Four
    }
}
// Output: Map contains: 3: Three 4: Four



// erase() 🍁
// Syntax: map_name.erase(key);
// Description: Removes the key-value pair with the specified key from the map.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    m.insert({1, "One"}); // Inserts key-value pair (1, "One")
    m.insert({2, "Two"}); // Inserts key-value pair (2, "Two")
    m.erase(1); // Removes key-value pair with key 1
    std::cout << "Map contains:\n";
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << "\n"; // Output: 2: Two
    }
}
// Output: Map contains: 2: Two




// find() 🍁
// Syntax: map_name.find(key);
// Description: Returns an iterator to the key-value pair if found, otherwise returns end().
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    m.insert({1, "One"}); // Inserts key-value pair (1, "One")
    m.insert({2, "Two"}); // Inserts key-value pair (2, "Two")
    auto it = m.find(1); // Finds key 1
    if (it != m.end()) {
        std::cout << "Found: " << it->first << ": " << it->second << "\n"; // Output: Found: 1: One
    } else {
        std::cout << "Not found\n";
    }
}
// Output: Found: 1: One



// contains() 🍁
// Syntax: map_name.contains(key);
// Description: Returns true if the map contains the key, false otherwise.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    m.insert({1, "One"}); // Inserts key-value pair (1, "One")
    m.insert({2, "Two"}); // Inserts key-value pair (2, "Two")
    if (m.contains(1)) {
        std::cout << "Map contains key 1\n"; // Output: Map contains key 1
    } else {
        std::cout << "Map does not contain key 1\n";
    }
}
// Output: Map contains key 1



// count() 🍁
// Syntax: map_name.count(key);
// Description: Returns the number of occurrences of the key in the map (0 or 1).
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    m.insert({1, "One"}); // Inserts key-value pair (1, "One")
    m.insert({2, "Two"}); // Inserts key-value pair (2, "Two")
    std::cout << "Count of key 1: " << m.count(1) << "\n"; // Output: 1
    std::cout << "Count of key 3: " << m.count(3) << "\n"; // Output: 0
}
// Output: Count of key 1: 1 Count of key 3: 0



// empty() 🍁
// Syntax: map_name.empty();
// Description: Returns true if the map is empty, false otherwise.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    if (m.empty()) {
        std::cout << "Map is empty\n"; // Output: Map is empty
    } else {
        std::cout << "Map is not empty\n";
    }
    m.insert({1, "One"}); // Inserts key-value pair (1, "One")
    if (m.empty()) {
        std::cout << "Map is empty\n";
    } else {
        std::cout << "Map is not empty\n"; // Output: Map is not empty
    }
}
// Output: Map is empty Map is not empty



// size() 🍁
// Syntax: map_name.size();
// Description: Returns the number of elements in the map.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    m.insert({1, "One"}); // Inserts key-value pair (1, "One")
    m.insert({2, "Two"}); // Inserts key-value pair (2, "Two")
    std::cout << "Size of map: " << m.size() << "\n"; // Output: 2
}
// Output: Size of map: 2



// clear() 🍁
// Syntax: map_name.clear();
// Description: Removes all elements from the map.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    m.insert({1, "One"}); // Inserts key-value pair (1, "One")
    m.insert({2, "Two"}); // Inserts key-value pair (2, "Two")
    m.clear(); // Removes all elements from the map
    std::cout << "Size after clear: " << m.size() << "\n"; // Output: 0
}
// Output: Size after clear: 0



// swap() 🍁
// Syntax: map_name.swap(other_map);
// Description: Exchanges the contents of this map with another map of the same type.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m1, m2;
    m1.insert({1, "One"}); // Inserts key-value pair (1, "One") into m1
    m2.insert({2, "Two"}); // Inserts key-value pair (2, "Two") into m2
    m1.swap(m2); // Swaps contents of m1 and m2
    std::cout << "Map 1 contains:\n";
    for (const auto& pair : m1) {
        std::cout << pair.first << ": " << pair.second << "\n"; // Output: 2: Two
    }
    std::cout << "Map 2 contains:\n";
    for (const auto& pair : m2) {
        std::cout << pair.first << ": " << pair.second << "\n"; // Output: 1: One
    }
}
// Output: Map 1 contains: 2: Two Map 2 contains: 1: One



// equal_range() 🍁
// Syntax: map_name.equal_range(key);
// Description: Returns a pair of iterators representing the range of elements equal to the key.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    m.insert({1, "One"}); // Inserts key-value pair (1, "One")
    m.insert({2, "Two"}); // Inserts key-value pair (2, "Two")
    auto range = m.equal_range(1); // Gets the range of elements equal to key 1
    std::cout << "Range: " << range.first->first << ": " << range.first->second << " to "
              << range.second->first << ": " << range.second->second << "\n"; // Output: 1: One to 2: Two
}
// Output: Range: 1: One to 2: Two



// lower_bound() 🍁
// Syntax: map_name.lower_bound(key);
// Description: Returns an iterator to the first element not less than the key.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    m.insert({1, "One"}); // Inserts key-value pair (1, "One")
    m.insert({2, "Two"}); // Inserts key-value pair (2, "Two")
    auto it = m.lower_bound(2); // Gets the first element not less than key 2
    if (it != m.end()) {
        std::cout << "Lower bound: " << it->first << ": " << it->second << "\n"; // Output: 2: Two
    } else {
        std::cout << "Not found\n";
    }
}
// Output: Lower bound: 2: Two



// upper_bound() 🍁
// Syntax: map_name.upper_bound(key);
// Description: Returns an iterator to the first element greater than the key.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    m.insert({1, "One"}); // Inserts key-value pair (1, "One")
    m.insert({2, "Two"}); // Inserts key-value pair (2, "Two")
    auto it = m.upper_bound(1); // Gets the first element greater than key 1
    if (it != m.end()) {
        std::cout << "Upper bound: " << it->first << ": " << it->second << "\n"; // Output: 2: Two
    } else {
        std::cout << "Not found\n";
    }
}
// Output: Upper bound: 2: Two



// emplace() 🍁
// Syntax: map_name.emplace({key, value});
// Description: Constructs a key-value pair in place in the map.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    m.emplace(1, "One"); // Constructs key-value pair (1, "One") in place
    m.emplace(2, "Two"); // Constructs key-value pair (2, "Two") in place
    std::cout << "Map contains:\n";
    for (const auto& pair : m) {
        std::cout << pair.first << ": " << pair.second << "\n"; // Output: 1: One 2: Two
    }
}
// Output: Map contains: 1: One 2: Two



// emplace_hint() 🍁
// Syntax: map_name.emplace_hint(position, {key, value});
// Description: Constructs a key-value pair in place at the specified position.
#include <iostream>
#include <map>
int main() {
    std::map<int, std::string> m;
    auto it = m.emplace_hint(m.end(), 1, "One"); // Constructs key-value pair (1, "One") in place at the end
    std::cout << "Inserted: " << it->first << ": " << it->second << "\n"; // Output: Inserted: 1: One
}
// Output: Inserted: 1: One
// Output: Map contains: 1: One 2: Two



