class CongNhan:
    def __init__(self,MaCN,Hoten,Bac,SNLV,NKHD) :
        self.MaCN = MaCN
        self.Hoten = Hoten
        self.Bac = Bac
        self.SNLV = SNLV
        self.NKHD = NKHD
    def get_MaCN(self):
        return self.MaCN
    def get_HoTen(self):
        return self.Hoten
    def get_Bac(self):
        return self.Bac
    def get_SoNgayLamViec(self):
        return self.SNLV
    def get_NgayKiHopDong(self):
        return f"{self.NKHD["ngay"]}/{self.NKHD["thang"]}/{self.NKHD["nam"]}"
    
    def __str__(self):
        return(
            f"Ma cong nhan: {self.MaCN}\n"
            f"Ho ten: {self.Hoten}\n"
            f"Bac: {self.Bac}\n"
            f"So ngay lam viec: {self.SNLV}\n"
            f"Ngay ki hop dong:  {self.NKHD["ngay"]}/{self.NKHD["thang"]}/{self.NKHD["nam"]}\n"
            f"Tien luong: {self.get_tienluong()}"
        )
    def display(self):
        print(f"{self.MaCN},{self.Hoten},{self.SNLV},{self.get_tienluong()}")

    def get_tienluong(self):
        if self.Bac == 1:
            return self.SNLV * 300000
        elif self.Bac == 2:
            return self.SNLV * 350000
        elif self.Bac == 3:
            return self.SNLV * 400000
    def __gt__(self, other):
        if self.NKHD["nam"] > other.NKHD["nam"]: 
            return True
        elif self.NKHD["nam"] == other.NKHD["nam"]:
            if self.NKHD["thang"] > other.NKHD["thang"]:
                return True
            elif self.NKHD["thang"] == other.NKHD["thang"]:
                return self.NKHD["ngay"] > other.NKHD["ngay"]
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