#include <ctime>    // for CLOCK macros
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// Convert names of variable, function, method, type to String
// https://code.i-harness.com/ko-kr/q/33aded
#pragma region TO_STRING

#define VARIABLE_TO_STRING(Variable) (void(Variable), #Variable)

#define FUNCTION_TO_STRING(Function) (void(&Function), #Function)

#define METHOD_TO_STRING(ClassName,Method) (void(&ClassName::Method),#Method)

#define TYPE_TO_STRING(Type) (void(sizeof(Type)), #Type)

#pragma endregion

// If want to track some values of variables on console as if debugging,
// this helps you do that easily by providing on/off mode.

// Avoid duplicate declarations of variables (using extern)

#pragma region DEBUG

extern bool Rito_debugPrintFlag = false;


// Debug mode on/off
#define DEBUG_ON  Rito_debugPrintFlag = true;
#define DEBUG_OFF Rito_debugPrintFlag = false;

// Simple use
#define DEBUG_                            if(Rito_debugPrintFlag)

// Print a message and the value of a variable
#define DEBUG_VALUE(message, value)       if(Rito_debugPrintFlag) cout << "[ DEBUG ] _ " << message << " = " << value << endl;

// Print all the values of the array with the name of the array (line by line)
#define DEBUG_ARRAY(arrayName, arraySize) if(Rito_debugPrintFlag) FOR(Rito_tempIndex, arraySize) { cout << "[ DEBUG ] _ " << VARIABLE_TO_STRING(arrayName) << "[" << Rito_tempIndex << "] = " << arrayName[Rito_tempIndex] << endl; }

// Exception handleing - out of range
#define DEBUG_RANGE(index, start, end)  { assert( index >= start); assert (index < end); }
#define DEBUG_GRTRANGE(index, start)	assert(index > start)
#define DEBUG_LSTRANGE(index, end)		assert(index < end) 

#pragma endregion

#pragma region MIN&MAX

// The minimum value between two values
#define MIN2(a, b) (((a) < (b)) ? (a) : (b))

// The minimum value among three values
#define MIN3(a, b, c) ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

// The maximum value between two values
#define MAX2(a, b) (((a) > (b)) ? (a) : (b))

// The maximum value among three values
#define MAX3(a, b, c) ((a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))

#pragma endregion

// Input enter on console.
#define ENTER std::cout << std::endl;

// A simple using for FOR sentence
#pragma region FOR

#define FOR(var, a)          for(int var = 0;  var < a;  var++)
#define FOR_(var, a1, a2)    for(int var = a1; var < a2; var++)
#define FOR_REV(var, a2, a1) for(int var = a2; var >= a1; var--)

#define FOR_DOUBLE(var1, a, var2, b)             for(int var1 = 0;  var1 < a;  var1++) for(int var2 = 0;  var2 < b;  var2++)
#define FOR_DOUBLE_(var1, a1, a2, var2, b1, b2)  for(int var1 = a1; var1 < a2; var1++) for(int var2 = b1; var2 < b2; var2++)

#define FOR_TRIPPLE(var1, a, var2, b, var3, c)                  for(int var1 = 0;  var1 < a;  var1++) for(int var2 = 0;  var2 < b;  var2++) for(int var3 = 0;  var3 < c;  var3++)
#define FOR_TRIPPLE_(var1, a1, a2, var2, b1, b2, var3, c1, c2)  for(int var1 = a1; var1 < a2; var1++) for(int var2 = b1; var2 < b2; var2++) for(int var3 = c1; var3 < c2; var3++)

#pragma endregion


// Clock macros that allows to measure the time it takes
#pragma region CLOCK

#define CLOCK_INIT clock_t timeBegin, timeEnd;
#define CLOCK_BEGIN timeBegin = clock();
#define CLOCK_END timeEnd = clock();
#define CLOCK_GET (double)(timeEnd - timeBegin) / CLOCKS_PER_SEC
#define CLOCK_SHOW std::cout << "Time Taken : " << (double)(timeEnd - timeBegin) / CLOCKS_PER_SEC << "(sec)" << std::endl << std::endl;

#pragma endregion