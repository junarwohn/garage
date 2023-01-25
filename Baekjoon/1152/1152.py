    inputString = input()
    space = 0
    if len(inputString) == 0:
        print(space)
    else:
        if inputString[0] == ' ':
            space -= 1
        if inputString[-1] == ' ':
            space -= 1
        for ch in inputString:
            if ch == ' ':
                space += 1
        space += 1
        print(space)