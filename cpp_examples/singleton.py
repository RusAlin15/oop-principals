class Singleton:
    _instance = None
    b = 3

    def __init__(self):
        if Singleton._instance is not None:
            raise Exception("Singleton instance already exists!")
        Singleton._instance = self

    @staticmethod
    def get_instance():
        if Singleton._instance is None:
            Singleton()
        return Singleton._instance


singleton_inst2 = Singleton.get_instance()
singleton_inst1 = Singleton()

print(singleton_inst1 is singleton_inst2)
