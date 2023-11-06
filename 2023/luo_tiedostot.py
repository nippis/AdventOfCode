import os

for i in range(14,25):
    if i not in [21, 22, 23]:
        dirname = str(i) + "th"
    elif i == 21:
        dirname = str(i) + "st"
    elif i == 22:
        dirname = str(i) + "nd"
    elif i == 23:
        dirname = str(i) + "rd"
        
    filename = "day" + str(i) + ".cpp"
    
    par = "C:\\Koodaus\\AdventOfCode\\2023"
    path = os.path.join(par, dirname)
    os.mkdir(path)
    filepath = os.path.join(path, filename)
    open(filepath, "x")
