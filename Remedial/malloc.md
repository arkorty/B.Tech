In C, dynamic memory allocation allows you to allocate memory during runtime using functions like `malloc`, `calloc`, `realloc`, and `free`. This is useful when you don’t know the exact amount of memory your program will need at compile-time.

### Key Functions:

- **`malloc(size_t size)`**: Allocates a block of memory of the specified size (in bytes) and returns a pointer to the beginning of the block. The contents of the block are uninitialized.
- **`free(void *ptr)`**: Frees the memory previously allocated by `malloc`, `calloc`, or `realloc`.

### Example of Dynamic Memory Allocation with `malloc`:

Let’s walk through a simple example using `malloc` and `free`.

```c
#include <stdio.h>
#include <stdlib.h>  // for malloc and free

int main() {
    // Dynamically allocate memory for one integer
    int *ptr = (int *)malloc(sizeof(int)); // Allocate memory

    if (ptr == NULL) {
        // Check if malloc succeeded
        printf("Memory allocation failed!\n");
        return 1; // Exit if allocation failed
    }

    *ptr = 42;  // Assign the value 42 to the allocated memory
    printf("Value: %d\n", *ptr);  // Access the value

    free(ptr);  // Free the allocated memory

    return 0;
}
```

### Memory Representation:

Let’s break down how memory looks before and after the `malloc` and `free` operations.

#### Step 1: Before `malloc`:

When you declare a pointer, it doesn’t point to any allocated memory yet.

```
ptr -> NULL
```

#### Step 2: After `malloc(sizeof(int))`:

```c
int *ptr = (int *)malloc(sizeof(int));
```

`malloc` allocates a block of memory, and `ptr` stores the address of the first byte of that block.

Assume `malloc` returns the address `3000`. The memory layout might look like this:

```
Memory Address | Value
---------------|------
     3000      | ????  <-- ptr (uninitialized memory)
```

Here, `ptr` holds the address `3000`, but the contents of the memory are uninitialized, hence `????`.

#### Step 3: Assigning a Value:

```c
*ptr = 42;
```

Now, we store the value `42` in the dynamically allocated memory.

```
Memory Address | Value
---------------|------
     3000      |  42   <-- *ptr (memory now contains the value 42)
```

#### Step 4: Freeing the Memory:

```c
free(ptr);
```

When you call `free(ptr)`, the memory at address `3000` is marked as available for future allocations. `ptr` itself is not changed, but the memory it points to is no longer valid to use. It’s a good practice to set `ptr` to `NULL` after freeing the memory to avoid dangling pointers.

```
ptr -> NULL
```

After calling `free(ptr)`, `ptr` still holds the value `3000`, but accessing `*ptr` is invalid.

### Common Mistakes with `malloc` and `free`:

1. **Memory Leaks**: If you don’t call `free()` after using `malloc()`, the allocated memory will not be released, leading to memory leaks.
2. **Double Free**: Freeing the same memory twice (e.g., calling `free(ptr)` multiple times) can cause undefined behavior.
3. **Dangling Pointer**: After freeing memory, the pointer still holds the old address. Dereferencing it after `free()` leads to undefined behavior. Always set the pointer to `NULL` after freeing.

```c
free(ptr);
ptr = NULL; // Avoid dangling pointer
```

### Allocating Memory for an Array:

You can dynamically allocate memory for arrays using `malloc` too.

```c
int *arr = (int *)malloc(5 * sizeof(int)); // Allocate memory for an array of 5 integers

if (arr == NULL) {
    // Handle memory allocation failure
}

for (int i = 0; i < 5; i++) {
    arr[i] = i + 1; // Initialize the array
}

free(arr); // Free the memory
arr = NULL;
```

#### Memory Representation for an Array:

```
Memory Address | Value
---------------|------
     3000      |  1
     3004      |  2
     3008      |  3
     3012      |  4
     3016      |  5
```

- Each integer takes 4 bytes (on most systems).
- The array `arr` points to the memory starting at address `3000`, with 5 consecutive integers allocated.

### Conclusion:

- `malloc` dynamically allocates memory at runtime, returning a pointer to the allocated memory.
- The allocated memory must be freed using `free()` to avoid memory leaks.
- Proper use of `malloc` and `free` ensures efficient memory management in C programs.
