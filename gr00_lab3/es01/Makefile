### x86_64 exe files
drawer: Drawer.o draw.o CommandInterpreter.o
	gcc -Wall -static -g -o drawer Drawer.o draw.o CommandInterpreter.o

Drawer.o: Drawer.c
	gcc -Wall -static -g -c Drawer.c

draw.o: draw.c draw.h
	gcc -Wall -static -g -c draw.c

CommandInterpreter.o: CommandInterpreter.c CommandInterpreter.h
	gcc -Wall -static -g -c CommandInterpreter.c

### Arm exe files
drawer_arm: Drawer_arm.o draw_arm.o CommandInterpreter_arm.o
	arm-none-eabi-gcc -Wall -specs=nosys.specs -o drawer_arm Drawer_arm.o draw_arm.o CommandInterpreter_arm.o

Drawer_arm.o: Drawer.c
	arm-none-eabi-gcc -Wall -c Drawer.c -o Drawer_arm.o

draw_arm.o: draw.c draw.h
	arm-none-eabi-gcc -Wall -c draw.c -o draw_arm.o

CommandInterpreter_arm.o: CommandInterpreter.c CommandInterpreter.h
	arm-none-eabi-gcc -Wall -c CommandInterpreter.c -o CommandInterpreter_arm.o

### Cleanup
clean:
	rm *.o

