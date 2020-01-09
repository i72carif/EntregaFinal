CFLAGS = -c

ejecutable.exe: Main.o
	$(CXX) Main.o -o ejecutable.exe

Main.o: Main.cpp
	$(CXX) $(CFLAGS) Main.cpp

clean:
	$(RM) *.o eje core
