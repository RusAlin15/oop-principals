from abc import ABC, abstractmethod


class Component(ABC):
    @abstractmethod
    def operation(self):
        pass


class Leaf(Component):
    def operation(self):
        print("Leaf operation")


class Composite(Component):
    def __init__(self):
        self.children = []

    def operation(self):
        print("Copmosite operation")
        for child in self.children:
            child.operation()

    def add(self, component):
        self.children.append(component)

    def remove(self, component):
        self.children.remove(component)


composite1 = Composite()
composite1.add(Leaf())
composite1.add(Leaf())

composite2 = Composite()
composite2.add(Leaf())
composite2.add((composite1))

composite2.operation()
