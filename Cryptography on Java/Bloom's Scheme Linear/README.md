# Bloom Linear
<br><br>
Bloom's protocol for exchanging keys on an insecure channel<br>
We choose the number of users<br>
n = 3, p> n<br>

1. We choose p-prime, a, b, c - prime numbers<br>
p = 187, a = 3, b = 19, c = 23<br>

2. We choose the public keys for users in the range of Zp<br>
Users: 1, 2, 3<br>
Public keys: r1 = 29, r2 = 53 r3 = 17<br>

3. We construct the polynomial for calculating the information transmitted through the secret channel<br>
f (x, y) = (a + b (x + y) + c * x * y) mod p = (3 + 19 (x + y) + 23 * x * y) mod 187<br>

4. Calculate the polynomials (secret keys):<br>
G1 = (x, r1) = (3 + 19 (x + 29) + 23 * x * 29) mod 187 = (3 + 19x + 551 + 667x) mod 187 = (686x + 554) mod 187<br>
G2 = (x, r2) = (3 + 19 (x + 53) + 23 * x * 53) mod 187 = (3 + 19x + 1007 + 1219x) mod 187 = (1238x + 1010) mod 187<br>
G3 = (x, r3) = (3 + 19 (x + 17) + 23 * x * 17) mod 187 = (3 + 19x + 323 + 391x) mod 187 = (410x + 326) mod 187<br>

5. We calculate public keys<br>
Gn (x) = f (x, ru), if u = v, then Ku, v = Ku, v = (ru, rv)<br>
r1 => r2, r3<br>
K (1, 2) = f (G1, r2) = (686x + 554) mod 187 = (686r2 + 554) mod 187 = (686 * 53+ 554) mod 187 = 73<br>
K (1, 3) = f (G1, r3) = (686x + 554) mod 187 = (686r3 + 554) mod 187 = (686 * 17+ 554) mod 187 = 61<br>
r2 => r1, r3<br>
K (2, 1) = f (G2, r1) = (1238x + 1010) mod 187 = (1238 r1 + 1010) mod 187 = (1238 * 29 + 1010) mod 187 = 73<br>
K (2, 3) = f (G2, r3) = (1238x + 1010) mod 187 = (1238 r3 + 1010) mod 187 = (1238 * 17 + 1010) mod 187 = 177<br>
r3 => r1<br>
K (3, 1) = f (G3, r1) = (410x + 326) mod 187 = (410 r1 + 326) mod 187 = (410 * 29 + 326) mod 187 = 61<br>
K (3, 2) = f (G3, r2) = (410x + 326) mod 187 = (410 r2 + 326) mod 187 = (410 * 53 + 326) mod 187 = 177<br>
