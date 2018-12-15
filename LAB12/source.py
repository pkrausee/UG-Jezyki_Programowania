import re


class Samochod:
    def __init__(self, line):
        [self.Model, self.MPG, self.Cylinders, self.EngineDisp, self.Horsepower, self.Weight, self.Accelerate, self.Year, self.Origin] = line.split(",")

    def __str__(self):
        return self.Model +","+ self.MPG, self.Cylinders +","+ self.EngineDisp +","+ self.Horsepower + "," +self.Weight +","+ self.Accelerate +","+ self.Year +","+ self.Origin


class Samochody:
    def __init__(self, linesList):
        self.listaSamochodow = []
        for line in linesList:
            self.listaSamochodow.append(Samochod(line))

    def znajdz(self, str1, atrr):
        for sam in self.listaSamochodow:
            if(getattr(sam, atrr)) == str1:
                return sam
            return None

    def zamien(self, str1, atrr, str2):
        p = self.znajdz(str1, atrr)
        setattr(p, atrr, str2)
        return p


with open("cars.csv") as file:
    linesList = file.read().splitlines()
file.close()

linesList = linesList[1:]
s1 = Samochody(linesList)

i = 0
for sam in s1.listaSamochodow:
    a = re.match(r'^ford.*',getattr(sam, 'Model'))
    # a = re.match(r'(^toyota.*)|(^volvo.*)',getattr(sam, 'Model'))
    # a = re.match(r'^.*\d.*',getattr(sam, 'Model'))
    # a = re.match(r'^.*[(|)].*',getattr(sam, 'Model'))
    # a = re.match(r'^.*[^\w\d\s].*',getattr(sam, 'Model'))
    # a = re.match(r'^\S*\s\S*\s\S*$',getattr(sam, 'Model'))
    # a = re.match(r'\b[^\WaAeEiIoOuUyY]*[aAeEiIoOuUyY][^\WaAeEiIoOuUyY]*[aAeEiIoOuUyY][^\WaAeEiIoOuUyY]*\b.*',getattr(sam, 'Model'))
    # a = re.match(r'\d{2}', getattr(sam, 'Horsepower'))
    # a = re.match(r'.*[.].*', getattr(sam, 'Accelerate'))
    # a = re.match(r'^7\d$', getattr(sam, 'Year'))


    if a:
        print(a.group())


        i += 1

print("\n\nZnaleziono %d wynikow" % (i))