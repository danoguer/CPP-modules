# 📚 CPP MODULES 05-09: THEORY SUMMARY

---

## **CPP05 - EXCEPTIONS**

### **ex00: Mommy, when I grow up, I want to be a bureaucrat!**
**Concept:** Basic exception handling in C++
- Create a `Bureaucrat` class with grades (1-150, where 1 is highest)
- Grades outside range throw exceptions
- **Key Learning:** Custom exception classes, `std::exception`, `throw`, `try-catch`
- **Implementation:** Nested exception classes inherit from `std::exception`

### **ex01: Form up, maggots!**
**Concept:** Exception propagation between objects
- Create a `Form` class that can be signed by bureaucrats
- Forms have grade requirements to sign
- **Key Learning:** Object interaction with exceptions, validation logic
- **Implementation:** `beSigned()` method throws if bureaucrat's grade too low

### **ex02: No, you need form 28B, not 28C...**
**Concept:** Abstract classes and polymorphism with exceptions
- Create abstract `AForm` base class
- Implement 3 concrete forms: `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`
- Each has different sign/execute grade requirements and behaviors
- **Key Learning:** Pure virtual functions (`execute()`), inheritance hierarchies
- **Implementation:** Virtual destructor, abstract base prevents instantiation

### **ex03: At least this beats coffee-making**
**Concept:** Factory pattern
- Create `Intern` class that creates forms by name
- Maps string names to form construction
- **Key Learning:** Object creation abstraction, function pointers/switch statements
- **Implementation:** `makeForm()` returns pointer to new form or NULL

---

## **CPP06 - CASTS**

### **ex00: Conversion of scalar types**
**Concept:** Type conversion and casting in C++
- Static class `ScalarConverter` converts string literals to char/int/float/double
- Handle special values (nan, inf, -inf)
- Display all 4 types or "impossible/Non displayable"
- **Key Learning:** `static_cast`, type limits, special float values
- **Implementation:** Parse string, check ranges, format output

### **ex01: Serialization**
**Concept:** Pointer serialization using reinterpret_cast
- Static class `Serializer` with `serialize()` and `deserialize()`
- Convert pointer ↔ `uintptr_t`
- **Key Learning:** `reinterpret_cast`, pointer arithmetic, memory addresses
- **Implementation:** Raw pointer conversion without data manipulation

### **ex02: Identify real type**
**Concept:** Runtime type identification without typeid
- Classes A, B, C inherit from Base
- `identify(Base* p)` - uses `dynamic_cast` with pointers
- `identify(Base& p)` - uses `dynamic_cast` with references (exception-based)
- **Key Learning:** `dynamic_cast`, RTTI, exception handling for failed casts
- **Implementation:** Try casting to each type, catch `std::bad_cast`

---

## **CPP07 - TEMPLATES**

### **ex00: Start with a few functions**
**Concept:** Function templates
- Implement `swap()`, `min()`, `max()` as templates
- Work with any comparable type
- **Key Learning:** Template syntax, type inference, generic programming
- **Implementation:** `template <typename T>` functions

### **ex01: Iter**
**Concept:** Template functions with function pointers
- Implement `iter()` that applies function to array elements
- Takes array, length, and function pointer
- **Key Learning:** Template functions with callbacks, generic algorithms
- **Implementation:** `template <typename T>` with function parameter

### **ex02: Array**
**Concept:** Template classes
- Create `Array<T>` class template for dynamic arrays
- Implement subscript operator, size(), copy/assignment
- Throw exception on out-of-bounds access
- **Key Learning:** Class templates, RAII, operator overloading with templates
- **Implementation:** Dynamic memory allocation, deep copy in template context

---

## **CPP08 - STL CONTAINERS, ITERATORS, ALGORITHMS**

### **ex00: Easy find**
**Concept:** Template algorithms with STL containers
- Implement `easyfind()` that searches for int in any container
- Returns iterator or end()
- **Key Learning:** STL iterators, container independence, `std::find`
- **Implementation:** `template <typename T>` with `T::iterator`

### **ex01: Span**
**Concept:** STL vector wrapper with custom algorithms
- Class stores N integers, finds shortest/longest span
- Must handle large datasets (10,000+ elements)
- Add range of elements using iterators
- **Key Learning:** `std::vector`, sorting, iterator ranges, exception handling
- **Implementation:** `addRange(InputIterator begin, InputIterator end)`

### **ex02: Mutated abomination**
**Concept:** Container adaptation - making stack iterable
- `MutantStack` inherits from `std::stack`
- Add `begin()` and `end()` methods to expose iterators
- **Key Learning:** Container adapters, underlying container access (`c` member)
- **Implementation:** `typedef` for iterator type, access protected member

---

## **CPP09 - STL ADVANCED**

### **ex00: Bitcoin Exchange**
**Concept:** std::map for key-value database
- Parse CSV database (date → price)
- Process input file, calculate bitcoin values
- Handle invalid dates, negative values, too large numbers
- **Key Learning:** `std::map`, file I/O, date validation, `lower_bound()`
- **Implementation:** Map stores historical prices, find closest earlier date

### **ex01: Reverse Polish Notation**
**Concept:** std::stack for expression evaluation
- RPN calculator: "8 9 * 9 - 9 - 9 - 4 - 1 +" = 42
- Stack-based algorithm: operands push, operators pop-calculate-push
- **Key Learning:** `std::stack`, algorithm implementation, parsing
- **Implementation:** Iterate string, push numbers, apply operators

### **ex02: PmergeMe**
**Concept:** Complex sorting algorithm with performance comparison
- Ford-Johnson merge-insert sort
- Implement for both `std::vector` and `std::deque`
- Compare performance, display timing
- Uses Jacobsthal sequence for optimal insertion order
- **Key Learning:** Advanced algorithms, container performance, benchmarking
- **Implementation:** Pair sorting, main chain, pending elements, binary insertion

---

## **🎯 KEY CONCEPTS BY MODULE**

| Module | Main Topic | Core Skills |
|--------|-----------|-------------|
| **CPP05** | Exceptions | Custom exceptions, inheritance, error handling |
| **CPP06** | Casts | Type conversion, reinterpret_cast, dynamic_cast |
| **CPP07** | Templates | Generic programming, template functions/classes |
| **CPP08** | STL Basics | Containers, iterators, algorithms |
| **CPP09** | STL Advanced | Map, stack, complex algorithms, performance |

---

## **💡 PROGRESSION**

1. **CPP05:** Error handling foundation
2. **CPP06:** Understanding C++ type system
3. **CPP07:** Writing reusable generic code
4. **CPP08:** Using Standard Library effectively
5. **CPP09:** Advanced data structures and algorithms

Each module builds on previous concepts while introducing new paradigms essential for modern C++ development! 🚀
