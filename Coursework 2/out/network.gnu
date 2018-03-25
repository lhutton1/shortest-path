
plot 'out/network.out' u 1:2:3 with lines lc rgbcolor variable lw 1 notitle,\
'out/network.out' u 1:2:(0.00003) with circles fill solid lc rgb "black" notitle
