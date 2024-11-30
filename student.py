class Student():
    #thuoc tinh lop
    subject="Python"
    #thuoc tinh doi tuong
    def __init__(self, id, name, score1, score2):
        self.id = id
        self.name = name
        self.score1 = score1
        self.score2 = score2
    def __str__(self):
        return (f"Ma sinh vien: {self.id} \nHoTen: {self.name} \nDiem: {self.score():.2f}")
    def score(self):
        return ((self.score1+self.score2)/2)
    def get_infor(self):
        print(f"{self.id}: {self.score():2f}")
    

n = int(input("Nhap so luong sinh vien: "))
arr = []
for i in range(n):
    id = input("Nhap id: ")
    name = input("Nhap ten: ")
    diem1 = int(input("Nhap diem lan 1: "))
    diem2 = int(input("Nhap diem lan 2: "))
    sv = Student(id,name,diem1,diem2)
    arr.append(sv)

for i in arr:
    print(i.get_infor())