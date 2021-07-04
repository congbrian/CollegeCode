# -*- coding: utf-8 -*-
"""
Created on Fri Oct 28 16:18:47 2016

@author: congbria
"""
from collections import defaultdict
import csv, plotting

def open_file():
    #open file with catches
    while True:
        try:
            fp = input("Select a decade. ")
            if fp.isalpha():
                raise Exception("This is not a year.")
            if (int(fp) > 2010) or (int(fp) < 1980):
                raise ValueError
            fp = fp + "s.csv"
            in_file = open( fp, "r" )
            inf = csv.reader(in_file)
            break
        except IOError:
            print( "\n*** unable to open file ***\n" )
            in_file.close()
        except ValueError:
            print("\n*** This year is invalid. ***\n")            
    return inf
    
    
def read_file(inf, brands):
    #read line-by-line
    count = 0
    rets = []
    for line in inf:
        if count > 0:
            vals = [line[46].lower(), line[63], line[4], line[34]]
            rets.append(vals)
        count+= 1
    rets = manfacts(rets, brands)
    return rets
        
def manfacts(data, dicts):
    #sort out manufacturer data
    sorteddicts = []
    for l in data:
        for brand, subs in dicts.items():
            if l[0] in subs:
                l[0] = brand
                sorteddicts.append(l)
    return sorteddicts
    
def merge_dicts(data):
    finaldicts = defaultdict(lambda:defaultdict(lambda:defaultdict(list,(('city',[0]),('highway',[0])))))
    count = 0
    #make nested/multivar dictionaries for holding city and highway mileage
    for brand, year, citymil, hwymil in data:
        finaldicts[brand][year]['city'].append(citymil)
        finaldicts[brand][year]['highway'].append(hwymil)
    #testing purposes
    for brand in finaldicts:
        for year in finaldicts[brand]:
            for city in finaldicts[brand][year]:
                for mileage in finaldicts[brand][year][city]:
                    count+=1
    return finaldicts    
   
def average(numbers):
    total = sum(numbers)
    total = float(total)
    return (total/len(numbers))

def yravg(dictdata):
    cityvals = 0
    hwyvals = 0
    hwyyravgs = defaultdict(lambda:list())
    cityyravgs = defaultdict(lambda:list())
    for brand in dictdata:
        citytuplist = []
        hwytuplist = []
        for year in dictdata[brand]:
            cityyearmil = 0
            hwyyearmil = 0
            for types in dictdata[brand][year]:
                for mileage in dictdata[brand][year][types]:
                    if types == 'city':
                        cityyearmil += int(mileage)
                        cityvals += 1
                    if types == 'highway':
                        hwyyearmil += int(mileage)
                        hwyvals +=1
            citytuplist.append((year,int(cityyearmil/cityvals)))
            hwytuplist.append((year,int(hwyyearmil/hwyvals)))
            cityvals = 0
            hwyvals = 0
        citytuplist.sort()
        hwytuplist.sort()
        for item in citytuplist:
            print(citytuplist[citytuplist.index(item)][1])
            cityyravgs[brand].update(citytuplist[citytuplist.index(item)][1])
            hwyyravgs[brand].update(hwytuplist[citytuplist.index(item)][1])
    return cityyravgs, hwyyravgs
    
def years(dictdata):
    yearlist = []
    for brand in dictdata:
        for year in dictdata[brand]:
            yearlist.append(year)
    return list(set(yearlist))
brands = {'ford': 'mercury ford lincoln', 'gm': 'saturn buick chevrolet gmc oldsmobile pontiac cadillac', 'honda': 'honda acura', 'toyota' : 'lexus scion toyota'}
inf = open_file()
vals = read_file(inf, brands)
dicts = merge_dicts(vals)
cityyravgs, hwyyravgs = yravg(dicts)
yearlist = sorted(years(dicts))
print('Years',yearlist, '\nCity year averages:',cityyravgs.items(),'\nHighway year averages:', hwyyravgs.items())
#plotting.plot_mileage(yearlist,cityyravgs,hwyyravgs)
'''for item in cityyravgs:
    print(int(average(cityyravgs[item])), item,'City')
    print(int(average(hwyyravgs[item])), item,'Highway')    
    '''