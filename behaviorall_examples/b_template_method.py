from abc import ABC, abstractmethod


class AbstractClass(ABC):
    def template_method(self):
        self.step1()
        self.step2()
        self.step3()

    @abstractmethod
    def step1(self):
        pass

    def step2(self):
        pass

    def step3(self):
        pass


class ConcreteClass(AbstractClass):
    def step1(self):
        print("Step1: Performing initial setup")

    def step2(self):
        print("Step2: Performing core logic")

    def step3(self):
        print("Step3: Performing end cleanup")


instance = ConcreteClass()

instance.template_method()
