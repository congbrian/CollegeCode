# -*- coding: utf-8 -*-
#Created by: Brian Cong
#Date: 10/7/16
#Project 05
#Graphing Red Cedar River Flow Rate from USGS Data
import pylab
#parses data into multivariable array
def sortdata(filename):
    file = open_file(filename)
    data = ''
    num_lines = sum(1 for line in open(filename))
    datalist = [[]for i in range(num_lines)]
    linenum = 0
    #datalist = [[-1,-1,-1]for x in file]
    for line in file:
        data = line[26:39]
        datalist[linenum].append(float(data[0:4]))
        datalist[linenum].append(float(data[5:6]))
        datalist[linenum].append(float(data[7:13]))
        linenum+= 1
    file.close()
    return datalist
#opening the file
def annual_average(datalist):
    newlist = [[]for i in range(len(datalist))]
    for i in range (0,len(datalist)-1):
        newlist[i].append(datalist[0][i])
        newlist[i].append(datalist[2][i])
    return newlist
def monthly_average(datalist):
    newlist = [[2]for i in range(len(datalist))]
    for i in range (len(datalist)):
        newlist[0][i] = datalist[1][i]
        newlist[1][i] = datalist[2][i]
    return newlist
def open_file(filename):
    fn = filename
    try:
        file = open(fn)
    except FileNotFoundError:
        print("File not found. Try again")
        fn = input("What is the name of the file which you wish to use? ")
    return file
#Draw plot function
def draw_plot( x, y, plt_title, x_label, y_label):
    ''' Draw x vs. y (lists should have the same length)
    Sets the title of plot and the labels of x and y axis '''
    pylab.title(plt_title)
    pylab.xlabel(x_label)
    pylab.ylabel(y_label)
    
    pylab.plot( x, y )
    pylab.show()
def main():
    filename = input("What is the name of the file which you wish to open? ")
    RedCedarList = sortdata(filename)
    command = ''
    anaverage = annual_average(RedCedarList)
    print (anaverage)
    #draw_plot(anaverage[1], anaverage[2])
    
main()