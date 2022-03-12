#Classifies supernova 
#Skill SWP - A2:

#Sorts file into list of lists
with open('/home/julia/Textfiles/sne.dat') as file:
    next(file)
    all_supernovas = []
    for line in file:
        supernova = [item.strip() for item in line.split()]
        all_supernovas.append(supernova)

#Sorts into type 2 or type 1
type2 = []
type1 = []
for lists in range(len(all_supernovas)):
        if all_supernovas[lists][2] == 'y':
            type2.append(all_supernovas[lists])
        else:
            type1.append(all_supernovas[lists])

#Sorts type two into sub categories
type2_L = []
type2_P = []
for lists in range(len(type2)):
    if type2[lists][1] == 'pla':
        type2_P.append(type2[lists][0])
    else:
        type2_L.append(type2[lists][0])

#Sorts type one into sub categories
type1a = []
type1b = []
type1c = []
for lists in range(len(type1)):
    if type1[lists][3] == 'y':
        type1a.append(type1[lists][0])
    elif type1[lists][4] == 'y':
        type1b.append(type1[lists][0])
    else:
        type1c.append(type1[lists][0])

#Present classified novas
type1_names = [item[0] for item in type1]
type2_names = [item[0] for item in type2]
print('Type 1 Supernovas: ' + str(type1_names))
print('\tType 1a: ' + str(type1a))
print('\tType 1b: ' + str(type1b))
print('\tType 1c: ' + str(type1c))
print('Type 2 Supernovas: ' + str(type2_names))
print('\tType 2_L: ' + str(type2_L))
print('\tType 2_P: ' + str(type2_P)) 

