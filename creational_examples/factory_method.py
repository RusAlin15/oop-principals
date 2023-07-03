from abc import ABC, abstractmethod


class Product(ABC):
    @abstractmethod
    def operation(self):
        pass


class ConcreteProductA(Product):
    def operation(self):
        return "Concrete Product A"


class ConcreteProductB(Product):
    def operation(self):
        return "Concrete Product B"


class Creator(ABC):
    @abstractmethod
    def factory_merhod(self):
        pass

    def some_operation(self):
        product = self.factory_merhod()
        result = product.operation()
        return f"Creator: {result}"


class ConcreteCreatorA(Creator):
    def factory_merhod(self):
        return ConcreteProductA()


class ConcreteCreatorB(Creator):
    def factory_merhod(self):
        return ConcreteProductB()


creator_a = ConcreteCreatorA()
print(creator_a.some_operation())

creator_b = ConcreteCreatorB()
print(creator_b.some_operation())
