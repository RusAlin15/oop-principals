# OOP Patterns

These patterns help address specific design challenges and promote reusable,
maintainable, and flexible code. It's important to choose the appropriate
pattern based on the problem at hand and the desired design goals.
***

## Structural Patterns

Structural patterns in object-oriented programming focus on organizing classes and objects to form
larger structures and relationships. They help to define how objects interact and compose to create
more complex systems.
***

### 1. Adapter

| Description |
|------|
| Converts the interface of a class into another interface that clients expect. |
| Allows incompatible classes to work together by providing a common interface.  |
| Examples: Adapting a third-party library, Converting data formats.  |

[Adapter](structural_examples/adapter.py)
***

### 2. Decorator

| Description |
|------|
| Dynamically adds additional behaviors or responsibilities to objects. |
| Wraps an object with one or more decorators to modify its behavior.  |
| Provides a flexible alternative to subclassing for extending functionality.  |
| Examples: Adding features to a text editor, Extending a UI component.     |

[Decorator](structural_examples/decorator.py)
***

### 3. Proxy

| Description |
|------|
| Provides a surrogate or placeholder for another object to control its access. |
| Acts as an intermediary to control or manage the interaction with the actual object.  |
| Examples: Caching expensive database queries, Implementing access control.  |

[Proxy](structural_examples/proxy.py)
***

### 4. Composite

| Description |
|------|
| Treats a group of objects as a single object. |
| Represents a hierarchy of objects in a tree-like structure.  |
| Allows clients to treat individual objects and compositions uniformly.  |
| Examples: Representing a file system, Building nested GUI components.     |

[Composite](structural_examples/composite.py)
***

### 5. Bridge

| Description |
|------|
| Decouples an abstraction from its implementation, allowing them to vary independently. |
| Provides a bridge between an abstraction and its implementation.  |
| Allows changes in the implementation to have minimal impact on the client code.  |
| Examples: GUI toolkit with different rendering engines, Database abstraction layer.     |

[Bridge](structural_examples/bridge.py)
***
