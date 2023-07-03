from abc import ABC, abstractmethod


class Subject(ABC):
    @abstractmethod
    def request(self):
        pass


class RealSubject(Subject):
    def request(self):
        print("RealSubject handling request")


class Proxy(Subject):
    def __init__(self, real_subject):
        self.real_subject = real_subject

    def request(self):
        # Perform some pre-processing or additional checks
        print("Proxy handling request")
        self.real_subject.request()
        # Perform some post-processing or additional checks


real_subject = RealSubject()
proxy = Proxy(real_subject)
proxy.request()
