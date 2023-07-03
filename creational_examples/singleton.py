import random
import threading
import time


class SingletonClass:
    _instance = None

    def __new__(cls, *args, **kwargs):
        if not cls._instance:
            cls._instance = super(SingletonClass, cls).__new__(cls)
        return cls._instance

    def __init__(self, data):
        self.data = data

    def get_instance(self):
        return self._instance


# instance1 = SingletonClass("Instance 1")
# instance2 = SingletonClass("Instance 2")


# print(instance1.data)
# print(instance2.data)
# print(instance1 is instance2)


def modify_singleton_data():
    rd = random.randint(1, 9)
    time.sleep(rd / 7954785)
    singleton = SingletonClass(f"Instance-{rd}")
    print(singleton.get_instance())


# Create multiple threads to modify the Singleton instance simultaneously
threads = []
for _ in range(7):
    rand = random.randint(1, 10)
    thread = threading.Thread(target=modify_singleton_data)
    threads.append(thread)
    thread.start()

# Wait for all threads to complete
for thread in threads:
    thread.join()

# Access the Singleton instance after the threads have completed
singleton = SingletonClass("Second ")
print(singleton.data)
