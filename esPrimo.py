def isPrime(num):
    if num < 1:
        return False
    elif num == 2:
        return True
    else:
        for i in range(2, num):
            if num % i == 0:
                return False
        return True            

def app():
    num = int(input('Escribe un Número: '))
    result = isPrime(num)

    if result is True:
        print('¡El número es Primo!')
    else:
        print('El número NO es Primo!!')

if __name__ == '__main__':
    app()