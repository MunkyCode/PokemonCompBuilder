//
// Created by Toby Dragon on 9/4/18.
//

#ifndef COMP220LAB_TESTLIBRARY_H
#define COMP220LAB_TESTLIBRARY_H
void printAssertEquals(float expected, float actual);

/**
 * reports whether ints are equal or not
 * @param expected - the value you expect the actual value to be
 * @param actual - the actual value to test
 * @post prints only "pass" if the values are equal,
 *      Else it prints "FAIL" and their respective values
 */
void printAssertEquals(int expected, int actual);

/**
 * reports whether booleans are equal or not
 * @param expected - the value you expect the actual value to be
 * @param actual - the actual value to test
 * @post prints only "pass" if the values are equal,
 *      Else it prints "FAIL" and their respective values
 */
void printAssertEquals(bool expected, bool actual);

/**
 * reports whether strings are equal or not
 * @param expected - the value you expect the actual value to be
 * @param actual - the actual value to test
 * @post prints only "pass" if the values are equal,
 *      Else it prints "FAIL" and their respective values
 */
void printAssertEquals(std::string expected, std::string actual);

/*template<typename T, typename D>
void printAssertEquals(T expected, D actual){
    if(expected == actual){
        std::cout << "pass" << std::endl;
    }
    else {
        std::cout << "FAIL, expected: " << expected << "\tactual: " << actual << std::endl;
    }
}*/

/**
 * reports whether arrays are equal or not
 * @param expected - the value you expect the actual value to be
 * @param actual - the actual value to test
 * @post prints only "pass" if the values are equal,
 *      Else it prints "FAIL" and the number of array elements that were different
 */
void printAssertEquals(int* a1, int *a2, int size);

/**
 * reports whether arrays are equal or not
 * @param expected - the array you expect the actual value to be
 * @param actual - the actual array to test
 * @param size - the number of elements in the arrays to check
 * @post prints only "pass" if the arrays are equal,
 *      Else it prints "FAIL" and the number of values that are different
 */
void printAssertArrayEqual(int* expected, int* actual, int size);


#endif //COMP220LAB_TESTLIBRARY_H
