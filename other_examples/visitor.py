from abc import ABC, abstractmethod


class Visitor(ABC):
    @abstractmethod
    def visit_circle(self, circle):
        pass

    @abstractmethod
    def visit_rectangle(self, rectangle):
        pass


class AreaCalculatorVisitor(Visitor):
    def visit_circle(self, circle):
        print("Calculating area of circle")

    def visit_rectangle(self, rectangle):
        print("Calculating area of rectangle")


class Shape(ABC):
    @abstractmethod
    def accept(self, visitor):
        pass


class Circle(Shape):
    def accept(self, visitor):
        visitor.visit_circle(self)


class Rectangle(Shape):
    def accept(self, visitor):
        visitor.visit_rectangle(self)


circle = Circle()
rectangle = Rectangle()

visitor = AreaCalculatorVisitor()

circle.accept(visitor)
rectangle.accept(visitor)
