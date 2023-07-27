# push_swap

Sorting a stack of ints with the limited amount of commands. Using two stacks. Implemented with linked lists and greedy choise insertion sort.
Also i have implemented the checker program.

## Get started

First of all you should git clone the repo in your terminal. And then enter the folder you've created. Do it in the folowing way:

```console
git clone https://github.com/MilenaKhalil/pipex push_swap
cd push_swap
```

Build the progect by running "make" and "make bonus":

```console
make
```

```console
make bonus
```
>NOTE! If you are running _make_ the name of the executable will be _push_swap_. If you run _make bonus_ it is going to be _checher_.

## Running the project

Run the exacutable with few ints. Could be even 1000. Then the program will give you sorting instractions. The numbers should be all unique. 

```console
./pipex 1 3 2 4 5
```
>NOTE! You can pipe the output to the checker program. 

For running checker you should use the same input. For instance like this:
```console
ARG="2 18 9 7 0"; ./push_swap $ARG | ./checker $ARG
```
In this case the program should output OK.
>NOTE! If there are duplicate numbers or if the number is out of int range. Both of the programs push_swap and checker with throuth an ERROR message.
