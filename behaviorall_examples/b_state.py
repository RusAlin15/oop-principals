class Context:
    def __init__(self):
        self.state = StateA()

    def request(self):
        self.state.handle(self)

    def change_state(self, new_state):
        self.state = new_state


class State:
    def handle(self, context):
        pass


class StateA(State):
    def handle(self, context):
        print("State A handling the request")
        context.change_state(StateB())


class StateB(State):
    def handle(self, context):
        print("State A handling the request")
        context.change_state(StateA())


context = Context()

context.request()
context.request()
