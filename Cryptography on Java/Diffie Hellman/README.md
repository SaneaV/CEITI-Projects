# Diffie-Hellman

![Diffie-Hellman](https://miro.medium.com/max/8000/1*_aF4uglKXQ1DY-5a8lw37A.png)

User Alice generates value p = 11 <br>
The smallest primitive root modulo for 11 is g = 2 <br>

Alice's secret key is a = 5 <br>
Bob's secret key is b = 13 <br>

Alice's public key is A = pow(g,a) (%)mod p => pow(2,5) (%)mod 11 = 10 <br>
Alice's public key is B = pow(g,b) (%)mod p => pow(2,13) (%)mod 11 = 8 <br>

Alice and Bob exchanged with keys <br>

Alice are trying to calculate K(A) = pow(B,a) (%)mod p => pow(8,5) (%)mod 11 = 10 <br>
Bob are trying to calculate K(B) = pow(A,b) (%)mod p => pow(10,13) (%)mod 11 = 10 <br>

The result is K(A) = K(B) => 10 = 10 <br>
