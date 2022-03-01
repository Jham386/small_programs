#Gets name and age of user.


print("Hello World!")
your_name = input("What is your name? ")
print("Hello " + your_name + "!")

your_age = input("How old are you? ")

if your_age.isdigit() == True:
    print("That's cool! I am ageless, since I'm a computer.")
else:
    while your_age.isdigit() == False:
        print("Your age must be an integer!")
        your_age = input("How old are you? ")
    print("That's cool! I am ageless, since I'm a computer.")
