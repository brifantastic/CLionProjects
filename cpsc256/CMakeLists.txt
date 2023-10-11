cmake_minimum_required(VERSION 3.25)
project(cpsc256)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)

# Week 1
add_executable(HelloWorld Examples/Week1/HelloWorld/main.c)
add_executable(PrimitiveDataTypes Examples/Week1/PrimitiveDataTypes/main.c)

# Week 2
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples/Week2/FileReader)
add_executable(FileReader Examples/Week2/FileReader/main.c)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples/Week2/CSVFileReader)
add_executable(CSVFileReader Examples/Week2/CSVFileReader/main.c)

# Week 3
add_executable(Declarations Examples/Week3/Declarations/main.c)
add_executable(FormatSpecifiers Examples/Week3/FormatSpecifiers/main.c)
add_executable(FunctionExample Examples/Week3/FunctionExample/main.c)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples/Week3/FileStatistics)
add_executable(FileStatistics Examples/Week3/FileStatistics/main.c Examples/Week3/FileStatistics/mean.c Examples/Week3/FileStatistics/stdev.c)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples/Week3/FileStatistics_Headers)
add_executable(FileStatistics_Headers Examples/Week3/FileStatistics_Headers/main.c Examples/Week3/FileStatistics_Headers/mean.c Examples/Week3/FileStatistics_Headers/stdev.c)

# Week 4
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/Examples/Week4/BasicPointers)
add_executable(BasicPointers Examples/Week4/BasicPointers/main.c Examples/Week4/BasicPointers/functions.c)
add_executable(VoidPointers Examples/Week4/VoidPointers/main.c)
add_executable(QuickSort Examples/Week4/QuickSort/main.c)

# Week 5
add_executable(Restaurant_C_Example Examples/Week5/Restaurant_C_Example/main.c)
add_executable(PointerCar Examples/Week5/PointerCar/main.c Examples/Week5/PointerCar/PointerCar.c)
add_executable(SimpleCar Examples/Week5/SimpleCar/main.c Examples/Week5/SimpleCar/SimpleCar.c)
add_executable(CoinFlip Examples/Week5/CoinFlip/main.c Examples/Week5/CoinFlip/Coin.c)
# Week 6
add_executable(HelloWorldCPP Examples/Week6/HelloWorldCPP/main.cpp)
add_executable(BasicVectorCPP Examples/Week6/BasicVectorCPP/main.cpp)
add_executable(FunctionOverloading Examples/Week6/FunctionOverloading/main.cpp)

# Week 7
add_executable(PassBy Examples/Week6/PassBy/main.cpp)
add_executable(BasicObjects Examples/Week7/BasicObjects/main.cpp Examples/Week7/BasicObjects/Restaurant.cpp)
add_executable(MultipleClasses Examples/Week7/MultipleClasses/main.cpp)

# Week 8
add_executable(ArtistAndArtwork Examples/Week8/ArtistAndArtwork/main.cpp Examples/Week8/ArtistAndArtwork/Artist.cpp Examples/Week8/ArtistAndArtwork/Artwork.cpp)
add_executable(CopyConstructorExample Examples/Week8/CopyConstructorExample/main.cpp)
add_executable(PointersCPP Examples/Week8/PointersCPP/main.cpp)
add_executable(BasicObjectsPointers Examples/Week8/BasicObjectsPointers/main.cpp Examples/Week8/BasicObjectsPointers/Restaurant.cpp)

# Week 9
add_executable(FunctionTemplates Examples/Week9/FunctionTemplates/main.cpp)
add_executable(OperatorOverloading Examples/Week9/OperatorOverloading/main.cpp Examples/Week9/OperatorOverloading/TimeHrMn.cpp)

# Week 10
add_executable(InheritancePolymorphism Examples/Week10/InheritancePolymorphism/main.cpp)