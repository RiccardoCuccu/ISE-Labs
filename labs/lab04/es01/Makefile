### Implicit Rules
CFLAGS_x86= -Wall -static
CFLAGS_Arm= -Wall --specs=nosys.specs
CFLAGS= -Wall

### Exe file
drawer: Drawer-$(PREFIX).o draw-$(PREFIX).o CommandInterpreter-$(PREFIX).o
	@case $(PREFIX) in \
		x86_64-redhat-linux) \
			$(PREFIX)-gcc $(CFLAGS_x86) -o $@ $^;; \
		arm-none-eabi) \
			$(PREFIX)-gcc $(CFLAGS_Arm) -o $@ $^;; \
		*) \
			echo Compiler not found;; \
	esac

Drawer-$(PREFIX).o: Drawer.c
	$(PREFIX)-gcc $(CFLAGS) -c $< -o $@

draw-$(PREFIX).o: draw.c draw.h
	$(PREFIX)-gcc $(CFLAGS) -c $< -o $@

CommandInterpreter-$(PREFIX).o: CommandInterpreter.c CommandInterpreter.h
	$(PREFIX)-gcc $(CFLAGS) -c $< -o $@

### Cleanup
clean:
	@rm -f *.o drawer 

### Target test
target_test:
	@touch diff_mod.txt
	@$(PREFIX)-gcc $(CFLAGS) -D TESTING -o drawer Drawer.c draw.c CommandInterpreter.c
	@echo --Testing Point Drawing--
	@echo P0010011 | ./drawer
	@diff -c output.txt ./test_files/pointtest.txt > ./diff_mod.txt
	@if ! [ -s ./diff_mod.txt ] ; then echo "Point Test OK"; else echo "Point Test Failed"; fi
	@echo --Testing Line Drawing--
	@echo L0000001271271 | ./drawer
	@diff -c output.txt ./test_files/linetest.txt > ./diff_mod.txt
	@if ! [ -s ./diff_mod.txt ]; then echo "Line Test OK"; else echo "Line Test Failed"; fi
	@echo --Testing Ellipse Drawing--
	@echo E0630630100201 | ./drawer
	@diff -c output.txt ./test_files/ellipsetest.txt > ./diff_mod.txt
	@if ! [ -s ./diff_mod.txt ]; then echo "Ellipse Test OK"; else echo "Ellipse Test Failed"; fi
	@rm output.txt
	@rm diff_mod.txt
