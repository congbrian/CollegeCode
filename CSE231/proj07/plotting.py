# -*- coding: utf-8 -*-
"""
Created on Sat Oct 22 16:15:39 2016

@author: enbody
"""

import pylab
import matplotlib.patches as patches

def plot_mileage(years,city,highway):
    '''Plot the city and highway mileage data.
       Input: years, a list of years;
              city, a dictionary with manufacturer as key and list of annual mileage as value;
              highway, a similar dictionary with a list of highway mileage as values.
       Requirement: all lists must be the same length.'''
    pylab.figure(1)
    pylab.plot(years, city['Ford'], 'r-', years, city['GM'], 'b-', years,
             city['Honda'], 'g-', years, city['Toyota'], 'y-')
    red_patch = patches.Patch(color='red', label='Ford')
    blue_patch = patches.Patch(color='blue', label='GM')
    green_patch = patches.Patch(color='green', label='Honda')
    yellow_patch = patches.Patch(color='yellow', label='Toyota')
    pylab.legend(handles=[red_patch, blue_patch, green_patch, yellow_patch])
    pylab.xlabel('Years')
    pylab.ylabel('City Fuel Economy (MPG)')
    pylab.show()
    
    # Plot the highway mileage data.
    pylab.figure(2)
    pylab.plot(years, highway['Ford'], 'r-', years, highway['GM'], 'b-', years,
             highway['Honda'], 'g-', years, highway['Toyota'], 'y-')
    pylab.legend(handles=[red_patch, blue_patch, green_patch, yellow_patch])
    pylab.xlabel('Years')
    pylab.ylabel('Highway Fuel Economy (MPG)')
    pylab.show()
    