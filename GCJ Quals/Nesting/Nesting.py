tasks = int(input())

for i in range (tasks):
    inputString = input()

    newString = ""
    lastNumber = -1

    for nextChar in inputString:
        number = int(nextChar)
        subtract = min(number, lastNumber)

        if subtract != -1 and subtract != 0:
            newString = newString[:-subtract]
            newString += (number-subtract)*"("
        else:
            newString += number*"("
        newString += str(nextChar)
        newString += number*")"
        
        lastNumber = number

    print("Case #{}: {}".format(i+1, newString))

