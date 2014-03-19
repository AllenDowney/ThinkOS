""" Example code for Think OS.

This program plots results from cache.c

To use it:

gcc -o cache cache.c
./cache > cache_data
python graph_data.py

It depends on thinkplot.py and matplotlib

Copyright 2014 Allen Downey
License: GNU GPLv3

"""

import thinkplot
import matplotlib.pyplot as pyplot

d = {}
for line in open('cache_data'):
    t = line.split()
    size, stride, time = int(t[1]), int(t[3]), float(t[5])
    d.setdefault(stride, []).append((size, time))


thinkplot.PrePlot(num=7)
for stride in reversed(sorted(d.keys())):
    xs, ys = zip(*d[stride])
    thinkplot.plot(xs, ys, label=str(stride)+' B')

pyplot.xscale('log', basex=2)
thinkplot.save(root='cache_data',
               xlabel='size (B)',
               ylabel='average penalty (ns)')
