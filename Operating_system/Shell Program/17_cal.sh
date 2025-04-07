


#  17. Write a shell script to modify ‘cal’ command to display calendars of specified range of months.


clear
echo "enter the month to see calender in range"
read -p "form the month " n1
read -p "to the month " n2
read -p "enter the year " y

echo "CALENDAR :-"
cal -m$n1 -A$n2 $y


# output

# enter the month to see calender in range
# form the month 2
# to the month 4
# enter the year 2025
# CALENDAR :-
#    February 2025           March 2025            April 2025       
# Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  
#                    1                     1         1  2  3  4  5  
#  2  3  4  5  6  7  8   2  3  4  5  6  7  8   6  7  8  9 10 11 12  
#  9 10 11 12 13 14 15   9 10 11 12 13 14 15  13 14 15 16 17 18 19  
# 16 17 18 19 20 21 22  16 17 18 19 20 21 22  20 21 22 23 24 25 26  
# 23 24 25 26 27 28     23 24 25 26 27 28 29  27 28 29 30           
#                       30 31                                       

#       May 2025             June 2025        
# Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  
#              1  2  3   1  2  3  4  5  6  7  
#  4  5  6  7  8  9 10   8  9 10 11 12 13 14  
# 11 12 13 14 15 16 17  15 16 17 18 19 20 21  
# 18 19 20 21 22 23 24  22 23 24 25 26 27 28  
# 25 26 27 28 29 30 31  29 30                 
                             