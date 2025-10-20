test: test_hash_table.o 
	g++ -o test test_hash_table.o
	
test_hash_table.o: test_hash_table.cpp hash_table.h hash_table.cpp element.h
	g++ -c test_hash_table.cpp

test_login: test_login.cpp hash_table.cpp usecase.cpp
	g++ -o test_login test_login.cpp hash_table.cpp usecase.cpp

login_system: main.cpp hash_table.cpp usecase.cpp
	g++ -o login_system main.cpp hash_table.cpp usecase.cpp

clean:
	rm -f all *.o