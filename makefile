test: test_hash_table.o 
	g++ -o test test_hash_table.o
	
test_hash_table.o: test_hash_table.cpp hash_table.h hash_table.cpp element.h
	g++ -c test_hash_table.cpp

clean:
	rm -f all *.o