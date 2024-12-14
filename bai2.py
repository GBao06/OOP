class Student:
    subject = "Python"
    def __init__(self, id, name, score1, score2):
        self.__id = id
        self.__name = name
        self.__score1 = score1
        self.__score2= score2
    def get_infor(self):
         return f"{self.__id};{self.__name};{self.__score1};{self.__score2}\n"
    def DTB(self):
            return (self.__score1 + self.__score2 ) / 2
    def get_Name(self):
         return self.__name
    def get_ID(self):
         return self.__id
    def get_Score1(self):
         return self.__score1
    def get_Score2(self):
         return self.__score2
    def set_Name(self,name):
         self.__name = name
    def set_ID(self, id):
         self.__id = id
    def set_Score1(self, a):
         self.__score1 = a
    def set_Score2(self, a):
         self.__score2 = a
    def __gt__(self, other):
        return self.DTB() > other.DTB()
    

sv = []
while True:
            id = input("Nhap MSV: ")
            if id == "":
                 break
            name = input("Nhap ten: ")
            diem1 = int(input("Nhap diem lan 1: "))
            diem2 = int(input("Nhap diem lan 2: "))
            sv.append(Student(id,name,diem1, diem2))

try:
    with open("sv.txt", "w", encoding="utf-8") as f_in:
        for i in sv:
             f_in.write(i.get_infor())
             print(i.get_infor())
    with open("ketqua.txt", "w",encoding="utf-8") as f_out:
         sv.sort()
         print("Danh sach sv sap xep da duoc ghi vao file ketqua.txt ")
         for i in sv:
              f_out.write(i.get_infor())
         
except Exception as e:
    print(e)    
                       