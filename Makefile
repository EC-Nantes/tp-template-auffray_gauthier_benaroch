all : TP_PLU_Note

rebuild : clean all

TP_PLU_Note : main.o point2D.o polygone.o parcelle.o zu.o zau.o za.o zn.o
	g++ -o TP_PLU_Note main.o point2D.o polygone.o parcelle.o zu.o zau.o za.o zn.o
	del *.o

main.o : main.cpp 
	g++ -o main.o -c main.cpp

point2D.o : point2D.cpp point2D.h
	g++ -o point2D.o -c point2D.cpp

polygone.o : polygone.cpp polygone.h
	g++ -o polygone.o -c polygone.cpp

parcelle.o : parcelle.cpp parcelle.h
	g++ -o parcelle.o -c parcelle.cpp

zu.o : zu.cpp zu.h constructible.h
	g++ -o zu.o -c zu.cpp

zau.o : zau.cpp zau.h constructible.h
	g++ -o zau.o -c zau.cpp

za.o : za.cpp za.h
	g++ -o za.o -c za.cpp

zn.o : zn.cpp zn.h
	g++ -o zn.o -c zn.cpp

clean :
	del *.o

#Pour ensuite executer : mingw32-make all puis .\TP_PLU_Note.exe