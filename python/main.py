import os
path = 'c:/Users/l.macura.st/Desktop/assets/slezak.jpg c:/Users/l.macura.st/Desktop/assets/'
dirList = os.listdir(path)
startFrom = 0

print(dirList)

for i in range(len(dirList)): os.rename(f'{path}{dirList[i]}', f'{path}{i + startFrom}.png')