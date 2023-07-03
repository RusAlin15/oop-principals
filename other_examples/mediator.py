from abc import ABC, abstractmethod


class Mediator(ABC):
    @abstractmethod
    def send_message(self, message, colleague):
        pass


class ChatroomMediator(Mediator):
    def __init__(self):
        self.colleagues = []

    def add_colleague(self, colleague):
        self.colleagues.append(colleague)

    def send_message(self, message, colleague):
        for c in self.colleagues:
            if c != colleague:
                c.receive_message(message)


class Colleague(ABC):
    def __init__(self, mediator):
        self.mediator = mediator

    @abstractmethod
    def send_message(self, message):
        pass

    @abstractmethod
    def receive_message(self, message):
        pass


class User(Colleague):
    def __init__(self, name, mediator):
        super().__init__(mediator)
        self.name = name

    def send_message(self, message):
        print(f"{self.name}  sends: {message}")
        self.mediator.send_message(message, self)

    def receive_message(self, message):
        print(f"{self.name} receives: {message}")


# Usage
mediator = ChatroomMediator()

user1 = User("Alice", mediator)
user2 = User("Bob", mediator)
user3 = User("Charlie", mediator)

mediator.add_colleague(user1)
mediator.add_colleague(user2)
mediator.add_colleague(user3)

user1.send_message("Hello everyone!")
