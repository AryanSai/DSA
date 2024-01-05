def add(digits):
    i = len(digits) - 1
    while i >= 0:
        digits[i] += 1
        if digits[i] <= 9:
            return digits
        else:
            carry = digits[i] / 10
            digits[i] = 0
            i -= 1
    if carry > 0:
        return [carry] + digits
    return digits

digits = [1,2,3]
print(add(digits))