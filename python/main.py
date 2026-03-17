import os
path = 'C:\\Users\\lukma\\OneDrive\\Desktop\\škola\\render\\'
dirList = os.listdir(path)
startFrom = 0

print(dirList)

for i in range(len(dirList)): os.rename(f'{path}{dirList[i]}', f'{path}{i + startFrom}.png')