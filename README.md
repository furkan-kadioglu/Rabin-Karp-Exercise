# Rabin-Karp-Exercise
## Description
Mahir has a really old fax machine. He is using this fax machine to communicate with his friends and family. But one day this machine starts glitching. As a result all of the space characters in the messages are skipped by the machine. As an example, if a friend sends Mahir the message ”the cake is a lie”, the fax machine will print it as ”thecakeisalie”. After some time this starts causing him problems since he cannot know where words start or end for sure. The message ”dragonfly” might mean ”dragonfly”, ”dragon fly” or ”drag on fly”. After struggling with these messages Mahir decides to write a program that can calculate how many ways are there to split a message printed by this fax machine into words.

## Input/Output
The program will be given a message and a list of possible words that can appear in the message. The program prints out in how many ways that a given message can be interpreted.

#### Input Format
The first line of the input file contains the received message as a string. Second line of the input file is an integer D, specifying the number of words in Mahir’s dictionary. Each of the following D lines contain a string, a distinct word in the dictionary. The dictionary does not have to be in the alphabetical order. A word in the dictionary might not appear in the message.

#### Output Format
The program calculates and prints out the number of possible splits of this message into words, using the words the given dictionary. This number can be really big, so the program calculates it in modulo 109 + 7. One of the biggest prime numbers that can fit into a 32 bit integer.

**Example Input 1**
```
hellomahir
3
hello
world
mahir
```

**Example Output 1**
```
1
```
This message can only be interpreted as ”hello mahir”.

**Example Input 2**
```
thisisoverusedcarsalesman
14
ale
ales
car
cars
is
man
over
overused
ruse
sale
sales
salesman
this
used
```

**Example Output 2**
```
6
```
All possible ways to interpret this message:
```
this is overused car salesman
this is overused cars ales man
this is over used car sales man
this is over used car salesman
this is over used cars ales man
```

**Example Input 3**
```
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
32
a
aa
aaa
aaaa
aaaaa
aaaaaa
aaaaaaa
aaaaaaaa
aaaaaaaaa
aaaaaaaaaa
aaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaaa
aaaaaaaaaaaaaa
aaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
```

**Example Output 3**
```
147483634
```
Since this message can be split on each possible location, the number of pos- sible interpretations of this message is 2^31 = 2, 147, 483, 648. 2, 147, 483, 648 modulo 1, 000, 000, 009 is 147, 483, 634.

## Implementation Details
1. Variable limits are as follows:
- 1 ≤ Length of the received message ≤ 1,000
- 1 ≤ Number of words in the dictionary ≤ 1,000
- 1 ≤ Length of each word in the dictionary ≤ 1,000
- All of the characters in each string will be a lower case letter.
2. Execution time limit is 1 seconds. 
3. The program will be compiled with cmake CMakeLists.txt && make command and executed with ./project5 inputFile output- File command.
