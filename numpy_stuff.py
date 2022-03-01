#Plays around with numpy functions

import numpy as np
#empty_array = np.empty(3)
#print(empty_array)

#zero_array = np.zeros(3)
#print(zero_array)

#two_d = np.array([[1,2],[3,7]])
#print(two_d)

#add_value = two_d + 2
#print(add_value)

#multiply_value = two_d * 2
#print(multiply_value)

array_one = np.array([1,2,3,4,5])
array_two = np.array([-1, 2, -3, 4, -5])
print("Array One: " + str(array_one))
print("Array Two: " + str(array_two))
combo_array = array_one * array_two
print("Array One * Array Two = " + str(combo_array))

#normal_array = [0,1,2,3,4,5]
#print("Array before multiplying by 2: " + str(normal_array))
#for num in normal_array:
#    num * 2
#print("Array after multiplying by 2: " + str(normal_array))
