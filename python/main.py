import os
path = 'C:/Users/lukma/OneDrive/Documents/GitHub/cigitonda.vip/zwa/makeItTeirList/assets/trida/'
dirList = os.listdir(path)
startFrom = 0

print(dirList)

for i in range(len(dirList)): os.rename(f'{path}{dirList[i]}', f'{path}{i + startFrom}.png')