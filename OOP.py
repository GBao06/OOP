class CongNhan:
    def __init__(self,MaCN,Hoten,Bac,SNLV,NKHD) :
        self.__MaCN = MaCN
        self.__Hoten = Hoten
        self.__Bac = Bac
        self.__SNLV = SNLV
        self.__NKHD = NKHD
    def set_MaCN(self,MaCN):
        self.__MaCN = MaCN
    def set_Hoten(self,Hoten):
        self.__Hoten = Hoten
    def set_Bac(self,Bac):
        self.__Bac = Bac   
    def set_SoNgayLamViec(self,SNLV):
        self.__SNLV = SNLV   
    def set_NgayKiHopDong(self,NKHD):
        self.__NKHD = NKHD           
    def get_MaCN(self):
        return self.__MaCN
    def get_HoTen(self):
        return self.__Hoten
    def get_Bac(self):
        return self.__Bac
    def get_SoNgayLamViec(self):
        return self.__SNLV
    def get_NgayKiHopDong(self):
        return f"{self.__NKHD["ngay"]}/{self.__NKHD["thang"]}/{self.__NKHD["nam"]}"
    
    def __str__(self):
        return(
            f"Ma cong nhan: {self.__MaCN}\n"
            f"Ho ten: {self.__Hoten}\n"
            f"Bac: {self.__Bac}\n"
            f"So ngay lam viec: {self.__SNLV}\n"
            f"Ngay ki hop dong:  {self.__NKHD["ngay"]}/{self.__NKHD["thang"]}/{self.__NKHD["nam"]}\n"
            f"Tien luong: {self.get_tienluong()}"
        )    
    def display(self):
        print(f"{self.__MaCN},{self.__Hoten},{self.__SNLV},{self.get_tienluong()}")

    def get_tienluong(self):
        if self.__Bac == 1:
            return self.__SNLV * 300000
        elif self.__Bac == 2:
            return self.__SNLV * 350000
        elif self.__Bac == 3:
            return self.__SNLV * 400000
        else: return 300000
        
    def __gt__(self, other):
        if self.__NKHD["nam"] > other.__NKHD["nam"]: 
            return True
        elif self.__NKHD["nam"] == other.__NKHD["nam"]:
            if self.__NKHD["thang"] > other.__NKHD["thang"]:
                return True
            elif self.__NKHD["thang"] == other.__NKHD["thang"]:
                return self.__NKHD["ngay"] > other.__NKHD["ngay"]
        return False

arr = []
while(True):
    MaCN = input("Nhap ma cong nhan: ")
    if MaCN == "": break
    check = False
    for i in arr:
        if i.get_MaCN() == MaCN:
            print(f"Ma cong nhan {MaCN} da co trong ds! Vui long nhap lai ! ")
            check = True
            break
    if check: continue
    Hoten = input("Nhập họ tên: ")
    Bac = int(input("Nhập bậc (1, 2, hoặc 3): "))
    SoNgayLV = int(input("Nhập số ngày làm việc: "))
    print("Nhập ngày ký hợp đồng:")
    Ngay = int(input("  Ngày: "))
    Thang = int(input("  Tháng: "))
    Nam = int(input("  Năm: "))
    NgayKiHopDong = {"ngay": Ngay, "thang": Thang, "nam": Nam}
    cong_nhan = CongNhan(MaCN, Hoten, Bac, SoNgayLV, NgayKiHopDong)
    arr.append(cong_nhan)

print("\nDanh sách công nhân đã nhập:")
for cn in arr:
    print("\n" + str(cn))

print("\nCong nhan co bac la 1: ")
for i in arr:
    if( i.get_Bac() == 1):
       i.display()
       print()

arr.sort()
# arr.sort(reverse=True)
print("Danh sach sau khi sap xep: \n")
for i in arr:
    print("\n" + str(i))
