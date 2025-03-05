CXX = g++
CXXFLAGS = -std=c++17 -Wall -I include
LDFLAGS = -lcurl

SRCS = src/main.cpp src/CScraper.cpp src/utils.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = scrapx

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
