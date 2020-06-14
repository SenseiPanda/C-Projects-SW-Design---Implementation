# Daniel Lynch 
## cs50 Spring 2020, Lab 2

GitHub username:
Sensei Panda
*Please replace this text with any comments you have about the overall assignment.  Your solutions should be in other files as defined by the assignment.*
Words.c
This program can take either 1 or no arguments. If no arguments, the program reads in characters line by line from STDIN and prints them out to the console, printing each word on a new line. If a file is given as an argument,
the program opens the file, reads in the characters, and prints them to a new output file, with one word on each new line. So if this body of text were run through this program through the console, a each new word would be printed out on a new line.
Chill.c
 Chill.c is a program that can take a variety of inputs (0,1, or 2) and calculates
  wind chills based on input temperatures and velocities.
  Wind chill is the bodily perceived temperature created by the compound effects of cold air and wind.
  A. The user can enter no input and receive a temp/velocity/wind chill chart.
  B. The user can enter a temperature and receive velocities and wind chills for that temp.
  C. The user can enter a temperature and velocity and receive a wind chill.
  Standard Formula for calculation given:
  Wind Chill = 35.74 + 0.6215T - 35.75(V^0.16) + 0.4275T(V^0.16)
Histo.c

This program  reads in from stdin a number of integers and groups their frequency into  16 bins 
of equal size. This is done by finding the max value, and finding 16 different bin sizes based on that max value. Note that the bins don't contain the numbers read in, they only contain the overall frequency in which those numbers occurThe program is then supposed to visually print these to the user. 

Regress.sh 

A program that implements regression testing, important to any quality software development process. This program can test each new revision and see if it still performs correctly as before. The program does this by comparing output files or outputs from certain programs and compares them to the output files or output of past versions of the program. The script creates a new directory when run using the date and time format YYYYMMDD.HHMMSS. This new directory is populated with a stderr, stdout, and status file.
  The program takes a directory name, along with a list of files to test. If the directory given in the argument does not yet exist, it is created. If it does, the testing files are added to that directory.

