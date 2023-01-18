all : TP_PLU_Note

rebuild : clean all

TP_PLU_Note : main.o point2D.o polygone.o parcelle.o zu.o zau.o za.o zn.o carte.o
	g++ -o TP_PLU_Note main.o point2D.o polygone.o parcelle.o zu.o zau.o za.o zn.o carte.o

main.o : main.cpp 
	g++ -o main.o -c main.cpp

point2D.o : point2D.cpp
	g++ -o point2D.o -c point2D.cpp

polygone.o : polygone.cpp
	g++ -o polygone.o -c polygone.cpp

parcelle.o : parcelle.cpp
	g++ -o parcelle.o -c parcelle.cpp

zu.o : zu.cpp
	g++ -o zu.o -c zu.cpp

zau.o : zau.cpp
	g++ -o zau.o -c zau.cpp

za.o : za.cpp
	g++ -o za.o -c za.cpp

zn.o : zn.cpp
	g++ -o zn.o -c zn.cpp

carte.o : carte.cpp
	g++ -o carte.o -c carte.cpp

clean :
	del *.o

#Pour ensuite executer : mingw32-make all puis .\TP_PLU_Note.exe