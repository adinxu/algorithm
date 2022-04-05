CXX=g++
OBJS=main.o \
	 FindPath.o
TARGET=FindPathDemo
$(TARGET):$(OBJS)
	$(CXX) -o $@ $^

main.o FindPath.o:FindPath.h

clean:
	rm $(TARGET) $(OBJS)
