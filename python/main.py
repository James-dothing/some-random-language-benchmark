import time

def check(n, used_f):
    for prime_number in used_f:
        if prime_number * prime_number > n:
            return True
        if n % prime_number == 0:
            return False
    return True

used = []
current_number = 3
maxium_number = 50000000
starting_time = time.time()

while current_number <= maxium_number:
    if check(current_number, used):
        # print(current_number)
        used.append(current_number)
    current_number += 2

print("total time: ", time.time() - starting_time)
print("total prime number: ", len(used) + 1)