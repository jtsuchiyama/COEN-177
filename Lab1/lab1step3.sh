# Name: Jake Tsuchiyama
# Date: 9/21/22
# Title: Lab 1 - Calculating Circle Area
# Description: This program checks if you are the correct user.
# If you are the correct user, then it allows you to compute the area of a circle 

#!/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$

user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
if [ $user = "jtsuchiyama" ]
then
        echo "Now you can proceed!"
else
        echo "Check who logged in!" 
        exit 1
fi

response="Yes"
while [ $response != "No" ]
do
        echo "Enter radius of circle: "
        read radius
        area=$(echo "scale=2;3.14 * ($radius * $radius)" | bc)
        echo "The area of the circle is $area"
        echo "Would you like to repeat for another circle [Yes/No]?"
        read response
done