# caesar

A simple C program that encodes files using [Caesar's cipher](https://en.wikipedia.org/wiki/Caesar_cipher).

## Building

Just run `make`.

## Usage

```bash
# Reading from stdin
$ echo "aaabbbccc" | ./caesar
nnnoooppp

# Specifying how many letters to shift by
$ echo "abc" | ./caesar --shift 1
bcd

# Using input and output files
$ echo "some words" > a.txt
$ ./caesar --input a.txt --output b.txt
$ cat b.txt
fbzr jbeqf

# The program ignores non-ascii letters
$ echo "ABC +-/ abc" | ./caesar
NOP +-/ nop
```
