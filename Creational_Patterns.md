# OOP Patterns

These patterns help address specific design challenges and promote reusable,maintainable, and
flexible code. It's important to choose the appropriate pattern based on the problem at hand and the
desired design goals.
***

## Creational Patterns

Creational patterns in object-oriented programming focus on the creation and instantiation of
objects. They provide flexible ways to create objects,decoupling the object creation process from
the client code.
***

### 1. Singleton

| Description                                                              |
|--------------------------------------------------------------------------|
| Ensures that only one instance of a class is created.                    |
| Provides global access to that instance.                                 |
| Useful when a single object needs to coordinate actions across a system. |
| Examples: Logger, Database connection.                                   |

[Code Example](link) :: [Code Example](link) :: [Code Example](link)


***

### 2.

| Description                                                                                            |
|--------------------------------------------------------------------------------------------------------|
| Defines an interface for creating objects, but allows subclasses to decide which class to instantiate. |
| Encapsulates the object creation logic in a separate method (the factory method).                      |
| Provides flexibility and extensibility for creating objects of different types.                        |
| Examples: Document creation in a word processing application, Shape creation in a drawing application. |

[Code Example](link)
***

### 3. Abstract Factory

| Description                                                                           |
|---------------------------------------------------------------------------------------|
| Provides an interface for creating families of related or dependent objects.          |
| Encapsulates the object creation logic for different product families.                |
| Supports creating objects with a consistent theme or across multiple platforms.       |
| Examples: GUI toolkit (creating buttons, windows, menus), Database abstraction layer. |

[Code Example](link)
***

### 4. Builder

| Description                                                                           |
|---------------------------------------------------------------------------------------|
| Separates the construction of a complex object from its representation.               |
| Allows the same construction process to create different representations.             |
| Provides step-by-step construction and configuration of an object.                    |
| Examples: Creating complex data structures, Object creation with optional parameters. |

[Code Example](link)

***

### 5. Prototype

| Description                                                                             |
|-----------------------------------------------------------------------------------------|
| Allows objects to be copied or cloned.                                                  |
| Provides a way to create new objects by duplicating existing ones.                      |
| Hides the complexity of creating new objects.                                           |
| Examples: Object copying in a game, Creating multiple instances of a document template. |

[Code Example](link)
***