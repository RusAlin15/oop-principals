# OOP Patterns

These patterns help address specific design challenges and promote reusable,
maintainable, and flexible code. It's important to choose the appropriate
pattern based on the problem at hand and the desired design goals.
***

## Other Patterns

***

### 1. Command

| Description |
|-------------|
| Encapsulates a request as an object, allowing parameterization of clients with different requests.      |
| Enables the queuing, logging, and undo functionality of requests.          |
| Examples: Implementing a command history in an editor, Remote control with programmable buttons.       |

[Code Example](link)
***

### 2. Memento

| Description |
|-------------|
| Provides the ability to restore an object's state to a previous state (undo/rollback).      |
| Captures and stores the internal state of an object externally without violating encapsulation.          |
| Examples: Undo/redo functionality, Restoring game state.       |

[Code Example](link)
***

### 3. Mediator

| Description |
|-------------|
| Examples: Undo/redo functionality, Restoring game state.      |
| Promotes loose coupling between objects by reducing direct dependencies.          |
| Facilitates communication and coordination between objects.       |
| Examples: Air traffic control system, Chat room application.      |

[Code Example](link)
***

### 4. Visitor

| Description |
|-------------|
| Separates an algorithm from the objects it operates on.      |
| Allows adding new operations to a group of related objects without modifying their classes.          |
| Ensures open-closed principle by extending the behavior without changing the object structure.       |
| Examples: Expression evaluation, Document parsing.      |

[Code Example](link)
***

### 5. Chain of Responsibility

| Description |
|-------------|
| Allows an object to pass a request along a chain of potential handlers.      |
| Provides a way to decouple the sender and receiver of a request.          |
| Enables multiple objects to handle the request without explicitly specifying the receiver.       |
|Examples: Request processing in web frameworks, Event propagation in UI frameworks.|

[Code Example](link)
***