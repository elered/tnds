LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

main : main.cc randomgen.h
	g++ -o main main.cc ${INCS} ${LIBS} 
	
mainbello : mainbello.cc randomgen.h
	    g++ -o mainbello mainbello.cc ${INCS} ${LIBS} 

clean:
	rm main.cc
