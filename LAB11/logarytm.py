import math

class ZlaPodstawa(Exception):
    def __init__(self):
        pass
    def __str__(self):
        return "Zla podstawa"


class ZlyArgument(Exception):
    def __init__(self):
        pass
    def __str__(self):
        return "Zly argument"


class RoznePodstawy(Exception):
    def __init__(self):
        pass
    def __str__(self):
        return "Rozne podstawy"


class Logarytm:
    def __init__(self, podstawa, argument):
        if podstawa <= 0 or podstawa == 1:
            raise ZlaPodstawa
        if argument <= 0:
            raise ZlyArgument
        self.podstawa = podstawa
        self.argument = argument

    def __add__(self, other):
        if self.podstawa != other.podstawa:
            raise RoznePodstawy
        return Logarytm(self.podstawa, self.argument * other.argument)

    def __str__(self):
        return "log"+str(self.podstawa)+"("+str(self.argument)+")"

    def redukuj(self):
        p = self.podstawa
        for i in range(2,(int(self.podstawa/2))+1):
            for j in range(2, 11):
                if i ** j == self.podstawa:
                    podst = i
                    pot = j
            for k in range(2,(int(self.argument/2))+1):
                if podst and pot and k ** pot == self.argument:
                    self.podstawa = podst
                    self.argument = k
        if p == self.podstawa:
            raise BaseException()

    def oblicz(self):
        return math.log(self.argument, self.podstawa)

