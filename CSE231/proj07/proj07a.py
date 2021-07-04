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
    
    
def makedicts(data, finaldicts):
    #make nested/multivar dictionaries for holding city and highway mileage
    for brand, year, citymil, hwymil in data:
        finaldicts[brand][year]['city'].append(citymil)
        finaldicts[brand][year]['highway'].append(hwymil)
    return finaldicts
    
    
def average(numbers):
    total = sum(numbers)
    total = float(total)
    return (total/len(numbers))
    
    
    
    
brands = {'ford': 'mercury ford lincoln', 'gm': 'saturn buick chevrolet gmc oldsmobile pontiac cadillac', 'honda': 'honda acura', 'toyota' : 'lexus scion toyota'}
inf = open_file()
vals = read_file(inf, brands)
finaldicts = defaultdict(lambda:defaultdict(lambda:defaultdict(list,(('city',[0]),('highway',[0])))))
finaldicts = makedicts(vals, finaldicts)
print(finaldicts.keys())
datalist = list()
for item in finaldicts:
    print(finaldicts.index(item))
    #tup = (finaldicts.index(item), average(item[0].items()))
    #datalist.append(tup)
print(datalist)
#plotting.plotmileage()
#run code