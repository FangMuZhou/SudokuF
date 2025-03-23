import openpyxl
import os
from config import *
book=openpyxl.load_workbook(filename=Table_Path)
print(book)
sheet = book[Sheet_Name]
letters='ABCDEFGHIJKLMNOPQRSTUVWXYZ'
ret=''
for i in range(9):
    for j in range(9):
        cellname=letters[j]+str(i+1)
        cell = str(sheet[cellname].value)
        # print(cell)
        if cell=='None':
            ret+='.'
            continue
        try:
            val=int(cell)
            if val>=1 and val<=9:
                ret+=cell
            else:
                raise ValueError
        except:
            print("Wrong table!")
            break
# print(ret)
with open("res.txt","w") as f:
    f.write(ret)
os.system("start calc.exe")