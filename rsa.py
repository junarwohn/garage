import math

def gcd(n, k):
    if k > n:
        n, k = k, n
    r = n % k
    if r == 0:
        return k
    else:
        return gcd(k, r)

def make_prime(n):
    for i in range(2, n // 2 + 1):
        if n % i == 0:
            return make_prime(n + 1)
    return n

if __name__ == "__main__":
    n1 = int(input())
    n2 = int(input())
    n1 = make_prime(n1)
    n2 = make_prime(n2)
    n = n1 * n2
    print(n1, n2)
    phi_n = (n1 - 1) * (n2 - 1)
    for i in range(2, phi_n):
        if gcd(phi_n, i) == 1:
            e = i
            break
    for i in range(1, phi_n):
        if (i * e) % phi_n == 1:
            d = i
            break
    print(gcd(n1, n2))
    m = int(input())
    print(m)
    enc = (m ** e) % n
    print(enc)
    dec = (enc ** d) % n
    print(dec)