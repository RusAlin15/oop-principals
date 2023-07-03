from abc import abstractmethod


class Subject:
    def __init__(self):
        self._observers = []

    def attach(self, observer):
        self._observers.append(observer)

    def detach(self, observer):
        self._observers.remove(observer)

    def notify(self, message):
        for observer in self._observers:
            observer.update(message)


class Observer:
    @abstractmethod
    def update(self, message):
        pass


class ConcreteObsrverA(Observer):
    def update(self, message):
        print("ConcreteObserverA received: ", message)


class ConcreteObsrverB(Observer):
    def update(self, message):
        print("ConcreteObserverB received: ", message)


subject = Subject()

observer_a = ConcreteObsrverA()
observer_b = ConcreteObsrverB()

subject.attach(observer_a)
subject.attach(observer_b)

subject.notify("Hello observers!")
