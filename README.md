# Pipex

This is a project from the second circle of the 42cursus.
It aims to simulate the pipes in the bash command line.

### Objectives :
  * Redirect an input, simulate a single pipe and redirect its output. (an example of what the program should handle : < infile cmd1 | cmd2 > outfile)
  * Simulate multiple pipes. (For the first bonus part) (< infile cmd1 | cmd2 .... | cmdn > outfile)
  * Simulate here_doc. (For the second bonus part) (cmd1 << limiter | cmd2 >> outfile)

### Skills I've learnt from this project
  * Functionning of processes.
  * Functionning of redirection of any input and output.
  * Unix logic.

### Final grade
  125/100.
  
### How to use
  1. Type make and let the Makefile do the compilation work ('make' for the mandatory part, 'make bonus for the bonus part').
  2. For the mandatory part execute the program like this : ./pipex 'infile' cmd1 cmd2 'outfile'.
  3. For the first bonus part execute it this way : ./pipex 'infile' cmd1 cmd2 ... cmdn 'outfile'.
  4. For the second bonus part : ./pipex here_doc 'limiter' 'cmd1' 'cmd2' outfile.
