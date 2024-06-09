#Makefile para STVS
all : STVS
STVS: ./utils/Utils.cpp ./utils/Utils.hpp ./model/Serie.cpp ./model/Serie.hpp ./repositories/implementation/VirtualDatabase.cpp ./repositories/implementation/VirtualDatabase.hpp ./repositories/implementation/ServerDatabase.cpp ./repositories/implementation/ServerDatabase.hpp ./controller/dto/AddSerieDTO.cpp ./controller/dto/AddSerieDTO.hpp ./view/Menu.cpp ./view/Menu.hpp ./controller/SerieController.cpp ./controller/SerieController.hpp ./infrastructure/MariaDBConnection.cpp ./infrastructure/MemoryDBConnection.hpp  
	g++ ./model/Serie.cpp \
    ./repositories/implementation/VirtualDatabase.cpp \
    ./repositories/implementation/ServerDatabase.cpp \
    ./controller/dto/AddSerieDTO.cpp \
    ./view/Menu.cpp  \
    ./controller/SerieController.cpp  \
    ./infrastructure/MariaDBConnection.cpp \
    ./infrastructure/MemoryDBConnection.hpp \
    ./utils/dto/MakeTableDecoratorDTO.cpp  \
    ./utils/Utils.cpp \
    main.cpp -o STVS -lmariadbcpp
run: STVS
	./STVS
clean:
	rm -f clean
