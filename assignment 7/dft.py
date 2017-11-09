# Copyright 2017 Wu Sun sunw5@bu.edu
# Copyright 2017 Tianyi Zhang tianyiz@bu.edu


from numpy import zeros, exp, array, pi


def DFT(x):
    if type(x) == dict:
        raise ValueError
    try:
        DFT_list = []
        k = 0
        for k in range(len(x)) :
            DFT_n = 0
            for i in range(len(x)) :
                DFT_n += x[i] * exp(-1j * ((2 * pi * i * k) / len(x)))
            DFT_list.append(DFT_n)
            DFT = array(DFT_list)
        return DFT
    except TypeError:
        raise ValueError
        return
