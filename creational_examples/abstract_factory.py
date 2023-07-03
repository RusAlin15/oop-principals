from abc import ABC, abstractmethod


class ProductA(ABC):
    @abstractmethod
    def operation(self):
        pass


class ConcreteProductA1(ProductA):
    def operation(self):
        return "Concrete Product A1"


class ConcreteProductA2(ProductA):
    def operation(self):
        return "Concrete Product A2"


class ProductB(ABC):
    @abstractmethod
    def operation(self):
        pass


class ConcreteProductB1(ProductB):
    def operation(self):
        return "Concrete Product B1"


class ConcreteProductB2(ProductB):
    def operation(se):
        return "Concrete Product B2"


class Factory(ABC):
    @abstractmethod
    def create_product_a(self):
        pass

    @abstractmethod
    def create_product_b(self):
        pass


class ConcreteFactory1(Factory):
    def create_product_a(self):
        return ConcreteProductA1()

    def create_product_b(self):
        return ConcreteProductB2()


class ConcreteFactory2(Factory):
    def create_product_b(self):
        return ConcreteProductA2()

    def create_product_a(self):
        return ConcreteProductB1()


# Usage
factory1 = ConcreteFactory1()
product_a1 = factory1.create_product_a()
product_b1 = factory1.create_product_b()
print(product_a1.operation())  # Output: ConcreteProductA1
print(product_b1.operation())  # Output: ConcreteProductB1

factory2 = ConcreteFactory2()
product_a2 = factory2.create_product_a()
product_b2 = factory2.create_product_b()
print(product_a2.operation())  # Output: ConcreteProductA2
print(product_b2.operation())  # Output: ConcreteProductB2_b()
