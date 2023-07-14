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

multiplicand = input('Enter the value of multiplicand: ')
multiplier = input('Enter the multiplier: ')

count = len(multiplier)
n = count
reg_b = _twosComplement(multiplicand)
reg_a = '0' * count
reg_q = multiplier
reg_q_minus_one = '0'

while count > 0:
    if reg_q[-1] == reg_q_minus_one:
        #ARS
        msb = reg_a[0]
        reg_q_minus_one = reg_q[-1]
        reg_q = reg_a[-1] + reg_q[:n - 1]
        reg_a = msb + reg_a[:n - 1]
    
    elif reg_q[-1] == '1' and reg_q_minus_one == '0':
        # A = A - B then ARS
        reg_a = _summer(reg_a, reg_b)
        msb = reg_a[0]
        reg_q_minus_one = reg_q[-1]
        reg_q = reg_a[-1] + reg_q[:n - 1]
        reg_a = msb + reg_a[:n - 1]

    
    elif reg_q[-1] == '0' and reg_q_minus_one == '1':
        # A = A + B then ARS
        reg_a = _summer(reg_a, multiplicand)
        msb = reg_a[0]
        reg_q_minus_one = reg_q[-1]
        reg_q = reg_a[-1] + reg_q[:n - 1]
        reg_a = msb + reg_a[:n - 1]

    
    count -= 1

print('Answer is: ', reg_a + reg_q)