# GCD: 최대 공약수
# LCM: 최소 공배수

# python library
# import math
# math.gcd(12, 8)


def _gcd(a, b):
    while a & b != 0: # 나머지가 0이 되면 멈춘다
        tmp = a % b
        a = b
        b = tmp

    return b

def _lcm(a, b):
    return a * b // _gcd(a, b)