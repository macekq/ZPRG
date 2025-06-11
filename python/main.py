import os
path = 'C:/Users/l.macura.st/Documents/GitHub/cigitonda.vip/zwa/makeItTierList/assets/got/'
dirList = os.listdir(path)
startFrom = 0

print(dirList)

for i in range(len(dirList)): os.rename(f'{path}{dirList[i]}', f'{path}{i + startFrom}.png')