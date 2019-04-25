# SP-Lab-2
This program aims to improve the employee database implement in Lab1, 4 functions have been added. To build an executable, open all source files, head files and input files in an IDE. (Here I used CLion)

![image](https://github.com/EzraWeng/SP-Lab-2/blob/master/Image/1.png)

Before the testing, the program needs to load the employee data stored in input.txt. In CLion, click “Run”

![image](https://github.com/EzraWeng/SP-Lab-2/blob/master/Image/2.png)

Choose “Run” in the sub menu, and click “0. Edit Configurations”

![image](https://github.com/EzraWeng/SP-Lab-2/blob/master/Image/3.png)

Enter “../input.txt” in “Program arguments”, apply and run

![image](https://github.com/EzraWeng/SP-Lab-2/blob/master/Image/4.png)

A new command line window will appear, to test the removing function, enter 6, the program will require you to enter a 6 digit employee id

![image](https://github.com/EzraWeng/SP-Lab-2/blob/master/Image/5.png)

After enter the id, if id is found in the database, program will ask for confirmation for removing operation, enter 1 to confirm, enter 0 to cancel

![image](https://github.com/EzraWeng/SP-Lab-2/blob/master/Image/6.png)

If id entered is not found in the database(i.e. 123456), program will show "No such an employee whose id is 123456"

![image](https://github.com/EzraWeng/SP-Lab-2/blob/master/Image/7.png)

To test the update function, enter 7 in main menu, program will require you to enter an existing employee id. If id is found in data base, enter new first name, new last name, new salary and new 6 digit employee id.

![image](https://github.com/EzraWeng/SP-Lab-2/blob/master/Image/9.png)

Return to main menu and enter 1 to print the data base, the employee information is updated

![image](https://github.com/EzraWeng/SP-Lab-2/blob/master/Image/10.png)

To test highest salary printing function, enter 8 in main menu, enter a value(i.e. 5), 5 employees informations with highest salary will be printed

![image](https://github.com/EzraWeng/SP-Lab-2/blob/master/Image/11.png)

To find all employees with matching last name, enter 9 in main menu, enter a last name, all results with same last name will be printed

![image](https://github.com/EzraWeng/SP-Lab-2/blob/master/Image/12.png)

To exit the program, enter 5 in main menu
