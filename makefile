quiz: main radixSort chocolate insertSort
	g++ -o quiz main.o radixSort.o chocolate.o insertSort.o

main:
	g++ -c main.cpp

radixSort:
	g++ -c radixSort.cpp

chocolate:
	g++ -c chocolate.cpp

insertSort:
	g++ -c insertSort.cpp