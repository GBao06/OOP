from math import gcd

class Phanso():
    tu = 0
    mau = 1
    def __init__(self,tu,mau):
        self.tu = tu
        self.mau = mau
        ucln = gcd(self.tu,self.mau)
        self.tu //= ucln
        self.mau //= ucln
    def getTu(self):
        return self.tu
    def getMau(self):
        return self.mau
    def __str__(self):
        return (f"{self.tu}/{self.mau}")
    def __add__(self, other):
        if isinstance(other, Phanso):
            tu_moi = self.tu * other.mau + other.tu * self.mau
            mau_moi = self.mau * other.mau
            return Phanso(tu_moi,mau_moi)
    def __sub__(self, other):
        if isinstance(other, Phanso):
            tu_moi = self.tu * other.mau - other.tu * self.mau
            mau_moi = self.mau * other.mau
            return Phanso(tu_moi,mau_moi)
    def __mul__(self, other):
        if isinstance(other,Phanso):
            tu_moi = self.tu * other.tu
            mau_moi = self.mau * other.mau
            return Phanso(tu_moi,mau_moi)
    def __truediv__(self,other):
        if isinstance(other, Phanso):
            tu_moi = self.tu * other.mau
            mau_moi = self.mau * other.tu
            return Phanso(tu_moi,mau_moi)



ps1 = Phanso(1,2)
ps2 = Phanso(1,3)
ps = ps1 + ps2
print(ps)
ps = ps1 - ps2
print(ps)
ps = ps1 * ps2
print(ps)
ps = ps1 / ps2
print(ps)
    
