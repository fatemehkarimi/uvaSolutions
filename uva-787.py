#uva 787
#Maximum Sub-sequence Product

while True:
    try:
        num = list(map(int, input().strip().split()))
    except EOFError:
        break

    if len(num) == 0:
        break

    num.pop()
    negativeCount = 0
    negativeValue = 0

    soFar = num[0]
    previous = 0

    result = num[0]

    if num[0] < 0:
        negativeCount = 1
        negativeValue = num[0]

    elif num[0] == 0:
        soFar = 1

    for x in num[1:]:
        soFar *= x

        previous = result

        if x < 0:
            negativeCount += 1
            if negativeCount == 1:
                negativeValue = soFar

                result = max(previous, soFar)
                continue

        if negativeCount == 0:
            result = max(previous, soFar)
        else:
            if negativeCount % 2:
                result = max(previous, soFar // negativeValue)
            else:
                result = max(previous, soFar)

        if x == 0:
            soFar = 1
            negativeValue = 0
            negativeCount = 0

    print(result)
