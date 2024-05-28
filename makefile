#Makefile para STVS
all : STVS
STVS : ./model/Serie.cpp ./repositories/SeriesDAO.hpp ./repositories/implementation/VirtualDatabase.cpp main.cpp ./view/Menu.cpp  ./view/Textos.hpp ./controller/SerieController.cpp ./model/DBconnection.cpp ./controller/dto/AddSerieDTO.cpp ./controller/dto/AddSerieDTO.hpp
	g++ ./model/Serie.cpp \
    ./repositories/SeriesDAO.hpp \
    ./repositories/implementation/VirtualDatabase.cpp \
    main.cpp \
    ./view/Menu.cpp  \
    ./view/Textos.hpp  \
    ./controller/SerieController.cpp  \
    ./model/DBconnection.cpp \
    ./controller/dto/AddSerieDTO.cpp -o STVS -lmariadbcpp
run: STVS
	./STVS
clean:
	rm -f clean
