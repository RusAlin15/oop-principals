from abc import ABC, abstractmethod


class Component(ABC):
    @abstractmethod
    def operation(self):
        pass


class ConcreteComponent(Component):
    def operation(self):
        print("Concrete Component operation")


class Decorator(Component):
    def __init__(self, component):
        self.component = component

    def operation(self):
        self.component.operation()


class ConcreteDecoratorA(Decorator):
    def operation(self):
        super().operation()
        self.additional_operation()

    def additional_operation(self):
        print("Concrete Decoretor A additional operation")


class ConcreteDecoratorB(Decorator):
    def operation(self):
        super().operation()
        self.other_opperation()

    def other_opperation(self):
        print("Concrete Decorator B other operation")


component = ConcreteComponent()
decoratorA = ConcreteDecoratorA(component)
decoratorB = ConcreteDecoratorB(component)

decoratorB.operation()
