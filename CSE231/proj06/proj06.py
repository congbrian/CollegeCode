__author__ = 'Brian'
#Still lacking some values.
#There are more minorities executed, and more minorities commiting crimes on whites executed.
import csv
import copy
def open_file(fp):
    while True:
        try:
            file = open(fp)
            return file
        except FileNotFoundError:
            print("File not found.")
            fp = input("Try again? ")
            if fp.lower() == "quit":
                break
            else:
                continue
def read_file(fp):
    file = open_file(fp)
    csv_fp = csv.reader(file)
    list = []
    x = 0
    for line in csv_fp:
        if x >= 1:
            holder = (line[15],line[16], line[27])
            list.append(holder)
        x += 1
    return(list)
def main():
    stats = [[]for x in range(2)]
    fp = input("Enter a file name. ")
    data = read_file(fp)
    racelist = []
    genderlist = []
    victimlist = []
    for item in range(data.__len__()):
        racelist.append(data[item][0].lower())
        genderlist.append(data[item][1].lower())
        victimlist.append(data[item][2].lower())
    racetypes = list(set(racelist))
    gendertypes = list(set(genderlist))
    victimtypes = list(set(victimlist))
    gendertypes.remove('not available')
    victimtypes.remove('not available')
    minorities = copy.deepcopy(racetypes)
    minorities.remove('white')
    print(gendertypes,victimtypes)
    racedata = [[0]for race in range(len(racetypes))]
    for offenderrace in racelist:
        for race in racetypes:
            if offenderrace == race:
                racedata[racetypes.index(offenderrace)][0] += 1
    #More generalized solution, allowing for a more detailed demographic.
    #Specific answer to problem 1 below
    white = racedata[(racetypes.index('white'))][0]
    minority = racedata[racetypes.index('black')][0]+racedata[racetypes.index('hispanic')][0]+racedata[racetypes.index('other')][0]
    print("Amount of whites executed:", white, "\nAmount of minorities executed:", minority)
    minority_on_white = 0
    white_on_minority = 0
    #print (minorities)
    for item in data:
        lst = list(item)
        for x in range(lst.__len__()):
            lst[x] = lst[x].lower()
        if (lst[0] in minorities) and ('white' in lst[2]):
            minority_on_white += 1
        elif (lst[0] in 'white') and (lst[2] in minorities):
            white_on_minority+= 0
    print('Amount of minorities on whites executed:',minority_on_white,'Amount of whites on minorities:', white_on_minority)
    female_on_male = 0
    male_on_female = 0
    for item in data:
        lst = list(item)
        for x in range(len(lst)):
            lst[x] = lst[x].lower()
        if (lst[1] in 'male') and (lst[2] in 'female'):
            male_on_female += 1
        elif (lst[1] in 'female') and (lst[2] in 'male'):
            male_on_female += 1
    print(male_on_female, female_on_male)
main()