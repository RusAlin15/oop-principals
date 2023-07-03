from abc import ABC, abstractmethod


# Handler
class Handler(ABC):
    def __init__(self):
        self.next_handler = None

    def set_next_handler(self, next_handler):
        self.next_handler = next_handler

    @abstractmethod
    def handle_request(self, request):
        pass


# Concrete Handler
class ConcreteHandlerA(Handler):
    def handle_request(self, request):
        if request == 'A':
            print("ConcreteHandlerA handles the request.")
        elif self.next_handler is not None:
            self.next_handler.handle_request(request)


# Concrete Handler
class ConcreteHandlerB(Handler):
    def handle_request(self, request):
        if request == 'B':
            print("ConcreteHandlerB handles the request.")
        elif self.next_handler is not None:
            self.next_handler.handle_request(request)


# Concrete Handler
class ConcreteHandlerC(Handler):
    def handle_request(self, request):
        if request == 'C':
            print("ConcreteHandlerC handles the request.")
        elif self.next_handler is not None:
            self.next_handler.handle_request(request)


# Usage
handler_a = ConcreteHandlerA()
handler_b = ConcreteHandlerB()
handler_c = ConcreteHandlerC()

handler_a.set_next_handler(handler_b)
handler_b.set_next_handler(handler_c)

handler_a.handle_request('A')

handler_b.handle_request('B')
