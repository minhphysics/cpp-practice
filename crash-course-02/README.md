g++ -c mylib02.cpp mylib02.o

ar rcs libmylib02.a mylib02.o

g++ crash-course-02.cpp -L. -lmylib02 -o main