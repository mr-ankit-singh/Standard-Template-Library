/*
#__ std::deqeue in STL __#

    - A deque (double-ended queue) is a sequence container that allows fast insertion and deletion at both ends.
    - It can be considered as a hybrid between a vector and a list.
    - Elements can be added or removed from both the front and back of the deque.
    - It is implemented as a dynamic array of arrays, allowing for efficient random access and insertion/deletion.

    - Syantax:
        std::deque<type> deque_name;
        std::deque<type> deque_name(size, value);   // Initializes a deque with 'size' elements, each initialized to 'value'
        std::deque<type> deque_name(begin, end);    // Initializes a deque with elements from the range [begin, end)
        std::deque<type> deque_name(deque_name);    // Copy constructor
        std::deque<type> deque_name(deque_name, allocator); // Copy constructor with custom allocator

    - Member Functions:
        push_front()   : Adds an element to the front of the deque.
        push_back()    : Adds an element to the back of the deque.
        pop_front()    : Removes the front element from the deque.
        pop_back()     : Removes the back element from the deque.
        front()        : Returns a reference to the first element in the deque.
        back()         : Returns a reference to the last element in the deque.
        at()           : Returns a reference to the element at a specific index.
        empty()        : Returns true if the deque is empty, false otherwise. 
        size()         : Returns the number of elements in the deque.
        swap()         : Exchanges the contents of the deque with another deque of the same type.
        emplace_front(): Constructs an element in place at the front of the deque.
        emplace_back() : Constructs an element in place at the back of the deque.
        insert()       : Inserts an element at a specific position in the deque.
        erase()        : Removes elements from a specific position in the deque.
        clear()        : Removes all elements from the deque.

*/

// push_front() and push_back() 🍁
// Syntax: deque_name.push_front(value); deque_name.push_back(value);
// Description: Adds an element to the front or back of the deque, respectively.
#include <iostream>
#include <deque>
int main() {
    std::deque<int> d;
    d.push_front(10); // Adds 10 to the front
    d.push_back(20);  // Adds 20 to the back
    std::cout << "Front: " << d.front() << "\n"; // Output: 10
    std::cout << "Back: " << d.back() << "\n";   // Output: 20
}
// Output: Front: 10 Back: 20


// pop_front() and pop_back() 🍁
// Syntax: deque_name.pop_front(); deque_name.pop_back();
// Description: Removes the front or back element from the deque, respectively.
#include <iostream>
#include <deque>
int main() {
    std::deque<int> d;
    d.push_front(10); // Adds 10 to the front
    d.push_back(20);  // Adds 20 to the back
    d.pop_front();    // Removes 10
    std::cout << "Front: " << d.front() << "\n"; // Output: 20
}
// Output: Front: 20


// front() and back() 🍁
// Syntax: deque_name.front(); deque_name.back();
// Description: Returns a reference to the first or last element in the deque, respectively.
#include <iostream>
#include <deque>
int main() {
    std::deque<int> d;
    d.push_front(10); // Adds 10 to the front
    d.push_back(20);  // Adds 20 to the back
    std::cout << "Front: " << d.front() << "\n"; // Output: 10
    std::cout << "Back: " << d.back() << "\n";   // Output: 20
}
// Output: Front: 10 Back: 20


// at() 🍁
// Syntax: deque_name.at(index);
// Description: Returns a reference to the element at a specific index in the deque.
#include <iostream>
#include <deque>
int main() {
    std::deque<int> d;
    d.push_front(10); // Adds 10 to the front
    d.push_back(20);  // Adds 20 to the back
    std::cout << "Element at index 0: " << d.at(0) << "\n"; // Output: 10
}
// Output: Element at index 0: 10


// empty() 🍁
// Syntax: deque_name.empty();
// Description: Returns true if the deque is empty, false otherwise.
#include <iostream>
#include <deque>
int main() {
    std::deque<int> d;
    std::cout << "Is deque empty? " << (d.empty() ? "Yes" : "No") << "\n"; // Output: Yes
    d.push_front(10); // Adds 10 to the front
    std::cout << "Is deque empty? " << (d.empty() ? "Yes" : "No") << "\n"; // Output: No
}
// Output: Is deque empty? Yes Is deque empty? No


// size() 🍁
// Syntax: deque_name.size();
// Description: Returns the number of elements in the deque.
#include <iostream>
#include <deque>
int main() {
    std::deque<int> d;
    d.push_front(10); // Adds 10 to the front
    d.push_back(20);  // Adds 20 to the back
    std::cout << "Size of deque: " << d.size() << "\n"; // Output: 2
}
// Output: Size of deque: 2


// swap() 🍁
// Syntax: deque_name1.swap(deque_name2);
// Description: Exchanges the contents of two deques.
#include <iostream>
#include <deque>
int main() {
    std::deque<int> d1, d2;
    d1.push_front(10); // Adds 10 to the front of d1
    d2.push_back(20);  // Adds 20 to the back of d2
    d1.swap(d2);      // Swaps contents of d1 and d2
    std::cout << "Front of d1: " << d1.front() << "\n"; // Output: 20
    std::cout << "Front of d2: " << d2.front() << "\n"; // Output: 10
}
// Output: Front of d1: 20 Front of d2: 10


// emplace_front() and emplace_back() 🍁
// Syntax: deque_name.emplace_front(value); deque_name.emplace_back(value);
// Description: Constructs an element in place at the front or back of the deque, respectively.
#include <iostream>
#include <deque>
#include <string>
int main() {
    std::deque<std::string> d;
    d.emplace_front("Hello"); // Constructs "Hello" at the front
    d.emplace_back("World");  // Constructs "World" at the back
    std::cout << "Front: " << d.front() << "\n"; // Output: Hello
    std::cout << "Back: " << d.back() << "\n";   // Output: World
}
// Output: Front: Hello Back: World


// insert() 🍁
// Syntax: deque_name.insert(position, value);
// Description: Inserts an element at a specific position in the deque.
#include <iostream>
#include <deque>
int main() {
    std::deque<int> d;
    d.push_front(10); // Adds 10 to the front
    d.push_back(20);  // Adds 20 to the back
    d.insert(d.begin() + 1, 15); // Inserts 15 at index 1
    std::cout << "Element at index 1: " << d.at(1) << "\n"; // Output: 15
}
// Output: Element at index 1: 15


// erase() 🍁
// Syntax: deque_name.erase(position);
// Description: Removes an element from a specific position in the deque.
#include <iostream>
#include <deque>
int main() {
    std::deque<int> d;
    d.push_front(10); // Adds 10 to the front
    d.push_back(20);  // Adds 20 to the back
    d.erase(d.begin() + 1); // Removes element at index 1 (20)
    std::cout << "Element at index 0: " << d.at(0) << "\n"; // Output: 10
}
// Output: Element at index 0: 10


// clear() 🍁
// Syntax: deque_name.clear();
// Description: Removes all elements from the deque.
#include <iostream>
#include <deque>
int main() {
    std::deque<int> d;
    d.push_front(10); // Adds 10 to the front
    d.push_back(20);  // Adds 20 to the back
    d.clear();        // Removes all elements
    std::cout << "Size after clear: " << d.size() << "\n"; // Output: 0
}
// Output: Size after clear: 0


// Example of using a deque as a stack 🍁
#include <iostream>
#include <deque>
int main() {
    std::deque<int> stack;
    stack.push_front(10); // Push 10 onto the stack
    stack.push_front(20); // Push 20 onto the stack
    std::cout << "Top of stack: " << stack.front() << "\n"; // Output: 20
    stack.pop_front();     // Pop the top element (20)
    std::cout << "Top of stack after pop: " << stack.front() << "\n"; // Output: 10
}
// Output: Top of stack: 20 Top of stack after pop: 10


// Example of using a deque as a queue 🍁
#include <iostream>
#include <deque>
int main() {
    std::deque<int> queue;
    queue.push_back(10); // Enqueue 10
    queue.push_back(20); // Enqueue 20
    std::cout << "Front of queue: " << queue.front() << "\n"; // Output: 10
    queue.pop_front();    // Dequeue (remove front element)
    std::cout << "Front of queue after dequeue: " << queue.front() << "\n"; // Output: 20
}
// Output: Front of queue: 10 Front of queue after dequeue: 20
