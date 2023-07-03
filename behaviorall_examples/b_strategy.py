from abc import ABC, abstractmethod


class Strategy(ABC):
    @abstractmethod
    def execute(self):
        pass


class ConcreteStrategyA(Strategy):
    def execute(self):
        print("Execute Strategy A")


class ConcreteStrategyB(Strategy):
    def execute(self):
        print("Execute Strategy B")


class Context:
    def __init__(self, strategy):
        self._strategy = strategy

    def set_strategy(self, strategy):
        self._strategy = strategy

    def execute_stratehy(self):
        self._strategy.execute()


contest = Context(ConcreteStrategyA())
contest.execute_stratehy()

contest = Context(ConcreteStrategyB())
contest.execute_stratehy()
