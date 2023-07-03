from abc import ABC, abstractmethod


class Command(ABC):
    @abstractmethod
    def execute(self):
        pass


class LightOnCommand(Command):
    def __init__(self, light):
        self.light = light

    def execute(self):
        self.light.switch_on()


class Light:
    def switch_on(self):
        print("Light is on")


class LightOffCommand(Command):
    def __init__(self, light):
        self.light = light

    def execute(self):
        self.light.switch_on()


class Light:
    def switch_on(self):
        print("Light is off")


class RemoteControl:
    def __init__(self):
        self.command = None

    def set_command(self, command):
        self.command = command

    def press_button(self):
        self.command.execute()


light = Light()
light_on_command = LightOnCommand(light)
light_off_command = LightOffCommand(light)

remote_control = RemoteControl()
remote_control.set_command(light_on_command)
remote_control.press_button()

remote_control.set_command(light_off_command)
remote_control.press_button()
