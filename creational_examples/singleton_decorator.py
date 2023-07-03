def singleton(cls):
    instances = {}

    def wrapper(*args, **kwargs):
        if cls not in instances:
            instances[cls] = cls(*args, **kwargs)
        return instances[cls]

    return wrapper


@singleton
class SingletonClass:
    def __init__(self, data):
        self.data = data


instace1 = SingletonClass("Instance 1")
instace2 = SingletonClass("Instance 2")

print(instace1.data)
print(instace2.data)
print(instace2 is instace1)
