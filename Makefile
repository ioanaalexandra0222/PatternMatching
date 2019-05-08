build:matching

matching:matching.c
	gcc $< -o $@
clean:
	rm matching

