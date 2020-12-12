# c-vs-cpp
### Time to settle this.

## Test 1: STDOUT
C Code:
```c
for(i = 0; i < 100000; i++)
{
  printf("%d\n", i);
}
```

C++ Code:
```cpp
for(i = 0; i < 100000; i++)
{
  // If I remember correctly, appending \n is faster than endl but whatever
  std::cout << i << std::endl;
}
```

Time comparison:
```
C: Average 0.332341 seconds
C++: Average 0.516324 seconds
```
### C is the victor

## Test 2: String concatenation
C Code:
```c
char test1[40] = "Hello ";
char test2[40] = "World!";
// If I remember correctly, strcat is actually unoptimized and there is a better alternative lol
strcat(test1, test2);
```

C++ Code:
```cpp
std::string test1 = "Hello ";
std::string test2 = "World!";
test1 += test2;
```

Time comparison:
```
C: Average 0.0000015 seconds
C++: Average 0.0000040 seconds
```
### C is the victor

## Test 3: Dynamic array operations
C Code:
```c
int testArr_size = 50;
int *testArr = malloc(sizeof(*testArr) * testArr_size);
int value = 0; 
if (testArr){
  for (i = 0; i < testArr_size; i++)
  {
    testArr[i] = i;
  }
  value = testArr[25];
  free(testArr);
}
else
  printf("testArr failed to initialize!");
```


C++ Code (with Vectors):
```cpp
std::vector<int> testArr;
for(i = 0; i < 50; i++)
{
  testArr.push_back(i);
}
int value = testArr[25];
```

C++ Code (with dynamic arrays):
```cpp
int testArr_new_size = 50;
int *testArr_new = new(std::nothrow) int[testArr_new_size];
int value_new = 0;
if (testArr_new)
{
  for(i = 0; i < testArr_new_size; i++)
  {
    testArr_new[i] = i;
  }
  value_new = testArr_new[25];
  delete[] testArr_new;
}
else
  std::cout << "testArr_new initialize failed!" << std::endl; 
```

Time comparison:
```
C: Average 0.000003 seconds
C++ (with Vectors): Average 0.000011 seconds
C++ (with dynamic arrays): Average 0.000003 seconds
```
### If you use vectors, C is the clear winner.
### However if you use dynamic arrays with new and delete, it is a tie

## Conclusion
  After running the tests, I can conclude that C beats out C++, 3 to 1. If I have missed a test, 
or you would like to make a bold claim about C++, by all means, make an issue or pull request :D 
