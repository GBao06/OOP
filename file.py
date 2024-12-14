n = input("Nhap chuoi: ")

try:
    with open("vd2.txt", "w", encoding="utf-8") as f_in:
      f_in.write(n)
      chu = ""
      so = ""
      kitu = ""
    for x in n:
        if x.isdigit():
            so += x + ","
        elif x.isalpha():
            chu += x+","
        else:
            kitu += x+","
    with open("Ketqua.txt","w", encoding="utf-8") as f_out:
      f_out.write(chu+"\n")
      f_out.write(so+"\n")
      f_out.write(kitu+"\n")
except Exception as e:
    print(e)    