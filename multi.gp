
# Test multiplot for running latency on Raspberry pi
# gnuplot -e 'output_file="/path/to/output.png";graph_title="title text"' /path/to/histo.gp
# gnuplot -e 'output_file="output.png";graph_title="fibonacci-time consuming"' multi.gp
#
# where the input file is generated using latency option "-g"
#
 
set terminal png size 900,700
set output output_file
 
set title graph_title
set xlabel "x of fibonacci"
set ylabel "Time-nanoseconds"
#set logscale y
set grid

set bar 1.000000
set style fill  solid 1.00 border -1
set style rectangle back fc lt -3 fillstyle  solid 1.00 border -1                                                                                                   
 
#plot "usrlatlog" w line,"kernellatlog" w line,"IRQlatlog" w line
plot "time" w linespoints,"time_recursive" w linespoints,"time_original" w linespoints

