


#  17. Write a shell script to modify ‘cal’ command to display calendars of specified range of months.


clear
echo "enter the month to see calender in range"
read -p "form the month " n1
read -p "to the month " n2
read -p "enter the year " y

echo "CALENDAR :-"
cal -m$n1 -A$n2 $y