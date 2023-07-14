def _xor(a, b):
    return (a and not b) or (not a and b)

def _fullAdder(a, b, c):
    sum = str(int(_xor(a, _xor(b, c))))
    carry = str(int((a and b) or (_xor(a, b) and c)))
    return sum, carry


num1 = input("Enter the first binary number: ")
num2 = input("Enter the second binary number: ")

if len(num1) > len(num2):
    digitsToPad = len(num1) - len(num2)
    num2 = '0' * digitsToPad + num2

else :
    digitsToPad = len(num2) - len(num1)
    num1 = '0' * digitsToPad + num1


sum = ""
carry = 0

for i in range(len(num1) - 1, -1, -1):
    temp_sum, carry = _fullAdder(int(num1[i]), int(num2[i]), int(carry))
    sum += temp_sum

if carry == '1':
    print('The result is: ', carry + sum[::-1])

else:
    print('The result is: ', sum[::-1])

