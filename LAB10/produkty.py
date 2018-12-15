class PolskiProdukt:
    def __init__(self, miastoProdukcji, producent, czyPowypadkowy):
        self.miastoProdukcji = miastoProdukcji
        self.producent = producent
        self.czyPowypadkowy = czyPowypadkowy
    def __str__(self):
        out = "\t Produkt wyprodukowany w: "+self.miastoProdukcji+" przez "+self.producent+"\n"
        if(self.czyPowypadkowy):
            out += "\t Produkt powypadkowy"
        else:
            out += "\t Produkt nieuszkodzony"
        return out