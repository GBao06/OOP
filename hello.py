from datetime import date
class CongNhan():
    def __init__(self,MaCN,Hoten,Bac,SoNgayLV,NgayKiHopDong):
        self.MaCN = MaCN
        self.Hoten = Hoten
        self.Bac = Bac
        self.SoNgayLV = SoNgayLV
        self.NgayKiHopDong = NgayKiHopDong
    def fomat_NgayKiHopDong(self):
        Ngay = self.NgayKiHopDong.get("Ngay"," ")
        Thang = self.NgayKiHopDong.get("Thang"," ")
        Nam = self.NgayKiHopDong.get("Nam"," ")
        return (f"{Ngay:02d}/{Thang:02d}/{Nam}")
    def __str__(self):
        return (
            f"Ma cong nhan: {self.MaCN} \n"
            f"Ho ten: {self.Hoten}\n"
            f"Bac: {self.Bac}\n"
            f"So ngay lam viec: {self.SoNgayLV}\n"
            f"Ngay ki hop dong: {self.fomat_NgayKiHopDong()}"
        )
    def TienLuong(self):
        if self.Bac == 1:
            return self.SoNgayLV*300000
        elif self.Bac == 2:
            return self.SoNgayLV*350000
        else:
            return self.SoNgayLV*400000
    def __gt__(self,other):
        ngay_self = date(   
            self.NgayKiHopDong["Nam"], 
            self.NgayKiHopDong["Thang"],
            self.NgayKiHopDong["Ngay"]
        )
        ngay_other = date(
            other.NgayKiHopDong["Nam"], 
            other.NgayKiHopDong["Thang"],
            other.NgayKiHopDong["Ngay"]
        )
        return ngay_self > ngay_other
    def get_MaCN(self):
        return self.MaCN
    def set_HoTen(self,Hoten):
        self.Hoten = Hoten
    def set_Bac(self,Bac):
        self.Bac = Bac
    def set_SoNgayLV(self,SoNgayLV):
        self.SoNgayLV = SoNgayLV
    def set_NgayKiHopDong(self,NgayKiHopDong):
        self.NgayKiHopDong = NgayKiHopDong    
    def nhap(self):
        self.MaCN = input("Nhập mã công nhân: ")
        self.Hoten = input("Nhập họ tên: ")
        self.Bac = int(input("Nhập bậc (1, 2, hoặc 3): "))
        self.SoNgayLV = int(input("Nhập số ngày làm việc: "))
        
        print("Nhập ngày ký hợp đồng:")
        Ngay = int(input("  Ngày: "))
        Thang = int(input("  Tháng: "))
        Nam = int(input("  Năm: "))
        self.NgayKiHopDong = {"Ngay": Ngay, "Thang": Thang, "Nam": Nam}



arr = []

while True:
    MaCN = input("Nhập mã công nhân (hoặc nhấn Enter để kết thúc): ")
    if MaCN == "":
        break
    is_duplicate = False
    for i in arr:
        if i.get_MaCN() == MaCN:
            print(f"Mã {MaCN} đã có trong danh sách! Vui lòng nhập lại.")
            is_duplicate = True
            break

    if is_duplicate:
        continue
    Hoten = input("Nhập họ tên: ")
    Bac = int(input("Nhập bậc (1, 2, hoặc 3): "))
    SoNgayLV = int(input("Nhập số ngày làm việc: "))
    print("Nhập ngày ký hợp đồng:")
    Ngay = int(input("  Ngày: "))
    Thang = int(input("  Tháng: "))
    Nam = int(input("  Năm: "))
    NgayKiHopDong = {"Ngay": Ngay, "Thang": Thang, "Nam": Nam}


    cong_nhan = CongNhan(MaCN, Hoten, Bac, SoNgayLV, NgayKiHopDong)
    arr.append(cong_nhan)

print("\nDanh sách công nhân đã nhập:")
for cn in arr:
    print("\n" + str(cn))