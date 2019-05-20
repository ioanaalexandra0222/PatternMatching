build:matching my_strace

matching:matching.c my_strace.c
	gcc $< -o $@

my_strace:my_strace.c
	gcc $< -o $@
clean:
	rm matching my_strace

