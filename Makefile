all : TP_PLU_Note

rebuild : clean all

TP_PLU_Note : main.o point2D.o polygone.o parcelle.o
	g++ -o TP_PLU_Note main.o point2D.o polygone.o parcelle.o
	del *.o

main.o : main.cpp 
	g++ -o main.o -c main.cpp

point2D.o : point2D.cpp 
	g++ -o point2D.o -c point2D.cpp

polygone.o : polygone.cpp
	g++ -o polygone.o -c polygone.cpp

parcelle.o : parcelle.cpp
	g++ -o parcelle.o -c parcelle.cpp

clean :
	del *.o

#Pour ensuite executer : mingw32-make all puis .\TP_PLU_Note.exe