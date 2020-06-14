#!/usr/bin/env bash

#this file compares some stuff and tests it to make sure
#everything is working ok
# written by Daniel Lynch, a second year Tuck MBA student


#take all of the arguments into an array

arg_list=( "$@" )

#$@ takes ALL of the command line arguments

#echo out to user the directory

echo "Inputted Directory: $arg_list[0]"

length=(${#arg_list[@]})
#make sure # arguments >=2, if not, ask for more arguments
if [ ${length}  -ge 2 ]
then
        #make sure the directory exists
        echo "Arg list meets length requirements"
        #three cases:
        #it directory arg exists, but not directory THROW ERROR
        #it does not exist at all GOOD/make a new directory
        #it exists and it is a directory GOOD/proceed
        #-e checks if exists





        if test -d arg_list[0] || !(test -e arg_list[0])
        then
        echo "Arg list contains the right elements"
                #if directory does not yet exist, make it
                if !(test -e arg_list[0])
                then
                        echo "Making new directory: ${arg_list[0]}
                        mkdir [arg_list[0]]
                exit 0
                else
                        echo 1>&2 "Directory unable to be created!"
                        exit 1
                fi
                #make a new directory with date and time form, in the newly made directory
                #go within given directory
               
cd arg_list[0]

                #within that directory, make a new directory
                #format YYYYMMDD.HHMMSS

                #store the format in a string so we can reuse it
                dir_string="$(%Y%m%d.%H%M%S)"

                #create the directory
                mkdir ${dir_string}

                #enter that directory now

                cd ${dir_string}

                #for each of the test files taken, create new
                #test case files
                i = 0
                for item in arg_list
                do

                        #we don't want to add files for the directory arg
                        if !(item eq ${arg_list[0]})
                        then
                        #make a .test, .status, .stdout, .stderr
                                touch "${arg_list[i]}".test
                                touch "${arg_list[i]}".status
                                touch "${arg_list[i]}".stdout
                                touch "${arg_list[i]}".stderr
                        fi
                i = i + 1
                done


        else
                echo 1>&2 "'Directory' isn't actually a directory.\n Enter legit directory please!"
                exit 1
        fi
else

#ask for more arguments

        echo 1>&2 "Need at least one directory and one file name!"
exit 1

fi
#do for each file given

#verify arguments, check for files, are they readable?


#check if the file exists
if test -f "$1"
 then #should work as long as -f is an option for test
    echo "$1E exist"
fi

#second part

#once checks are done, if dir does not exists, create a new directory under that #name
#pull in the date and time to name these directories
#
#loop through each argument/test file and redirect stdin , copied test file to the current directory, redirected the stderr and stdout to files, redirected the exit status (write
if [ $# -eq 0 ]
#check if there are differences
then
        echo true
exit 0
else
        echo 1>&2  "Either directory or file are not valid!"
fi


