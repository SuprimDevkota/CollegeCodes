def _xor(a, b):
    return (a and not b) or (not a and b)

def _fullAdder(a, b, c):
    sum = str(int(_xor(a, _xor(b, c))))
    carry = str(int((a and b) or (_xor(a, b) and c)))
    return sum, carry

def _twosComplement(num):
    result = ""

    if num[-1] == '1':
        result += '1'
        for i in range(len(num) - 2, -1, -1):
            result += str((int(_xor(int(num[i]), 1))))
        

    else:
        flag = False
        for i in range(len(num) - 1, -1, -1):
            if flag == False:
                result += num[i]
                if num[i] == '1':
                    flag = True

            else:
                result += str((int(_xor(int(num[i]), 1))))

    return result[::-1]

#have to be of equal length
def _summer(num1, num2):
    sum = ""
    carry = 0

    for i in range(len(num1) - 1, -1, -1):
        temp_sum, carry = _fullAdder(int(num1[i]), int(num2[i]), int(carry))
        sum += temp_sum
    
    return sum

def _subtractor(num1, num2):
    x = num1
    y = _twosComplement(num2)

    sum = _summer(x, y)

    return sum[::-1]


num1 = input("Enter the first binary number: ")
num2 = input("Enter the second binary number: ")

if len(num1) > len(num2):
    digitsToPad = len(num1) - len(num2)
    num2 = '0' * digitsToPad + num2

else :
    digitsToPad = len(num2) - len(num1)
    num1 = '0' * digitsToPad + num1

result = _subtractor(num1, num2)
print('The result is: ', result)