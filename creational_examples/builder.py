class Product:
    def __init__(self):
        self.part_a = None
        self.part_b = None

    def __str__(self):
        return f"Part A: {self.part_a}, Part B: {self.part_b}"


class Builder:
    def build_part_a(self):
        pass

    def build_part_b(self):
        pass

    def get_product(self):
        pass


class ConcreteBuilder(Builder):
    def __init__(self):
        self.product = Product()

    def build_part_a(self):
        self.product.part_a = "Part A"

    def build_part_b(self):
        self.product.part_b = "Part B"

    def get_product(self):
        return self.product


class Director:
    def __init__(self, builder):
        self.builder = builder

    def construct_product(self):
        self.builder.build_part_a()
        self.builder.build_part_b()


# Usage
builder = ConcreteBuilder()
director = Director(builder)
director.construct_product()
product = builder.get_product()
print(product)  # Output: Part A: Part A, Part B: Part B
