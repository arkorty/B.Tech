# Problems

Here are 15 C programming questions focused on string manipulation, structs, unions, dynamic allocation, and linked lists:

### **String Manipulation:**

1. Write a function to reverse a given string in place.
2. Write a function that checks if a string is a palindrome.
3. Write a function to find the first non-repeating character in a string.
4. Write a function to remove all spaces from a string.
5. Write a function to find the longest word in a given string.

### **Structs:**

6. Define a `Student` struct and write a function to print the details of a student.
7. Write a function that sorts an array of `Employee` structs by salary.
8. Create a `Date` struct and write a function to calculate the difference between two dates.

### **Unions:**

9. Define a union that can store an `int`, `float`, or `char`. Write a program to demonstrate accessing different members.
10. Write a program that uses a union to store either a `double` or a string, and print the correct value based on the data type.

### **Dynamic Memory Allocation:**

11. Write a function to dynamically allocate memory for an array of integers and initialize it with random values.
12. Write a function to concatenate two dynamically allocated strings.
13. Write a function to create a dynamic 2D array and initialize it with zeroes.

### **Linked Lists:**

14. Write a function to insert a node at the end of a singly linked list.
15. Write a function to reverse a singly linked list.

These questions will help cover various key concepts in C programming!

# Dynamic Memory Allocation & Data Structures

---

### **1. Pointer Swap**

**Example:**

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
```

---

### **2. Reverse an Array**

**Example:**

```c
#include <stdio.h>

void reverse(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    reverse(arr, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

---

### **3. Find the Largest Element Using Pointers**

**Example:**

```c
#include <stdio.h>

int findMax(int *arr, int size) {
    int max = *arr;
    for (int i = 1; i < size; i++) {
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }
    return max;
}

int main() {
    int arr[5] = {10, 20, 5, 40, 30};
    printf("Max: %d\n", findMax(arr, 5));
    return 0;
}
```

---

### **4. Dynamic Memory Allocation for Arrays**

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", arr + i);
        sum += *(arr + i);
    }

    printf("Sum = %d\n", sum);

    free(arr);
    return 0;
}
```

---

### **5. Dynamic String Concatenation**

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str1 = (char *)malloc(50 * sizeof(char));
    char *str2 = (char *)malloc(50 * sizeof(char));

    if (str1 == NULL || str2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(str1, "Hello, ");
    strcpy(str2, "World!");

    strcat(str1, str2);

    printf("Concatenated String: %s\n", str1);

    free(str1);
    free(str2);
    return 0;
}
```

---

### **6. Structure to Store Student Data**

**Example:**

```c
#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main() {
    struct Student students[3] = {
        {"Alice", 20, 88.5},
        {"Bob", 21, 92.0},
        {"Charlie", 19, 85.0}
    };

    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d, Grade: %.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    return 0;
}
```

---

### **7. Calculate Distance Between Two Points**

**Example:**

```c
#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    struct Point p1 = {0.0, 0.0};
    struct Point p2 = {3.0, 4.0};

    printf("Distance: %.2f\n", calculateDistance(p1, p2));
    return 0;
}
```

---

### **8. Structure Array with Dynamic Memory Allocation**

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char name[50];
    int age;
    float salary;
};

int main() {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee *employees = (struct Employee *)malloc(n * sizeof(struct Employee));

    for (int i = 0; i < n; i++) {
        printf("Enter details for employee %d\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Age: ");
        scanf("%d", &employees[i].age);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    printf("Employee Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Age: %d, Salary: %.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    free(employees);
    return 0;
}
```

---

### **9. Create and Initialize a Union**

**Example:**

```c
#include <stdio.h>

union Number {
    int i;
    float f;
};

int main() {
    union Number num;

    num.i = 10;
    printf("Integer: %d\n", num.i);

    num.f = 3.14;
    printf("Float: %.2f\n", num.f);

    return 0;
}
```

---

### **10. Read and Write to a File Using Pointers**

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("numbers.txt", "r");
    if (!file) {
        printf("Could not open file\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", arr + i);
    }

    printf("Array elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    fclose(file);
    free(arr);
    return 0;
}
```

---

### **11. Copy a String Using Pointers**

**Example:**

```c
#include <stdio.h>

void strCopy(char *src, char *dest) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
}

int main() {
    char source[] = "Hello, World!";
    char destination[20];

    strCopy(source, destination);
    printf("Copied string: %s\n", destination);

    return 0;
}
```

---

### **12. Initialize and Access Union Members**

**Example:**

```c
#include <stdio.h>
#include <string.h>

union Data {
    float f;
    char str[20];
};

int main() {
    union Data data;

    strcpy(data.str, "Hello");
    printf("String: %s\n", data.str);

    data.f = 3.14;
    printf("Float: %.2f\n", data.f);

    return 0;
}
```

---

### **13. Pointer to Struct**

**Example:**

```c
#include <stdio.h>

struct Rectangle {
    int length;
    int width;
};

void modifyRectangle(struct Rectangle *rect) {
    rect->length = 20;
    rect->width = 10;
}

int main() {
    struct Rectangle r = {5, 5};
    modifyRectangle(&r);
    printf("Length: %d, Width: %d\n", r.length, r.width);
    return 0;
}
```

---

### **14. Dynamic Matrix Allocation**

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter value for matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
```

---

### **15. Stack Implementation Using Arrays**

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 4

struct Stack {
    int data[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[s->top--];
}

int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));

    return 0;
}
```

---

### **17. Stack Implementation Using Linked List**

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Stack {
    struct Node *top;
};

void initStack(struct Stack *s) {
    s->top = NULL;
}

int isEmpty(struct Stack *s) {
    return s->top == NULL;
}

void push(struct Stack *s, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node *temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->top->data;
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));

    return 0;
}
```

---

### **18. Queue Implementation Using Arrays**

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue {
    int data[MAX];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = -1;
}

int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct Queue *q) {
    return q->front == -1;
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->data[++q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    displayQueue(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));

    displayQueue(&queue);

    return 0;
}
```

---

### **19. Queue Implementation Using Linked List**

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;
};

void initQueue(struct Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

void enqueue(struct Queue *q, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return value;
}

void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    displayQueue(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));

    displayQueue(&queue);
    return 0;
}
```

---

### **20. Singly Linked List: Insert and Display**

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

void initList(struct LinkedList *list) {
    list->head = NULL;
}

void insert(struct LinkedList *list, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

void displayList(struct LinkedList *list) {
    struct Node *temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkedList list;
    initList(&list);

    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 30);

    displayList(&list);

    return 0;
}
```

---

### **21. Singly Linked List: Delete a Node**

**Example:**

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

void initList(struct LinkedList *list) {
    list->head = NULL;
}

void insert(struct LinkedList *list, int value) {
    struct Node *
```
