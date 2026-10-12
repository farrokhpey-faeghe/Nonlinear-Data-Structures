# EECS 2510 – Lab Session
## Constructor Overloading and Constructor Initializer Lists

**Course:** EECS 2510 – Non-Linear Data Structures  
**Semester:** Fall 2026  
**Topic:** Constructor Overloading and Constructor Initializer Lists

---

## 1. Lab Overview

In this lab, we will learn how constructors work in C++ and how they are used to initialize objects.

The main topics covered are:

- Default Constructors
- Parameterized Constructors
- Constructor Overloading
- Constructors with Default Parameter Values
- Constructor Initializer Lists

By the end of this lab, students should be able to understand how different constructors are called and how to initialize class members using constructor initializer lists.

---

## 2. What Is a Constructor?

A constructor is a special member function of a class that is automatically called when an object is created.

A constructor:

- Has the same name as the class.
- Does not have a return type.
- Is called automatically when an object is created.
- Is commonly used to initialize class data members.

### Example

```cpp
class Student
{
private:
    string name;
    int age;

public:
    Student()
    {
        name = "Unknown";
        age = 0;
    }
};
```

When we create an object:

```cpp
Student student1;
```

The constructor `Student()` is automatically called.

The object's initial values are:

```text
name = "Unknown"
age = 0
```

---

## 3. Constructor Overloading

Constructor overloading allows a class to have multiple constructors with different parameter lists.

C++ determines which constructor to call based on the arguments provided when the object is created.

### Example: Pet Class

```cpp
class Pet
{
public:
    Pet();
    Pet(string petName, int yearsOld);
    void Print();

private:
    string name;
    int age;
};
```

This class has two constructors.

### 3.1 Default Constructor

```cpp
Pet::Pet()
{
    name = "NoName";
    age = -1;
}
```

The default constructor is called when an object is created without arguments.

Example:

```cpp
Pet dog;
```

The values are:

```text
name = "NoName"
age = -1
```

### 3.2 Parameterized Constructor

```cpp
Pet::Pet(string petName, int yearsOld)
{
    name = petName;
    age = yearsOld;
}
```

This constructor is called when two arguments are provided.

Example:

```cpp
Pet cat("Nala", 3);
```

The values are:

```text
name = "Nala"
age = 3
```

### 3.3 How Does C++ Select a Constructor?

Consider:

```cpp
Pet dog;
Pet cat("Nala", 3);
```

| Object | Constructor Called | Result |
|---|---|---|
| `dog` | `Pet()` | NoName, -1 |
| `cat` | `Pet(string, int)` | Nala, 3 |

The compiler selects the appropriate constructor based on the provided arguments.

---

## 4. Problem 1 – Constructor Overloading

### Problem Description

Determine the output of the following program.

```cpp
#include <iostream>
#include <string>

using namespace std;

class Pet
{
public:
    Pet();
    Pet(string petName, int yearsOld);
    void Print();

private:
    string name;
    int age;
};

Pet::Pet()
{
    name = "NoName";
    age = -1;
}

Pet::Pet(string petName, int yearsOld)
{
    name = petName;
    age = yearsOld;
}

void Pet::Print()
{
    cout << name << ", " << age << endl;
}

int main()
{
    Pet dog;
    Pet cat("Nala", 3);

    dog.Print();
    cat.Print();

    return 0;
}
```

### Step-by-Step Explanation

**Step 1: Create the dog object**

```cpp
Pet dog;
```

The default constructor is called.

```text
dog.name = "NoName"
dog.age = -1
```

**Step 2: Create the cat object**

```cpp
Pet cat("Nala", 3);
```

The parameterized constructor is called.

```text
cat.name = "Nala"
cat.age = 3
```

**Step 3: Print the objects**

```cpp
dog.Print();
cat.Print();
```

The `Print()` function displays each object's name and age.

### Expected Output

```text
NoName, -1
Nala, 3
```

---

## 5. Constructors with Default Parameter Values

A constructor can also have default values for its parameters.

Example:

```cpp
Restaurant(string initName = "NoName",
           int initRating = -1);
```

This constructor can be called with or without arguments.

```cpp
Restaurant foodPlace;
Restaurant coffeePlace("Joes", 5);
```

For `foodPlace`, the default values are used:

```text
name = "NoName"
rating = -1
```

For `coffeePlace`, the supplied values are used:

```text
name = "Joes"
rating = 5
```

### Important Note

A constructor with default parameter values can serve as a default constructor if it can be called without arguments.

For example:

```cpp
Restaurant(string initName = "NoName",
           int initRating = -1);
```

This allows:

```cpp
Restaurant foodPlace;
```

---

## 6. Constructor Initializer Lists

A constructor initializer list provides another way to initialize class data members.

Instead of assigning values inside the constructor body, we can initialize members before the constructor body executes.

### Without an Initializer List

```cpp
SampleClass::SampleClass()
{
    field1 = 100;
    field2 = 200;
}
```

### With an Initializer List

```cpp
SampleClass::SampleClass()
    : field1(100), field2(200)
{
}
```

Both examples result in:

```text
field1 = 100
field2 = 200
```

### General Syntax

```cpp
ClassName::ClassName()
    : member1(value1),
      member2(value2)
{
}
```

### Understanding the Syntax

- The colon `:` begins the initializer list.
- Each data member is followed by its initialization value.
- Commas separate multiple member initializers.
- The constructor body `{}` can remain empty.

Initializer lists are especially useful when initializing `const` members, references, and class-type members.

---

## 7. Problem 2 – Constructor Initializer Lists

### Problem Description

Determine the output of the following program.

```cpp
#include <iostream>
#include <string>

using namespace std;

class Tutor
{
public:
    Tutor();
    void Print() const;

private:
    string name;
    string topic;
};

Tutor::Tutor()
    : name("NoName"), topic("NeedsTopic")
{
}

void Tutor::Print() const
{
    cout << name << " tutors " << topic << endl;
}

int main()
{
    Tutor myTutor;

    myTutor.Print();

    return 0;
}
```

### Step-by-Step Explanation

**Step 1: Create the Tutor object**

```cpp
Tutor myTutor;
```

This automatically calls:

```cpp
Tutor::Tutor()
```

**Step 2: Initialize the data members**

```cpp
Tutor::Tutor()
    : name("NoName"), topic("NeedsTopic")
{
}
```

The initializer list assigns the initial values:

```text
name = "NoName"
topic = "NeedsTopic"
```

**Step 3: Call the Print() function**

```cpp
myTutor.Print();
```

The function executes:

```cpp
cout << name << " tutors " << topic << endl;
```

### Expected Output

```text
NoName tutors NeedsTopic
```

### Important Note

The keyword `const` in:

```cpp
void Print() const;
```

means that this member function cannot modify the object's non-mutable data members.

---

## 8. Problem 3 – Applicant Constructor Initializer List

### Problem Description

Complete the default constructor of the `Applicant` class using a constructor initializer list.

The constructor must initialize:

| Data Member | Data Type | Initial Value |
|---|---|---|
| `name` | `string` | `"Unfilled"` |
| `experience` | `int` | `-1` |
| `fullTime` | `char` | `'-'` |

### Provided Class

```cpp
class Applicant
{
public:
    Applicant();

    void SetInformation(
        string newName,
        int newExperience,
        char newFullTime
    );

    void Print() const;

private:
    string name;
    int experience;
    char fullTime;
};
```

### Task

Complete the constructor:

```cpp
Applicant::Applicant() /* Your code goes here */
{
}
```

### Solution

```cpp
Applicant::Applicant()
    : name("Unfilled"),
      experience(-1),
      fullTime('-')
{
}
```

### Explanation

**1. Initialize name**

```cpp
name("Unfilled")
```

Initializes the `name` member to `"Unfilled"`.

**2. Initialize experience**

```cpp
experience(-1)
```

Initializes `experience` to `-1`.

**3. Initialize fullTime**

```cpp
fullTime('-')
```

Initializes `fullTime` to the character `'-'`.

Remember:

- Strings use double quotation marks: `"Unfilled"`
- Characters use single quotation marks: `'-'`
- Integers do not require quotation marks: `-1`

---

## 9. How Problem 3 Works

### Step 1: Create the Applicant Object

```cpp
Applicant myApplicant;
```

The default constructor automatically initializes the object.

Initial values:

```text
name = "Unfilled"
experience = -1
fullTime = '-'
```

### Step 2: Print the Default Values

```cpp
myApplicant.Print();
```

Output:

```text
Applicant: Unfilled, Experience: -1, Full Time: -
```

### Step 3: Read User Input

```cpp
cin >> newName;
cin >> newExperience;
cin >> newFullTime;
```

Example input:

```text
Jen 10 Y
```

The variables contain:

```text
newName = "Jen"
newExperience = 10
newFullTime = 'Y'
```

### Step 4: Update the Object

```cpp
myApplicant.SetInformation(
    newName,
    newExperience,
    newFullTime
);
```

The `SetInformation()` function updates the object's data members.

```cpp
void Applicant::SetInformation(
    string newName,
    int newExperience,
    char newFullTime
)
{
    name = newName;
    experience = newExperience;
    fullTime = newFullTime;
}
```

Updated values:

```text
name = "Jen"
experience = 10
fullTime = 'Y'
```

### Step 5: Print the Updated Values

```cpp
myApplicant.Print();
```

Output:

```text
Applicant: Jen, Experience: 10, Full Time: Y
```

---

## 10. Example Execution

### Input

```text
Jen 10 Y
```

### Expected Output

```text
Applicant: Unfilled, Experience: -1, Full Time: -
Applicant: Jen, Experience: 10, Full Time: Y
```

The first line displays the default constructor values.

The second line displays the updated applicant information.

---

## 11. Compile and Run

The complete solution is provided in:

`constructor_initializer_solution.cpp`

### Compile

Open a terminal in the directory containing the C++ file.

```bash
g++ -std=c++17 constructor_initializer_solution.cpp -o applicant
```

### Run

```bash
./applicant
```

### Enter Input

```text
Jen 10 Y
```

### Expected Result

```text
Applicant: Unfilled, Experience: -1, Full Time: -
Applicant: Jen, Experience: 10, Full Time: Y
```

---

## 12. Summary

| Concept | Description |
|---|---|
| Constructor | Automatically called when an object is created |
| Default Constructor | Can be called without arguments |
| Parameterized Constructor | Accepts arguments to initialize an object |
| Constructor Overloading | Defines multiple constructors with different parameter lists |
| Default Parameter Values | Allows parameters to use predefined values |
| Constructor Initializer List | Initializes class members before the constructor body |
| `Print() const` | Displays information without modifying the object |
| `SetInformation()` | Updates the object's data members |

---

## 13. Key Takeaways

After completing this lab, students should understand:

1. How constructors initialize objects.
2. The difference between default and parameterized constructors.
3. How constructor overloading works.
4. How constructors with default parameter values are used.
5. How to write constructor initializer lists.
6. How to initialize multiple private data members.
7. How constructor initialization differs from updating object values using member functions.

**Important:** Review constructor overloading and constructor initializer lists carefully. Understanding these topics will help with future C++ assignments and exam preparation.
