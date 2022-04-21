#Takes integral of a given function and limits

def funct(x):
    return x**4 - 2*x + 1

def integral(a, b):
    #Set error info
    okay_error = .0001
    actual_value = 4.4
    #unreasonably high so will begin loop
    error_level = 6000
    #Start at just one step 
    n = 1
    
    while (error_level > okay_error):
        h = (b -a) / n
        answer_part_one = (h/2)*funct(a) + (h/2)*funct(b)
        big_sum = 0
        k = 1
        while k < n:
            big_sum += funct(a + h*k)
            k += 1
        answer_part_two = h*big_sum
        answer = answer_part_one + answer_part_two

        #Write over old error/n info, so loop may continue if needed 
        error_level = abs(answer - actual_value)
        n = n*2
    print(answer)
    print(n)
    return answer

integral(0,2)
