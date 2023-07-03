from abc import ABC, abstractmethod


class Shape(ABC):
    def __init__(self, implementation):
        self.implementation = implementation

    @abstractmethod
    def draw(self):
        pass


class Circle(Shape):
    def draw(self):
        print("Drawing a circle")
        self.implementation.draw_implementation()


class Implementation(ABC):
    @abstractmethod
    def draw_implementation(self):
        pass


class RedImplementation(Implementation):
    def draw_implementation(self):
        print("Using red color")


class BlueImplementation(Implementation):
    def draw_implementation(self):
        print("Using blue color")


# Usage
red_implementation = RedImplementation()
blue_implementation = BlueImplementation()

circle_red = Circle(red_implementation)
circle_red.draw()

circle_blue = Circle(blue_implementation)
circle_blue.draw()
