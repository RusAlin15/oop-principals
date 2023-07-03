class Originator:

    def __init__(self):
        self.state = None

    def set_state(self, state):
        self.state = state

    def save_state(self):
        return Memento(self.state)

    def restore_state(self, memento):
        self.state = memento.get_state()


class Memento:
    def __init__(self, state):
        self.state = state

    def get_state(self):
        return self.state


class Caretaker:
    def __init__(self):
        self.mementos = []

    def add_memento(self, memento):
        self.mementos.append(memento)

    def get_memento(self, index):
        return self.mementos[index]


originator = Originator()
caretaker = Caretaker()

originator.set_state("State 1")
caretaker.add_memento(originator.save_state())

originator.set_state("State 2")
caretaker.add_memento(originator.save_state())

originator.set_state("State 3")
caretaker.add_memento(originator.save_state())

originator.restore_state(caretaker.get_memento(0))
print(originator.state)
