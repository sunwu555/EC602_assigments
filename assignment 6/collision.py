#!/usr/bin/env python

# Copyright 2017 Wu Sun sunw5@bu.edu

import sys
import math
import numpy as np

indata = []
data = []
outTime = []


class Ball:

    
    def __init__(self, id, xlocation, ylocation, xspeed, yspeed):
    	self.id = id
    	self.xl = float(xlocation)
    	self.yl = float(ylocation)
    	self.xs = float(xspeed)
    	self.ys = float(yspeed)

    def mov(self, movTime) :
        self.xl = self.xl + movTime * self.xs 
        self.yl = self.yl + movTime * self.ys

    def col(self, others):

        global nextColTime
        global currentTime

        g = (self.xs - others.xs)**2 + (self.ys - others.ys)**2

        if g == 0 :
            return 0

        k = 2 * ((self.xl - others.xl) * (self.xs - others.xs) + (self.yl - others.yl) * (self.ys - others.ys)) / g
        l = ((self.xl - others.xl)**2 + (self.yl - others.yl)**2 - 100) / g
        if (k**2 - 4 * l) <= 0 :
            return 0
        else :
            ctime1 = (-k + (k**2 - 4 * l)**0.5) / 2
            ctime2 = (-k - (k**2 - 4 * l)**0.5) / 2
            if ctime2 < 0 :
                return 0
            else :
                localColTime = ctime2
                #print(g,' ',k,' ',l,' ',localColTime)
            if localColTime + currentTime < nextColTime :
                nextColTime = localColTime + currentTime
                return 1
            elif localColTime + currentTime == nextColTime :
                return 2
            else :
                return 0

# nextColTime update

    


def simpleMove(checkNum) :

    global currentTime

    for i in range(len(data)) :
        data[i].mov(outTime[checkNum] - currentTime)
    currentTime = outTime[checkNum]

# currentTime update, currentLocation update


def proceedCol():

    global colList
    global nextColTime
    global currentTime

    for i in range(len(data)) :
        data[i].mov(nextColTime - currentTime)
    currentTime = nextColTime
    for i in range(len(colList)) :
        #print('there should be a collision in ', colList[i][0], 'and ', colList[i][1], 'at time ', currentTime)
        changeColSpeed(data[colList[i][0]], data[colList[i][1]])
        # This part should be the function of the elastic collision 
    nextColTime = outTime[-1] + 1
    colList.clear()

# currentTime update, currentLocation after collision update

def changeColSpeed(a,b) :
    if a.xl == b.xl :
        a.ys, b.ys = b.ys, a.ys
        return()
    if a.yl == b.yl :
        a.xs, b.xs = b.xs, a.xs
        return()
    aspeed = np.array([a.xs, a.ys])
    bspeed = np.array([b.xs, b.ys])
    alocation = np.array([a.xl, a.yl])
    blocation = np.array([b.xl, b.yl])
    anewspeed = aspeed - (( np.dot( aspeed - bspeed, alocation - blocation ))) * ( alocation - blocation ) / 100
    bnewspeed = bspeed - (( np.dot( bspeed - aspeed, blocation - alocation ))) * ( blocation - alocation ) / 100
    a.xs = anewspeed[0]
    b.xs = bnewspeed[0]
    a.ys = anewspeed[1]
    b.ys = bnewspeed[1]

'''
    angle = arccos(abs(a.yl - b.yl) / 10)
    anewXs = a.xs * cos(90 - angle) - a.ys * cos(angle)
    anewYs = a.xs * cos(angle) + a.ys * cos(90 - angle)
    bnewXs = b.xs * cos(90 - angle) - b.ys * cos(angle)
    bnewYs = b.xs * cos(angle) + b.ys * cos(90 - angle)

    anewYs, bnewYs = bnewYs, anewYs

    a.xs = anewYs * cos(angle) + anewXs * cos(90 - angle)
    a.ys = anewYs * cos(90 - angle) - anewXs * cos(angle)
    b.xs = bnewYs * cos(angle) + bnewXs * cos(90 - angle)
    b.ys = bnewYs * cos(90 - angle) - bnewXs * cos(angle)
'''

# curreSpeed (after collision) update
    
def checkCol() :
    global currentTime
    global nextColTime
    for i in range(len(data)-1) :
        for j in range(i+1, len(data)) :
            colstatus = data[i].col(data[j])
            if colstatus == 1 :
                colList.clear()
                colList.append([i,j])
            elif colstatus == 2 :
                colList.append([i,j])
            else :
                pass

# collision list update, in function nextc colision time update

def outLocation(checkNum) :
    print(outTime[checkNum])
    for i in range(len(data)) :
        print(data[i].id, ' ',data[i].xl, ' ',data[i].yl, ' ',data[i].xs, ' ',data[i].ys)

def is_number(s):
    try:
        float(s)
        return True
    except ValueError:
        pass
    try:
        import unicodedata
        unicodedata.numeric(s)
        return True
    except (TypeError, ValueError):
        pass
 
    return False

def return_2() :
    exit(2)

def return_1() :
    exit(1)

'''
def is_good(s) :
    try:
        a, b, c, d, e = line.split()
        return True
    except :
        pass
    return False
'''
#------------Check for Right Inputs of Arguments-------------


for arg in sys.argv[1:] :
    if is_number(arg) :
        if float(arg) < 0 :
            pass
        else :
            outTime.append(float(arg))
    else :
        return_2()

if len(outTime) == 0 :
    return_2()

#---------Check for Right Inputs of Data----------------------

for line in sys.stdin :
    #if line == '' :
    #    print(1)
    #    exit()
    #if is_good(line) :
	a, b, c, d, e = line.split()
	indata.append([a,b,c,d,e])
    #else :
    #    print(1)
    #    exit()

#----------End of Input Checking--------------------------------

outTime.sort()


for i in range(len(indata)) :
	data.append(Ball(indata[i][0], indata[i][1], indata[i][2], indata[i][3], indata[i][4]))


currentTime = 0
colList = []
nextColTime = outTime[len(outTime)-1] + 1

checkCol()

for i in range(len(outTime)) :
    while outTime[i] > nextColTime :
        proceedCol()
        checkCol()
    simpleMove(i)
    outLocation(i)



