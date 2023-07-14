def _xor(a, b):
    return (a and not b) or (not a and b)

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

def _fullAdder(a, b, c):
    sum = str(int(_xor(a, _xor(b, c))))
    carry = str(int((a and b) or (_xor(a, b) and c)))
    return sum, carry

def _summer(num1, num2):
    sum = ""
    carry = 0

    for i in range(len(num1) - 1, -1, -1):
        temp_sum, carry = _fullAdder(int(num1[i]), int(num2[i]), int(carry))
        sum += temp_sum
    
    return sum[::-1]


reg_q = input('Enter the value of dividend: ')
reg_b = '0' + input('Enter the value of divisor: ')
reg_a = '00000'

twos_b = _twosComplement(reg_b)
count = len(reg_q)

#loop
while count > 0:
    reg_a = reg_a[1:] + reg_q[0]
    reg_q = reg_q[1:]

    reg_a = _summer(reg_a, twos_b)

    if reg_a[0] == '0':
        reg_q += '1'

    else:
        reg_q += '0'
        reg_a = _summer(reg_a, reg_b)

    count -= 1

print('Quotient (Q): ', reg_q)
print('Remainder (A): ', reg_a)

