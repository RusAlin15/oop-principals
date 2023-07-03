import threading
import random


class SingletonClass:
    _instance = None
    _lock = threading.Lock()

    def __init__(self, data):
        self.data = data

    def __new__(cls, *args, **kwargs):
        if not cls._instance:
            with cls._lock:
                if not cls._instance:
                    cls._instance = super(SingletonClass, cls).__new__(cls)
        return cls._instance

    def get_instance(self):
        return self._instance


def modify_singleton_data():
    rd = random.randint(1, 9)
    singleton = SingletonClass(f"Instance-{rd}")
    print(singleton.get_instance())


# Create multiple threads to modify the Singleton instance simultaneously
threads = []
for _ in range(5):
    thread = threading.Thread(target=modify_singleton_data)
    threads.append(thread)
    thread.start()

# Wait for all threads to complete
for thread in threads:
    thread.join()

# Access the Singleton instance after the threads have completed
singleton = SingletonClass("Second ")
print(singleton.data)
