# Copyright 2017 Wu Sun sunw5@bu.edu
# Copyright 2017 Tianyi Zhang tianyiz@bu.edu

import scipy.io.wavfile as wavfile
from numpy import pi, array, append, cos, fft
from pylab import linspace

def dialer(file_name,frame_rate,phone,tone_time) :

    fs = frame_rate
    t = linspace(0, tone_time, frame_rate * tone_time)
    tone = array([])

    tone1 = {'1': 697, '2': 697, '3': 697, '4': 770, '5': 770, '6': 770, '7': 852, '8': 852, '9': 852, '0': 941}
    tone2 = {'1': 1209, '2': 1336, '3': 1477, '4': 1209, '5': 1336, '6': 1477, '7': 1209, '8': 1336, '9': 1477, '0': 1336}

    i = 1
    for i in range(len(phone)) :
        fre = cos(2 * pi * tone1[phone[i]] * t) + cos(2 * pi * tone2[phone[i]] * t)
        tone = append(tone, fre, axis=0)
    #print(tone1[phone[i]], ' ', tone2[phone[i]])
    wavfile.write(file_name, fs, tone)


#dialer('test.wav', 8000, '1234567890', 0.5)