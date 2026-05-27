/*

TOPIC: Strings in C++

    1. string is a collection of characters. 
    2. There are two different types of strings in C++.
        a. C-style string
        b. std::string (part of the standard library)
    3. String is an array of character.
    4. \0 represents the termination of string.


    5. These predefined functions are part of the cstring library. 
       Therefore, we need to include this library in our code by writing
        #include <cstring>

TOPIC: C-String Functions (cstring header)

    Header: #include <cstring>

    FUNCTIONS:
        a. strlen()  -> calculates the length of string
        b. strcat()  -> appends one string at the end of another
        c. strncat() -> appends first n characters of a string at the end of another
        d. strcpy()  -> copies a string into another
        e. strncpy() -> copies first n characters of one string into another
        f. strcmp()  -> compares two strings
        g. strncmp() -> compares first n characters of two strings
        h. strchr()  -> finds first occurrence of a given character in a string
        i. strrchr() -> finds last occurrence of a given character in a string
        j. strstr()  -> finds first occurrence of a given string in another string

*/

//==============================================================================
// strlen() -> It calculates and returns the length of a string (excluding null character '\0').
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[] = "Hello";
    cout << "Length : " << strlen(str) << endl;  // 5
    return 0;
}

//==============================================================================
// strcat() -> It appends (joins) one string at the end of another string.
// The destination string must have enough space to hold the result.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[20] = "Hello";
    char str2[] = " World";
    strcat(str1, str2);
    cout << "After strcat : " << str1 << endl;  // Hello World
    return 0;
}

//==============================================================================
// strncat() -> It appends first n characters of source string at the end of destination string.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[20] = "Hello";
    char str2[] = " World";
    strncat(str1, str2, 3);  // append only first 3 characters of str2 i.e. " Wo"
    cout << "After strncat : " << str1 << endl;  // Hello Wo
    return 0;
}

//==============================================================================
// strcpy() -> It copies the source string into the destination string (including '\0').
// The previous content of destination is replaced.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char src[] = "Hello World";
    char dest[20];
    strcpy(dest, src);
    cout << "After strcpy : " << dest << endl;  // Hello World
    return 0;
}

//==============================================================================
// strncpy() -> It copies only the first n characters of source string into destination string.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char src[] = "Hello World";
    char dest[20];
    strncpy(dest, src, 5);  // copy only first 5 characters
    dest[5] = '\0';          // manually add null terminator
    cout << "After strncpy : " << dest << endl;  // Hello
    return 0;
}

//==============================================================================
// strcmp() -> It compares two strings lexicographically (character by character).
// Returns 0 if equal, negative if str1 < str2, positive if str1 > str2.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[] = "apple";
    char str2[] = "apple";
    char str3[] = "banana";
    cout << strcmp(str1, str2) << endl;  // 0      (equal)
    cout << strcmp(str1, str3) << endl;  // negative (apple < banana)
    cout << strcmp(str3, str1) << endl;  // positive (banana > apple)
    return 0;
}

//==============================================================================
// strncmp() -> It compares only the first n characters of two strings.
// Returns 0 if equal, negative if str1 < str2, positive if str1 > str2.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str1[] = "apple";
    char str2[] = "apricot";
    cout << strncmp(str1, str2, 2) << endl;  // 0  (first 2 chars "ap" == "ap")
    cout << strncmp(str1, str2, 3) << endl;  // negative ("app" < "apr")
    return 0;
}

//==============================================================================
// strchr() -> It finds the first occurrence of a given character in a string.
// Returns a pointer to the first occurrence, or NULL if not found.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[] = "Hello World";
    char* ptr = strchr(str, 'o');  // first 'o' in the string
    if (ptr) {
        cout << "First 'o' found at index : " << ptr - str << endl;  // 4
        cout << "Substring from first 'o' : " << ptr << endl;        // o World
    }
    return 0;
}

//==============================================================================
// strrchr() -> It finds the last occurrence of a given character in a string.
// Returns a pointer to the last occurrence, or NULL if not found.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[] = "Hello World";
    char* ptr = strrchr(str, 'o');  // last 'o' in the string
    if (ptr) {
        cout << "Last 'o' found at index : " << ptr - str << endl;  // 7
        cout << "Substring from last 'o' : " << ptr << endl;        // orld
    }
    return 0;
}

//==============================================================================
// strstr() -> It finds the first occurrence of a given substring in another string.
// Returns a pointer to the beginning of the found substring, or NULL if not found.
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char str[]    = "Hello World";
    char substr[] = "World";
    char* ptr = strstr(str, substr);
    if (ptr) {
        cout << "Substring found at index : " << ptr - str << endl;  // 6
        cout << "Substring from position  : " << ptr << endl;        // World
    }
    return 0;
}