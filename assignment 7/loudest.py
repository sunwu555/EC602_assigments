# Copyright 2017 Wu Sun sunw5@bu.edu
# Copyright 2017 Tianyi Zhang tianyiz@bu.edu

import numpy as np
from math import ceil

def loudest_band(music,frame_rate,bandwidth):
    
    loudestBand = 0
    musicFre = np.fft.fft(music)
    musicLength = len(musicFre)
    simpleGap = frame_rate / musicLength
    bandLength = ceil(bandwidth / simpleGap)
    musicBandLength = ceil((musicLength / 2) - bandLength)
    bandPowerSum = sum((abs(musicFre[0 : bandLength]) ** 2)) #powersum of the band from the 0Hz to the bandlength

#-------------------- check the loudest band --------------------#
    maxPower = bandPowerSum
    for i in range(musicBandLength):
    	a = bandPowerSum - (abs(musicFre[i]) ** 2) + (abs(musicFre[i + bandLength]) ** 2)
    	if a > maxPower :
    		loudestBand = i + 1
    		bandPowerSum = a
    		maxPower = a
    	else:
            bandPowerSum = a
#------------------ end of check the loudest band ---------------#

#------- generate the music from the selected loudest band ------#
    loudestBandFre = [0] * musicLength
    loudestBandFre[loudestBand : loudestBand + bandLength + 1] = musicFre[loudestBand : loudestBand + bandLength + 1]
    loudestBandFre[-(loudestBand + bandLength - musicLength) : -(loudestBand - musicLength) + 1] = musicFre[-(loudestBand + bandLength - musicLength) : -(loudestBand - musicLength) + 1]
    loudestMusic = np.fft.ifft(loudestBandFre)
#--- end of generate the music from the selected loudest band ---#

    simpleAmount = np.linspace(0, frame_rate, musicLength + 1)
    low = simpleAmount[loudestBand]
    high = simpleAmount[loudestBand + bandLength]
    return low, high, loudestMusic
