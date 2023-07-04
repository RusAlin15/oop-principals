# OOP Patterns

These patterns help address specific design challenges and promote reusable,
maintainable, and flexible code. It's important to choose the appropriate
pattern based on the problem at hand and the desired design goals.
***

## Behavioral Patterns

Behavioral patterns in object-oriented programming focus on defining the communication and
interaction between objects and classes. They help manage algorithms, responsibilities, and
relationships between objects in a system.
***

### 1. Observer

| Description |
| -------- |
| Defines a one-to-many dependency between objects. |
| When the state of one object changes, all its dependents are automatically notified and updated. |
| Allows loose coupling between objects and promotes maintainability. |
| Examples: Event handling, Notifications in a messaging system. |

[Observer](behaviorall_examples/b_observer.py) ::
***

### 2. Strategy

| Description |
| --------- |
| Encapsulates interchangeable behaviors and algorithms. |
| Allows clients to dynamically select and use different strategies at runtime. |
| Enables easy extension and modification of behavior. |
| Examples: Sorting algorithms, Payment methods in an e-commerce system. |

[Strategy](behaviorall_examples/b_strategy.py)
***

### 3. Template Method

| Description |
|------|
| Defines the skeleton of an algorithm in a base class. |
| Allows subclasses to override specific steps of the algorithm.  |
| Provides a framework for implementing and reusing common algorithms.  |
| Examples: Document processing with different file formats, Game development with      |

[Template Methood](behaviorall_examples/b_template_method.py)
***

### 4. Iterator

| Description |
|------------|
| Provides a way to access the elements of an aggregate object sequentially.   |
| Hides the underlying representation of the collection and provides a consistent interface.     |
| Simplifies traversal and iteration over complex data structures.    |
| Examples: Iterating over a list, Parsing a tree structure.     |

[Iterator](behaviorall_examples/b_iterator.py)
***

### 5. State

| Description |
|-------------|
| Allows an object to alter its behavior when its internal state changes. |
| Encapsulates state-specific behavior in separate classes. |
| Simplifies complex conditional logic and promotes modularity. |
| Examples: Workflow management, Game character behavior based on game state. |

[State](behaviorall_examples/b_state.py)
***
