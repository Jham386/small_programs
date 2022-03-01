#Takes a user's list and asks how they want to change it

#Get's the user's list
def get_list():
        print("\n")
        print("Hi! This program takes every number in your list and scales them in a way you'd like.")
        print("Enter the numbers you want in your list, and enter D when you're done: ")
        print("To quit, enter Q.")

        your_list = []
        counter = 1
        element = "nothin"
        while True:
                element = input(str(counter) + ": ")
                if element == "D" or element == "d":
                        break
                if element == "Q" or element == "q":
                        raise Exception("User quit program!")
                
                your_list.append(element)
                counter += 1
        
        new_list = []
        for n in your_list:
                try:
                        n = float(n)
                        new_list.append(n)
                except ValueError:
                        print("Your list can only have numbers!")
                        continue
                        
        print("Your list: " + str(new_list))
        return new_list

#Checks to see if they want to raise to power, multiply/divide, add/subtract
def get_choice():
        print("\n")
        print("Choose one:\nRaise to a power:       P\nMultiply/Divide it:     M\nAdd/Subtract from it:   A")
        your_scale = input("Your choice: ")

        #Checks to see if user inputed a valid option
        choices = ["P", "p", "M", "m", "A", "a"]
        x = False
        while x == False:
                if your_scale not in choices:
                        print("Please enter a valid choice. Must be either P, p, M, m, A, or A.")
                        your_scale = input("Re-enter your choice: ")
                else:
                        x = True
        return your_scale

#Gets number how they want to scale it
def get_num(your_scale):
        print("\n")
        if your_scale == "P" or your_scale == "p":
                num_scale = input("What power would you like to raise the list to? ")
        elif your_scale == "M" or your_scale == "m":
                print("Note: to divide, use fractions.")
                num_scale = input("What number would you like to multiply/divide by? ")
        else:
                print("Note: If you would like to subtract, enter it as a negative number.")
                num_scale = input("What number would you like to add/subtract from your list? ")

 #Check to see if num_scale is int or float:
        while True:
                try:
                        is_num = float(num_scale)
                except ValueError:
                        num_scale = input("You haven't entered a number! Please retry: ")
                        continue
                else:
                        break
        return num_scale
            
#Inputs a list and how you want to change it
def change_list(new_list, your_scale, num_scale):
        final_list = []
        for item in new_list:
                if your_scale == "P" or your_scale == "p":
                        num_scale = int(num_scale)
                        final_list.append(item ** num_scale)
                elif your_scale == "M" or your_scale == "m":
                        num_scale = float(num_scale)
                        final_list.append(item * num_scale)
                else:
                        num_scale = float(num_scale)
                        final_list.append(item + num_scale)
        print("\n")
        print("Here is your new list: ")
        print(final_list)

#Executes all functions
def main():
        the_list = get_list()
        the_choice = get_choice()
        the_num = get_num(the_choice)
        change_list(the_list, the_choice, the_num)

#Executes them
main()
