from abc import ABC, abstractmethod


class Prototype(ABC):
    @abstractmethod
    def clone(self):
        pass


class ConcretePrototype(Prototype):
    def __init__(self, name):
        self.name = name

    def clone(self):
        return ConcretePrototype(f"New + {self.name}")

    def __str__(self):
        return f"Prototype: {self.name}"


prototype = ConcretePrototype("Prototype")
print(prototype)

clone_prototype = prototype.clone()
print(clone_prototype)
