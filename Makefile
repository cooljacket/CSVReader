objs = main.o CSVReader.o CSVVectorContainer.o CSVMapContainer.o
CC = g++

out: $(objs)
	$(CC) -o out $(objs)

CSVVectorContainer.o: CSVVectorContainer.h CSVContainerAdapter.h
CSVMapContainer.o: CSVMapContainer.h CSVContainerAdapter.h
CSVReader.o: CSVReader.h

clean:
	rm *.o out