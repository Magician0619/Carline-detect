# import xlwt

# f = xlwt.Workbook(encoding="utf-8")
# sheet1 = f.add_sheet("test",cell_overwrite_ok=True)
# list = [[1,2,3],[2,3,4]]
# print(list[:,0])

# # for i in range(10):
# #     for j in range(5):
# #         sheet1.write(i,j,"the"+str(10*i+j)+"classmates")

# for i in range(10):
#     sheet1.write(i,0,"the"+str(i)+" classmates")

# sheet1.write(2,0,"hello")

# f.save("save.xlsx") #保存文件
import re

a_list=[[1.0,2.0],1,2]
print(a_list)
print(a_list[0])

string = str(a_list).replace('[','').replace(']','')

print(str(a_list[0]))
print(string)

import xlwt

f = xlwt.Workbook()
sheet1 = f.add_sheet(u'sheet1',cell_overwrite_ok=True)

num_a = str(train_cost[0]).replace('[','').replace(']','')
sheet1.write(int(pass_id),0,num_a)

f.save("save.xls") #保存文件