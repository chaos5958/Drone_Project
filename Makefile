all: 
	g++ -o video_test video_test.cpp `pkg-config --cflags --libs opencv`

clean:
	rm video_test
