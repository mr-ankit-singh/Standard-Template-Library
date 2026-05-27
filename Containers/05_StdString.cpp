/*

TOPIC: std::string

    1. C++ has in its definition a way to represent a sequence of characters as an object of the class. 
    2. This class is called std:: string. 
    3. String class stores the characters as a sequence of bytes with the functionality of allowing access to the single-byte character.  

    Syntax: std::string name;

    4. Access Elements:
        a. at()    -> access specified element with bounds checking.
        b. []      -> access specified element.
        c. front() -> access the first element.
        d. back()  -> access the last element.
        e. data()  -> gives access to the underlying array.

    5. Capacity
        size()           -> Return length of string.
        length()         -> Return length of string.
        max_size()       -> Return maximum size of string.
        resize()         -> Resize string.
        capacity()       -> Return size of allocated storage.
        reserve()        -> Request a change in capacity.
        clear()          -> Clear string.
        empty()          -> Test if string is empty.
        shrink_to_fit()  -> Shrink to fit.

    6. Operations
        clear()          -> clears the contents
        insert()         -> inserts characters
        erase()          -> removes characters
        push_back()      -> appends a character to the end
        pop_back()       -> removes the last character
        append()         -> appends characters to the end
        operator+=       -> appends characters to the end
        compare()        -> compares two strings
        starts_with()    -> checks if the string starts with the given prefix
        ends_with()      -> checks if the string ends with the given suffix
        contains()       -> checks if the string contains the given substring or character
        replace()        -> replaces specified portion of a string
        substr()         -> returns a substring
        copy()           -> copies characters
        resize()         -> changes the number of characters stored
        swap()           -> swaps the contents
        resize_and_overwrite()   ->changes the number of characters stored and possibly overwrites indeterminate contents via user-provided operation
        
    7. Search
        c_str()             -> Get C string equivalent 
        data()              -> Get string data 
        get_allocator()     -> Get allocator 
        copy()              -> Copy sequence of characters from string 
        find()              -> Find content in string 
        rfind()             -> Find last occurrence of content in string 
        find_first_of()     -> Find character in string 
        find_last_of()      -> Find character in string from the end 
        find_first_not_of() -> Find absence of character in string 
        find_last_not_of()  -> Find non-matching character in string from the end 
        substr()            -> Generate substring 
        compare()           -> Compare strings 

*/

// Input a string using std::cin 🍁
#include <iostream>
using namespace std;
int main(){
	string name;
	cin >> name;
	cout << name << endl;
	return 0;
}

// Taking multi-word input using std::getline 🍁
// Syntax:std::getline(std::cin, name); 
#include <iostream>
#include<string>
int main(){
	std::string name;
	std::getline(std::cin, name);
	std::cout << name << std::endl;
	return 0;
}


// at() 🍁
// Syntax : str.at(index)
// Description : It also returns the character at some specified position in a string.
#include <iostream>
#include <string>
int main()
{
	std::string s = "I love C";
	std::cout << "Character at fifth position : " << s.at(5) << std::endl;
	return 0;
}


// length() 🍁
// Description : Return the length of string
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	std::cout << name.length() << std::endl;
    std::cout << name.size() << std::endl;
	return 0;
}


// size() 🍁
// Syntax: str.size()
// Description: Returns the number of characters in the string.
// It is same as length() function.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	std::cout << name.size() << std::endl;
	return 0;
}


// front() & back() 🍁
// Syntax: str.front() | str.back()
// Description: Returns the first and last character of a string respectively.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	std::cout << name.front() << std::endl;
	std::cout << name.back() << std::endl;
	return 0;
}


// data() 🍁
// Syntax: str.data()
// Description: It returns the address of the first character of the string.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	std::cout << name.data() << std::endl;
	std::cout << *(name.data()) << std::endl;
	std::cout << (void*)(name.data()) << std::endl;
	return 0;
}


// max_size() 🍁
// Syntax: str.max_size()
// Description: It returns the maximum size of the string.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	std::cout << name.max_size() << std::endl;
	return 0;
}


// capacity() 🍁
// Syntax: str.capacity()
// Description: It returns the size of the allocated storage.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	std::cout << name.capacity() << std::endl;
	return 0;
}



// resize() 🍁
// Syntax: str.resize(size, character)
// Description: It changes the size of the string to the specified size.
// If the size is less than the current size, it reduces the string to the specified size.
// If the size is greater than the current size, it increases the string to the specified size and fills the extra space with the specified character.
// If the character is not specified, it fills the extra space with null characters.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	name.resize(20, 'a');
	std::cout << name << std::endl;
	return 0;
}
// Note: The default character is null character.


// reverse() 🍁
// Syntax: str.reverse()
// Description: It reverses the string.
// It is not a member function of the string class.
// It is a member function of the algorithm header file.
// It is used to reverse the string in place.
#include <iostream>
#include<string>
#include <algorithm> // for reverse
int main(){
	std::string name;
	name = "I have 4 chocolates";
	std::reverse(name.begin(), name.end());
	std::cout << name << std::endl;
	return 0;
}


// clear() 🍁
// Syntax: str.clear()
// Description: It clears the contents of the string.
// It does not change the size of the string.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	name.clear();
	std::cout << name << std::endl;
	return 0;
}


// empty() 🍁
// Syntax: str.empty()
// Description: It checks whether the string is empty or not.
// It returns 1 if the string is empty and 0 if not.
// It is same as size() == 0.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	std::cout << name.empty() << std::endl;
	return 0;
}


// shrink_to_fit() 🍁
// Syntax: str.shrink_to_fit()
// Description: It reduces the capacity of the string to fit its size.
// It is used to reduce the memory usage of the string.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	name.shrink_to_fit();
	std::cout << name.capacity() << std::endl;
	return 0;
}


// insert() 🍁
// Syntax: str.insert(position, string)
// Description: It inserts the string at the specified position in the string.
// It shifts the rest of the string to the right.
// It is used to insert a string at a specified position in the string.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	name.insert(2, "love ");
	std::cout << name << std::endl;
	return 0;
}
// Note: The default position is 0.
// Note: The default string is empty string.
// Note: The default character is null character.
// Note: The default size is 0.
// Note: The default character is null character.


// erase() 🍁
// Syntax: str.erase(position, size)
// Description: It erases the specified number of characters from the string starting from the specified position.
// It shifts the rest of the string to the left.
// It is used to erase a string from a specified position in the string.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	name.erase(2, 4);
	std::cout << name << std::endl;
	return 0;
}
// Note: The default position is 0.
// Note: The default size is 0.
// Note: The default character is null character.


// push_back() 🍁
// Syntax: str.push_back(character)
// Description: It appends the character to the end of the string.
// It is used to append a character to the end of the string.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	name.push_back('!?');
	std::cout << name << std::endl;
	return 0;
}


// pop_back() 🍁
// Syntax: str.pop_back()
// Description: It removes the last character from the string.
// It is used to remove the last character from the string.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates!";
	name.pop_back();
	std::cout << name << std::endl;
	return 0;
}


// append() 🍁
// Syntax: str.append(string)
// Description: It appends the string to the end of the string.
// It is used to append a string to the end of the string.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	name.append(" and 2 ice creams");
	std::cout << name << std::endl;
	return 0;
}
// Note: The default string is empty string.
// Note: The default character is null character.


// operator+= 🍁
// Syntax: str += string
// Description: It appends the string to the end of the string.
// It is used to append a string to the end of the string.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	name += " and 2 ice creams";
	std::cout << name << std::endl;
	return 0;
}
// Note: The default string is empty string.


// compare() 🍁
// Syntax: str.compare(string)
// Description: It compares the string with the specified string.
// It returns 0 if both the strings are equal.
// It returns a positive value if either str1 > str2
// It returns a negative value if either str1 < str2
// It is used to compare two strings lexicographically.
// It is used to compare two strings character by character.
// It is used to compare two strings in a case sensitive manner.
// It is used to compare two strings in a case insensitive manner.
#include <iostream>
#include<string>
int main(){
	std::string str1 ("have apple");
	std::string str2 ("have app");
	std::cout << str1.compare(str2) << std::endl;
	return 0;
}
//-------
#include <iostream>
#include<string>
int main(){
	std::string str1 ("have gpple");
	std::string str2 ("have apple");
	std::cout << str1.compare(str2) << std::endl;
	return 0;
}
//-------
#include <iostream>
#include<string>
int main(){
	std::string str1 ("have apple");
	std::string str2 ("have apple");
	std::cout << str1.compare(str2) << std::endl;
	return 0;
}
//-------
#include <iostream>
#include<string>
int main(){
	std::string str1 ("have apple");
	std::string str2 ("have apple pie");
	std::cout << str1.compare(str2) << std::endl;
	return 0;
}


// starts_with() 🍁
// Syntax: str.starts_with(string)
// Description: It checks if the string starts with the specified string.
// It returns 1 if the string starts with the specified string and 0 if not.
// It is used to check if the string starts with the specified string.
// It is used to check if the string starts with the specified string in a case sensitive manner.
// It is used to check if the string starts with the specified string in a case insensitive manner.
#include <iostream>
#include<string>
int main(){
	std::string str1 ("have apple");
	std::string str2 ("have app");
	std::cout << str1.starts_with(str2) << std::endl;
	return 0;
}


// ends_with() 🍁
// Syntax: str.ends_with(string)
// Description: It checks if the string ends with the specified string.
// It returns 1 if the string ends with the specified string and 0 if not.
// It is used to check if the string ends with the specified string.
// It is used to check if the string ends with the specified string in a case sensitive manner.
// It is used to check if the string ends with the specified string in a case insensitive manner.
#include <iostream>
#include<string>
int main(){
	std::string str1 ("have apple");
	std::string str2 ("apple");
	std::cout << str1.ends_with(str2) << std::endl;
	return 0;
}


// contains() 🍁
// Syntax: str.contains(string)
// Description: It checks if the string contains the specified string.
// It returns 1 if the string contains the specified string and 0 if not.
// It is used to check if the string contains the specified string.
// It is used to check if the string contains the specified string in a case sensitive manner.
// It is used to check if the string contains the specified string in a case insensitive manner.
#include <iostream>
#include<string>
int main(){
	std::string str1 ("have apple");
	std::string str2 ("apple");
	std::cout << str1.contains(str2) << std::endl;
	return 0;
}


// replace() 🍁
// Syntax: str.replace(position, size, string)
// Description: It replaces the specified number of characters from the string starting from the specified position with the specified string.
// It shifts the rest of the string to the right.
// It is used to replace a string from a specified position in the string.
// It is used to replace a string from a specified position in the string in a case sensitive manner.
// It is used to replace a string from a specified position in the string in a case insensitive manner.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	name.replace(2, 4, "love ");
	std::cout << name << std::endl;
	return 0;
}


// substr() 🍁
// Syntax: str.substr(position, size)
// Description: It returns the substring of the string starting from the specified position and of the specified size.
// It is used to get a substring from a specified position in the string.
// It is used to get a substring from a specified position in the string in a case sensitive manner.
// It is used to get a substring from a specified position in the string in a case insensitive manner.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	std::cout << name.substr(2, 4) << std::endl;
	return 0;
}
// Note: The default position is 0.


// copy() 🍁
// Syntax: str.copy(string, position, size)
// Description: It copies the specified number of characters from the string starting from the specified position to the specified string.
// It is used to copy a string from a specified position in the string.
// It is used to copy a string from a specified position in the string in a case sensitive manner.
// It is used to copy a string from a specified position in the string in a case insensitive manner.
#include <iostream>
#include <string>
int main(){
    std::string name = "I have 4 chocolates";
    char str[10];                    // char array chahiye, std::string nahi
    int len = name.copy(str, 2, 4);  // 2 characters, index 4 se
    str[len] = '\0';                 // null terminator manually lagao
    std::cout << str << std::endl;   // "av"
    return 0;
}
// Note: The default position is 0.


// swap() 🍁
// Syntax: str.swap(string)
// Description: It swaps the contents of the string with the specified string.
// It is used to swap the contents of two strings.
// It is used to swap the contents of two strings in a case sensitive manner.
// It is used to swap the contents of two strings in a case insensitive manner.
#include <iostream>
#include<string>
int main(){
	std::string name1;
	name1 = "I have 4 chocolates";
	std::string name2;
	name2 = "I love 4 chocolates";
	name1.swap(name2);
	std::cout << name1 << std::endl;
	return 0;
}
// Note: The default string is empty string.


// resize_and_overwrite() 🍁
// Syntax: str.resize_and_overwrite(size, operation)
// Description: It changes the size of the string to the specified size and overwrites the indeterminate contents via user-provided operation.
// It is used to resize a string and overwrite the indeterminate contents via user-provided operation.
// It is used to resize a string and overwrite the indeterminate contents via user-provided operation in a case sensitive manner.
#include <iostream>
#include<string>
#include <algorithm> // for reverse
#include <iterator> // for iterators
#include <vector> // for vector
int main(){
	std::string name;
	name = "I have 4 chocolates";
	name.resize_and_overwrite(20, [](char* p, std::size_t n) {
		std::fill(p, p + n, 'a');
	});
	std::cout << name << std::endl;
	return 0;
}
// Note: The default string is empty string.


// c_str() 🍁
// Syntax: str.c_str()
// Description: It returns the C string equivalent of the string.
// It is used to convert a string to a C string.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	const char* cstr = name.c_str();
	std::cout << cstr << std::endl;
	return 0;
}


// data() 🍁
// Syntax: str.data()
// Description: It returns the string data equivalent of the string.
// It is used to convert a string to a string data.
#include <iostream>
#include<string>
int main(){
	std::string name;
	name = "I have 4 chocolates";
	const char* cstr = name.data();
	std::cout << cstr << std::endl;
	return 0;
}



