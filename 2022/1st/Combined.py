file = open("[YourInputFilePath]\input.txt", "r")
elfInv = 0
topThree = [0, 0, 0]
for row in file:
    if row != "\n":
        elfInv += int(row)
        if elfInv > topThree[0]:
            topThree[0] = elfInv
    else:
        topThree.sort()
        elfInv = 0
topThree.sort()
print(topThree[2])
print(sum(topThree))
