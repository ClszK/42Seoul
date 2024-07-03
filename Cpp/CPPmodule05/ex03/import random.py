import random


class Prime:
    def mod_exp(self, a : int, e : int, n : int) -> int:
            x = format(e,"b")
            s = 1
            for k in range(0,len(x)):
                s = pow(s,2,n)          # square
                if x[k] == '1':         # multiple
                    s = s * a % n
                elif x[k] == '0':       
                    continue
            return s


    def miller_rabin_test(self, n : int, b : int, s : int, t : int) -> bool:
        if b == 1:      # FLT
            return 1
        
        for i in range(s-1):
            if b == n - 1:  # FLT
                return 1
            
            b = pow(b, 2, n) # 모듈러 연산 
            
        return b == n-1
    
    def is_prime(self, n : int) -> bool:
        # n - 1 = 2^s * t의 값을 구하는 과정이다.
    
        s = 0
        t = n - 1
        
        while t % 2 == 0:
            s += 1
            t //= 2

        #20번의 반복으로 소수로 판별되었지만 합성수일 확률을(1/4)^20로 낮춘다. 
        for i in range(20):
            randomVal = random.randrange(2, n - 1)
            
            b = self.mod_exp(randomVal,t,n)
            
            if self.miller_rabin_test(n, b, s, t) == 0:
                return 0
        return 1

test = Prime()
print("is_prime(561) : ", test.is_prime(561))
print("is_prime(569) : ", test.is_prime(569))
print("is_prime(2**(2**4)+1) : ", test.is_prime(2**(2**4)+1))
print("is_prime(2**(2**10)+1) : ", test.is_prime(2**(2**10)+1))
print("is_prime(2**1279-1) : ", test.is_prime(2**1279-1))
print("is_prime(2**2203-1) : ", test.is_prime(2**2203-1))
print("is_prime(2**3217-1) : ", test.is_prime(2**3217-1))