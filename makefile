build:
	rm -f ./a.out
	g++ -std=c++17 -g -Wall main.cpp rekognition.o -lm -lstdc++fs -Wno-unused-variable -Wno-unused-function

run:
	./a.out

valgrind:
	rm -f ./a.out
	g++ -std=c++17 -g -Wall main.cpp rekognition.o -lm -lstdc++fs -Wno-unused-variable -Wno-unused-function
	valgrind --tool=memcheck --leak-check=full --track-origins=yes ./a.out

clean:
	rm -f ./a.out
  
submit:
	/home/cs211/s2025/tools/project01 submit main.cpp
  
commit:
	git add .
	git commit -m "$(msg)"

rekognition:
	rm -f rekognition.o
	g++ -std=c++17 -c -w -Wall rekognition.cpp -Wno-unused-variable -Wno-unused-function
