# Problems

### **Dynamic Memory Allocation:**

1. Write a function to dynamically allocate memory for an array of chars and initialize it with random letters.

2. Write a function to concatenate two dynamically allocated strings.

3. Write a function to create a dynamic 2D array and initialize it with zeroes.

### **String Manipulation:**

1. Write a function to reverse a given string in place.
2. Write a function that checks if a string is a palindrome.
3. Write a function to find the first non-repeating character in a string.
4. Write a function to remove all spaces from a string.
5. Write a function to find the longest word in a given string.

### **Structs:**

1. Define a `Student` struct and write a function to print the details of a student.
2. Write a function that sorts an array of `Employee` structs by salary.
3. Create a `Date` struct and write a function to calculate the difference between two dates.

### **Unions:**

1. Define a union that can store an `int`, `float`, or `char`. Write a program to demonstrate accessing different members.
2. Write a program that uses a union to store either a `double` or a string, and print the correct value based on the data type.

### **Linked Lists:**

1. Write a function to insert a node at the end of a singly linked list.
2. Write a function to reverse a singly linked list.

# Solutions

### 1. Reverse a String In-Place

```c
#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    char str[] = "Hello, World!";
    reverseString(str);
    printf("%s\n", str); // Output: !dlroW ,olleH
    return 0;
}
```

### 2. Check if a String is a Palindrome

```c
#include <stdio.h>
#include <string.h>

int isPalindrome(const char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[] = "madam";
    printf("%s is %s\n", str, isPalindrome(str) ? "a palindrome" : "not a palindrome");
    return 0;
}
```

### 3. Find the First Non-Repeating Character

```c
#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(const char *str) {
    int count[256] = {0}; 
    for (int i = 0; str[i]; i++)
        count[(unsigned char)str[i]]++;

    for (int i = 0; str[i]; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }
    return '\0'; 
}

int main() {
    char str[] = "swiss";
    char result = firstNonRepeatingChar(str);
    if (result)
        printf("First non-repeating character is '%c'\n", result);
    else
        printf("No non-repeating character found\n");
    return 0;
}
```

### 4. Remove All Spaces from a String

```c
#include <stdio.h>

void removeSpaces(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[] = "Hello World";
    removeSpaces(str);
    printf("%s\n", str); // Output: HelloWorld
    return 0;
}
```

### 5. Find the Longest Word in a String

```c
#include <stdio.h>
#include <string.h>

void findLongestWord(const char *str, char *longest) {
    int maxLen = 0, len = 0;
    const char *start = str;
    const char *maxWord = NULL;

    while (*str) {
        if (*str != ' ') {
            len++;
        } else {
            if (len > maxLen) {
                maxLen = len;
                maxWord = start;
            }
            len = 0;
            start = str + 1;
        }
        str++;
    }
    if (len > maxLen) {
        maxLen = len;
        maxWord = start;
    }
    if (maxWord) {
        strncpy(longest, maxWord, maxLen);
        longest[maxLen] = '\0';
    }
}

int main() {
    char str[] = "Find the longest word in this sentence";
    char longest[50];
    findLongestWord(str, longest);
    printf("Longest word: %s\n", longest); // Output: sentence
    return 0;
}
```

### 6. Define a `Student` Struct and Print Details

```c
#include <stdio.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

void printStudentDetails(Student s) {
    printf("Name: %s, Age: %d, GPA: %.2f\n", s.name, s.age, s.gpa);
}

int main() {
    Student s = {"John Doe", 20, 3.5};
    printStudentDetails(s);
    return 0;
}
```

### 7. Sort an Array of `Employee` Structs by Salary

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    float salary;
} Employee;

void sortEmployees(Employee employees[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (employees[j].salary > employees[j + 1].salary) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

int main() {
    Employee employees[] = {
        {"Alice", 50000},
        {"Bob", 40000},
        {"Charlie", 45000}
    };
    int n = 3;

    sortEmployees(employees, n);

    for (int i = 0; i < n; i++) {
        printf("%s: %.2f\n", employees[i].name, employees[i].salary);
    }
    return 0;
}
```

### 8. `Date` Struct and Calculate Date Difference

```c
#include <stdio.h>

typedef struct {
    int day, month, year;
} Date;

int daysBetween(Date d1, Date d2) {
    int d1_total = d1.year * 365 + d1.month * 30 + d1.day;
    int d2_total = d2.year * 365 + d2.month * 30 + d2.day;
    return d2_total - d1_total;
}

int main() {
    Date d1 = {1, 1, 2020};
    Date d2 = {5, 5, 2021};
    printf("Difference: %d days\n", daysBetween(d1, d2));
    return 0;
}
```

### 9. Union to Store `int`, `float`, or `char`

```c
#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    data.i = 10;
    printf("int: %d\n", data.i);

    data.f = 220.5;
    printf("float: %.2f\n", data.f);

    data.c = 'A';
    printf("char: %c\n", data.c);

    return 0;
}
```

### 10. Union to Store `double` or `string`

```c
#include <stdio.h>
#include <string.h>

union Value {
    double d;
    char str[20];
};

int main() {
    union Value val;

    val.d = 123.456;
    printf("double: %.3f\n", val.d);

    strcpy(val.str, "Hello");
    printf("string: %s\n", val.str);

    return 0;
}
```

### 11. Dynamic Allocation for an Array of Integers

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* allocateAndInitialize(int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

int main() {
    srand(time(NULL));
    int n = 5;
    int *arr = allocateAndInitialize(n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
```

### 12. Concatenate Two Dynamically Allocated Strings

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenate(char *s1, char *s2) {
    char *result = (char*)malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main() {
    char *str1 = "Hello, ";
    char *str2 = "World!";
    char *result = concatenate(str1, str2);
    printf("%s\n", result);
    free(result);
    return 0;
}
```

### 13. Create a Dynamic 2D Array and Initialize it with Zeroes

```c
#include <stdio.h>
#include <stdlib.h>

int** create2DArray(int rows, int cols) {
    int **arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
    }
    return arr;
}

int


### 1. Reverse a String In-Place
```c
#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    char str[] = "Hello, World!";
    reverseString(str);
    printf("%s\n", str); // Output: !dlroW ,olleH
    return 0;
}
```

### 2. Check if a String is a Palindrome

```c
#include <stdio.h>
#include <string.h>

int isPalindrome(const char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[] = "madam";
    printf("%s is %s\n", str, isPalindrome(str) ? "a palindrome" : "not a palindrome");
    return 0;
}
```

### 3. Find the First Non-Repeating Character

```c
#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(const char *str) {
    int count[256] = {0}; 
    for (int i = 0; str[i]; i++)
        count[(unsigned char)str[i]]++;

    for (int i = 0; str[i]; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }
    return '\0'; 
}

int main() {
    char str[] = "swiss";
    char result = firstNonRepeatingChar(str);
    if (result)
        printf("First non-repeating character is '%c'\n", result);
    else
        printf("No non-repeating character found\n");
    return 0;
}
```

### 4. Remove All Spaces from a String

```c
#include <stdio.h>

void removeSpaces(char *str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char str[] = "Hello World";
    removeSpaces(str);
    printf("%s\n", str); // Output: HelloWorld
    return 0;
}
```

### 5. Find the Longest Word in a String

```c
#include <stdio.h>
#include <string.h>

void findLongestWord(const char *str, char *longest) {
    int maxLen = 0, len = 0;
    const char *start = str;
    const char *maxWord = NULL;

    while (*str) {
        if (*str != ' ') {
            len++;
        } else {
            if (len > maxLen) {
                maxLen = len;
                maxWord = start;
            }
            len = 0;
            start = str + 1;
        }
        str++;
    }
    if (len > maxLen) {
        maxLen = len;
        maxWord = start;
    }
    if (maxWord) {
        strncpy(longest, maxWord, maxLen);
        longest[maxLen] = '\0';
    }
}

int main() {
    char str[] = "Find the longest word in this sentence";
    char longest[50];
    findLongestWord(str, longest);
    printf("Longest word: %s\n", longest); // Output: sentence
    return 0;
}
```

### 6. Define a `Student` Struct and Print Details

```c
#include <stdio.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

void printStudentDetails(Student s) {
    printf("Name: %s, Age: %d, GPA: %.2f\n", s.name, s.age, s.gpa);
}

int main() {
    Student s = {"John Doe", 20, 3.5};
    printStudentDetails(s);
    return 0;
}
```

### 7. Sort an Array of `Employee` Structs by Salary

```c
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    float salary;
} Employee;

void sortEmployees(Employee employees[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (employees[j].salary > employees[j + 1].salary) {
                Employee temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

int main() {
    Employee employees[] = {
        {"Alice", 50000},
        {"Bob", 40000},
        {"Charlie", 45000}
    };
    int n = 3;

    sortEmployees(employees, n);

    for (int i = 0; i < n; i++) {
        printf("%s: %.2f\n", employees[i].name, employees[i].salary);
    }
    return 0;
}
```

### 8. `Date` Struct and Calculate Date Difference

```c
#include <stdio.h>

typedef struct {
    int day, month, year;
} Date;

int daysBetween(Date d1, Date d2) {
    int d1_total = d1.year * 365 + d1.month * 30 + d1.day;
    int d2_total = d2.year * 365 + d2.month * 30 + d2.day;
    return d2_total - d1_total;
}

int main() {
    Date d1 = {1, 1, 2020};
    Date d2 = {5, 5, 2021};
    printf("Difference: %d days\n", daysBetween(d1, d2));
    return 0;
}
```

### 9. Union to Store `int`, `float`, or `char`

```c
#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    data.i = 10;
    printf("int: %d\n", data.i);

    data.f = 220.5;
    printf("float: %.2f\n", data.f);

    data.c = 'A';
    printf("char: %c\n", data.c);

    return 0;
}
```

### 10. Union to Store `double` or `string`

```c
#include <stdio.h>
#include <string.h>

union Value {
    double d;
    char str[20];
};

int main() {
    union Value val;

    val.d = 123.456;
    printf("double: %.3f\n", val.d);

    strcpy(val.str, "Hello");
    printf("string: %s\n", val.str);

    return 0;
}
```

### 11. Dynamic Allocation for an Array of Integers

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* allocateAndInitialize(int n) {
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    return arr;
}

int main() {
    srand(time(NULL));
    int n = 5;
    int *arr = allocateAndInitialize(n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
```

### 12. Concatenate Two Dynamically Allocated Strings

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenate(char *s1, char *s2) {
    char *result = (char*)malloc(strlen(s1) + strlen(s2) + 1);
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main() {
    char *str1 = "Hello, ";
    char *str2 = "World!";
    char *result = concatenate(str1, str2);
    printf("%s\n", result);
    free(result);
    return 0;
}
```

### 13. Create a Dynamic 2D Array and Initialize it with Zeroes

```c
#include <stdio.h>
#include <stdlib.h>

int** create2DArray(int rows, int cols) {
    int **arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;  // Initialize with zeroes
        }
    }
    return arr;
}

void print2DArray(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void free2DArray(int **arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int rows = 3, cols = 4;
    int **arr = create2DArray(rows, cols);
    print2DArray(arr, rows, cols);
    free2DArray(arr);
    return 0;
}
```

### 14. Insert a Node at the End of a Singly Linked List

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printList(head);  // Output: 10 -> 20 -> 30 -> NULL

    return 0;
}
```

### 15. Reverse a Singly Linked List

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }
    return prev;  // New head of the reversed list
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Original List: ");
    printList(head);  // Output: 10 -> 20 -> 30 -> NULL

    head = reverseList(head);

    printf("Reversed List: ");
    printList(head);  // Output: 30 -> 20 -> 10 -> NULL

    return 0;
}
```
