vlib work

vcom constants.vhd
vcom full_adder.vhd
vcom ripple_carry_adder.vhd
vcom rca_tb.vhd

vsim -c work.rca_tb

#add list -decimal clk -notrigger a b c cout sum

run 0ns
run 10ms

#write list counter.lst
quit -f
