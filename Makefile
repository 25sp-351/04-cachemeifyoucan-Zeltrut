CC = gcc
CFLAGS = -Wall -Wextra -g
OBJFILES = main.o rod_cut.o utils.o
POLICY_A = policy_a.o
POLICY_B = policy_b.o

all: rod_cut_a rod_cut_b

rod_cut_a: $(OBJFILES) $(POLICY_A)
	$(CC) $(CFLAGS) -o rod_cut_a $(OBJFILES) $(POLICY_A)

rod_cut_b: $(OBJFILES) $(POLICY_B)
	$(CC) $(CFLAGS) -o rod_cut_b $(OBJFILES) $(POLICY_B)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o rod_cut_a rod_cut_b
