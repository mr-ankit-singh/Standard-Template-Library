/*
#__ std::queue in STL __#

    - A queue is a FIFO (First In First Out) data structure.
    - The first element added to the queue will be the first one to be removed.

    Member Functions:
    push()       : Adds an element to the end of the queue.
    push_range() : Adds a range of elements to the end of the queue.
    pop()        : Removes the front element from the queue.
    front()      : Returns a reference to the front element in the queue.
    back()       : Returns a reference to the last element in the queue.
    empty()      : Returns true if the queue is empty, false otherwise. 
    size()       : Returns the number of elements in the queue.
    swap()       : Exchanges the contents of the queue with another queue of the same type.
    emplace()    : Constructs an element in place at the end of the queue.

*/

// push() 🍁
// Syntax: queue_name.push(value);
// Description: Adds an element to the end of the queue.
#include <iostream>
#include <queue>
int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    std::cout << "Front: " << q.front() << "\n"; // Output: 10
}
// Output: 10


// push_range() 🍁
// Syntax: queue_name.push_range(start, end);
// Description: Adds a range of elements to the end of the queue.
#include <iostream>
#include <queue>
#include <vector>
int main() {
    std::queue<int> q;
    std::vector<int> vec = {30, 40, 50};
    // q.push_range(vec.begin(), vec.end());
    std::cout << "Front: " << q.front() << "\n"; // Output: 10
}
// Output: 10


// pop() 🍁
// Syntax: queue_name.pop();
// Description: Removes the front element from the queue.
#include <iostream>
#include <queue>
int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.pop(); // Removes 10
    std::cout << "Front: " << q.front() << "\n"; // Output: 20
}


// front() 🍁
// Syntax: queue_name.front();
// Description: Returns a reference to the front element in the queue.
#include <iostream>
#include <queue>
int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    std::cout << "Front: " << q.front() << "\n"; // Output: 10
}


// back() 🍁
// back() 🍁
// Syntax: queue_name.back();
// Description: Returns a reference to the last element in the queue.
#include <iostream>
#include <queue>
int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    std::cout << "Back: " << q.back() << "\n"; // Output: 20
}


// empty() 🍁
// Syntax: queue_name.empty();
// Description: Returns true if the queue is empty, false otherwise.
#include <iostream> 
#include <queue>
int main() {
    std::queue<int> q;
    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << "\n"; // Output: Yes
    q.push(10);
    std::cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << "\n"; // Output: No
}
// Output: Yes No


// size() 🍁
// Syntax: queue_name.size();
// Description: Returns the number of elements in the queue.
#include <iostream>
#include <queue>
int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    std::cout << "Size: " << q.size() << "\n"; // Output: 2
}
// Output: 2


// swap() 🍁
// Syntax: queue_name.swap(other_queue);
// Description: Exchanges the contents of the queue with another queue of the same type.
#include <iostream>
#include <queue>
int main() {
    std::queue<int> q1, q2;
    q1.push(10);
    q2.push(20);
    q1.swap(q2);
    std::cout << "Front of q1: " << q1.front() << "\n"; // Output: 20
    std::cout << "Front of q2: " << q2.front() << "\n"; // Output: 10
}
// Output: 20 10


// emplace() 🍁
// Syntax: queue_name.emplace(value);
// Description: Constructs an element in place at the end of the queue.
#include <iostream>
#include <queue>
#include <string>
int main() {
    std::queue<std::string> q;
    q.emplace("Hello");
    q.emplace("World");
    std::cout << "Front: " << q.front() << "\n"; // Output: Hello
}
// Output: Hello

// Note: emplace() is used to construct an object in place, which can be more efficient than push() in some cases.
// It avoids unnecessary copies or moves of the object being added to the queue.
// It is particularly useful when adding complex objects or when the constructor of the object takes parameters.
// In this case, emplace() allows you to pass the constructor arguments directly, and the object is constructed in place within the queue.
// This can lead to performance improvements, especially for large or complex objects.
// However, for simple types like integers or strings, the difference in performance may not be significant.
// In such cases, using push() is perfectly fine and often more readable.
// The choice between emplace() and push() depends on the specific use case and the type of objects being added to the queue.