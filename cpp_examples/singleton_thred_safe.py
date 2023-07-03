import threading
import time


class Singleton:
    _instance = None
    _lock = threading.Lock()

    def __init__(self):
        if Singleton._instance is not None:
            raise Exception("Singleton instance already exists!")
        Singleton._instance = self

    @staticmethod
    def get_instance():
        if Singleton._instance is None:
            with Singleton._lock:
                if Singleton._instance is None:
                    Singleton._instance = Singleton()
        return Singleton._instance


def creat_singleton_instance():
    sleep_duration = (2 * threading.currentThread().ident) % 3
    time.sleep(sleep_duration)
    singleton_instance = Singleton.get_instance()
    print(
        f"Thread {threading.current_thread().name} created Singleton instance :{singleton_instance}")


threads = []

for i in range(5):
    thread = threading.Thread(target=creat_singleton_instance)
    threads.append(thread)
    thread.start()

for thread in threads:
    thread.join()
