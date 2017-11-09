# Copyright 2017 Wu Sun sunw5@bu.edu

import numpy
from numpy import fft,array,real,zeros_like,linspace
from random import randint
from math import ceil

def loudest_band(music,frame_rate,bandwidth):

    "define low and high f"
    global f_low
    global f_high
    "store the lowest f for loudest part"

    index = [0]

    "length of signal"
    x_fre = fft.fft(music)
    n = len(x_fre)

    "intervel between each two signal"
    intervel = frame_rate/(n)
    frequency = linspace(0,frame_rate,n+1)

    "length of BW"
    n_bw = ceil(bandwidth/intervel)

    "Initial value of loudest part"
    sum_bw = (abs(x_fre[0:n_bw])**2).sum()
    index[0] = 0

    "Interation of loudest part"
    Max = sum_bw
    for i in range(ceil((n/2)-n_bw)):
        Sum = sum_bw-(abs(x_fre[i])**2)+(abs(x_fre[i+n_bw])**2)      
        if Sum > Max:
            sum_bw = Sum
            Max = Sum
            index[0] = i+1
        else:
            sum_bw = Sum

    "locate the lowest boundary"
    a = index[0]

    "reconstruct the signal"
    x_filter = [0]*n
    x_filter[a:a+n_bw+1]=x_fre[a:a+n_bw+1]
    x_filter[-a-n_bw+n:-a+n+1]=x_fre[-a-n_bw+n:-a+n+1]
    C_loud = fft.ifft(x_filter)
    "determine the lowest and highest frequency"
    
    f_low = frequency[a]
    f_high = frequency[a+n_bw]
    return f_low,f_high,C_loud