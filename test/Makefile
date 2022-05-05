make: 
	g++ -std=c++14 test.cpp -include printArray.hpp -include baseSort.hpp -include selection/*.hpp -include insertion/*.hpp -include shell/*.hpp -include merge/*.hpp -o test.exe
verbosed:
	g++ -std=c++14 -DPRINT_ENABLED test.cpp -include printArray.hpp -include baseSort.hpp -include selection/*.hpp -include insertion/*.hpp -include shell/*.hpp -include merge/*.hpp -o test.exe
run: 
	./test.exe
clean: 
	rm *.exe