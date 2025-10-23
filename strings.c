#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Declarations of helper functions
//
// You can ignore them for now and return to them once you fully understand how strings work
// if you wish
void section_start(const char* section);
void section_end();
void subsection_start(const char* subsection);
void subsection_end();
void vertical_padding();


/*************************************************************************************************/
/*                                                                                               */
/*                                                                                               */
/*                                            READ ME                                            */
/*                                                                                               */
/*                                                                                               */
/*************************************************************************************************/

// * * * * * * * * * * * * * * * * * * * * Introduction * * * * * * * * * * * * * * * * * * * * * *
//
// This file explains how characters and strings are represented in computers and how to work
// with them in the C programming language.
//
//
// All code is compilable and runnable so you can test everything out yourself.
//
// gcc -o main -Wall -Wextra -Werror=vla -Wconversion -g -lm strings.c -std=c99
//
// ./main
//
// * * * * * * * * * * * * * * * * * * * * *  main()  * * * * * * * * * * * * * * * * * * * * * * *
//
//
// Immediately after this README, you will find a main() function calling multiple functions.
//
// Each function represents a single section, each section focused on a different topic.
//
//
// * * * * * * * * * * * * * * * * * * * *  Sections  * * * * * * * * * * * * * * * * * * * * * * *
//
//
// Each section is further split into multiple subsections, so you can only focus on the parts
// you wish to learn about.
//
// For a brief overview of what a certain section focuses on, look at the function definition
// for said section. In each subsection, you will find explanations along with practical
// code examples. Each subsection also tries to explain possible limitations and pitfalls.
//
// Feel free to comment out or uncomment specific sections in main() or subsections in section
// definitions so you can only focus on what you want.
//
// All sections and subsections are defined in the code after the main() function in the order
// they are called.
//
//
// * * * * * * * * * * * * * * * * * *  Extra Functions * * * * * * * * * * * * * * * * * * * * * *
//
//
// After section definitions, you can find certain smaller functions called from subsections, again
// sorted by section/subsection. These functions also include comments and explanations, but are
// kept separate from the subsections to make the sections a bit easier to read.
//
//
// * * * * * * * * * * * * * * * * * * * * Exercises  * * * * * * * * * * * * * * * * * * * * * * *
//
//
// Subsections can also contain exercises for the reader. These exercises ask you to write your
// own functions. You can find incomplete definitions of these functions after the helper functions
// described in the previous paragraph. Exercises are described in subsections, so I suggest
// implementing them on the go instead of jumping straight to exercises. When a subsection defines
// and exercise, it also includes a function prototype and calls the function to test if it works,
// but feel free to add your own tests as well.
//
//
// * * * * * * * * * * * * * * * * * * Helper Functions * * * * * * * * * * * * * * * * * * * * * *
//
// At the very end of the file, you can find my own helper functions that allow me to organize
// the code into sections. After you've gone through all the sections, you should be able to easily
// understand what those helper functions do, but feel free to ignore them.
//
//
// * * * * * * * * * * * * * * * * * * * * * Notes  * * * * * * * * * * * * * * * * * * * * * * * *
//
//
// Note: You may find yourself jumping between many function definitions across the entire file.
//       I suggest you use 'go to definition'.
//


/*************************************************************************************************/
/*                                                                                               */
/*                                                                                               */
/*                                        Function main()                                        */
/*                                                                                               */
/*                                                                                               */
/*************************************************************************************************/


void characters();
void string_basics();
void string_operations();
void parsing_strings();
void reading_strings();


int main() {
    characters();
    string_basics();
    string_operations();
    parsing_strings();
    reading_strings();
}



/*************************************************************************************************/
/*                                                                                               */
/*                                                                                               */
/*                                            Sections                                           */
/*                                                                                               */
/*                                                                                               */
/*************************************************************************************************/


/**********************************************/
/*                                            */
/*                 Characters                 */
/*                                            */
/**********************************************/


void char_type();
void chars_are_just_numbers();
void char_arithmetics();


void characters() {
    section_start("Characters");

    // The bare basics of the char data type
    char_type();

    // Behaviour of chars in C and how they're actually just numbers
    chars_are_just_numbers();

    // What operations we can do with chars in C
    // How to use the fact that a char is just a number to our advantage
    char_arithmetics();

    section_end();
}


void char_type() {
    subsection_start(__func__);


    // We should all know by now that all data in a computer has to be represented using numbers
    // for the computer to be able to process the data. Therefore, it should be obvious that
    // to process characters, we need to figure out a way to map numbers to characters. You could,
    // in theory, create your own mapping and work with it as you like, but preferrably we would
    // all want to stick to the same standard, so all programs understand text the same way and
    // are able to interact between one another.
    //
    // This universal mapping used by most people and programs today is known as the ASCII table.
    // It is supported by virtually every program in the world -- including your operating system,
    // the program used to create the font you're using (so a character can be mapped to its
    // correct graphic representation and then rendered), or by your compiler, which understands
    // bytes in the source file as ASCII values.
    //
    // The ASCII table was originally invented as a mapping from 7bit numbers to characters, but
    // was later extended to 256 characters to utilize all 8 bits of a byte.
    
    // To represent characters from the extended ASCII table, we use the char data type
    //
    // char is guaranteed by the standard to be always exactly one byte long
    char c = 'a';

    // To print a character, we can use the putchar function or the %c formatting sequence
    // in a call to printf
    putchar(c);
    printf(" %c\n", c);

    // We can also print the ASCII value corresponding to the character easily using printf
    printf("Character '%c' is represented using the number %d\n", c, (int)c);


    subsection_end();
}


void chars_are_just_numbers() {
    subsection_start(__func__);


    // Character literals are translated by the compiler to corresponding ASCII values
    // This means char is just a one byte integer that can also be printed as a character
    // We can use them as numbers if we want, and they will behave as numbers
    // The only special thing about chars is that we can print them as characters using the ASCII
    // table
    for (char c = 0; c < 10; ++c) {
        printf("%4d", c*c);
    }
    printf("\n");


    // Both signed and unsigned variants of char exist
    char signed_char = -1;
    // Be aware that integer overflow/underflow is considered undefined behaviour
    unsigned char unsigned_char = (unsigned char)-1;

    printf("signed_char=%d\n", signed_char);
    printf("unsigned_char=%d\n", unsigned_char);


    subsection_end();
}


void char_arithmetics() {
    subsection_start(__func__);


    char c = 'r';

    // Since chars are numbers, we can perform standard arithmetic operations
    // Keep in mind the ASCII tables keeps characters '0'-'9', 'A'-'Z', and 'a'-'z' sorted
    // in an ascending order
    
    // We can check whether a character falls within a specified range
    if ('a' <= c && c <= 'z') {
        printf("'%c' is a lowercase letter\n", c);
    } else if ('A' <= c && c <= 'Z') {
        printf("'%c' is an uppercase letter\n", c);
    } else if ('0' <= c && c <= '9') {
        printf("'%c' is a digit\n", c);
    } else {
        printf("'%c' is not alphanumeric\n", c);
    }

    // Or, better yet, use functions provided by the standard library when possible
    if (islower(c)) {
        printf("'%c' is a lowercase letter\n", c);
    } else if (isupper(c)) {
        printf("'%c' is an uppercase letter\n", c);
    } else if (isdigit(c)) {
        printf("'%c' is a digit\n", c);
    } else {
        printf("'%c' is not alphanumeric\n", c);
    }
    
    // We can iterate over characters
    for (char c = 'a'; c <= 'z'; ++c) {
        printf("%c ", c);
    }
    printf("\n");

    // We can convert between lower and uppercase letters just by adding/subtracting
    // the difference between the lowercased and uppercased alphabet
    //
    // Note: uppercase characters come first in the ASCII table and therefore have lower values
    //
    // Note: The delta is 32, but if you can't rely on the standard library, try not to use
    //       the number 32 directly, but instead compute it as the difference between a lowercase
    //       and uppercase variant of the same letter
    //       This way it is immediately obvious what the value means and where it came from
    //       32 may seem random at first glance and requires a check of the ASCII table to verify
    const char case_delta = 'a' - 'A';

    char x = 'X';
    char y = 'y';
    
    printf("[Manual Conversion] Before: %c%c", x, y);

    x += case_delta;
    y -= case_delta;

    printf(", after: %c%c\n", x, y);

    // Or, better yet, use toupper and tolower from the standard library
    char h = 'h';
    char j = 'J';

    printf("[toupper/tolower] Before: %c%c", h, j);

    h = (char)toupper('h');
    j = (char)tolower('J');

    printf(", after: %c%c\n", h, j);

    // In a similar fashion, you can convert between an ASCII representation of a digit
    // and what digit the character represents
    //
    // Keep in mind that the ASCII representations are not equal to the corresponding digits,
    // but they are grouped together and sorted in an increasing manner
    
    char six = '6';

    // To convert an ASCII representation of a number to a number, we only need to compute
    // the offset from the '0' character
    int isix = '6' - '0';

    printf("'6'*10 = %d\n", six*10);
    printf("('6'-'0')*10 = %d\n", isix*10);


    subsection_end();
}


/**********************************************/
/*                                            */
/*                String Basics               */
/*                                            */
/**********************************************/


void what_is_a_string();
void printf_safety();
void terminator();
void heap_allocated_strings();
void string_literals();

void string_basics() {
    section_start("String Basics");


    // What exactly is a string in C and how do we represent text
    what_is_a_string();

    // A brief warning about the dangers of printf and how to practice safe formatting
    printf_safety();

    // The importance of a terminator
    terminator();

    // How to allocate strings on the heap
    heap_allocated_strings();

    // How string literals work in C
    string_literals();


    section_end();
}


void what_is_a_string() {
    subsection_start(__func__);

    // A string is a how we represent volumes of text longer than one character
    // Since strings are just ordered sequences of characters, it is fairly obvious
    // we can use arrays of chars to store text

    // You've already seen the syntax for a string literal. A sequence of characters surrounded by
    // quotes is just a simpler notation for an array of chars.
    //
    // Note: (void) cast is only used to suppress unused value warning
    //       Normally, you would want to work with the string literal (or any other value) in some
    //       way, not ignore it
    (void)"string literal";

    // However, you may remember that when working with arrays, we always have to store the length
    // of the array (or pointer to the end of the array), because there is no way to figure out
    // the length of an array from just a pointer to the beginning of the array. So how do
    // functions like printf know where a string end?
    
    printf("printf knows where this string ends, even if we don't pass the length of the string using an argument...\n");

    // That's because strings in the C programming language (and many other modern languages)
    // are 'null-terminated'. That is, after the last character of the string, we also include
    // a terminator byte (a zero byte). The integer 0 is defined by the ASCII table as
    // a terminator for this very usage. A zero byte will never serve any other purpose when
    // following the ASCII table, and therefore can be reliably used to mark the end of a string.
    //
    // This convention is followed by the C standard, and, by extension, the C standard library,
    // all C compilers, and almost every C programmer in the world. Thus, if you want to use the C
    // standard library or any third-party libraries, it is best to follow this convention as well.

    // A string is just a zero-terminated array of characters
    // Don't forget to allocate enough memory to fit the terminator
    char string1[9] = { 's', 't', 'r', 'i', 'n', 'g', ' ', '1', 0 };

    // You can (and often want to) allocate a buffer large enough to accomodate more characters,
    // than you currently need. This is in no way an issue, the underlying buffer can be as large
    // as we need. The string, however, ends with the first 0. Anything that comes after the zero
    // will be ignored.
    char string2[100] = { 's', 't', 'r', 'i', 'n', 'g', ' ', '2', 0 };

    // When working with strings, we can use the shorthand notation for null-terminated arrays
    // of characters
    // It is a prettier equivalent to the curly brace notation
    char string3[100] = "string 3";

    // To print out a string, we can use the puts function, or printf with the %s formatting
    // sequence
    // Note: puts automatically prints out a newline character
    puts(string1);
    printf("%s\n", string2);
    puts(string3);


    subsection_end();
}


void printf_safety() {
    subsection_start(__func__);

    // Be careful when calling printf (or any other formatting function from the C standard
    // library). If you allow the user to pass their own custom format strings (not just from
    // standard input, but also from e.g. easily modifiable configuration files found on the disk),
    // you open up a potential vector of attack to malicious users.

    // You can ignore the implementation of readline for now
    // It's just a helper function that displays a prompt to the user and reads an entire
    // line of text from stdin
    void readline(char* dest, int buffer_size);
    char line[255] = "";

    // Never pass a user-provided string as the first argument to printf
    // This could allow a malicious user to access data which shouldn't be accessible
    // When running the program, type in "%d%d%d" and see what happens
    // Try experimenting with other formatting sequences accepted by printf

    readline(line, 255);
    printf("Printing a user-provided string using printf: ");

    // Here, printf only receives the format string, but doesn't receive any values to actually
    // format. If the user were to pass in text containing formatting characters, printf would
    // try to format this string as per usual. However, since we do not pass anything to format,
    // printf would just start reading and outputting whatever is stored on the stack wherever
    // its arguments would otherwise be. This can allow attackers to print out contents of our
    // stack, which can lead to e.g. password leaks.
    //
    // Note: Compilers often detect such situations and print out warnings.
    printf(line);

    vertical_padding();


    printf("Printing a user-provided string using puts: ");

    puts(line);

    subsection_end();
}


void terminator() {
    subsection_start(__func__);

    char sensitive_data[] = "password 123";

    // Unterminated strings often result in some kind of out-of-bounds read or write
    // This can lead to unpredictable behaviour and unpleasant bugs
    // Always make sure to terminate your strings
    //
    // Note: Whether any extra data will be printed cannot be determined easily
    //       This all depends on your architecture, your compiler, which optimizations
    //       you enabled, ...
    //       Without optimizations and when using GCC, this code will leak the password
    //       stored in the array above. However, changing the size of the array
    //       (even if the string remains the same), adding new variables, etc. can influence
    //       the layout of the stack and change what data gets leaked
    char unterminated[12] = { 'u', 'n', 't', 'e', 'r', 'm', 'i', 'n', 'a', 't', 'e', 'd' };
    printf("An unterminated string: \"%s\"\n", unterminated);

    // If nothing else, you could at least always set the very last byte of the buffer to zero
    unterminated[11] = 0;
    printf("A terminated string: \"%s\"\n", unterminated);

    (void)sensitive_data;

    subsection_end();
}


void heap_allocated_strings() {
    subsection_start(__func__);

    // You can allocate strings on the heap if necessary. Use malloc to allocate the array, and
    // don't forget to initialize the string. As per usual, prefer static arrays on the stack when
    // possible, but don't be afraid to use malloc when you actually need to.
    char* heap_str = (char*)malloc(1024 * sizeof(char));

    // If we don't have a good initial string, we can always set the first byte of the array to 0,
    // which will give us an empty string (i.e. there will be no characters before the terminator)
    //
    // Note: You may prefer to zero out the entire array instead of just the first byte
    //       due to safety reasons
    *heap_str = 0;

    // assign_str copies the contents of a source string into a destination buffer
    // You can skip the details for now, as this will be covered later
    void assign_str(char* dest, const char* src);

    // Don't forget C strings are just arrays. To modify arrays, we have to mutate them element by
    // element. You cannot just use = to assign, that would only change the address
    // stored in the heap_str variable and create a memory leak
    assign_str(heap_str, "A string allocated on the heap");
    printf("heap_str=\"%s\"\n", heap_str);

    free(heap_str);


    subsection_end();
}


void string_literals() {
    subsection_start(__func__);

    // As you now know, you can create local static arrays and initialize them using
    // a string literal
    char local_string[100] = "Local string stored in a static array on the stack";
    (void)local_string;

    // However, if you don't plan to modify the string in any way, you don't actually
    // have to create a local array to store the data.
    //
    // You can actually create pointers to strings located in the read-only section of your program
    const char* ro_string1 = "Read-only string";
    printf("ro_string1=\"%s\"\n", ro_string1);

    // Attempting to modify any data stored in the read-only section results in a segmentation
    // violation
    puts("Warning: If the program crashes now, you didn't go through the source code thouroughly and forgot to fix the code.");

    char* ro_string2 = "Read-only string. The program will crash if you don't comment out the following line.";

    ro_string2[5] = 'O';

    // Suppress unused variable warning that should pop-up after you comment out/delete
    // the previous line of code
    (void)ro_string2;

    // Pointers to strings found in read-only memory can be safely returned from functions, because
    // they will outlive any frame on the stack. Lifetime of strings in the read-only section
    // is not limited the way lifetime of local arrays is.

    subsection_end();
}


/**********************************************/
/*                                            */
/*              String Operations             */
/*                                            */
/**********************************************/


void pointer_mutation();
void custom_print();
void pointers_into_larger_strings();
void iterating_over_strings();
void comparing_strings();
void string_lengths();
void suffixes_and_prefixes();
void string_mutation();
void concatenating_strings();
void character_lookup_in_strings();
void substring_lookup_in_strings();


void string_operations() {
    section_start("String Operations");


    // How modifying the pointer to the array doesn't modify the actual array
    // How to avoid mistakes which stem from modifying pointers instead of the data they point to
    pointer_mutation();

    // A simple excercise where you can implement your own print function (without formatting)
    custom_print();

    // How to traverse a string using for loops
    iterating_over_strings();

    // How we can actually use pointer arithmetics to our advantage and process only smaller
    // parts of large strings
    pointers_into_larger_strings();

    // How to properly compare strings 
    comparing_strings();

    // How to compute the length of a string
    string_lengths();

    // A practical example of how we can use our newfound knowledge to process string suffixes
    // and prefixes easily using just the standard library
    //
    // Note: This knowledge is not limited to suffixes and prefixes and can be applied in many
    //       other situations
    suffixes_and_prefixes();

    // How to properly mutate strings
    string_mutation();

    // How to concatenate strings
    concatenating_strings();

    // How to search for characters in strings
    character_lookup_in_strings();

    // How to search for substrings in strings
    substring_lookup_in_strings();


    section_end();
}


void pointer_mutation() {
    subsection_start(__func__);


    // Let us remember once again that in C, strings are just arrays of characters ended with
    // a null byte
    // Therefore, all string operations have to be performed character by character
    // There is little we can accomplish by modifying the pointer to the array

    // We can create pointers that point into the original buffer, but any sort of modification
    // to the pointer will have no effect on the underlying data
    char triangle[100] = "triangle";

    // We have multiple pointers to the same data. Modifying the pointers, however, doesn't 
    // modify the data in any way.
    char* string_ptr = triangle;
    for (; *string_ptr != 0; ++string_ptr) {
        puts(string_ptr);
    }
    string_ptr = "new_string";
    // Regardless of what operations we performed earlier, we only modified pointers
    // We never modified any of the underlying data, so the original string remains the same
    printf("Original string: \"%s\"\n", triangle);


    // This may not have looked like a major issue with a stack allocated string
    // However, with strings allocated on the heap, this can lead to memory leaks, because we lose
    // pointers to the allocated memory.
    char* string_on_heap = (char*)malloc(100 * sizeof(char));

    string_on_heap[0] = 'V';
    string_on_heap[1] = 'S';
    string_on_heap[2] = 'B';
    string_on_heap[3] = 0;

    // Store original pointer so we don't leak memory
    char* ptr_copy = string_on_heap;

    printf("string_on_heap [address=%p] before mutating pointers: %s\n", string_on_heap, string_on_heap);
    printf("ptr_copy       [address=%p] before mutating pointers: %s\n", ptr_copy, ptr_copy);

    // WARNING: The following line only mutates the pointer.
    string_on_heap = "new value";

    // If we print out the data again, we can see that while we changed the address string_on_heap
    // points to, the actual data remained unchanged
    // No copies of the original pointer will ever reflect the fact that an independent pointer
    // was ever mutated
    printf("string_on_heap [address=%p] after mutating pointers: %s\n", string_on_heap, string_on_heap);
    printf("ptr_copy       [address=%p] after mutating pointers: %s\n", ptr_copy, ptr_copy);

    free(ptr_copy);


    subsection_end();
}


void custom_print() {
    subsection_start(__func__);


    // Exercise: Create your own implementation of puts
    //           Find the incomplete implementation of print_str in this file and finish it
    void print_str(const char* str);

    printf("A string printed out with our own print_str function: ");
    print_str("If you're seeing this, print_str probably works as intended.");


    subsection_end();
}


void iterating_over_strings() {
    subsection_start(__func__);

    // We can traverse strings the same way we would traverse any other array
    // However, you have to make sure you never traverse beyond the terminator

    char vsbtuo[100] = "VSB-TUO";

    puts("Traversing string using numeric indices");
    vertical_padding();

    // To iterate over and process strings, we usually want to use a loop
    for (int i = 0; vsbtuo[i] != 0; ++i) {
        printf("[%d]='%c'\n", i, vsbtuo[i]);
    }

    vertical_padding();
    puts("Traversing string using pointer arithmetics");
    vertical_padding();

    // We can use indices or pointer arithmetics, both are perfectly fine,
    // though in some use-cases, one approach may be preferrable over the other
    for (char* ptr = vsbtuo; *ptr != 0; ++ptr) {
        // Note: Pointer subtraction yields a value of type ptrdiff_t
        //       Use %td to properly format a value of type ptrdiff_t
        printf("[%td]='%c'\n", ptr - vsbtuo, *ptr);
    }

    vertical_padding();
    puts("Traversing string and checking for terminator despite being given a size");
    vertical_padding();

    // Even if someone gives you an incorrect length (by mistake or as a purposeful
    // overestimation), you should always look out for the terminator. Never venture beyond
    // the terminator, unless you have a very good reason to believe you're allowed to access
    // the memory (such as when you are appending to a string and you are absolutely sure
    // the allocated buffer is large enough to accomodate the longer string)
    int max_len = 100;
    for (int i = 0; i < max_len && vsbtuo[i] != 0; ++i) {
        printf("[%d]='%c'\n", i, vsbtuo[i]);
    }


    subsection_end();
}


void pointers_into_larger_strings() {
    subsection_start(__func__);

    // We have already learned that advancing pointers that point at a string has no effect
    // on the actual data and is a common source of bugs for beginners.

    // Still, this behaviour can be very useful, as we can create views into a larger string
    // and only process certain portions of the data, without the need to copy the contents
    // to a new buffer

    // Pointer to any string somewhere in memory
    const char* path = "path/abcd.txt";
    
    // If we advance the pointer properly, the pointer file will now point to the portion
    // of the string that contains only the name of the file, not the entire path
    // This gives us a way to access only the name of the file without actually allocating a new
    // buffer and copying any strings
    //
    // Note: In this example, we use hardcoded offsets that correspond to the lengths
    //       of the names in the specific path we're using. This is done to keep this example
    //       simple, ways to process complex strings such as paths algorithmically will be covered
    //       later
    const char* file = path + 5;
    const char* extension = file + 5;

    const char* base_path_view = path;
    const size_t base_path_view_size = 5;

    const char* stem_view = file;
    const int stem_view_size = 4;

    // As an exercise, we implement a function that prints out a portion of a string
    // all by ourselves
    // However, you should consider using printf formatting options in real applications
    void print_view(const char* view, const size_t size);

    printf("Path: %s\n", path);

    printf("Base path: ");
    print_view(base_path_view, base_path_view_size);
    printf("\n");

    // %.*s allows us to write at most a specified number of characters from the string
    // This allows us to only print a portion of the string
    printf("File: %s (stem=%.*s, extension=%s)\n", file, stem_view_size, stem_view, extension);


    subsection_end();
}


void comparing_strings() {
    subsection_start(__func__);


    // Be wary when comparing strings. Basic == will only yield in pointer comparison
    // To check whether two strings are identical, you have to check the contents of the array,
    // because you can have two matching strings in different places in memory
    const char* eq1 = "VSB";
    const char* eq2 = "VSB";
    const char* eq3 = "TUO";

    // Compilers will not create duplicates of data in read-only memory, so pointer equality
    // may work for literals
    if (eq1 == eq2) {
        puts("eq1 == eq2");
    }
    if (eq1 != eq3) {
        puts("eq1 != eq3");
    }

    char eq4[100] = "VSB";

    // However, the same will not apply to strings allocated on the stack using static arrays
    // or on the heap using malloc
    // We have two matching strings located in different places in memory, so pointer equality
    // will yield false
    if (eq1 == eq4) {
        puts("eq1 == eq4");
    } else {
        puts("eq1 != eq4");
    }

    // To check whether two strings are equal, we have to check not just their addresses, but also
    // their contents
    bool str_eq(const char* s1, const char* s2);

    if (str_eq(eq1, eq4)) {
        puts("[str_eq] eq1 and eq4 are equal strings");
    } else {
        puts("[str_eq] eq1 and eq4 are different strings");
    }

    // We can also use the strcmp function found in the standard library
    // However, strcmp compares the string alphabetically and tells us not only if
    // the strings are equal, but also which comes first in the alphabet
    // If the strings are equal, strcmp returns 0. Otherwise, strcmp returns a value >0 or <0
    // depending on which string comes first in an alphabetical ordering
    if (strcmp(eq1, eq4) == 0) {
        puts("[strcmp] eq1 and eq4 are equal strings");
    } else {
        puts("[strcmp] eq1 and eq4 are different strings");
    }

    // This may seem counterintuitive at first, but it's very useful when we want to sort strings
    // alphabetically

    size_t city_count = 5;
    size_t city_name_size = 100;
    char cities[5][100] = { "Ostrava", "Girona", "Barcelona", "Andorra la Vella", "Zaragoza" };

    // We're getting a bit ahead of ourselves here so feel free to skip this comment as well as
    // the upcoming line of code. All you need to know is that it sorts the cities alphabetically.
    //
    // qsort is a function from the standard library that allows us to sort an array
    // As its arguments, qsort requires address of the array, number of elements in the array,
    // size of one element of the array, and a pointer to a function used to compare the elements
    // Here, we can use strcmp to compare the strings alphabetically and sort the array of strings
    // as we need
    //
    // Note: This line wouldn't (without modification) work with
    //       an array of pointers (char* cities[5] or char** cities)
    //       Don't copy the code blindly unless you understand completely what is happening here
    qsort(cities, city_count, city_name_size, (int(*)(const void*, const void*))strcmp);

    // The cities should now be sorted alphabetically
    for (size_t i = 0; i < city_count; ++i) {
        // Note: Use %zu to properly format a value of type size_t (unsigned size)
        printf("[%zu]: %s\n", i, cities[i]);
    }


    subsection_end();
}


void string_lengths() {
    subsection_start(__func__);

    // So far, we have been able to avoid the need to know the length of a string. Oftentimes,
    // you don't need to know the length beforehand, you only need to traverse the string left
    // to right until you find a terminator.
    //
    // However, there are also many applications, where you have to know the length of the string
    // before you can process it properly.

    const char* ostrava = "Ostrava";
    const char* empty = "";

    // To figure out the length of a string, we have to traverse the entire string and count
    // the number of characters we iterate over before we encounter a terminator
    // You can implement this yourself as a programming exercise, but in real-world applications,
    // it's better to rely on strlen, a function from the standard library
    printf("[strlen] Size of \"%s\" is %zu\n", ostrava, strlen(ostrava));
    printf("[strlen] Size of \"%s\" is %zu\n", empty, strlen(empty));

    // Exercise: Create your own implementation of strlen
    //           Find the incomplete definition of the function in this file and finish it
    size_t string_length(const char* str);
    printf("[string_length] Size of \"%s\" is %zu\n", ostrava, string_length(ostrava));
    printf("[string_length] Size of \"%s\" is %zu\n", empty, string_length(empty));

    // To check if a string is empty, we don't have to compute its entire length
    // The string may be very long and traversing the entire string would be pointless
    // We only need to check the very first character of the string
    printf("String \"%s\" is%s empty\n", ostrava, (*ostrava == 0) ? "" : " not");
    printf("String \"%s\" is%s empty\n", empty, (*empty == 0) ? "" : " not");


    subsection_end();
}


void suffixes_and_prefixes() {
    subsection_start(__func__);

    // Now that we know how to figure out the length of the string, we can easily perform
    // certain operations using just pointer arithmetics and functions from the standard library,
    // that may have otherwise seemed non-trivial.
    //
    // Before we continue, look at the actual implementation of has_suffix. We can easily implement
    // this functionality with just addition, subtraction, and two functions from the standard
    // library. No loops or custom semi-complex algorithms required.
    bool has_suffix(const char* str, const char* suffix);

    char domain1[100] = "www.vsb.cz";
    char domain2[100] = "github.com";

    const char* checked_domain = domain1;

    if (has_suffix(checked_domain, ".cz")) {
        printf("Domain \"%s\" has a czech TLD\n", checked_domain);
    } else if (has_suffix(checked_domain, ".com")) {
        printf("Domain \"%s\" has an international commercial TLD\n", checked_domain);
    } else {
        printf("Domain \"%s\" has an unexpected TLD\n", checked_domain);
    }

    checked_domain = domain2;

    if (has_suffix(checked_domain, ".cz")) {
        printf("Domain \"%s\" has a czech TLD\n", checked_domain);
    } else if (has_suffix(checked_domain, ".com")) {
        printf("Domain \"%s\" has an international commercial TLD\n", checked_domain);
    } else {
        printf("Domain \"%s\" has an unexpected TLD\n", checked_domain);
    }

    // Checking any other part of the string (such as the prefix) isn't possible using just pointer
    // arithmetics. We can, however, use strncmp to compare at most n characters of the string.
    //
    // See the implementation of has_prefix for a practical demonstration
    bool has_prefix(const char* str, const char* prefix);

    const char* car = "BMW M4";
    printf("A %s is%s equiped with blinkers.\n", car, (has_prefix(car, "BMW")) ? " not" : "");

    car = "Mercedes-Benz A200L";
    printf("A %s is%s equiped with blinkers.\n", car, (has_prefix(car, "BMW")) ? " not" : "");


    // You can also combine pointer arithmetics (offset from the beginning) and strncmp (only check
    // a specified amount of characters, don't process until the very end) to check
    // any part of the string you want, not just the prefix and the suffix.


    subsection_end();
}


void string_mutation() {
    subsection_start(__func__);

    
    // By now, we know very well modifying a pointer does not affect the underlying data in any way
    //
    // To actually change the string, we have to dereference a pointer to the character
    // we want to change and then write a new value into the array
    char vsb[100] = "vsb";
    printf("Before: %s\n", vsb);
    vsb[0] = 'V';
    vsb[1] = 'S';
    vsb[2] = 'B';
    printf("After: %s\n", vsb);

    // To cut a string short, you can replace any character in the string with a terminator
    // You can ignore anything that may or may not come after the newly inserted terminator
    char vsbtuo[100] = "VSB-TUO";
    printf("Before: %s\n", vsbtuo);
    vsbtuo[3] = 0;
    printf("After: %s\n", vsbtuo);

    // Of course, manually changing every single character can be tedious and may lead to errors
    char string_to_overwrite[100] = "Very long string";

    printf("Unmodified string_to_overwrite=\"%s\"\n", string_to_overwrite);

    string_to_overwrite[0] = 'V';
    string_to_overwrite[1] = 'S';
    string_to_overwrite[2] = 'B';

    // Never forget the terminator
    // string_to_overwrite[3] = 0;

    printf("Incorrectly modified string_to_overwrite=\"%s\"\n", string_to_overwrite);

    // Of course, you probably want to use a loop for this
    // See the implementation of assign_str for details on how to copy the contents of a string
    void assign_str(char* dest, const char* src);

    assign_str(string_to_overwrite, "An even longer string");

    printf("Correctly modified string_to_overwrite=\"%s\"\n", string_to_overwrite);

    vertical_padding();

    // Better yet, we can use the strcpy function found in the standard library
    // We can use string literals, stack-allocated or heap-allocated strings as the source string
    // The destination string (first argument), of course, always has to be mutable
    //
    // Note: strcpy doesn't check the size of the allocated memory, it is your responsibility
    //       to ensure the source fits into the destination string 
    //
    // Note: strncpy can be used if you only want to copy a portion of the destination string
    char distro1[100] = "Ubuntu";
    char distro2[100] = "Debian";

    printf("distro1 before strcpy: %s\n", distro1);

    strcpy(distro1, distro2);
    printf("distro1 after first strcpy: %s\n", distro1);

    strcpy(distro1, "Arch Linux");
    printf("distro1 after second strcpy: %s\n", distro1);


    subsection_end();
}


void concatenating_strings() {
    subsection_start(__func__);


    // We can concatenate strings using the strcat function
    // Once again, you will have to make sure the destination buffer is large enough to accomodate
    // the modified string
    //
    // By now, you may be asking why strcat just doesn't create a new string instead of modifying
    // its first argument. That is because the C standard library doesn't want to do anything more
    // than absolutely necessary so you have maximum control over the program's performance
    // and memory usage. If it strcat allocated memory for you, you would lose control over how
    // the memory is allocated or where the memory is allocated. This would pose a significant
    // issue in cases, where you care about every detail regarding your code's behaviour.

    char vsb_buffer[100] = "VSB";
    strcat(vsb_buffer, "-TUO");
    printf("[strcat] vsb_buffer=\"%s\"\n", vsb_buffer);

    // Exercise: Create your own implementation of strcat
    //           Find the incomplete definition of the function in this file and finish it
    void concatenate(char* dest, const char* src);

    strcpy(vsb_buffer, "VSB");
    concatenate(vsb_buffer, "-TUO");

    printf("[concatenate] vsb_buffer=\"%s\"\n", vsb_buffer);

    // You can, of course, call strcat repeatedly as many times as you like, but make sure you
    // don't cause a write outside the bounds of the allocated memory
    //
    // Note: This is just a demonstration, for a shopping list you may want at least
    //       an array of strings, one string per item
    char shopping_list[256] = "";

    void append_to_shopping_list(char* list, const char* item);

    append_to_shopping_list(shopping_list, "Apple (5x)");
    append_to_shopping_list(shopping_list, "Banana (3x)");
    append_to_shopping_list(shopping_list, "Cocaine (5g)");
    append_to_shopping_list(shopping_list, "Milk (2l)");

    printf("My shopping list: %s\n", shopping_list);


    subsection_end();
}


void character_lookup_in_strings() {
    subsection_start(__func__);


    // It is also possible to search through strings using the standard library
    // To find the first occurence of a certain character, you can use strchr
    // strchr returns a pointer to the first occurence of the desired character,
    // or NULL if the character is not found
    // Note: You can also use strrchr to find the last occurence
    char university[100] = "VSB-TUO";

    char* dash = strchr(university, '-');

    if (dash != NULL) {
        printf("Dash was found in string \"%s\" on position %td\n", university, dash-university);
    } else {
        printf("No dash was found in string \"%s\"\n", university);
    }

    // Exercise: Create your own implementation of strchr
    //           Find the incomplete definition of the function in this file and finish it
    char* find_char(const char* str, char c);

    strcpy(university, "VSB-TUO");

    dash = find_char(university, '-');

    if (dash != NULL) {
        printf("[find_char] Dash was found in string \"%s\" on position %td\n", university, dash-university);
    } else {
        printf("[find_char] No dash was found in string \"%s\"\n", university);
    }

    // Because strchr returns a pointer to the character, not an index, it is a little bit easier
    // for us to traverse over all occurrences of a character in a string and possibly modify the
    // string
    //
    // See the definition of the function for more information
    void generate_variable_name(const char* description, char* dest);

    const char* var_description = "Maximum width of printed number.";
    char var_name[100] = "";
    generate_variable_name(var_description, var_name);
    printf( "For a variable described as \"%s\", we propose the identifier \"%s\"\n",
           var_description,
           var_name);

    // Note: Realistically, the name of the variable could be shorter while retaining its meaning,
    //       but this proposal would still be better than 'seru_histogramy_pojebane' and similar
    //       alternatives found in submitted coursework


    subsection_end();
}


void substring_lookup_in_strings() {
    subsection_start(__func__);


    // To find the first occurence of an entire string within a larger string, we can use the
    // function strstr provided by the standard library
    // strstr returns a pointer to the beginning of the first match

    const char* faculties = "EkF, FMT, FEI, FS";
    const char* searched = "FEI";
    const char* match = strstr(faculties, searched);

    if (match != NULL) {
        printf("Faculty \"%s\" found on index %td\n", searched, match - faculties);
    } else {
        printf("Faculty \"%s\" not found in list \"%s\"\n", searched, faculties);
    }

    // Exercise: Create your own implementation of strstr
    //           Find the incomplete definition of the function in this file and finish it
    char* find_substring(const char* haystack, const char* needle);

    match = find_substring(faculties, searched);

    if (match != NULL) {
        printf("[find_substring] Faculty \"%s\" found on index %td\n", searched, match - faculties);
    } else {
        printf("[find_substring] Faculty \"%s\" not found in list \"%s\"\n", searched, faculties);
    }


    // We will need to recreate our shopping list for the upcoming example
    char shopping_list[256] = "";

    void append_to_shopping_list(char* list, const char* item);

    append_to_shopping_list(shopping_list, "Apple (5x)");
    append_to_shopping_list(shopping_list, "Banana (3x)");
    append_to_shopping_list(shopping_list, "Cocaine (5g)");
    append_to_shopping_list(shopping_list, "Milk (2l)");

    // We can use strstr in more complex applications and creatively combine it with other
    // functions
    //
    // See the implementation of check_for_essentials for an example of a somewhat practical use
    // of strstr and strchr at the same time
    void check_for_essentials(
            const char* shopping_list, const char** essentials, size_t essentialItemCount);

    const char* essentials[3] = { "Porsche 911", "Cocaine", "Milk" };

    check_for_essentials(shopping_list, essentials, 3);

    // Of course, you don't only ever read data, sometimes you may want to modify it as well.
    // strstr cannot modify anything for us, but it makes it very easy to find and successively
    // overwrite anything we need
    //
    // See the implementation of censor_bad_words for more details
    void censor_bad_words(char* text);

    char text_message[] = "ktery kokot vymyslel ten ukol na kokotske histogramy a proc kurva nemuzeme v upr pouzivat windows";
    censor_bad_words(text_message);
    printf("Censored message: \"%s\"\n", text_message);


    subsection_end();
}



/**********************************************/
/*                                            */
/*               Parsing Strings              */
/*                                            */
/**********************************************/


void parsing_integers();
void parsing_floats();
void tokenizing_strings_basics();
void tokenizing_strings_advanced();
void formatted_scanning();


void parsing_strings() {
    section_start("Parsing Strings");

    // How to parse an integer from a string
    parsing_integers();

    // How to parse a floating point number from a string
    parsing_floats();

    // How to parse strings using the standard library. Simple, but limited
    formatted_scanning();

    // How to split strings on desired separators
    // A bit more complex than formatted scanning, but also more powerful
    // First we explain the basics of string tokenization using the standard library
    tokenizing_strings_basics();

    // Then we apply our newfound knowledge on a couple examples
    tokenizing_strings_advanced();

    section_end();
}


void parsing_integers() {
    subsection_start(__func__);

    // Converting a single digit to a number is straightforward and we've already covered it before
    // In its simplest form, converting a string to a number is only a little bit more complicated.
    // You have to repeat this process in a loop and build-up the number left to right. Should
    // you wish to make your parsing function smarter, and your life more difficult, you could
    // also add extra features, such as support for a sign character, support for separators
    // to make the numbers more readable, support for bases beyond base 10, etc...
    // However, this would just mean doing a lot of string manipulation, which is something we've
    // already covered
    //
    // So how do we convert the following strings to the numbers they are supposed to represent?
    
    const char* numbers[6] = {
        "1899",
        "  747   ",
        "   321abcd",
        "   +666abcd",
        "   -150abcd",
        "  VSB-TUO  "
    };
    
    // Fortunately, the C standard library is already shipped with functions capable of parsing
    // integers from strings.
    //
    // To parse an int, we use the function atoi (ascii to integer)
    // To parse a long, we use the function atol (ascii to long)
    //
    // Both of these functions accept a single string as their only argument and return the parsed
    // integer as their return value. Any whitespace at the beginning of the string is skipped.
    // Parsing stops after the first non-digit character is encountered. However, the number may
    // optionally start with a sign character (both positive ('+') and negative ('-') signs are
    // supported). If no number can be parsed (i.e. because the string does not start with
    // a number), zero is returned.


    for (int i = 0; i < 6; ++i) {
        printf("[atoi] Parsing string \"%s\"\n", numbers[i]);
        int parsed_number = atoi(numbers[i]);
        // Perform a few arithmetic operations just to prove that it is, in fact, a number
        printf(
                "[atoi] parsed_number = %d, parsed_number+28 = %d, parsed_number*2 = %d, parsed_number**2 = %d\n",
                parsed_number,
                parsed_number+28,
                parsed_number*2,
                parsed_number*parsed_number
                );
    }

    vertical_padding();

    // Exercise: Create your own implementation of atoi
    //           Find the incomplete implementation of parse_int in this file and finish it
    //
    //           Start by only parsing positive numbers. If you succeed, you can add extra
    //           functionality, such as the ability to skip whitespace at the start of the string,
    //           support for sign characters, support for separators that separate
    //           groups of digits (i.e. you can write 10000000 as 10_000_000 and the number
    //           will be parsed correctly), etc.
    int parse_int(const char* str);

    for (int i = 0; i < 6; ++i) {
        printf("[parse_int] Parsing string \"%s\"\n", numbers[i]);
        int parsed_number = atoi(numbers[i]);
        // Perform a few arithmetic operations just to prove that it is, in fact, a number
        printf(
                "[parse_int] parsed_number = %d, parsed_number+28 = %d, parsed_number*2 = %d, parsed_number**2 = %d\n",
                parsed_number,
                parsed_number+28,
                parsed_number*2,
                parsed_number*parsed_number
                );
    }

    subsection_end();
}


void parsing_floats() {
    subsection_start(__func__);

    // The process of parsing floating point numbers is similar to the process of parsing integers,
    // however, we now also need to watch out for a decimal point and any numbers that succeed it
    //
    // Once again, we don't have to implement the parsing logic ourselves, we can
    // rely on the standard library which is guaranteed to include the function atof
    // (ascii to float). atof accepts a single string, attempts to parse a floating point number
    // from the string, and returns the parsed number as a double precision float.
    //
    // The parsing rules are similar to atoi/atol, and if parsing fails, atof returns a 0. However,
    // unlike atoi/atol, atof also supports exponential notation, hexadecimal numbers, and
    // the special floating point values Infinity and NaN.
    //
    // You can read more about atof in the documentation


    const char* numbers[8] = {
        "1899",
        "  74.7   ",
        "   321e3",
        "   +6.66e2",
        "   -150e-2",
        "  infinity  ",
        "  nan  ",
        "  VSB-TUO  "
    };


    for (int i = 0; i < 8; ++i) {
        printf("[atof] Parsing string \"%s\"\n", numbers[i]);
        double parsed_number = atof(numbers[i]);
        // Perform a few arithmetic operations just to prove that it is, in fact, a number
        printf(
                "[atof] parsed_number = %.2f, parsed_number+28 = %.2f, parsed_number*2 = %.2f, parsed_number**2 = %.2f\n",
                parsed_number,
                parsed_number+28,
                parsed_number*2,
                parsed_number*parsed_number
                );
    }


    vertical_padding();


    // Exercise: Create your own implementation of atof
    //           Find the incomplete implementation of parse_float in this file and finish it
    //
    //           Once again, start with very simple parsing, improve the function as you go. Try
    //           to get as close as you can to atof.
    double parse_float(const char* str);


    for (int i = 0; i < 8; ++i) {
        printf("[parse_float] Parsing string \"%s\"\n", numbers[i]);
        double parsed_number = parse_float(numbers[i]);
        // Perform a few arithmetic operations just to prove that it is, in fact, a number
        printf(
                "[parse_float] parsed_number = %.2f, parsed_number+28 = %.2f, parsed_number*2 = %.2f, parsed_number**2 = %.2f\n",
                parsed_number,
                parsed_number+28,
                parsed_number*2,
                parsed_number*parsed_number
                );
    }

    subsection_end();
}


void formatted_scanning() {
    subsection_start(__func__);

    // To parse strings simply and readably, we can also use formatted scanning.
    // Surely you alread know the scanf function from the standard library, that allows you
    // to read formatted input from stdin. In C, it is possible to parse strings in the exact same
    // way using the function sscanf.

    char text[100] = "first  ignore  second \n int=12 \t float=3.1415 char=$";
    printf("Scanning: \"%s\"\n", text);

    char word1[100] = "";
    char word2[100] = "";
    int integer = 0;
    float real = 0;
    char character = 0;

    // sscanf works very much like scanf, but because it scans a string, you have to pass
    // the scanned string as the first argument
    //
    // You can use as many formatting sequences as you like. You can specify
    // the format of the input using all the formatting sequence options (such as input width),
    // and you can instruct sscanf to expect certain substrings and skip over them, such as the
    // word ignore and the keys/equal signs in the input string and input format.
    //
    // Note: sscanf ignores any whitespace and stops on the first whitespace character
    //       when reading strings
    sscanf(text, "%s ignore %s int=%d float=%f char=%c",
            word1, word2, &integer, &real, &character);

    printf("First word: \"%s\"\n", word1);
    printf("Second word: \"%s\"\n", word2);
    printf("Integer: %d\n", integer);
    printf("Float: %.4f\n", real);
    printf("Character: %c\n", character);

    vertical_padding();
    // WARNING: It is always your responsibility to make sure a string parsed using sscanf will
    //          fit into the specified buffer. You can limit the amount of characters sscanf reads,
    //          but never forget the terminator.

    char long_word[100] = "a_very_long_word_with_no_whitespace";
    char short_buffer[10] = "";

    printf("Scanning: \"%s\"\n", long_word);

    // short_buffer is 10 bytes long, therefore we can only read 9 chars, we have to leave space
    // for the terminator
    sscanf(long_word, "%9s", short_buffer);

    printf("Content of short_buffer is: \"%s\"\n", short_buffer);

    // Calling sscanf repeatedly on the same string has no effect. The original string remains
    // unchanged and sscanf always starts reading from the start of the string it receives
    //
    // This makes sscanf very easy to use, but a bit inflexible in some ways
    puts("Repeating sscanf on the same string");
    sscanf(long_word, "%9s", short_buffer);
    printf("Content of short_buffer is the same: \"%s\"\n", short_buffer);

    subsection_end();
}


void tokenizing_strings_basics() {
    subsection_start(__func__);

    // When working with strings, it is sometimes desirable to split the strings on predefined
    // separators. We should now be able to create at least a naive implementation of such
    // tokenization using functions such as strstr or strchr.
    //
    // Here, we will look at the strtok function from the standard library and go over examples
    // of using strtok to parse simple strings.
    //
    // Before we even start, you may already see an issue with the function strtok.
    // The number of tokens in the input string may be unknown ahead of time and theoretically
    // unlimited. So how does strtok return an unknown and theoretically unlimited
    // amount of strings? The obvious answer would be an array, but we already know the standard
    // library doesn't like allocating memory for the programmer.
    //
    // Let's look at the signature of strtok

    char* strtok(char* str, const char* delim);

    // strtok accepts the source string and a string of delimiters, that could be expected.
    // But it only returns a single char*, which would be the pointer to the next token it found
    // in the string. So how do we use it to process an entire string?
    //
    // When you want to tokenize a new string, you call strtok as you would expect and pass in
    // the string you wish to tokenize as the first argument. The second argument is a string of 
    // delimiters.
    //
    // WARNING: strtok tokenizes on any one of the characters from this string, not on a matching
    //          sequence of characters.
    //
    // strtok finds the first delimiter in the input string (possibly a terminator), and overwrites
    // the delimiter with a terminator, as if ending the input string earlier. Then, strtok
    // saves where it last ended in an internal state, and returns the beginning of the first
    // token, which would probably be the start of the input string.
    //
    // WARNING: strtok is destructive and will overwrite the string it's tokenizing. If you need
    //          the original, untokenized string, create a duplicate before calling strtok.
    //
    // If you want to continue parsing the same string, you then call strtok as many times as you
    // need while passing NULL as the first argument. Since strtok overwrote the original string,
    // if you tried to pass the pointer to the beginning of the array, strtok would just keep
    // returning the first token forever, never knowing when to stop, because you would always
    // reset the internal state of strtok. The delimiters can differ accross calls to strtok. 
    //
    // WARNING: Because of this internal state, strtok can only be used on one string at a time.
    //          You can't recursively call strtok, i.e. to use strtok to parse tokens
    //          returned by strtok, nor can you use strtok on multiple threads at the same time.
    //
    // If no other valid tokens can be found (you reached the end of the input string),
    // strtok returns NULL

    char faculties[100] = "FMT,FEI,EkF";
    const size_t orig_len = strlen(faculties);

    // Before we start, let's look at what the actual state of the faculties string is right now,
    // so we can see if/how the string was changed.

    printf("The state of faculties string before tokenization: ");
    for (size_t i = 0; i < orig_len+1; ++i) {
        if (faculties[i] != 0) {
            printf("'%c' ", faculties[i]);
        } else {
            printf("<NULL> ");
        }
    }
    puts("");

    char* faculty = strtok(faculties, ",");

    printf("First token returned by strtok is \"%s\"\n", faculty);

    // After the previous call to strtok, the state of the program will look like this
    //
    // faculties = "FMT\0FEI,EkF\0\0\0\0\0\0\0"
    //              ^    ^
    // faculty -----|    |
    //                   |
    // strtok memory ----|

    // We can then call strtok again, this time passing NULL as the first argument, so strtok
    // knows to continue where it left off

    faculty = strtok(NULL, ",");
    printf("Second token returned by strtok is \"%s\"\n", faculty);

    // Now the state of the program would look like this
    //
    // faculties = "FMT\0FEI\0EkF\0\0\0\0\0\0\0"
    //                   ^    ^
    // faculty ----------|    |
    //                        |
    // strtok memory ---------|
    
    // Finally, we can extract the last valid token

    faculty = strtok(NULL, ",");
    printf("Third token returned by strtok is \"%s\"\n", faculty);

    // The state of the program would change to something along the lines of this
    //
    // faculties = "FMT\0FEI\0EkF\0\0\0\0\0\0\0"
    //                        ^   ^
    // faculty ---------------|   |
    //                            |
    // strtok memory -------------|

    // Because strtok now knows it reached the end of the string, any subsequent calls to strtok
    // without specifying a new string to parse would cause strtok to return NULL
    
    faculty = strtok(NULL, ",");
    if (faculty != NULL) {
        printf("Fourth token returned by strtok is \"%s\"\n", faculty);
    } else {
        puts("No other faculty found, strtok returned NULL");
    }

    // Now that we have successfully finished parsing one string, we can move onto any other string
    // we may wish to parse

    // Before we end this example, let's look at what the actual state of the faculties string is

    printf("The state of faculties string after tokenization: ");
    for (size_t i = 0; i < orig_len+1; ++i) {
        if (faculties[i] != 0) {
            printf("'%c' ", faculties[i]);
        } else {
            printf("<NULL> ");
        }
    }
    puts("");

    subsection_end();
}


void tokenizing_strings_advanced() {
    subsection_start(__func__);

    // Since we know strtok will always return a valid pointer so long as it can find another
    // token, or always return NULL if no other token is found, we can easily use strtok in a loop
    // to parse a variable amount of tokens
    //
    // Feel free to add or remove other languages to the string and see how the loop will always
    // parse the string properly

    char languages[100] = "C;C++;Rust;Python;Kotlin;Scala;Haskell";
    printf("Tokenizing: %s\n", languages);

    int counter = 0;
    char* language = strtok(languages, ";");

    while (language != NULL) {
        // Process the token however we like
        printf("%d) %s\n", counter+1, language);

        // Increment counter and move on to the next token
        ++counter;
        language = strtok(NULL, ";");
    }

    vertical_padding();

    // You can specify as many delimiter as you'd like, but keep in mind strtok will match any one
    // of the delimiters from the string

    char inconsistent_str[100] = "abc;def,ghi\tjkl";
    printf("Tokenizing: %s\n", inconsistent_str);

    counter = 0;
    // The delimiters don't have to be ordered in any way
    char* tok = strtok(inconsistent_str, ", \t\n;");
    
    while (tok != NULL) {
        printf("%d) %s\n", counter+1, tok);

        ++counter;
        tok = strtok(NULL,  ", \t\n;");
    }

    vertical_padding();
    // You can change the delimiters however you like when using strtok
    // Imagine you have a line that starts with a key, followed by a space, and then
    // a list of comma separated values

    char key_list_line[100] = "allowed_ports 80,443,21";
    printf("Tokenizing: %s\n", key_list_line);

    char* key = strtok(key_list_line, " ");

    printf("Values for key '%s':\n", key);

    char* value = strtok(NULL, ",");

    while (value != NULL) {
        // Process the data
        int int_value = atoi(value);
        printf("    %d\n", int_value);

        value = strtok(NULL, ",");
    }

    vertical_padding();
    // You can alternate between delimiters as much as you'd like. If you have a fixed format,
    // you can switch the delimiters manually, by looping through an array, or any other way you
    // want.

    // Let's parse the La Liga table from the 2024/25 season. Each record contains the clubs name
    // and their total points tally after the season ended, separated by an equals sign. Records
    // are separated by semicolon.

    char key_val_pairs[100] = "Real Madrid CF=84;Atletico de Madrid=76;FC Barcelona=88;Athletic Club Bilbao=70";
    printf("Tokenizing: %s\n", key_val_pairs);

    char* winner = NULL;
    int max_points = -1;

    // Keep in mind, no matter how many times we mention strtok or how many times we actually call
    // strtok manually or with a loop, we always pass the pointer to the input string exactly once,
    // any other calls to strtok pass NULL

    // The team comes first, stops at '=' character
    char* team = strtok(key_val_pairs, "=");
    // The team is always followed by their total points tally, which is followed by another record
    // or the end of the string, hence the ";"
    char* points = strtok(NULL, ";");

    puts("La Liga 2024/25:");
    while (team != NULL && points != NULL) {
        // Process the data
        int int_points = atoi(points);
        printf("  * %s (%d points)\n", team, int_points);

        if (int_points > max_points) {
            max_points = int_points;
            // We can copy the string to a new buffer, or we can just keep a pointer
            // to the existing buffer if don't overwrite the data while we're using it
            winner = team;
        }

        // Again, next team in the list until the equals sign
        team = strtok(NULL, "=");
        // And their points tally until the next record or terminator is found
        points = strtok(NULL, ";");
    }

    printf("The winner of La Liga 2024/25 is %s\n", winner);

    vertical_padding();

    // You can also alternate between delimiters programatically based on what strtok has returned
    // earlier
    //
    // Let's try to parse and implement very simple mathematical operations
    //
    // All operations are separated by semicolons. Each operation includes the operations name,
    // followed by a space (' '), and then it's arguments. An operation cannot
    // consist of other operations.
    //
    // No extra whitespace beyond the mandatory spaces is allowed
    //
    //   set <var>=<int|var>              sets variable <var> to the specified
    //                                       * no whitespace is allowed around '='
    //                                       * variable names can only be one character long
    //                                       * assume only lowercase letters will ever be used
    //
    //   compute <int|var> op <int|var>   computes the result of the operation specified by
    //                                    the operator (+, -, *, /)
    //                                       * The operator must be surrounded by a space (' ')
    //                                         on both sides
    //
    //   print <int|var>                  prints the value on a single line
    //
    //
    //   $ will be a special variable that refers to the result of the last operation.
    //   This variable will be set automatically and is the only variable that can be used in set
    //   statements. set will never modify $. Assume $ never appears on the LHS of a set statement. 

    // Enough space for the alphabet + $
    int variables['z' - 'a' + 1] = { 0 };
    const int last_result_idx = 'z' - 'a';

    // Will parse a single operand a return it's value, whether it's a variable or a literal
    int get_operand_value(const char* operand, const int* variables);

    char math_operations[255] = "set a=5;print a;set b=4;compute a + b;print $;compute $ + 5;print $;compute 10 * b;print $;compute 1 + 1;set a=$; compute 2 + 2; set b=$; compute a * b; print $";
    printf("Tokenizing: %s\n", math_operations);

    const char* operation = strtok(math_operations, " ");

    // Just for prettier printing
    int print_count = 0;

    // Note: Preferrably you would split this up into multiple functions and keep it in a separate
    //       file, but because we have yet to cover some features that would allow us to break up
    //       the code nicely and to keep the example reasonably simple, we will keep it as is.
    //
    //       You can try to break it up as an exercise in your own time.
    while (operation != NULL) {
        if (strcmp(operation, "set") == 0) {
            // No whitespace, we're looking for a '='
            const char* lhs = strtok(NULL, "=");
            // End of the statement
            const char* rhs = strtok(NULL, ";");

            const char var = *lhs;

            const int value = get_operand_value(rhs, variables);

            variables[var - 'a'] = value;
        } else if (strcmp(operation, "print") == 0) {
            const char* arg = strtok(NULL, ";");

            int value = get_operand_value(arg, variables);

            // If the argument was a variable, print out variable name and equals sign
            // If the argument was a number, print nothing so we don't print out number=number
            const char* identifier = (isdigit(*arg)) ? "" : arg;
            const char* equals = (isdigit(*arg)) ? "" : "=";

            printf("[%d] %s%s%d\n", print_count + 1, identifier, equals, value);

            ++print_count;

        } else if (strcmp(operation, "compute") == 0) {
            // Keep in mind here we need to actually figure out the value of the operator
            // Everything is separated by a single space
            const char* lhs = strtok(NULL, " ");
            
            // We don't actually need the entire string, just the operator, which is a single
            // character, so we can just store the character immediately
            const char op  = *strtok(NULL, " ");

            // RHS goes until the next statement or end of string
            const char* rhs = strtok(NULL, ";");

            const int lhs_val = get_operand_value(lhs, variables);
            const int rhs_val = get_operand_value(rhs, variables);

            int compute_op(char op, int lhs, int rhs);
            const int res = compute_op(op, lhs_val, rhs_val);

            variables[last_result_idx] = res;
        }

        operation = strtok(NULL, " ");
    }


    subsection_end();
}


/**********************************************/
/*                                            */
/*         Reading Strings From stdin         */
/*                                            */
/**********************************************/


void reading_word_by_word();
void reading_line_by_line();


void reading_strings() {
    section_start("Reading Strings");

    // Reading strings word by word from the standard input
    reading_word_by_word();

    // Reading strings line by line
    reading_line_by_line();

    section_end();
}


void reading_word_by_word() {
    subsection_start(__func__);


    // Reading word by word can be accomplished using the scanf function. We've already covered
    // the basics of formatted input and you surely know scanf from before, so this subsection
    // will be very simple.

    char word[100] = "";

    // Print out a simple prompt so the user knows we're awaiting input
    printf("$> ");

    // Read anything you like from the standard input
    scanf("%s", word);

    printf("Read the word: \"%s\"\n", word);

    // WARNING: Once again, you have to make sure the input fits into the specified buffer.
    //          Limit the input size using formatting sequences if needed

    // Everything scanf reads from standard input is automatically discarded. Therefore you can
    // read whatever you want for as long as you want unless scanf fails

    char key[100] = "";
    char value[100] = "";

    // Print out a prompt
    printf("[expecting <key>=<value>] $> ");

    // scanf returns how many values it managed to scan properly. Since we're trying to read two
    // strings, scanf should return 2 on success and <2 on failure
    //
    // Pass in as many values as you like when running the program. When you're done, press CTRL+D
    // to send an EOF character (end of file) to signify the end of stdin or pass the data
    // in the wrong format to cause scanf to fail.
    //
    // Note: scanf ignores whitespace, therefore you can spread the key and value between multiple
    //       lines. Just pressing enter will not result in a scanf failure.
    //
    // Note: The '=' character has to be separated by whitespace, otherwise
    //       scanf will scan it as one string. Don't forget scanf doesn't stop until the first
    //       whitespace when reading strings.
    while (scanf("%s = %s", key, value) == 2) {

        printf("Received key: \"%s\", received value: \"%s\"\n", key, value);

        // Print out prompt again before scanning
        printf("[expecting <key>=<value>] $> ");
    }


    subsection_end();
}


void reading_line_by_line() {
    subsection_start(__func__);

    // While scanf is fairly simple to use, it is also a bit inflexible. Oftentimes you want to
    // actually read the input line by line and process each line by yourself with functions such
    // as strtok.
    //
    // To read a line from a file we can use the fgets function. Let's look at
    // the signature of fgets.

    char* fgets(char* str, int count, FILE* stream);

    // The first argument of fgets is the buffer where fgets will store the line.
    // 
    // The second argument is how many characters fgets can write, including the terminator.
    // Usually you will want to pass the size of the buffer from the first argument.
    //
    // The last argument is the input file fgets should read from. For now, we will only use stdin,
    // but you can open and read from other files as well.
    //
    // WARNING: If the buffer is too small to accomodate the entire line, fgets will stop reading
    //          once the buffer is full (once it has written count characters). This means you will
    //          not accidentally discard data, but if the buffer is too small, you can split lines
    //          unknowingly. This is a common cause of bugs.
    //
    // WARNING: fgets writes the entire line to the buffer, including end-of-line character
    //          sequences. Always make sure your buffer can accomodate not just the input line,
    //          but also the line separators and a terminator.

    // We want to read 100 characters from the input.
    // Our buffer also needs to include space for a line feed character and a space
    // for the terminator, which means two extra bytes
    //
    // Note: On obscure operating systems, you may need 103 characters to process CRLF line endings
    char buffer[102] = "";
    const int buffer_size = 102;

    // Print out a prompt
    printf("[input any text (100 chars max)] $> ");

    // Read until the end of the line or up to 101 characters, whichever comes first
    fgets(buffer, buffer_size, stdin);

    // Because fgets doesn't discard newline characters, we may want to trim the newline character
    // from the end of the string.
    //
    // newline would be the character on the very last index, so check for newline and remove it
    // if necessary
    size_t length = strlen(buffer);

    // If the last character is a line feed character, trim the string and update the length
    // variable accordingly
    //
    // If you want, you can keep the newline character at the end. There is no law forbidding it.
    // But you have to be mindful that your line contains a newline character. However, usually
    // it's better to remove the newline, and then create/add/print out all
    // newlines by yourself as needed. Don't forget fgets doesn't have to write a newline if the
    // file doesn't end with a newline or the entire line doesn't fit into the buffer.
    //
    if (length > 0 && buffer[length - 1] == '\n') {
        buffer[length - 1] = 0;
        --length;
    }

    printf("Received line \"%s\"\n", buffer);

    vertical_padding();

    // If we look at the signature of fgets again, we will see that fgets returns a char*

    char* fgets(char* str, int count, FILE* stream);

    // If fgets finished successfully, str is returned, i.e. the pointer we passed in
    //
    // If fgets failed (such as if we tried to read after the end of file was received),
    // fgets returns NULL
    //
    // Therefore, to read the entire input if we don't know it's length in lines, we only need to
    // call fgets in a loop until it returns NULL

    // Print out a prompt
    printf("[expecting,comma,separated,values] $> ");

    // Keep reading until fgets fails
    //
    // Once again, keep in mind the behaviour of fgets. Don't forget to check for newline
    // characters, etc.
    //
    // Write as many lines as you want. Once you're done, press CTRL+D to send an EOF cause
    // fgets to fail 
    //
    while (fgets(buffer, buffer_size, stdin) != NULL) {

        // Process data any way you desire. Such as using strtok, but you already know
        // how to do that
        //
        // WARNING: If you run the code, you will notice the program prints out an extra
        //          empty line. That is because we don't trim the end of the string.
        //
        int counter = 0;
        char* tok = strtok(buffer, ",");

        while (tok != NULL) {
            printf("[%d] %s\n", counter+1, tok);

            ++counter;
            tok = strtok(NULL, ",");
        }

        // Prompt before reading again
        printf("[expecting,comma,separated,values] $> ");
    }

    // WARNING: Don't mix scanf and fgets at the same time. scanf can leave unprocessed characters,
    //          including newlines or whitespace, in the input file, and cause fgets to read empty
    //          lines or any other scanf leftovers.
    //
    //          If you really want to use formatted input, read the entire line using fgets first,
    //          then process the line using sscanf. If you cannot use scanf, process the line
    //          manually.


    subsection_end();
}


/*************************************************************************************************/
/*                                                                                               */
/*                                                                                               */
/*                                    Function Implementations                                   */
/*                                                                                               */
/*                                                                                               */
/*************************************************************************************************/


/**********************************************/
/*                                            */
/*                 Characters                 */
/*                                            */
/**********************************************/


// Nothing here as of now


/**********************************************/
/*                                            */
/*                String Basics               */
/*                                            */
/**********************************************/


void readline(char* dest, int buffer_size) {
    printf("$> ");
    fgets(dest, buffer_size, stdin);

    size_t length = strlen(dest);
    // Trim newline characters from the input
    // Unix-like operating systems use only the LF character ('\n') to end a line, so you might
    // get away with only checking for '\n' on the last index in the string
    // However, certain obscure operating systems use CR ('\r') or CRLF ("\r\n") to mark the end
    // of a line
    if (dest[length - 1] == '\n' || dest[length - 1] == '\r') {
        dest[length - 1] = 0;
    }
    // Needed on Windows, not Linux, macOS or FreeBSD
    if (dest[length - 2] == '\r') {
        dest[length - 2] = 0;
    }
}


// Use pointer to const to declare that your function will never change the received data
// This will both make your function easier to use, as it's easier to see from the outside
// if the received data will be modified, but also stop you from making errors and modifying
// something that shouldn't be modified
void assign_str(char* dest, const char* src) {
    // Iterate over the two strings and copy character by character until we reach the very end
    // of the source string
    while (true) {
        *dest = *src;

        if (*dest == 0) {
            return;
        }

        ++dest;
        ++src;
    }
}


/**********************************************/
/*                                            */
/*              String Operations             */
/*                                            */
/**********************************************/


void print_view(const char* view, const size_t size) {
    // Continue until we reach the terminator or the argument-specified end of the view
    for (const char* const end = view+size; *view != 0 && view != end; ++view) {
        putchar(*view);
    }
}


bool str_eq(const char* s1, const char* s2) {
    // We check the address first, because we can't have two different strings at the same address
    if (s1 == s2) {
        return true;
    }
    // If the addresses differ, we have to check the contents of each string
    while (true) {
        if (*s1 != *s2) {
            return false;
        }

        if (*s1 == 0) {
            return true;
        }

        ++s1;
        ++s2;
    }
}


bool has_suffix(const char* str, const char* suffix) {

    const size_t len = strlen(str);
    const size_t suffix_len = strlen(suffix);

    if (suffix_len > len) {
        return false;
    }

    // We can create a new pointer that points to only the ending of our existing string
    const char* str_ending = str + len - suffix_len;

    // We can then compare the ending of our original string with the expected suffix
    // Of course, this only works for the end of the string, we cannot compare only the beginning
    // of the string this way as strcmp doesn't stop until it encounters a terminator
    return strcmp(str_ending, suffix) == 0;
}


bool has_prefix(const char* str, const char* prefix) {
    // We only check the length of the prefix
    return strncmp(str, prefix, strlen(prefix)) == 0;
}


void append_to_shopping_list(char* list, const char* item) {
    if (*list != 0) {
        strcat(list, ", ");
    }
    strcat(list, item);
}


void generate_variable_name(const char* description, char* dest) {
    strcpy(dest, description);


    // Not really the point of this demonstration, but to generate somewhat meaningful results,
    // we have to process the input in multiple ways
    size_t length = strlen(dest);

    // Convert all characters to lowercase
    for (size_t i = 0; i < length; ++i) {
        dest[i] = (char)tolower(dest[i]);
    }
    // If the input string ends with a period, trim the string
    if (dest[length-1] == '.') {
        --length;
        dest[length] = 0;
    }

    char* space = strchr(dest, ' ');

    while (space != NULL) {
        *space = '_';

        // We already checked this character and modified it accordingly, so we can skip over it
        ++space;

        // Pass the rest of the string to strchr and search again until no space is found
        // We only pass the portion of the string we haven't checked yet, there is not point
        // in passing in the start of the string and that no longer contains any spaces
        space = strchr(space, ' ');
    }
}


void check_for_essentials(
        const char* shopping_list,
        const char** essentials,
        size_t essentialItemCount
    ) {

    for (size_t i = 0; i < essentialItemCount; ++i) {
        // Search for the currently processed item.
        // We only need one occurence, we can ignore duplicates
        // The shopping list is not guaranteed to be ordered, so we check the entire string
        // left to right for every essential
        char* substring = strstr(shopping_list, essentials[i]);

        if (substring == NULL) {
            printf("WARNING: Missing essential item \"%s\"\n", essentials[i]);
        } else {
            // Find the comma that separates the current item from the next item on the list
            char* comma = strchr(substring, ',');

            // The rest is just printing out the result in a pretty manner
            printf("Essential item found in shopping list: ");

            if (comma == NULL) {
                // If no comma is found, we found the last element of the list and can print it out
                // directly
                puts(substring);
            } else {
                // If we found a comma, we only want to print out the current item and stop before
                // the next item in the list
                const int substr_len = (int)(comma - substring);
                printf("%*s\n", substr_len, substring);
            }
        }
    }
}


void censor_bad_words(char* text) {

    // Preferrably, the list would be passed as an argument
    const size_t number_of_bad_words = 4;

    const char* bad_words[] = {
        "kokot", "pica", "kurva", "windows"
    };

    // Lengths are precomputed so we don't have to call strlen in a loop constantly
    const size_t lengths[] = {
        strlen("kokot"), strlen("pica"), strlen("kurva"), strlen("windows")
    };

    for (size_t i = 0; i < number_of_bad_words; ++i) {
        const char* word = bad_words[i];
        const size_t word_len = lengths[i];

        char* match = strstr(text, word);
        while (match != NULL) {

            // We don't have to bother with indices or offsets since the beginning of the text,
            // because the pointer match points to the desired word already
            //
            // In fact, we don't even have to use a loop, we can just call a standard library
            // function that does it for us
            //
            // Note: memset will not check for or write terminators for you. Here, we can use it
            //       safely and easily because we never write outside the bounds of the string,
            //       we only modify already initialized non-null characters
            memset(match, '*', word_len);

            // Because one word can occur multiple times in the string, we have to keep checking
            // for the same word until strstr returns NULL
            // We can, once again, skip the part of the string we have already processed to speed
            // up the censoring algorithm
            match = strstr(match + word_len, word);
        }
    }
}


/**********************************************/
/*                                            */
/*               Parsing Strings              */
/*                                            */
/**********************************************/


int get_operand_value(const char* operand, const int* variables) {
    const int last_result_idx = 'z' - 'a';

    int value = 0;

    if (*operand == '$') {
        value = variables[last_result_idx];
    } else if (islower(*operand)) {
        value = variables[*operand - 'a'];
    } else {
        value = atoi(operand);
    }

    return value;
}


int compute_op(const char op, const int lhs, const int rhs) {
    int res = 0;

    if (op == '*') {
        res = lhs * rhs;
    } else if (op == '/') {
        res = lhs / rhs;
    } else if (op == '+') {
        res = lhs + rhs;
    } else if (op == '-') {
        res = lhs - rhs;
    } 

    return res;
}


/**********************************************/
/*                                            */
/*         Reading Strings From stdin         */
/*                                            */
/**********************************************/


// Nothing here for now


/*************************************************************************************************/
/*                                                                                               */
/*                                                                                               */
/*                                           Exercises                                           */
/*                                                                                               */
/*                                                                                               */
/*************************************************************************************************/


// Exercise: Implement this function yourself
void print_str(const char* str) {
    // Ignore 'unused parameter' warning
    (void)str;

    // You can use putchar to print out a single character
    // Keep this call as the last line of the function so print_str behaves like puts
    // and ends the line properly
    putchar('\n');
}

// Exercise: Implement this function yourself
size_t string_length(const char* str) {
    (void)str;
    return 0;
}

// Exercise: Implement this function yourself
void concatenate(char* dest, const char* src) {
    (void)dest;
    (void)src;
}

// Exercise: Implement this function yourself
//
// Note: This function has to accept a const char* so it can receive immutable strings
//       This function also has to return a char* (without the const) so the user of our
//       function can mutate the string as they wish in case the string is mutable
//
//       Our function will never mutate any data, therefore our function is using const correctly
//       It is the responsibility of the caller to know whether they can mutate data through
//       the pointer returned by find_char
//
//       This issue does not have a simple and straightforward solution in C so don't worry about
//       the loss of const somewhere along the way
char* find_char(const char* str, char c) {
    (void)str;
    (void)c;
    return NULL;
}

// Exercise: Implement this function yourself
//
// Note: Same issue with pointers to const as with find_char
//       See find_char for more details
char* find_substring(const char* haystack, const char* needle) {
    (void)haystack;
    (void)needle;
    return NULL;
}

// Exercise: Implement this function yourself
int parse_int(const char* str) {
    (void)str;
    return 0;
}


// Exercise: Implement this function yourself
double parse_float(const char* str) {
    (void)str;
    return 0.0;
}


/*************************************************************************************************/
/*                                                                                               */
/*                                                                                               */
/*                                       Helper Functions                                        */
/*                                                                                               */
/*                                                                                               */
/*************************************************************************************************/

// This section is dedicated to helper functions that simplify the organization
// into sections for me
//
// You should be able to understand the following functions easily now, so feel free to read them,
// if you so desire


void vertical_padding() {
    puts("");
}


void repeat_char(char c, size_t count) {
    for (size_t i = 0; i < count; ++i) {
        putchar(c);
    }
}


static const size_t section_sep_width = 80;
static const size_t section_sep_height = 9;
static const size_t section_edge_width = 2;
static const char section_sep_char = '*';


void section_full_line() {
    repeat_char(section_sep_char, section_sep_width);
    putchar('\n');
}


void section_empty_line() {
    repeat_char(section_sep_char, section_edge_width);
    repeat_char(' ', section_sep_width - 2*section_edge_width);
    repeat_char(section_sep_char, section_edge_width);
    putchar('\n');
}


void section_horizontal_edge() {
    for (size_t i = 0; i < section_edge_width; ++i) {
        section_full_line();
    }
}


void section_empty_half() {
    const size_t total_empty = section_sep_height - section_edge_width*2 - 1;

    const size_t lines = total_empty / 2;

    for (size_t i = 0; i < lines; ++i) {
        section_empty_line();
    }
}


void print_section_name(const char* section) {

    const size_t name_len = strlen(section);
    const size_t total_spaces = section_sep_width - name_len - section_edge_width*2;

    const size_t left_spaces = total_spaces / 2;
    const size_t right_spaces = total_spaces - left_spaces;

    repeat_char(section_sep_char, section_edge_width);
    repeat_char(' ', left_spaces);
    printf("%s", section);
    repeat_char(' ', right_spaces);
    repeat_char(section_sep_char, section_edge_width);

    putchar('\n');
}


void section_start(const char* section) {
    vertical_padding();

    section_horizontal_edge();
    section_empty_half();

    print_section_name(section);

    section_empty_half();
    section_horizontal_edge();

    vertical_padding();
}


void section_end() {
    vertical_padding();

    section_horizontal_edge();

    vertical_padding();
}


static const size_t subsection_sep_width = 50;
static const char subsection_sep_char = '-';


void print_subsection_name(
        const char* subsection,
        const size_t left_chars,
        const size_t right_chars,
        const size_t space_padding
    ) {

    repeat_char(subsection_sep_char, left_chars);
    repeat_char(' ', space_padding);

    printf("%s()", subsection);

    repeat_char(' ', space_padding);
    repeat_char(subsection_sep_char, right_chars);

    putchar('\n');
}


void subsection_start(const char* subsection) {
    vertical_padding();

    const size_t fn_len = strlen(subsection);
    const size_t parens = 2;
    const size_t space_padding = 1;

    const size_t total_sep_chars = subsection_sep_width - fn_len - parens - 2*space_padding;

    const size_t left_chars = total_sep_chars / 2;
    const size_t right_chars = total_sep_chars - left_chars;
    
    print_subsection_name(subsection, left_chars, right_chars, space_padding);

    vertical_padding();
}


void subsection_end() {
    vertical_padding();

    repeat_char(subsection_sep_char, subsection_sep_width);
    putchar('\n');

    vertical_padding();
}

