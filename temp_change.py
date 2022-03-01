#Takes user input for celsius and converts to farenheit

c_temp = input("Enter temp in celsius here: ")

#checks to make sure is a num
while True:
    try:
        c_temp = float(c_temp)
        break
    except ValueError:
        print("Must be a number!")
        c_temp = input("Re-enter here: ")
        continue

print("\n")
f_temp = (c_temp * (9/5)) + 32
print("Temperature in Farenheit: " + str(f_temp))
