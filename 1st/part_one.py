max = 0
file = open("[YourInputFilePath]\input.txt", "r")
elfInv = 0
for row in file:
    if row != "\n":
        elfInv += int(row)
        if elfInv > max:
            max = elfInv
    else:
        elfInv = 0

print(max)