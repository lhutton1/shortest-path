set term 'png'
set terminal png size 1500,1100
set style line 1 lc rgb 'black' pt 5 ps 0.2

plot 'out/network.out' u 1:2:3 with lines lc rgbcolor variable lw 1 notitle,\
'out/network.out' with points ls 1 notitle
