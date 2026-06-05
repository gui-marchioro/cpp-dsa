# Class changes for Improvements in Memory Management

After basic linked list implementation improvements regarding memory management were implemented to follow RAII.

## RAII in C++ (Resource Acquisition Is Initialization)

**RAII** is a design principle where a resource’s lifetime is **tied to an object’s lifetime**.


### Core Idea

> Acquire the resource in the **constructor**  
> Release it in the **destructor**

### What counts as a “resource”?

* Dynamic memory (`new` / heap)
* File handles
* Sockets
* Mutex/locks
* Database connections

### Why RAII matters

* Prevents **memory leaks**
* Prevents **resource leaks**
* Ensures **exception safety**
* Makes ownership **explicit and predictable**

## Rule of Three

If a class manages resources (e.g., raw pointers), you must implement:

* Destructor
* Copy constructor
* Copy assignment operator

Prevents issues like **shallow copy, double delete, and memory leaks**.

## Rule of Five (C++11+)

Extends Rule of Three by adding:

* Move constructor
* Move assignment operator

Enables **efficient resource transfer (move semantics)** instead of expensive copies.

### Key Concept

* **Copy = duplicate resource**
* **Move = transfer ownership**

## Why These Rules Exist

Because raw resource management (e.g., `new`/`delete`) requires you to define:

* How resources are **copied**
* How they are **transferred**
* How they are **cleaned up**

## Smart Pointers (Modern C++)

Smart pointers **eliminate the need** to manually implement these rules:

* `std::unique_ptr` → exclusive ownership (move-only)
* `std::shared_ptr` → shared ownership (reference counted)
* `std::weak_ptr` → non-owning reference

They:

* Automatically manage destruction (RAII)
* Provide correct copy/move behavior
* Prevent memory errors

## Final Takeaway

> The Rule of Five is about **manual resource management**  
> Smart pointers let you **avoid it entirely**


## Practical Guideline

* Using raw pointers → apply Rule of Five
* Using smart pointers / STL → **no Rule of Five needed**
